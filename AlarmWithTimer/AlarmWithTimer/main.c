/*
 * main.c
 *
 *  Created on: Oct 24, 2023
 *      Author: bishoy18126
 */
#include "Std_types.h"
#include "Bit_utils.h"

#include "GIE_int.h"
#include "PORT.h"
#include "DIO_int.h"
#include "ADC_int.h"
#include "LCD.h"
#include "EXTI_int.h"
#include "TIMER0_int.h"
#include "KEYPAD_int.h"
void func(void);
u32 TimerVal = 0;
//u32 TimerCounter = 0;
u8 flag = 0;

int main(void)
{
	PORT_voidInit();
	LCD_voidInit();
	KEYPAD_voidInit();
	LCD_voidInit();
	u8 data =0;
	TIMER0_voidSetCallBack(func);
	TIMER0_voidSetTimeOnNormalMode(22000,8);
	TIMER0_voidInit();
	//M_GIE_void_EnableGlobalInterrupt();
	while(1)
	{
		M_GIE_void_DisableGlobalInterrupt();
		LCD_voidSetCursorToX_y(LCD_ROW0,LCD_Coloumn0);
		LCD_voidWriteString("Set Alarm: ");
		LCD_voidWriteNumbers(TimerVal);
		M_GIE_void_EnableGlobalInterrupt();
		data = KEYPAD_voidGetKEYPADVal();
		if(data != 0)
		{
			if(data != '=' && data != '+'&& data != '-' && data != '*'&&data != '/' && data != '.' && flag ==0)
			{
				TimerVal = (TimerVal*10) + (data - '0');
			}
			else if(data == '.')
			{
				if(flag == 0)
				{
					TIMER0_voidInterruptEnable(OVERFLOW_INT);
					flag = 1;
				}
				else if (flag == 1)
				{
					TIMER0_voidInterruptEnable(DISABLE_INT);
					flag = 0;
				}
			}
			else if(data == '=')
			{
				DIO_enum_WriteChannel(DIO_u8PORTAPIN0, 0);
				LCD_voidSendCommand(LCD_CLEAR);
				flag = 0;
				TimerVal = 0;
			}
		}

	}
	return 0;
}

void func(void)
{

	if(flag == 1)
	{
		TimerVal--;
		if(TimerVal == 0)
		{
			DIO_enum_WriteChannel(DIO_u8PORTAPIN0, 1);
			flag = 0;
			LCD_voidSendCommand(LCD_CLEAR);
		}
	}
	else
	{

	}


}
