/*
 * eeprom.c
 *
 * Created: 10/30/2023 10:39:37 PM
 *  Author: sharb
 */ 

#include "std_types.h"
#include "bit_math.h"
#include "../../../MCAL/I2C/includes/I2C.h"
#include "../includes/eeprom.h"
#define F_CPU  8000000UL
#include "util/delay.h"
#include "../../LCD/includes/Lcd.h"



u8 arr_g_ReadBuffer[EEPROM_PAGE_SIZE];



void eeprom_init(void)
{
	TWI_MasterInit(0x01); // call function that init I2c Master
}


void eeprom_write_byte(u16 address, u8 data)
{
	
	TWI_start(EEPROM_ADDRESS,0); // Send Start Bit On I2c
	TWI_data(address >> 8); // Write Byte Contain Device Address Shifted By 8 On I2c
	TWI_data(address); // Write Byte Contain Device Address On I2c
	TWI_data(data); // Write Byte Contain Data On I2c
	TWI_stop(); // Send Stop Bit On I2c
}


u8 eeprom_read_byte(u16 address)
{
	u8 data = 0;
	TWI_start(EEPROM_ADDRESS,0);
	TWI_data(address >> 8);
	TWI_data(address); 
	TWI_repeated_start();
	_delay_ms(5);
	data = TWI_readNACK();
	TWI_stop();// Send Stop Bit On I2c
	return data;//Return The Data That Been Read
}


void eeprom_write_string(u16 Copy_u8Address,u8 * str)
{
	u8 i = 0;
	while(str[i] != '\0') // Loop Until The End Of The String
	{
		_delay_ms(50);
		eeprom_write_byte(Copy_u8Address++,str[i++]);//Call This Function To Write Char In EEPROM And Increment The Address And Index
	}
	_delay_ms(50);
	eeprom_write_byte(Copy_u8Address++,'\0');//Call This Function To Write Null After The Last Char Of The String To Know Where The String Is End
}


void eeprom_read_string(u16 Copy_u8Address, u8* str)
{
	u8 len = 0;
	do
	{
		_delay_ms(50);
		str[len] = eeprom_read_byte(Copy_u8Address++);//Call This Function To Read Char From EEPROM And Increment The Address And Index
	}
	while(str[len++] != '\0');// Loop Until The End Of The String
}


