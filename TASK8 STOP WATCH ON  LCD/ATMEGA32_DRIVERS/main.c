/*
 * ATMEGA32_DRIVERS.c
 *
 * Created: 28/10/2023 10:09:00 م
 * Author : mahoud ismail
 */ 

#include "services/Std_types.h"
#include "services/Bit_utils.h"
#include "MCAL/PORT/include/port.h"
#include "MCAL/DIO/include/DIO.h"
#include "MCAL/DIO/include/DIO_private.h"
#include "MCAL/TIMER0/include/TIMER0_Interface.h"
#include "MCAL/TIMER0/include/TIMER0_private.h"
#include "MCAL/EXT_INTERUPT/include/external_interrupt.h"
#include "MCAL/SPI/includes/SPI.h"
#include "MCAL/I2C/I2C.h"
#include "HAL/KEYPAD/include/KEYPAD.h"

#include <util/delay.h>

volatile u16 sec=0;
volatile u16 min=0;
volatile u16 hours=0;

void TIMER0_ISR_OV(void)
{
	TGL_BIT(PORTA,PORTA_PIN0);
	sec++;
	TCNT0=0x00;
	
}
void show_time(void)
{
	LCD_voidSetCursor(0,1);

	if (sec==60)
	{
		sec=0;
		min++;
	}
	//sec++;
	if (min==60)
	{
		hours++;
		min==0;
	}
	if (hours<10)
	{
		LCD_voidWriteCharacter('0');
	}
	lcd_voidSendNumber(&hours);
	LCD_voidWriteCharacter(':');
	if (min<10)
	{
		LCD_voidWriteCharacter('0');
	}
	lcd_voidSendNumber(&min);
	LCD_voidWriteCharacter(':');
	if (sec<10)
	{
		LCD_voidWriteCharacter('0');
	}
	lcd_voidSendNumber(&sec);
}
int main(void)
{	
	
	Port_setPinDirection(PORTA_PIN0,PIN_OUTPUT);
	Global_Interrupt_EnablE();
	LCD_voidInit();
	TIMER0_voidMode();
	TIMER0_SET_COUNTER(50);
	Timer0_EnableInterupt();
	LCD_voidWriteString("stop watch");
	LCD_voidSetCursor(0,1);
	LCD_voidWriteString("00:00:00");
	Timer0SetCallBack(TIMER0_ISR_OV);
	
	while(1)
	{
	   show_time();
	}
}