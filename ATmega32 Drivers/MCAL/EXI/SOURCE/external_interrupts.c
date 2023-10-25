/*
=======================================================================================================================
Author       : Mamoun
Module       : External Interrupt
File Name    : external_interrupts.c
Date Created : Oct 22, 2023
Description  : Source file for the ATmega32 External Interrupt driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../OTHERS/std_types.h"
#include "../../../OTHERS/common_macros.h"
#include "../INCLUDES/external_interrupts_prv.h"
#include "../INCLUDES/external_interrupts_cfg.h"
#include "../INCLUDES/external_interrupts.h"
#include <avr/io.h>

/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/

static volatile void (*g_callBackFunctionsArray[EXI_NUM_OF_CALLBACK_FUNCTIONS])(void) = {NULL_PTR,NULL_PTR,NULL_PTR};

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : EXI_init
 * [Description]   : Initialize the External Interrupt with specific static configurations.
 * [Arguments]     : The function Takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void EXI_init(void)
{
    #if(EXI_INT0_STATUS == EXI_INT_ENABLE)

    EXI_setTriggerMode(EXI_INT0_ID,EXI_INT0_TRIGGER_MODE);
    EXI_enableInterrupt(EXI_INT0_ID);

    #endif

    #if(EXI_INT1_STATUS == EXI_INT_ENABLE)

    EXI_setTriggerMode(EXI_INT1_ID,EXI_INT1_TRIGGER_MODE);
    EXI_enableInterrupt(EXI_INT1_ID);

    #endif

    #if(EXI_INT2_STATUS == EXI_INT_ENABLE)

    EXI_setTriggerMode(EXI_INT2_ID,EXI_INT2_TRIGGER_MODE);
    EXI_enableInterrupt(EXI_INT2_ID);

    #endif
}

/*=====================================================================================================================
 * [Function Name] : EXI_enableInterrupt
 * [Description]   : Enable a specific External Interrupt [INT0 - INT1 - INT2].
 * [Arguments]     : <a_index>      -> Indicates to the required External Interrupt.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Index Number Error.
 ====================================================================================================================*/
EXI_errorStatus EXI_enableInterrupt(EXI_interruptIndex a_index)
{
    EXI_errorStatus LOC_errorStatus = EXI_NO_ERRORS;

    if((a_index != EXI_INT0_ID) && (a_index != EXI_INT1_ID) && (a_index != EXI_INT2_ID))
    {
        LOC_errorStatus = EXI_INDEX_ERROR;
    }

    else
    {

        switch (a_index)
        {
        case EXI_INT0_ID:
            SET_BIT(GICR,6);
            break;
        
        case EXI_INT1_ID:
            SET_BIT(GICR,7);
            break;
        
        case EXI_INT2_ID:
            SET_BIT(GICR,5);
            break;
        
        default:
            /* Do Nothing. */
            break;
        }
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : EXI_disableInterrupt
 * [Description]   : Disable a specific External Interrupt [INT0 - INT1 - INT2].
 * [Arguments]     : <a_index>      -> Indicates to the required External Interrupt.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Index Number Error.
 ====================================================================================================================*/
EXI_errorStatus EXI_disableInterrupt(EXI_interruptIndex a_index)
{
    EXI_errorStatus LOC_errorStatus = EXI_NO_ERRORS;

    if((a_index != EXI_INT0_ID) && (a_index != EXI_INT1_ID) && (a_index != EXI_INT2_ID))
    {
        LOC_errorStatus = EXI_INDEX_ERROR;
    }

    else
    {

        switch (a_index)
        {
        case EXI_INT0_ID:
            CLEAR_BIT(GICR,6);
            break;
        
        case EXI_INT1_ID:
            CLEAR_BIT(GICR,7);
            break;
        
        case EXI_INT2_ID:
            CLEAR_BIT(GICR,5);
            break;
        
        default:
            /* Do Nothing. */
            break;
        }
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : EXI_setTriggerMode
 * [Description]   : Set the trigger mode for a specific External Interrupt.
 * [Arguments]     : <a_index>          -> Indicates to the required External Interrupt.
 *                   <a_triggerMode>    -> Indicates to the required mode.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Index Number Error.
 *                                                          - Invalid Trigger Mode Error.
 ====================================================================================================================*/
EXI_errorStatus EXI_setTriggerMode(EXI_interruptIndex a_index, EXI_triggerMode a_triggerMode)
{
    EXI_errorStatus LOC_errorStatus = EXI_NO_ERRORS;

    if((a_index != EXI_INT0_ID) && (a_index != EXI_INT1_ID) && (a_index != EXI_INT2_ID))
    {
        LOC_errorStatus = EXI_INDEX_ERROR;
    }

    else if((a_triggerMode != EXI_LOW_LEVEL) && (a_triggerMode != EXI_ANY_LOGICAL_CHANGE) && (a_triggerMode != EXI_FALLING_EDGE) && (a_triggerMode != EXI_RISING_EDGE))
    {
        LOC_errorStatus = EXI_TRIGGER_MODE_ERROR;
    }

    else if((a_index == EXI_INT2_ID) && ((a_triggerMode == EXI_LOW_LEVEL) || (a_triggerMode == EXI_ANY_LOGICAL_CHANGE)))
    {
        LOC_errorStatus = EXI_TRIGGER_MODE_ERROR;
    }

    else
    {
        switch (a_index)
        {
        case EXI_INT0_ID:
            MCUCR = ((MCUCR & 0XFC) | (a_triggerMode));
            break;
        
        case EXI_INT1_ID:
            MCUCR = ((MCUCR & 0XF3) | (a_triggerMode << 2));
            break;
        
        case EXI_INT2_ID:
            MCUCSR = ((MCUCSR & 0XBF) | ((a_triggerMode & 0X01) << 6));
            break;
        
        default:
            /* Do Nothing. */
            break;
        }
    }
    
    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : EXI_setCallBackFunction
 * [Description]   : Set the address of the call-back function for a specific External Interrupt.
 * [Arguments]     : <a_index>                 -> Indicates to the required External Interrupt.
 *                   <a_ptr2callBackFunction>  -> Pointer to the call-back function.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
EXI_errorStatus EXI_setCallBackFunction(EXI_interruptIndex a_index, void (*a_ptr2callBackFunction)(void))
{
    EXI_errorStatus LOC_errorStatus = EXI_NO_ERRORS;

    if(a_ptr2callBackFunction == NULL_PTR)
    {
        LOC_errorStatus = EXI_CALLBACK_NULL_PTR_ERROR;
    }
    
    else
    {
        *(g_callBackFunctionsArray + a_index) = a_ptr2callBackFunction;
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : INT0_ISR
 * [Description]   : The interrupt service routine for the INT0.
 * [Arguments]     : The function Takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    (*(g_callBackFunctionsArray + EXI_INT0_ID))();
}

/*=====================================================================================================================
 * [Function Name] : INT1_ISR
 * [Description]   : The interrupt service routine for the INT1.
 * [Arguments]     : The function Takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
    (*(g_callBackFunctionsArray + EXI_INT1_ID))();
}

/*=====================================================================================================================
 * [Function Name] : INT2_ISR
 * [Description]   : The interrupt service routine for the INT2.
 * [Arguments]     : The function Takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
    (*(g_callBackFunctionsArray + EXI_INT2_ID))();
}
