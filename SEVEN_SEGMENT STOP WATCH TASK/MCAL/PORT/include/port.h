#ifndef PORT_PORT_H_
#define PORT_PORT_H_



/*PORT init initialize all pin directon firstly in code*/
void Port_Init(void); 

/*set pin direction mode */
PIN_ERROR_TYPES Port_setPinDirection(u8 Pin_id,u8 pin_direction);

/* SET PIN mode Ddepending on direction */
PIN_ERROR_TYPES Port_SetPinMode(u8 Pin_id,u8 Pin_mode);


#endif