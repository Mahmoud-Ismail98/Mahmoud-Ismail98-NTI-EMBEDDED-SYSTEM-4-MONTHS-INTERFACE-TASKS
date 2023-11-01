/*
 * TIMER.c
 *
 * Created: 10/24/2023 11:58:38 AM
 *  Author: FADY
 */

 #include "../../SERVICES/Std_types.h"
#include "../../SERVICES/Bit_utils.h"
#include "Timer.h"
#include "Timer_prv.h"
#include "Timer_cfg.h"
volatile  u16 Global_u8Counter = 0;
static u16 TIMER_u16OnPeriod=0,TIMER_u16OffPeriod=0;
static void(*Timer_pfNotification[2])(void);

void Timer_voidInit(void)
{
	#if (TIMER0_OVF_INTERRUPT_INIT == TIMER_INTERRUPT_ENABLE)
		SET_BIT(TIMSK,TIMSK_TOIE0);
	#elif(TIMER0_OVF_INTERRUPT_INIT == TIMER_INTERRUPT_DISABLE)
		CLR_BIT(TIMSK,TIMSK_TOIE0);
	#endif
	#if (TIMER0_CTC_INTERRUPT_INIT == TIMER_INTERRUPT_ENABLE)
		SET_BIT(TIMSK,TIMSK_OCIE0);
	#elif(TIMER0_CTC_INTERRUPT_INIT == TIMER_INTERRUPT_DISABLE)
		CLR_BIT(TIMSK,TIMSK_OCIE0);
	#endif
     	//Choose The Mode of the timer and the prescaler
     #if TIMER0_MODE == TIMER0_FAST_PWM
     	OCR0 = TIMER_u8_OCR0_INIT_VALUE;
     	SET_BIT(TCCR0,TCCR0_WGM00);
     	SET_BIT(TCCR0,TCCR0_WGM01);
     #elif TIMER0_MODE == TIMER0_PHASE_CORRECT_PWM
     	OCR0 = TIMER_u8_OCR0_INIT_VALUE;
     	SET_BIT(TCCR0,TCCR0_WGM00);
     	CLR_BIT(TCCR0,TCCR0_WGM01);
     #elif TIMER0_MODE == TIMER0_NORMAL_MODE
     	TCNT0 = TIMER0_u8_PRELOAD_VALUE;
     	CLR_BIT(TCCR0,TCCR0_WGM00);
     	CLR_BIT(TCCR0,TCCR0_WGM01);
	 #elif TIMER0_MODE == TIMER0_CTC_MODE
     	OCR0 = TIMER_u8_OCR0_INIT_VALUE;
     	SET_BIT(TCCR0,TCCR0_WGM01);
     	CLR_BIT(TCCR0,TCCR0_WGM00);
     #endif
     #if TIMER_u8_OC0_PIN_MODE == TIMER_u8_OCX_CLEAR
     	SET_BIT(TCCR0,TCCR0_COM01);
     	CLR_BIT(TCCR0,TCCR0_COM00);
	 #elif TIMER_u8_OC0_PIN_MODE == TIMER_u8_OCX_SET
     	SET_BIT(TCCR0,TCCR0_COM01);
     	SET_BIT(TCCR0,TCCR0_COM00);
     #endif
     /* Select the Prescaler value to start the timer to count */
     	TCCR0 |= TIMER0_CLOCK_SOURCE;

}


void Timer_voidSetPWM(u16 Copy_u16CompareValue)
{
	OCR0 = Copy_u16CompareValue;
}

void Timer_voidSetCallBack(void(*Copy_pfNotification)(void),u8 Copy_u8TimerIntIndex)
{
	Timer_pfNotification[Copy_u8TimerIntIndex] = Copy_pfNotification;
}


TIMER_ErrorState   TImer_u8GetPWMOnPeriod   (pu16  Copy_pu16OnPeriod)
{
	u8 Local_u8ReturnState = TIMER_OK;
	if(Copy_pu16OnPeriod == NULL)
	{
		
		Local_u8ReturnState  = TIMER_NULLPTR;
	}
	else{
		*Copy_pu16OnPeriod = TIMER_u16OnPeriod;
	}
	return Local_u8ReturnState;
}
TIMER_ErrorState   TImer_u8GetPWMTotalPeriod(pu32  Copy_pu32TotalPeriod)
{
	u8 Local_u8ReturnState = TIMER_OK;
		if(Copy_pu32TotalPeriod == NULL)
	{
		
		Local_u8ReturnState  = TIMER_NULLPTR;
	}
	else
	{
		*Copy_pu32TotalPeriod = (u32)(TIMER_u16OnPeriod + TIMER_u16OffPeriod);
		
	}
	return Local_u8ReturnState;
}
TIMER_ErrorState   TImer_u8GetPWMDutyCycle  (pu8   Copy_pu8DutyCycle)
{
	u8 Local_u8ReturnState = TIMER_OK;
	if(Copy_pu8DutyCycle == NULL)
	{
		
		Local_u8ReturnState  = TIMER_NULLPTR;
	}
	else{
		*Copy_pu8DutyCycle =(u8)(((u32)TIMER_u16OnPeriod * 100) / (TIMER_u16OnPeriod + TIMER_u16OffPeriod));
	}
	return Local_u8ReturnState;
}
void Timer_voidGetTimer1CounterValue(pu16  Copy_u16CounterValue)
{
	*Copy_u16CounterValue = Global_u8Counter;
}
// void TIMER0_delay_init(u16 Copy_u8MS) {
//     // Timer properties
//     const double Ttick = 256.0 / 1000.0; // Tick time is 0.256 ms as prescaler is 256
//     const double Tmaxdelay = 65.536;      // Time for max delay is 65.536 as Timer0 is an 8-bit counter

//     u16 T_initial;

//     if (Copy_u8MS == (int)Tmaxdelay) {
//         // If the desired delay is equal to the max delay, there will be only one overflow, and start with zero
//         T_initial = 0;
//         TIMER_u16NOV = 1;
//     } else if (Copy_u8MS < Tmaxdelay) {
//         // If the desired delay is less than the max delay, there will be only one overflow, and not start with zero
//         T_initial = (Tmaxdelay - Copy_u8MS) / Ttick;
//         TIMER_u16NOV = 1;
//     } else {
//         // If the desired delay is more than the max delay, there will be more than one overflow, and not start with zero
//         TIMER_u16NOV = ceil((double)Copy_u8MS / Tmaxdelay);
//         T_initial = (1 << 8) - ((double)Copy_u8MS / Ttick) / TIMER_u16NOV;
//     }

//     // Configure timer
//     TCNT0 = T_initial;
// 	// Set 256 prescaler
//     TCCR0 |= TIMER0_CLOCK_SOURCE; 
// }





/* ISR Function for Timer0 OVF */
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	
	Global_u8Counter++;


}















