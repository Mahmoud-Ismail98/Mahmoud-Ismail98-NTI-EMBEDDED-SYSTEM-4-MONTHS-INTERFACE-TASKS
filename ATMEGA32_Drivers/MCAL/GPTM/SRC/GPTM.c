/*
 * GPTM.c
 *
 * Created: 10/23/2023 9:18:56 PM
 *  Author: Mahmoud Tariq
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CLCK.h"

#include "PORT.h"
#include "DIO.h"
#include "GPTM.h"
#include "GPTM_CFG.h"
#include "GPTM_PRIVATE.h"

void(*timerClbk_ptr[4])(void);
void GPTM_TIMER0_vidInit(void)
{
	

	
		/*=================Setting TIMER0 CLOCK============*/
				TCCR0 &= GPTM_TIMER0_INIT_CLOCK_MASK;
				TCCR0 |= GPTM_TIMER0_FREQ;	
			
		/*=================Setting TIMER0 MODE============*/
					
		#if (GPTM_TIMER0_MODE == GPTM_TIMER0_NORMAL_MODE) //Initializing Timer0 to work on Normal Mode of wave generation
			CLR_BIT(TCCR0,TCCR0_WGM00);
			CLR_BIT(TCCR0,TCCR0_WGM01);
			
		#elif (GPTM_TIMER0_MODE == GPTM_TIMER0_CTC_MODE) //Initializing TIMER0 to work on CTC Mode of wave Generation
			CLR_BIT(TCCR0,TCCR0_WGM00);
			SET_BIT(TCCR0,TCCR0_WGM01);
			
		#elif (GPTM_TIMER0_MODE == GPTM_TIMER0_FASTPWM_MODE) //Initializing TIMER0 To work on Fast PWM Mode of wave generation
			SET_BIT(TCCR0,TCCR0_WGM00);
			SET_BIT(TCCR0,TCCR0_WGM01);
		#elif (GPTM_TIMER0_MODE == GPTM_TIMER0_PhaseCorrect_Mode) //Initializing TIMER0 To work on PhaseCorrect Mode of wave generation
			SET_BIT(TCCR0,TCCR0_WGM00);
			CLR_BIT(TCCR0,TCCR0_WGM01);
		#endif
		
					/*=================Setting OC0 PIN MODE============*/
					
		#if (GPTM_TIMER0_OC0_MODE == GPTM_TIMER0_OC0_NORMAL)  //Init OC0 Pin In normal operating Mode on event
					
			if( GPTM_TIMER0_MODE == GPTM_TIMER0_CTC_MODE ||GPTM_TIMER0_MODE == GPTM_TIMER0_NORMAL_MODE)//Checking TIMER0 MODE OF OPERATION
			{
				CLR_BIT(TCCR0,TCCR0_COM00);
				CLR_BIT(TCCR0,TCCR0_COM01);
			}
			else if(GPTM_TIMER0_MODE == GPTM_TIMER0_FASTPWM_MODE || GPTM_TIMER0_MODE == GPTM_TIMER0_PhaseCorrect_Mode)
			{
				CLR_BIT(TCCR0,TCCR0_COM00);
				CLR_BIT(TCCR0,TCCR0_COM01);
			}
			else{} //Do Nothing
			
		#elif (GPTM_TIMER0_OC0_MODE == GPTM_TIMER0_OC0_TGL)     //Init OC0 Pin to toggle on event
			if( GPTM_TIMER0_MODE == GPTM_TIMER0_CTC_MODE ||GPTM_TIMER0_MODE == GPTM_TIMER0_NORMAL_MODE)
			{
				SET_BIT(TCCR0,TCCR0_COM00);
				CLR_BIT(TCCR0,TCCR0_COM01);
			}
			else if(GPTM_TIMER0_MODE == GPTM_TIMER0_FASTPWM_MODE || GPTM_TIMER0_MODE == GPTM_TIMER0_PhaseCorrect_Mode)
			{
				SET_BIT(TCCR0,TCCR0_COM00);
				CLR_BIT(TCCR0,TCCR0_COM01);
			}
			else{} //Do Nothing
				
		#elif (GPTM_TIMER0_OC0_MODE == GPTM_TIMER0_OC0_SET)     //Init OC0 Pin to Set on event
			if( GPTM_TIMER0_MODE ==  GPTM_TIMER0_CTC_MODE ||GPTM_TIMER0_MODE ==  GPTM_TIMER0_NORMAL_MODE)
			{
				SET_BIT(TCCR0,TCCR0_COM00);
				SET_BIT(TCCR0,TCCR0_COM01);
			}
			else if(GPTM_TIMER0_MODE == GPTM_TIMER0_FASTPWM_MODE ||GPTM_TIMER0_MODE ==  GPTM_TIMER0_PhaseCorrect_Mode)
			{
				SET_BIT(TCCR0,TCCR0_COM00);
				SET_BIT(TCCR0,TCCR0_COM01);
			}
			else{} //Do Nothing
				
		#elif (GPTM_TIMER0_OC0_MODE == GPTM_TIMER0_OC0_CLEAR)   //Init OC0 Pin to CLR On event
			if( GPTM_TIMER0_MODE == GPTM_TIMER0_CTC_MODE || GPTM_TIMER0_MODE == GPTM_TIMER0_NORMAL_MODE)
			{
				CLR_BIT(TCCR0,TCCR0_COM00);
				SET_BIT(TCCR0,TCCR0_COM01);
			}
			else if(GPTM_TIMER0_MODE == GPTM_TIMER0_FASTPWM_MODE ||GPTM_TIMER0_MODE ==  GPTM_TIMER0_PhaseCorrect_Mode)
			{
				CLR_BIT(TCCR0,TCCR0_COM00);
				SET_BIT(TCCR0,TCCR0_COM01);
			}
			else{} //Do Nothing
		#endif
		
		
		#if (GPTM_TIMER0_INTERRUPT_MODE == GPTM_TIMER0_OVERFLOW_IE) //Enable TIMER0 OVERFLOW INTERRUPT
			SET_BIT(TIMSK,TOIE0);
			CLR_BIT(TIMSK,OCIE0);
		#elif (GPTM_TIMER0_INTERRUPT_MODE == GPTM_TIMER0_COMPARE_MATCH_IE) //Enable TIME0 COMPARE MATCH INTERRUPT
			CLR_BIT(TIMSK,TOIE0);
			SET_BIT(TIMSK,OCIE0);
		#elif (GPTM_TIMER0_INTERRUPT_MODE == GPTM_TIMER0_DISABLE_INTERRUPT)  //DISABLE TIMER0 INTERRUPTS
			CLR_BIT(TIMSK,OCIE0);
			CLR_BIT(TIMSK,TOIE0);
		#endif		
	
}


