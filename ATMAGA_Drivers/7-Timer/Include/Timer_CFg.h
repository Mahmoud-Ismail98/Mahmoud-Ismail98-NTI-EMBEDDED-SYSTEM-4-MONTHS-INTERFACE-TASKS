/*
 * Timer_CFg.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Online
 */

#ifndef COTS_1_MCAL_3_TIMER_INCLUDE_TIMER_CFG_H_
#define COTS_1_MCAL_3_TIMER_INCLUDE_TIMER_CFG_H_
/*****************************************************/
#define TIMER1_u8_WAVEFORM_MODE     TIMER1_CTC
#define TIMER1_u8_MODECTC           CLEAR_ON_COMPARE
#define TIMER1_u8_PRESCALLER        TIMER0_DIV_BY_8
/*****************************************************/
#define Enable                  1
#define Disable                 0

#define FALLIND_EDGE            0
#define RISING_EDGE             1
/*****************************************************/
/*
 *          1-TIMER0_NORMAL
 * 			2-TIMER0_CTC
 * 			3-TIMER0_FASTPWM
 * 			4-TIMER0_PHASEPWM
 */
#define TIMER0_u8_WAVEFORM_MODE         TIMER0_CTC
/*
 *          1-TIMER0_STOP				(No clock source)
 * 			2-TIMER0_DIV_BY_1
 * 			3-TIMER0_DIV_BY_8
 * 			4-TIMER0_DIV_BY_64
 * 			5-TIMER0_DIV_BY_256
 * 			6-TIMER0_DIV_BY_1024
 */
#define TIMER0_u8_PRESCALLER          TIMER0_DIV_BY_8


#endif /* COTS_1_MCAL_3_TIMER_INCLUDE_TIMER_CFG_H_ */
