/*
=======================================================================================================================
Author       : Mamoun
Module       : ADC
File Name    : adc.h
Date Created : Oct 23, 2023
Description  : Header file for the ATmega32 ADC driver.
=======================================================================================================================
*/


#ifndef MCAL_ADC_INCLUDES_ADC_H_
#define MCAL_ADC_INCLUDES_ADC_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

#if((ADC_API_INTERFACE_MODE != ADC_USING_POLLING) && (ADC_API_INTERFACE_MODE!= ADC_USING_INTERRUPT))
#error "Invalid ADC API interface mode, You can only interface using [polling or interrupt]"
#endif

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    ADC_NO_ERRORS,
    ADC_NULL_PTR_ERROR,
    ADC_PRESCALER_ERROR,
    ADC_VOLTAGE_REF_ERROR,
    ADC_CHANNEL_NUM_ERROR
}ADC_errorStatus;

typedef enum
{
    ADC_CHANNEL_0,
    ADC_CHANNEL_1,
    ADC_CHANNEL_2,
    ADC_CHANNEL_3,
    ADC_CHANNEL_4,
    ADC_CHANNEL_5,
    ADC_CHANNEL_6,
    ADC_CHANNEL_7,
}ADC_channelID;

typedef enum
{
    ADC_DIVISION_FACTOR_1,
    ADC_DIVISION_FACTOR_2,
    ADC_DIVISION_FACTOR_4,
    ADC_DIVISION_FACTOR_8,
    ADC_DIVISION_FACTOR_16,
    ADC_DIVISION_FACTOR_32,
    ADC_DIVISION_FACTOR_64,
    ADC_DIVISION_FACTOR_128
}ADC_prescaler;

typedef enum
{
    ADC_REF_AREF,
    ADC_REF_AVCC,
    ADC_REF_INTERNAL = 0x03
}ADC_voltageReference;

typedef struct
{
    ADC_prescaler prescaler;
    ADC_voltageReference voltage_reference;
}ADC_configurations;

/*=====================================================================================================================
                                         < Functions Prototypes >
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
ADC_errorStatus ADC_init(ADC_configurations* a_ptr2configurations);

/*=====================================================================================================================
 * [Function Name] : ADC_enable
 * [Description]   : Enable the ADC peripheral.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void ADC_enable(void);

/*=====================================================================================================================
 * [Function Name] : ADC_disable
 * [Description]   : Disable the ADC peripheral.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void ADC_disable(void);

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
ADC_errorStatus ADC_readChannelSync(ADC_channelID a_channelID, uint16* a_ptr2value);
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
ADC_errorStatus ADC_readChannelAsync(ADC_channelID a_channelID);

/*=====================================================================================================================
 * [Function Name] : ADC_setCallBackFunction
 * [Description]   : Set the address of the call-back function.
 * [Arguments]     : <a_ptr2CallBackFunction>      -> Pointer to the call-back function.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
ADC_errorStatus ADC_setCallBackFunction(void (*a_ptr2CallBackFunction)(uint16));
#endif

#endif /* MCAL_ADC_INCLUDES_ADC_H_ */
