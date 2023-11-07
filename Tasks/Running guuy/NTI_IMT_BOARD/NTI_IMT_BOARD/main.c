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
#include "DIO_PRIVATE.h"
#include "GIE.h"
#include "EXTI.h"
#include "EXTI_CFG.h"
#include "GPTM.h"
#include "USART.h"
#include "SSD.h"
#include "ADC.h"
#include "ADC_PRIVATE.h"
#include "WDT.h"
#include "LCD.h"
#include "KEYPAD.h"


#include "APP.h"

u8 Guy[] = {
	0x0E,
	0x0A,
	0x04,
	0x0E,
	0x15,
	0x04,
	0x0A,
	0x1F
};

int main(void)
{  
	APP_vidInit();
	LCD_vidDisplayCustomChar(Guy,0);
	
	for(u8 rows=0 ; rows <=3 ; rows++)
	{
		for(u8 cols=0; cols<=19 ; cols++)
		{	LCD_vidMoveCusrsor(rows,cols);
			LCD_vidDisplayChar('_');
		}
	}

	while(1)
	{
		for(u8 rows=0 ; rows <=3 ; rows++)
		{
			for(u8 cols=0; cols<=19 ; cols++)
			{	if(cols == 0 && rows == 0){
				LCD_vidMoveCusrsor(3,19);
				LCD_vidDisplayChar('_');

				LCD_vidMoveCusrsor(rows,cols);
				LCD_vidDisplayChar(0);}
				
				else if (cols == 0 && rows > 0){
					LCD_vidMoveCusrsor(rows-1,19);
					LCD_vidDisplayChar('_');
					LCD_vidMoveCusrsor(rows,cols);
					LCD_vidDisplayChar(0);
				}
				else {
					LCD_vidMoveCusrsor(rows,cols-1);
					LCD_vidDisplayChar('_');
					//LCD_vidMoveCusrsor(rows,cols);
					LCD_vidDisplayChar(0);
				}
				_delay_ms(10);
				
				
			}
		}
	
	}

}
