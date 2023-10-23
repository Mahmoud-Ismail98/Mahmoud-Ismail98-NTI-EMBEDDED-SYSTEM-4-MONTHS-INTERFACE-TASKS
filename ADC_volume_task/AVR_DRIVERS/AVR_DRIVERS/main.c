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
#include "HAL/LCD/LCD.h"
#include "MCAL/GIE/GIE.h"
#include "MCAL/EXTI/EXTI.h"
#include "MCAL/ADC/ADC.h"

u16 ADC_val=9;
f32 volt_print=0;
LCD_4BIT_ST lcd={.lcd_pins[0]=PIN_B0_ID_8,
	.lcd_pins[1]=PIN_B1_ID_9,
	.lcd_pins[2]=PIN_B2_ID_10,
	.lcd_pins[3]=PIN_B4_ID_12,
	.lcd_pin_rs=PIN_A3_ID_3,
.lcd_pin_e=PIN_A2_ID_2};

u8 volume1[] = {
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b11111,
	0b11111,
	0b11111
};
u8 volume2[] = {
	0b00000,
	0b00000,
	0b00000,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111
};
u8 volume3[] = {
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111
};

int main(void)
{  
	LCD_vidInit_4bit(&lcd);
	LCD_vidCraetCustomChar_4bit(&lcd,volume1,1);
	LCD_vidCraetCustomChar_4bit(&lcd,volume2,2);
	LCD_vidCraetCustomChar_4bit(&lcd,volume3,3);
	

	LCD_vidDisplayString_4bit(&lcd,"VOLUME:");
	LCD_vidGotoXY_4bit(&lcd,1,8);
	
	ADC_INIT();
	
    while (1) 
    {
		ADC_GET_CONV_BOOLING(ADC1,&ADC_val);
		 if(ADC_val<100)
		{
			LCD_vidGotoXY_4bit(&lcd,1,8);
			LCD_vidDisplayChar_4bit(&lcd,'X');
			LCD_vidDisplayChar_4bit(&lcd,' ');
			LCD_vidDisplayChar_4bit(&lcd,' ');

		}
		else if(ADC_val>100&&ADC_val<400)
		{
			LCD_vidGotoXY_4bit(&lcd,1,8);
			LCD_vidDisplayChar_4bit(&lcd,1);
			LCD_vidDisplayChar_4bit(&lcd,' ');
			LCD_vidDisplayChar_4bit(&lcd,' ');

		}
		else if(ADC_val>400&&ADC_val<700)
		{
			LCD_vidGotoXY_4bit(&lcd,1,8);
			LCD_vidDisplayChar_4bit(&lcd,1);
			LCD_vidDisplayChar_4bit(&lcd,2);
			LCD_vidDisplayChar_4bit(&lcd,' ');
		}	
		else if(ADC_val>700)
		{
			LCD_vidGotoXY_4bit(&lcd,1,8);
			LCD_vidDisplayChar_4bit(&lcd,1);
			LCD_vidDisplayChar_4bit(&lcd,2);
			LCD_vidDisplayChar_4bit(&lcd,3);
		}
		else{}
				
    }
}

