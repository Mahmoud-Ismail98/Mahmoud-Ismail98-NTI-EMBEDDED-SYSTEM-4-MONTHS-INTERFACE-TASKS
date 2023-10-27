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
#include "HAL/LCD/LCD_COMANDS.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/GIE/GIE.h"
#include "MCAL/EXTI/EXTI.h"

volatile u32 counter=0;
volatile u8 flag=0;
void isr1(void)
{
	EXTI_INT0_Interrupt_Disable();
	if(counter!=0)
	{
		counter--;
	}
	_delay_ms(1000);
	flag=1;
	EXTI_INT0_Interrupt_Flag_clear();
	EXTI_INT0_Interrupt_Enable();
	
	
}

void isr2(void)
{
	EXTI_INT1_Interrupt_Disable();
	counter++;
	_delay_ms(1000);
	flag=1;
	EXTI_INT1_Interrupt_Flag_clear();
	EXTI_INT1_Interrupt_Enable();
}


LCD_4BIT_ST lcd={.lcd_pins[0]=PIN_B0_ID_8,
				 .lcd_pins[1]=PIN_B1_ID_9,
				 .lcd_pins[2]=PIN_B2_ID_10,
				 .lcd_pins[3]=PIN_B4_ID_12,
				 .lcd_pin_rs=PIN_A3_ID_3,
				 .lcd_pin_e=PIN_A2_ID_2};
				 
int main(void)
{
	Port_vidInit();
	GIE_INIT();
	LCD_vidInit_4bit(&lcd);
	//LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
	LCD_vidDisplayString_4bit(&lcd,"counter:");
	EXI_INT(EXTI_INT0,EXTI_MODE_FALING_EDGE,isr1);
	EXI_INT(EXTI_INT1,EXTI_MODE_FALING_EDGE,isr2);
	while (1)
	{
 		if(counter>=9999)
		{
			counter=0;
		}	
		if(flag==1)
		{
			LCD_vidGotoXY_4bit(&lcd,1,9);
			LCD_vidDisplayString_4bit(&lcd,"    ");
 			LCD_vidGotoXY_4bit(&lcd,1,9);
			LCD_vidDisplayNumber_4bit(&lcd,counter);
			_delay_ms(500);
			flag=0;
		}

	}
	
}