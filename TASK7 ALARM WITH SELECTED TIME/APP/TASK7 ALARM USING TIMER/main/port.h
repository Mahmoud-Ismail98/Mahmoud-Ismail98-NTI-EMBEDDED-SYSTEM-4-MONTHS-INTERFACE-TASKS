#ifndef PORT_PORT_H_
#define PORT_PORT_H_
#include "Std_types.h"
#define PIN_OUTPUT  1
#define PIN_INPUT   0

typedef enum {
	OK,
	PIN_DIR_ERROR,
	PIN_MODE_ERROR
}ERROR_TYPES;

void Port_Init(void);
ERROR_TYPES Port_setPinDirection(u8 Pin_id,u8 pin_direction);
ERROR_TYPES Port_SetPinMode(u8 Pin_id,u8 Pin_mode);


#endif