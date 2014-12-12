#include <avr/io.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "uart.h"
#include "color.h"

/**
 * This function initializes the PWM Channels and the UART
 */
void init()
{
	color_init();
	uart_init();

	//Interrupts enable
	sei();
}

/**
 * Main (what else?)
 */
int main()
{
	init();
	while(1) color_handler();
}


