/*
 * uart.c
 *
 *  Created on: 02.12.2011
 *      Author: cyborg-x1
 */

#include "uart.h"



void uart_sendByte(uint8_t byte)
{
	//Wait for empty output buffer
	while (!( UCSR0A & (1<<UDRE0)));
	UDR0 = byte;
}

void uart_init()
{
	//USART Enable  9600 baud, 8 bit, 1 stop bit, no parity,
	UCSR0A|=(1<<U2X0);
	UCSR0B|=(1<<RXCIE0)|(1<<TXEN0)|(1<<RXEN0);
	UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00)|(1<<USBS0);

	UBRR0=129;
}
