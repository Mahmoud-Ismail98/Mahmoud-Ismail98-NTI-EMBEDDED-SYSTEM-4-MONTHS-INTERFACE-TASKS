/*
=======================================================================================================================
Author       : Mamoun
Module       : Button
File Name    : button.c
Date Created : Oct 26, 2023
Description  : Source file for the Mechanical Button driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../OTHERS/std_types.h"
#include "../../../OTHERS/common_macros.h"
#include "../../../MCAL/DIO/INCLUDES/dio.h"
#include "../INCLUDES/button_prv.h"
#include "../INCLUDES/button_cfg.h"
#include "../INCLUDES/button.h"

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : BUTTON_readButtonState
 * [Description]   : Read the status of a specific button [Pressed - Not Pressed].
 * [Arguments]     : <a_portID>          -> Indicates to the button port ID.
 *                   <a_pinID>           -> Indicates to the button pin ID.
 *                   <a_connectionType>  -> Indicates to the type of connection [Pull-up - Pull-down].
 *                   <a_ptr2buttonState> -> Pointer to variable to store the button status.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port ID Error.
 *                                                          - Pin ID Error.
 *                                                          - Connection Type Error.
 ====================================================================================================================*/
BUTTON_errorStatus BUTTON_readButtonState(uint8 a_portID, uint8 a_pinID, BUTTON_connectionType a_connectionType, BUTTON_buttonStatus* a_ptr2buttonState)
{
    BUTTON_errorStatus LOC_errorStatus = BUTTON_NO_ERRORS;
    DIO_pinStatus LOC_buttonPinStatus = DIO_LOW_PIN;

    if(a_portID >= DIO_NUM_OF_PORTS)
    {
        LOC_errorStatus = BUTTON_PORT_ID_ERROR;
    }

    else if(a_pinID >= DIO_NUM_OF_PINS_PER_PORT)
    {
        LOC_errorStatus = BUTTON_PIN_ID_ERROR;
    }

    else if((a_connectionType != BUTTON_PULLUP_CONNECTION) && (a_connectionType != BUTTON_PULLDOWN_CONNECTION))
    {
        LOC_errorStatus = BUTTON_CONNECTION_TYPE_ERROR;
    }

    else
    {
        DIO_readPin(a_portID,a_pinID,&LOC_buttonPinStatus);

        switch (a_connectionType)
        {
        case BUTTON_PULLUP_CONNECTION:
            switch (LOC_buttonPinStatus)
            {
            case DIO_HIGH_PIN:
                *a_ptr2buttonState = BUTTON_NOT_PRESSED;
                break;
            
            case DIO_LOW_PIN:
                *a_ptr2buttonState = BUTTON_PRESSED;
                break;
            
            default:
                /* Do Nothing. */
                break;
            }
            break;

        case BUTTON_PULLDOWN_CONNECTION:
            switch (LOC_buttonPinStatus)
            {
            case DIO_HIGH_PIN:
                *a_ptr2buttonState = BUTTON_PRESSED;
                break;
            
            case DIO_LOW_PIN:
                *a_ptr2buttonState = BUTTON_NOT_PRESSED;
                break;
            
            default:
                /* Do Nothing. */
                break;
            }
            break;

        default:
            /* Do Nothing. */
            break;
        }
    }

    return LOC_errorStatus;
}