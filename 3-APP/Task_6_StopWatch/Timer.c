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

void (*TIMER_0_OVERFLOW_ISR_POINTER)() = NULL;
void (*TIMER_0_CTC_ISR_POINTER)() = NULL;

void (*TIMER_2_OVERFLOW_ISR_POINTER)() = NULL;
void (*TIMER_2_CTC_ISR_POINTER)() = NULL;

/*****************************************************************************/
/*****************************************************************************/
/*******************************    TIMER 0    *******************************/
/*****************************************************************************/
/*****************************************************************************/
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
        TIMER_0_OVERFLOW_ISR_POINTER = Copy_pvT0overflowFunc;
    }
    else {
        Local_u8ErrorState = ERROR_nullPointer;
    }
    return Local_u8ErrorState;

}
void __vector_11(void) __attribute__((signal));
void __vector_11(void){
    if (TIMER_0_OVERFLOW_ISR_POINTER != NULL){
        TIMER_0_OVERFLOW_ISR_POINTER();
    }
}

tenuErrorStatus Timer0_enuErrorStateCTCSetCallBack(void (*Copy_pvT0CTCFunc)(void)){
    tenuErrorStatus Local_u8ErrorState = no_error;
    if(Copy_pvT0CTCFunc != NULL){
        TIMER_0_CTC_ISR_POINTER = Copy_pvT0CTCFunc;
    }
    else {
        Local_u8ErrorState = ERROR_nullPointer;
    }
    return Local_u8ErrorState;

}
void __vector_10(void) __attribute__((signal));
void __vector_10(void){
    if (TIMER_0_CTC_ISR_POINTER != NULL){
        TIMER_0_CTC_ISR_POINTER();
    }
}


/*****************************************************************************/
/*****************************************************************************/
/*******************************    TIMER 2    *******************************/
/*****************************************************************************/
/*****************************************************************************/
void TIMER_2_voidInit(Timer2_cfg * prt_TIMER2_CFG){
    if (prt_TIMER2_CFG->TIMER_2_MODE == TIMER_2_MODE_NORMAL){
        CLR_BIT(TCCR2, 3); 
        CLR_BIT(TCCR2, 6);
    }else if (prt_TIMER2_CFG->TIMER_2_MODE == TIMER_2_MODE_PWM_PHASE_CORRECT){
        CLR_BIT(TCCR2, 3); 
        SET_BIT(TCCR2, 6);
    }else if (prt_TIMER2_CFG->TIMER_2_MODE == TIMER_2_MODE_CTC){
        SET_BIT(TCCR2, 3); 
        CLR_BIT(TCCR2, 6);
    }else if (prt_TIMER2_CFG->TIMER_2_MODE == TIMER_2_MODE_FAST_PWM){
        SET_BIT(TCCR2, 3); 
        SET_BIT(TCCR2, 6);
    }

    if (prt_TIMER2_CFG->OC2_MODE == OC0_MODE_NORMAL_PORT){
        CLR_BIT(TCCR2, 5); 
        CLR_BIT(TCCR2, 4);
    }else if (prt_TIMER2_CFG->OC2_MODE == OC0_MODE_TOGGLE_ON_CTC){
        CLR_BIT(TCCR2, 5); 
        SET_BIT(TCCR2, 4);
    }else if (prt_TIMER2_CFG->OC2_MODE == OC0_MODE_CLEAR_ON_CTC_NON_INV){
        SET_BIT(TCCR2, 5); 
        CLR_BIT(TCCR2, 4);
    }else if (prt_TIMER2_CFG->OC2_MODE == OC0_MODE_SET_ON_CTC_INV){
        SET_BIT(TCCR2, 5); 
        SET_BIT(TCCR2, 4);
    }

    if (prt_TIMER2_CFG->TIMER_2_INTERRUPT_MODE == TIMER_2_INTERRUPT_MODE_DISABLE){
        CLR_BIT(TIMSK, 6);
        CLR_BIT(TIMSK, 7);
    }else if (prt_TIMER2_CFG->TIMER_2_INTERRUPT_MODE == TIMER_2_INTERRUPT_MODE_ENABLE_OVERFLOW){
        SET_BIT(TIMSK, 6);
    }else if (prt_TIMER2_CFG->TIMER_2_INTERRUPT_MODE == TIMER_2_INTERRUPT_MODE_ENABLE_CTC){
        SET_BIT(TIMSK, 7);
    }else if (prt_TIMER2_CFG->TIMER_2_INTERRUPT_MODE == TIMER_2_INTERRUPT_MODE_ENABLE_OVERFLOW_CTC){
        SET_BIT(TIMSK, 6);
        SET_BIT(TIMSK, 7);
    }

    TCCR2 &= 0b11111000;
    TCCR2 |= prt_TIMER2_CFG->CLOCK_MODE;
}

void TIMER_2_void_setValue(u8 copy_u8Value){
    TCNT2 = copy_u8Value;
}

void TIMER_2_void_setCTCValue(u8 copy_u8CompareValue){
    OCR2 = copy_u8CompareValue;
}

u8 TIMER_2_void_getValue(){
    return TCNT2 ;
}

u8 TIMER_2_void_getCTCValue(){
    return OCR2 ;
}

tenuErrorStatus Timer2_enuErrorStateOverFlowSetCallBack(void (*Copy_pvT2overflowFunc)(void)){
    tenuErrorStatus Local_u8ErrorState = no_error;
    if(Copy_pvT2overflowFunc != NULL){
        TIMER_2_OVERFLOW_ISR_POINTER = Copy_pvT2overflowFunc;
    }
    else {
        Local_u8ErrorState = ERROR_nullPointer;
    }
    return Local_u8ErrorState;

}
void __vector_5(void) __attribute__((signal));
void __vector_5(void){
    if (TIMER_2_OVERFLOW_ISR_POINTER != NULL){
        TIMER_2_OVERFLOW_ISR_POINTER();
    }
}

tenuErrorStatus Timer2_enuErrorStateCTCSetCallBack(void (*Copy_pvT2CTCFunc)(void)){
    tenuErrorStatus Local_u8ErrorState = no_error;
    if(Copy_pvT2CTCFunc != NULL){
        TIMER_2_CTC_ISR_POINTER = Copy_pvT2CTCFunc;
    }
    else {
        Local_u8ErrorState = ERROR_nullPointer;
    }
    return Local_u8ErrorState;

}
void __vector_4(void) __attribute__((signal));
void __vector_4(void){
    if (TIMER_2_CTC_ISR_POINTER != NULL){
        TIMER_2_CTC_ISR_POINTER();
    }
}
