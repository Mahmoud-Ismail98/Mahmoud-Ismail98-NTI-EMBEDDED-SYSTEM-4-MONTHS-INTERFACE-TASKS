/*
=======================================================================================================================
Author       : Mamoun
Module       : Timer-0
File Name    : timer0.c
Date Created : Oct 27, 2023
Description  : Source file for the ATmega32 Timer-0 driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../OTHERS/std_types.h"
#include "../../../OTHERS/common_macros.h"
#include "../INCLUDES/timer0_prv.h"
#include "../INCLUDES/timer0_cfg.h"
#include "../INCLUDES/timer0.h"
#include <avr/io.h>

/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/

static volatile void (*g_callBackFunctionsArray[TIMER0_NUM_OF_INTERRUPT_MODES])(void) = {NULL_PTR,NULL_PTR};

static uint64 g_number_of_cycles = 0;
static uint8 g_preload_value = 0;
static uint8 g_compare_value = 0;

/*=====================================================================================================================
                                      < Private Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : TIMER0_getPrescalerValue
 * [Description]   : Get the value of the Timer-0 prescaler based on its ID.
 * [Arguments]     : <a_prescalerID>      -> Indicates to the prescaler ID.
 * [return]        : The function returns the prescaler value.
 ====================================================================================================================*/
static uint16 TIMER0_getPrescalerValue(TIMER0_prescalerID a_prescalerID);

/*=====================================================================================================================
 * [Function Name] : TIMER0_ticksCalculator
 * [Description]   : Calculate the number of timer ticks needed to reach the desired time period.
 * [Arguments]     : <a_time>           -> Indicates to the desired time period in milli seconds.
 *                   <a_prescalerValue> -> Indicates to the prescaler value.
 *                   <a_timerMode>      -> Indicates to the timer operation mode.
 * [return]        : The function returns void.
 ====================================================================================================================*/
static void TIMER0_ticksCalculator(uint32 a_time, uint16 a_prescalerValue, TIMER0_operationMode a_timerMode);

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : TIMER0_init
 * [Description]   : Initialize Timer-0 peripheral with specific configurations.
 * [Arguments]     : <a_ptr2configurations>      -> Pointer to structure holds the configurations.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Prescaler Error.
 *                                                          - Null Pointer Error.
 *                                                          - Operation Mode Error.
 *                                                          - Compare Output Mode Error.
 ====================================================================================================================*/
