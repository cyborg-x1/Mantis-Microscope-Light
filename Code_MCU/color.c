#include "color.h"

//Command Buffer and length
uint8_t command_buffer[]={0,0,0,0,0,0,0,0};
uint8_t command_len=0;

//Button/Pedal variable
uint8_t butPed=0;

//Button/Pedal light situations
uint8_t butPedSit1[]={0,0,0,0,0};
uint8_t butPedSit2[]={0,0,0,0,0};

//variable for storing the current light situation
uint8_t curlight[]={0,0,0,0,0};

//variable for a new light situation
uint8_t newlight[]={0,0,0,0,0};

//variables for timing
uint8_t time_6us4=0;
uint16_t time_ms=0;

uint8_t setColors(volatile uint8_t uv, uint8_t w, uint8_t r, uint8_t g, uint8_t b)
{
	if((!uv) || (!w)) // White ___or___ UV-light
	{
		if(uv==0) //If white
		{
			PORTB&=~((1<<PB4));
			OCR1B=w;
		}
		else	 //If UV
		{
			PORTB|=(1<<PB4);
			OCR1B=uv;
		}

		OCR0A=r;
		OCR2A=g;
		OCR1A=b;
		return 0;
	}
	else
	{
		OCR1B=0;
		OCR0A=0;
		OCR2A=0;
		OCR1A=0;
		return 1;
	}
}

uint8_t setColorsFromArray(const uint8_t *arr)
{
	return setColors(arr[0],arr[1],arr[2],arr[3],arr[4]);
}

uint8_t setColorMEMFromArray(uint8_t addr, const uint8_t *arr)
{
	//Is address ok?
	if(addr>12) return 1;

	//Is UV or white null?
	if(arr[0]!=0 && arr[1]!=0) return 1;

	switch(addr)
	{
	//Current LED brightness
	case 0:
		copyColorArray(arr, newlight);
		break;
	//pedal
	case 1:
		copyColorArray(arr, butPedSit1);
		break;
	case 2:
		copyColorArray(arr, butPedSit2);
		break;
	//eeprom
	case 3: case 4: case 5: case 6: case 7:
    case 8: case 9: case 10: case 11: case 12:
    	writeBytesToEEprom(addr-3*5,arr,5);
    	break;
	}
	return 0;
}

uint8_t ColorMEMToArray(uint8_t addr, uint8_t *arr)
{
	//if address is out of range -> error
	if(addr>12)return 1;

	switch(addr)
	{
	//Current LED brightness
	case 0:
		copyColorArray(newlight, arr);
		break;
	//pedal
	case 1:
		copyColorArray(butPedSit1, arr);
		break;
	case 2:
		copyColorArray(butPedSit2, arr);
		break;
	//eeprom
	case 3: case 4: case 5: case 6: case 7:
    case 8: case 9: case 10: case 11: case 12:
    	readBytesFromEEprom(addr-3*5,arr,5);
    	break;
	}

	return 0;
}

void color_handler()
{
	//Check if a new color is present
	for(int col=0;col<5;col++)
	{
		if(curlight[col]!=newlight[col])
		{
			//Set curlight to newlight
			for(int coln=0;coln<5;coln++)
			{
				curlight[col]=newlight[col];
			}
			//Update PWM Outputs
			setColorsFromArray(newlight);
		}
	}
}

void color_init()
{
	//Set pins to output and to zero
	DDRB|=(1<<PB4)|(1<<PB3);
	DDRD|=(1<<PD4)|(1<<PD5)|(1<<PB7);
	PORTB&=~((1<<PB4)|(1<<PB3));
	PORTD&=~((1<<PD4)|(1<<PD5)|(1<<PB7));

	//PWM -- RED non inv. FAST PWM (Prescaler 1/64)
	TCCR0A=0x81;
	TCCR0B=0x03;
	OCR0A=0;

	//PWM BLUE / UV / W non inv. 8 Bit FAST PWM (Prescaler 1/64)
	TCCR1A=0xA1;
	TCCR1B=0x03;
	OCR1A=0;
	OCR1B=0;

	//PWM GREEN non inv. FAST PWM (Prescaler 1/64)
	TCCR2A=0x81;
	TCCR2B=0x03;
	OCR2A=0;
}

void copyColorArray(const uint8_t *from_array, uint8_t *to_array)
{
	for (int col = 0; col < 5; ++col)
	{
		to_array[col]=from_array[col];
	}
}


