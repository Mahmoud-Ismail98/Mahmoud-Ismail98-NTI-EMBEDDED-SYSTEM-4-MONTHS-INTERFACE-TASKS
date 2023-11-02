/*
 * EXTI_Private.h
 *
 * Created: 10/22/2023 3:42:47 PM
 *  Author: Mohamed Alaa
 */ 


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#include <Services/Std_types.h>
#include <MCAL/PORT/PORT_Includes/Port.h>

#define MCUCR_REG				(*(volatile Puint8)0x55)
#define MCUCSR_REG				(*(volatile Puint8)0x54)
#define GICR_REG				(*(volatile Puint8)0x5B)

//MCUCR_REG bits
#define  ISC00					0
#define  ISC10					2

//MCUCSR_REG bits
#define  ISC2					6

//GICR_REG bits
#define  INT2					5
#define  INT0					6
#define  INT1					7


#endif /* EXTI_PRIVATE_H_ */