#ifndef DIO_H_
#define DIO_H_

typedef enum {
	NO_ERROR,
	PIN_DIRECTION_ERROR,
	PIN_MOD_ERROR,
	PORT_ERROR
}DIO_ERROR_TYPES;

DIO_ERROR_TYPES DIO_WritrPin(u8 pin_id,u8 level_value);
DIO_ERROR_TYPES  DIO_READ_PIN(u8 pin_id,u8 *ptr_val);
DIO_ERROR_TYPES  DIO_WritePort(u8 port_num,u8 port_value);
DIO_ERROR_TYPES  DIO_ReadPort(u8 port_num,u8 *ptr_val);


#endif