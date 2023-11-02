/*
 * Timer_priv.h
 *
 * Created: 10/29/2023 10:05:17 AM
 *  Author: 20101
 */ 


#ifndef TIMER_PRIV_H_
#define TIMER_PRIV_H_


#define TCCR0   *((volatile u8 *)0x53)

#define TCCR0_WGM00     6
#define TCCR0_WGM01     3
#define TCCR0_CS02      2
#define TCCR0_CS01      1
#define TCCR0_CS00      0




#define  TCCR1B     *((volatile u8 *)0x4E)       /*TImer1 Control RegisterB */

#define TCCR0_CS12      2
#define TCCR0_CS11      1
#define TCCR0_CS10      0


#define TCNT1  *((volatile u16 *)0x4C)   /* Timer 1 : Counter Register */
#define OCR0   *((volatile u8 *)0x5C)


#define TCNT0  *((volatile u16 *)0x52)   /* Timer 1 : Counter Register */

#define TIMSK *((volatile u8 *)0x59)
#define TIMSK_OCIE0      1
#define TIMSK_TOIE0      0






#endif /* TIMER_PRIV_H_ */