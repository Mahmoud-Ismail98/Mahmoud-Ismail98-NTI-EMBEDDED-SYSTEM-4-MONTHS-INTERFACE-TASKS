/*
 * Watchdog.c
 *
 * Created: 10/27/2023 12:30:50 PM
 *  Author: Mohamed Alaa
 */ 

#include <MCAL/Watchdog/Watchdog_Includes/Watchdog_Private.h>


void Watchdog_Start(uint8 Watchdog_Time)
{
	WDTCR |= Watchdog_Time << WDPn;
	SET_BIT(WDTCR, WDE);
}

void Watchdog_Stop(void)
{
	WDTCR |= 1<<WDE | 1<<WDTOE;
	CLR_BIT(WDTCR, WDE);
}