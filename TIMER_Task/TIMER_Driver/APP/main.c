/*
 * TIMER_Driver.c
 *
 * Created: 10/24/2023 12:16:07 AM
 * Author : sharpel
 */ 


#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"
#include "../MCAL/PORT/PORT.h"
#include "../MCAL/WDT/WDT.h"
#include "../MCAL/GIE/Gie.h"
#include "../MCAL/DIO/Dio.h"
#include "../MCAL/TIMER/timer.h"
#include "../HAL/KEYPAD/Keypad.h"
#include "../HAL/LCD/Lcd.h"
#include "../HAL/ICU/ICU.h"
#include "util/delay.h"


void alarm_count(void);
void timeOut(void);
#define APP_READ_CHOICE           0
#define ALARM_CHOICE              1
#define ALARM_COUNT               3
#define CLOCK_CHOICE              2
u8  gl_u8_timeout     = FALSE;
u8  gl_u8_app_state   = FALSE;
u8  gl_u8_lock_state  = FALSE;
u32 gl_u32_alarmstate = FALSE;
u8  gl_u8_buff[5];
u8  gl_u8_buffCount = FALSE;
u8  gl_u8_char_array[16] =
{
	'7','8','9','/',
	'4','5','6','x',
	'1','2','3','-',
	'c','0','=','+',
};

int main(void)
{
	
    PORT_voidInit();
	GIE_status(GIE_ENABLE);
	TIMER0_init();
	LCD_vidInit();
	TIMER0_setcallBack(timeOut);
    while (1) 
    {
		timerTask();
    }
}



void alarm_count(void)
{
	LCD_vidClrDisplay();
	LCD_vidDisplayString("Count Down");
	gl_u32_alarmstate = atoi(gl_u8_buff);
	u32 loc_counter   = 0;
	TIMER0_setTimeAndStart(1,TIME_IN_SECOND,TIMER_RUN_ASYNCH);
	while(loc_counter <= gl_u32_alarmstate)
	{
		if( gl_u8_timeout == TRUE)
		{
			
			LCD_vidGoToXY(3,0);
			LCD_vidDisplayNumber(gl_u32_alarmstate-loc_counter);
			LCD_vidDisplayString("            ");
			loc_counter++;
			gl_u8_timeout = FALSE;
			TIMER0_setTimeAndStart(1,TIME_IN_SECOND,TIMER_RUN_ASYNCH);
		}
		else
		{
			
		}		
		
	}
	
	LCD_vidClrDisplay();
	DIO_enu_WriteChannel(DIO_PORTC_PIN6,DIO_PIN_LEVEL_HIGH);
	LCD_vidDisplayString("TIME OUT ");
	gl_u8_timeout = FALSE;
	TIMER0_setTimeAndStart(3,TIME_IN_SECOND,TIMER_RUN_ASYNCH);
	while(gl_u8_timeout == FALSE);
	DIO_enu_WriteChannel(DIO_PORTC_PIN6,DIO_PIN_LEVEL_LOW);
	gl_u8_timeout = FALSE;
	
}


void timeOut(void)
{
	gl_u8_timeout = TRUE;
	TIMER0_stop();
}


