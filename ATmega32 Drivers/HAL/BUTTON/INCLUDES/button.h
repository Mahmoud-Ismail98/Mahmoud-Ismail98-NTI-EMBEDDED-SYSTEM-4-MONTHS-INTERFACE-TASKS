/*
=======================================================================================================================
Author       : Mamoun
Module       : Button
File Name    : button.h
Date Created : Oct 26, 2023
Description  : Header file for the Mechanical Button driver.
=======================================================================================================================
*/


#ifndef HAL_BUTTON_INCLUDES_BUTTON_H_
#define HAL_BUTTON_INCLUDES_BUTTON_H_

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    BUTTON_NO_ERRORS,
    BUTTON_PORT_ID_ERROR,
    BUTTON_PIN_ID_ERROR,
    BUTTON_CONNECTION_TYPE_ERROR
}BUTTON_errorStatus;

typedef enum
{
    BUTTON_PULLUP_CONNECTION,
    BUTTON_PULLDOWN_CONNECTION
}BUTTON_connectionType;

typedef enum
{
    BUTTON_NOT_PRESSED,
    BUTTON_PRESSED
}BUTTON_buttonStatus;

/*=====================================================================================================================
                                         < Functions Prototypes >
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
BUTTON_errorStatus BUTTON_readButtonState(uint8 a_portID, uint8 a_pinID, BUTTON_connectionType a_connectionType, BUTTON_buttonStatus* a_ptr2buttonState);

#endif /* HAL_BUTTON_INCLUDES_BUTTON_H_ */
