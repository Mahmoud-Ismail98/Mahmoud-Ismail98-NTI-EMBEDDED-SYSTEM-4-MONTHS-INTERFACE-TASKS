/*
 * Timers_prv.h
 *
 * Created: 10/24/2023 11:15:51 AM
 *  Author: Wael
 */
 /* Timer 0 */
#define TCNT0   (*(volatile unsigned char*)0x52)
#define TCCR0   (*(volatile unsigned char*)0x53)
/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

#define TWCR    (*(volatile unsigned char*)0x56)
#define SPMCR   (*(volatile unsigned char*)0x57)
#define TIFR    (*(volatile unsigned char*)0x58)
#define TIMSK   (*(volatile unsigned char*)0x59)
/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

#define OCR0    (*(volatile unsigned char*)0x5C)

#define TIMER0_OVF __vector_11

 /*TIMER 1*/

 #define ICR1         (*(volatile unsigned short*)0x46)
 #define ICR1L		  (*(volatile unsigned char*)0x46)
 #define ICR1H		  (*(volatile unsigned char*)0x47)
 #define OCR1B		  (*(volatile unsigned short*)0x48)
 #define OCR1BL		  (*(volatile unsigned char*)0x48)
 #define OCR1BH       (*(volatile unsigned char*)0x49)
 #define OCR1A        (*(volatile unsigned short*)0x4A)
 #define OCR1AL       (*(volatile unsigned char*)0x4A)
 #define OCR1AH       (*(volatile unsigned char*)0x4B)
 #define TCNT1        (*(volatile unsigned short*)0x4C)
 #define TCNT1L       (*(volatile unsigned char*)0x4C)
 #define TCNT1H       (*(volatile unsigned char*)0x4D)
 #define TCCR1B       (*(volatile unsigned char*)0x4E)
 #define TCCR1A       (*(volatile unsigned char*)0x4F)

 #define SFIOR       (*(volatile unsigned char*)0x50)

 #define OSCCAL       (*(volatile unsigned char*)0x51)
 
 /* TCCR1A */
 #define COM1A1  7
 #define COM1A0  6
 #define COM1B1  5
 #define COM1B0  4
 #define FOC1A   3
 #define FOC1B   2
 #define WGM11   1
 #define WGM10   0

 /* TCCR1B */
 #define ICNC1   7
 #define ICES1   6
 /* bit 5 reserved */
 #define WGM13   4
 #define WGM12   3
 #define CS12    2
 #define CS11    1
 #define CS10    0