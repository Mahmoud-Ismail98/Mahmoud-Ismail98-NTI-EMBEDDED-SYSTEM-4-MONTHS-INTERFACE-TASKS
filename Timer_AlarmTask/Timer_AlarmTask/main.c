/*
 * Timer_AlarmTask.c
 *
 * Created: 10/24/2023 2:16:28 PM
 * Author : Ahmed Wael
 */

#define F_CPU 16000000
#include "util/delay.h"

#include "Std_types.h"
#include "Bit_utils.h"
#include "MCAL/Port/inc/Port.h"
#include "MCAL/Dio/inc/Dio.h"
#include "MCAL/EXTI/inc/EXTI.h"
#include "MCAL/Timers//inc/Timers.h"
#include "HAL/LCD/inc/LCD.h"
#include "HAL/KeyPad/inc/Keypad.h"


#define BUZZ_PIN DIO_u8CHANNEL22

typedef enum {
	Set_Time,
	Counting_Time
}Sys_Mode;
//////////////////////////

//Global Variables
u16 Global_u16Time = 0;
Sys_Mode Mode = Set_Time;
//////////////////////////

//Helper Functions
void Buzz_voidOn() {
	Dio_enuWriteChannel(BUZZ_PIN,DIO_u8LEVEL_HIGH);
}

void Buzz_voidOff() {
	Dio_enuWriteChannel(BUZZ_PIN,DIO_u8LEVEL_LOW);
}
/*To Display Each Number after Entering it*/
void KeyPad_voidGetNumberHelper(pu16 Copy_u16Num)
{
	u8 Local_u8Button = 0;
	u8 Local_u8Temp = 0;
	u16 Local_u16Result = 0;
	do
	{
		KeyPad_voidGetButton(&Local_u8Button);
		if(Local_u8Button != 0  && Local_u8Button != '.')
		{
			Local_u8Temp = Local_u8Button - '0';
			Local_u16Result = (Local_u16Result*10) + Local_u8Temp;
			LCD_voidDisplayNumbers(Local_u8Temp);
			Local_u8Button = 0;
		}

		else
		{

		}

	}while(Local_u8Button != '.' );
	*Copy_u16Num = Local_u16Result;
}
//////////////////////////

//Interrupt Functions
void Timer_voidFunc()
{
	static u8 c;
	c++;
	{
		if(c == 62)
		{
			Global_u16Time--;
			c=0;
		}
	}
}

void EXTI_voidFunc()
{
	Mode^=1;
}
/////////////////////
int main(void)
{
	Port_vidInit();
	LCD_voidInit();
	Timer0_voidInit(Timer0_NormalMode,Timer0_SCALER_1024,OC0_DISCONNECTED); //OVF interrupt after 16.384ms
	Timer0_voidOVF_SetCallBack(Timer_voidFunc);
	EXTI_voidEnable(EXTI_INT0);
	EXTI_voidSetPinMode(EXTI_INT0, EXTI_FALLING);
	EXTI_voidSetCallBack(EXTI_INT0,EXTI_voidFunc);
	GIE();
    while (1)
    {
		switch(Mode)
		{
			case Set_Time:

			Timer0_voidOVF_InterruptDisable();
			Buzz_voidOff();

			LCD_voidClear();
			LCD_voidDisplayString("Enter Time: ");
			KeyPad_voidGetNumberHelper(&Global_u16Time);
			LCD_voidClear();

			Timer0_voidOVF_InterruptEnable();
			Mode = Counting_Time;
			break;
///////////////////////////////////////////////////////////////
			case Counting_Time:
			if(Global_u16Time == 0)
			{
				Buzz_voidOn();
				Timer0_voidOVF_InterruptDisable();
				LCD_voidGoToXY(0,0);
				LCD_voidDisplayNumbers(Global_u16Time);
			}
			else
			{
				LCD_voidGoToXY(0,0);
				LCD_voidDisplayNumbers(Global_u16Time);
				LCD_voidDisplayString("    ");
			}
			break;
		}
    }
}

