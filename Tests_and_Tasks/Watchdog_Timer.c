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

void Timer_OVF_CallBack(void)
{
	Timer_Flag = 0;
}


int main()
{
Init_ALL();
	while(1)
	{
		Watchdog_Start(Watchdog_Time_2100ms);
		for (uint8 Cnt=0; Cnt < 10; ++Cnt)
		{
			LCD_Display_Number(Cnt);
			My_Delay(300);
			LCD_Clear();
		}
		Watchdog_Stop();
	}
	return 0;
}

void Init_ALL(void)
{
	PORT_Init();
	LCD_Init();
	GIE_Enable();
 	Timer0_Config_t Timer_Cfg = {Timer0_Normal_Mode, Timer0_OC0_Set_On_match, Timer0_Clock_Prescaler_256, Timer_Interrupt_Disable,Timer_Interrupt_Enable};
 	Timer0_Init(&Timer_Cfg);
 	Timer0_Set_CallBack(Timer_OVF_CallBack, Timer0_INT_Over_Flow);
}

void My_Delay(uint32 Time_Delay)
{
	Timer0_Delay_ms(Time_Delay);
	while(Timer_Flag == 1);
	Timer_Flag = 1;
}



