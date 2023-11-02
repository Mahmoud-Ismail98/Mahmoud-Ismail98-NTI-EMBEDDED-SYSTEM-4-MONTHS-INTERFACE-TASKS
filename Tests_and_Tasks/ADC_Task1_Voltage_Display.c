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

void ADC_Task1(void);

uint8 Display_Mode = 0;

void EXTI_INT0_ISR_CallBack(void)
{
	Display_Mode ^= 1;
}

int main(void)
{
	
	PORT_Init();
	LCD_Init();
	
	Port_Set_Pin_Mode(PORTA_ADD, PORT_PIN0, PIN_Input_Floating);
	ADC_Config_t ADC_CFG = {ADC_VREF_AVCC, ADC_Channel_ADC0, ADC_Auto_Trigger_Disable, ADC_Interrupt_State_Disable, ADC_Prescale_128, ADC_Trigger_EXTI0, PTR_NULL};
	ADC_Set_Config(&ADC_CFG);

	EXTI_Init();
	Port_Set_Pin_Mode(PORTD_ADD, PORT_PIN2, PIN_Input_pullup);
	EXTI_Enable(EXTI_INT0, EXTI_Falling_Edge, EXTI_INT0_ISR_CallBack);
	
	while(1)
	{
		ADC_Task1();
	}
}

void ADC_Task1(void)
{
	uint32 ADC_value=0;
	float32 voltage;
	uint32 vloatge_int, vloatge_fraction;
	ADC_Start();
	ADC_Read(&ADC_value);
	
	switch(Display_Mode)
	{
		case 0: 	//Display mv
		ADC_value = (ADC_value*5000)/(1<<10);
		LCD_Clear();
		LCD_Display_Number(ADC_value);
		_delay_ms(200);
		break;
		
		case 1:   //Display volt
		voltage = ((float32)(ADC_value*5))/(1<<10);
		vloatge_int = voltage;
		vloatge_fraction = (voltage-vloatge_int)*1000;

		LCD_Clear();
		LCD_Display_Number(vloatge_int);
		LCD_Display_Character('.');
		LCD_Display_Number(vloatge_fraction);
		_delay_ms(200);
		break;
	}
}



