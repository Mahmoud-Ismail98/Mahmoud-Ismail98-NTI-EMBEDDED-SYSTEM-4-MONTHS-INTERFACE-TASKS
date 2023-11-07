/*
 * LCD.c
 *
 * Created: 10/22/2023 10:06:09 AM
 *  Author: Mahmoud Tariq
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CLCK.h"
#include "util/delay.h"
/*MCAL Drivers Includes*/
#include "PORT.h"
#include "DIO.h"
#include "DIO_PRIVATE.h"
/*HAL Drivers Includes*/
#include "LCD.h"
#include "LCD_CFG.h"
#include "LCD_PRIVATE.h"






void LCD_vidSendFallingEdge(void)
{
	  PORT_enuSetPinMode(LCD_EN,OUTPUT_HIGH);
	   _delay_ms(1);
	   PORT_enuSetPinMode(LCD_EN,OUTPUT_LOW);
	   _delay_ms(1);
} 
void LCD_vidSendCMD(u8 CMD){
	/*Pulling RS PIN TO LOW TO Init Commands Register*/
	PORT_enuSetPinMode(LCD_RS,OUTPUT_LOW);
	PORT_enuSetPinMode(LCD_RW,OUTPUT_LOW);
	//_delay_ms(15);	
	/*Sending High Nibble*/
	DIO_enuWriteChannel(LCD_D4,GET_BIT(CMD,7));
	DIO_enuWriteChannel(LCD_D3,GET_BIT(CMD,6));
	DIO_enuWriteChannel(LCD_D2,GET_BIT(CMD,5));
	DIO_enuWriteChannel(LCD_D1,GET_BIT(CMD,4));
	/*Sending Falling edge to trigger enable pin*/
	LCD_vidSendFallingEdge();
	/*Sending Low  Nibble*/
	DIO_enuWriteChannel(LCD_D4,GET_BIT(CMD,3));
	DIO_enuWriteChannel(LCD_D3,GET_BIT(CMD,2));
	DIO_enuWriteChannel(LCD_D2,GET_BIT(CMD,1));
	DIO_enuWriteChannel(LCD_D1,GET_BIT(CMD,0));

	/*Sending Falling edge to trigger enable pin*/
	LCD_vidSendFallingEdge();
}
void LCD_vid4Bit_Init(){
	_delay_ms(30);
	/*Initializing data Pins Mode as Output*/
	PORT_enuSetPinDirection(LCD_D1,PORT_PIN_OUTPUT);
	PORT_enuSetPinDirection(LCD_D2,PORT_PIN_OUTPUT);
	PORT_enuSetPinDirection(LCD_D3,PORT_PIN_OUTPUT);
	PORT_enuSetPinDirection(LCD_D4,PORT_PIN_OUTPUT);
	/*Initializng RS PIN and EN PIN as Output*/
	PORT_enuSetPinDirection(LCD_RS,PORT_PIN_OUTPUT);
	PORT_enuSetPinDirection(LCD_EN,PORT_PIN_OUTPUT);
	/*Writing RW PIN to LOW*/
	PORT_enuSetPinMode(LCD_RW,OUTPUT_LOW);
	_delay_ms(20);
	LCD_vidSendCMD(0x33);			//Command to init cursor at the beginning of the display
	LCD_vidSendCMD(0x32);			//Command to init cursor at the beginning of the display
	LCD_vidSendCMD(LCD_FUNCTION_4BIT_2LINES );  //command to start screen using 4bit data mode and init 2 lines
	LCD_vidSendCMD(LCD_RETURN_HOME);			//Command to init cursor at the beginning of the display

	/*Clearing the display*/
	LCD_vidSendCMD(LCD_CLEAR_SCREEN);
	//shift cursor to right
	_delay_ms(4);	
	LCD_vidSendCMD(LCD_ENTRY_MODE);	
	//Display On cursor On
	_delay_ms(1);
	LCD_vidSendCMD(LCD_DISP_ON_CURSOR_ON );
	_delay_ms(1);
	
	
}