void timerTask(void)
{
	KEYPAD_enu_PressedKey_t loc_enum_pressedKey = KEY_NOTHING;
	switch(gl_u8_app_state)
		{
			case APP_READ_CHOICE:
			{
				if(gl_u8_lock_state == FALSE)
				{
				  LCD_vidClrDisplay();
				  LCD_vidDisplayString("Enter Your Choice");
				  LCD_vidGoToXY(1,0);
				  LCD_vidDisplayString("1-Alarm");
				  LCD_vidGoToXY(2,0);
				  LCD_vidDisplayString("2-Clock");
				  gl_u8_lock_state = TRUE ;	
				}
				
				loc_enum_pressedKey = KEYPAD_GetKey();
				if( loc_enum_pressedKey != KEY_NOTHING)
				{
					LCD_vidGoToXY(3,0);
					if(loc_enum_pressedKey == 8)
					{
						LCD_vidDisplayCharacter(gl_u8_char_array[loc_enum_pressedKey]);
						LCD_vidDisplayString("    ");
						gl_u8_app_state  = ALARM_CHOICE;
						gl_u8_lock_state = FALSE;
						
					}
					else if (loc_enum_pressedKey == 9)
					{
						LCD_vidDisplayCharacter(gl_u8_char_array[loc_enum_pressedKey]);
						LCD_vidDisplayString("    ");
						gl_u8_app_state  = CLOCK_CHOICE;
						gl_u8_lock_state = FALSE;
					}
					else
					{
						
						LCD_vidDisplayString("ERROR");
					}
					
					
				}
				else
				{
					// do nothing
				}
				break;
			}
			case ALARM_CHOICE:
			{
				if(gl_u8_lock_state == FALSE)
				{
					LCD_vidClrDisplay();
					LCD_vidDisplayString("Enter Time In second");
					LCD_vidGoToXY(2,0);
					gl_u8_lock_state = TRUE;
				}
					loc_enum_pressedKey = KEYPAD_GetKey();
					if(loc_enum_pressedKey == 14)
					{
						gl_u8_app_state = ALARM_COUNT;
						gl_u8_lock_state = FALSE;
					}
					else if ( loc_enum_pressedKey == KEY_NOTHING)
					{
						
					}
					else
					{
						LCD_vidDisplayCharacter(gl_u8_char_array[loc_enum_pressedKey]);
						gl_u8_buff[gl_u8_buffCount++]=gl_u8_char_array[loc_enum_pressedKey];
					}
				
				break;
			}
			
			case ALARM_COUNT:
			alarm_count();
			gl_u8_app_state = APP_READ_CHOICE;
			gl_u8_lock_state =FALSE;
			break;
			
			case CLOCK_CHOICE:
			if(gl_u8_lock_state == FALSE)
			{
				LCD_vidClrDisplay();
				gl_u8_lock_state =TRUE;
			}
			clock_start();
			gl_u8_lock_state =FALSE;
			gl_u8_app_state = APP_READ_CHOICE;
			break;
		}
}

void clock_start(void)
{
	u8 loc_lock = 0;
	u8 sec=0,min=0,h =0;
	LCD_vidDisplayString("HH:MM:SS");
	LCD_vidGoToXY(1,0);
	LCD_vidDisplayString("  :  :  ");
	
	while(KEYPAD_GetKey() != 12)
	{
		if(gl_u8_timeout == FALSE && loc_lock == 0)
		{
			LCD_vidGoToXY(1,0);
			if(h<10)
			{
				if(h==0)
				LCD_vidDisplayCharacter('0');
				LCD_vidDisplayCharacter('0');
			}
			LCD_vidDisplayNumber(h);
			LCD_vidGoToXY(1,3);
			if(min<10)
			{
				if(min==0)
				LCD_vidDisplayCharacter('0');
				LCD_vidDisplayCharacter('0');
			}
			LCD_vidDisplayNumber(min);
			LCD_vidGoToXY(1,6);
			if(sec<10)
			{
				if(sec==0)
				LCD_vidDisplayCharacter('0');
				LCD_vidDisplayCharacter('0');
			}
			LCD_vidDisplayNumber(sec);
			loc_lock = 1 ;
			TIMER0_setTimeAndStart(1,TIME_IN_SECOND,TIMER_RUN_ASYNCH);
		}
		else if (gl_u8_timeout == TRUE)
		{
			gl_u8_timeout = FALSE;
			loc_lock = 0;
			sec++;
			if(sec == 60)
			{
				sec = 0;
				min++;
			}
			else if (min == 60)
			{
				min = 0;
				h++;
			}
			
		}
	}
	
}