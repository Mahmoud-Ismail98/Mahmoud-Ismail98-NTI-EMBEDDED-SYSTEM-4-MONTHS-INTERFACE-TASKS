/*
 * EXTI_prv.h
 *
 * Created: 10/22/2023 9:29:51 AM
 *  Author: Wael
 */ 

#ifndef EXTI_PRV_H_
#define EXTI_PRV_H_


#define EXTI_MCUCSR   (*(volatile u8*)0x54)
#define ISC2 6

#define EXTI_MCUCR   	  (*(volatile u8*)0x55)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define EXTI_GICR     (*(volatile u8*)0x5B)
#define INT1 7
#define INT0 6
#define INT2 5


#define EXTI_GIFR    (*(volatile u8*)0x5A)
#define INTF1 7
#define INTF0 6
#define INTF2 5


#define EXTI_INT0 0
#define EXTI_INT1 1
#define EXTI_INT2 2

#define EXTI_FALLING    0
#define EXTI_RISING     1
#define EXTI_LOW        2
#define EXTI_ONCHANGE   3

/* External Interrupt Request 0 */
#define EXTI_INT0_vect			__vector_1
/* External Interrupt Request 1 */
#define EXTI_INT1_vect			__vector_2
/* External Interrupt Request 2 */
#define EXTI_INT2_vect			__vector_3




#endif