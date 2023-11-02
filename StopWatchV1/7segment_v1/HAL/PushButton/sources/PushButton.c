/*
 * PushButton.c
 *
 * Created: 11/2/2023 12:12:19 PM
 *  Author: sharb
 */ 

#include "std_types.h"
#include "../includes/PushButton.h"


/*
NAME: PUSHBUTTON_vidGetState
DESC: read Button state and return it's value
ARGS: DIO_enu_PinId_t arg_enu_ButtonPin --> Button Pin
RET : PUSH_BUTTON_STATE_enu_t (LOGIC_HIGH,LOGIC_LOW)

*/
PUSH_BUTTON_STATE_enu_t PUSHBUTTON_vidGetState(DIO_enu_PinId_t arg_enu_ButtonPin)
{
	u8 loc_u8_pinLogic = FALSE; // loc to hold pin status
	DIO_enu_ReadChannel(arg_enu_ButtonPin,&loc_u8_pinLogic); // read pin value
	return loc_u8_pinLogic; // return value
}