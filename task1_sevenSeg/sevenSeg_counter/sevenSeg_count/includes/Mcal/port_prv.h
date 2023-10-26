/*
 * port_prv.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Ahmed Dwidar
 */



#ifndef PORT_PRV_H_
#define PORT_PRV_H_

#include"../Services/std_types.h"
#include"../Services/common_macros.h"

/*IMPORTANT MCROS*/
#define NUM_OF_PORTS                          3
#define NUM_OF_PINS_PER_PORT                  8
#define SIZE_OF_REGISTER                      8
#define NUM_OF_PINS                          31
#define NUM_OF_MODES                          3
#define NUM_OF_DIRECTION                      1

/*PORTS MCROS*/
#define PORT_PORTA                            0
#define PORT_PORTB                            1
#define PORT_PORTC                            2
#define PORT_PORTD                            3

/*ADDRESSES OF DDR,PORT REGISTERS*/
#define DDRA_R        ( *( (volatile u8*)0x3A) )
#define DDRB_R        ( *( (volatile u8*)0x37) )
#define DDRC_R        ( *( (volatile u8*)0x34) )
#define DDRD_R        ( *( (volatile u8*)0x31) )

#define PORTA_R       ( *( (volatile u8*)0x3B ))
#define PORTB_R       ( *( (volatile u8*)0x38) )
#define PORTC_R       ( *( (volatile u8*)0x35) )
#define PORTD_R       ( *( (volatile u8*)0x32) )

#define PINA_R       ( *( (volatile u8*)0x39 ))
#define PINB_R       ( *( (volatile u8*)0x36) )
#define PINC_R       ( *( (volatile u8*)0x33) )
#define PIND_R       ( *( (volatile u8*)0x30) )

#endif /* PORT_PRV_H_ */
