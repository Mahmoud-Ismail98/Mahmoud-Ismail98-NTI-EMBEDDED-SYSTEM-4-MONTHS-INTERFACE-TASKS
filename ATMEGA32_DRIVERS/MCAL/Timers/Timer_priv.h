#ifndef TIMER_PRIV_H_
#define TIMER_PRIV_H_

#define TCCR0 *(volatile u8 * ) 0x53
#define FOC0 7
#define WGM00 6
#define COM01 5
#define COM00 4
#define WGM01 3
#define CS02 2
#define CS01 1
#define CS00 0

#define TCNT0 *(volatile u8 *) 0x52

#define OCR0 *(volatile u8 *) 0x5C

#define TIMSK *(volatile u8 *) 0x59
#define OCIE0 1
#define TOIE0 0
#define TIMSK_TICIE1                  /* Input Capture Interrupt Enable */

#define TIFR *(volatile u8 *) 0x58
#define OCF0 1
#define TOV0 0

#define SFIOR *(volatile u8 *) 0x50
#define PSR10 0


#define  TCCR1B     *((volatile u8 *)0x4E) /* TImer1 Control RegisterB */

#define TCCR0_CS12      2
#define TCCR0_CS11      1
#define TCCR0_CS10      0

#define TCNT1  *((volatile u16 *)0x4C)   /* Timer 1 : Counter Register */


#define ICR1 *((volatile u16 *)0x46)       




#define WDTCR   *((volatile u8 *)0x41)
#define WDTCR_WDTOE   4    
#define WDTCR_WDE     3 





#endif