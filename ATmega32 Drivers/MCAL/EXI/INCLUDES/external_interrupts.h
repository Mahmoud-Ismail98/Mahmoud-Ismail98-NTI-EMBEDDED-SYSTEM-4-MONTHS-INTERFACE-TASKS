/*
=======================================================================================================================
Author       : Mamoun
Module       : External Interrupt
File Name    : external_interrupts.h
Date Created : Oct 22, 2023
Description  : Header file for the ATmega32 External Interrupt driver.
=======================================================================================================================
*/


#ifndef MCAL_EXI_INCLUDES_EXTERNAL_INTERRUPTS_H_
#define MCAL_EXI_INCLUDES_EXTERNAL_INTERRUPTS_H_

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    EXI_LOW_LEVEL,
    EXI_ANY_LOGICAL_CHANGE,
    EXI_FALLING_EDGE,
    EXI_RISING_EDGE
}EXI_triggerMode;

typedef enum
{
    EXI_INT0_ID,
    EXI_INT1_ID,
    EXI_INT2_ID
}EXI_interruptIndex;

typedef enum
{
    EXI_NO_ERRORS,
    EXI_INDEX_ERROR,
    EXI_TRIGGER_MODE_ERROR,
    EXI_CALLBACK_NULL_PTR_ERROR
}EXI_errorStatus;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : EXI_init
 * [Description]   : Initialize the External Interrupt with specific static configurations.
 * [Arguments]     : The function Takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void EXI_init(void);

/*=====================================================================================================================
 * [Function Name] : EXI_enableInterrupt
 * [Description]   : Enable a specific External Interrupt [INT0 - INT1 - INT2].
 * [Arguments]     : <a_index>      -> Indicates to the required External Interrupt.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Index Number Error.
 ====================================================================================================================*/
EXI_errorStatus EXI_enableInterrupt(EXI_interruptIndex a_index);

/*=====================================================================================================================
 * [Function Name] : EXI_disableInterrupt
 * [Description]   : Disable a specific External Interrupt [INT0 - INT1 - INT2].
 * [Arguments]     : <a_index>      -> Indicates to the required External Interrupt.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Index Number Error.
 ====================================================================================================================*/
EXI_errorStatus EXI_disableInterrupt(EXI_interruptIndex a_index);

/*=====================================================================================================================
 * [Function Name] : EXI_setTriggerMode
 * [Description]   : Set the trigger mode for a specific External Interrupt.
 * [Arguments]     : <a_index>          -> Indicates to the required External Interrupt.
 *                   <a_triggerMode>    -> Indicates to the required mode.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Index Number Error.
 *                                                          - Invalid Trigger Mode Error.
 ====================================================================================================================*/
EXI_errorStatus EXI_setTriggerMode(EXI_interruptIndex a_index, EXI_triggerMode a_triggerMode);

/*=====================================================================================================================
 * [Function Name] : EXI_setCallBackFunction
 * [Description]   : Set the address of the call-back function for a specific External Interrupt.
 * [Arguments]     : <a_index>                 -> Indicates to the required External Interrupt.
 *                   <a_ptr2callBackFunction>  -> Pointer to the call-back function.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
EXI_errorStatus EXI_setCallBackFunction(EXI_interruptIndex a_index, void (*a_ptr2callBackFunction)(void));

#endif /* MCAL_EXI_INCLUDES_EXTERNAL_INTERRUPTS_H_ */
