/*
 * GIE.h
 *
 * Created: 10/21/2023 11:44:23 AM
 *  Author: FADY
 */
#include "Gie.h"
#include "Gie_prv.h"

void GIE_globalInterruptEnable(void){
    SET_BIT(SREG,SREG_globalInterruptEnable);  
}
void GIE_globalInterruptDisable(void){
    CLR_BIT(SREG,SREG_globalInterruptEnable);
}
