/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Dwidar
 */
#include<util/delay.h>
#include<avr/io.h>
#include"../includes/Hal/lcd.h"
#include"../includes/Hal/keyPad.h"
#include<avr/interrupt.h>
#include"../includes/Mcal/timer.h"
#include"../includes/Hal/buzzer.h"

//#define arraySegment_size           2
//char seg[arraySegment_size];

u8 sec = 0;

extern void(*timerClbk_ptr[4])(void);
u8 flag = 0;

ISR(TIMER0_OVF_vect)
{
	if(timerClbk_ptr[0] != NULL)
	{
		flag++;
		timerClbk_ptr[0]();
	}
}

void buzzer_activation(void)
{
	Buzzer_on();
}


void settingSeconds(void)
{
	if(sec == 10)
	{
		buzzer_activation();
	}


}
void increment_seconds(void)
{
	if(flag == 4)
	{
		sec++;
		flag = 0;
	}
}
void displaySeconds(void)
{
	LCD_moveCurser(1,0);
	LCD_intgerToString(sec);
	_delay_ms(2);
}

int main()
{
	port_init();
	LCD_init();
	SREG = (1<<7);

	timer_setCallBack(increment_seconds,0);

	LCD_displayStringRowColumn(0,0,"Press 0 to start");


	while(1)
	{
		while(KEYPAD_getPressedKey() != 0){}

			LCD_clearScreen();
			LCD_displayStringRowColumn(0,0,"1:ALARM");
			LCD_displayStringRowColumn(1,0,"2:CLOCK");

			_delay_ms(500);


		if(KEYPAD_getPressedKey() == 1)
		{
			LCD_clearScreen();
			timer_init();
			while(sec <= 10)
			{
				displaySeconds();
				_delay_ms(2);
				settingSeconds();
				if(sec == 10)
				{
					Timer0_deInit();
					sec = 0;
					break;
				}
			}


		}
		else if(KEYPAD_getPressedKey() == 2)
		{
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,0,"12 : 28 PM");
		}
	}

}

