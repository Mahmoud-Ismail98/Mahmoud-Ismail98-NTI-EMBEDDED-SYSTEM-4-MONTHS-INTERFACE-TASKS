/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 24 Oct 2023                                                           */
/************************************************************************************/
#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H

/* configuration of the compare output mode  => OC HW Pin */
/*       on normal and ctc mode                           */
/*      Options: TIMER_NORMAL_PORT
                 TIMER_TOG_ON_CMATCH
                 TIMER_CLR_ON_CMATCH
                 TIMER_SET_ON_CMATCH                    */
#define TIMER_NORM_CTC_MODE       TIMER_NORMAL_PORT 

/* configuration of the compare output mode  => OC HW Pin */
/*       on fast PWM and phase correct PWM mode           */
/*      Options: TIMER_NORM_PORT
                 TIMER_NON_INVERTING
                 TIMER_INVRTING                           */
#define TIMER_FAST_PHASE_MODE       TIMER_NON_INVERTING 

/* configuration of the clock prescaler           */
/*      Options: TIMER_NO_PRESCALING
                 TIMER_CLK_8_PRESCALING
                 TIMER_CLK_64_PRESCALING                     */
#define TIMER_CLK_PRESCALER       TIMER_CLK_8_PRESCALING 

/* set preload value and compare match value */
// TIMER 0
#define TIMER0_u8_PRELOAD_VALUE              192
#define TIMER0_u8_COMPMATCH_VALUE            99
#define TIMER0_u32_NORMAL_NO_OVF             3907
#define TIMER0_u32_CTC_NO_OVF                5000
// TIMER 1
#define TIMER1_u16_PRELOAD_VALUE             192
#define TIMER1_u16_COMPMATCH_VALUE_A         99
#define TIMER1_u16_COMPMATCH_VALUE_B         99
#define TIMER1_u32_NORMAL_NO_OVF             3907
#define TIMER1_u32_CTC_NO_OVF                500

/* time out mechanism */
#define TIMER_TIME_OUT_MECHANISM             50000

#endif