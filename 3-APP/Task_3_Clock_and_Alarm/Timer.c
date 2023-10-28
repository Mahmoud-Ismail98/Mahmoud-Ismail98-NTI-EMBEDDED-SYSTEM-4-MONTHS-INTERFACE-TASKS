/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : Timer               **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "Std_types.h"
#include "Bit_utils.h"

#include "Timer.h"
#include "Timer_prv.h"
#include "Timer_cfg.h"

void (*TIMER_OVERFLOW_ISR_POINTERS)() = NULL;
void (*TIMER_CTC_ISR_POINTERS)() = NULL;

void TIMER_0_voidInit(Timer0_cfg * prt_TIMER0_CFG){
    if (prt_TIMER0_CFG->TIMER_0_MODE == TIMER_0_MODE_NORMAL){
        CLR_BIT(TCCR0, 3); 
        CLR_BIT(TCCR0, 6);
    }else if (prt_TIMER0_CFG->TIMER_0_MODE == TIMER_0_MODE_PWM_PHASE_CORRECT){
        CLR_BIT(TCCR0, 3); 
        SET_BIT(TCCR0, 6);
    }else if (prt_TIMER0_CFG->TIMER_0_MODE == TIMER_0_MODE_CTC){
        SET_BIT(TCCR0, 3); 
        CLR_BIT(TCCR0, 6);
    }else if (prt_TIMER0_CFG->TIMER_0_MODE == TIMER_0_MODE_FAST_PWM){
        SET_BIT(TCCR0, 3); 
        SET_BIT(TCCR0, 6);
    }

    if (prt_TIMER0_CFG->OC0_MODE == OC0_MODE_NORMAL_PORT){
        CLR_BIT(TCCR0, 5); 
        CLR_BIT(TCCR0, 4);
    }else if (prt_TIMER0_CFG->OC0_MODE == OC0_MODE_TOGGLE_ON_CTC){
        CLR_BIT(TCCR0, 5); 
        SET_BIT(TCCR0, 4);
    }else if (prt_TIMER0_CFG->OC0_MODE == OC0_MODE_CLEAR_ON_CTC_NON_INV){
        SET_BIT(TCCR0, 5); 
        CLR_BIT(TCCR0, 4);
    }else if (prt_TIMER0_CFG->OC0_MODE == OC0_MODE_SET_ON_CTC_INV){
        SET_BIT(TCCR0, 5); 
        SET_BIT(TCCR0, 4);
    }

    if (prt_TIMER0_CFG->TIMER_0_INTERRUPT_MODE == TIMER_0_INTERRUPT_MODE_DISABLE){
        CLR_BIT(TIMSK, 0);
        CLR_BIT(TIMSK, 1);
    }else if (prt_TIMER0_CFG->TIMER_0_INTERRUPT_MODE == TIMER_0_INTERRUPT_MODE_ENABLE_OVERFLOW){
        SET_BIT(TIMSK, 0);
    }else if (prt_TIMER0_CFG->TIMER_0_INTERRUPT_MODE == TIMER_0_INTERRUPT_MODE_ENABLE_CTC){
        SET_BIT(TIMSK, 1);
    }else if (prt_TIMER0_CFG->TIMER_0_INTERRUPT_MODE == TIMER_0_INTERRUPT_MODE_ENABLE_OVERFLOW_CTC){
        SET_BIT(TIMSK, 0);
        SET_BIT(TIMSK, 1);
    }

    TCCR0 &= 0b11111000;
    TCCR0 |= prt_TIMER0_CFG->CLOCK_MODE;
}

void TIMER_0_void_setValue(u8 copy_u8Value){
    TCNT0 = copy_u8Value;
}

void TIMER_0_void_setCTCValue(u8 copy_u8CompareValue){
    OCR0 = copy_u8CompareValue;
}

u8 TIMER_0_void_getValue(){
    return TCNT0 ;
}

u8 TIMER_0_void_getCTCValue(){
    return OCR0 ;
}

tenuErrorStatus Timer0_enuErrorStateOverFlowSetCallBack(void (*Copy_pvT0overflowFunc)(void)){
    tenuErrorStatus Local_u8ErrorState = no_error;
    if(Copy_pvT0overflowFunc != NULL){
        TIMER_OVERFLOW_ISR_POINTERS = Copy_pvT0overflowFunc;
    }
    else {
        Local_u8ErrorState = ERROR_nullPointer;
    }
    return Local_u8ErrorState;

}
void __vector_11(void) __attribute__((signal));
void __vector_11(void){
    if (TIMER_OVERFLOW_ISR_POINTERS != NULL){
        TIMER_OVERFLOW_ISR_POINTERS();
    }
}

tenuErrorStatus Timer0_enuErrorStateCTCSetCallBack(void (*Copy_pvT0CTCFunc)(void)){
    tenuErrorStatus Local_u8ErrorState = no_error;
    if(Copy_pvT0CTCFunc != NULL){
        TIMER_CTC_ISR_POINTERS = Copy_pvT0CTCFunc;
    }
    else {
        Local_u8ErrorState = ERROR_nullPointer;
    }
    return Local_u8ErrorState;

}
void __vector_10(void) __attribute__((signal));
void __vector_10(void){
    if (TIMER_CTC_ISR_POINTERS != NULL){
        TIMER_CTC_ISR_POINTERS();
    }
}

