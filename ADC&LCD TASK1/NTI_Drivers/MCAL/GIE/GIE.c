/*
 * MGIE_Program.c
 *
 *  Created on: Oct 21, 2022
 *      Author: Ismail
 */
#include "GIE_prv.h"
#include "GIE.h"
void GIEMode(u8 LocalGIE_Mode){
	switch (LocalGIE_Mode){
	case GIE_ENABLE:
		SET_BIT(SREG,7);
		break;
	case GIE_DISABLE:
		CLR_BIT(SREG,7);
		break;
	default:
		CLR_BIT(SREG,7);
		break;
	}
}





