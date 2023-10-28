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




// timer 2 registers 
/*Timer/Counter Control Register*/
#define TCCR2           *((volatile u8*) 0x45)

/*Timer/Counter Register – TCNT0*/
#define TCNT2           *((volatile u8*) 0x44)

/*Output Compare Register */
#define OCR2            *((volatile u8*) 0x43)

/*Asynchronous Status Register*/
#define ASSR            *((volatile u8*) 0x42)


/* common registers for 3 timers */
/*Timer/Counter Interrupt Mask Register*/
#define TIMSK           *((volatile u8*) 0x59)

/*Timer/Counter Interrupt Flag Register*/
#define TIFR            *((volatile u8*) 0x58)
