/*
 * Timer0.h
 *
 * Created: 10/24/2023 11:19:21 AM
 *  Author: Mohamed Alaa
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "Services/Bit_utils.h"
#include "Services/Std_types.h"

typedef struct
{
	uint8 Timer_Opertion_Mode;						//this member is set according to @Timer_Opertion_Mode macros Reference
	uint8 Output_Compare_Mode;						//this member is set according to @Output_Compare_Mode macros Reference
	uint8 Timer_Clock_Select;						//this member is set according to @Timer_Clock_Select macros Reference
	uint8 Timer_OCM_Interrupt_State;
	uint8 Timer_Overflow_Interrupt_State;
}Timer0_Config_t;

//========================================
//@Timer_Opertion_Mode macros Reference
//========================================
#define Timer0_Normal_Mode							((uint8) 0)
#define Timer0_PWM_Phase_Correct_Mode				((uint8) 1) //This mode allows greater control of the Compare Match output frequency. It also simplifies the operation of counting external events.
#define Timer0_Clear_OC0_on_Compare_Match_Mode		((uint8) 2)
#define Timer0_Fast_PWM_Mode						((uint8) 3)




//========================================
//@Output_Compare_Mode macros Reference
//========================================
#define Timer0_OC0_Disconnected						((uint8) 0)
#define Timer0_OC0_Toggle_Normal					((uint8) 1)
#define Timer0_OC0_Clear_On_match					((uint8) 2)
#define Timer0_OC0_Set_On_match						((uint8) 3)


//========================================
//@Timer_Clock_Select macros Reference
//========================================
#define	Timer0_clock_Disable						((uint8) 0)
#define Timer0_Clock_Prescaler_1					((uint8) 1)
#define Timer0_Clock_Prescaler_8					((uint8) 2)
#define Timer0_Clock_Prescaler_64					((uint8) 3)
#define Timer0_Clock_Prescaler_256					((uint8) 4)
#define Timer0_Clock_Prescaler_1024					((uint8) 5)		// the clock is selected internally based on the timer needs
#define	Timer_clock_External						((uint8) 7)		//clock is connected on T0 pin


//========================================
//@Timer_Interrupt_State macros Reference
//========================================
#define	Timer_Interrupt_Disable						((uint8) 0)
#define	Timer_Interrupt_Enable						((uint8) 1)




//========================================
//@Timer Interrupt index for Timer_INTx
//========================================
#define Timer0_INT_Output_Compare_Match				1
#define Timer0_INT_Over_Flow						0

void Timer0_Init(Timer0_Config_t* Timer0_CFG);
void Timer0_Set_CallBack(void(*Timer_PCallBack)(void), uint8 Timer_INTx);
void Timer0_Delay_ms(uint32 Time_Delay);
void Timer0_Stop(void);
void Timer0_Run_Free(void);
float64 Timer0_Read_Register_Time(void);
float64 Timer0_OVF_Time(void);
void Timer1_Input_Capture_Init(void(*Timer_PCallBack)(void));
uint16 Timer1_Read_ICR_Value(void);
void Timer1_Stop(void);
void Timer1_Input_Capture_Start(void);
void Timer1_Input_Capture_Falling();
void Timer1_Input_Capture_Rising();
#endif /* TIMER0_H_ */