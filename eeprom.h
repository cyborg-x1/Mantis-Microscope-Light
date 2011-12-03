#ifndef EEPROM_H_
#define EEPROM_H_

#include <avr/io.h>

/**
 * This function writes a defined number from an array to the specified address
 */
void writeBytesToEEprom(uint16_t address, const uint8_t *arr, uint8_t len);

/**
 * This function reads a defined number of bytes from the eeprom
 * at the specified address
 */
void readBytesFromEEprom(uint16_t address, uint8_t *arr, uint8_t len);

#endif /* EEPROM_H_ */
