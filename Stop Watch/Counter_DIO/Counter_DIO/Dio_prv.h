/*
 * Dio_prv.h
 *
 *  Created on: Mar 4, 2022
 *      Author: MahmoudElImbabi
 */

#ifndef MCAL_DIO_DRIVER_DIO_PRV_H_
#define MCAL_DIO_DRIVER_DIO_PRV_H_

/*MACROS*/
#define DIO_u8NUMBER_OF_CHANNELS  	31

#define DIO_u8NUMBER_OF_LEVELS		2
#define DIO_u8REGISTER_SIZE			8

#define DIO_u8NUMBER_OF_PORTS		3



/* DIO_Registers */
#define DDRA (*(volatile unsigned char*)0x3A)
#define DDRB (*(volatile unsigned char*)0x37)
#define DDRC (*(volatile unsigned char*)0x34)
#define DDRD (*(volatile unsigned char*)0x31)

#define PINA (*(volatile unsigned char*)0x39)
#define PINB (*(volatile unsigned char*)0x36)
#define PINC (*(volatile unsigned char*)0x33)
#define PIND (*(volatile unsigned char*)0x30)

#define PORTA (*(volatile unsigned char*)0x3B)
#define PORTB (*(volatile unsigned char*)0x38)
#define PORTC (*(volatile unsigned char*)0x35)
#define PORTD (*(volatile unsigned char*)0x32)

#endif /* MCAL_DIO_DRIVER_DIO_PRV_H_ */
