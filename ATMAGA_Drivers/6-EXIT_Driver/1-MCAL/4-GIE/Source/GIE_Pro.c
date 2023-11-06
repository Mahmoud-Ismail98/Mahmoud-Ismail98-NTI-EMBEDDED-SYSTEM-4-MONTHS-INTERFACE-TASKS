/*
 * GIE_Pro.c
 *
 *  Created on: Oct 24, 2023
 *      Author: Online
 */

#include "../../../4-SERVICS/Bit_utils.h"
#include "../../../4-SERVICS/Std_types.h"
#include "../../4-GIE/Include/GIE.h"
#include "../../4-GIE/Include/GIE_Cfg.h"
#include "../../4-GIE/Include/GIE_Prv.h"
void GIE_VidInit(void){

switch (GIE_STATE){
case GIE_ENABLE: SET_BIT(SREG,SREG_I);break;
case GIE_DIABLE: CLR_BIT(SREG,SREG_I);break;
default : /* do nothig */ break;
}
}
