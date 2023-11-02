/*
 * lcd.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Dwidar
 */
#include"lcd.h"
#include<stdlib.h>
#include<stdio.h>


void LCD_init(void)
{
#if(DATA_BITS_MODE == EIGHT_BITS_MODE)

	_delay_ms(30);

	LCD_sendCommand(LCD8_2_LINES_COMMAND);

#elif(DATA_BITS_MODE == FOUR_BITS_MODE)

		setPinDirection(LCD_DB4_PIN_ID,PIN_OUTPUT);
		setPinDirection(LCD_DB5_PIN_ID,PIN_OUTPUT);
		setPinDirection(LCD_DB6_PIN_ID,PIN_OUTPUT);
		setPinDirection(LCD_DB7_PIN_ID,PIN_OUTPUT);

		_delay_ms(30);

		LCD_sendCommand(LCD4_2_LINES_INIT1_COMMAND);
		_delay_ms(1);
		LCD_sendCommand(LCD4_2_LINES_INIT2_COMMAND);
		_delay_ms(1);
		LCD_sendCommand(LCD4_2_LINES_SET_COMMAND);

#endif

		LCD_sendCommand(LCD_CURSOR_OFF);
		LCD_sendCommand(LCD_SCREEN_CLEAR);
}
void LCD_sendCommand(u8 command)
{
	dio_writePin(LCD_RS_PIN_ID,LOGIC_LOW);
	_delay_ms(1);
	dio_writePin(LCD_E_PIN_ID,LOGIC_HIGH);
	_delay_ms(1);

#if(DATA_BITS_MODE == EIGHT_BITS_MODE)

	dio_writePort(LCD_DATA_PORT_ID,command);
	_delay_ms(1);
	dio_writePin(LCD_E_PIN_ID,LOGIC_LOW);
	_delay_ms(1);

#elif(DATA_BITS_MODE == FOUR_BITS_MODE)

	dio_writePin(LCD_DB4_PIN_ID,GET_BIT(command,4));
	dio_writePin(LCD_DB5_PIN_ID,GET_BIT(command,5));
	dio_writePin(LCD_DB6_PIN_ID,GET_BIT(command,6));
	dio_writePin(LCD_DB7_PIN_ID,GET_BIT(command,7));

	_delay_ms(1);
	dio_writePin(LCD_E_PIN_ID,DIO_LOW);
	_delay_ms(1);
	dio_writePin(LCD_E_PIN_ID,DIO_HIGH);
	_delay_ms(1);

	dio_writePin(LCD_DB4_PIN_ID,GET_BIT(command,0));
	dio_writePin(LCD_DB5_PIN_ID,GET_BIT(command,1));
	dio_writePin(LCD_DB6_PIN_ID,GET_BIT(command,2));
	dio_writePin(LCD_DB7_PIN_ID,GET_BIT(command,3));

	_delay_ms(1);
	dio_writePin(LCD_E_PIN_ID,LOGIC_LOW);
	_delay_ms(1);
#endif

}
void LCD_displayCharacter(u8 character)
{
	dio_writePin(LCD_RS_PIN_ID,LOGIC_HIGH);
	_delay_ms(1);
	dio_writePin(LCD_E_PIN_ID,LOGIC_HIGH);
	_delay_ms(1);

#if(DATA_BITS_MODE == EIGHT_BITS_MODE)

	dio_writePort(LCD_DATA_PORT_ID,character);
	_delay_ms(1);
	dio_writePin(LCD_E_PIN_ID,LOGIC_LOW);
	_delay_ms(1);

#elif(DATA_BITS_MODE == FOUR_BITS_MODE)

	dio_writePin(LCD_DB4_PIN_ID,GET_BIT(character,4));
	dio_writePin(LCD_DB5_PIN_ID,GET_BIT(character,5));
	dio_writePin(LCD_DB6_PIN_ID,GET_BIT(character,6));
	dio_writePin(LCD_DB7_PIN_ID,GET_BIT(character,7));

	_delay_ms(1);
	dio_writePin(LCD_E_PIN_ID,LOGIC_LOW);
	_delay_ms(1);
	dio_writePin(LCD_E_PIN_ID,LOGIC_HIGH);
	_delay_ms(1);

	dio_writePin(LCD_DB4_PIN_ID,GET_BIT(character,0));
	dio_writePin(LCD_DB5_PIN_ID,GET_BIT(character,1));
	dio_writePin(LCD_DB6_PIN_ID,GET_BIT(character,2));
	dio_writePin(LCD_DB7_PIN_ID,GET_BIT(character,3));

	_delay_ms(1);
	dio_writePin(LCD_E_PIN_ID,LOGIC_LOW);
	_delay_ms(1);
#endif

}
void LCD_displayString(pu8 str)
{
	u8 iterator;
	for (iterator = 0; str[iterator] != '\0'; iterator++)
	{
		LCD_displayCharacter(str[iterator]);
	}
}
void LCD_moveCurser(u8 row,u8 col)
{
	u8 lcd_memory_adress;

#if(LCD_NUM_OF_COLUMNS == LCD_16_COLS)
	switch(row)
	{
	case 0:
		lcd_memory_adress = col;
		break;
	case 1:
		lcd_memory_adress = col + 0x40;
		break;
	case 2:
		lcd_memory_adress = col + 0x14;
		break;
	case 3:
		lcd_memory_adress = col + 0x54;
		break;
	}

#elif(LCD_NUM_OF_COLUMNS == LCD_20_COLS)
	switch(row)
	{
	case 0:
		lcd_memory_adress = col;
		break;
	case 1:
		lcd_memory_adress = col + 0x40;
		break;
	case 2:
		lcd_memory_adress = col + 0x14;
		break;
	case 3:
		lcd_memory_adress = col + 0x54;
		break;

	}
#endif

	LCD_sendCommand(lcd_memory_adress | LCD_SET_CURSOR_LOCATION);
}
void LCD_displayStringRowColumn(u8 row,u8 col,pu8 str)
{
	LCD_moveCurser(row,col);
	LCD_displayString(str);
}
//void LCD_displayNumber(u32 number)
//{
//	u32 loc_inverse = 0;
//	while(number != 0)
//	{
//	loc_inverse = ( (loc_inverse * 10) + (number % 10) );
//	}
//
//	while(loc_inverse != 0)
//	{
//		LCD_displayCharacter( (loc_inverse % 10) + '0' );
//		loc_inverse /= 10;
//	}
//}
void LCD_intgerToString(u32 data)
{
	char buff[32];
	itoa(data,buff,10);
	LCD_displayString(buff);
}
void LCD_creatCustomCharacter(pu8 character, u8 index)
{
	u8 iterator;
	u8 loc_CGRAM_aaddress;

	if(index < 8)
	{
		loc_CGRAM_aaddress =( LCD_CGRAM_BASE_ADDRESS + (index * LCD_NUMBER_OF_LOCATIONS_IN_CGRAM) );
		LCD_sendCommand(loc_CGRAM_aaddress);

		for(iterator = 0; iterator < LCD_NUMBER_OF_LOCATIONS_IN_CGRAM; iterator++)
		{
			LCD_displayCharacter(character[iterator]);
		}
		_delay_ms(2);
		LCD_sendCommand(LCD_SET_CURSOR_LOCATION);
	}
}
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_SCREEN_CLEAR);
}
void shiftDisplay_right(void)
{
	LCD_sendCommand(LCD_SHIFT_DISPLAY_RIGHT);
}
