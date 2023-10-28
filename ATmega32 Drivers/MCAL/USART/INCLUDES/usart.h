/*
=======================================================================================================================
Author       : Mamoun
Module       : USART
File Name    : usart.h
Date Created : Oct 28, 2023
Description  : Header file for the ATmega32 USART driver.
=======================================================================================================================
*/


#ifndef MCAL_USART_INCLUDES_USART_H_
#define MCAL_USART_INCLUDES_USART_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

#if((USART_API_INTERFACE_MODE != USART_USING_POLLING) && (USART_API_INTERFACE_MODE!= USART_USING_INTERRUPT))
#error "Invalid USART API interface mode, You can only interface using [polling or interrupt]"
#endif

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    USART_NO_ERRORS,
    USART_NULL_PTR_ERROR,
    USART_BAUD_RATE_ERROR,
    USART_RX_TX_STATUS_ERROR,
    USART_PARITY_MODE_ERROR,
    USART_COMMUNICATION_MODE_ERROR,
    USART_DOUBLE_BAUD_RATE_STATUS_ERROR
}USART_errorStatus;

typedef enum
{
    USART_RX_TX_DISABLE,
	USART_RX_TX_ENABLE
}USART_TxRxStatus; ////////////////////////////////////////

typedef enum
{
    USART_ASYNCHRONOUS,
    USART_SYNCHRONOUS
}USART_communicationMode;

typedef enum
{
    USART_PARITY_DISABLE,
    USART_EVEN_PARITY_ENABLE = 0X02,
    USART_ODD_PARITY_ENABLE,
}USART_parityMode;

typedef enum
{
    USART_DOUBLE_BAUD_RATE_DISABLE,
    USART_DOUBLE_BAUD_RATE_ENABLE,
}USART_doubleBaudRateStatus;

typedef struct
{
    USART_TxRxStatus receiver_status;
    USART_TxRxStatus transmitter_status;
    USART_communicationMode communication_mode;
    USART_parityMode parity_mode;
    USART_doubleBaudRateStatus double_baudrate_status;
    uint32 baudrate;
}USART_configurations;

/*=====================================================================================================================
                                         < Functions Prototypes >
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
USART_errorStatus USART_init(USART_configurations* a_ptr2configurations);

/*=====================================================================================================================
 * [Function Name] : USART_sendCharSync
 * [Description]   : Send a byte using USART with polling technique.
 * [Arguments]     : <a_byte>      -> Indicates to the required byte to be transmitted.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void USART_sendCharSync(uint8 a_byte);

/*=====================================================================================================================
 * [Function Name] : USART_receiveCharSync
 * [Description]   : Receive a byte using USART with polling technique.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns the received byte.
 ====================================================================================================================*/
uint8 USART_receiveCharSync(void);

/*=====================================================================================================================
 * [Function Name] : USART_sendStringSync
 * [Description]   : Send a string using USART with polling technique.
 * [Arguments]     : <a_ptr2string>      -> Pointer to the required string to be transmitted.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
USART_errorStatus USART_sendStringSync(uint8* a_ptr2string);

/*=====================================================================================================================
 * [Function Name] : USART_receiveCharSync
 * [Description]   : Receive a string using USART with polling technique.
 * [Arguments]     : <a_ptr2buffer>      -> Pointer to the buffer to store the received string.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
USART_errorStatus USART_receiveStringSync(uint8* a_ptr2buffer);

#if(USART_API_INTERFACE_MODE == USART_USING_INTERRUPT)
/*=====================================================================================================================
 * [Function Name] : USART_setCallBackFunction
 * [Description]   : Set the address of the call-back function.
 * [Arguments]     : <a_ptr2callBackFunction>      -> Pointer to the call-back function.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
USART_errorStatus USART_setCallBackFunction(void (*a_ptr2callBackFunction)(uint8));
#endif

#endif /* MCAL_USART_INCLUDES_USART_H_ */
