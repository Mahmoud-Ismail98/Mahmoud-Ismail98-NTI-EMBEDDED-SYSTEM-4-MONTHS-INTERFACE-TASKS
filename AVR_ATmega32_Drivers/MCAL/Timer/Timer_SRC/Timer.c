/*
 * Timer0.c
 *
 * Created: 10/24/2023 12:11:40 PM
 *  Author: Mohamed Alaa
 */ 

#include <Services/Std_types.h>
#include <Services/Bit_utils.h>
#include <MCAL/Timer/Timer_Includes/Timer.h>
#include <MCAL/Timer/Timer_Includes/Timer_CFG.h>
#include <MCAL/Timer/Timer_Includes/Timer_Private.h>
#include <MCAL/PORT/PORT_Includes/Port.h>


void Timer0_Init(Timer0_Config_t* Timer0_CFG)
{
	Timer0_GCFG = *Timer0_CFG;
	TCCR0 = 0;
	//set Timer_Opertion_Mode
	TCCR0 |= (GET_BIT(Timer0_CFG->Timer_Opertion_Mode, 0) << WGM00);	
	TCCR0 |= (GET_BIT(Timer0_CFG->Timer_Opertion_Mode, 1) << WGM01);
	
	if(Timer0_CFG->Output_Compare_Mode == Timer0_OC0_Toggle_Normal)
	{
		if(Timer0_CFG->Timer_Opertion_Mode == Timer0_Normal_Mode)
		{
			TCCR0 |= (Timer0_CFG->Output_Compare_Mode << COM0n);

		}
		else
		{
			//invalid invalid input: reserved
		}
	}
	else
	{
		TCCR0 |= (Timer0_CFG->Output_Compare_Mode << COM0n);

	}
	
	TIMSK &= ~(0x03 << TOIE0);
	TIMSK |=  (Timer0_CFG->Timer_OCM_Interrupt_State << OCIE0) | (Timer0_CFG->Timer_Overflow_Interrupt_State << TOIE0);
	
	uint32 Prescaler_Value = 0;
	
	switch(Timer0_CFG->Timer_Clock_Select)
	{
		case Timer0_Clock_Prescaler_1:
		Prescaler_Value = 1;
		break;
		
		case Timer0_Clock_Prescaler_8:
		Prescaler_Value = 8;
		break;
		
		case Timer0_Clock_Prescaler_64:
		Prescaler_Value = 64;
		
		break;
		
		case Timer0_Clock_Prescaler_256:
		Prescaler_Value = 256;
		
		break;
		
		case Timer0_Clock_Prescaler_1024:
		Prescaler_Value = 1024;
		break;
	}
	Tic_Time = (1000000.0 * (float64)(Prescaler_Value)) / (float64)F_CPU ;	//Tic_Time in us
	
	//Clock is still disabled timer will start through Timer_Delay_ms or Timer0_Run_Free
}

void Timer0_Set_CallBack(void(*Timer_PCallBack)(void), uint8 Timer_INTx)
{
	Timer0_GPCallBack[Timer_INTx] = Timer_PCallBack;
}

void Timer0_Delay_ms(uint32 Time_Delay)
{
	Timer0_Run_Free_State = Timer0_Run_Free_Disable;
	Timer0_Total_Tics = (uint32)((float64)Time_Delay*1000.0 / Tic_Time);
	Timer0_Flag_Counts = Timer0_Total_Tics / 255;
	Timer0_Last_Time_Tics = Timer0_Total_Tics % 255;

	if(Timer0_Flag_Counts > 0)
	{
	
		
		if(Timer0_GCFG.Timer_Overflow_Interrupt_State == Timer_Interrupt_Enable)
		{
			TCNT0 = 0;
			OCR0 = 0;
		}
		else if (Timer0_GCFG.Timer_OCM_Interrupt_State == Timer_Interrupt_Enable)
		{
			TCNT0 = 0;	
			OCR0 = 255;
		}	
	}
	else if (Timer0_Last_Time_Tics > 0)
	{
		if(Timer0_GCFG.Timer_Overflow_Interrupt_State == Timer_Interrupt_Enable)
		{
			TCNT0 = 256 - Timer0_Last_Time_Tics;
			OCR0 = 0;
		}
		else if (Timer0_GCFG.Timer_OCM_Interrupt_State == Timer_Interrupt_Enable)
		{
			TCNT0 = 0;
			OCR0 = Timer0_Last_Time_Tics;
		}
	}
	
	//enable timer clock to start counting
	TCCR0 &= ~(0x07  << CS0n);
	TCCR0 |= (Timer0_GCFG.Timer_Clock_Select << CS0n);
}

