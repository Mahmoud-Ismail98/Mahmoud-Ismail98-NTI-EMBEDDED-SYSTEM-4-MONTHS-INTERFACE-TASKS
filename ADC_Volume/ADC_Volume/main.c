/*
 * ADC_Volume.c
 *
 * Created: 10/25/2023 10:51:28 PM
 * Author : Ahmed Wael

-> Description:
		This Project Displays Volume using Potentiometer

-> Peripherals & Drivers Used:
		ADC,
		DIO,
		LCD

 */
#define F_CPU 16000000
#include "util/delay.h"
#include "Std_types.h"
#include "Bit_utils.h"

#include "MCAL/Port/inc/Port.h"
#include "MCAL/Dio/inc/Dio.h"
#include "MCAL/ADC/inc/ADC.h"

#include "HAL/LCD/inc/LCD.h"

u8 Level_1[] =
{
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b11111,
	0b11111
};
u8 Level_2[] =
{
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b11111,
	0b11111,
	0b11111
};
u8 Level_3[] =
{
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b11111,
	0b11111,
	0b11111,
	0b11111
};
u8 Level_4[] =
{
	0b00000,
	0b00000,
	0b00000,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111
};
u8 Level_5[] =
{
	0b00000,
	0b00000,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111
};
u8 Level_6[] =
{
	0b00000,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111
};
u8 Level_7[] =
{
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111
};






void LCD_voidDisplayVolumeHelper(u8 Copy_u16Vol)
{
	LCD_voidGoToXY(7,1);

	for(u8 i = 0; i < Copy_u16Vol;i++)
	{
		LCD_voidDisplayChar(i+1);
	}

}
void Volume_voidWelcome()
{
	LCD_voidGoToXY(7,0);
	LCD_voidDisplayString("HELLO!");
	LCD_voidGoToXY(7,1);
	LCD_voidDisplayChar(1);
	_delay_ms(200);
	LCD_voidDisplayChar(2);
	_delay_ms(200);
	LCD_voidDisplayChar(3);
	_delay_ms(200);
	LCD_voidDisplayChar(4);
	_delay_ms(200);
	LCD_voidDisplayChar(5);
	_delay_ms(200);
	LCD_voidDisplayChar(6);
	_delay_ms(200);
	LCD_voidDisplayChar(7);
	_delay_ms(1000);
	LCD_voidGoToXY(13,1);
	LCD_voidDisplayString(" ");
	_delay_ms(200);
	LCD_voidGoToXY(12,1);
	LCD_voidDisplayString(" ");
	_delay_ms(200);
	LCD_voidGoToXY(11,1);
	LCD_voidDisplayString(" ");
	_delay_ms(200);
	LCD_voidGoToXY(10,1);
	LCD_voidDisplayString(" ");
	_delay_ms(200);
	LCD_voidGoToXY(9,1);
	LCD_voidDisplayString(" ");
	_delay_ms(200);
	LCD_voidGoToXY(8,1);
	LCD_voidDisplayString(" ");
	_delay_ms(200);
	LCD_voidGoToXY(7,1);
	LCD_voidDisplayString(" ");
	_delay_ms(200);
	LCD_voidGoToXY(6,1);
	LCD_voidDisplayString(" ");
	_delay_ms(200);
}

int main (void)
{
	Port_vidInit();
	LCD_voidInit();
	ADC_voidInit(ADC_VREF_AVCC,ADC_Prescaler_128);
	ADC_Enable();
	LCD_voidCreateCustomChar(Level_1,1);
	LCD_voidCreateCustomChar(Level_2,2);
	LCD_voidCreateCustomChar(Level_3,3);
	LCD_voidCreateCustomChar(Level_4,4);
	LCD_voidCreateCustomChar(Level_5,5);
	LCD_voidCreateCustomChar(Level_6,6);
	LCD_voidCreateCustomChar(Level_7,7);

	Volume_voidWelcome();
	LCD_voidClear();

	LCD_voidGoToXY(0,0);
	LCD_voidDisplayString("Volume: ");
	u16 Local_u16AdcRead;

    while (1)
    {
	ADC_voidReadPolling(ADC_CH0,&Local_u16AdcRead);
	LCD_voidDisplayVolumeHelper(Local_u16AdcRead/128);
	LCD_voidDisplayString("       ");
	//LCD_voidClear();

	}
}

