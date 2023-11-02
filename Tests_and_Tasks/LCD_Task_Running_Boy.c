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
#include <HAL/Seven_SEG/Seven_SEG_Includes/Seven_SEG.h>
#include <limits.h>
#include <stdint.h>


uint8 Human[8] = { 0b01110, 0b01110, 0b00100, 0b11111, 0b00100, 0b01010, 0b11111, 0b11111 };


uint8 LCD_Line_Address[4] = {LCD_Line1, LCD_Line2, LCD_Line3, LCD_Line4};
uint8 Line_index = 0;
uint8 Col_index = LCD_Col1;

void LCD_Display_Horizontal_Lines(void);
void Level1(void);
void Level2(void);
void Level3(void);
void Level4(void);

int main(void)
{
	PORT_Init();
	LCD_Init();
	LCD_Display_Horizontal_Lines();
	Level1();
	Level2();
	Level3();
	Level4();
}

void LCD_Display_Horizontal_Lines(void)
{
	uint8 Line_index = 0;
	uint8 Col_index = LCD_Col1;
	while(Line_index < 5)
	{
		LCD_Display_Character('_');
		Col_index++;
		if(Col_index == LCD_Col20+1)
		{
			Col_index = LCD_Col1;
			Line_index++;
			LCD_GoTO_XY(LCD_Line_Address[Line_index], Col_index);
		}
	}
	
}

void Level1(void)
{
	LCD_Create_Custom_Character(Human,1);
	LCD_Display_Horizontal_Lines();
	
	LCD_GoTO_XY(LCD_Line1, LCD_Col1);
	while(Line_index < 4)
	{
		LCD_Display_Character(1);
		Col_index++;
		_delay_ms(100);
		if(Col_index == LCD_Col20+1)
		{
			LCD_GoTO_XY(LCD_Line_Address[Line_index], Col_index-1);
			LCD_Display_Character('_');
			Col_index = LCD_Col1;
			Line_index++;
			LCD_GoTO_XY(LCD_Line_Address[Line_index], Col_index);
		}
		else
		{
			
			LCD_GoTO_XY(LCD_Line_Address[Line_index], Col_index-1);
			LCD_Display_Character('_');
			LCD_GoTO_XY(LCD_Line_Address[Line_index], Col_index);
		}
	}
}

void Level2(void)
{
	LCD_GoTO_XY(LCD_Line2, LCD_Col10);
	LCD_Display_Character(' ');
	LCD_GoTO_XY(LCD_Line1, LCD_Col1);
	
	Line_index = 0;
	Col_index = LCD_Col1;
	while(Line_index < 3)
	{
		LCD_Display_Character(1);
		Col_index++;
		_delay_ms(100);
		if(Col_index == LCD_Col20+1)
		{
			LCD_GoTO_XY(LCD_Line_Address[Line_index], Col_index-1);
			LCD_Display_Character('_');
			Col_index = LCD_Col1;
			Line_index++;
			LCD_GoTO_XY(LCD_Line_Address[Line_index], Col_index);
		}
		else
		{
			LCD_GoTO_XY(LCD_Line_Address[Line_index], Col_index-1);
			LCD_Display_Character('_');
			LCD_GoTO_XY(LCD_Line_Address[Line_index], Col_index);
		}
		
		if(LCD_Line_Address[Line_index] == LCD_Line2 && Col_index == LCD_Col10)
		{
			LCD_GoTO_XY(LCD_Line_Address[++Line_index], Col_index);
		}
	}
}

void Level3(void)
{
	LCD_GoTO_XY(LCD_Line2, LCD_Col10);
	LCD_Display_Character('_');
	
	LCD_GoTO_XY(LCD_Line2, LCD_Col15);
	LCD_Display_Character(' ');
	
	LCD_GoTO_XY(LCD_Line3, LCD_Col15);
	LCD_Display_String("/ ");
	
	LCD_GoTO_XY(LCD_Line3, LCD_Col1);
	
	Line_index = 2;
	Col_index = LCD_Col1;
	while(Col_index <= LCD_Col20)
	{
		LCD_Display_Character(1);
		Col_index++;
		_delay_ms(100);
		
		LCD_GoTO_XY(LCD_Line_Address[Line_index], Col_index-1);
		LCD_Display_Character('_');
		LCD_GoTO_XY(LCD_Line_Address[Line_index], Col_index);
		
		if(LCD_Line_Address[Line_index] == LCD_Line3 && Col_index == LCD_Col15)
		{
			LCD_GoTO_XY(LCD_Line_Address[--Line_index], Col_index);
			LCD_Display_Character(1);
			_delay_ms(100);
			LCD_GoTO_XY(LCD_Line_Address[Line_index], Col_index);
			LCD_Display_Character('_');
			LCD_GoTO_XY(LCD_Line3, LCD_Col15);
			LCD_Display_String("__");
			LCD_GoTO_XY(LCD_Line_Address[Line_index], ++Col_index);
		}
	}
}

void Level4(void)
{
	LCD_GoTO_XY(LCD_Line2, LCD_Col15);
	LCD_Display_Character('|');
	
	LCD_GoTO_XY(LCD_Line2, LCD_Col1);
	
	Line_index = 1;
	Col_index = LCD_Col1;
	while(Col_index <= LCD_Col20)
	{
		LCD_Display_Character(1);
		Col_index++;
		_delay_ms(100);
		
		LCD_GoTO_XY(LCD_Line_Address[Line_index], Col_index-1);
		LCD_Display_Character('_');
		LCD_GoTO_XY(LCD_Line_Address[Line_index], Col_index);
		
		if(LCD_Line_Address[Line_index] == LCD_Line2 && Col_index == LCD_Col15)
		{
			LCD_Clear();
			LCD_GoTO_XY(LCD_Line2, LCD_Col7);
			LCD_Display_String("Game Over");
			break;
		}
	}
}