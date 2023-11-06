/*
 * Timer_Pro.c
 *
 *  Created on: Oct 24, 2023
 *      Author: aya
 */
#include "../../../4-SERVICS/Std_types.h"
#include "../../../4-SERVICS/Bit_utils.h"
#include "../../6-Watch_DogDriver/Include/WchDog_Reg.h"
#include "../../6-Watch_DogDriver/Include/WchDog_Prv.h"


void WDT_VoidEnable(void){
	SET_BIT(WDTCR,WDTCR_WDE);
}
void WDT_VoidDisnable(void){
	WDTCR = (1<<WDTCR_WDE) | (1<< WDTCR_WDTOE);
	WDTCR=0;
}
void WDT_VoidSleep(u8 Copy_u8SleepTime){
	if (Copy_u8SleepTime < 8){
		WDTCR &=0b11111000;
		WDTCR |= Copy_u8SleepTime;
	}
}
