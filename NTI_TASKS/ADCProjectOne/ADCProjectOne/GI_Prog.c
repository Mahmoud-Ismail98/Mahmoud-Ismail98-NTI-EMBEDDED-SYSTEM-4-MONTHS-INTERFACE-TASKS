/*
 * GI_Prog.c
 *
 *  Created on: May 23, 2019
 *      Author: salsa
 */


#include "Std_types.h"
#include "Bit_utils.h"

#include "GI_Priv.h"
#include "GI_Config.h"
#include "GI_Int.h"


GIE_voidEnableGlobalInterrupt(void){
	SET_BIT(SREG,I);
}
GIE_voidDisableGlobalInterrupt(void){
	CLR_BIT(SREG,I);
}
