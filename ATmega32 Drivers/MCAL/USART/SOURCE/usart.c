/*
=======================================================================================================================
Author       : Mamoun
Module       : USART
File Name    : usart.c
Date Created : Oct 28, 2023
Description  : Source file for the ATmega32 USART driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../OTHERS/std_types.h"
#include "../../../OTHERS/common_macros.h"
#include "../INCLUDES/usart_prv.h"
#include "../INCLUDES/usart_cfg.h"
#include "../INCLUDES/usart.h"
#include <avr/io.h>

/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/

void (*g_ptr2callBackFunction)(uint8) = NULL_PTR;

/*=====================================================================================================================
                                      < Private Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : USART_baudRateCalculator
 * [Description]   : Calculate the value of thr UBRR register based on the choosen baud rate.
 * [Arguments]     : <a_ptr2configurations>   -> Pointer to a structure holds the configurations.
 *                   <a_regisetValue>         -> Pointer to a variable to store the UBRR value.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Double Baud Rate Status.
 *                                                          - Communication Mode Error.
 ====================================================================================================================*/
static USART_errorStatus USART_baudRateCalculator(USART_configurations* a_ptr2configurations, uint16* a_regisetValue);

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : USART_init
 * [Description]   : Initialize the USART with specific configurations.
 * [Arguments]     : <a_ptr2configurations>    -> Pointer to a structure holds the configurations.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Baud Rate Error.
 *                                                          - Prescaler Error.
 *                                                          - Null Pointer Error.
 *                                                          - Parity Mode Error.
 *                                                          - Rx Tx Status Error.
 *                                                          - Double Baud Rate Status.
 *                                                          - Communication Mode Error.
 ====================================================================================================================*/
