/*
=======================================================================================================================
Author       : Mamoun
Module       : GPIO
File Name    : gpio.h
Date Created : Nov 6, 2023
Description  : Header file for the STM32F401 GPIO peripheral driver.
=======================================================================================================================
*/


#ifndef MCAL_GPIO_INCLUDES_GPIO_H_
#define MCAL_GPIO_INCLUDES_GPIO_H_

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    GPIO_NO_ERRORS,
    GPIO_PIN_STATUS_ERROR,
    GPIO_NULL_PTR_ERROR,
    GPIO_PORT_ID_ERROR,
    GPIO_PIN_ID_ERROR,
    GPIO_SPEED_ERROR,
    GPIO_MODE_ERROR,
    GPIO_ALTERNATE_FUNCTION_ERROR,
}GPIO_errorStatus;

typedef enum
{
    GPIO_PORTA_ID,
    GPIO_PORTB_ID,
    GPIO_PORTC_ID,
    GPIO_PORTD_ID,
    GPIO_PORTE_ID,
    GPIO_PORTH_ID
}GPIO_portID;

typedef enum
{
    GPIO_PIN00_ID,
    GPIO_PIN01_ID,
    GPIO_PIN02_ID,
    GPIO_PIN03_ID,
    GPIO_PIN04_ID,
    GPIO_PIN05_ID,
    GPIO_PIN06_ID,
    GPIO_PIN07_ID,
    GPIO_PIN08_ID,
    GPIO_PIN09_ID,
    GPIO_PIN10_ID,
    GPIO_PIN11_ID,
    GPIO_PIN12_ID,
    GPIO_PIN13_ID,
    GPIO_PIN14_ID,
    GPIO_PIN15_ID,
}GPIO_pinID;

typedef enum
{
    GPIO_INPUT_FLOAT_MODE,
    GPIO_OUTPUT_PUSH_PULL_MODE,
    GPIO_ALTERNATE_PUSH_PULL_MODE,
    GPIO_ANALOG_MODE,
    GPIO_INPUT_PULLUP_MODE,
    GPIO_OUTPUT_OPEN_DRAIN_MODE,
    GPIO_ALTERNATE_OPEN_DRAIN_MODE,
    GPIO_INPUT_PULLDEOWN_MODE,
}GPIO_mode;

typedef enum
{
    GPIO_LOW_SPEED,
    GPIO_MEDIUM_SPEED,
    GPIO_HIGH_SPEED,
    GPIO_VERY_HIGH_SPEED,
}GPIO_speed;

typedef enum
{
    GPIO_LOW_PIN,
    GPIO_HIGH_PIN
}GPIO_pinStatus;

typedef enum
{
    GPIO_
}GPIO_alternateFunction; /* XXXXXX */

typedef struct
{
    GPIO_portID portID;
    GPIO_pinID pinID;
    GPIO_mode pinMode;
    GPIO_speed pinSpeed;
}GPIO_configurations;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : GPIO_init
 * [Description]   : Initialize all the pins with specific static configurations.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void GPIO_init(void);

/*=====================================================================================================================
 * [Function Name] : GPIO_configurePin
 * [Description]   : Configure a specific GPIO pin with specific configurations.
 * [Arguments]     : <a_ptr2configurations>      -> Pointer to a structure that holds the configurations.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 *                                                          - Port ID Error.
 *                                                          - Pin ID Error.
 *                                                          - Speed Error.
 *                                                          - Mode Error.
 ====================================================================================================================*/
GPIO_errorStatus GPIO_configurePin(GPIO_configurations* a_ptr2configurations);

/*=====================================================================================================================
 * [Function Name] : GPIO_setPin
 * [Description]   : Configure a specific GPIO pin with specific configurations and set its state.
 * [Arguments]     : <a_ptr2configurations>  -> Pointer to a structure that holds the configurations.
 *                   <a_pinStatus>           -> Indicates to the required pin state.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 *                                                          - Port ID Error.
 *                                                          - Pin ID Error.
 *                                                          - Speed Error.
 *                                                          - Mode Error.
 *                                                          - Status Error.
 ====================================================================================================================*/
GPIO_errorStatus GPIO_setPin(GPIO_configurations* a_ptr2configurations, GPIO_pinStatus a_pinStatus);

/*=====================================================================================================================
 * [Function Name] : GPIO_writePin
 * [Description]   : Write a certain value (High or Low) on a certain pin.
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_pinID>       -> Indicates to the required pin ID.
 *                   <a_pinStatus>   -> Indicates to the value [High - Low].
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port ID Error.
 *                                                          - Pin ID Error.
 *                                                          - Mode Error.
 ====================================================================================================================*/
GPIO_errorStatus GPIO_writePin(GPIO_portID a_portID, GPIO_pinID a_pinID, GPIO_pinStatus a_pinStatus);

/*=====================================================================================================================
 * [Function Name] : GPIO_writePort
 * [Description]   : Write a certain value in a certain port.
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_value>       -> Indicates to the value of the port [0 ~ 65535].
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port ID Error.
 ====================================================================================================================*/
GPIO_errorStatus GPIO_writePort(GPIO_portID a_portID, uint16 a_portValue);

/*=====================================================================================================================
 * [Function Name] : GPIO_readPin
 * [Description]   : Read the value of a certain pin [High - LOW].
 * [Arguments]     : <a_portID>         -> Indicates to the required port ID.
 *                   <a_pinID>          -> Indicates to the required pin ID.
 *                   <a_ptr2pinStatus>  -> Pointer to variable to store the value of the pin.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 *                                                          - Port ID Error.
 *                                                          - Pin ID Error.
 ====================================================================================================================*/
GPIO_errorStatus GPIO_readPin(GPIO_portID a_portID, GPIO_pinID a_pinID, GPIO_pinStatus* a_ptr2pinStatus);

/*=====================================================================================================================
 * [Function Name] : GPIO_readPort
 * [Description]   : Read the value of a certain port.
 * [Arguments]     : <a_portID>         -> Indicates to the required port ID.
 *                   <a_ptr2portValue>  -> Pointer to variable to store the value of the port.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 *                                                          - Port ID Error.
 ====================================================================================================================*/
GPIO_errorStatus GPIO_readPort(GPIO_portID a_portID, uint16* a_ptr2portValue);

/*=====================================================================================================================
 * [Function Name] : GPIO_togglePin
 * [Description]   : Toggle the value of a certain pin.
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_pinID>       -> Indicates to the required pin ID.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port ID Error.
 *                                                          - Pin ID Error.
 ====================================================================================================================*/
GPIO_errorStatus GPIO_togglePin(GPIO_portID a_portID, GPIO_pinID a_pinID);

/*=====================================================================================================================
 * [Function Name] : GPIO_lockPinConfiguration
 * [Description]   : Lock the configurations for a specific pin.
 * [Arguments]     : <a_portID>        -> Indicates to the required port ID.
 *                   <a_pinID>         -> Indicates to the required pin ID.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port ID Error.
 *                                                          - Pin ID Error.
 ====================================================================================================================*/
GPIO_errorStatus GPIO_lockPinConfiguration(GPIO_portID a_portID, GPIO_pinID a_pinID);

#endif /* MCAL_GPIO_INCLUDES_GPIO_H_ */
