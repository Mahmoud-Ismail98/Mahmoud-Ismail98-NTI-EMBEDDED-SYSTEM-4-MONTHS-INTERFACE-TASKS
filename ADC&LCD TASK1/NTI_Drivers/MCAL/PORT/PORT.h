/*
 * PORT.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Ismail
 */

#ifndef MCAL_PORT_PORT_H_
#define MCAL_PORT_PORT_H_


#include"../../Services/Bit_utils.h"
#include"../../Services/Std_types.h"
                  //EACH PORT HAS 8 CONFIGURABLE PINS//
	/*PORTA PINS*/
#define PORT_u8PIN0            0
#define PORT_u8PIN1            1
#define PORT_u8PIN2            2
#define PORT_u8PIN3            3
#define PORT_u8PIN4            4
#define PORT_u8PIN5            5
#define PORT_u8PIN6            6
#define PORT_u8PIN7            7
	/*PORTB PINS*/
#define PORT_u8PIN8            8
#define PORT_u8PIN9            9
#define PORT_u8PIN10           10
#define PORT_u8PIN11           11
#define PORT_u8PIN12           12
#define PORT_u8PIN13           13
#define PORT_u8PIN14           14
#define PORT_u8PIN15           15

	/*PORTC PINS*/
#define PORT_u8PIN16            16
#define PORT_u8PIN17            17
#define PORT_u8PIN18            18
#define PORT_u8PIN19            19
#define PORT_u8PIN20            20
#define PORT_u8PIN21            21
#define PORT_u8PIN22            22
#define PORT_u8PIN23            23

	/*PORTD PINS*/
#define PORT_u8PIN24            24
#define PORT_u8PIN25            25
#define PORT_u8PIN26            26
#define PORT_u8PIN27            27
#define PORT_u8PIN28            28
#define PORT_u8PIN29            29
#define PORT_u8PIN30            30
#define PORT_u8PIN31            31


/*PIN DIRECTIONS*/
#define PORT_u8INPUT 			0
#define PORT_u8OUTPUT 			1

/*PORT OPTIONS*/
#define PORT_u8OUTPUT_LOW 		0
#define PORT_u8OUTPUT_HIGH 		1
#define PORT_u8INPUT_FLOATING 	2
#define PORT_u8INPUT_PULLUP 	3

/*ERROR STATE ENUMS FOR RETURN*/
typedef enum{

	Ok,
	PinError,
	ModeError

}Port_EnumErrorStatus;


/*FUNCTIONS PROTOTYPES*/
void Port_Init(void);
Port_EnumErrorStatus Port_enuSetPinDirection(u8 Copy_u8PinNum , u8 Copy_u8PinDirection);
Port_EnumErrorStatus Port_enuSetPinMode(u8 Copy_u8PinNum , u8 Copy_u8PinDirection);


#endif /* MCAL_PORT_PORT_H_ */