USART_errorStatus USART_init(USART_configurations* a_ptr2configurations)
{
    USART_errorStatus LOC_errorStatus = USART_NO_ERRORS;
    uint16 LOC_valueOfUBRR = 0;

    if(a_ptr2configurations == NULL_PTR)
    {
        LOC_errorStatus = USART_NULL_PTR_ERROR;
    }

    else if((a_ptr2configurations->receiver_status != USART_RX_TX_ENABLE) && \
            (a_ptr2configurations->receiver_status != USART_RX_TX_DISABLE))
    {
        LOC_errorStatus = USART_RX_TX_STATUS_ERROR;
    }

    else if((a_ptr2configurations->transmitter_status != USART_RX_TX_ENABLE) && \
            (a_ptr2configurations->transmitter_status != USART_RX_TX_DISABLE))
    {
        LOC_errorStatus = USART_RX_TX_STATUS_ERROR;
    }

    else if((a_ptr2configurations->parity_mode != USART_PARITY_DISABLE) && \
            (a_ptr2configurations->parity_mode != USART_EVEN_PARITY_ENABLE) && \
            (a_ptr2configurations->parity_mode != USART_ODD_PARITY_ENABLE))
    {
        LOC_errorStatus = USART_PARITY_MODE_ERROR;
    }

    else if((a_ptr2configurations->baudrate < 2400UL) || \
            (a_ptr2configurations->baudrate > 250000UL))
    {
        LOC_errorStatus = USART_BAUD_RATE_ERROR;
    }

    else
    {
        LOC_errorStatus = USART_baudRateCalculator(a_ptr2configurations,&LOC_valueOfUBRR);

        USART_SET_RECEIVER_STATUS(a_ptr2configurations->receiver_status);
        USART_SET_TRANSMITTER_STATUS(a_ptr2configurations->transmitter_status);
        USART_ENABLE_DOUBLE_BAUD_RATE(a_ptr2configurations->double_baudrate_status);
        USART_SET_COMMUNICATION_MODE(a_ptr2configurations->communication_mode);
        USART_SET_PARITY_MODE(a_ptr2configurations->parity_mode);
        USART_SET_DATA_BITS_SIZE();
        USART_SET_STOP_BIT_SIZE();
        USART_SET_UBRRL_REGISTER(LOC_valueOfUBRR);
        USART_SET_UBRRH_REGISTER(LOC_valueOfUBRR);

        #if(USART_API_INTERFACE_MODE == USART_USING_INTERRUPT)
        /* Incase interfacing with USART using interrupt, enable the interrupt. */
        (a_ptr2configurations->receiver_status == USART_RX_TX_ENABLE) ? SET_BIT(UCSRB,RXCIE) : CLEAR_BIT(UCSRB,RXCIE);
        (a_ptr2configurations->transmitter_status == USART_RX_TX_ENABLE) ? SET_BIT(UCSRB,TXCIE) : CLEAR_BIT(UCSRB,TXCIE);
        #endif
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : USART_baudRateCalculator
 * [Description]   : Calculate the value of thr UBRR register based on the choosen baud rate.
 * [Arguments]     : <a_ptr2configurations>   -> Pointer to a structure holds the configurations.
 *                   <a_regisetValue>         -> Pointer to a variable to store the UBRR value.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Double Baud Rate Status.
 *                                                          - Communication Mode Error.
 ====================================================================================================================*/
static USART_errorStatus USART_baudRateCalculator(USART_configurations* a_ptr2configurations, uint16* a_regisetValue)
{
    USART_errorStatus LOC_errorStatus = USART_NO_ERRORS;

    switch (a_ptr2configurations->communication_mode)
    {
    case USART_ASYNCHRONOUS:
        switch (a_ptr2configurations->double_baudrate_status)
        {
        case USART_DOUBLE_BAUD_RATE_DISABLE:
            *a_regisetValue = ((F_CPU / (16 * a_ptr2configurations->baudrate)) - 1);
            break;
        
        case USART_DOUBLE_BAUD_RATE_ENABLE:
            *a_regisetValue = ((F_CPU / (8 * a_ptr2configurations->baudrate)) - 1);
            break;
        
        default:
            LOC_errorStatus = USART_DOUBLE_BAUD_RATE_STATUS_ERROR;
            break;
        }
        break;
    
    case USART_SYNCHRONOUS:
        *a_regisetValue = ((F_CPU / (2 * a_ptr2configurations->baudrate)) - 1);
        break;
    
    default:
        LOC_errorStatus = USART_COMMUNICATION_MODE_ERROR;
        break;
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : USART_sendCharSync
 * [Description]   : Send a byte using USART with polling technique.
 * [Arguments]     : <a_byte>      -> Indicates to the required byte to be transmitted.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void USART_sendCharSync(uint8 a_byte)
{
    while(BIT_IS_CLEAR(UCSRA,UDRE));
    SET_BIT(UCSRA,UDRE);
    UDR = a_byte;
}

/*=====================================================================================================================
 * [Function Name] : USART_receiveCharSync
 * [Description]   : Receive a byte using USART with polling technique.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns the received byte.
 ====================================================================================================================*/
uint8 USART_receiveCharSync(void)
{
    while(BIT_IS_CLEAR(UCSRA,RXC));
    return UDR;
}

/*=====================================================================================================================
 * [Function Name] : USART_sendStringSync
 * [Description]   : Send a string using USART with polling technique.
 * [Arguments]     : <a_ptr2string>      -> Pointer to the required string to be transmitted.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
USART_errorStatus USART_sendStringSync(uint8* a_ptr2string)
{
    USART_errorStatus LOC_errorStatus = USART_NO_ERRORS;

    if(a_ptr2string == NULL_PTR)
    {
        LOC_errorStatus = USART_NULL_PTR_ERROR;
    }

    else
    {
        for(uint8 iterator = 0; *(a_ptr2string + iterator) != USART_MESSAGE_TERMINATOR; iterator++)
        {
            USART_sendCharSync(*(a_ptr2string + iterator));
        }
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : USART_receiveStringSync
 * [Description]   : Receive a string using USART with polling technique.
 * [Arguments]     : <a_ptr2buffer>      -> Pointer to the buffer to store the received string.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
USART_errorStatus USART_receiveStringSync(uint8* a_ptr2buffer)
{
    USART_errorStatus LOC_errorStatus = USART_NO_ERRORS;
    uint8 LOC_receivedByte = USART_MESSAGE_TERMINATOR;
    uint8 LOC_bufferCounter = 0;

    if(a_ptr2buffer == NULL_PTR)
    {
        LOC_errorStatus = USART_NULL_PTR_ERROR;
    }

    else
    {
        LOC_receivedByte = USART_receiveCharSync();

        while(LOC_receivedByte != USART_MESSAGE_TERMINATOR)
        {
            *(a_ptr2buffer + LOC_bufferCounter) = LOC_receivedByte;
            LOC_bufferCounter++;

            LOC_receivedByte = USART_receiveCharSync();
        }

        *(a_ptr2buffer + LOC_bufferCounter) = '\0';
    }

    return LOC_errorStatus;
}

#if(USART_API_INTERFACE_MODE == USART_USING_INTERRUPT)
/*=====================================================================================================================
 * [Function Name] : USART_setCallBackFunction
 * [Description]   : Set the address of the call-back function.
 * [Arguments]     : <a_ptr2callBackFunction>      -> Pointer to the call-back function.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
USART_errorStatus USART_setCallBackFunction(void (*a_ptr2callBackFunction)(uint8))
{
    USART_errorStatus LOC_errorStatus = USART_NO_ERRORS;

    if(a_ptr2callBackFunction == NULL_PTR)
    {
        LOC_errorStatus = USART_NULL_PTR_ERROR;
    }

    else
    {
        g_ptr2callBackFunction = a_ptr2callBackFunction;
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : USART_RX_ISR
 * [Description]   : Interrupt Service Routine of the USART Receive Complete.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
    if(g_ptr2callBackFunction != NULL_PTR)
    {
        /* Call the call-back function. */
        g_ptr2callBackFunction(UDR);
    }
}
#endif

