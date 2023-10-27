/*
=======================================================================================================================
Author       : Mamoun
Module       : Watch-Dog Timer
File Name    : wdt.h
Date Created : Oct 27, 2023
Description  : Header file for the AVR Watch-Dog Timer driver.
=======================================================================================================================
*/


#ifndef MCAL_WDT_INCLUDES_WDT_H_
#define MCAL_WDT_INCLUDES_WDT_H_

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    WDT_NO_ERRORS,
    WDT_PRESCALER_ERROR
}WDT_errorStatus;

typedef enum
{
    WDT_16_3_MS,
    WDT_32_5_MS,
    WDT_65_0_MS,
    WDT_0_13_S,
    WDT_0_26_S,
    WDT_0_52_S,
    WDT_1_00_S,
    WDT_2_10_S,
}WDT_prescalerID;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : WDT_sleep
 * [Description]   : Enable the WDT with a specific prescaler to sleep a specific cycles.
 * [Arguments]     : <a_prescalerID>      -> Indicates to the required prescaler ID.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Prescaler Error.
 ====================================================================================================================*/
WDT_errorStatus WDT_sleep(WDT_prescalerID a_prescalerID);

/*=====================================================================================================================
 * [Function Name] : WDT_disable
 * [Description]   : Disable the WDT.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void WDT_disable(void);

#endif /* MCAL_WDT_INCLUDES_WDT_H_ */
