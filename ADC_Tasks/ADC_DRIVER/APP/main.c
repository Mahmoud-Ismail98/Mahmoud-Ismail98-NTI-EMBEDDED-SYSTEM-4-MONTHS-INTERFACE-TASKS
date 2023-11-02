/*
 * ADC_DRIVER.c
 *
 * Created: 10/23/2023 3:50:57 AM
 * Author : sharb
 */ 


#include "std_types.h"
#include "../MCAL/PORT/includes/PORT.h"
#include "../MCAL/EXTINT/includes/ExtInt.h"
#include "../MCAL/GIE/includes/Gie.h"
#include "../MCAL/ADC/includes/Adc.h"
#include "../HAL/LCD/includes/Lcd.h"

#define F_CPU             8000000UL
#define THOUSAND_CONVERT  1000.00

#include "util/delay.h"

u8 customChar1[] = {
0b0000,
0b0000,
0b0000,
0b0000,
0b0000,
0b0000,
0b0000,
0b1111
};

u8 customChar2[] = {
0b0000,
0b0000,
0b0000,
0b0000,
0b0000,
0b0000,
0b1111,
0b1111
};

u8 customChar3[] = {
0b0000,
0b0000,
0b0000,
0b0000,
0b0000,
0b1111,
0b1111,
0b1111
};

u8 customChar4[] = {
0b0000,
0b0000,
0b0000,
0b0000,
0b1111,
0b1111,
0b1111,
0b1111
};

u8 customChar5[] = {
	0b0000,
	0b0000,
	0b0000,
	0b1111,
	0b1111,
	0b1111,
	0b1111,
	0b1111
};
volatile u8  gl_u8_unitSwitch = FALSE;
volatile u8  gl_u8_dataDone   = FALSE;
volatile u8  gl_u8_state      = FALSE;
volatile u16 gl_u16_DataRead  = FALSE;
volatile u16 gl_u16_oldRead   = FALSE;
volatile f32 gl_f32_Datafloat = FALSE;

void keyPressed(void);
void conVersionDone(u16 arg_u16_reading);
void firstTask(void);
void secondTask(void);
void lcdTask(void);

int main(void)
{
	PORT_voidInit();
	ADC_voidInit();
	LCD_vidInit();
	GIE_status(GIE_ENABLE);
	firstTask();
	
}

void keyPressed(void)
{
	if (gl_u8_unitSwitch == TRUE)
	{
	     gl_u8_unitSwitch = FALSE;
	}
	else
	{
		gl_u8_unitSwitch = TRUE;
	}
}

void conVersionDone(u16 arg_u16_reading)
{
	gl_u16_DataRead  = arg_u16_reading ;
	gl_f32_Datafloat = ( arg_u16_reading / THOUSAND_CONVERT ) ;
	gl_u8_dataDone = TRUE;
}


void firstTask(void)
{
	EXTINT_enum_Init(EXT_INT1,EXT_INT_FALLING_EDGE,keyPressed);
	ADC_enum_setCallBack(conVersionDone);
	ADC_enum_readValueInterrupt(ADC_PORTA_PIN_0);
	LCD_vidDisplayString(" Volt = ");
	while (1)
	{
		
		if ( gl_u8_dataDone == TRUE)
		{
			if ( gl_u8_unitSwitch == FALSE )
			{
				LCD_vidGoToXY(0,11);
				LCD_vidDisplayNumber(gl_u16_DataRead);
				LCD_vidGoToXY(0,14);
				LCD_vidDisplayString("  ");
				LCD_vidGoToXY(1,18);
				LCD_vidDisplayString("mv");
				
			}
			else if ( gl_u8_unitSwitch == TRUE )
			{
				LCD_vidGoToXY(0,11);
				LCD_vidDisplayFloat(gl_f32_Datafloat);
				LCD_vidGoToXY(1,18);
				LCD_vidDisplayString(" v");
			}
			
			gl_u8_dataDone = FALSE;
		}
		else
		{
			ADC_enum_readValueInterrupt(ADC_PORTA_PIN_0);
		}

	}
}


void secondTask(void)
{
	LCD_vidCreateCustomCharacter(customChar1,0);
	LCD_vidCreateCustomCharacter(customChar2,1);
	LCD_vidCreateCustomCharacter(customChar3,2);
	LCD_vidCreateCustomCharacter(customChar4,3);
	LCD_vidCreateCustomCharacter(customChar5,4);

	ADC_enum_setCallBack(conVersionDone);
	ADC_enum_readValueInterrupt(ADC_PORTA_PIN_0);
	LCD_vidDisplayString(" VOLUME ");
	while (1)
	{
		
		if ( gl_u8_dataDone == TRUE)
		{
			if( gl_u16_oldRead < gl_u16_DataRead)
			{
				if(gl_u8_state < 6)
				gl_u8_state++;
			}
			else if (gl_u16_oldRead > gl_u16_DataRead)
			{
				if(gl_u8_state <= 6 && gl_u8_state > 0)
				gl_u8_state--;
			}
			gl_u16_oldRead = gl_u16_DataRead ;
			LCD_vidGoToXY(1,11);
			switch (gl_u8_state)
			{
				case 1  : 
				{
					LCD_vidDisplayCharacter(0);
					LCD_vidDisplayString("    ");
					break;
				}
				
				case 2  :
				{
					LCD_vidDisplayCharacter(0);
					LCD_vidDisplayCharacter(1);
					LCD_vidDisplayString("   ");
					break;
				}
				case 3  :
				{
					LCD_vidDisplayCharacter(0);
					LCD_vidDisplayCharacter(1);
					LCD_vidDisplayCharacter(2);
					LCD_vidDisplayString("  ");
					break;
				}
				case 4  :
				{
					LCD_vidDisplayCharacter(0);
					LCD_vidDisplayCharacter(1);
					LCD_vidDisplayCharacter(2);
					LCD_vidDisplayCharacter(3);
					LCD_vidDisplayString(" ");
					break;
				}
				case 5  :
				{
					LCD_vidDisplayCharacter(0);
					LCD_vidDisplayCharacter(1);
					LCD_vidDisplayCharacter(2);
					LCD_vidDisplayCharacter(3);
					LCD_vidDisplayCharacter(4);
					break;
				}
				
			}
			
			
			gl_u8_dataDone = FALSE;
		}
		else
		{
			ADC_enum_readValueInterrupt(ADC_PORTA_PIN_0);
		}

	}
}

