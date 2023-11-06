#ifndef DIO_PRV_H_
#define DIO_PRV_H_

/*******************************************************************/
/************************* PORTS ADDRSESS **************************/
#define PORTA        *((volatile u8*)0x3B)
#define PORTB        *((volatile u8*)0x38)
#define PORTC        *((volatile u8*)0x35)
#define PORTD        *((volatile u8*)0x32)

/*******************************************************************/
/************************* PINS ADDRSESS **************************/
#define PINA        *((volatile u8*)0x39)
#define PINB        *((volatile u8*)0x36)
#define PINC        *((volatile u8*)0x33)
#define PIND        *((volatile u8*)0x30)

/*******************************************************************/
/************************* DDRS ADDRSESS **************************/
#define DDRA        *((volatile u8*)0x3A)
#define DDRB        *((volatile u8*)0x37)
#define DDRC        *((volatile u8*)0x34)
#define DDRD        *((volatile u8*)0x31)


/*******************************************************************/
/******************************************************************/

#define PORTA_REG                      0
#define PORTB_REG                      1
#define PORTC_REG                      2
#define PORTD_REG                      3

#define RIGESTER_SIZE                  8
#define NUMBER_CHANNALS                32
#define NUMBER_PORTS                   4

















#endif
