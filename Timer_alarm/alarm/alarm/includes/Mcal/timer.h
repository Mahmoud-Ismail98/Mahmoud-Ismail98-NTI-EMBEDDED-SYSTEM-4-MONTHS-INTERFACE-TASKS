/*
 * timer.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef MCAL_TIMER_H_
#define MCAL_TIMER_H_

#include"../Services/std_types.h"
#include"../Mcal/dio.h"
#include"../Mcal/port.h"
#include"../Services/common_macros.h"
#include"timer_prv.h"
#include"timer_cfg.h"


/*timer selection*/
#define TIMER_ZERO                                                                        0
#define TIMER_ONE                                                                         1
#define TIMER_TWO                                                                         2

/*Waveform Generation Mode Bit Description*/
#define TIMER_NORMAL_MODE                                                                 0
#define TIMER_PWM_PHASE_CORRECT_MODE                                                      1
#define TIMER_COMPARE_MATCH_MODE                                                          2
#define TIMER_NORMAL_PWM_FAST_MODE                                                        4

/*Compare Output Mode with or without pwm*/
#define TIMER_COMPARE_MODE_NONE_PWM                                                       0
#define TIMER_COMPARE_MODE_WITH_PWM                                                       1

/*Compare Output Mode with pwm*/
#define TIMER_COMPARE_MODE_PWM_FAST                                                       0
#define TIMER_COMPARE_MODE_PWM_PHASE_CORRECT                                              1

/*Compare Output Mode, non-PWM Mode*/
#define TIMER_NORMAL_NONE_PWM                                                             0
#define TIMER_TOGGLE_OC_REG_IN_COMPARE_MODE_NONE_PWM                                      1
#define TIMER_CLEAR_OC_REG_IN_COMPARE_MODE_NONE_PWM                                       2
#define TIMER_SET_OC_REG_IN_COMPARE_MODE_NONE_PWM                                         3

/*Compare Output Mode, Fast PWM Mode*/
#define TIMER_NORMAL_WITH_FAST_PWM                                                        0
#define TIMER_CLEAR_OC_REG_IN_COMPARE_MODE_NON_INVERTING_WITH_FAST_PWM                    2
#define TIMER_CLEAR_OC_REG_IN_COMPARE_MODE_INVERTING_WITH_FAST_PWM                        3

/*Compare Output Mode, Phase Correct PWM Mode*/
#define TIMER_NORMAL_WITH_PHASE_CORRECT_PWM                                               0
#define TIMER_CLEAR_OC_REG_IN_COMPARE_MODE_NON_INVERTING_WITH_PHASE_CORRECT_PWM           2
#define TIMER_CLEAR_OC_REG_IN_COMPARE_MODE_EITH_INVERTING_WITH_PHASE_CORRECT_PWM          3

/*timer prescaler*/
#define TIMER_NO_CLOCK                                                                    0
#define TIMER_NO_PRESCALER                                                                1
#define TIMER_WITH_PRESCALER_8                                                            2
#define TIMER_WITH_PRESCALER_64                                                           3
#define TIMER_WITH_PRESCALER_256                                                          4
#define TIMER_WITH_PRESCALER_1024                                                         5
#define TIMER_WITH_EX_CLOCK_FALLING                                                       6
#define TIMER_WITH_EX_CLOCK_RISING                                                        7

/*bits in register*/
#define BIT_NU0                      0
#define BIT_NU1                      1
#define BIT_NU2                      2
#define BIT_NU3                      3
#define BIT_NU4                      4
#define BIT_NU5                      5
#define BIT_NU6                      6
#define BIT_NU7                      7

/*FREQUENCIES VALUES*/
#define MAX_FREQUENCY                (16000000U)
#define MID_FREQUENCY                (8000000U)
#define MIN_FREQUENCY                (1000000U)

#define TIMER_INITIAL_VALUE    0


/*icu in timer1 static configs*/
#define ICU_FALLING_EDGE           0
#define ICU_RISING_EDGE            1

#define ICU_PRESCALER_NO_CLOCK            0
#define ICU_PRESCALER_F_CPU_CLOCK         1
#define ICU_PRESCALER_F_CPU_8             2
#define ICU_PRESCALER_F_CPU_64            3
#define ICU_PRESCALER_F_CPU_256           4
#define ICU_PRESCALER_F_CPU_1024          5

#define ICU_EDGE_SELECT_BIT               BIT_NU6
#define ICU_NOISE_CANCELER_BIT            BIT_NU7
#define ICU_INTERRUPT_ENABLE              BIT_NU5
#define ICU_INTERRUPT_FLAG                BIT_NU5

/*timer functions prototypes*/

void timer_init(void);
void timer_setCallBack(void(*funClbk_ptr)(void), u8 index);
void timer_setPwm(u16 compareValue);
void timer_getValue(u16 *timerRead);
u8 timer_getPwmOnPeriod(u16 *timerPwmOnRead);
u8 timer_getPwmTotalPeriod(u32 *timerPwmTotalRead);
u8 timer_getPwmDutycycle(u8 *timerPwmDutycycleRead);
void Timer0_deInit(void);

/*icu in timer1 functions prototypes*/
void ICU_init(void); //initialization of ICU with (dynamic configration)

void ICU_setEdgeDetectionType(const u8 edgeType); // to set the edge we want the ICU to detect

u16 ICU_getInputCaptureValue(void);  // return the captured value of the timer on ICR1

void ICU_clearTimerValue(void);  // clear the timer to zero to get another value from it

void ICU_deint(void); // disable the Timer1 to stop the ICU Driver(as ICU is part of the timer)

#endif /* MCAL_TIMER_H_ */
