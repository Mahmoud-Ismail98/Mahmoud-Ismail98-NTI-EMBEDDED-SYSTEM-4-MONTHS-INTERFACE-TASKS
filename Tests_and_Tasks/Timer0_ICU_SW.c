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
#include <HAL/Keypad/Keypad_Includes/Keypad.h>
#include <MCAL/Watchdog/Watchdog_Includes/Watchdog.h>
#include <limits.h>
#include <stdint.h>

void Init_ALL(void);
void My_Delay(uint32 Time_Delay);

uint8 Timer_Flag = 1;
uint64 count_OVF = 0;
uint8 Count_Edges = 0;
uint8 PWM_Measured = 0;
float64 OVF_Time = 0;
float64 On_Time = 0;
float64 Off_Time = 0;

void Timer_OVF_CallBack(void)
{
	count_OVF++;
}

void EXTI_INT0_CallBack(void)
{
	if(!Count_Edges)
	{
		Timer0_Run_Free();
		Count_Edges = 1;
	}
	switch(Count_Edges)
	{
		case 1:
		EXTI_Enable(EXTI_INT0,  EXTI_Falling_Edge, EXTI_INT0_CallBack);
		Count_Edges++;
		break;
		
		case 2:
		On_Time = Timer0_Read_Register_Time() + count_OVF*OVF_Time;
		EXTI_Enable(EXTI_INT0,  EXTI_Rising_Edge, EXTI_INT0_CallBack);
		Count_Edges++;
		break;
		
		case 3:
		Off_Time = Timer0_Read_Register_Time() + count_OVF*OVF_Time - On_Time;
		Timer0_Stop();
		PWM_Measured = 1;
		Count_Edges = 4;
		count_OVF = 0;
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
		LCD_Display_Number((uint32)(On_Time + Off_Time));
		LCD_GoTO_XY(LCD_Line2, LCD_Col1);
		LCD_Display_String((const Puint8)"On time: ");
		LCD_Display_Number(On_Time);
		_delay_ms(1000);
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
	EXTI_Init();
	GIE_Init();
	GIE_Enable();
 	Timer0_Config_t Timer_Cfg = {Timer0_Normal_Mode, Timer0_OC0_Set_On_match, Timer0_Clock_Prescaler_256, Timer_Interrupt_Disable,Timer_Interrupt_Enable};
 	Timer0_Init(&Timer_Cfg);
 	Timer0_Set_CallBack(Timer_OVF_CallBack, Timer0_INT_Over_Flow);
	Port_Set_Pin_Mode(PORTD_ADD, PORT_PIN2, PIN_Input_Floating);
	EXTI_Enable(EXTI_INT0,  EXTI_Rising_Edge, EXTI_INT0_CallBack);
	OVF_Time = Timer0_OVF_Time();

}

void My_Delay(uint32 Time_Delay)
{
	Timer0_Delay_ms(Time_Delay);
	while(Timer_Flag == 1);
	Timer_Flag = 1;
}



