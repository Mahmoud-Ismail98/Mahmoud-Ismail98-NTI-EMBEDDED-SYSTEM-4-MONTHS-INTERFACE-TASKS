/*
 * Application.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Ismail
 */


#include "Calculator.h"


/* this application is simple calculator on keypad 4*4
*/

u16 GetNumber(u8 charcter)
{
    u8 num = 0;
    switch(charcter)
    {
    case '0':
        num = 0;
        break;
    case '1':
        num = 1;
        break;
    case '2':
        num = 2;
        break;
    case '3':
        num = 3;
        break;
    case '4':
        num = 4;
        break;
    case '5':
        num = 5;
        break;
    case '6':
        num = 6;
        break;
    case '7':
        num = 7;
        break;
    case '8':
        num = 8;
        break;
    case '9':
        num = 9;
        break;
    case 'C':
        LCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
        num = Error;
        break;  //this is used as a clear screen and then reset by setting error
    default:
        DispError(0);
        num = Error;
        break;       //it means wrong input
    }
    return num;
}

u8 GetOperation(u8 fun)            //detects the errors in function
{
    if(fun=='C')                   //if clear screen then clear the LCD and reset
    {
    	LCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
        return 'e';
    }
    if( fun != '+' && fun != '-' && fun != '*' && fun != '/' )  //if input is not from allowed functions then show error
    {
        DispError(1);
        return 'e';
    }
    return fun;                        //function is correct so return the correct function
}


void DispError(u16 numb)           //displays different error messages
{
	u8 msg1[] = {"Wrong Input"};
	u8 msg2[] = {"Wrong Function"};

 	LCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);            //clear display
    switch(numb)
    {
    case 0:
        LCD_WriteString(msg1);
        break;
    case 1:
    	LCD_WriteString(msg2);
        break;
    default:
    	LCD_WriteString(msg1);
        break;
    }
}

void DispNumber(s16 numb)            //displays number on LCD
{
    u8 UnitDigit  = 0;  //It will contain unit digit of numb
    u8 TenthDigit = 0;  //It will contain 10th position digit of numb

    if(numb<0)    {
        numb = -1*numb;          // Make number positive
        LCD_WriteChar4Bit('-');   // Display a negative sign on LCD
    }
    TenthDigit = (numb/10);                    // Find out Tenth Digit

    if( TenthDigit != 0)                    // If it is zero, then don't display
    	LCD_WriteChar4Bit(TenthDigit+0x30);    // Make Char of TenthDigit and then display it on LCD
		UnitDigit = numb - TenthDigit*10;
		LCD_WriteChar4Bit(UnitDigit+0x30);    // Make Char of UnitDigit and then display it on LCD
}
