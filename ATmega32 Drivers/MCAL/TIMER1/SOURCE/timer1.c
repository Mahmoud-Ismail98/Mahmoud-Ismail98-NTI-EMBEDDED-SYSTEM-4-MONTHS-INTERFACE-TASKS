/*
=======================================================================================================================
Author       : Mamoun
Module       : Timer-1
File Name    : timer1.c
Date Created : Oct 27, 2023
Description  : Source file for the ATmega32 Timer-1 driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../OTHERS/std_types.h"
#include "../../../OTHERS/common_macros.h"
#include "../INCLUDES/timer1_prv.h"
#include "../INCLUDES/timer1_cfg.h"
#include "../INCLUDES/timer1.h"
#include <avr/io.h>

/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/

static volatile void (*g_callBackFunctionsArray[TIMER1_NUM_OF_INTERRUPT_MODES])(void) = {NULL_PTR,NULL_PTR};

static uint64 g_number_of_cycles = 0;
static uint16 g_preload_value = 0;
static uint16 g_compare_value = 0;

/*=====================================================================================================================
                                      < Private Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : TIMER1_getPrescalerValue
 * [Description]   : Get the value of the Timer-1 prescaler based on its ID.
 * [Arguments]     : <a_prescalerID>      -> Indicates to the prescaler ID.
 * [return]        : The function returns the prescaler value.
 ====================================================================================================================*/
static uint16 TIMER1_getPrescalerValue(TIMER1_prescalerID a_prescalerID);

/*=====================================================================================================================
 * [Function Name] : TIMER1_ticksCalculator
 * [Description]   : Calculate the number of timer ticks needed to reach the desired time period.
 * [Arguments]     : <a_time>           -> Indicates to the desired time period in milli seconds.
 *                   <a_prescalerValue> -> Indicates to the prescaler value.
 *                   <a_timerMode>      -> Indicates to the timer operation mode.
 * [return]        : The function returns void.
 ====================================================================================================================*/
static void TIMER1_ticksCalculator(uint32 a_time, uint16 a_prescalerValue, TIMER1_operationMode a_timerMode);

/*=====================================================================================================================
                                          < Functions Definitions >
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
TIMER1_errorStatus TIMER1_init(TIMER1_configurations* a_ptr2configurations)
{
    TIMER1_errorStatus LOC_errorStatus = TIMER1_NO_ERRORS;

    if(a_ptr2configurations == NULL_PTR)
    {
        LOC_errorStatus = TIMER1_NULL_PTR_ERROR;
    }

    else if((a_ptr2configurations->timer_mode != TIMER1_OVERFLOW_MODE) && \
            (a_ptr2configurations->timer_mode != TIMER1_COMPARE_MATCH_MODE) &&
            (a_ptr2configurations->timer_mode != TIMER1_PHASE_CORRECT_PWM_MODE) && \
            (a_ptr2configurations->timer_mode != TIMER1_FAST_PWM_MODE))
    {
        LOC_errorStatus = TIMER1_OPERATION_MODE_ERROR;
    }

    else if(a_ptr2configurations->prescaler_id > TIMER1_PRESCALER_1024)
    {
        LOC_errorStatus = TIMER1_PRESCALER_ERROR;
    }

    else if((a_ptr2configurations->channel_a_output_mode > TIMER1_PHASE_CORRECT_PWM_SET_OC1) || \
            (a_ptr2configurations->channel_b_output_mode > TIMER1_PHASE_CORRECT_PWM_SET_OC1))
    {
        LOC_errorStatus = TIMER1_COMPARE_OUTPUT_MODE_ERROR;
    }

    else
    {
        uint16 LOC_prescalerValue = TIMER1_getPrescalerValue(a_ptr2configurations->prescaler_id);
        TIMER1_ticksCalculator(a_ptr2configurations->time_in_millis,LOC_prescalerValue,a_ptr2configurations->timer_mode);

        TIMER1_SET_CHANNEL_A_PWM_STATE(a_ptr2configurations->timer_mode);
        TIMER1_SET_CHANNEL_B_PWM_STATE(a_ptr2configurations->timer_mode);
        TIMER1_SET_CHANNEL_A_OUTPUT_MODE(a_ptr2configurations->channel_a_output_mode);
        TIMER1_SET_CHANNEL_B_OUTPUT_MODE(a_ptr2configurations->channel_b_output_mode);
        TIMER1_SET_OPERATION_MODE_LOW_BITS(a_ptr2configurations->timer_mode);
        TIMER1_SET_OPERATION_MODE_HIGH_BITS(a_ptr2configurations->timer_mode);

        switch (a_ptr2configurations->timer_mode)
        {
        case TIMER1_OVERFLOW_MODE:
            TCNT1 = (g_number_of_cycles == 0) ? g_preload_value : 0;
            TIMER0_ENABLE_OVERFLOW_INTERRUPT();
            break;
        
        case TIMER1_COMPARE_MATCH_MODE:
        	OCR1A = (g_number_of_cycles == 0) ? g_compare_value : (TIMER1_OVERFLOW_VALUE - 1);
        	TIMER0_ENABLE_COMPARE_MATCH_A_INTERRUPT();
            break;
        
        default:
            /* Do Nothing.  */
            break;
        }

        TIMER1_SET_PRESCALER_VALUE(a_ptr2configurations->prescaler_id);
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : TIMER1_getPrescalerValue
 * [Description]   : Get the value of the Timer-1 prescaler based on its ID.
 * [Arguments]     : <a_prescalerID>      -> Indicates to the prescaler ID.
 * [return]        : The function returns the prescaler value.
 ====================================================================================================================*/
