/*
=======================================================================================================================
Author       : Mamoun
Module       : SPI
File Name    : spi.h
Date Created : Oct 29, 2023
Description  : Header file for the ATmega32 SPI driver.
=======================================================================================================================
*/


#ifndef MCAL_SPI_INCLUDES_SPI_H_
#define MCAL_SPI_INCLUDES_SPI_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

#if((SPI_DEVICE_MODE != SPI_MASTER_MODE) && (SPI_DEVICE_MODE != SPI_SLAVE_MODE))
#warning "Invalid SPI device mode, The SPI device can only be [Master or Slave]"
#endif

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    SPI_NO_ERRORS,
    SPI_PRESCALER_ERROR,
    SPI_NULL_PTR_ERROR
}SPI_errorStatus;

typedef enum
{
    SPI_PRESCASLER_4,
    SPI_PRESCASLER_16,
    SPI_PRESCASLER_64,
    SPI_PRESCASLER_128,
    SPI_PRESCASLER_2,
    SPI_PRESCASLER_8,
    SPI_PRESCASLER_32
}SPI_prescslerID;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

#if(SPI_DEVICE_MODE == SPI_MASTER_MODE)
/*=====================================================================================================================
 * [Function Name] : SPI_initMaster
 * [Description]   : Initialize this device as a Master with a specific prescaler.
 * [Arguments]     : <a_prescaler>      -> Indicates to the required prescaler.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Prescaler Error.
 ====================================================================================================================*/
SPI_errorStatus SPI_initMaster(SPI_prescslerID a_prescaler);

/*=====================================================================================================================
 * [Function Name] : SPI_masterSendChar
 * [Description]   : Send a byte as a Master using SPI with polling technique.
 * [Arguments]     : <a_byte>      -> Indicates to the required byte to be transmitted.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void SPI_masterSendChar(uint8 a_byte);

/*=====================================================================================================================
 * [Function Name] : SPI_masterReceiveChar
 * [Description]   : Receive a byte as a Master using SPI with polling technique.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns the received byte.
 ====================================================================================================================*/
uint8 SPI_masterReceiveChar(void);

/*=====================================================================================================================
 * [Function Name] : SPI_masterSendString
 * [Description]   : Send a string as a Master using SPI with polling technique.
 * [Arguments]     : <a_ptr2string>    -> Pointer to the required string to be transmitted.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
SPI_errorStatus SPI_masterSendString(uint8* a_ptr2string);

/*=====================================================================================================================
 * [Function Name] : SPI_masterReceiveString
 * [Description]   : Receive a string as a Master using SPI with polling technique.
 * [Arguments]     : <a_ptr2buffer>    -> Pointer to the buffer to store the received string.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
SPI_errorStatus SPI_masterReceiveString(uint8* a_ptr2buffer);
#endif

#if((SPI_DEVICE_MODE == SPI_SLAVE_MODE) && (SPI_API_INTERFACE_MODE == SPI_USING_POLLING))
/*=====================================================================================================================
 * [Function Name] : SPI_initSlave
 * [Description]   : Initialize this device as a Slave with polling technique.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void SPI_initSlave(void);

/*=====================================================================================================================
 * [Function Name] : SPI_slaveReceiveChar
 * [Description]   : Receive a byte as a Slave using SPI with polling technique.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns the received byte.
 ====================================================================================================================*/
uint8 SPI_slaveReceiveChar(void);

/*=====================================================================================================================
 * [Function Name] : SPI_slaveReceiveString
 * [Description]   : Receive a string as a Slave using SPI with polling technique.
 * [Arguments]     : <a_ptr2buffer>    -> Pointer to the buffer to store the received string.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
SPI_errorStatus SPI_slaveReceiveString(uint8* a_ptr2buffer);
#endif

#if((SPI_DEVICE_MODE == SPI_SLAVE_MODE) && (SPI_API_INTERFACE_MODE == SPI_USING_INTERRUPT))
/*=====================================================================================================================
 * [Function Name] : SPI_initSlave
 * [Description]   : Initialize this device as a Slave with receiving interrupt.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void SPI_initSlave(void);

/*=====================================================================================================================
 * [Function Name] : SPI_setCallBackFunction
 * [Description]   : Set the address of the call-back function.
 * [Arguments]     : <a_ptr2callBackFunction>      -> Pointer to the call-back function.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
SPI_errorStatus SPI_setCallBackFunction(void (*a_ptr2callBackFunction)(uint8));
#endif

/*=====================================================================================================================
 * [Function Name] : SPI_byteTransceiver
 * [Description]   : Send and Receive a byte using SPI at the same time.
 * [Arguments]     : <a_byte>    -> Indicates to the required byte to be transmitted.
 * [return]        : The function returns the received byte.
 ====================================================================================================================*/
uint8 SPI_byteTransceiver(uint8 a_byte);

/*=====================================================================================================================
 * [Function Name] : SPI_stringTransceiver
 * [Description]   : Send and Receive a string using SPI at the same time.
 * [Arguments]     : <a_ptr2stringOut>   -> Pointer to the required string to be transmitted.
 *                   <a_ptr2stringIn>    -> Pointer to the buffer to store the received string.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
SPI_errorStatus SPI_stringTransceiver(uint8* a_ptr2stringOut, uint8* a_ptr2stringIn);

#endif /* MCAL_SPI_INCLUDES_SPI_H_ */
