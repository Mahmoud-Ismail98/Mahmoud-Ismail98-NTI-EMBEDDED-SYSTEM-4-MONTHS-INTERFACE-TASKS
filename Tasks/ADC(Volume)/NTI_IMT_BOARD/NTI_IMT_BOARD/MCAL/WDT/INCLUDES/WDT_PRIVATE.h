/*
 * WDT_PRIVATE.h
 *
 * Created: 10/27/2023 1:26:49 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_


#define WDTCR ((*(volatile pu8)0x41))
	/*WDTCR BITS*/
	#define WDTCR_WDTOE     4  //Watchdog Turn-off Enable i.e 1 to disable watch dog timer
	#define WDTCR_WDE       3  //Watchdog Enable          i.e 0 to disable watch dog timer
	#define WDTCR_WDP2      2  //Watchdog Timer Prescaler 2
	#define WDTCR_WDP1      1  //Watchdog Timer Prescaler 1
	#define WDTCR_WDP0      0  //Watchdog Timer Prescaler 0
	
	
	


#endif /* WDT_PRIVATE_H_ */