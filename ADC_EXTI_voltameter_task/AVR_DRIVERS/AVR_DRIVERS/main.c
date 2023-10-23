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
#include "HAL/LCD/LCD.h"
#include "MCAL/GIE/GIE.h"
#include "MCAL/EXTI/EXTI.h"
#include "MCAL/ADC/ADC.h"
volatile u8 flag=0;
void isr(void)
{
	if(flag==0)
	{
		flag=1;
	}
	else if(flag==1)
	{
		flag=0;
	}
}
u16 test_var=9;
f32 volt_print=0;
LCD_4BIT_ST lcd={.lcd_pins[0]=PIN_B0_ID_8,
	.lcd_pins[1]=PIN_B1_ID_9,
	.lcd_pins[2]=PIN_B2_ID_10,
	.lcd_pins[3]=PIN_B4_ID_12,
	.lcd_pin_rs=PIN_A3_ID_3,
.lcd_pin_e=PIN_A2_ID_2};

int main(void)
{
	Port_vidInit();
	LCD_vidInit_4bit(&lcd);
	GIE_INIT();
	EXI_INT(EXTI_INT0,EXTI_MODE_FALING_EDGE,isr);
	LCD_vidDisplayString_4bit(&lcd,"VOLT:");
	LCD_vidGotoXY_4bit(&lcd,1,6);

	ADC_INIT();

    while (1)
    {
		ADC_GET_CONV_BOOLING(ADC1,&test_var);
		volt_print=(f32)test_var*5/1024;
		LCD_vidGotoXY_4bit(&lcd,1,5);
		if(flag==1)
		{
			LCD_vidDisplayFloatNumber_4bit(&lcd,volt_print);//v
			LCD_vidDisplayString_4bit(&lcd,"v   ");
		}
		else if(flag==0)
		{
			LCD_vidDisplayNumber_4bit(&lcd,volt_print*1000);//mv
			LCD_vidDisplayString_4bit(&lcd,"mv  ");
		}
		else{}

    }
}