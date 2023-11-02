/*
 * Watchdog_Private.h
 *
 * Created: 10/27/2023 12:30:09 PM
 *  Author: Mohamed Alaa
 */ 


#ifndef WATCHDOG_PRIVATE_H_
#define WATCHDOG_PRIVATE_H_
#include <Services/Std_types.h>
#include <Services/Bit_utils.h>

#define WDTCR	(*(volatile Puint8)0x41)

#define WDTOE	4
#define WDE		3
#define WDPn	0

#endif /* WATCHDOG_PRIVATE_H_ */