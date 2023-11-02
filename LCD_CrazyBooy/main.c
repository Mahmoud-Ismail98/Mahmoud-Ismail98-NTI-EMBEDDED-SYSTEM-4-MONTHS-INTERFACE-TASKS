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
		  0x0E,
		  0x0E,
		  0x04,
		  0x0E,
		  0x15,
		  0x04,
		  0x0A,
		  0x1F
};
u8 customChar2[8] = {
		  0x0E,
		  0x0E,
		  0x04,
		  0x0E,
		  0x15,
		  0x04,
		  0x0A,
		  0x11
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
	LCD_voidInit();

	//PORT_enumSET_PINDirection(PORT_u8PORTAPIN0, PORT_u8PINDIR_INPUT);
	//PORT_enumSET_PINMODE(PORT_u8PORTAPIN0, PORT_u8PINMODE_INPUUT_PULLUP);

//	PORT_enumSET_PINDirection(PORT_u8PORTDPIN2, PORT_u8PINDIR_INPUT);
	//PORT_enumSET_PINMODE(PORT_u8PORTDPIN2, PORT_u8PINMODE_INPUUT_PULLUP);




	//ADC_voidInit();
	//ADC_voidReadVal_Async(func);


	//EXTI_voidInit();
	//EXTI_voidSetCallBack(EXTI0, func2);

	//M_GIE_void_EnableGlobalInterrupt();

	LCD_voidInit();
	LCD_voidCreateCustomChar(0,customChar0);
	LCD_voidCreateCustomChar(8,customChar1);
	LCD_voidCreateCustomChar(16,customChar2);
	LCD_voidCreateCustomChar(24,customChar3);

	//volatile f64 num = 0;
	for(u8 i=0;i<4;i++)
	{
		for(u8 m=0;m<20;m++)
		{
			LCD_voidSetCursorToX_y(i,m);
			LCD_voidWriteChar(0);
		}
	}
u8 x,y;
u8 flag =0;
u8 i,m;
for( i=0;i<4;i++)
{
for( m=0;m<20;m++)
{
	LCD_voidSetCursorToX_y(i,m);
	LCD_voidWriteChar(1);
	_delay_ms(50);
	x=i,y=m;
	LCD_voidSetCursorToX_y(x,y);
	LCD_voidWriteChar(0);
}
}
LCD_voidSetCursorToX_y(0,12);
LCD_voidWriteChar(' ');
for(u8 i=0;i<4;i++)
{
for(u8 m=0;m<20;m++)
{
	if (flag == 0)
	{
	if(i == 0 && m==12)
	{
		LCD_voidWriteChar(0);
		i=1;
		LCD_voidSetCursorToX_y(3,2);
		LCD_voidWriteChar('/');
		flag =1;
	}
	}
	if(flag == 1)
	{
	if(i == 3 && m==2)
	{
		i=2;
		LCD_voidWriteChar(0);
		flag = 2;
		LCD_voidSetCursorToX_y(2,12);
		LCD_voidWriteChar('/');
	}
	}
	if(flag == 2)
	{
		if(i == 2 && m==12)
		{
			i=1;
			LCD_voidWriteChar(0);
			flag = 3;
			LCD_voidSetCursorToX_y(1,16);
			LCD_voidWriteChar('/');
		}
	}
	if(flag == 3)
	{
		if(i == 1 && m==16)
		{
			i=0;
			LCD_voidWriteChar(0);
			flag = 5;

		}
	}
	if(flag == 5)
	{
		if(i == 0 && m==19)
		{
			LCD_voidSetCursorToX_y(0,19);
			LCD_voidWriteChar(1);
			LCD_voidSetCursorToX_y(1,19);
			LCD_voidWriteChar(' ');
			LCD_voidSetCursorToX_y(2,19);
			LCD_voidWriteChar(' ');
			LCD_voidSetCursorToX_y(3,19);
			LCD_voidWriteChar(' ');
			_delay_ms(40);
			LCD_voidSetCursorToX_y(0,19);
			LCD_voidWriteChar(' ');
			LCD_voidSetCursorToX_y(1,19);
			LCD_voidWriteChar(1);
			LCD_voidSetCursorToX_y(2,19);
			LCD_voidWriteChar(' ');
			LCD_voidSetCursorToX_y(3,19);
			LCD_voidWriteChar(' ');
			_delay_ms(40);
			LCD_voidSetCursorToX_y(0,19);
			LCD_voidWriteChar(' ');
			LCD_voidSetCursorToX_y(1,19);
			LCD_voidWriteChar(' ');
			LCD_voidSetCursorToX_y(2,19);
			LCD_voidWriteChar(1);
			LCD_voidSetCursorToX_y(3,19);
			LCD_voidWriteChar(' ');
			_delay_ms(40);
			LCD_voidSetCursorToX_y(0,19);
			LCD_voidWriteChar(' ');
			LCD_voidSetCursorToX_y(1,19);
			LCD_voidWriteChar(' ');
			LCD_voidSetCursorToX_y(2,19);
			LCD_voidWriteChar(' ');
			LCD_voidSetCursorToX_y(3,19);
			LCD_voidWriteChar(1);
			_delay_ms(40);
			LCD_voidSetCursorToX_y(0,19);
			LCD_voidWriteChar(' ');
			LCD_voidSetCursorToX_y(1,19);
			LCD_voidWriteChar(' ');
			LCD_voidSetCursorToX_y(2,19);
			LCD_voidWriteChar(' ');
			LCD_voidSetCursorToX_y(3,19);
			LCD_voidWriteChar(' ');
			_delay_ms(40);
			break;
		}
	}
	LCD_voidSetCursorToX_y(i,m);
	LCD_voidWriteChar(1);
	_delay_ms(150);
	x=i,y=m;
	LCD_voidSetCursorToX_y(x,y);
	LCD_voidWriteChar(0);
}
if(i == 0 && m==20)
{
	break;
}
}
LCD_voidSetCursorToX_y(2,8);
LCD_voidWriteString("Game Over");
	while(1)
	{

		_delay_ms(2000);

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
