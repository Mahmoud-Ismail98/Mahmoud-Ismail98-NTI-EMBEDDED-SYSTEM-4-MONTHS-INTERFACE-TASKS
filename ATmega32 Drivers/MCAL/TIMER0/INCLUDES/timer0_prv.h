/*
=======================================================================================================================
Author       : Mamoun
Module       : Timer-1
File Name    : timer0_prv.h
Date Created : Oct 27, 2023
Description  : Private file for the ATmega32 Timer-0 driver.
=======================================================================================================================
*/


#ifndef MCAL_TIMER0_INCLUDES_TIMER0_PRV_H_
#define MCAL_TIMER0_INCLUDES_TIMER0_PRV_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

#define TIMER0_NUM_OF_INTERRUPT_MODES            (2U)
#define TIMER0_OVF_INTERRUPT_ID                  (0U)
#define TIMER0_CTC_INTERRUPT_ID                  (1U)

#define TIMER0_OVERFLOW_VALUE                    (256)

/*=====================================================================================================================
                                         < Function-like Macros >
=====================================================================================================================*/

#define TIMER0_SET_PWM_STATE(MODE) (TCCR0 = ((TCCR0 & 0X7F) | ((~(MODE & 0X01)) << FOC0)))
#define TIMER0_SET_OPERATION_MODE(MODE) (TCCR0 = ((TCCR0 & 0XB7) | ((MODE & 0X01) << WGM00) | ((MODE & 0X02) << WGM01)))
#define TIMER0_SET_PRESCALER_VALUE(PRESCALER) (TCCR0 = ((TCCR0 & 0XF8) | (PRESCALER & 0X07)))
#define TIMER0_SET_COMPARE_OUTPUT_MODE(MODE) (TCCR0 = ((TCCR0 & 0XCF) | ((MODE & 0X03) << COM00)))
#define TIMER0_ENABLE_OVERFLOW_INTERRUPT()     (TIMSK = ((TIMSK & 0XFE) | (1 << TOIE0)))
#define TIMER0_ENABLE_COMPARE_MATCH_INTERRUPT()        (TIMSK = ((TIMSK & 0XFD) | (1 << OCIE0)))

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/



#endif /* MCAL_TIMER0_INCLUDES_TIMER0_PRV_H_ */
