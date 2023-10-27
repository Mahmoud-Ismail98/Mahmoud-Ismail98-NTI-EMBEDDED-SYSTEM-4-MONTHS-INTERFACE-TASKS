/*
=======================================================================================================================
Author       : Mamoun
Module       : Timer-0
File Name    : timer0.h
Date Created : Oct 27, 2023
Description  : Header file for the ATmega32 Timer-0 driver.
=======================================================================================================================
*/


#ifndef MCAL_TIMER0_INCLUDES_TIMER0_H_
#define MCAL_TIMER0_INCLUDES_TIMER0_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/



/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    TIMER0_NO_ERRORS,
    TIMER0_NULL_PTR_ERROR,
    TIMER0_PRESCALER_ERROR,
    TIMER0_OPERATION_MODE_ERROR,
    TIMER0_COMPARE_OUTPUT_MODE_ERROR
}TIMER0_errorStatus;

typedef enum
{
    TIMER0_OVERFLOW_MODE,
    TIMER0_PHASE_CORRECT_PWM_MODE,
    TIMER0_COMPARE_MATCH_MODE,
    TIMER0_FAST_PWM_MODE
}TIMER0_operationMode;

typedef enum
{
    TIMER0_NO_CLOCK,
    TIMER0_PRESCALER_1,
    TIMER0_PRESCALER_8,
    TIMER0_PRESCALER_64,
    TIMER0_PRESCALER_256,
    TIMER0_PRESCALER_1024
}TIMER0_prescalerID;

typedef enum
{
    TIMER0_NON_PWM_NO_OUTPUT,
    TIMER0_NON_PWM_TOGGLE_OC0,
    TIMER0_NON_PWM_CLEAR_OC0,
    TIMER0_NON_PWM_SET_OC0,

    TIMER0_FAST_PWM_NO_OUTPUT,
    TIMER0_FAST_PWM_CLEAR_OC0 = 0X06,
    TIMER0_FAST_PWM_SET_OC0,

    TIMER0_PHASE_CORRECT_PWM_NO_OUTPUT,
    TIMER0_PHASE_CORRECT_PMW_CLEAR_OC0 = 0X0A,
    TIMER0_PHASE_CORRECT_PWM_SET_OC0
}TIMER0_compareOutputMode;

typedef struct
{
    uint32 time_in_millis;
    TIMER0_operationMode timer_mode;
    TIMER0_prescalerID prescaler_id;
    TIMER0_compareOutputMode compare_output_mode;
}TIMER0_configurations;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : TIMER0_init
 * [Description]   : Initialize Timer-1 peripheral with specific configurations.
 * [Arguments]     : <a_ptr2configurations>      -> Pointer to structure holds the configurations.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Prescaler Error.
 *                                                          - Null Pointer Error.
 *                                                          - Operation Mode Error.
 *                                                          - Compare Output Mode Error.
 ====================================================================================================================*/
TIMER0_errorStatus TIMER0_init(TIMER0_configurations* a_ptr2configurations);

/*=====================================================================================================================
 * [Function Name] : TIMER0_setCallBackFunction
 * [Description]   : Set the call-back function address of a specific Timer-1 operation mode.
 * [Arguments]     : <a_timerMode>             -> Indicates to the timer operation mode.
 *                   <a_ptr2callBackFunction>  -> Pointer to the call-back function.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 *                                                          - Operation Mode Error.
 ====================================================================================================================*/
TIMER0_errorStatus TIMER0_setCallBackFunction(TIMER0_operationMode a_timerMode, void (*a_ptr2callBackFunction)(void));

#endif /* MCAL_TIMER0_INCLUDES_TIMER0_H_ */
