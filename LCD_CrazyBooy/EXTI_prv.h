#ifndef EXTI_PRV_H_
#define EXTI_PRV_H_


#define MCUCR		*((volatile u8*)0x55)
#define MCUCSR		*((volatile u8*)0x54)

#define GICR		*((volatile u8*)0x5B)
#define GIFR        *((volatile u8*)0x5A)

#define	INT1	7
#define	INT0	6
#define	INT2	5

#define	ISC2	5

/* number 1 for external interrupt 0 in vector table */ 
void __vector_1 (void) __attribute__((signal)); 

/* number 2 for external interrupt 1 in vector table */ 
void __vector_2 (void) __attribute__((signal));

/* number 3 for external interrupt 2 in vector table */ 
void __vector_3 (void) __attribute__((signal));

#endif