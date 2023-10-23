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
u8 customChar0[8] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x1F,
  0x1F
};
u8 customChar1[8] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x1F,
  0x1F,
  0x1F,
  0x1F
};
u8 customChar2[8] = {
		  0x00,
		  0x00,
		  0x1F,
		  0x1F,
		  0x1F,
		  0x1F,
		  0x1F,
		  0x1F
		};
u8 customChar3[8] = {
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
	LCD_voidCreateCustomChar(0,customChar0);
	LCD_voidCreateCustomChar(8,customChar1);
	LCD_voidCreateCustomChar(16,customChar2);
	LCD_voidCreateCustomChar(24,customChar3);

	volatile f64 num = 0;

	while(1)
	{
		ADC_voidStartConversion(0);
		LCD_voidSetCursorToX_y(LCD_ROW0,LCD_Coloumn0);
		LCD_voidWriteString("VOLUME=    ");
		LCD_voidSetCursorToX_y(LCD_ROW1,LCD_Coloumn10);
		if(POINTERR<160)
		{
			LCD_voidWriteString("     ");
		}
		else if(POINTERR<370)
		{
			LCD_voidWriteChar(0);
			LCD_voidWriteString("     ");
		}
		else if(POINTERR<590)
		{
			LCD_voidWriteChar(0);
			LCD_voidWriteChar(1);
			LCD_voidWriteString("     ");
		}
		else if(POINTERR<850)
		{
			LCD_voidWriteChar(0);
			LCD_voidWriteChar(1);
			LCD_voidWriteChar(2);
			LCD_voidWriteString("     ");
		}
		else if(POINTERR<1024)
		{
			LCD_voidWriteChar(0);
			LCD_voidWriteChar(1);
			LCD_voidWriteChar(2);
			LCD_voidWriteChar(3);
			LCD_voidWriteString("     ");
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
