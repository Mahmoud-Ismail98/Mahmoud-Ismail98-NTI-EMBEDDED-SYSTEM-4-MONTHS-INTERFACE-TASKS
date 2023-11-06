/
#include "../../../4-SERVICS/Std_types.h"
#include "../../../4-SERVICS/Bit_utils.h"
#include "../../5-EXIT/include/EXIT.h"
#include "../../3-Timer/Include/Timer_Reg.h"
#include "../../3-Timer/Include/Timer.h"
#include "../../3-Timer/Include/Timer_CFg.h"
#include "../../3-Timer/Include/Timer_Prv.h"

void (*Global_pvCTCFunction)(void)= NULL;
void (*Global_pvICUFunction)(void)= NULL;
u8 pwmDutyCycle =0;
Timer_tenuErrorStatus Timer0_voidInit(void){
u8 Error_u8State = Timer_EnmOk;
// Set Timer0 Mode
#ifndef Enable_Timer0
#if TIMER0_u8_WAVEFORM_MODE == TIMER0_NORMAL
    CLR_BIT(TCCR0,TCCR0_WGM00);
    CLR_BIT(TCCR0,TCCR0_WGM01);
#elif TIMER0_u8_WAVEFORM_MODE == TIMER0_CTC
    SET_BIT(TCCR0,TCCR0_WGM00);
    CLR_BIT(TCCR0,TCCR0_WGM01);
#elif TIMER0_u8_WAVEFORM_MODE == TIMER0_FASTPWM
    SET_BIT(TCCR0,TCCR0_WGM01);
     SET_BIT(TCCR0,TCCR0_WGM00);
#elif TIMER0_u8_WAVEFORM_MODE == TIMER0_PHASEPWM
    CLR_BIT(TCCR0,TCCR0_WGM01);
    SET_BIT(TCCR0,TCCR0_WGM00);
#endif
     // Set Prescaller of timer0
#if TIMER0_u8_PRESCALLER == TIMER0_STOP
            CLR_BIT(TCCR0,TCCR0_CS00);
    		CLR_BIT(TCCR0,TCCR0_CS01);
    		CLR_BIT(TCCR0,TCCR0_CS02);
    	#elif TIMER0_u8_PRESCALLER == TIMER0_DIV_BY_1
    		SET_BIT(TCCR0,TCCR0_CS00);
    		CLR_BIT(TCCR0,TCCR0_CS01);
    		CLR_BIT(TCCR0,TCCR0_CS02);
    	#elif TIMER0_u8_PRESCALLER == TIMER0_DIV_BY_8
    		CLR_BIT(TCCR0,TCCR0_CS00);
    		SET_BIT(TCCR0,TCCR0_CS01);
    		CLR_BIT(TCCR0,TCCR0_CS02);
    	#elif TIMER0_u8_PRESCALLER == TIMER0_DIV_BY_64
    		SET_BIT(TCCR0,TCCR0_CS00);
    		SET_BIT(TCCR0,TCCR0_CS01);
    		CLR_BIT(TCCR0,TCCR0_CS02);
    	#elif TIMER0_u8_PRESCALLER == TIMER0_DIV_BY_256
    		CLR_BIT(TCCR0,TCCR0_CS00);
    		CLR_BIT(TCCR0,TCCR0_CS01);
    		SET_BIT(TCCR0,TCCR0_CS02);
    	#elif TIMER0_u8_PRESCALLER == TIMER0_DIV_BY_1024
    		SET_BIT(TCCR0,TCCR0_CS00);
    		CLR_BIT(TCCR0,TCCR0_CS01);
    		SET_BIT(TCCR0,TCCR0_CS02);

    	#endif
OCR0=64;
    	// Set Interrupt Of Timer0
      #if TIMER0_u8_INTERRUPT == TIMER0_u8_ENABLE_INTERRUPT
		  #if TIMER0_u8_WAVEFORM_MODE == TIMER0_u8_NORMAL
			SET_BIT(TIMSK,TIMSK_TOIE0);
		 #elif TIMER0_u8_WAVEFORM_MODE == TIMER0_u8_CTC
			SET_BIT(TIMSK,TIMSK_OCIE0);
		#endif
   #endif
#endif

	// Timer 1
#ifndef EnableTimer1
// NORMAL TIMER1
#if TIMER1_u8_WAVEFORM_MODE == TIMER1_NORMAL
    CLR_BIT(TCCR1A,TCCR1A_WGM10);
    CLR_BIT(TCCR1A,TCCR1A_WGM11);
    CLR_BIT(TCCR1B,TCCR1B_WGM12);
    CLR_BIT(TCCR1B,TCCR1B_WGM13);
    // CTC TIMER1
#elif TIMER1_u8_WAVEFORM_MODE == TIMER1_CTC
    CLR_BIT(TCCR1A,TCCR1A_WGM10);
    CLR_BIT(TCCR1A,TCCR1A_WGM11);
    SET_BIT(TCCR1B,TCCR1B_WGM12);
    CLR_BIT(TCCR1B,TCCR1B_WGM13);

    // TIMER MODES FOR CTC TIMER

        #if TIMER1_u8_MODECTC == OC1ADISCONNECTED
        CLR_BIT(TCCR1A,TCCR1A_COM1A0);
        CLR_BIT(TCCR1A,TCCR1A_COM1A1);
        #elif TIMER1_u8_MODECTC == Toggle_OC1A_OnCompareMatch
        SET_BIT(TCCR1A,TCCR1A_COM1A0);
        CLR_BIT(TCCR1A,TCCR1A_COM1A1);
        #elif TIMER1_u8_MODECTC == CLEAR_ON_COMPARE
        CLR_BIT(TCCR1A,TCCR1A_COM1A0);
        SET_BIT(TCCR1A,TCCR1A_COM1A1);
        #elif TIMER1_u8_MODECTC == SET_ON_COMPARE
        SET_BIT(TCCR1A,TCCR1A_COM1A0);
        SET_BIT(TCCR1A,TCCR1A_COM1A1);
        #endif

// TIMER0_FASTPWM
#elif TIMER1_u8_WAVEFORM_MODE == TIMER0_FASTPWM
    SET_BIT(TCCR1A,TCCR1A_WGM10);
    CLR_BIT(TCCR1A,TCCR1A_WGM11);
    SET_BIT(TCCR1B,TCCR1B_WGM12);
    CLR_BIT(TCCR1B,TCCR1B_WGM13);


    // TIMER1 MODE FOR FASTPWM TIMER1
#if TIMER1_u8_MODE == OC1ADISCONNECTED
    CLR_BIT(TCCR1A,TCCR1A_COM1A0);
    CLR_BIT(TCCR1A,TCCR1A_COM1A1);
    #elif TIMER1_u8_MODE ==ToggleOC1AOnCompareMatch
    SET_BIT(TCCR1A,TCCR1A_COM1A0);
    CLR_BIT(TCCR1A,TCCR1A_COM1A1);
    #elif TIMER1_u8_MODE == NON_INVERTING
    CLR_BIT(TCCR1A,TCCR1A_COM1A0);
    SET_BIT(TCCR1A,TCCR1A_COM1A1);
    #elif TIMER1_u8_MODE == INVERTING
    SET_BIT(TCCR1A,TCCR1A_COM1A0);
    SET_BIT(TCCR1A,TCCR1A_COM1A1);
    #endif


    // TIMER0_PHASEPWM
#elif TIMER1_u8_WAVEFORM_MODE == TIMER0_PHASEPWM
    CLR_BIT(TCCR1A,TCCR1A_WGM10);
    SET_BIT(TCCR1A,TCCR1A_WGM11);
    CLR_BIT(TCCR1B,TCCR1B_WGM12);
    SET_BIT(TCCR1B,TCCR1B_WGM13);
    // TIMER1 MODE FOR PHASE TIMER1
#if TIMER1_u8_MODE == OC1ADISCONNECTED
    CLR_BIT(TCCR1A,TCCR1A_COM1A0);
    CLR_BIT(TCCR1A,TCCR1A_COM1A1);
    #elif TIMER1_u8_MODE ==ToggleOC1AOnCompareMatch
    SET_BIT(TCCR1A,TCCR1A_COM1A0);
    CLR_BIT(TCCR1A,TCCR1A_COM1A1);
    #elif TIMER1_u8_MODE == NON_INVERTING
    CLR_BIT(TCCR1A,TCCR1A_COM1A0);
    SET_BIT(TCCR1A,TCCR1A_COM1A1);
    #elif TIMER1_u8_MODE == INVERTING
    SET_BIT(TCCR1A,TCCR1A_COM1A0);
    SET_BIT(TCCR1A,TCCR1A_COM1A1);
    #endif

#endif

     // Set Prescaller of timer1
#if TIMER1_u8_PRESCALLER == TIMER0_STOP
            CLR_BIT(TCCR1A,TCCR0_CS00);
    		CLR_BIT(TCCR1A,TCCR0_CS01);
    		CLR_BIT(TCCR1A,TCCR0_CS02);
    	#elif TIMER1_u8_PRESCALLER == TIMER0_DIV_BY_1
    		SET_BIT (TCCR1B,TCCR1B_CS10);
    		CLR_BIT (TCCR1B,TCCR1B_CS11);
    	    CLR_BIT (TCCR1B,TCCR1B_CS12);
    	#elif TIMER1_u8_PRESCALLER == TIMER0_DIV_BY_8
    	    CLR_BIT (TCCR1B,TCCR1B_CS10);
    	    SET_BIT (TCCR1B,TCCR1B_CS11);
    	    CLR_BIT (TCCR1B,TCCR1B_CS12);
    	#elif TIMER1_u8_PRESALLER == TIMER0_DIV_BY_64
    		SET_BIT (TCCR1B,TCCR1B_CS10);
    		SET_BIT (TCCR1B,TCCR1B_CS11);
    		CLR_BIT (TCCR1B,TCCR1B_CS12);
    	#elif TIMER1_u8_PRESCALLER == TIMER0_DIV_BY_256
    		CLR_BIT (TCCR1B,TCCR1B_CS10);
    		CLR_BIT (TCCR1B,TCCR1B_CS11);
    		SET_BIT (TCCR1B,TCCR1B_CS12);
    	#elif TIMER1_u8_PRESCALLER == TIMER0_DIV_BY_1024
    		SET_BIT (TCCR1B,TCCR1B_CS10);
    		CLR_BIT (TCCR1B,TCCR1B_CS11);
    		SET_BIT (TCCR1B,TCCR1B_CS12);

    	#endif
#endif
return Error_u8State;

}


