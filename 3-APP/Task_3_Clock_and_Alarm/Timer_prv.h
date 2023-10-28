/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : Timer               **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

// timer 0 registers 

/*Timer/Counter Control Register*/
#define TCCR0           *((volatile u8*) 0x53)

/*Timer/Counter Register – TCNT0*/
#define TCNT0           *((volatile u8*) 0x52)

/*Output Compare Register */
#define OCR0            *((volatile u8*) 0x5C)

/*Timer/Counter Interrupt Mask Register*/
#define TIMSK           *((volatile u8*) 0x59)

/*Timer/Counter Interrupt Flag Register*/
#define TIFR            *((volatile u8*) 0x58)
