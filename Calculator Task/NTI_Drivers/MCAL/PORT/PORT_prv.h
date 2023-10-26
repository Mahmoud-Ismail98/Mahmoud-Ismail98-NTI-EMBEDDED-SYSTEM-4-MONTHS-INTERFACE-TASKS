/*
 * PORT_prv.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Ismail
 */

#ifndef MCAL_PORT_PORT_PRV_H_
#define MCAL_PORT_PORT_PRV_H_

/*USEFUL MACROS DURING IMPLEMNTATION &CAN BE REPLACED WITH enum of the same concept */
#define PORT_u8PORTA 						0
#define PORT_u8PORTB					    1
#define PORT_u8PORTC 						2
#define PORT_u8PORTD					    3
#define PORT_u8TOTALNUMBER_OF_PINS 			31
#define PORT_u8NUMBER_OF_DIRECTION 			1
#define PORT_u8REGISTER_SIZE 				8
/*PORT MEMORY ADRESSES FOR ATMEGA32, Data sheet page '299' */
#define PORTA_Address	(0x3B)
#define DDRA_Address	(0x3A)
#define PINA_Address	(0x39)

#define PORTB_Address	(0x38)
#define DDRB_Address	(0x37)
#define PINB_Address	(0x36)

#define PORTC_Address	(0x35)
#define DDRC_Address	(0x34)
#define PINC_Address	(0x33)

#define PORTD_Address	(0x32)
#define DDRD_Address	(0x31)
#define PIND_Address	(0x30)

/*PORTA,PINA And DDRA*/
#define PORTA 	*((volatile u8*)PORTA_Address)
#define DDRA 	*((volatile u8*)DDRA_Address)
#define PINA 	*((volatile u8*)PINA_Address)

/*PORTB,PINB And DDRB*/
#define PORTB 	*((volatile u8*)PORTB_Address)
#define DDRB 	*((volatile u8*)DDRB_Address)
#define PINB 	*((volatile u8*)PINB_Address)

/*PORTC,PINC And DDRC*/
#define PORTC 	*((volatile u8*)PORTC_Address)
#define DDRC 	*((volatile u8*)DDRC_Address)
#define PINC 	*((volatile u8*)PINC_Address)

/*PORTD,PIND And DDRD*/
#define PORTD 	*((volatile u8*)PORTD_Address)
#define DDRD 	*((volatile u8*)DDRD_Address)
#define PIND 	*((volatile u8*)PIND_Address)


#endif /* MCAL_PORT_PORT_PRV_H_ */
