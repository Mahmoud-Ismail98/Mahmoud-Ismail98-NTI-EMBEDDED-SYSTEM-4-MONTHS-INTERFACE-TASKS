/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : EEPROM              **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "Std_types.h"
#include "Bit_utils.h"
#include <util/delay.h>

#include "TWI.h"

#include "EEPROM.h"
#include "EEPROM_prv.h"
#include "EEPROM_cfg.h"

void EEPROM_voidWriteData(u16 Copy_u16Address, u8 Copy_u8Data){
    TWI_SendStartCondition();
    TWI_SendSlaveAddressWithWrite(0b1010000 | ((u8)(Copy_u16Address >>8)));
    TWI_MasterWriteDataByte(Copy_u16Address);
    TWI_MasterWriteDataByte(Copy_u8Data);
    TWI_SendStopCondition();
    _delay_ms(10);

}

void EEPROM_voidReadData(u16 Copy_u16Address, pu8 Copy_pu8Data){
    TWI_SendStartCondition();
    TWI_SendSlaveAddressWithWrite(0b1010000 | ((u8)(Copy_u16Address >>8)));
    TWI_MasterWriteDataByte(Copy_u16Address);
    TWI_SendRepeatedStartCondition();
    TWI_SendSlaveAddressWithRead(0b1010000 | ((u8)(Copy_u16Address >>8)));
    TWI_MasterReadDataByte(Copy_pu8Data);
    TWI_SendStopCondition();
}
