/*
 * main.c
 *
 *  Created on: Oct 30, 2023
 *      Author: bishoy18126
 */
#include "STD_TYPES.h"
#include "Bit_utils.h"

#include "PORT.h"
#include "DIO_int.h"
#include "UART.h"
#include "LCD.h"
#include"I2C.h"
#include"EEPROM.h"
#include <util/delay.h>

int main(void)
{
	LCD_voidInit();
	PORT_voidInit();
	I2C_voidInit();
	//DIO_enum_WriteChannel(DIO_u8PORTAPIN0, DIO_u8High);


	EEPROM_voidWriteByte('B',0);
	_delay_ms(2000);
	EEPROM_voidWriteByte('E',1);
	_delay_ms(2000);
	EEPROM_voidWriteByte('S',2);
	_delay_ms(2000);
	EEPROM_voidWriteByte('H',3);
	_delay_ms(2000);
	EEPROM_voidWriteByte('O',4);
	_delay_ms(2000);
	//DIO_enum_WriteChannel(DIO_u8PORTAPIN0, DIO_u8High);

	u8 data;
	LCD_voidInit();
	while(1)
	{
		//LCD_voidInit();
		LCD_voidSetCursorToX_y(0,0);
		for(u8 i=0;i<5;i++)
		{

			EEPROM_voidReadByte(&data,i);
			LCD_voidWriteChar(data);
			_delay_ms(2000);
		}
		/*if(data == 'A')
		{
			//DIO_enum_WriteChannel(DIO_u8PORTAPIN0, DIO_u8LOW);
			DIO_enum_FlipChannel(DIO_u8PORTAPIN1);
			_delay_ms(2000);
		}*/
	}
	return 0;
}