void LCD_vidMoveCusrsor(u8 copy_x , u8 copy_y)
{
	/*
if(copy_x == 0)
LCD_vidSendCMD(LCD_16COL_ROW1_BASE_ADD + (copy_y & 0x0FU));
else if(copy_x == 1)
LCD_vidSendCMD(LCD_16COL_ROW2_BASE_ADD + (copy_y & 0x0FU));
*/

if(copy_x == 0)
LCD_vidSendCMD(   (((LCD_20COL_ROW1_BASE_ADD + copy_y) & 0X7F) | (0X80)));
else if(copy_x == 1)
LCD_vidSendCMD(   (((LCD_20COL_ROW2_BASE_ADD + copy_y) & 0X7F) | (0X80)));
else if(copy_x == 2)
LCD_vidSendCMD(   (((LCD_20COL_ROW3_BASE_ADD + copy_y) & 0X7F) | (0X80)));
else if(copy_x == 3)
LCD_vidSendCMD(   (((LCD_20COL_ROW4_BASE_ADD + copy_y) & 0X7F) | (0X80)));



}
void LCD_vidDisplayChar(u8 copy_char){
	
	
	/*Pulling RS PIN TO HIGH TO Init Data Register*/
	DIO_enuWriteChannel(LCD_RS,DIO_HIGH);
	/*RW TO low to enable writing to lcd register*/
	//DIO_enuWriteChannel(LCD_RW,0);
	/*Sending High Nibble*/
	DIO_enuWriteChannel(LCD_D4,GET_BIT(copy_char,7));
	DIO_enuWriteChannel(LCD_D3,GET_BIT(copy_char,6));
	DIO_enuWriteChannel(LCD_D2,GET_BIT(copy_char,5));
	DIO_enuWriteChannel(LCD_D1,GET_BIT(copy_char,4));
	LCD_vidSendFallingEdge();
	
	/*Sending Low  Nibble*/
	DIO_enuWriteChannel(LCD_D4,GET_BIT(copy_char,3));
	DIO_enuWriteChannel(LCD_D3,GET_BIT(copy_char,2));
	DIO_enuWriteChannel(LCD_D2,GET_BIT(copy_char,1));
	DIO_enuWriteChannel(LCD_D1,GET_BIT(copy_char,0));
	LCD_vidSendFallingEdge();		
}
void LCD_vidDisplayString (pu8 add_string)
{
	u8 i = 0;
	
	
	while(add_string[i] != '\0')
	{
		LCD_vidDisplayChar(add_string[i]);
		i++;
		_delay_ms(100);
	}
}

void LCD_vidDisplayCustomChar(pu8 add_custom_char,u8 copy_u8Index){
	if (add_custom_char != NULL &&copy_u8Index <8){
		
		u8 loc_u8iterator;
		LCD_vidSendCMD(LCD_CGRAM_BASE_ADD + (8*copy_u8Index));
		for(loc_u8iterator=0 ; loc_u8iterator<8 ; loc_u8iterator++)
		{
			LCD_vidDisplayChar(add_custom_char[loc_u8iterator]);
		}	
			LCD_vidSendCMD(LCD_DDRAM_BASE_ADD);
	}
}

void LCD_vidClearDisplay(void){
	LCD_vidSendCMD(LCD_CLEAR_SCREEN);
}
void LCD_vidSetCursorHome(void){
	LCD_vidSendCMD(LCD_RETURN_HOME);
}
void LCD_vidDisplayInt(u64 copy_int){
	u64 local_u8numberInReverse = 1;
	if (copy_int == 0){
		LCD_vidDisplayChar( 0x30 + 0);
		}else {
		while (copy_int != 0) {
			local_u8numberInReverse *= 10  ;
			local_u8numberInReverse += (copy_int % 10);
			copy_int /= 10;
		}
		while (local_u8numberInReverse != 1) {
			LCD_vidDisplayChar( 0x30 + (local_u8numberInReverse % 10));
			local_u8numberInReverse /= 10;
		}
	}

}