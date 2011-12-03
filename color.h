/*
 * color.h
 *
 *  Created on: 02.12.2011
 *      Author: cyborg-x1
 */

#ifndef COLOR_H_
#define COLOR_H_

#include "uart.h"
#include "eeprom.h"


/**
 * This function initializes the PWM Channels
 */
void color_init();

/**
 * This function does the color handling in the main routine
 */
void color_handler();

/**
 * This function sets the PWM values for the various LED channels
 */
uint8_t setColors(volatile uint8_t uv, uint8_t w, uint8_t r, uint8_t g, uint8_t b);

/**
 * This function takes an color array (length=5) to set the LED brightness
 */
uint8_t setColorsFromArray(uint8_t const *arr);

/**
 * This function takes an color array to set a memory.
 * The memories are mapped as follows:
 * \n
 * Addr |  Description \n
 * 0 Current LED_Color \n
 * 1 Button/Pedal Color1 \n
 * 2 Button/Pedal Color2 \n
 * 3 EEProm Color 0(on init Button/Pedal Color1) \n
 * 4 EEProm Color 1(on init Button/Pedal Color2) \n
 * 5 EEProm Color 2 \n
 * 6 EEProm Color 3 \n
 * 7 EEProm Color 4 \n
 * 8 EEProm Color 5 \n
 * 9 EEProm Color 6 \n
 * 10 EEProm Color 7 \n
 * 11 EEProm Color 8 \n
 * 12 EEProm Color 9 \n
 * @return 0 on success, 1 on error
 */
uint8_t setColorMEMFromArray(uint8_t addr, uint8_t const *arr);

/**
 * This function copys the content of a color memory into a specified array
 * @return 0 on success, 1 on error
 */
uint8_t ColorMEMToAArray(uint8_t addr, uint8_t *arr);


/**
 * This function copies a color array into another
 */
void copyColorArray(const uint8_t *from_array, uint8_t *to_array);

/**
 * ISR for handling serial commands
 */
ISR(USART0_RX_vect);

/**
 * ISR for serial command timeout
 */
ISR(TIMER2_COMPB_vect);


#endif /* COLOR_H_ */