void Timer_voidSetPWM(u16 Copy_u16CompareValue) {
	    // Set the compare value for PWM duty cycle
	    OCR0 = Copy_u16CompareValue;
	    pwmDutyCycle = (u8)((Copy_u16CompareValue * 100) / 255);
}


void TIMERS_voidTimer0CTCSetCallBackFunction (void(*Copy_pvCTCFunction)(void))
{
	if (Copy_pvCTCFunction != NULL){
	Global_pvCTCFunction = Copy_pvCTCFunction;
	}
	else /* nothing  */ ;
}


void Timer_voidGetTimerCountValue(u16 * Copy_u16CounterValue){
	* Copy_u16CounterValue = TCNT0;
}


u8 Timer_u8GetPWMOnPeriod (u16 * Copy_pu16onPeriod){
	if (Copy_pu16onPeriod != NULL){
		* Copy_pu16onPeriod = OCR0;
		return 0;
	}
	else return 1;
}


void TIMERS_voidTIMER0SetCompareMatchValue(u8 Copy_u8CompareMatchValue){
      OCR0 = Copy_u8CompareMatchValue;
}


u8 Timer_u8GetTotalPWMOnPeriod (u32 * Copy_pu32TotalPeriod){
	if (Copy_pu32TotalPeriod != NULL){
		* Copy_pu32TotalPeriod = OCR0 * 256;
		return 0;
	}
	else return 1;
}


