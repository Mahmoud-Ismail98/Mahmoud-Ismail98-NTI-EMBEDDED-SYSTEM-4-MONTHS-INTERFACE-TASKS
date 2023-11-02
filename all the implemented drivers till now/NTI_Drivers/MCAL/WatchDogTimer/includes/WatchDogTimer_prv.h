/*
 * WatchDogTimer_prv.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Ismail
 */

#ifndef MCAL_WATCHDOGTIMER_WATCHDOGTIMER_PRV_H_
#define MCAL_WATCHDOGTIMER_WATCHDOGTIMER_PRV_H_

#define WDTCR		*((volatile u8*)0x41)
#define WDTOE		4
#define WDE			3
#define WDP2        2
#define WDP1        1
#define WDP0        0

/*Options for prescaler*/

#define KWDT16K     16
#define KWDT32K		32
#define KWDT64K     64
#define KWDT128K	128
#define KWDT256K	256
#define KWDT512K	512
#define KWDT1024K	1024
#define KWDT2048K	2048


#endif /* MCAL_WATCHDOGTIMER_WATCHDOGTIMER_PRV_H_ */
