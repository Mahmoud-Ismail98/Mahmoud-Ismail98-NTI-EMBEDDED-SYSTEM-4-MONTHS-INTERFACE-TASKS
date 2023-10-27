/*
* AVR_DRIVERS.c
*
* Created: 10/20/2023 8:33:11 PM
* Author : ahmed radwan
*/
#define F_CPU 16000000UL
#include <util/delay.h>
#include "SERVICES/Standard_Data_Types.h"
#include "SERVICES/Bit_Wise_Operations.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/DIO/DIO.h"
#include "HAL/BUTTON/BUTTON.h"
#include "HAL/7_SEGMENT/7_SEGMENT.h"
#include "HAL/LCD/LCD_COMANDS.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/GIE/GIE.h"
#include "MCAL/EXTI/EXTI.h"
#include "MCAL/TIMER0/TIMER0.h"
#include "HAL/KEY_PAD/KEY_PAD.h"

u8 *line="____________________";
u8 hamada[] = {
	0B01110,
	0B01110,
	0B11111,
	0B10101,
	0B00100,
	0B01110,
	0B11011,
	0B00000
};

LCD_4BIT_ST lcd={.lcd_pins[0]=PIN_B0_ID_8,
	.lcd_pins[1]=PIN_B1_ID_9,
	.lcd_pins[2]=PIN_B2_ID_10,
	.lcd_pins[3]=PIN_B4_ID_12,
	.lcd_pin_rs=PIN_A3_ID_3,
.lcd_pin_e=PIN_A2_ID_2};

int main(void)
{
	
	Port_vidInit();
	GIE_INIT();
	LCD_vidInit_4bit(&lcd);
	LCD_vidCraetCustomChar_4bit(&lcd,hamada,1);
	LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
	LCD_vidDisplayString_4bit(&lcd,line);
	LCD_vidGotoXY_4bit(&lcd,2,0);
	LCD_vidDisplayString_4bit(&lcd,line);
	LCD_vidGotoXY_4bit(&lcd,3,0);
	LCD_vidDisplayString_4bit(&lcd,line);
	LCD_vidGotoXY_4bit(&lcd,4,0);
	LCD_vidDisplayString_4bit(&lcd,line);
	LCD_vidGotoXY_4bit(&lcd,1,0);
	LCD_vidDisplayChar_4bit(&lcd,1);
	while (1)
	{

		//LCD_vidDisplayChar_4bit(&lcd,keypad_value);
		//1s
		for(u8 row=1;row<=4;row++)
		{
			
			for(u8 col=0;col<=18;col++)
			{	
				LCD_vidGotoXY_4bit(&lcd,row,col);
				LCD_vidDisplayChar_4bit(&lcd,'_');
				LCD_vidDisplayChar_4bit(&lcd,1);
				_delay_ms(100);
			}
			LCD_vidGotoXY_4bit(&lcd,row,19);
			LCD_vidDisplayChar_4bit(&lcd,'_');
		}//1e
		//2s
		LCD_vidGotoXY_4bit(&lcd,1,10);
		LCD_vidDisplayChar_4bit(&lcd,' ');
		for(u8 row=1;row<=4;row++)
		{
			
			for(u8 col=0;col<=18;col++)
			{	
				if(row==1&&col==10)
				{
					LCD_vidGotoXY_4bit(&lcd,row,col);
					LCD_vidDisplayChar_4bit(&lcd,' ');
					row=2;
				}
				else
				{
					LCD_vidGotoXY_4bit(&lcd,row,col);
					LCD_vidDisplayChar_4bit(&lcd,'_');
					LCD_vidDisplayChar_4bit(&lcd,1);
					_delay_ms(100);
				}
			}
			LCD_vidGotoXY_4bit(&lcd,row,19);
			LCD_vidDisplayChar_4bit(&lcd,'_');
		}//2e
		//3
		LCD_vidGotoXY_4bit(&lcd,1,10);
		LCD_vidDisplayChar_4bit(&lcd,'_');
		LCD_vidGotoXY_4bit(&lcd,3,10);
		LCD_vidDisplayChar_4bit(&lcd,' ');
		LCD_vidGotoXY_4bit(&lcd,4,10);
		LCD_vidDisplayChar_4bit(&lcd,'/');
		LCD_vidGotoXY_4bit(&lcd,4,1);
		u8 row=4;
		for(u8 col=0;col<=18;col++)
		{
			
			if(col==10)
			{
				LCD_vidGotoXY_4bit(&lcd,4,10);
				LCD_vidDisplayChar_4bit(&lcd,'_');
				LCD_vidGotoXY_4bit(&lcd,3,10);
				LCD_vidDisplayChar_4bit(&lcd,1);
				row=3;
				LCD_vidGotoXY_4bit(&lcd,3,10);
				LCD_vidDisplayChar_4bit(&lcd,' ');

			}
			else
			{
				LCD_vidGotoXY_4bit(&lcd,row,col);
				LCD_vidDisplayChar_4bit(&lcd,'_');
				LCD_vidDisplayChar_4bit(&lcd,1);
				_delay_ms(100);
			}
		}
		LCD_vidGotoXY_4bit(&lcd,3,19);
		LCD_vidDisplayChar_4bit(&lcd,'_');
		LCD_vidGotoXY_4bit(&lcd,3,10);
		LCD_vidDisplayChar_4bit(&lcd,'|');
		for(u8 finalcol=0;finalcol<10;finalcol++)
		{
			LCD_vidGotoXY_4bit(&lcd,3,finalcol);
			LCD_vidDisplayChar_4bit(&lcd,'_');
			LCD_vidDisplayChar_4bit(&lcd,1);
			_delay_ms(100);
		}
		break;
		
	}
	LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
	LCD_vidGotoXY_4bit(&lcd,2,6);
	LCD_vidDisplayString_4bit(&lcd,"GAME OVER");
	
}