u8 Timer_u8GetPWMDutyCycle (u8 * Copy_pu8DutyCycle){
	if (Copy_pu8DutyCycle != NULL){
		*Copy_pu8DutyCycle = pwmDutyCycle;
		return 0;
	}
	else
		{
		return 1;
		}

}


/*ISR For Timer 0 Compare Match*/
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(Global_pvCTCFunction != NULL)
	{
		Global_pvCTCFunction();
	}
	else
	{
		/*Do Nothing*/
	}
}



/**************************** TIMER 1 ***************************/
/******************************************************************/
void TIMERS_voidTimer1SetOverflowValue (u16 Copy_u16OverflowValue)
{
	ICR1 = Copy_u16OverflowValue;
}

void TIMERS_voidTimer1ChannelASetCompareMatchValue(u16 Copy_u16CompareMatchValue)
{
	OCR1A = Copy_u16CompareMatchValue;
}

void TIMERS_voidTimer1ChannelBSetCompareMatchValue(u16 Copy_u16CompareMatchValue)
{
	OCR1B = Copy_u16CompareMatchValue;
}
/******************************** ICU ***************************/
/****************************************************************/
void TIMERS_voidICUSetCallBackFunction (void(*Copy_pvICUFunction)(void))
{
	if (Copy_pvICUFunction != NULL){
	Global_pvICUFunction = Copy_pvICUFunction;
	}
	else /* nothing  */ ;
}

void ICU_voidSetSenseControl (u8 Copy_u8SenseControl)
{
	switch(Copy_u8SenseControl)
	{
	case FALLIND_EDGE:
		SET_BIT(TCCR1B,TCCR1B_ICES1);break;
	case RISING_EDGE:
		CLR_BIT( TCCR1B,TCCR1B_ICES1);break;
	}
}
u16 ICU_u16ReadInputCapture (void)
{
	return ICR1;
}
void ICU_voidSetEnableIntterrupt (u8 Copy_u8Interrupt){
	switch(Copy_u8Interrupt)
		{
		case Enable:
			SET_BIT( TIMSK,TIMSK_TICIE1);break;
		case Disable:
			CLR_BIT( TIMSK,TIMSK_TICIE1);break;
		}
}

/*ISR For Input Capture Unit*/
void __vector_6(void) __attribute__((signal));
void __vector_6 (void)
{
	if(Global_pvICUFunction != NULL)
	{
		Global_pvICUFunction();
	}
	else
	{
		/*Do Nothing*/
	}
}

