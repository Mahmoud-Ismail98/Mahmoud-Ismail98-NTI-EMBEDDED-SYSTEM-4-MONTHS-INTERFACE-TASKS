/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : EXTI                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/
#include "Std_types.h"
#include "Bit_utils.h"

#include "EXTI.h"
#include "EXTI_prv.h"
#include "EXTI_cfg.h"

// GLOBAL array of pointers to functions to hold ISR addresses 
void (*EXTI_ISR_POINTERS[3])() = {NULL, NULL, NULL};
void EXTI_voidInit(void){
    // initializing INT0 
    #if EXTI0_OPERATION == EXTI_ENABLE
        SET_BIT(GICR,GICR_INT0);
        #if EXTI0_SENSE_CONTROL == EXTI_LOW_LEVEL
            // set sense control for INT0 on low level
            CLR_BIT(MCUCR, MCUCR_ISC00);
            CLR_BIT(MCUCR, MCUCR_ISC01);

        #elif EXTI0_SENSE_CONTROL == EXTI_ON_CHANGE
            // set sense control for INT0 on a logical change
            SET_BIT(MCUCR, MCUCR_ISC00);
            CLR_BIT(MCUCR, MCUCR_ISC01);

        #elif EXTI0_SENSE_CONTROL == EXTI_FALLING_EDGE
            // set sense control for INT0 on a falling edge
            CLR_BIT(MCUCR, MCUCR_ISC00);
            SET_BIT(MCUCR, MCUCR_ISC01);

        #elif EXTI0_SENSE_CONTROL == EXTI_RISING_EDGE
            // set sense control for INT0 on a rising edge
            SET_BIT(MCUCR, MCUCR_ISC00);
            SET_BIT(MCUCR, MCUCR_ISC01);
        #endif

    #elif EXTI_INT0_INITIAL_STATE == EXTI_DISABLE
        CLR_BIT(GICR,GICR_INT0);
    #else 

    #endif

    // initializing INT1 
    #if EXTI1_OPERATION == EXTI_ENABLE
        SET_BIT(GICR,GICR_INT1);
        #if EXTI1_SENSE_CONTROL == EXTI_LOW_LEVEL
            // set sense control for INT1 on low level
            CLR_BIT(MCUCR, MCUCR_ISC10);
            CLR_BIT(MCUCR, MCUCR_ISC11);

        #elif EXTI1_SENSE_CONTROL == EXTI_ON_CHANGE
            // set sense control for INT1 on a logical change
            SET_BIT(MCUCR, MCUCR_ISC10);
            CLR_BIT(MCUCR, MCUCR_ISC11);

        #elif EXTI1_SENSE_CONTROL == EXTI_FALLING_EDGE
            // set sense control for INT1 on a falling edge
            CLR_BIT(MCUCR, MCUCR_ISC10);
            SET_BIT(MCUCR, MCUCR_ISC11);

        #elif EXTI1_SENSE_CONTROL == EXTI_RISING_EDGE
            // set sense control for INT1 on a rising edge
            SET_BIT(MCUCR, MCUCR_ISC10);
            SET_BIT(MCUCR, MCUCR_ISC11);
        #endif


    #elif EXTI_INT0_INITIAL_STATE == EXTI_DISABLE
        CLR_BIT(GICR,GICR_INT0);
    #else 

    #endif
     
    // initializing INT2
    #if EXTI2_OPERATION == EXTI_ENABLE
        SET_BIT(GICR,GICR_INT2);
        #if EXTI_SENSE_CONTROL == EXTI_RISING_EDGE
            // set sense control for INT2 on a rising edge
            SET_BIT(MCUCSR, MCUCSR_ISC2);
        #elif EXTI1_SENSE_CONTROL == EXTI_FALLING_EDGE
            // set sense control for INT2 on a falling edge
            CLR_BIT(MCUCSR, MCUCSR_ISC2);
        #endif


    #elif EXTI_INT0_INITIAL_STATE == EXTI_DISABLE
        CLR_BIT(GICR,GICR_INT0);
    #else 

    #endif
}

tenuErrorStatus EXTI_enuErrorStateInt0SetCallBack(void (*Copy_pvInt0Func)()){
    tenuErrorStatus Local_u8ErrorState = no_error;
    if(Copy_pvInt0Func != NULL){
        EXTI_ISR_POINTERS[0] = Copy_pvInt0Func;
    }
    else {
        Local_u8ErrorState = ERROR_nullPointer;
    }
    return Local_u8ErrorState;

}
void __vector_1(void) __attribute__((signal));
void __vector_1(void){
    if (EXTI_ISR_POINTERS[0] != NULL){
        EXTI_ISR_POINTERS[0]();
    }
}

tenuErrorStatus EXTI_enuErrorStateInt1SetCallBack(void (*Copy_pvInt1Func)()){
    tenuErrorStatus Local_u8ErrorState = no_error;
    if(Copy_pvInt1Func != NULL){
        EXTI_ISR_POINTERS[1] = Copy_pvInt1Func;
    }
    else {
        Local_u8ErrorState = ERROR_nullPointer;
    }
    return Local_u8ErrorState;

}
void __vector_2(void) __attribute__((signal));
void __vector_2(void){
    if (EXTI_ISR_POINTERS[1] != NULL){
        EXTI_ISR_POINTERS[1]();
    }
}


tenuErrorStatus EXTI_enuErrorStateInt2SetCallBack(void (*Copy_pvInt2Func)()){
    tenuErrorStatus Local_u8ErrorState = no_error;
    if(Copy_pvInt2Func != NULL){
        EXTI_ISR_POINTERS[2] = Copy_pvInt2Func;
    }
    else {
        Local_u8ErrorState = ERROR_nullPointer;
    }
    return Local_u8ErrorState;

}
void __vector_3(void) __attribute__((signal));
void __vector_3(void){
    if (EXTI_ISR_POINTERS[2] != NULL){
        EXTI_ISR_POINTERS[2]();
    }
}

