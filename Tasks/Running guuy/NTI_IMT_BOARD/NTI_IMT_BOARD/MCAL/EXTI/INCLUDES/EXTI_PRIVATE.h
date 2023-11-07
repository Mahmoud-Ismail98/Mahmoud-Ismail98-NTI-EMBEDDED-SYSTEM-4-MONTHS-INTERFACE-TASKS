/*
 * EXTI_PRIVATE.h
 *
 * Created: 10/22/2023 3:29:51 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define GICR    (*((volatile pu8)0x5B))  /*General Interrupt Control Register*/
#define GICR_INT2   5					/*INT2 Enable bit*/
#define GICR_INT0   6					 /*INT0 Enable bit*/
#define GICR_INT1   7					/*INT1 Enable bit*/

#define GIFR     (*((volatile pu8)0x5A)) /*General Interrupt Flag Register*/
#define GIFR_INTF2  5						/*INT2 Flag bit*/
#define GIFR_INTF0  6						/*INT0 Flag bit*/
#define GIFR_INTF1  7						/*INT1 Flag bit*/

#define MCUCR   (*((volatile pu8)0x55))   /*MCU CONTROL REGISTER*/
#define MCUCR_ISC00  0					  /*INT0 SENSE CONTROL BIT 0*/
#define MCUCR_ISC01  1					  /*INT0 SENSE CONTROL BIT 1*/
#define MCUCR_ISC10  2					  /*INT1 SENSE CONTROL BIT 0*/
#define MCUCR_ISC11  3				      /*INT1 SENSE CONTROL BIT 1*/

#define MCUCSR  (*((volatile pu8)0x54))  /*MCU CONTROL AND STATUS REGISTER*/
#define MCUCSR_ISC2   6					 /*INT2 SENSE CONTROL BIT*/




#endif /* EXTI_PRIVATE_H_ */