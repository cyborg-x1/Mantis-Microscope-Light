/*
 * uart.h
 *
 *  Created on: 02.12.2011
 *      Author: cyborg-x1
 */

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/**
 * This function initializes the UART
 */
void uart_init();


/**
 * This functions sends a byte over the UART
 * @param byte
 */
void uart_sendByte(uint8_t byte);



#endif /* UART_H_ */