typedef enum
{
    SET_COLOR,

    _READ_OPS,

    READ_MEM,
}mcu_command_t;


typedef enum
{
	HEADER0,
	HEADER1,
	_CHECKSUM_COVERED_BEGIN,
	COMMAND,
	PAYLOAD,
	_CHECKSUM_COVERED_END,
	CHECKSUM,
}receive_state_t;

//Commands
//RW / UV / W / R / G / B / Check


void send_message(uint8_t *array, uint8_t len)
{
	unsigned checksum=0;

	uart_sendByte(0xAA);
	uart_sendByte(0x55);
	for (int i = 0; i < len; ++i)
	{
		checksum^=array[i];
		uart_sendByte(array[i]);
	}
	uart_sendByte(checksum);
}



ISR(USART0_RX_vect)
{
	static receive_state_t state=HEADER0;
	static uint8_t payload_byte=0;
	static uint8_t payload_array[10];
	static mcu_command_t cmd;
	static uint8_t checksum;




	uint8_t cur_byte=UDR0;
	if(state>_CHECKSUM_COVERED_BEGIN && state<_CHECKSUM_COVERED_END)
	{
		checksum^=cur_byte;
	}

	switch(state)
	{
		case HEADER0:
			if(0xAA == cur_byte)
			{

				state=HEADER1;
			}
			break;

		case HEADER1:
			if(0x55 == cur_byte)
			{
				state=COMMAND;
				checksum=0;
			}
			else
			{
				state=HEADER0;
			}
			break;

		case COMMAND:
			payload_byte=0;
			cmd=cur_byte;

			if(cmd<_READ_OPS)
			{
				state=PAYLOAD;
			}
			else
			{
				state=CHECKSUM;
			}

			break;

		case PAYLOAD:
			payload_array[payload_byte]=cur_byte;
			payload_byte++;

			switch(cmd)
			{
			case SET_COLOR:
				if(payload_byte==6)
				{
					state=CHECKSUM;
				}
				break;

			default:
				state=HEADER0;
				break;
			}
			break;

		case CHECKSUM:
		{
			uint8_t response[6];
			if(checksum==cur_byte)
			{


				switch(cmd)
				{
				case SET_COLOR:
					{
						uint8_t response[2];
						response[0]=cmd;
						response[1]=setColorMEMFromArray(payload_array[0],payload_array+1);
						send_message(response,2);
					}
					break;

				case READ_MEM:
					{

					}
					break;
					default:
						break;
				}
			}
			else
			{
				//Checksum error message
				response[0]=0xFF;
				response[1]=checksum;
				response[2]=cur_byte;
				send_message(response,1);
			}
		}


			state=HEADER0;

			break;


		default:
			break;
	}


//	//TODO RESET TIMER VARS
//	//TODO TIMER INT ON
//	command_buffer[command_len]=UDR0;
//	if(command_len>=7)
//	{
//		//TODO TIMER INT OFF
//		switch(command_buffer[0])
//		{
//			//Write
//			case 'W':
//			{
//				//command_buffer[2]=4;//TODO REMOVE!!!
//
//				//Write color(5 bytes from byte 2) to given address (byte 1)
//				uint8_t err=setColorMEMFromArray(command_buffer[1],command_buffer+2);
//				if(!err)
//				{
//					uart_sendByte('A');
//				}
//				else
//				{
//					uart_sendByte('N');
//				}
//			}
//			break;
//
//			//Read MEM
//			case 'R':
//			{
//				uint8_t err=ColorMEMToArray(command_buffer[1],command_buffer+2);
//				if(!err)
//				{
//					uint8_t checksum=0;
//					for (int col = 0; col < 7; ++col)
//					{
//						checksum+=command_buffer[col];
//						uart_sendByte(command_buffer[col]);
//					}
//					uart_sendByte(checksum);
//				}
//				else
//				{
//					uart_sendByte('N');
//				}
//			}
//			break;
//
//			default:
//				uart_sendByte('N');
//			break;
//		}
//		command_len=0;
//	}
//	else
//	{
//		command_len++;
//	}
}


ISR(TIMER2_COMPB_vect)
{
//	time_6us4++;
//	if(time_6us4>=156)
//	{
//		time_6us4=0;
//		time_ms++;
//	}
//	if(time_ms>=100)//timeout 100ms
//	{
//		time_ms=0;
//		command_len=0;
//		//TODO TIMER INT OFF
//	}
}

