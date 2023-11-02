/*
 * MEXIT_Private.h
 *
 *  Created on: Oct 21, 2022
 *      Author: Ismail
 */

#ifndef MCAL_EXIT_EXIT_PRV_H_
#define MCAL_EXIT_EXIT_PRV_H_




#define MCUCR *((volatile u8*)(0x55))
#define MCUCSR *((volatile u8*)(0x54))
#define GICR *((volatile u8*)(0x5B))
#define GIFR *((volatile u8*)(0x5A))

/* EXTERNAL INTERRUPT 0 BITS*/
#define GICR_INT0_BIT	6
#define MCUCR_ISC00_BIT	0
#define MCUCR_ISC01_BIT	1
#define GIFR_INTF0_BIT	6

/* EXTERNAL INTERRUPT 1 BITS*/
#define GICR_INT1_BIT	7
#define MCUCR_ISC10_BIT	2
#define MCUCR_ISC11_BIT	3
#define GIFR_INTF1_BIT	7

/* EXTERNAL INTERRUPT 2 BITS*/
#define GICR_INT2_BIT	5
#define MCUCSR_ISC2_BIT	2
#define GIFR_INTF2_BIT	5




#endif /* MCAL_MEXIT_MEXIT_PRIVATE_H_ */
