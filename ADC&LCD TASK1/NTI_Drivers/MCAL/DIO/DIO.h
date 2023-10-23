/*
 * DIO.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Ismail
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_
#include"../../Services/Bit_utils.h"
#include"../../Services/Std_types.h"
/*pin macros for each port */
/*PORTA*/
#define DIO_u8PIN0            0
#define DIO_u8PIN1            1
#define DIO_u8PIN2            2
#define DIO_u8PIN3            3
#define DIO_u8PIN4            4
#define DIO_u8PIN5            5
#define DIO_u8PIN6            6
#define DIO_u8PIN7            7
/*PORTB*/
#define DIO_u8PIN8            8
#define DIO_u8PIN9            9
#define DIO_u8PIN10           10
#define DIO_u8PIN11           11
#define DIO_u8PIN12           12
#define DIO_u8PIN13           13
#define DIO_u8PIN14           14
#define DIO_u8PIN15           15
/*PORTC*/
#define DIO_u8PIN16           16
#define DIO_u8PIN17           17
#define DIO_u8PIN18           18
#define DIO_u8PIN19           19
#define DIO_u8PIN20           20
#define DIO_u8PIN21           21
#define DIO_u8PIN22           22
#define DIO_u8PIN23           23
/*PORTD*/
#define DIO_u8PIN24           24
#define DIO_u8PIN25           25
#define DIO_u8PIN26           26
#define DIO_u8PIN27           27
#define DIO_u8PIN28           28
#define DIO_u8PIN29           29
#define DIO_u8PIN30           30
#define DIO_u8PIN31           31

/*DIO PIN STATE*/
#define DIO_u8LEVEL_HIGH 	1
#define DIO_u8LEVEL_LOW 	0

/*Enum for the error state*/
typedef enum {
Dio_Ok,
Dio_ChannelError,
Dio_LevelError,
Dio_DirectionError,
Dio_NullPointerError,
Dio_PortRangeError
}Dio_EnumErrorState;

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


/*Macros for DIO*/

#define DIO_u8MAXNUMBER_OF_PINS 31 // WE START FROM '0' TILL '31'
#define	DIO_u8PORTA 			0
#define	DIO_u8PORTB 			1
#define	DIO_u8PORTC 			2
#define	DIO_u8PORTD 			3
#define DIO_u8MAXNUMBER_OF_LEVELS	1 //lEVEL IS THE STATE WETHER HIGH OR LOW
#define DIO_u8REGISTER_SIZE		8
#define DIO_u8OUTPUT			1 //because the high state for dio is '1'
#define DIO_u8INPUT				0  //because the low state for dio is '0'
#define DIO_u8MAXNUMBER_OF_PORTS	3 // WE START FROM '0' TO '3'


/*Functions PROTOTYPES*/
Dio_EnumErrorState  Dio_enuWriteChannel(u8 Copy_u8ChannelId , u8 Copy_u8Level);
Dio_EnumErrorState  Dio_enuReadChannel(u8 Copy_u8ChannelId , pu8 Add_pu8ChannelLevel);
Dio_EnumErrorState  Dio_enuWritePort(u8 Copy_u8PortId , u8 Copy_u8Value);
Dio_EnumErrorState  Dio_enuReadPort(u8 Copy_u8PortId , pu8 Add_pu8PortValue);
Dio_EnumErrorState  Dio_enuFlipChannel(u8 Copy_u8ChannelId );
Dio_EnumErrorState  DIO_SetNibbleValue(u8 Copy_u8PinStart,u8 Copy_u8PortNumber,u8 Copy_u8Value);

#endif /* MCAL_DIO_DIO_H_ */
