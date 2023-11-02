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

#define Button_increment	'+'
#define Button_decrement	'-'
#define Button_Reset		'c'

void Init_ALL(void);
void My_Delay(uint32 Time_Delay);
void Calculate_Value(void);

uint8 Seven_Seg1_Counter = 0, Seven_Seg2_Counter = 0, Seven_Seg3_Counter = 0, Seven_Seg4_Counter = 0;
uint8 Button_Value = Button_Reset;

int main()
{

	Init_ALL();
	while(1)
	{
		Calculate_Value();
		Seven_SEG_Display(SEVEN_SEG1, Seven_Seg1_Counter);
		_delay_ms(10);
		Seven_SEG_Init();
		
		Seven_SEG_Display(SEVEN_SEG2, Seven_Seg2_Counter);
		_delay_ms(10);
		Seven_SEG_Init();
		
		Seven_SEG_Display(SEVEN_SEG3, Seven_Seg3_Counter);
		_delay_ms(10);
		Seven_SEG_Init();

		Seven_SEG_Display(SEVEN_SEG4, Seven_Seg4_Counter);
		_delay_ms(10);
		Seven_SEG_Init();
	}
	
	return 0;
}

void Init_ALL(void)
{
	PORT_Init();
	Keypad_Init();
	Seven_SEG_Init();
}

void Calculate_Value(void)
{
	Button_Value = Keypad_Read_Character(Keypad_Read_Single_Press);
	switch(Button_Value)
	{
		case Button_increment:
		
		if(Seven_Seg1_Counter < 9)
		{
			Seven_Seg1_Counter++;
		}
		else if(Seven_Seg2_Counter < 9 && Seven_Seg1_Counter == 9)
		{
			Seven_Seg2_Counter++;
			Seven_Seg1_Counter = 0;
		}
		else if(Seven_Seg3_Counter < 9 && Seven_Seg2_Counter == 9 && Seven_Seg1_Counter == 9)
		{
			Seven_Seg3_Counter++;
			Seven_Seg2_Counter = Seven_Seg1_Counter = 0;
		}
		else if(Seven_Seg4_Counter < 9 && Seven_Seg3_Counter == 9 && Seven_Seg2_Counter == 9 && Seven_Seg1_Counter == 9)
		{
			Seven_Seg4_Counter++;
			Seven_Seg3_Counter = Seven_Seg2_Counter = Seven_Seg1_Counter = 0;
		}
		
		break;
		
		case Button_decrement:
		
		if(Seven_Seg1_Counter > 0)
		{
			Seven_Seg1_Counter--;
		}
		else if(Seven_Seg2_Counter > 0 && Seven_Seg1_Counter == 0)
		{
			Seven_Seg2_Counter--;
			Seven_Seg1_Counter = 9;
		}
		else if(Seven_Seg3_Counter > 0 && Seven_Seg2_Counter == 0 && Seven_Seg1_Counter == 0)
		{
			Seven_Seg3_Counter--;
			Seven_Seg2_Counter = Seven_Seg1_Counter = 9;
		}
		else if(Seven_Seg4_Counter > 0 && Seven_Seg3_Counter == 0 && Seven_Seg2_Counter == 0 && Seven_Seg1_Counter == 0)
		{
			Seven_Seg4_Counter--;
			Seven_Seg3_Counter = Seven_Seg2_Counter = Seven_Seg1_Counter = 9;
		}
		
		break;
		
		case Button_Reset:
		Seven_Seg4_Counter = Seven_Seg3_Counter = Seven_Seg2_Counter = Seven_Seg1_Counter = 0;
		break;
	}
}
