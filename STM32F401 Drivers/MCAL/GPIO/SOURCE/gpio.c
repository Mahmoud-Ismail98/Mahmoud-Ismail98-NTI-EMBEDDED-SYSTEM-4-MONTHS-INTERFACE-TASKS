/*
=======================================================================================================================
Author       : Mamoun
Module       : GPIO
File Name    : gpio.c
Date Created : Nov 6, 2023
Description  : Source file for the STM32F401 GPIO peripheral driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../OTHERS/std_types.h"
#include "../../../OTHERS/common_macros.h"
#include "../INCLUDES/gpio_prv.h"
#include "../INCLUDES/gpio_cfg.h"
#include "../INCLUDES/gpio.h"

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : GPIO_init
 * [Description]   : Initialize all the pins with specific static configurations.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void GPIO_init(void)
{
    GPIO_registers* LOC_ptr2gpioRegisters[GPIO_NUM_OF_PORTS] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};
    uint8 LOC_portIterator = 0;
    uint8 LOC_pinIterator = 0;

    uint8 LOC_pinsConfigurationsArray[GPIO_NUM_OF_PORTS][GPIO_NUM_OF_PINS_PER_PORT] =
    {
        {GPIO_PORTA_PIN00_MODE,GPIO_PORTA_PIN01_MODE,GPIO_PORTA_PIN02_MODE,GPIO_PORTA_PIN03_MODE,GPIO_PORTA_PIN04_MODE,GPIO_PORTA_PIN05_MODE,GPIO_PORTA_PIN06_MODE,GPIO_PORTA_PIN07_MODE,GPIO_PORTA_PIN08_MODE,GPIO_PORTA_PIN09_MODE,GPIO_PORTA_PIN10_MODE,GPIO_PORTA_PIN11_MODE,GPIO_PORTA_PIN12_MODE,GPIO_PORTA_PIN13_MODE,GPIO_PORTA_PIN14_MODE,GPIO_PORTA_PIN15_MODE},
        {GPIO_PORTB_PIN00_MODE,GPIO_PORTB_PIN01_MODE,GPIO_PORTB_PIN02_MODE,GPIO_PORTB_PIN03_MODE,GPIO_PORTB_PIN04_MODE,GPIO_PORTB_PIN05_MODE,GPIO_PORTB_PIN06_MODE,GPIO_PORTB_PIN07_MODE,GPIO_PORTB_PIN08_MODE,GPIO_PORTB_PIN09_MODE,GPIO_PORTB_PIN10_MODE,GPIO_PORTB_PIN11_MODE,GPIO_PORTB_PIN12_MODE,GPIO_PORTB_PIN13_MODE,GPIO_PORTB_PIN14_MODE,GPIO_PORTB_PIN15_MODE},
        {GPIO_PORTC_PIN00_MODE,GPIO_PORTC_PIN01_MODE,GPIO_PORTC_PIN02_MODE,GPIO_PORTC_PIN03_MODE,GPIO_PORTC_PIN04_MODE,GPIO_PORTC_PIN05_MODE,GPIO_PORTC_PIN06_MODE,GPIO_PORTC_PIN07_MODE,GPIO_PORTC_PIN08_MODE,GPIO_PORTC_PIN09_MODE,GPIO_PORTC_PIN10_MODE,GPIO_PORTC_PIN11_MODE,GPIO_PORTC_PIN12_MODE,GPIO_PORTC_PIN13_MODE,GPIO_PORTC_PIN14_MODE,GPIO_PORTC_PIN15_MODE},
        {GPIO_PORTD_PIN00_MODE,GPIO_PORTD_PIN01_MODE,GPIO_PORTD_PIN02_MODE,GPIO_PORTD_PIN03_MODE,GPIO_PORTD_PIN04_MODE,GPIO_PORTD_PIN05_MODE,GPIO_PORTD_PIN06_MODE,GPIO_PORTD_PIN07_MODE,GPIO_PORTD_PIN08_MODE,GPIO_PORTD_PIN09_MODE,GPIO_PORTD_PIN10_MODE,GPIO_PORTD_PIN11_MODE,GPIO_PORTD_PIN12_MODE,GPIO_PORTD_PIN13_MODE,GPIO_PORTD_PIN14_MODE,GPIO_PORTD_PIN15_MODE},
        {GPIO_PORTE_PIN00_MODE,GPIO_PORTE_PIN01_MODE,GPIO_PORTE_PIN02_MODE,GPIO_PORTE_PIN03_MODE,GPIO_PORTE_PIN04_MODE,GPIO_PORTE_PIN05_MODE,GPIO_PORTE_PIN06_MODE,GPIO_PORTE_PIN07_MODE,GPIO_PORTE_PIN08_MODE,GPIO_PORTE_PIN09_MODE,GPIO_PORTE_PIN10_MODE,GPIO_PORTE_PIN11_MODE,GPIO_PORTE_PIN12_MODE,GPIO_PORTE_PIN13_MODE,GPIO_PORTE_PIN14_MODE,GPIO_PORTE_PIN15_MODE},
        {GPIO_PORTH_PIN00_MODE,GPIO_PORTH_PIN01_MODE,GPIO_PORTH_PIN02_MODE,GPIO_PORTH_PIN03_MODE,GPIO_PORTH_PIN04_MODE,GPIO_PORTH_PIN05_MODE,GPIO_PORTH_PIN06_MODE,GPIO_PORTH_PIN07_MODE,GPIO_PORTH_PIN08_MODE,GPIO_PORTH_PIN09_MODE,GPIO_PORTH_PIN10_MODE,GPIO_PORTH_PIN11_MODE,GPIO_PORTH_PIN12_MODE,GPIO_PORTH_PIN13_MODE,GPIO_PORTH_PIN14_MODE,GPIO_PORTH_PIN15_MODE},
    };

    for(; LOC_portIterator < GPIO_NUM_OF_PORTS; LOC_portIterator++)
    {
        for(; LOC_pinIterator < GPIO_NUM_OF_PINS_PER_PORT; LOC_pinIterator++)
        {
            (*(LOC_ptr2gpioRegisters + LOC_portIterator))->GPIO_MODER |= (((*(*(LOC_pinsConfigurationsArray + LOC_portIterator) + LOC_pinIterator)) & 0X03) << (2 * LOC_pinIterator));

            switch (*(*(LOC_pinsConfigurationsArray + LOC_portIterator) + LOC_pinIterator))
            {
            case GPIO_INPUT_FLOAT_MODE:
            case GPIO_INPUT_PULLUP_MODE:
            case GPIO_INPUT_PULLDEOWN_MODE:
                (*(LOC_ptr2gpioRegisters + LOC_portIterator))->GPIO_PUPDR |= (((*(*(LOC_pinsConfigurationsArray + LOC_portIterator) + LOC_pinIterator)) >> 2) << (2 * LOC_pinIterator));
                break;

            case GPIO_OUTPUT_PUSH_PULL_MODE:
            case GPIO_OUTPUT_OPEN_DRAIN_MODE:
                (*(LOC_ptr2gpioRegisters + LOC_portIterator))->GPIO_OTYPER |= ((((*(*(LOC_pinsConfigurationsArray + LOC_portIterator) + LOC_pinIterator)) >> 2) & 0X01) << LOC_pinIterator);
                break;

            default:
                /* Do Nothing. */
                break;
            }
        }
    }
}

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
GPIO_errorStatus GPIO_configurePin(GPIO_configurations* a_ptr2configurations)
{
    GPIO_errorStatus LOC_errorStatus = GPIO_NO_ERRORS;
    GPIO_registers* LOC_ptr2gpioRegisters[GPIO_NUM_OF_PORTS] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};

    if(a_ptr2configurations == NULL_PTR)
    {
        LOC_errorStatus = GPIO_NULL_PTR_ERROR;
    }

    else if(a_ptr2configurations->portID >= GPIO_NUM_OF_PORTS)
    {
        LOC_errorStatus = GPIO_PORT_ID_ERROR;
    }

    else if(a_ptr2configurations->pinID >= GPIO_NUM_OF_PINS_PER_PORT)
    {
        LOC_errorStatus = GPIO_PIN_ID_ERROR;
    }

    else if(a_ptr2configurations->pinSpeed > GPIO_VERY_HIGH_SPEED)
    {
        LOC_errorStatus = GPIO_SPEED_ERROR;
    }

    else if(a_ptr2configurations->pinMode > GPIO_INPUT_PULLDEOWN_MODE)
    {
        LOC_errorStatus = GPIO_MODE_ERROR;
    }

    else
    {
        (*(LOC_ptr2gpioRegisters + a_ptr2configurations->portID))->GPIO_MODER |= ((a_ptr2configurations->pinMode & 0X03) << (2 * a_ptr2configurations->pinID));
        (*(LOC_ptr2gpioRegisters + a_ptr2configurations->portID))->GPIO_OSPEEDR |= (a_ptr2configurations->pinSpeed << (2 * a_ptr2configurations->pinID));

        switch (a_ptr2configurations->pinMode)
        {
        case GPIO_INPUT_FLOAT_MODE:
        case GPIO_INPUT_PULLUP_MODE:
        case GPIO_INPUT_PULLDEOWN_MODE:
            (*(LOC_ptr2gpioRegisters + a_ptr2configurations->portID))->GPIO_PUPDR |= ((a_ptr2configurations->pinMode >> 2) << (2 * a_ptr2configurations->pinID));
            break;
        
        case GPIO_OUTPUT_PUSH_PULL_MODE:
        case GPIO_OUTPUT_OPEN_DRAIN_MODE:
            (*(LOC_ptr2gpioRegisters + a_ptr2configurations->portID))->GPIO_OTYPER |= (((a_ptr2configurations->pinMode >> 2) & 0X01) << a_ptr2configurations->pinMode);
            break;
        
        case GPIO_ALTERNATE_PUSH_PULL_MODE:
            /* code */
            break;

        case GPIO_ALTERNATE_OPEN_DRAIN_MODE:
            /* code */
            break;
        case GPIO_ANALOG_MODE:
            /* code */
            break;

        default:
            /* Do Nothing. */
            break;
        }
    }

    return LOC_errorStatus;
}

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
GPIO_errorStatus GPIO_setPin(GPIO_configurations* a_ptr2configurations, GPIO_pinStatus a_pinStatus)
{
    GPIO_errorStatus LOC_errorStatus = GPIO_NO_ERRORS;

    if(a_ptr2configurations == NULL_PTR)
    {
        LOC_errorStatus = GPIO_NO_ERRORS;
    }

    else if(a_ptr2configurations->portID >= GPIO_NUM_OF_PORTS)
    {
        LOC_errorStatus = GPIO_PORT_ID_ERROR;
    }

    else if(a_ptr2configurations->pinID >= GPIO_NUM_OF_PINS_PER_PORT)
    {
        LOC_errorStatus = GPIO_PIN_ID_ERROR;
    }

    else if(a_ptr2configurations->pinSpeed > GPIO_VERY_HIGH_SPEED)
    {
        LOC_errorStatus = GPIO_SPEED_ERROR;
    }

    else if((a_pinStatus != GPIO_LOW_PIN) && (a_pinStatus != GPIO_HIGH_PIN))
    {
        LOC_errorStatus = GPIO_PIN_STATUS_ERROR;
    }
    
    else if(a_ptr2configurations->pinMode > GPIO_INPUT_PULLDEOWN_MODE)
    {
        LOC_errorStatus = GPIO_MODE_ERROR;
    }

    else
    {
        GPIO_configurePin(a_ptr2configurations);
        GPIO_writePin(a_ptr2configurations->portID,a_ptr2configurations->pinID,a_pinStatus);
    }

    return LOC_errorStatus;
}

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
GPIO_errorStatus GPIO_writePin(GPIO_portID a_portID, GPIO_pinID a_pinID, GPIO_pinStatus a_pinStatus)
{
    GPIO_errorStatus LOC_errorStatus = GPIO_NO_ERRORS;
    GPIO_registers* LOC_ptr2gpioRegisters[GPIO_NUM_OF_PORTS] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};

    if(a_portID >= GPIO_NUM_OF_PORTS)
    {
        LOC_errorStatus = GPIO_PORT_ID_ERROR;
    }

    else if(a_pinID >= GPIO_NUM_OF_PINS_PER_PORT)
    {
        LOC_errorStatus = GPIO_PIN_ID_ERROR;
    }

    else if((a_pinStatus != GPIO_LOW_PIN) && (a_pinStatus != GPIO_HIGH_PIN))
    {
        LOC_errorStatus = GPIO_PIN_STATUS_ERROR;
    }

    else
    {
        /* xxxxx Replace it with bitband or BSRR for atomic xxxxx */
        (*(LOC_ptr2gpioRegisters + a_portID))->GPIO_ODR |= ((a_pinStatus & 0X01) << a_pinID);
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : GPIO_writePort
 * [Description]   : Write a certain value in a certain port.
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_value>       -> Indicates to the value of the port [0 ~ 65535].
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port ID Error.
 ====================================================================================================================*/
GPIO_errorStatus GPIO_writePort(GPIO_portID a_portID, uint16 a_portValue)
{
    GPIO_errorStatus LOC_errorStatus = GPIO_NO_ERRORS;
    GPIO_registers* LOC_ptr2gpioRegisters[GPIO_NUM_OF_PORTS] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};

    if(a_portID >= GPIO_NUM_OF_PORTS)
    {
        LOC_errorStatus = GPIO_PORT_ID_ERROR;
    }

    else
    {
        /* xxxxx Replace it with bitband or BSRR for atomic xxxxx */
        (*(LOC_ptr2gpioRegisters + a_portID))->GPIO_ODR = a_portValue;
    }

    return LOC_errorStatus;
}

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
GPIO_errorStatus GPIO_readPin(GPIO_portID a_portID, GPIO_pinID a_pinID, GPIO_pinStatus* a_ptr2pinStatus)
{
    GPIO_errorStatus LOC_errorStatus = GPIO_NO_ERRORS;
    GPIO_registers* LOC_ptr2gpioRegisters[GPIO_NUM_OF_PORTS] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};

    if(a_portID >= GPIO_NUM_OF_PORTS)
    {
        LOC_errorStatus = GPIO_PORT_ID_ERROR;
    }

    else if(a_pinID >= GPIO_NUM_OF_PINS_PER_PORT)
    {
        LOC_errorStatus = GPIO_PIN_ID_ERROR;
    }

    else if(a_ptr2pinStatus == NULL_PTR)
    {
        LOC_errorStatus = GPIO_NULL_PTR_ERROR;
    }

    else
    {
        *a_ptr2pinStatus = GET_BIT((*(LOC_ptr2gpioRegisters + a_portID))->GPIO_IDR,a_pinID);
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : GPIO_readPort
 * [Description]   : Read the value of a certain port.
 * [Arguments]     : <a_portID>         -> Indicates to the required port ID.
 *                   <a_ptr2portValue>  -> Pointer to variable to store the value of the port.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 *                                                          - Port ID Error.
 ====================================================================================================================*/
GPIO_errorStatus GPIO_readPort(GPIO_portID a_portID, uint16* a_ptr2portValue)
{
    GPIO_errorStatus LOC_errorStatus = GPIO_NO_ERRORS;
    GPIO_registers* LOC_ptr2gpioRegisters[GPIO_NUM_OF_PORTS] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};

    if(a_portID >= GPIO_NUM_OF_PORTS)
    {
        LOC_errorStatus = GPIO_PORT_ID_ERROR;
    }

    else if(a_ptr2portValue == NULL_PTR)
    {
        LOC_errorStatus = GPIO_NULL_PTR_ERROR;
    }

    else
    {
        *a_ptr2portValue = (*(LOC_ptr2gpioRegisters + a_portID))->GPIO_IDR;
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : GPIO_togglePin
 * [Description]   : Toggle the value of a certain pin.
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_pinID>       -> Indicates to the required pin ID.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port ID Error.
 *                                                          - Pin ID Error.
 ====================================================================================================================*/
GPIO_errorStatus GPIO_togglePin(GPIO_portID a_portID, GPIO_pinID a_pinID)
{
    GPIO_errorStatus LOC_errorStatus = GPIO_NO_ERRORS;
    GPIO_registers* LOC_ptr2gpioRegisters[GPIO_NUM_OF_PORTS] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};

    if(a_portID >= GPIO_NUM_OF_PORTS)
    {
        LOC_errorStatus = GPIO_PORT_ID_ERROR;
    }

    else if(a_pinID >= GPIO_NUM_OF_PINS_PER_PORT)
    {
        LOC_errorStatus = GPIO_PIN_ID_ERROR;
    }

    else
    {
        TOGGLE_BIT((*(LOC_ptr2gpioRegisters + a_portID))->GPIO_ODR,a_pinID);
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : GPIO_selectAlternateFunction
 * [Description]   : Select the alternate function for a specific pin.
 * [Arguments]     : <a_portID>        -> Indicates to the required port ID.
 *                   <a_pinID>         -> Indicates to the required pin ID.
 *                   <a_pinFunction>   -> Indicates to the required pin function.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port ID Error.
 *                                                          - Pin ID Error.
 *                                                          - Pin Function Error.
 ====================================================================================================================*/
GPIO_errorStatus GPIO_selectAlternateFunction(GPIO_portID a_portID, GPIO_pinID a_pinID, GPIO_alternateFunction a_pinFunction)
{
    GPIO_errorStatus LOC_errorStatus = GPIO_NO_ERRORS;
    GPIO_registers* LOC_ptr2gpioRegisters[GPIO_NUM_OF_PORTS] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};

    if(a_portID >= GPIO_NUM_OF_PORTS)
    {
        LOC_errorStatus = GPIO_PORT_ID_ERROR;
    }

    else if(a_pinID >= GPIO_NUM_OF_PINS_PER_PORT)
    {
        LOC_errorStatus = GPIO_PIN_ID_ERROR;
    }

    else if(a_pinFunction > GPIO_) /* XXXXXX */
    {
        LOC_errorStatus = GPIO_ALTERNATE_FUNCTION_ERROR;
    }

    else if(a_pinID < 8) /* XXX Magic Number XXX */
    {
        (*(LOC_ptr2gpioRegisters + a_portID))->GPIO_AFRL |= ((a_pinFunction & 0X0F) << (4 * a_pinID));
    }

    else
    {
        (*(LOC_ptr2gpioRegisters + a_portID))->GPIO_AFRH |= ((a_pinFunction & 0X0F) << (4 * a_pinID));
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : GPIO_lockPinConfiguration
 * [Description]   : Lock the configurations for a specific pin.
 * [Arguments]     : <a_portID>        -> Indicates to the required port ID.
 *                   <a_pinID>         -> Indicates to the required pin ID.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port ID Error.
 *                                                          - Pin ID Error.
 ====================================================================================================================*/
GPIO_errorStatus GPIO_lockPinConfiguration(GPIO_portID a_portID, GPIO_pinID a_pinID)
{
    GPIO_errorStatus LOC_errorStatus = GPIO_NO_ERRORS;
    GPIO_registers* LOC_ptr2gpioRegisters[GPIO_NUM_OF_PORTS] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};

    if(a_portID >= GPIO_NUM_OF_PORTS)
    {
        LOC_errorStatus = GPIO_PORT_ID_ERROR;
    }

    else if(a_pinID >= GPIO_NUM_OF_PINS_PER_PORT)
    {
        LOC_errorStatus = GPIO_PIN_ID_ERROR;
    }

    else
    {
        SET_BIT((*(LOC_ptr2gpioRegisters + a_portID))->GPIO_LCKR,16);
        SET_BIT((*(LOC_ptr2gpioRegisters + a_portID))->GPIO_LCKR,a_pinID);
        CLEAR_BIT((*(LOC_ptr2gpioRegisters + a_portID))->GPIO_LCKR,16);
    }

    return LOC_errorStatus;
}

