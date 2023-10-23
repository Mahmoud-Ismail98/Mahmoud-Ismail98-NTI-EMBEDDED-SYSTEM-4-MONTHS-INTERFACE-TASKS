/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: bishoy18126
 */
#include "Std_types.h"
#include "Bit_utils.h"

#include "GIE_int.h"
#include "PORT.h"
#include "DIO_int.h"
#include "ADC_int.h"
#include "LCD.h"
#include "EXTI_int.h"
#include<util/delay.h>
void func(u16 Ptr_pu16CopyData);
void func2(void);
volatile int FLAG=1;
volatile u16 POINTERR ;
int main(void)
{
	/**/
	PORT_voidInit();
	PORT_enumSET_PINDirection(PORT_u8PORTAPIN0, PORT_u8PINDIR_INPUT);
	PORT_enumSET_PINMODE(PORT_u8PORTAPIN0, PORT_u8PINMODE_INPUUT_PULLUP);

	PORT_enumSET_PINDirection(PORT_u8PORTDPIN2, PORT_u8PINDIR_INPUT);
	PORT_enumSET_PINMODE(PORT_u8PORTDPIN2, PORT_u8PINMODE_INPUUT_PULLUP);


	LCD_voidInit();


	ADC_voidInit();
	ADC_voidReadVal_Async(func);


	EXTI_voidInit();
	EXTI_voidSetCallBack(EXTI0, func2);

	M_GIE_void_EnableGlobalInterrupt();

	LCD_voidInit();
	volatile f64 num = 0;

	while(1)
	{
		ADC_voidStartConversion(0);
		LCD_voidSetCursorToX_y(LCD_ROW0,LCD_Coloumn0);
		LCD_voidWriteString("VOLT = ");
		LCD_voidSetCursorToX_y(LCD_ROW0,LCD_Coloumn10);

		if(FLAG == 1)
		{
			num = (f64)(POINTERR*5)/1023;
			LCD_voidWriteNumbers(num);
			LCD_voidWriteString(" V");
			LCD_voidWriteString("    ");
		}
		else if(FLAG == 2)
		{

			num = (f64)(POINTERR)*5000/1023;
			LCD_voidWriteNumbers(num);
			LCD_voidWriteString(" mV");
			LCD_voidWriteString("    ");
		}
		_delay_us (900);

	}
	return 0;
}

void func(u16 Ptr_pu16CopyData)
{
	POINTERR = Ptr_pu16CopyData ;
}
void func2(void)
{
	if(FLAG == 1)
	{
		FLAG=2;
	}
	else if(FLAG == 2)
	{
		FLAG=1;
	}
}
