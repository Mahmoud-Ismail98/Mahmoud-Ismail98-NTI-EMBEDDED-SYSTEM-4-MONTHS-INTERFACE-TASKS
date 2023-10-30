/*
=======================================================================================================================
Author       : Mamoun
Module       : SPI
File Name    : spi.c
Date Created : Oct 29, 2023
Description  : Source file for the ATmega32 SPI driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../OTHERS/std_types.h"
#include "../../../OTHERS/common_macros.h"
#include "../INCLUDES/spi_prv.h"
#include "../INCLUDES/spi_cfg.h"
#include "../INCLUDES/spi.h"
#include <avr/io.h>

/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/

#if((SPI_DEVICE_MODE == SPI_SLAVE_MODE) && (SPI_API_INTERFACE_MODE == SPI_USING_INTERRUPT))
void (*g_ptr2callBackFunction)(uint8) = NULL_PTR;
#endif

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

#if(SPI_DEVICE_MODE == SPI_MASTER_MODE)
/*=====================================================================================================================
 * [Function Name] : SPI_initMaster
 * [Description]   : Initialize this device as a Master with a specific prescaler.
 * [Arguments]     : <a_prescaler>      -> Indicates to the required prescaler.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Prescaler Error.
 ====================================================================================================================*/
SPI_errorStatus SPI_initMaster(SPI_prescslerID a_prescaler)
{
    SPI_errorStatus LOC_errorStatus = SPI_NO_ERRORS;

    if((a_prescaler < SPI_PRESCASLER_4) || (a_prescaler > SPI_PRESCASLER_32))
    {
        LOC_errorStatus = SPI_PRESCALER_ERROR;
    }

    else
    {
        SET_BIT(SPCR,MSTR);                                      /* Set this device as a Master. */
        SPCR = ((SPCR & 0XFC) | (a_prescaler & 0X03));           /* Set the SPI prescaler.       */
        SPSR = ((SPSR & 0XFE) | ((a_prescaler >> 2) & 0X01));    /* Set the SPI prescaler.       */
        SET_BIT(SPCR,SPE);                                       /* Enable SPI Peripheral.       */
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : SPI_masterSendChar
 * [Description]   : Send a byte as a Master using SPI with polling technique.
 * [Arguments]     : <a_byte>      -> Indicates to the required byte to be transmitted.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void SPI_masterSendChar(uint8 a_byte)
{
	SPDR = a_byte;
	while(BIT_IS_CLEAR(SPSR,SPIF));
}

/*=====================================================================================================================
 * [Function Name] : SPI_masterReceiveChar
 * [Description]   : Receive a byte as a Master using SPI with polling technique.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns the received byte.
 ====================================================================================================================*/
uint8 SPI_masterReceiveChar(void)
{
    SPDR = SPI_DUMMY_BYTE;
    while(BIT_IS_CLEAR(SPSR,SPIF));
    return SPDR;
}

/*=====================================================================================================================
 * [Function Name] : SPI_masterSendString
 * [Description]   : Send a string as a Master using SPI with polling technique.
 * [Arguments]     : <a_ptr2string>    -> Pointer to the required string to be transmitted.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
SPI_errorStatus SPI_masterSendString(uint8* a_ptr2string)
{
    SPI_errorStatus LOC_errorStatus = SPI_NO_ERRORS;

    if(a_ptr2string == NULL_PTR)
    {
        LOC_errorStatus = SPI_NULL_PTR_ERROR;
    }

    else
    {
        for(uint8 iterator = 0; *(a_ptr2string + iterator) != '\0'; iterator++)
        {
            SPI_masterSendChar(*(a_ptr2string + iterator));
        }
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : SPI_masterReceiveString
 * [Description]   : Receive a string as a Master using SPI with polling technique.
 * [Arguments]     : <a_ptr2buffer>    -> Pointer to the buffer to store the received string.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
SPI_errorStatus SPI_masterReceiveString(uint8* a_ptr2buffer)
{
    SPI_errorStatus LOC_errorStatus = SPI_NO_ERRORS;

    if(a_ptr2buffer == NULL_PTR)
    {
        LOC_errorStatus = SPI_NULL_PTR_ERROR;
    }

    else
    {
        uint8 LOC_byteCounter = 0;
        uint8 LOC_receivedByte = SPI_masterReceiveChar();

        if(LOC_receivedByte != SPI_MESSAGE_TERMINATOR)
        {
            *(a_ptr2buffer + LOC_byteCounter) = LOC_receivedByte;
            LOC_byteCounter++;

            LOC_receivedByte = SPI_masterReceiveChar();
        }

        *(a_ptr2buffer + LOC_byteCounter) = '\0';
    }

    return LOC_errorStatus;
}
#endif

#if((SPI_DEVICE_MODE == SPI_SLAVE_MODE) && (SPI_API_INTERFACE_MODE == SPI_USING_POLLING))
/*=====================================================================================================================
 * [Function Name] : SPI_initSlave
 * [Description]   : Initialize this device as a Slave with polling technique.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void SPI_initSlave(void)
{
    SET_BIT(SPCR,SPE);                                            /* Enable SPI Peripheral.      */
}

/*=====================================================================================================================
 * [Function Name] : SPI_slaveReceiveChar
 * [Description]   : Receive a byte as a Slave using SPI with polling technique.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns the received byte.
 ====================================================================================================================*/
uint8 SPI_slaveReceiveChar(void)
{
    while(BIT_IS_CLEAR(SPSR,SPIF));
    return SPDR;
}

/*=====================================================================================================================
 * [Function Name] : SPI_slaveReceiveString
 * [Description]   : Receive a string as a Slave using SPI with polling technique.
 * [Arguments]     : <a_ptr2buffer>    -> Pointer to the buffer to store the received string.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
SPI_errorStatus SPI_slaveReceiveString(uint8* a_ptr2buffer)
{
    SPI_errorStatus LOC_errorStatus = SPI_NO_ERRORS;

    if(a_ptr2buffer == NULL_PTR)
    {
        LOC_errorStatus = SPI_NULL_PTR_ERROR;
    }

    else
    {
        uint8 LOC_byteCounter = 0;
        uint8 LOC_receivedByte = SPI_slaveReceiveChar();

        if(LOC_receivedByte != SPI_MESSAGE_TERMINATOR)
        {
            *(a_ptr2buffer + LOC_byteCounter) = LOC_receivedByte;
            LOC_byteCounter++;

            LOC_receivedByte = SPI_slaveReceiveChar();
        }

        *(a_ptr2buffer + LOC_byteCounter) = '\0';
    }

    return LOC_errorStatus;
}
#endif

#if((SPI_DEVICE_MODE == SPI_SLAVE_MODE) && (SPI_API_INTERFACE_MODE == SPI_USING_INTERRUPT))
/*=====================================================================================================================
 * [Function Name] : SPI_initSlave
 * [Description]   : Initialize this device as a Slave with receiving interrupt.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void SPI_initSlave(void)
{
    SET_BIT(SPCR,SPIE);                                           /* Enable SPI Interrupt.       */
    SET_BIT(SPCR,SPE);                                            /* Enable SPI Peripheral.      */
}

