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
#include "MCAL/TIMER0/TIMER0.h"
#include "HAL/KEY_PAD/KEY_PAD.h"
#include "MCAL/watch_DOG_TIMER/watch_dog.h"
#include "MCAL/ICUSW/ICUSW.h"
 f32 var=0;
  f32 period,ont;
LCD_4BIT_ST lcd = {.lcd_pins[0] = PIN_B0_ID_8,
				   .lcd_pins[1] = PIN_B1_ID_9,
				   .lcd_pins[2] = PIN_B2_ID_10,
				   .lcd_pins[3] = PIN_B4_ID_12,
				   .lcd_pin_rs = PIN_A3_ID_3,
				   .lcd_pin_e = PIN_A2_ID_2};
				   
int main(void)
{
  Port_vidInit();
  LCD_vidInit_4bit(&lcd);

  
  LCD_vidDisplayString_4bit(&lcd,"period:");
  LCD_vidGotoXY_4bit(&lcd,2,0);
  LCD_vidDisplayString_4bit(&lcd,"on time:");
  LCD_vidGotoXY_4bit(&lcd,3,0);
  LCD_vidDisplayString_4bit(&lcd,"duty:");
   ICUSW_voidEnable();
  GIE_INIT();
  while (1)
  {
	
	  
	  ICUSW_u8Get_period(&var);
	  period=var;
	  LCD_vidGotoXY_4bit(&lcd,1,10);
	  LCD_vidDisplayFloatNumber_4bit(&lcd,var);
	  LCD_vidDisplayString_4bit(&lcd,"ms  ");
	  
	  ICUSW_u8Get_On_period(&var);
	  ont=var;
	  LCD_vidGotoXY_4bit(&lcd,2,10);
	  LCD_vidDisplayFloatNumber_4bit(&lcd,var);
	  LCD_vidDisplayString_4bit(&lcd,"ms  ");
	  
	  LCD_vidGotoXY_4bit(&lcd,3,10);
	  LCD_vidDisplayFloatNumber_4bit(&lcd,((f32)ont/period)*100);
	  LCD_vidDisplayString_4bit(&lcd,"      ");
  }
  return 0;
}