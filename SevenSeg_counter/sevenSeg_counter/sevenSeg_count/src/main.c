/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Dwidar
 */
#include"../includes/Mcal/port.h"
#include"../includes/Mcal/dio.h"
#include<util/delay.h>
#include<avr/io.h>
#include"../includes/Hal/sevenSeg.h"
int main()
{
	// Display number
	u8 count = 0;

	// configure pins as output from PA1 to PA7
	// configure pins as input from PD26 to PD28
	port_init();


	// Display ZERO value on the 7-segment
	SevenSegment_Display(count);

	while(1)
	{
		// read push button pin state
		if( !(PIND & (1<<PD2)) )
		{
			_delay_ms(30);
			//check after bouncing
			if( !(PIND & (1<<PD2)) )
			{
				if(count != MAX_DISPLAY_NUM)
				{
					// increment 7-segment every press
					count++;
				}
				// Display the number
				SevenSegment_Display(count);
			}
			// wait until switch is released
			while( !(PIND & (1<<PD2)) ){}
		}
		else if(!(PIND & (1<<PD3)))
		{
			_delay_ms(30);
			if( !(PIND & (1<<PD3)) )
			{
				if(count != MIN_DISPLAY_NUM)
				{
					// decrement 7-segment every press
					count--;
				}
				SevenSegment_Display(count);
			}
			while( !(PIND & (1<<PD3)) ){}
		}
		else if(!(PIND & (1<<PD4)))
		{
			_delay_ms(30);
			if( !(PIND & (1<<PD4)) )
			{
				SevenSegment_Display(MIN_DISPLAY_NUM);
				count = 0;
			}
			while( !(PIND & (1<<PD2)) ){}
		}
	}

}
