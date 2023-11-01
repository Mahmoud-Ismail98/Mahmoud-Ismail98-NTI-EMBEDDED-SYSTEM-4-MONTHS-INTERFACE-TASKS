/*
 * DIO_prv.h
 *
 * Created: 10/20/2023 11:59:46 AM
 *  Author: FADY
 */ 


#ifndef DIO_PRV_H_
#define DIO_PRV_H_


/* PORT A Registers */
#define DIO_PORTA_Reg  *((volatile u8*)0x3B)
#define DIO_DDRA_Reg   *((volatile u8*)0x3A)
#define DIO_PINA_Reg   *((volatile u8*)0x39)

/* PORT B Registers */
#define DIO_PORTB_Reg   *((volatile u8*)0x38)
#define DIO_DDRB_Reg   *((volatile u8*)0x37)
#define DIO_PINB_Reg   *((volatile u8*)0x36)

/* PORT C Registers */
#define DIO_PORTC_Reg   *((volatile u8*)0x35)
#define DIO_DDRC_Reg   *((volatile u8*)0x34)
#define DIO_PINC_Reg   *((volatile u8*)0x33)

/* PORT D Registers */
#define DIO_PORTD_Reg  *((volatile u8*)0x32)
#define DIO_DDRD_Reg   *((volatile u8*)0x31)
#define DIO_PIND_Reg   *((volatile u8*)0x30)





#endif /* DIO_PRV_H_ */
