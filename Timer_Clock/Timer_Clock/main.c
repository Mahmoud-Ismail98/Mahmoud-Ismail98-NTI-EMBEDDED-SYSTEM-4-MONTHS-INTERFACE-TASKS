/*
 * Timer_Clock.c
 *
 * Created: 11/1/2023 4:01:13 PM
 * Author : Ahmed Wael
 */
#include "Std_types.h"
#include "Bit_utils.h"
#include "MCAL/Dio/inc/Dio.h"
#include "MCAL/Port/inc/Port.h"
#include "MCAL/Timers/inc/Timers.h"
#include "HAL/LCD/inc/LCD.h"

#define OneSec_Ticks 61
#define HalfSec_Ticks (OneSec_Ticks/2)
#define QuarterSec_Ticks (HalfSec_Ticks/2)

/*Init Vlaues*/
u8 Global_u8Secs =55;
u8 Global_u8Mins =55;
u8 Global_u8Hrs =9;

/*Helper Functions*/
void LCD_voidDisplayNumbersHelper(u32 Copy_u32Number)  //To Display Number in 2 Digits
{
	if(Copy_u32Number < 10)
	{
		LCD_voidDisplayNumbers(0);
		LCD_voidDisplayNumbers(Copy_u32Number);
	}
	else
	{
		LCD_voidDisplayNumbers(Copy_u32Number);
	}
}
/*Timer ISR */
void Timer_OVF()
{
	static u16 c=0;
	c++;
	if(c == 3) //Second is fast
	{
		Global_u8Secs++;
		if(Global_u8Secs == 60)
		{
			Global_u8Secs = 0;
			Global_u8Mins++;
			if(Global_u8Mins == 60)
			{
				Global_u8Mins =0;
				Global_u8Hrs++;
				if(Global_u8Hrs == 12)
				{
					Global_u8Hrs=0;
					Global_u8Mins =0;
					Global_u8Secs = 0;
				}
			}
		}
		c=0;
	}
}
int main(void)
{
	Port_vidInit();
	LCD_voidInit();
	/*Creating GUI*/
	LCD_voidDisplayString("Clock");
	LCD_voidGoToXY(6,0);
	LCD_voidDisplayString("__________");
	LCD_voidGoToXY(6,3);
	LCD_voidDisplayString("----------");
	LCD_voidGoToXY(6,1);
	LCD_voidDisplayChar('|');
	LCD_voidGoToXY(6,2);
	LCD_voidDisplayChar('|');
	LCD_voidGoToXY(15,1);
	LCD_voidDisplayChar('|');
	LCD_voidGoToXY(15,2);
	LCD_voidDisplayChar('|');
	LCD_voidGoToXY(7,1);
	LCD_voidDisplayString("hh:mm:ss");
	LCD_voidGoToXY(7,2);
	///////////////////////////////////////

	GIE();
	Timer0_voidInit(Timer0_NormalMode,Timer0_SCALER_1024,OC0_DISCONNECTED);
	Timer0_voidOVF_SetCallBack(Timer_OVF);
	Timer0_voidOVF_InterruptEnable();
    while (1)
    {
		LCD_voidDisplayNumbersHelper(Global_u8Hrs);
		LCD_voidDisplayChar(':');
		LCD_voidDisplayNumbersHelper(Global_u8Mins);
		LCD_voidDisplayChar(':');
		LCD_voidDisplayNumbersHelper(Global_u8Secs);
		LCD_voidGoToXY(7,2);
    }
}

