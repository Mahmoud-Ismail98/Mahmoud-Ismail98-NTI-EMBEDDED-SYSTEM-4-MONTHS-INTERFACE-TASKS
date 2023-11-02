/*
 * EXT_PRV.h
 *
 * Created: 10/21/2023 11:44:23 AM
 *  Author: FADY
 */
#ifndef EXT_PRV
#define EXT_PRV


#define MCUCR     *((volatile u8*)0x55)
#define MCUCSR    *((volatile u8*)0x54)
#define GICR      *((volatile u8*)0x5B)
#define GIFR      *((volatile u8*)0x5A)

/* MCUCR BITS */
#define MCUCR_ISC11        3
#define MCUCR_ISC10        2
#define MCUCR_ISC01        1
#define MCUCR_ISC00        0

/* MCUCSR BITS */
#define MCUCSR_ISC2        6

/* GICR BITS */
#define GICR_INT1          7
#define GICR_INT0          6
#define GICR_INT2          5


#define GIE_globalInterruptEnable 7
#endif