/*
 * main.c
 *
 * Created: 10/20/2023 12:01:32 PM
 *  Author: Mohamed Alaa
 */ 

#define F_CPU 8000000

#include <MCAL/PORT/PORT_Includes/Port.h>
#include <MCAL/DIO/DIO_Includes/DIO.h>
#include <HAL/LCD/LCD_Includes/LCD.h>
#include <util/delay.h>
#include <HAL/LCD/LCD_Includes/LCD.h>
#include <MCAL/GIE/GIE_Includes/GIE.h>
#include <MCAL/EXTI/EXTI_Includes/EXTI.h>
#include <Services/Std_types.h>
#include <MCAL/ADC/ADC_Includes/ADC.h>
#include <MCAL/Timer/Timer_Includes/Timer.h>
#include <HAL/Keypad/Keypad_Includes/Keypad.h>
#include <MCAL/Watchdog/Watchdog_Includes/Watchdog.h>
#include <limits.h>
#include <stdint.h>

uint8 Volume_char[5][8] = {
	{ 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b11111},
	{ 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b11111},
	{ 0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111},
	{ 0b00000, 0b00000, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111},
	{ 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111}
};

void ADC_Task2(void);

int main(void)
{
	
	PORT_Init();
	LCD_Init();
	Port_Set_Pin_Mode(PORTA_ADD, PORT_PIN0, PIN_Input_Floating);
	ADC_Config_t ADC_CFG = {ADC_VREF_AVCC, ADC_Channel_ADC0, ADC_Auto_Trigger_Disable, ADC_Interrupt_State_Disable, ADC_Prescale_128, ADC_Trigger_EXTI0, PTR_NULL};
	ADC_Set_Config(&ADC_CFG);

	for (uint8 custome_Char_Index = 0; custome_Char_Index < 5; custome_Char_Index++)
	{
		LCD_Create_Custom_Character(Volume_char[custome_Char_Index],custome_Char_Index);
	}
	LCD_Display_String((const Puint8)"Volume");
	while(1)
	{
		ADC_Task2();
	}
}

void ADC_Task2(void)
{
	uint32 Volume_Level;
	uint32 ADC_value=0;
	ADC_Start();
	ADC_Read(&ADC_value);
	Volume_Level = (ADC_value* 5000)/(1<<10);
	static uint32 Old_Volume_Level = 0;
	if( (0 <= Volume_Level) && (Volume_Level < 1000) && !((0 < Old_Volume_Level) && (Old_Volume_Level < 1000)) )
	{
		if(Volume_Level >= Old_Volume_Level)
		{
			LCD_GoTO_XY(LCD_Line3, LCD_Col10);
			LCD_Display_Character(0);
		}
		else
		{
			LCD_GoTO_XY(LCD_Line3, LCD_Col11);
			LCD_Display_Character(' ');
		}

	}
	else if((1000 <= Volume_Level) && (Volume_Level < 2000) && !((1000 <= Old_Volume_Level) && (Old_Volume_Level < 2000)))
	{
		if(Volume_Level > Old_Volume_Level)
		{
			LCD_GoTO_XY(LCD_Line3, LCD_Col11);
			LCD_Display_Character(1);
		}
		else
		{
			LCD_GoTO_XY(LCD_Line3, LCD_Col12);
			LCD_Display_Character(' ');
		}
	}
	else if((2000 <= Volume_Level) && (Volume_Level < 3000) && !((2000 <= Old_Volume_Level) && (Old_Volume_Level < 3000)))
	{
		if(Volume_Level > Old_Volume_Level)
		{
			LCD_GoTO_XY(LCD_Line3, LCD_Col12);
			LCD_Display_Character(2);
		}
		else
		{
			LCD_GoTO_XY(LCD_Line3, LCD_Col13);
			LCD_Display_Character(' ');
		}
	}
	else if((3000 <= Volume_Level) && (Volume_Level < 4000) && !((3000 <= Old_Volume_Level) && (Old_Volume_Level < 4000)))
	{
		if(Volume_Level > Old_Volume_Level)
		{
			LCD_GoTO_XY(LCD_Line3, LCD_Col13);
			LCD_Display_Character(3);
		}
		else
		{
			LCD_GoTO_XY(LCD_Line3, LCD_Col14);
			LCD_Display_Character(' ');
		}
	}
	else if((4000 <= Volume_Level) && (Volume_Level < 5000) && !((4000 <= Old_Volume_Level) && (Old_Volume_Level < 5000)))
	{
		LCD_GoTO_XY(LCD_Line3, LCD_Col14);
		LCD_Display_Character(4);
	}
	Old_Volume_Level = Volume_Level;
}

