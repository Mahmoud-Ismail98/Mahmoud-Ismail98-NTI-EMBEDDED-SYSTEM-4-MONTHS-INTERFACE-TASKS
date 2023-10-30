#include "Std_types.h"
#include "Bit_utils.h"

#include "I2C.h"
#include "PORT.h"
#include "DIO_int.h"
void EEPROM_voidWriteByte(u8 Copy_u8Data,u8 RegAddress)
{
	//I2C_voidTransmitStopCondition();
	I2C_voidTransmitStartCondition();
	I2C_voidMasterTransmitSlaveAddress(0b01010000, Write);
	I2C_voidMasterTransmitData(RegAddress);
	I2C_voidMasterTransmitData(Copy_u8Data);
	//I2C_voidMasterTransmitData('H');
	//DIO_enum_WriteChannel(DIO_u8PORTAPIN0, DIO_u8High);
	I2C_voidTransmitStopCondition();
}
void EEPROM_voidReadByte(pu8 ptr_u8Data,u8 RegAddress)
{
	I2C_voidTransmitStartCondition();
	I2C_voidMasterTransmitSlaveAddress(0b01010000, Write);
	I2C_voidMasterTransmitData(RegAddress);
	I2C_voidTransmitStartCondition();
	I2C_voidMasterTransmitSlaveAddress(0b01010000, Read);
	I2C_voidMasterReadData(ptr_u8Data);
	I2C_voidTransmitStopCondition();
}
