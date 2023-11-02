/*
 * main.c
 *
 * Created: 10/20/2023 12:01:32 PM
 *  Author: computer store
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
#include "HAL/Keypad/Keypad_Includes/Keypad.h"

#define Keypad_SW_NULL 'N'
#define Error		0
#define Alarm		'1'
#define Stopwatch	'2'

void Init_ALL(void);
void Task(void);
void Main_Menu(void);
void User_Interface(void);
void Alarm_Count(void);
void Alarm_On(void);
void Start_Stopwatch(void);
void My_Delay(uint32 Time_Delay);
void Get_Input();
uint32 Read_number();

uint32 Timer_Flag = 1;
uint32 input = 0;

typedef enum 
{
	ST_Main_Menu,
	ST_Get_Input,
	ST_Alarm_On,
	ST_Alarm_Count,
	ST_Stopwatch
}Program_State_t;

Program_State_t Program_state = ST_Main_Menu;

void Timer_OCM_CallBack(void)
{
	Timer_Flag = 0;
}


int main()
{
	Init_ALL();
	while(1)
	{
		Task();
	}
	return 0;
}

void Init_ALL(void)
{
	PORT_Init();
	LCD_Init();
	Keypad_Init();
	GIE_Enable();
 	Timer0_Config_t Timer_Cfg = {Timer0_Normal_Mode, Timer0_OC0_Set_On_match, Timer0_Clock_Prescaler_256, Timer_Interrupt_Enable,Timer_Interrupt_Disable};
 	Timer0_Init(&Timer_Cfg);
 	Timer0_Set_CallBack(Timer_OCM_CallBack, Timer0_INT_Output_Compare_Match);
}

void Task(void)
{
	switch((uint32)Program_state)
	{
		case ST_Main_Menu:
		Main_Menu();
		break;
		
		case ST_Alarm_Count:
		Alarm_Count();
		break;
				
		case ST_Stopwatch:
		Start_Stopwatch();
		break;
		
		case ST_Alarm_On:
		Alarm_On();
		break;
	}

}

void Main_Menu(void)
{
	LCD_Display_String((const Puint8)"Welcome");
	LCD_GoTO_XY(LCD_Line2,LCD_Col1);
	LCD_Display_String((const Puint8)"1) Alarm");
	LCD_GoTO_XY(LCD_Line3,LCD_Col1);
	LCD_Display_String((const Puint8)"2) StopWatch");
	
	Program_state = ST_Get_Input;
	while(Program_state == ST_Get_Input)
	{	
		My_Delay(100);
		input = Keypad_Read_Character(Keypad_Read_Single_Press);
		switch(input)
		{
			case Alarm:
			Program_state = ST_Alarm_Count;
			break;
			
			case Stopwatch:
			Program_state = ST_Stopwatch;
			break;
		}
	}
}

void Alarm_Count(void)
{
	LCD_Clear();
	LCD_Display_String((const Puint8)"Please enter time");
	Program_state = ST_Get_Input;
	while(Program_state == ST_Get_Input)
	{
		My_Delay(100);
		input = Read_number();
		switch(input)
		{
			case Error:
			LCD_Clear();
			LCD_Display_String((const Puint8)"Invalid input");
			My_Delay(1000);
			Program_state = ST_Main_Menu;
			break;
			
			default:
			Program_state = ST_Alarm_On;
			break;
		}
	}

	uint32 Temp_input = input;
	while(input != (uint32)-1) 
	{
		LCD_Clear();
		LCD_Display_String((const Puint8)"Alarm mode: ");
		LCD_Display_Number(Temp_input);
		LCD_GoTO_XY(LCD_Line2, LCD_Col1);

		LCD_Display_Number(input);
		My_Delay(1000);
		input--;		
	}
	LCD_Clear();
	LCD_Display_String((const Puint8)"Alarm On");
}

void Alarm_On(void)
{
	Port_Set_Pin_Mode(PORTC_ADD, PORT_PIN6, PIN_Output_High);
	My_Delay(500);
	DIO_Write_Channel(PORTC_ADD, PORT_PIN6, PIN_Low);
	My_Delay(500);
}

void Start_Stopwatch(void)
{
	LCD_Clear();
	LCD_Display_String((const Puint8)"Stopwatch mode:");
	LCD_GoTO_XY(LCD_Line2, LCD_Col1);
	LCD_Display_String((const Puint8)"HH:MM:SS");
	uint8 Seconds = 0,Minutes = 0;
	uint32 Hours = 0;
	while(1)
	{
		LCD_GoTO_XY(LCD_Line3, LCD_Col1);	
		if(Seconds == 60)
		{
			Seconds = 0;
			Minutes++;
		}
		if(Minutes == 60)
		{
			Minutes = 0;
			Hours++;
		}
		
		if(Hours <= 9)
		{
			LCD_Display_Character('0');
			LCD_Display_Number(Hours);
		}
		else
		{
			LCD_Display_Number(Hours);
		}
		LCD_Display_Character(':');
		
		if(Minutes <= 9)
		{
			LCD_Display_Character('0');
			LCD_Display_Number(Minutes);
		}
		else
		{
			LCD_Display_Number(Minutes);
		}
		LCD_Display_Character(':');				
		
		if(Seconds <= 9)
		{
			LCD_Display_Character('0');
			LCD_Display_Number(Seconds);
		}
		else
		{
			LCD_Display_Number(Seconds);
		}
		My_Delay(1000);
		LCD_Display_String((const Puint8)"                    ");	//Clear line
		Seconds++;
	}
	Program_state = ST_Main_Menu;
}

void My_Delay(uint32 Time_Delay)
{
	Timer0_Delay_ms(Time_Delay);
	while(Timer_Flag == 1);
	Timer_Flag = 1;
}

uint32 Read_number(void)
{
	uint8 Keypad_SW = Keypad_SW_NULL;
	uint32 Number = 0;
	while(1)
	{
		Keypad_SW = Keypad_Read_Character(Keypad_Read_Single_Press);
		My_Delay(100);

		if	((Keypad_SW < '0' || Keypad_SW > '9') && Keypad_SW != Keypad_SW_NULL)
			break;
		else if(Keypad_SW != Keypad_SW_NULL)
		{
			Number *= 10;
			Number += Keypad_SW -'0';
		}
	}
	return Number;
}

