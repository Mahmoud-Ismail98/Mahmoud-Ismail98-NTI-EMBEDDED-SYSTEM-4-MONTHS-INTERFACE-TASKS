/*
=======================================================================================================================
Author       : Mamoun
Module       : Global Interrupt
File Name    : gie.h
Date Created : Oct 22, 2023
Description  : Header file for the AVR Global Interrupt driver.
=======================================================================================================================
*/


#ifndef MCAL_GIE_INCLUDES_GIE_H_
#define MCAL_GIE_INCLUDES_GIE_H_

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    GIE_DISABLE,
    GIE_ENABLE
}GIE_interruptStatus;

typedef enum
{
    GIE_NO_ERRORS,
    GIE_STATUS_ERROR
}GIE_errorStatus;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : GIE_setInterruptStatus
 * [Description]   : Enable or disable the AVR Global Interrupt.
 * [Arguments]     : <a_status>      -> Indicates to the required status [Enable - Disable].
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Invalid Status Error.
 ====================================================================================================================*/
GIE_errorStatus GIE_setInterruptStatus(GIE_interruptStatus a_status);

#endif /* MCAL_GIE_INCLUDES_GIE_H_ */
