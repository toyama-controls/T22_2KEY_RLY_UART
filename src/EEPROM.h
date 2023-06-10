/*
 * EEPROM.h
 *
 *  Created on: May 31, 2023
 *      Author: aishw
 */

#ifndef EEPROM_H_
#define EEPROM_H_
void EEPROM_WRITE(uint8_t * TX_BUFF);
void EEPROM_WRITE_ADDRESS(uint8_t * TX_BUFF1);
void EEPROM_READ(void);
#endif /* EEPROM_H_ */
