/*
 * EEPROM.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Ismail
 */


#include <util/delay.h>
#include "../includes/EEPROM.h"
void EEPROM_ReadByte(u8 Copy_u8BlockNo, u8 Copy_u8ByteAddress){

	TWI_SendStart();
		TWI_SendAdressWithWrite(EEPROM_FIXED_SLAVE_ADDRESS);
		TWI_SendDataOnly(Copy_u8ByteAddress);
		TWI_SendRepeatedStart();
		TWI_SendAdressWithRead(Copy_u8ByteAddress);
		TWI_SendStopCondition();
}
void EEPROM_WriteByte(u8 Copy_u8ByteAddress, u8 Transmitted_data){

	TWI_SendStart();
	TWI_SendAdressWithWrite(EEPROM_FIXED_SLAVE_ADDRESS);
	TWI_SendDataOnly(Copy_u8ByteAddress);
	TWI_SendDataOnly(Transmitted_data);
	TWI_SendStopCondition();
}
