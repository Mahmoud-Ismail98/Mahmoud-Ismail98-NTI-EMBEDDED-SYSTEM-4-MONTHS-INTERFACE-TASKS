/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : SWICU                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "Std_types.h"
#include "Bit_utils.h"

#include "EXTI.h"
#include "Timer.h"

#include "SWICU.h"
#include "SWICU_prv.h"
#include "SWICU_cfg.h"

Timer0_cfg TIMER0_CFG;
EXTI0_CFG EXTI0_cfg;
u8 GLOBAL_u8ISR_COUNTS = 0;
u8 GLOBAL_u8TIMER_OVER_FLOWS = 0;
u8 GLOBAL_U8TIMER_VALUE = 0;

u16 GLOBAL_u16ON_PERIOD = 0;
u32 GLOBAL_u32TOTAL_PERIOD = 0;

void SWICU_voidEnable(void){

    EXTI0_cfg.EXTI_OPERATION = EXTI_ENABLE;
    EXTI0_cfg.EXTI_SENSE_CONTROL = EXTI_RISING_EDGE;
    EXTI0_voidInit(&EXTI0_cfg);
    EXTI_enuErrorStateInt0SetCallBack(&SWICU_voidPrvIntCallBack);
    Timer0_enuErrorStateOverFlowSetCallBack(&SWICU_voidPrvTimerOverFlowCallBack);
    
    TIMER0_CFG.TIMER_0_MODE = TIMER_0_MODE_NORMAL;
    TIMER0_CFG.OC0_MODE = OC0_MODE_NORMAL_PORT;
    TIMER0_CFG.TIMER_0_INTERRUPT_MODE = TIMER_0_INTERRUPT_MODE_ENABLE_OVERFLOW;
    TIMER0_CFG.CLOCK_MODE = TIMER_2_CLOCK_MODE_8_PRESCALER;
        
}
void SWICU_voidDisable(void){

}

tenuErrorStatus SWICU_ErrStateGetOnPeriod(pu16 Copy_pu16OnPeriod){
    Copy_pu16OnPeriod = GLOBAL_u16ON_PERIOD;
}
tenuErrorStatus SWICU_ErrStateGetTotalPeriod(pu32 Copy_pu32TotalPeriod){
    Copy_pu32TotalPeriod = GLOBAL_u32TOTAL_PERIOD;
}
tenuErrorStatus SWICU_ErrStateGetDutyCycle(pu8 Copy_pu8DutyCycle){
    Copy_pu8DutyCycle = (u8)(((f64)GLOBAL_u16ON_PERIOD / (f64)GLOBAL_u32TOTAL_PERIOD) * 100.0);
}

void SWICU_voidPrvIntCallBack(void){
    
    switch (GLOBAL_u8ISR_COUNTS)
    {
    case 0:
        GLOBAL_u8TIMER_OVER_FLOWS = 0;
        TIMER_0_voidInit(&TIMER0_CFG);
        TIMER_0_void_setValue(0);
        break;
    case 1:
        GLOBAL_U8TIMER_VALUE = TIMER_0_void_getValue();
        TIMER_0_void_setValue(0);
        GLOBAL_u32TOTAL_PERIOD = GLOBAL_U8TIMER_VALUE + 255* GLOBAL_u8TIMER_OVER_FLOWS;
        GLOBAL_u8TIMER_OVER_FLOWS = 0;
        EXTI0_cfg.EXTI_OPERATION = EXTI_ENABLE;
        EXTI0_cfg.EXTI_SENSE_CONTROL = EXTI_FALLING_EDGE;
        EXTI0_voidInit(&EXTI0_cfg);
        break;
    case 2:
        GLOBAL_U8TIMER_VALUE = TIMER_0_void_getValue();
        TIMER_0_void_setValue(0);
        GLOBAL_u16ON_PERIOD = GLOBAL_U8TIMER_VALUE + 255* GLOBAL_u8TIMER_OVER_FLOWS;
        GLOBAL_u8TIMER_OVER_FLOWS = 0;
        EXTI0_cfg.EXTI_OPERATION = EXTI_ENABLE;
        EXTI0_cfg.EXTI_SENSE_CONTROL = EXTI_RISING_EDGE;
        EXTI0_voidInit(&EXTI0_cfg);
        GLOBAL_u8ISR_COUNTS = 0;
        break;
    }
    GLOBAL_u8ISR_COUNTS ++;
    
}

void SWICU_voidPrvTimerOverFlowCallBack(void){
    GLOBAL_u8TIMER_OVER_FLOWS ++;
}

