/*
 * dio_prv.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef DIO_PRV_H_
#define DIO_PRV_H_

#include"../Services/std_types.h"
#include"../Services/common_macros.h"

/*LIST OF OPTIONS TO THE USER TO SET DIRECTION*/
#define PORT_INPUT               0
#define PORT_OUTPUT              1

/*IMPORTANT MCROS*/
#define NUM_OF_PORTS                          3
#define NUM_OF_PINS_PER_PORT                  8
#define SIZE_OF_REGISTER                      8
#define NUM_OF_PINS                          31
#define NUM_OF_LEVELS                         1
#define NUM_OF_DIRECTION                      1

/*ADDRESSES OF DDR,PORT REGISTERS
#define DDRA        ( *( (volatile u8*)0x3A) )
#define DDRB        ( *( (volatile u8*)0x37) )
#define DDRC        ( *( (volatile u8*)0x34) )
#define DDRD        ( *( (volatile u8*)0x31) )

#define PORTA       ( *( (volatile u8*)0x3B ))
#define PORTB       ( *( (volatile u8*)0x38) )
#define PORTC       ( *( (volatile u8*)0x35) )
#define PORTD       ( *( (volatile u8*)0x32) )

#define PINA       ( *( (volatile u8*)0x39 ))
#define PINB       ( *( (volatile u8*)0x36) )
#define PINC       ( *( (volatile u8*)0x33) )
#define PIND       ( *( (volatile u8*)0x30) )
*/
#endif /* DIO_PRV_H_ */
