/*
 * main.c
 *
 *  Created on: Oct 24, 2023
 *      Author: bishoy18126
 */
#include "../inc/LIB/Bit_utils.h"
#include "../inc/LIB/Std_types.h"
#include "../inc/MCAL/ADC/ADC_int.h"
#include "../inc/MCAL/DIO/DIO_int.h"
#include "../inc/MCAL/EXTI/EXTI_int.h"
#include "../inc/MCAL/GIE/GIE_int.h"
#include "../inc/MCAL/PORT/PORT.h"
#include "../inc/MCAL/TIMER0/TIMER0_int.h"
#include "../inc/HAL/KEYPAD/KEYPAD_int.h"
#include "../inc/HAL/LCD/LCD.h"

void func(void);
u8 Hours = 1;
u8 Minutes = 0;
u8 Seconds = 0;
int main(void)
{
	PORT_voidInit();
	LCD_voidInit();
	//KEYPAD_voidInit();
	LCD_voidInit();
	TIMER0_voidSetCallBack(func);
	TIMER0_voidSetTimeOnNormalMode(10,8);
	TIMER0_voidInit();
	TIMER0_voidInterruptEnable(OVERFLOW_INT);

	//M_GIE_void_EnableGlobalInterrupt();
	while(1)
	{
		M_GIE_void_DisableGlobalInterrupt();
		LCD_voidSetCursorToX_y(LCD_ROW0,LCD_Coloumn0);
		if(Hours < 10)
		{
			LCD_voidWriteChar('0');
			LCD_voidWriteNumbers(Hours);
			LCD_voidWriteChar(':');
		}
		else
		{
			LCD_voidWriteNumbers(Hours);
			LCD_voidWriteChar(':');
		}
		if(Minutes == 0)
		{
			LCD_voidWriteChar('0');
			LCD_voidWriteChar('0');
			LCD_voidWriteChar(':');
		}
		else if(Minutes < 10)
		{
			LCD_voidWriteChar('0');
			LCD_voidWriteNumbers(Minutes);
			LCD_voidWriteChar(':');
		}
		else
		{
			LCD_voidWriteNumbers(Minutes);
			LCD_voidWriteChar(':');
		}
		if(Seconds == 0)
		{
			LCD_voidWriteChar('0');
			LCD_voidWriteChar('0');
		}
		else if(Seconds < 10)
		{
			LCD_voidWriteChar('0');
			LCD_voidWriteNumbers(Seconds);
		}
		else
		{
			LCD_voidWriteNumbers(Seconds);
		}
		M_GIE_void_EnableGlobalInterrupt();
	}
	return 0;
}

void func(void)
{

	Seconds++;
	if(Seconds>59)
	{
		Minutes++;
		Seconds = 0;
	}
	if(Minutes>59)
	{
		Hours++;
		Minutes = 0;
	}
	if(Hours>12)
	{
		Hours = 1;
	}
}
