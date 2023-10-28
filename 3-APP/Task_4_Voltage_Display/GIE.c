/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : GIE                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "Std_types.h"
#include "Bit_utils.h"

#include "GIE.h"
#include "GIE_prv.h"
#include "GIE_cfg.h"

void GIE_vidInit(void){
    #if GIE_INITIAL_STATE == GIE_ENABLE

        SET_BIT(SREG, 7);

    #elif GIE_INITIAL_STATE == GIE_DISABLE
        CLR_BIT(SREG, 7);
    #endif
}

void GIE_vidEnable(){
    SET_BIT(SREG, 7);
}

void GIE_vidDisable(){
    CLR_BIT(SREG, 7);
}
