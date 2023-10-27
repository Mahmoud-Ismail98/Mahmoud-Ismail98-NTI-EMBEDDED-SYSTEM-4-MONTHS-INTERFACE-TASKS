/*
=======================================================================================================================
Author       : Mamoun
Module       : Timer-1
File Name    : timer1.h
Date Created : Oct 27, 2023
Description  : Header file for the ATmega32 Timer-1 driver.
=======================================================================================================================
*/


#ifndef MCAL_TIMER1_INCLUDES_TIMER1_H_
#define MCAL_TIMER1_INCLUDES_TIMER1_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/



/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    TIMER1_NO_ERRORS,
    TIMER1_NULL_PTR_ERROR,
    TIMER1_PRESCALER_ERROR,
    TIMER1_OPERATION_MODE_ERROR,
    TIMER1_COMPARE_OUTPUT_MODE_ERROR
}TIMER1_errorStatus;

typedef enum
{
    TIMER1_OVERFLOW_MODE,
    TIMER1_COMPARE_MATCH_MODE = 0X04,
    TIMER1_PHASE_CORRECT_PWM_MODE = 0X0B,
    TIMER1_FAST_PWM_MODE = 0X0F,
}TIMER1_operationMode;

typedef enum
{
    TIMER1_NO_CLOCK,
    TIMER1_PRESCALER_1,
    TIMER1_PRESCALER_8,
    TIMER1_PRESCALER_64,
    TIMER1_PRESCALER_256,
    TIMER1_PRESCALER_1024
}TIMER1_prescalerID;

typedef enum
{
    TIMER1_NON_PWM_NO_OUTPUT,
    TIMER1_NON_PWM_TOGGLE_OC1,
    TIMER1_NON_PWM_CLEAR_OC1,
    TIMER1_NON_PWM_SET_OC1,

    TIMER1_FAST_PWM_NO_OUTPUT,
    TIMER1_FAST_PWM_TOGGLE_OC1A,
    TIMER1_FAST_PWM_CLEAR_OC1,
    TIMER1_FAST_PWM_SET_OC1,

    TIMER1_PHASE_CORRECT_PWM_NO_OUTPUT,
    TIMER1_PHASE_CORRECT_PMW_CLEAR_OC1 = 0X0A,
    TIMER1_PHASE_CORRECT_PWM_SET_OC1
}TIMER1_compareOutputMode;

typedef struct
{
    uint32 time_in_millis;
    TIMER1_operationMode timer_mode;
    TIMER1_prescalerID prescaler_id;
    TIMER1_compareOutputMode channel_a_output_mode;
    TIMER1_compareOutputMode channel_b_output_mode;
}TIMER1_configurations;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : TIMER1_init
 * [Description]   : Initialize Timer-1 peripheral with specific configurations.
 * [Arguments]     : <a_ptr2configurations>      -> Pointer to structure holds the configurations.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Prescaler Error.
 *                                                          - Null Pointer Error.
 *                                                          - Operation Mode Error.
 *                                                          - Compare Output Mode Error.
 ====================================================================================================================*/
TIMER1_errorStatus TIMER1_init(TIMER1_configurations* a_ptr2configurations);

/*=====================================================================================================================
 * [Function Name] : TIMER1_setCallBackFunction
 * [Description]   : Set the call-back function address of a specific Timer-1 operation mode.
 * [Arguments]     : <a_timerMode>             -> Indicates to the timer operation mode.
 *                   <a_ptr2callBackFunction>  -> Pointer to the call-back function.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 *                                                          - Operation Mode Error.
 ====================================================================================================================*/
TIMER1_errorStatus TIMER1_setCallBackFunction(TIMER1_operationMode a_timerMode, void (*a_ptr2callBackFunction)(void));

#endif /* MCAL_TIMER1_INCLUDES_TIMER1_H_ */
