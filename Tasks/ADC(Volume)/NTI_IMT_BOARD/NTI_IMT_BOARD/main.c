/*
 * NTI_IMT_BOARD.c
 *
 * Created: 10/20/2023 11:56:11 AM
 * Author : Mahmoud Tariq
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CLCK.h"
#include "util/delay.h"

#include "PORT.h"
#include "DIO.h"
#include "ADC.h"
#include "LCD.h"



#include "APP.h"
u8 one[] = {
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x1F,
	0x1F
};
u8 two[] = {
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x1F,
	0x1F,
	0x1F
};
u8 three[] = {
	0x00,
	0x00,
	0x00,
	0x1F,
	0x1F,
	0x1F,
	0x1F,
	0x1F
};
u8 four[] = {
	0x00,
	0x1F,
	0x1F,
	0x1F,
	0x1F,
	0x1F,
	0x1F,
	0x1F
};

u8 FULL[] = {
	 0x1F,
	 0x1F,
	 0x1F,
	 0x1F,
	 0x1F,
	 0x1F,
	 0x1F,
	 0x1F
};


int main(void)
{   APP_vidInit();
	PORT_enuSetPinMode(PORTA_PIN0,INPUT_FLOATING);
	LCD_vidClearDisplay();
	LCD_vidDisplayString("Volume");
	LCD_vidDisplayCustomChar(one,0);
	LCD_vidDisplayCustomChar(two,1);
	LCD_vidDisplayCustomChar(three,2);
	LCD_vidDisplayCustomChar(four,3);
	LCD_vidDisplayCustomChar(FULL,4);
	u16 adc_val=0;
	
	while (1)
	{  	
		ADC_ReadChannel(ADC_CHANNEL0,&adc_val);
		
		if(adc_val<5){
			
			LCD_vidMoveCusrsor(2,0);
			LCD_vidDisplayString("Muted");
		}
		else if(adc_val>=5 && adc_val <200){
			
			LCD_vidMoveCusrsor(2,0);
			LCD_vidDisplayChar(0);
			LCD_vidMoveCusrsor(2,1);
			LCD_vidDisplayChar(' ');
			LCD_vidMoveCusrsor(2,2);
			LCD_vidDisplayChar(' ');
			LCD_vidMoveCusrsor(2,3);
			LCD_vidDisplayChar(' ');
			LCD_vidMoveCusrsor(2,4);
			LCD_vidDisplayChar(' ');
		}
		else if(adc_val>=200 && adc_val <400){
			LCD_vidMoveCusrsor(2,0);
			LCD_vidDisplayChar(0);
			LCD_vidMoveCusrsor(2,1);
			LCD_vidDisplayChar(1);
			LCD_vidMoveCusrsor(2,2);
			LCD_vidDisplayChar(' ');
			LCD_vidMoveCusrsor(2,3);
			LCD_vidDisplayChar(' ');
			LCD_vidMoveCusrsor(2,4);
			LCD_vidDisplayChar(' ');
		}
		else if(adc_val>=400 && adc_val <600){
			LCD_vidMoveCusrsor(2,0);
			LCD_vidDisplayChar(0);
			LCD_vidMoveCusrsor(2,1);
			LCD_vidDisplayChar(1);
			LCD_vidMoveCusrsor(2,2);
			LCD_vidDisplayChar(2);
			LCD_vidMoveCusrsor(2,3);
			LCD_vidDisplayChar(' ');
			LCD_vidMoveCusrsor(2,4);
			LCD_vidDisplayChar(' ');
		}
		else if(adc_val>=600 && adc_val <800){
			LCD_vidMoveCusrsor(2,0);
			LCD_vidDisplayChar(0);
			LCD_vidMoveCusrsor(2,1);
			LCD_vidDisplayChar(1);
			LCD_vidMoveCusrsor(2,2);
			LCD_vidDisplayChar(2);
			LCD_vidMoveCusrsor(2,3);
			LCD_vidMoveCusrsor(2,3);
			LCD_vidDisplayChar(3);
			LCD_vidMoveCusrsor(2,4);
			LCD_vidDisplayChar(' ');
		}
		else if(adc_val>=800 && adc_val <=1023){
				LCD_vidMoveCusrsor(2,0);
				LCD_vidDisplayChar(0);
				LCD_vidMoveCusrsor(2,1);
				LCD_vidDisplayChar(1);
				LCD_vidMoveCusrsor(2,2);
				LCD_vidDisplayChar(2);
				LCD_vidMoveCusrsor(2,3);
				LCD_vidMoveCusrsor(2,3);
				LCD_vidDisplayChar(3);
				LCD_vidMoveCusrsor(2,4);
				LCD_vidDisplayChar(4);
				
			}
		
		

	}

}

