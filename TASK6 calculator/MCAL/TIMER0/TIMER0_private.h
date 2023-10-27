/*
 * private.h
 *
 * Created: 24/10/2023 02:12:00 م
 *  Author: mkora
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_


/*
 * private.h
 *
 * Created: 24/10/2023 02:12:00 م
 *  Author: mkora
 */ 


#ifndef PRIVATE_H_
#define PRIVATE_H_




#define TCCR0		(*(volatile u8*)0x53)
#define TCNT0		(*(volatile u8*)0x52)
#define OCR0        (*(volatile u8*)0x5c)
#define TIMSK       (*(volatile u8*)0x59)
#define TIFR        (*(volatile u8*)0x58)

#define    NORMAL_MODE      			                            0
#define    PWM_OR_PHASE_COTROL                                      1
#define    CTC_MODE                                                 2
#define    FAST_PWM_MODE                                            3

#define	  TIMER_COUNTER_DISABLED             0
#define	   NORMAL_CLK				        1
#define	   CLK_DIV_BY_8				        2
#define	   CLK_DIV_BY_64                    3
#define	   CLK_DIV_BY_256                   4
#define	   CLK_DIV_BY_1024                  5
#define	   ECS_ON_T0_FALLING_EDGE           6
#define	   ECS_ON_T0_RISING_EDGE            7
#define	   ECS_ON_T1_FALLING_EDGE           8
#define	   ECS_ON_T1_RISING_EDGE            9

#define  TIMER0_MODE NORMAL_MODE
#define timer0_prescaler CLK_DIV_BY_1024

#endif /* PRIVATE_H_ */


#endif /* PRIVATE_H_ */