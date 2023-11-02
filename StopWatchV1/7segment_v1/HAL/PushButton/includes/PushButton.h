/*
 * PushButton.h
 *
 * Created: 11/2/2023 12:11:39 PM
 *  Author: sharb
 */ 


#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_

#include "../../../MCAL/DIO/includes/Dio.h"



// enum To hold Button state
typedef enum
{
	BUTTON_LOGIC_LOW,
	BUTTON_LOGIC_HIGH,
	BUTTON_LOGIC_MAX,
	
}PUSH_BUTTON_STATE_enu_t;


/*
NAME: PUSHBUTTON_vidGetState
DESC: read Button state and return it's value
ARGS: DIO_enu_PinId_t arg_enu_ButtonPin --> Button Pin
RET : PUSH_BUTTON_STATE_enu_t (LOGIC_HIGH,LOGIC_LOW)

*/

PUSH_BUTTON_STATE_enu_t PUSHBUTTON_vidGetState(DIO_enu_PinId_t arg_enu_ButtonPin);

#endif /* PUSHBUTTON_H_ */