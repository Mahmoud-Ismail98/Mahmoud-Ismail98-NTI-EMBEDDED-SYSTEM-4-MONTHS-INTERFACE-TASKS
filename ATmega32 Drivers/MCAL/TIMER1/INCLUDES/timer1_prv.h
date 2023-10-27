/*
=======================================================================================================================
Author       : Mamoun
Module       : Timer-1
File Name    : timer1_prv.h
Date Created : Oct 27, 2023
Description  : Private file for the ATmega32 Timer-1 driver.
=======================================================================================================================
*/


#ifndef MCAL_TIMER1_INCLUDES_TIMER1_PRV_H_
#define MCAL_TIMER1_INCLUDES_TIMER1_PRV_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

#define TIMER1_NUM_OF_INTERRUPT_MODES            (2U)
#define TIMER1_OVF_INTERRUPT_ID                  (0U)
#define TIMER1_CTC_INTERRUPT_ID                  (1U)

#define TIMER1_OVERFLOW_VALUE                    (65536UL)

/*=====================================================================================================================
                                         < Function-like Macros >
=====================================================================================================================*/

#define TIMER1_SET_CHANNEL_A_PWM_STATE(STATE)       (TCCR1A = ((TCCR1A & 0XF7) | ((!(STATE & 0X01)) << FOC1A)))
#define TIMER1_SET_CHANNEL_B_PWM_STATE(STATE)       (TCCR1A = ((TCCR1A & 0XFB) | ((!(STATE & 0X01)) << FOC1B)))
#define TIMER1_SET_CHANNEL_A_OUTPUT_MODE(MODE)      (TCCR1A = ((TCCR1A & 0X3F) | ((MODE & 0X03) << COM1A0)))
#define TIMER1_SET_CHANNEL_B_OUTPUT_MODE(MODE)      (TCCR1A = ((TCCR1A & 0XCF) | ((MODE & 0X03) << COM1B0)))
#define TIMER1_SET_OPERATION_MODE_LOW_BITS(MODE)    (TCCR1A = ((TCCR1A & 0XFC) | (MODE & 0X03)))
#define TIMER1_SET_OPERATION_MODE_HIGH_BITS(MODE)   (TCCR1B = ((TCCR1B & 0XE7) | ((MODE & 0X0C) << 1)))
#define TIMER1_SET_PRESCALER_VALUE(PRESCALER)       (TCCR1B = ((TCCR1B & 0XF8) | (PRESCALER & 0X07)))
#define TIMER0_ENABLE_OVERFLOW_INTERRUPT()          (TIMSK |= (1 << TOIE1))
#define TIMER0_ENABLE_COMPARE_MATCH_A_INTERRUPT()   (TIMSK |= (1 << OCIE1A))
#define TIMER0_ENABLE_COMPARE_MATCH_B_INTERRUPT()   (TIMSK |= (1 << OCIE1B))

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/



#endif /* MCAL_TIMER1_INCLUDES_TIMER1_PRV_H_ */
