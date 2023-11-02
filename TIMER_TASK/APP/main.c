#include "../LIB/Include/STD_TYPES.h"
#include "../LIB/Include/BIT_MATH.h"
#include "../MCAL/PORT/Include/PORT_interface.h"
#include "../MCAL/DIO/Include/DIO_interface.h"
#include "../MCAL/GIE/Include/GIE_interface.h"
#include "../MCAL/TIMER/Include/TIMER_interface.h"
#include "../HAL/LCD/Include/LCD_interface.h"
#include "../HAL/KPD/Include/KPD_interface.h"
#define F_CPU   8000000UL
#include <util/delay.h>
void Timer_Alarm(void);
void Timer_Clock(void);
#define   CLOCK         1
#define   ALARM         2
u8 KPD_u8Read = 0;
u8 KPD_u8ReadAlarm = 25;
u8 TIMER_u8_COUNT = 0;
u8 Minute=0,Hour=0;
int main(void)
{
	PORT_voidInit();
	GIE_voidInit(GIE_u8_ENABLE);
	LCD_voidInit();
	TIMER_TIMEREnumTimer0Init(TIMER_CTC_MODE);
	LCD_voidGoToXY(LCD_u8_ROW1,LCD_u8_COL0);
	LCD_u8DisplayString("ENTER YOUR CHOICE:");
	LCD_voidGoToXY(LCD_u8_ROW2,LCD_u8_COL0);
	LCD_u8DisplayString("1-CLOCK:");
	LCD_voidGoToXY(LCD_u8_ROW3,LCD_u8_COL0);
	LCD_u8DisplayString("2-ALARM:");
	while(1)
	{
		KPD_KPDEnumGetKeyState(&KPD_u8Read);
		if(KPD_u8Read == CLOCK)
		{
			LCD_voidDisplayClear();
			LCD_voidGoToXY(LCD_u8_ROW1,LCD_u8_COL0);
			LCD_u8DisplayString("HH:MM:SS");
			LCD_voidGoToXY(LCD_u8_ROW2,LCD_u8_COL0);
			LCD_u8DisplayString("00:00:00");
			while(Hour != 2)
			{
				TIMER_TIMEREnumTimer0Callback(TIMER_CTC_MODE,&Timer_Clock);
			}
			break;
		}
		else if(KPD_u8Read == ALARM)
		{
			LCD_voidDisplayClear();
			LCD_voidGoToXY(LCD_u8_ROW1,LCD_u8_COL0);
			LCD_u8DisplayString("TIME IN SECOND:");
//			KPD_KPDEnumGetKeyState(&KPD_u8ReadAlarm);
			LCD_voidGoToXY(LCD_u8_ROW1,LCD_u8_COL16);
			LCD_voidDisplayNumber(KPD_u8ReadAlarm);
			while(KPD_u8ReadAlarm != 0)
			{
				TIMER_TIMEREnumTimer0Callback(TIMER_CTC_MODE,&Timer_Alarm);
			}
			DIO_DioEnumWriteChannel(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_HIGH);
			LCD_voidDisplayClear();
			LCD_voidGoToXY(LCD_u8_ROW1,LCD_u8_COL0);
			LCD_u8DisplayString("BUZZER ENABLE");
			break;
		}
	}
	return 0;
}

void Timer_Alarm(void)
{
	if(KPD_u8ReadAlarm <10)
	{
		LCD_voidGoToXY(LCD_u8_ROW2,LCD_u8_COL5);
		LCD_voidDisplayCharacter(' ');
		LCD_voidGoToXY(LCD_u8_ROW2,LCD_u8_COL6);
		LCD_voidDisplayNumber(KPD_u8ReadAlarm);
	}
	else
	{
		LCD_voidGoToXY(LCD_u8_ROW2,LCD_u8_COL5);
		LCD_voidDisplayNumber(KPD_u8ReadAlarm);
	}
	KPD_u8ReadAlarm--;
}

void Timer_Clock(void)
{
	TIMER_u8_COUNT += 1;
	if(TIMER_u8_COUNT <= 9)
	{
		LCD_voidGoToXY(LCD_u8_ROW2,LCD_u8_COL7);
		LCD_voidDisplayNumber(TIMER_u8_COUNT);
	}
	else if((TIMER_u8_COUNT > 9) && (TIMER_u8_COUNT <= 60))
	{
		LCD_voidGoToXY(LCD_u8_ROW2,LCD_u8_COL6);
		LCD_voidDisplayNumber(TIMER_u8_COUNT);
	}
	else
	{
		LCD_voidGoToXY(LCD_u8_ROW2,LCD_u8_COL6);
		LCD_voidDisplayCharacter('0');
		TIMER_u8_COUNT = 0;
		Minute++;
		if(Minute <= 9)
		{
			LCD_voidGoToXY(LCD_u8_ROW2,LCD_u8_COL4);
			LCD_voidDisplayNumber(Minute);
		}
		else if((Minute > 9) && (Minute <= 60))
		{
			LCD_voidGoToXY(LCD_u8_ROW2,LCD_u8_COL3);
			LCD_voidDisplayNumber(Minute);
		}
		else
		{
			LCD_voidGoToXY(LCD_u8_ROW2,LCD_u8_COL3);
			LCD_voidDisplayCharacter('0');
			Minute = 0;
			Hour++;
			if(Hour <= 9)
			{
				LCD_voidGoToXY(LCD_u8_ROW2,LCD_u8_COL1);
				LCD_voidDisplayNumber(Hour);
			}
			else if((Hour > 9) && (Minute <= 60))
			{
				LCD_voidGoToXY(LCD_u8_ROW2,LCD_u8_COL0);
				LCD_voidDisplayNumber(Hour);
			}
		}
	}
}


