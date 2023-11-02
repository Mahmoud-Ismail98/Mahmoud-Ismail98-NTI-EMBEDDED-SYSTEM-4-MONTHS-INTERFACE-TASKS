/*
 * WDT.c
 *
 * Created: 10/27/2023 4:20:40 AM
 *  Author: sharb
 */ 



#include "bit_math.h"
#include "WDT_prv.h"
#include "WDT.h"
#include "WDT_cfg.h"



void WDT_voidInit(void)
{
	WDTCR = SELECT_TIME_OUT;
}
void WDT_voidEnable(void)
{
	SET_BIT(WDTCR,WDE);
}
void WDT_voidDisable(void)
{
	
	WDTCR|=(1<<WDTOE) | (1<<WDE);
	WDTCR = 0x00;
}