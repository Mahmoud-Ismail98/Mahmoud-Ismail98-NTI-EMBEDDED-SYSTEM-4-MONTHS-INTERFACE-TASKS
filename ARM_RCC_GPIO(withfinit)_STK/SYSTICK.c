
#include "STD_TYPES.h"
#include "BIT_UTILS.h"
#include "SYSTICK.h"
#include "SYSTICK_prv.h"
#include "SYSTICK_cfg.h"

static Systick_Cbf systickCallback = NULL; 


 Systick_tenuErrorStatus Systick_Init(u32 Copy_TimeMs) {
    if (Copy_TimeMs > VALIDATE_RELOADVALUE) {
        return Systick_enuErrorTimeMs; 
    }
    
    Copy_TimeMs &= VALIDATE_RELOADVALUE; 
    MSTK->LOAD = Copy_TimeMs + 1;
    MSTK->VAL = 0;

#if STK_PRESCALER == STK_PRESCALER_DIV1
    SET_BIT(MSTK->CTRL, 2);
#elif STK_PRESCALER == SYSTICK_PRESCALER_DIV8
    CLR_BIT(MSTK->STK_CTRL, 2);
#endif

#if STK_TICKINT == STK_INTERRUPT_EN
    SET_BIT(MSTK->CTRL, 1);
    Systick_Start();
#elif STK_TICKINT == STK_INTERRUPT_DIS
    CLR_BIT(MSTK->CTRL, 1);
    while ((GET_BIT(MSTK->CTRL, 16)) == 0);
    /* Disable Timer */
    Systick_Stop();
#endif
 
    
    
    return Systick_enuOk;
}


Systick_tenuErrorStatus Systick_RegisterCbf(Systick_Cbf Add_pfCbf) {
    if (Add_pfCbf != NULL) {
        
        systickCallback = Add_pfCbf;
        return Systick_enuOk;
    } else {
        return Systick_enuErrorNullPointer;
    }
}


 void Systick_Start(void){
    SET_BIT(MSTK->CTRL,0);
}


 void Systick_Stop(void){
    CLR_BIT(MSTK->CTRL,0);
    MSTK->LOAD = 0;
	MSTK->VAL  = 0;
}


void SysTick_Handler(void) {
    if (systickCallback != NULL) {
        systickCallback();
        Systick_Stop();
    }
}