TIMER0_errorStatus TIMER0_init(TIMER0_configurations* a_ptr2configurations)
{
    TIMER0_errorStatus LOC_errorStatus = TIMER0_NO_ERRORS;

    if(a_ptr2configurations == NULL_PTR)
    {
        LOC_errorStatus = TIMER0_NULL_PTR_ERROR;
    }

    else if((a_ptr2configurations->timer_mode != TIMER0_OVERFLOW_MODE) && \
            (a_ptr2configurations->timer_mode != TIMER0_COMPARE_MATCH_MODE) &&
            (a_ptr2configurations->timer_mode != TIMER0_PHASE_CORRECT_PWM_MODE) && \
            (a_ptr2configurations->timer_mode != TIMER0_FAST_PWM_MODE))
    {
        LOC_errorStatus = TIMER0_OPERATION_MODE_ERROR;
    }

    else if(a_ptr2configurations->prescaler_id > TIMER0_PRESCALER_1024)
    {
        LOC_errorStatus = TIMER0_PRESCALER_ERROR;
    }

    else if(a_ptr2configurations->compare_output_mode > TIMER0_PHASE_CORRECT_PWM_SET_OC0)
    {
        LOC_errorStatus = TIMER0_COMPARE_OUTPUT_MODE_ERROR;
    }

    else
    {
        uint16 LOC_prescalerValue = TIMER0_getPrescalerValue(a_ptr2configurations->prescaler_id);
        TIMER0_ticksCalculator(a_ptr2configurations->time_in_millis,LOC_prescalerValue,a_ptr2configurations->timer_mode);

        TIMER0_SET_PWM_STATE(a_ptr2configurations->timer_mode);
        TIMER0_SET_OPERATION_MODE(a_ptr2configurations->timer_mode);
        TIMER0_SET_COMPARE_OUTPUT_MODE(a_ptr2configurations->compare_output_mode);

        switch (a_ptr2configurations->timer_mode)
        {
        case TIMER0_OVERFLOW_MODE:
            TCNT0 = (g_number_of_cycles == 0) ? g_preload_value : 0;
            TIMER0_ENABLE_OVERFLOW_INTERRUPT();
            break;
        
        case TIMER0_COMPARE_MATCH_MODE:
            OCR0 = (g_number_of_cycles == 0) ? g_compare_value : (TIMER0_OVERFLOW_VALUE - 1);
            TIMER0_ENABLE_COMPARE_MATCH_INTERRUPT();
            break;
        
        default:
            /* Do Nothing.  */
            break;
        }

        TIMER0_SET_PRESCALER_VALUE(a_ptr2configurations->prescaler_id);
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : TIMER0_getPrescalerValue
 * [Description]   : Get the value of the Timer-0 prescaler based on its ID.
 * [Arguments]     : <a_prescalerID>      -> Indicates to the prescaler ID.
 * [return]        : The function returns the prescaler value.
 ====================================================================================================================*/
static uint16 TIMER0_getPrescalerValue(TIMER0_prescalerID a_prescalerID)
{
    uint16 LOC_prescalerValue = 0;

	switch (a_prescalerID)
    {
    case TIMER0_PRESCALER_1:
        LOC_prescalerValue = 1;
        break;
    
    case TIMER0_PRESCALER_8:
        LOC_prescalerValue = 8;
        break;
    
    case TIMER0_PRESCALER_64:
        LOC_prescalerValue = 64;
        break;
    
    case TIMER0_PRESCALER_256:
        LOC_prescalerValue = 256;
        break;
    
    case TIMER0_PRESCALER_1024:
        LOC_prescalerValue = 1024;
        break;
    
    default:
        LOC_prescalerValue = 1;
        break;
    }

    return LOC_prescalerValue;
}

/*=====================================================================================================================
 * [Function Name] : TIMER0_ticksCalculator
 * [Description]   : Calculate the number of timer ticks needed to reach the desired time period.
 * [Arguments]     : <a_time>           -> Indicates to the desired time period in milli seconds.
 *                   <a_prescalerValue> -> Indicates to the prescaler value.
 *                   <a_timerMode>      -> Indicates to the timer operation mode.
 * [return]        : The function returns void.
 ====================================================================================================================*/
static void TIMER0_ticksCalculator(uint32 a_time, uint16 a_prescalerValue, TIMER0_operationMode a_timerMode)
{
    uint32 LOC_timerFrequency = (F_CPU / a_prescalerValue);
    uint64 LOC_numOfTicks = ((LOC_timerFrequency * (uint64)a_time) / 1000);
    g_number_of_cycles = (LOC_numOfTicks / TIMER0_OVERFLOW_VALUE);

    switch (a_timerMode)
    {
    case TIMER0_OVERFLOW_MODE:
        g_preload_value = (TIMER0_OVERFLOW_VALUE - (LOC_numOfTicks % TIMER0_OVERFLOW_VALUE));
        break;
    
    case TIMER0_COMPARE_MATCH_MODE:
        g_compare_value = (TIMER0_OVERFLOW_VALUE - (LOC_numOfTicks % TIMER0_OVERFLOW_VALUE));
        break;
    
    default:
        /* Do Nothing. */
        break;
    }
}

/*=====================================================================================================================
 * [Function Name] : TIMER0_setCallBackFunction
 * [Description]   : Set the call-back function address of a specific Timer-0 operation mode.
 * [Arguments]     : <a_timerMode>             -> Indicates to the timer operation mode.
 *                   <a_ptr2callBackFunction>  -> Pointer to the call-back function.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 *                                                          - Operation Mode Error.
 ====================================================================================================================*/
TIMER0_errorStatus TIMER0_setCallBackFunction(TIMER0_operationMode a_timerMode, void (*a_ptr2callBackFunction)(void))
{
    TIMER0_errorStatus LOC_errorStatus = TIMER0_NO_ERRORS;

    if(a_ptr2callBackFunction == NULL_PTR)
    {
        LOC_errorStatus = TIMER0_NULL_PTR_ERROR;
    }

    else
    {
        switch (a_timerMode)
        {
        case TIMER0_OVERFLOW_MODE:
            *(g_callBackFunctionsArray + TIMER0_OVF_INTERRUPT_ID) = a_ptr2callBackFunction;
            break;
        
        case TIMER0_COMPARE_MATCH_MODE:
            *(g_callBackFunctionsArray + TIMER0_CTC_INTERRUPT_ID) = a_ptr2callBackFunction;
            break;
        
        default:
            LOC_errorStatus = TIMER0_OPERATION_MODE_ERROR;
            break;
        }
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : CTC_ISR
 * [Description]   : Interrupt Service Routine of the Compare Match mode in Timer-0.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
    if(*(g_callBackFunctionsArray + TIMER0_CTC_INTERRUPT_ID) != NULL_PTR)
    {
        static uint64 LOC_cyclesCounter = 0;

        if((g_number_of_cycles != 0) && (LOC_cyclesCounter != g_number_of_cycles))
        {
            LOC_cyclesCounter++;

            if(LOC_cyclesCounter == g_number_of_cycles)
            {
            	OCR0 = g_compare_value;
            }
        }

        else
        {
            LOC_cyclesCounter = 0;
            (*(g_callBackFunctionsArray + TIMER0_CTC_INTERRUPT_ID))();
            OCR0 = (g_number_of_cycles == 0) ? g_compare_value : (TIMER0_OVERFLOW_VALUE - 1);
        }
    }

    else
    {
    	/* Do Nothing. */
    }
}

/*=====================================================================================================================
 * [Function Name] : OVF_ISR
 * [Description]   : Interrupt Service Routine of the Overflow mode in Timer-0.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
    if(*(g_callBackFunctionsArray + TIMER0_OVF_INTERRUPT_ID) != NULL_PTR)
    {
        static uint64 LOC_cyclesCounter = 0;

        if((g_number_of_cycles != 0) && (LOC_cyclesCounter != g_number_of_cycles))
        {
            LOC_cyclesCounter++;

            if(LOC_cyclesCounter == g_number_of_cycles)
            {
                TCNT0 = g_preload_value;
            }
        }

        else
        {
            LOC_cyclesCounter = 0;
            (*(g_callBackFunctionsArray + TIMER0_OVF_INTERRUPT_ID))();
            TCNT0 = (g_number_of_cycles == 0) ? g_preload_value : 0;
        }
    }

    else
    {
    	/* Do Nothing. */
    }
}