void GPTM_TIMER0_vidSetCompareMatchValue(u8 copy_u8Value)
{
	OCR0 = copy_u8Value;
	
}
/*

void GPTM_vidTIMER1_ICU_MODE(void){
	SET_BIT(TCCR1B,TCCR1B_ICNC1);
	
	#if   (1 == GPTM_TIMER1_ICU_Capture_on_the_falling_edge )
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	#elif (1 == GPTM_TIMER1_ICU_Capture_on_the_rising_edge)
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	#endif
	
	
	#if (1 ==  GPTM_Timer1_Freq_Default)
		CLR_BIT(TCCR1B,TCCR1B_CS12);
		CLR_BIT(TCCR1B,TCCR1B_CS11);
		SET_BIT(TCCR1B,TCCR1B_CS10);
	#elif (1 == GPTM_Timer1_Freq_Prescaler1_8)
		CLR_BIT(TCCR1B,TCCR1B_CS12);
		SET_BIT(TCCR1B,TCCR1B_CS11);
		CLR_BIT(TCCR1B,TCCR1B_CS10);
	#elif (1 == GPTM_Timer1_Freq_Prescaler1_64)
		CLR_BIT(TCCR1B,TCCR1B_CS12);
		SET_BIT(TCCR1B,TCCR1B_CS11);
		SET_BIT(TCCR1B,TCCR1B_CS10);
	#elif (1 == GPTM_Timer1_Freq_Prescaler1_256)
		SET_BIT(TCCR1B,TCCR1B_CS12);
		CLR_BIT(TCCR1B,TCCR1B_CS11);
		CLR_BIT(TCCR1B,TCCR1B_CS10);
	#elif (1 == GPTM_Timer1_Freq_Prescaler1_1024)
		SET_BIT(TCCR1B,TCCR1B_CS12);
		CLR_BIT(TCCR1B,TCCR1B_CS11);
		SET_BIT(TCCR1B,TCCR1B_CS10);
	#elif (1 == GPTM_TIMER1_Ext_clck_src_on_T1_pin_Clck_on_falling_edge)
		SET_BIT(TCCR1B,TCCR1B_CS12);
		SET_BIT(TCCR1B,TCCR1B_CS11);
		CLR_BIT(TCCR1B,TCCR1B_CS10);
	#elif (1 == GPTM_TIMER1_Ext_clck_src_on_T1_pin_Clck_on_rising_edge)
		SET_BIT(TCCR1B,TCCR1B_CS12);
		SET_BIT(TCCR1B,TCCR1B_CS11);
	    SET_BIT(TCCR1B,TCCR1B_CS10);
	#endif
	
}*/

void GPTM_timer0_setCallBack(void(*funClbk_ptr)(void), u8 index)
{
	timerClbk_ptr[index] = funClbk_ptr;
}


void GPTM_timer0_setPwm(u8 compareValue)
{
	/*=================Setting TIMER0 CLOCK============*/
	TCCR0 &= GPTM_TIMER0_INIT_CLOCK_MASK;
	TCCR0 |= GPTM_TIMER0_FREQ;
	//PORT_enuSetPinDirection(TIMER_ZERO_OC_PIN,PORT_PIN_OUTPUT);

	OCR0 = compareValue;

	//	SET_BIT(TCCR0,WGM00);
	//	SET_BIT(TCCR0,WGM01);
	//	SET_BIT(TCCR0,COM00);
	//	SET_BIT(TCCR0,CS01);

	CLR_BIT(TCCR0,TCCR0_FOC0);

	//SET_BIT(TCCR0,WGM01);
	//SET_BIT(TCCR0,WGM00);

}
void __vector_10	(void)	__attribute__((signal,used));
void __vector_10	(void)
{
	if(timerClbk_ptr[1] != NULL)
	{
		timerClbk_ptr[1]();
	}
}

void GPTM_TIMER0_vidDeInit(void)
{

TCCR0 = 0xF8;
}

void GPTM_timer0_CLERPwm(void)
{
	OCR0 = 0;
}