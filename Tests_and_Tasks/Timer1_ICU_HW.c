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

void Init_ALL(void);

uint8 Count_Edges = 0;
uint8 PWM_Measured = 0;
uint64 On_Time = 0;
uint64 Off_Time = 0;

void Timer1_ICU_CallBack(void)
{
	if(!Count_Edges)
	{
		Timer1_Input_Capture_Start();
		Count_Edges = 1;
	}
	switch(Count_Edges)
	{
		case 1:
		Timer1_Input_Capture_Falling();
		Count_Edges++;
		break;
		
		case 2:
		On_Time = Timer1_Read_ICR_Value()+10;
		Timer1_Input_Capture_Rising();
		Count_Edges++;
		break;
		
		case 3:
		Off_Time = Timer1_Read_ICR_Value() - On_Time + 10;
		Timer1_Stop();
		PWM_Measured = 1;
		Count_Edges = 4;
		break;
	}
}

int main()
{
	Init_ALL();
	while(1)
	{
		while(!PWM_Measured);
		LCD_Display_String((const Puint8)"Periodic time: ");
		LCD_Display_Number(Off_Time + On_Time);
		LCD_GoTO_XY(LCD_Line2, LCD_Col1);
		LCD_Display_String((const Puint8)"On time: ");
		LCD_Display_Number(On_Time);
		_delay_ms(500);
		LCD_Clear();
		Count_Edges = 0;
		PWM_Measured = 0;	
	}
	return 0;
}

void Init_ALL(void)
{
	PORT_Init();
	LCD_Init();
	GIE_Init();
	GIE_Enable();
	Port_Set_Pin_Mode(PORTD_ADD, PORT_PIN6, PIN_Input_Floating);
	Timer1_Input_Capture_Init(Timer1_ICU_CallBack);		
}


