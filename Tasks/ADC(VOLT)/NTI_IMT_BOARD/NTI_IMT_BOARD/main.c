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
void INT0_ISR(void);
u16 mv;
u16 v;
u16 adc_val=0;
int main(void)
{   APP_vidInit();
	PORT_enuSetPinMode(PORTA_PIN0,INPUT_FLOATING);

	EXTI_vidSetCallBack(0,INT0_ISR);
	
	LCD_vidClearDisplay();
	LCD_vidDisplayString("Volt:");

	
	while (1)
	{  	
		ADC_ReadChannel(ADC_CHANNEL0,&adc_val);
			mv = 5 * (adc_val-1);
			LCD_vidMoveCusrsor(2,5);
			LCD_vidDisplayInt(mv);
			LCD_vidMoveCusrsor(2,9);
			LCD_vidDisplayString(" mv ");
		
	}

}

void INT0_ISR(void)
{	//LCD_vidClearDisplay();
	u16 temp1;
	if (mv >1000){
		temp1 = mv/10;
		temp1 /=10;
		temp1 /=10;
	LCD_vidMoveCusrsor(2,5);
	LCD_vidDisplayInt(temp1);
	LCD_vidDisplayChar('.');
	mv= mv %1000;
	if(mv <100) LCD_vidDisplayChar('0');
	LCD_vidDisplayInt(mv);
	LCD_vidMoveCusrsor(2,10);
	LCD_vidDisplayString(" V");
	}
	else{
	LCD_vidMoveCusrsor(2,5);
	LCD_vidDisplayChar('0');
	LCD_vidDisplayChar('.');
	mv= mv %1000;
	if(mv <100) LCD_vidDisplayChar('0');
	LCD_vidDisplayInt(mv);
	LCD_vidMoveCusrsor(2,10);
	LCD_vidDisplayString(" V");	
		
		
		
		
	}

}

