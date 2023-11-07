/*
 * GIE.c
 *
 * Created: 10/22/2023 3:12:57 PM
 *  Author: Mahmoud Tariq
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE.h"


void GI_vidInit(void){
	#if GI  == 1
	SET_BIT(SREG,Global_Interrupt_Enable);	
	#endif
	#if 0 == GI
	CLR_BIT(SREG,Global_Interrupt_Enable);
	#endif
	
}

void GI_vidSet(void){
	SET_BIT(SREG,Global_Interrupt_Enable);
}
void GI_vidClear(void){
	CLR_BIT(SREG,Global_Interrupt_Enable);
}
