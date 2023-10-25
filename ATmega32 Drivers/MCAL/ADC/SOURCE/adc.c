/*
=======================================================================================================================
Author       : Mamoun
Module       : ADC
File Name    : adc.c
Date Created : Oct 23, 2023
Description  : Source file for the ATmega32 ADC driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../OTHERS/std_types.h"
#include "../../../OTHERS/common_macros.h"
#include "../INCLUDES/adc_prv.h"
#include "../INCLUDES/adc_cfg.h"
#include "../INCLUDES/adc.h"
#include <avr/io.h>

/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/

#if(ADC_API_INTERFACE_MODE == ADC_USING_INTERRUPT)
/* Pointer to the call-back function that will be called in interrupt mode. */
static volatile void (*g_ptr2callBackFunction)(uint16) = NULL_PTR;
#endif

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : ADC_init
 * [Description]   : Initialize the ADC with specific configurations.
 * [Arguments]     : <a_ptr2configurations>   -> Pointer to a structure holds the configurations.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Prescaler Error.
 *                                                          - Null Pointer Error.
 *                                                          - Voltage Reference Error.
 ====================================================================================================================*/
ADC_errorStatus ADC_init(ADC_configurations* a_ptr2configurations)
{
    ADC_errorStatus LOC_errorStatus = ADC_NO_ERRORS;

    if(a_ptr2configurations == NULL_PTR)
    {
        LOC_errorStatus = ADC_NULL_PTR_ERROR;
    }

    else if(a_ptr2configurations->prescaler > ADC_DIVISION_FACTOR_128)
    {
        LOC_errorStatus = ADC_PRESCALER_ERROR;
    }

    else if((a_ptr2configurations->voltage_reference != ADC_REF_AREF) && (a_ptr2configurations->voltage_reference != ADC_REF_AVCC) && (a_ptr2configurations->voltage_reference != ADC_REF_INTERNAL))
    {
        LOC_errorStatus = ADC_VOLTAGE_REF_ERROR;
    }

    else
    {
        ADC_SET_VOLTAGE_REF(a_ptr2configurations->voltage_reference);   /* Set the ADC voltage reference. */
        ADC_SET_PRESCALER(a_ptr2configurations->prescaler);                     /* Set the ADC prescaler. */

        #if(ADC_API_INTERFACE_MODE == ADC_USING_INTERRUPT)
        SET_BIT(ADCSRA,ADIE);                        /* Incase using ADC interrupt, enable the interrupt. */
        #endif

        SET_BIT(ADCSRA,ADEN);                                               /* Enable the ADC peripheral. */
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : ADC_enable
 * [Description]   : Enable the ADC peripheral.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void ADC_enable(void)
{
    SET_BIT(ADCSRA,ADEN);                                                   /* Enable the ADC peripheral. */
}

/*=====================================================================================================================
 * [Function Name] : ADC_disable
 * [Description]   : Disable the ADC peripheral.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void ADC_disable(void)
{
    CLEAR_BIT(ADCSRA,ADEN);                                                /* Disable the ADC peripheral. */
}

#if(ADC_API_INTERFACE_MODE == ADC_USING_POLLING)
/*=====================================================================================================================
 * [Function Name] : ADC_readChannelSync
 * [Description]   : Read the analog value of a specific channel and convert it to corresponding digital
 *                   value using the ADC peripheral then return the digital value.
 * [Arguments]     : <a_channelID>      -> Indicates to the required channel.
 *                   <a_ptr2value>      -> Pointer to variable to store the digital value.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Channel ID Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
ADC_errorStatus ADC_readChannelSync(ADC_channelID a_channelID, uint16* a_ptr2value)
{
    ADC_errorStatus LOC_errorStatus = ADC_NO_ERRORS;

    if((a_channelID > ADC_CHANNEL_7) && (a_channelID < ADC_CHANNEL_0))
    {
        LOC_errorStatus = ADC_CHANNEL_NUM_ERROR;
    }

    else if(a_ptr2value == NULL_PTR)
    {
        LOC_errorStatus = ADC_NULL_PTR_ERROR;
    }

    else
    {
        ADC_SET_CHANNEL(a_channelID);     /* Choose the required channel to read and convert its value. */
        SET_BIT(ADCSRA,ADSC);                                              /* Start the ADC conversion. */
        while(BIT_IS_CLEAR(ADCSRA,ADIF));                            /* Polling on the conversion flag. */
        SET_BIT(ADCSRA,ADIF);                                             /* Clear the conversion flag. */
        *a_ptr2value = (ADC & 0X03FF);                                    /* Store the converted value. */
    }
    
    return LOC_errorStatus;
}
#endif

#if(ADC_API_INTERFACE_MODE == ADC_USING_INTERRUPT)
/*=====================================================================================================================
 * [Function Name] : ADC_readChannelAsync
 * [Description]   : Select the required channel that you need to read.
 *                   Then, return and the result will be catched using the call-back function.
 * [Arguments]     : <a_channelID>      -> Indicates to the required channel.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Channel ID Error.
 ====================================================================================================================*/
ADC_errorStatus ADC_readChannelAsync(ADC_channelID a_channelID)
{
    ADC_errorStatus LOC_errorStatus = ADC_NO_ERRORS;

    if((a_channelID > ADC_CHANNEL_7) && (a_channelID < ADC_CHANNEL_0))
    {
        LOC_errorStatus = ADC_CHANNEL_NUM_ERROR;
    }

    else
    {
        ADC_SET_CHANNEL(a_channelID);     /* Choose the required channel to read and convert its value. */
        SET_BIT(ADCSRA,ADSC);                                              /* Start the ADC conversion. */
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : ADC_setCallBackFunction
 * [Description]   : Set the address of the call-back function.
 * [Arguments]     : <a_ptr2CallBackFunction>      -> Pointer to the call-back function.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
ADC_errorStatus ADC_setCallBackFunction(void (*a_ptr2CallBackFunction)(uint16))
{
    ADC_errorStatus LOC_errorStatus = ADC_NO_ERRORS;

    if(a_ptr2CallBackFunction == NULL_PTR)
    {
        LOC_errorStatus = ADC_NULL_PTR_ERROR;
    }

    else
    {
        /* Store the call-back function address to be called when conversion finished. */
        g_ptr2callBackFunction = a_ptr2CallBackFunction;
    }
}

/*=====================================================================================================================
 * [Function Name] : ADC_ISR
 * [Description]   : Interrupt Service Routine of the ADC.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
    /* Call the call-back function. */
    g_ptr2callBackFunction(ADC);
}
#endif
