/*
 * Watchdog.h
 *
 * Created: 10/27/2023 12:29:32 PM
 *  Author: Mohamed Alaa
 */ 


#ifndef WATCHDOG_H_
#define WATCHDOG_H_

#include <Services/Std_types.h>

#define Watchdog_Time_16ms			0
#define Watchdog_Time_32ms			1
#define Watchdog_Time_65ms			2
#define Watchdog_Time_130ms			3
#define Watchdog_Time_260ms			4
#define Watchdog_Time_520ms			5
#define Watchdog_Time_1000ms		6
#define Watchdog_Time_2100ms		7


void Watchdog_Init(void);
void Watchdog_Start(uint8 Watchdog_Time);
void Watchdog_Stop(void);



#endif /* WATCHDOG_H_ */