/*
=======================================================================================================================
Author       : Mamoun
Module       : Global Interrupt
File Name    : gie.c
Date Created : Oct 22, 2023
Description  : Source file for the AVR Global Interrupt driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../OTHERS/common_macros.h"
#include "../../../OTHERS/std_types.h"
#include "../INCLUDES/gie_prv.h"
#include "../INCLUDES/gie_cfg.h"
#include "../INCLUDES/gie.h"
#include <avr/io.h>

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : GIE_setInterruptStatus
 * [Description]   : Enable or disable the AVR Global Interrupt.
 * [Arguments]     : <a_status>      -> Indicates to the required status [Enable - Disable].
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Invalid Status Error.
 ====================================================================================================================*/
GIE_errorStatus GIE_setInterruptStatus(GIE_interruptStatus a_status)
{
    GIE_errorStatus LOC_errorStatus = GIE_NO_ERRORS;

    if((a_status != GIE_DISABLE) && (a_status != GIE_ENABLE))
    {
        LOC_errorStatus = GIE_STATUS_ERROR;
    }

    else
    {
        WRITE_BIT(SREG,GIE_BIT_ID,a_status);
    }

    return LOC_errorStatus;
}