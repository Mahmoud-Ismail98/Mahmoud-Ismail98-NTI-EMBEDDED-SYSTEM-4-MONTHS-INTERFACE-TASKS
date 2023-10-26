/*
 * ADC_VmV.c
 *
 * Created: 10/23/2023 11:19:14 PM
 * Author : Ahmed Wael
 
-> Description:
		This Project reads voltage from Potentiometer and display it on LCD, with voltage and milli voltage.
		
-> Peripherals & Drivers Used: 
		ADC,
		EXTI,
		DIO,
		LCD
*/


#define F_CPU 16000000
#include "util/delay.h"

#include "Bit_utils.h"
#include "Std_types.h"
#include "Port.h"
#include "Dio.h"
#include "LCD.h"
#include "ADC.h"
#include "EXTI.h"

volatile u8 Global_u8Mode = 1;


//Helper function to get reading in mv
u16 ADC_voidReadMVolt(u8 Copy_u8Channel)
{
	u16 Local_u8read = 0;
	ADC_voidReadPolling(Copy_u8Channel,&Local_u8read);
	u16 Local_u8Result = ((u32)Local_u8read*5000)/1023;
	return Local_u8Result;
}
/////////////////////////////////////////////////////////


//Interrupt Function
void T_voidSetMode()
{
	Global_u8Mode = Global_u8Mode ^ 1;
	if(Global_u8Mode == 0)
	{
		LCD_voidGoToXY(18,1);
		LCD_voidDisplayString("V ");
	}
	else if(Global_u8Mode == 1)
	{
		LCD_voidGoToXY(18,1);
		LCD_voidDisplayString("mV");
	}
}
/////////////////////////////////////



//Helper function to display volt with decimal point
void LCD_DisplayVolt(u16 Copy_u16Volt)
{
	u8 Local_u8Arr[4];
	for(u8 i = 0 ; i < 4; i++)
	{
		Local_u8Arr[i] = Copy_u16Volt%10;
		Copy_u16Volt/=10;
	}
	LCD_voidDisplayChar(Local_u8Arr[3] + '0');
	LCD_voidDisplayChar('.');
	LCD_voidDisplayChar(Local_u8Arr[2] + '0');

}
//////////////////////////////////////////////


int main(void)
{
	Port_vidInit();
	
	LCD_voidInit();
	
	ADC_voidInit(ADC_VREF_AVCC,ADC_Prescaler_128);
	ADC_Enable();
	
	EXTI_voidEnable(EXTI_INT0);
	EXTI_voidSetCallBack(EXTI_INT0,T_voidSetMode);
	EXTI_voidSetPinMode(EXTI_INT0,EXTI_FALLING);	
	
	GIE();
	
	LCD_voidDisplayString("VOLT:");
	LCD_voidGoToXY(18,1);
	LCD_voidDisplayString("mV");
	
	u16 mV;
	u16 V;
	
	
	while (1)
	{
		switch(Global_u8Mode)
		{
			case 0 :
			V = ADC_voidReadMVolt(ADC_CH0);
			GID();
			LCD_voidGoToXY(5,0);
			LCD_DisplayVolt(V);
			LCD_voidDisplayString("    ");
			GIE();
			break;
			case 1 :
			mV = ADC_voidReadMVolt(ADC_CH0);
			GID();
			LCD_voidGoToXY(5,0);
			LCD_voidDisplayNumbers(mV);
			LCD_voidDisplayString("    ");
			GIE();
			break;
		}
	}
}


