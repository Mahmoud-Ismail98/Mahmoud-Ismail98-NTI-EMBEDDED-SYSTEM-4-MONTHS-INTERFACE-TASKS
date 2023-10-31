/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : WDT                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "Std_types.h"
#include "Bit_utils.h"

#include "WDT.h"
#include "WDT_prv.h"
#include "WDT_cfg.h"

void WDT_voidEnable(void){

	SET_BIT(WDTCR, WDTCR_WDE);
    
}


void WDT_voidDisable(void){   
    /* Setting WDE and WDTOE bits at same time */
    u8 Local_u8Variable = 0;
    SET_BIT(Local_u8Variable, WDTCR_WDTOE);
    SET_BIT(Local_u8Variable, WDTCR_WDE);
	WDTCR = Local_u8Variable;
	WDTCR = 0x00;
}

void WDT_voidSleep(u8 Copy_u8SleepTime){
    WDTCR &= 0b11111000;
	WDTCR |= Copy_u8SleepTime;

}