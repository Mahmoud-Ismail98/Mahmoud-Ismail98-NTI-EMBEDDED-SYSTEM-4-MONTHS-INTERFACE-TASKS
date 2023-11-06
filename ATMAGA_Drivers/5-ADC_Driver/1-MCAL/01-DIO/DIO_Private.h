/********************************************/
/******** By: Aya Moneam   *****************/
/******** Date : Oct 22/10  *****************/
/******** Version: V1.0     *****************/
/******** ***********************************/
#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_

/*This file related to Atmega32 controller*/
  /* Direction Control */
#define         DDRA            *((volatile u8 *)0x3A)
#define			DDRB            *((volatile u8 *)0x37)
#define			DDRC            *((volatile u8 *)0x34)
#define			DDRD            *((volatile u8 *)0x31)
  /* Value Control */           
#define         PORTA           *((volatile u8 *)0x3B)
#define			PORTB           *((volatile u8 *)0x38)
#define			PORTC           *((volatile u8 *)0x35)
#define			PORTD           *((volatile u8 *)0x32)
								
  /* Value Receiving */         
#define         PINA            *((volatile u8 *)0x39)
#define			PINB            *((volatile u8 *)0x36)
#define			PINC            *((volatile u8 *)0x33)
#define			PIND            *((volatile u8 *)0x30)

#endif
