/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Dwidar
 */

#include "../includes/Hal/lcd.h"
#include "../includes/Mcal/ADC.h"
#include<avr/interrupt.h>

u16 ADCread_var;
float ADCread_varHold;

void get_adcread(void)
{
	ADCread_var = ADC;
//	ADCread_varHold = ADCread_var / 1000;
}

int main(void)
{
	port_init();
	LCD_init();
	ADC_init();

	SREG = (1<<7);
	LCD_displayString("voltage = ");

    while(1)
    {

       	ADC_readChannel(ADC_PIN2);
       	ADC_setCallBack(get_adcread);

    	LCD_moveCurser(0,9);


		if(ADCread_var >= 1000)
		{

//			if(!(PIND & (1<<2)))
//			{
//				LCD_intgerToString(ADCread_varHold);
//			}
//			else
//			{
				LCD_intgerToString(ADCread_var);
//			}

		}
		else
		{
//
//			if(!(PIND & (1<<2)))
//			{
////				LCD_intgerToString(ADCread_varHold);
//				LCD_displayCharacter(' ');
//			}
//			else
//			{
				LCD_intgerToString(ADCread_var);
				LCD_displayCharacter(' ');
//			}
		}

    }
}

