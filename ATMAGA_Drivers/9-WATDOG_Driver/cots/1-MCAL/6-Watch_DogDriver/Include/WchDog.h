/*
 * Timer.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Online
 */

#ifndef COTS_1_MCAL_3_TIMER_INCLUDE_TIMER_H_
#define COTS_1_MCAL_3_TIMER_INCLUDE_TIMER_H_


/*********************** WATCHDOG PROTOTYPES *******************************/

void WDT_VoidEnable(void);
void WDT_VoidDisnable(void);
void WDT_VoidSleep(u8 Copy_u8SleepTime);

#endif /* COTS_1_MCAL_3_TIMER_INCLUDE_TIMER_H_ */
