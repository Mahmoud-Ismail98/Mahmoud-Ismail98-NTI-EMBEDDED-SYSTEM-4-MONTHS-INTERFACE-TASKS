/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Dwidar
 */
#include<util/delay.h>
#include"../includes/Hal/sevenSeg.h"
#include<avr/interrupt.h>
#include"../includes/Mcal/exInterrupt.h"
#include"../includes/Mcal/timer.h"

#define arraySegment_size           4
char seg[arraySegment_size];

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

void settingSegment(void)
{
	if(seg[0] == 10)
	{
		seg[0] = 0;
		seg[1]++;
	}

	if(seg[1] == 6)
	{
		seg[0] = 0;
		seg[1] = 0;
		seg[2]++;
	}


	if(seg[2] == 10)
	{
		seg[0] = 0;
		seg[1] = 0;
		seg[2] = 0;
		seg[3]++;
	}

	if(seg[3] == 6)
	{
		seg[0] = 0;
		seg[1] = 0;
		seg[2] = 0;
		seg[3] = 0;
	}

}

void clear_button(void)
{
	SEVENSEG_PORT = 0x00;

	seg[0] = 0;
	seg[1] = 0;
	seg[2] = 0;
	seg[3] = 0;
}
void increment_button(void)
{
	if(flag == 4)
	{
		seg[0]++;
		flag = 0;
	}
}

void displaySegment(void)
{
	int i;
	for(i = 0; i < arraySegment_size; i++)
	{
		DISPLAY_PORT = (1<<i);
		SevenSegment_Display(seg[i]);
		_delay_ms(2);
	}
}
int main()
{
	port_init();
	timer_init();


	SEVENSEG_PORT = 0x00;
	DISPLAY_PORT = 0x01;
	SREG = (1<<7);

	timer_setCallBack(increment_button,0);
	exInt0_enable(FALLING_EDGE_INT_REQ);

	callBack(clear_button,0);


	while(1)
	{
		displaySegment();
		_delay_ms(2);
		settingSegment();
	}

}
