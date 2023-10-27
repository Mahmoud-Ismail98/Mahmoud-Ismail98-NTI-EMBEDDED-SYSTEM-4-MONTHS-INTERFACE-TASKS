/*
=======================================================================================================================
Author       : Mamoun
Module       : Watch-Dog Timer
File Name    : wdt.c
Date Created : Oct 27, 2023
Description  : Source file for the AVR Watch-Dog Timer driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../OTHERS/std_types.h"
#include "../../../OTHERS/common_macros.h"
#include "../INCLUDES/wdt_prv.h"
#include "../INCLUDES/wdt_cfg.h"
#include "../INCLUDES/wdt.h"
#include <avr/io.h>

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : WDT_sleep
 * [Description]   : Enable the WDT with a specific prescaler to sleep a specific cycles.
 * [Arguments]     : <a_prescalerID>      -> Indicates to the required prescaler ID.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Prescaler Error.
 ====================================================================================================================*/
WDT_errorStatus WDT_sleep(WDT_prescalerID a_prescalerID)
{
    WDT_errorStatus LOC_errorStatus = WDT_NO_ERRORS;

    if(a_prescalerID > WDT_2_10_S)
    {
        LOC_errorStatus = WDT_PRESCALER_ERROR;
    }

    else
    {
    	WDTCR = ((WDTCR & 0X07) | (a_prescalerID & 0XF8));                    /* Set the WDT prescaler value. */
        SET_BIT(WDTCR,WDE);                                         /* Enable the WDT by setting the WDE bit. */
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : WDT_disable
 * [Description]   : Disable the WDT.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void WDT_disable(void)
{
    /* WDT disabled by clear the WDE bit, but WDE bit cannot be cleared if WDTOE is cleared.               */
    /* So, you have to write the 2 bits at the same operatoin and then clear both.                         */

    WDTCR = ((0X03) << WDE);                              /* Set WDTOE and WDE bits at the same operation. */
    WDTCR = 0X00;                                               /* Clear WDTCR register to reset the WDT.  */
}
