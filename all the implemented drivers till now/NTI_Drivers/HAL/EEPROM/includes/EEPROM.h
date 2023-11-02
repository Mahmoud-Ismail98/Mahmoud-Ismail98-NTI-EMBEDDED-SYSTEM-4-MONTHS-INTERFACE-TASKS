/*
 * EEPROM.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Ismail
 */

#ifndef HAL_EEPROM_EEPROM_H_
#define HAL_EEPROM_EEPROM_H_
#include"../../../Services/Std_types.h"
#include "../../../MCAL/I2C/includes/I2C.h"
#define EEPROM_FIXED_SLAVE_ADDRESS 0b01010000

void EEPROM_ReadByte(u8 Copy_u8BlockNo, u8 Copy_u8ByteAddress);
void EEPROM_WriteByte( u8 Copy_u8ByteAddress, u8 Transmitted_data);

#endif /* HAL_EEPROM_EEPROM_H_ */
