/*
 * TImer1_priv.h
 *
 * Created: 10/30/2023 11:17:57 PM
 *  Author: 20101
 */ 


#ifndef TIMER1_PRIV_H_
#define TIMER1_PRIV_H_
#define TCCR0   *((volatile u8 *)0x53)

#define TCCR0_WGM00     6
#define TCCR0_WGM01     3
#define TCCR0_CS02      2
#define TCCR0_CS01      1
#define TCCR0_CS00      0



#define TCCR1A  *((volatile u8*)0x4F)
#define WGM10    0
#define WGM11    1
#define COM1A1    7 
#define COM1A0    6

#define TCCR1B  *((volatile u8*)0x4E)
#define WGM13   4
#define WGM12   3


#define TCNT1  *((volatile u16 *)0x4C)   /* Timer 1 : Counter Register */
#define OCR0   *((volatile u8 *)0x5C)


#define TIMSK *((volatile u8 *)0x59)

#define TIMSK_OCIE0      1
#define TIMSK_TICIE1     /* Input Capture Interrupt Enable */

#define ICR1  *((volatile u16*)0x46)
#define OCR1A  *((volatile u16*)0x4A)






#endif /* TIMER1_PRIV_H_ */