void Timer0_Hold(void)
{
	TCCR0 &= ~(0x07  << CS0n);
}

void Timer0_Stop(void)
{
	TCCR0 &= ~(0x07  << CS0n);
	TCNT0 = 0;
}

void Timer0_Continue(void)
{
	TCCR0 &= ~(0x07  << CS0n);
	TCCR0 |= Timer0_GCFG.Timer_Clock_Select;
}

void Timer0_Run_Free(void)
{
	TCNT0 = 0;
	TCCR0 &= ~(0x07  << CS0n);
	TCCR0 |= (Timer0_GCFG.Timer_Clock_Select << CS0n);
	Timer0_Run_Free_State = Timer0_Run_Free_Enable;
}

float64 Timer0_Read_Register_Time(void)
{
	return Tic_Time*TCNT0;
}

float64 Timer0_OVF_Time(void)
{
	return Tic_Time*256;
}


void Timer1_Input_Capture_Init(void(*Timer_PCallBack)(void))
{
	Timer1_GPCallBack = Timer_PCallBack;
	Timer1_Input_Capture_Rising();
	SET_BIT(TIMSK, TICIE1);
}

void Timer1_Input_Capture_Start(void)
{
	TCCR1B |= (2 << CS10);
}

uint16 Timer1_Read_ICR_Value(void)
{
	return ICR1;
}

void Timer1_Stop(void)
{
	TCCR1B &= ~(0x07  << CS10);
	TCNT1 = 0;
}

void Timer1_Input_Capture_Rising()
{
	SET_BIT(TCCR1B, ICES1);
}				
void Timer1_Input_Capture_Falling()				
{
	CLR_BIT(TCCR1B, ICES1);
}
void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	Timer1_GPCallBack();	
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if (  Timer0_Run_Free_State == Timer0_Run_Free_Enable)
	{
		Timer0_GPCallBack[Timer0_INT_Over_Flow]();
	}
	else
	{	
		static uint32 Overflow_ISR_Cnt = 0;
		Overflow_ISR_Cnt++;
		if (Timer0_Flag_Counts > 0)
		{
			if(Overflow_ISR_Cnt == Timer0_Flag_Counts)
			{
				
				Overflow_ISR_Cnt = 0;
				if(Timer0_Last_Time_Tics > 0)
				{
					Timer0_Flag_Counts = 1;
					TCNT0 = 256 - Timer0_Last_Time_Tics;
					Timer0_Last_Time_Tics = 0;
				}
				else
				{
					Timer0_Stop();
					Timer0_Flag_Counts = 0;
					Timer0_GPCallBack[Timer0_INT_Over_Flow]();
				}
			}


		}
		else
		{
			Timer0_Stop();
			Timer0_Last_Time_Tics = 0;
			Timer0_GPCallBack[Timer0_INT_Over_Flow]();
		}
	}
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	
	if (  Timer0_Run_Free_State == Timer0_Run_Free_Enable)
	{
		Timer0_GPCallBack[Timer0_INT_Output_Compare_Match]();
	}
		else
		{
			static uint32 Overflow_ISR_Cnt = 0;
			Overflow_ISR_Cnt++;
			if (Timer0_Flag_Counts > 0)
			{
				if(Overflow_ISR_Cnt == Timer0_Flag_Counts)
				{
					
					Overflow_ISR_Cnt = 0;
					if(Timer0_Last_Time_Tics > 0)
					{
						Timer0_Flag_Counts = 1;
						TCNT0 = Timer0_Last_Time_Tics;
						Timer0_Last_Time_Tics = 0;
					}
					else
					{
						Timer0_Stop();
						Timer0_Flag_Counts = 0;
						Timer0_GPCallBack[Timer0_INT_Output_Compare_Match]();
					}
				}
			}
			else
			{
				Timer0_Stop();
				Timer0_Last_Time_Tics = 0;
				Timer0_GPCallBack[Timer0_INT_Output_Compare_Match]();
			}
	}
}
