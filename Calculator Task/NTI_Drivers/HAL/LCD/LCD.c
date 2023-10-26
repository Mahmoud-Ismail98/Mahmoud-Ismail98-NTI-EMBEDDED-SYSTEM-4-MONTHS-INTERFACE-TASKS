/*
 * LCD.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Ismail
 */
#include "LCD.h"
#include <util/delay.h>
void LCDInit4BitMode(){

_delay_ms(30);

//SET DIRECTION OF THE used PINS
//PORTB PIN0 to pin3 DROM 8 -11 FOR DATA, RS =PA3 ,E= PA2

Port_enuSetPinDirection(12,PORT_u8OUTPUT);
Port_enuSetPinDirection(13,PORT_u8OUTPUT);
Port_enuSetPinDirection(14,PORT_u8OUTPUT);
Port_enuSetPinDirection(15,PORT_u8OUTPUT);

//SET DIRECTION OF THE CONTROL PINS
Port_enuSetPinDirection(RS,PORT_u8OUTPUT);
Port_enuSetPinDirection(RW,PORT_u8OUTPUT);
Port_enuSetPinDirection(E,PORT_u8OUTPUT);

//START OF THE INTIALIZATION SEQUENCE
//SEND FUNCTION SET COMMAND
DIO_SetNibbleValue(LCD_PIN_START,DATA_PORT,FUNCTION_SET_MODE_COMMAND>>4);
//SEND THE FALLING EDGE ENABLE
Dio_enuWriteChannel(E,DIO_u8LEVEL_HIGH);
	_delay_ms(2);
Dio_enuWriteChannel(E,DIO_u8LEVEL_LOW);

LCD_WriteCommand4Bit(FUNCTION_SET_MODE_COMMAND);
//SEND DISPLAY CONTROL COMMAND
_delay_ms(1); //SHOULD BE 39US
LCD_WriteCommand4Bit(DISPALY_ON_OFF_COMMAND);
//SEND CLEAR COMMAND
_delay_ms(1); //SHOULD BE 39US
LCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
//SEND ENRTYMODE COMMAND
_delay_ms(2);
LCD_WriteCommand4Bit(ENTRY_MODE_COMMAND);
}
void LCD_WriteCommand4Bit(u8 Copy_u8Command){
	//SET RW TO ZERO
	Dio_enuWriteChannel(RW,DIO_u8LEVEL_LOW);
	//SET RS TO ZERO
	Dio_enuWriteChannel(RS,DIO_u8LEVEL_LOW);
	//set high nibble value of command
	DIO_SetNibbleValue(LCD_PIN_START,DATA_PORT,Copy_u8Command>>4);
	//SEND THE FALLING EDGE ENABLE
	Dio_enuWriteChannel(E,DIO_u8LEVEL_HIGH);
	_delay_ms(2);
	Dio_enuWriteChannel(E,DIO_u8LEVEL_LOW);
	//set LOW nibble value of command
	DIO_SetNibbleValue(LCD_PIN_START,DATA_PORT,Copy_u8Command);
	//SEND THE FALLING EDGE ENABLE
	Dio_enuWriteChannel(E,DIO_u8LEVEL_HIGH);
		_delay_ms(2);
		Dio_enuWriteChannel(E,DIO_u8LEVEL_LOW);
}

