/*
 * Port_prv.h
 *
 *  Created on: Mar 4, 2022
 *      Author: MahmoudElImbabi
 */

#ifndef MCAL_PORT_DRIVER_PORT_PRV_H_
#define MCAL_PORT_DRIVER_PORT_PRV_H_



/*MACROS*/
#define PORT_u8NUMBER_OF_PINS 				31
#define PORT_u8NUMBER_OF_DIRECTION 			1
#define PORT_u8REGISTER_SIZE 				8
#define PORT_u8PORTA 						0
#define PORT_u8PORTB					    1
#define PORT_u8PORTC 						2
#define PORT_u8PORTD					    3


/* DIO_Registers */
#define DDRA (*(volatile unsigned char*)0x3A)
#define DDRB (*(volatile unsigned char*)0x37)
#define DDRC (*(volatile unsigned char*)0x34)
#define DDRD (*(volatile unsigned char*)0x31)

#define PINA (*(const volatile unsigned char*)0x39)
#define PINAA (*(volatile unsigned char*)0x39)
#define PINB (*(volatile unsigned char*)0x36)
#define PINC (*(volatile unsigned char*)0x33)
#define PIND (*(volatile unsigned char*)0x30)

#define PORTA (*(volatile unsigned char*)0x3B)
#define PORTB (*(volatile unsigned char*)0x38)
#define PORTC (*(volatile unsigned char*)0x35)
#define PORTD (*(volatile unsigned char*)0x32)

#endif /* MCAL_PORT_DRIVER_PORT_PRV_H_ */