/*=====================================================================================================================
 * [Function Name] : SPI_setCallBackFunction
 * [Description]   : Set the address of the call-back function.
 * [Arguments]     : <a_ptr2callBackFunction>      -> Pointer to the call-back function.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
SPI_errorStatus SPI_setCallBackFunction(void (*a_ptr2callBackFunction)(uint8))
{
    SPI_errorStatus LOC_errorStatus = SPI_NO_ERRORS;

    if(a_ptr2callBackFunction == NULL_PTR)
    {
        LOC_errorStatus = SPI_NULL_PTR_ERROR;
    }

    else
    {
        g_ptr2callBackFunction = a_ptr2callBackFunction;
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : SPI_STC_ISR
 * [Description]   : Interrupt Service Routine of the SPI Transfere Complete.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
    if(g_ptr2callBackFunction != NULL_PTR)
    {
        /* Call the call-back function. */
        g_ptr2callBackFunction(SPDR);
    }
}
#endif

/*=====================================================================================================================
 * [Function Name] : SPI_byteTransceiver
 * [Description]   : Send and Receive a byte using SPI at the same time.
 * [Arguments]     : <a_byte>    -> Indicates to the required byte to be transmitted.
 * [return]        : The function returns the received byte.
 ====================================================================================================================*/
uint8 SPI_byteTransceiver(uint8 a_byte)
{
    SPDR = a_byte;
    while(BIT_IS_CLEAR(SPSR,SPIF));
    return SPDR;
}

/*=====================================================================================================================
 * [Function Name] : SPI_stringTransceiver
 * [Description]   : Send and Receive a string using SPI at the same time.
 * [Arguments]     : <a_ptr2stringOut>   -> Pointer to the required string to be transmitted.
 *                   <a_ptr2stringIn>    -> Pointer to the buffer to store the received string.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
SPI_errorStatus SPI_stringTransceiver(uint8* a_ptr2stringOut, uint8* a_ptr2stringIn)
{
    SPI_errorStatus LOC_errorStatus = SPI_NO_ERRORS;

    if((a_ptr2stringOut == NULL_PTR) || (a_ptr2stringIn == NULL_PTR))
    {
        LOC_errorStatus = SPI_NULL_PTR_ERROR;
    }

    else
    {
        uint8 LOC_byteCounter = 0;
        uint8 LOC_receivedByte = SPI_byteTransceiver(*(a_ptr2stringOut + LOC_byteCounter));

        if(LOC_receivedByte != SPI_MESSAGE_TERMINATOR)
        {
            *(a_ptr2stringIn + LOC_byteCounter) = LOC_receivedByte;
            LOC_byteCounter++;

            LOC_receivedByte = SPI_byteTransceiver(*(a_ptr2stringOut + LOC_byteCounter));
        }

        *(a_ptr2stringIn + LOC_byteCounter) = '\0';
    }

    return LOC_errorStatus;
}