/*sending this function an integer from 0 to 7 prints custom char stored in cgram*/
void LCD_WriteChar4Bit(u8 Copy_u8Data){
	//SET RW TO low
	Dio_enuWriteChannel(RW,DIO_u8LEVEL_LOW);
	//SET RS TO high
	Dio_enuWriteChannel(RS,DIO_u8LEVEL_HIGH);
	//set high nibble value of DATA
	DIO_SetNibbleValue(LCD_PIN_START,DATA_PORT,Copy_u8Data>>4);
	//SEND THE FALLING EDGE ENABLE
	Dio_enuWriteChannel(E,DIO_u8LEVEL_HIGH);
	_delay_ms(2);
	Dio_enuWriteChannel(E,DIO_u8LEVEL_LOW);
	//set LOW nibble value of DATA
	DIO_SetNibbleValue(LCD_PIN_START,DATA_PORT,Copy_u8Data);
	//SEND THE FALLING EDGE ENABLE
	Dio_enuWriteChannel(E,DIO_u8LEVEL_HIGH);
		_delay_ms(2);
		Dio_enuWriteChannel(E,DIO_u8LEVEL_LOW);
}
void LCD_WriteString(u8 *u8Copy_u8String){
	u8 Loc_u8Counter=0;
	u8 Copy_u8Data_SizeofString =0;
	for (Loc_u8Counter = 0; u8Copy_u8String[Loc_u8Counter] != '\0'; Loc_u8Counter++){
		Copy_u8Data_SizeofString =Loc_u8Counter+1;
	}
	if(Copy_u8Data_SizeofString>32){
	//print error

	}
	else{
	Loc_u8Counter =0;
	while(Copy_u8Data_SizeofString>0){
		if(Loc_u8Counter<LCD_LINE_LENGTH){
			LCD_WriteChar4Bit(u8Copy_u8String[Loc_u8Counter]);
		     Loc_u8Counter++;
			 Copy_u8Data_SizeofString--;
		}
		else{
			 LCD_SetCursorPosition(LCD_LINE_1, Loc_u8Counter-LCD_LINE_LENGTH);
			 LCD_WriteChar4Bit(u8Copy_u8String[Loc_u8Counter]);
			 Loc_u8Counter++;
			 Copy_u8Data_SizeofString--;
		}
	}
	}

}
void LCD_SetCursorPosition(u8 Copy_u8LineNumber,u8 Copy_u8PositionNumber)
{
if((Copy_u8LineNumber==LCD_LINE_0)||(Copy_u8LineNumber==LCD_LINE_1))
{
	if(Copy_u8PositionNumber<16)
	{
		if(Copy_u8LineNumber==LCD_LINE_0)
		{
			LCD_WriteCommand4Bit(Copy_u8PositionNumber+LCD_LINE0_OFFSET);
		}
		else
		{
			LCD_WriteCommand4Bit(Copy_u8PositionNumber+LCD_LINE1_OFFSET);
		}
	}
}
else
{
	//Wrong Line Chosen
}
}
void LCD_WriteNumber(u32 Copy_u32Number)
	{
		/*Define an array of 10 elements to hold the number digits
		size is 10 because largest number in u32 is 4,294,967,295
		which is 10 digits
		 */
		u8 Loc_u8Arr_Digits[10];

		/*Define a Local Counter to traverse the array*/
		u8 Loc_Counter=0;

		/*Check on the upcoming number*/
		if(Copy_u32Number>0)
		{
			/*Parsing the number into the array*/
			while(Copy_u32Number!=0) //Exit Condition means number is done parsing
			{
				//Extract the Least Significant Digit and Put it in the
				//Array
				Loc_u8Arr_Digits[Loc_Counter]=Copy_u32Number%10 ;

				//Removing the Extracted digit from the number
				Copy_u32Number=Copy_u32Number/10 ;

				//Increasing the counter so the digits are saved in next array element
				Loc_Counter++;

			}

			//Here the parsing is finished and the digits are saved
			//in the array but backwards

			//Take Care Loc_forCounter is signed
			//because we are decrementing it
			s8 Loc_forCounter;
			for(Loc_forCounter=Loc_Counter-1;Loc_forCounter>=0;Loc_forCounter--)
			{
				//Write the digits to the screen in their right order
				//Notice the addition of the number to the ASCII Code
				//of the number 0 because our Function takes ASCII of character
				//to Print on the LCD
				LCD_WriteChar4Bit(Loc_u8Arr_Digits[Loc_forCounter]+'0');
			}

		}
		else
		{
			/*if the number is zero so we have to send ASCII Code of Zero*/
			LCD_WriteChar4Bit('0');
		}

	}
void LCD_CustomChar (pu8 AddCustomChar,u8 index)
{
    u8 Localu8Counter;
    if(index<8)
    {
    	LCD_WriteCommand4Bit (0x40 + (index*8));  /* Command 0x40 and onwards forces
                                       	   	   	   	    CGRAM address */
       for(Localu8Counter=0;Localu8Counter<8;Localu8Counter++)  /* Write 8 arrays values for generation of 1 character */
    	   LCD_WriteChar4Bit(AddCustomChar[Localu8Counter]);
    }
}