static uint16 TIMER1_getPrescalerValue(TIMER1_prescalerID a_prescalerID)
{
    uint16 LOC_prescalerValue = 0;

	switch (a_prescalerID)
    {
    case TIMER1_PRESCALER_1:
        LOC_prescalerValue = 1;
        break;
    
    case TIMER1_PRESCALER_8:
        LOC_prescalerValue = 8;
        break;
    
    case TIMER1_PRESCALER_64:
        LOC_prescalerValue = 64;
        break;
    
    case TIMER1_PRESCALER_256:
        LOC_prescalerValue = 256;
        break;
    
    case TIMER1_PRESCALER_1024:
        LOC_prescalerValue = 1024;
        break;
    
    default:
        LOC_prescalerValue = 1;
        break;
    }

    return LOC_prescalerValue;
}

/*=====================================================================================================================
 * [Function Name] : TIMER1_ticksCalculator
 * [Description]   : Calculate the number of timer ticks needed to reach the desired time period.
 * [Arguments]     : <a_time>           -> Indicates to the desired time period in milli seconds.
 *                   <a_prescalerValue> -> Indicates to the prescaler value.
 *                   <a_timerMode>      -> Indicates to the timer operation mode.
 * [return]        : The function returns void.
 ====================================================================================================================*/
static void TIMER1_ticksCalculator(uint32 a_time, uint16 a_prescalerValue, TIMER1_operationMode a_timerMode)
{
    uint32 LOC_timerFrequency = (F_CPU / a_prescalerValue);
    uint64 LOC_numOfTicks = ((LOC_timerFrequency * (uint64)a_time) / 1000);
    g_number_of_cycles = (LOC_numOfTicks / TIMER1_OVERFLOW_VALUE);

    switch (a_timerMode)
    {
    case TIMER1_OVERFLOW_MODE:
        g_preload_value = (TIMER1_OVERFLOW_VALUE - (LOC_numOfTicks % TIMER1_OVERFLOW_VALUE));
        break;
    
    case TIMER1_COMPARE_MATCH_MODE:
        g_compare_value = (TIMER1_OVERFLOW_VALUE - (LOC_numOfTicks % TIMER1_OVERFLOW_VALUE));
        break;
    
    default:
        /* Do Nothing. */
        break;
    }
}

/*=====================================================================================================================
 * [Function Name] : TIMER1_setCallBackFunction
 * [Description]   : Set the call-back function address of a specific Timer-1 operation mode.
 * [Arguments]     : <a_timerMode>             -> Indicates to the timer operation mode.
 *                   <a_ptr2callBackFunction>  -> Pointer to the call-back function.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 *                                                          - Operation Mode Error.
 ====================================================================================================================*/
TIMER1_errorStatus TIMER1_setCallBackFunction(TIMER1_operationMode a_timerMode, void (*a_ptr2callBackFunction)(void))
{
    TIMER1_errorStatus LOC_errorStatus = TIMER1_NO_ERRORS;

    if(a_ptr2callBackFunction == NULL_PTR)
    {
        LOC_errorStatus = TIMER1_NULL_PTR_ERROR;
    }

    else
    {
        switch (a_timerMode)
        {
        case TIMER1_OVERFLOW_MODE:
            *(g_callBackFunctionsArray + TIMER1_OVF_INTERRUPT_ID) = a_ptr2callBackFunction;
            break;
        
        case TIMER1_COMPARE_MATCH_MODE:
            *(g_callBackFunctionsArray + TIMER1_CTC_INTERRUPT_ID) = a_ptr2callBackFunction;
            break;
        
        default:
            LOC_errorStatus = TIMER1_OPERATION_MODE_ERROR;
            break;
        }
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : CTC_ISR
 * [Description]   : Interrupt Service Routine of the Compare Match mode in Timer-1.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
    if(*(g_callBackFunctionsArray + TIMER1_CTC_INTERRUPT_ID) != NULL_PTR)
    {
        static uint64 LOC_cyclesCounter = 0;

        if((g_number_of_cycles != 0) && (LOC_cyclesCounter != g_number_of_cycles))
        {
            LOC_cyclesCounter++;

            if(LOC_cyclesCounter == g_number_of_cycles)
            {
            	OCR1A = g_compare_value;
            }
        }

        else
        {
            LOC_cyclesCounter = 0;
            (*(g_callBackFunctionsArray + TIMER1_CTC_INTERRUPT_ID))();
            OCR1A = (g_number_of_cycles == 0) ? g_compare_value : (TIMER1_OVERFLOW_VALUE - 1);
        }
    }

    else
    {
    	/* Do Nothing. */
    }
}

/*=====================================================================================================================
 * [Function Name] : OVF_ISR
 * [Description]   : Interrupt Service Routine of the Overflow mode in Timer-1.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
    if(*(g_callBackFunctionsArray + TIMER1_OVF_INTERRUPT_ID) != NULL_PTR)
    {
        static uint64 LOC_cyclesCounter = 0;

        if((g_number_of_cycles != 0) && (LOC_cyclesCounter != g_number_of_cycles))
        {
            LOC_cyclesCounter++;

            if(LOC_cyclesCounter == g_number_of_cycles)
            {
                TCNT1 = g_preload_value;
            }
        }

        else
        {
            LOC_cyclesCounter = 0;
            (*(g_callBackFunctionsArray + TIMER1_OVF_INTERRUPT_ID))();
            TCNT1 = (g_number_of_cycles == 0) ? g_preload_value : 0;
        }
    }

    else
    {
    	/* Do Nothing. */
    }
}
