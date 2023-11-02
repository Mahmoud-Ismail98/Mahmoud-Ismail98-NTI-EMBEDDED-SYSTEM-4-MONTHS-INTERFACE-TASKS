/*
 * WDT_prv.h
 *
 * Created: 10/27/2023 4:21:06 AM
 *  Author: sharb
 */ 


#ifndef WDT_PRV_H_
#define WDT_PRV_H_

#include "std_types.h"

#define WDTCR (*(vu8*)(0x41))



//BIT 4 WDTOE: Watchdog Turn-off Enable
#define WDTOE    4

//BIT 3 WDE

#define WDE      3




//WDP2, WDP1, WDP0: Watchdog Timer Prescaler 2, 1, and 0


#define  TIME_OUT_16_ms                  0x00
#define  TIME_OUT_32_ms                  0x01
#define  TIME_OUT_65_ms                  0x02
#define  TIME_OUT_130_ms                 0x03
#define  TIME_OUT_260_ms                 0x04
#define  TIME_OUT_520_ms                 0x05
#define  TIME_OUT_1_s                    0x06
#define  TIME_OUT_2_s                    0x07



#endif /* WDT_PRV_H_ */