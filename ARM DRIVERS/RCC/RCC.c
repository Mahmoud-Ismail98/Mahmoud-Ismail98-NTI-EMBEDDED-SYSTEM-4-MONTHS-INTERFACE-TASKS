#include "std_types.h"
#include "bit_utils.h"

#include "RCC.h"

typedef struct RCC_t{
    u32 CR;
    u32 PLLCFGR;
    u32 CFGR;
    u32 CIR;
    u32 AHB1RSTR;
    u32 AHB2RSTR;
    u32 rese[2];
    u32 APB1RSTR;
    u32 APB2RSTR;
    u32 Rese[2];
    u32 AHB1ENR;
    u32 AHB2ENR;
    u32 REse[2];
    u32 APB1ENR;
    u32 APB2ENR;
    u32 RESe[2];
    u32 AHB1LPENR;
    u32 AHB2LPENR;
    u32 RESE[2];
    u32 APB1LPENR;
    u32 APB2LPENR;
    u32 rEse[2];
    u32 BDCR;
    u32 CSR;
    u32 rESe[2];
    u32 SSCGR;
    u32 PLLI2SCFGR;
    u32 DCKCFGR;
} RCC_t;



#define RCC ((volatile RCC_t*) 0x40023800)



Rcc_tenuErrorStatus Rcc_enuSelectSysCLk(u8 Copy_u8SysClk){
    Rcc_tenuErrorStatus local_errorState = Rcc_enuOk; 
    u32 Loc_u32CountDown = 20000;
    //enable the clock source 
    switch (Copy_u8SysClk){
        case RCC_CLK_PLL : Peripheral_BitBand(RCC->CR, 24) = 1;
        while(Peripheral_BitBand(RCC->CR, 25) == 0 && (Loc_u32CountDown > 1) ){
            Loc_u32CountDown--;
        }
        break;
        case RCC_CLK_HSE : Peripheral_BitBand(RCC->CR, 16) = 1;
        while(Peripheral_BitBand(RCC->CR, 17) == 0 && (Loc_u32CountDown > 1) ){
            Loc_u32CountDown--;
        }
        break;
        case RCC_CLK_HSI : Peripheral_BitBand(RCC->CR, 0)  = 1;
        while(Peripheral_BitBand(RCC->CR, 1) == 0 && (Loc_u32CountDown > 1) ){
            Loc_u32CountDown--;
        }
        break;
        default : local_errorState = Rcc_enuInvalidClk ; break; 
    }
    if (Loc_u32CountDown ==0){
        local_errorState = Rcc_enuTimeOutError;
    }
    // enable the selected clock as system clock 
    switch (Copy_u8SysClk){
        case RCC_CLK_HSI : 
            Peripheral_BitBand(RCC->CFGR, 0) = 0;
            Peripheral_BitBand(RCC->CFGR, 1) = 0;
            break;
        case RCC_CLK_HSE : 
            Peripheral_BitBand(RCC->CFGR, 0) = 1;
            Peripheral_BitBand(RCC->CFGR, 1) = 0;
            break;
        case RCC_CLK_PLL : 
            Peripheral_BitBand(RCC->CFGR, 0) = 0;
            Peripheral_BitBand(RCC->CFGR, 1) = 1;
            break;
        default : local_errorState = Rcc_enuInvalidClk ; break; 
    }
    return local_errorState;
}

Rcc_tenuErrorStatus Rcc_enuControlCLk(u8 Copy_u8ControlHSI  ,u8 Copy_u8ControlHSE ,u8 Copy_u8ControlPLL){
    Rcc_tenuErrorStatus local_errorState = Rcc_enuOk; 

    switch (Copy_u8ControlPLL){
    case RCC_CNTROL_PLLON : Peripheral_BitBand(RCC->CR, 24) = 1;break;
    case RCC_CNTROL_PLLOFF : Peripheral_BitBand(RCC->CR, 24) = 0;break;
    default : local_errorState = Rcc_enuInvalidClk ; break; 
    }

    switch (Copy_u8ControlHSE){
    case RCC_CNTROL_HSEON : Peripheral_BitBand(RCC->CR, 16) = 1;break;
    case RCC_CNTROL_HSEOFF : Peripheral_BitBand(RCC->CR, 16) = 0;break;
    default : local_errorState = Rcc_enuInvalidClk ; break; 
    }

    switch (Copy_u8ControlHSI){
    case RCC_CNTROL_HSION : Peripheral_BitBand(RCC->CR, 0) = 1;break;
    case RCC_CNTROL_HSIOFF : Peripheral_BitBand(RCC->CR, 0) = 0;break;
    default : local_errorState = Rcc_enuInvalidClk ; break; 
    }
    return local_errorState;
}

Rcc_tenuErrorStatus Rcc_enuCheckCLk(u8 Copy_u8CLk, pu8 Add_pu8RdyStatus){
    Rcc_tenuErrorStatus local_errorState = Rcc_enuOk;
    if (Add_pu8RdyStatus == NULL){
        local_errorState = RCC_enuNullPointerError;
    }else {
        switch (Copy_u8CLk){
            case RCC_CLK_PLL :*Add_pu8RdyStatus = (u8)Peripheral_BitBand(RCC->CR, 24) ;break;
            case RCC_CLK_HSE :*Add_pu8RdyStatus = (u8)Peripheral_BitBand(RCC->CR, 16) ;break;
            case RCC_CLK_HSI :*Add_pu8RdyStatus = (u8)Peripheral_BitBand(RCC->CR, 0 ) ;break;
            default : local_errorState = Rcc_enuInvalidClk ;break; 
        }
    }
    return local_errorState;
}

Rcc_tenuErrorStatus Rcc_enuCnfgrPll(u8 COPY_u8M , u16 Copy_u16N , u8 Copy_u8P , u8 Copy_u8SrcPll , u8 Copy_u8Q){
    Rcc_tenuErrorStatus local_errorState = Rcc_enuOk;
    RCC->PLLCFGR &= 0xFFFFFFE0;
    RCC->PLLCFGR |= COPY_u8M;
    
    RCC->PLLCFGR &= 0xFFFF803F;
    RCC->PLLCFGR |= (Copy_u16N << 6);
    
    RCC->PLLCFGR &= 0xFFFCFFFF;
    RCC->PLLCFGR |= (Copy_u8P << 16);
    
    RCC->PLLCFGR &= 0xF0FFFFFF;
    RCC->PLLCFGR |= (Copy_u8Q << 22);



    Peripheral_BitBand(RCC->PLLCFGR,22) = Copy_u8SrcPll;


    return local_errorState;

}

Rcc_tenuErrorStatus Rcc_enuEnablePeriphral(u8 Copy_u8PeriphralBus , u32 Copy_u32Periphral){
    Rcc_tenuErrorStatus local_errorState = Rcc_enuOk;
    switch(Copy_u8PeriphralBus){
        case RCC_REGISTER_AHB1 : RCC->AHB1ENR |= Copy_u32Periphral ;break;
        case RCC_REGISTER_AHB2 : RCC->AHB2ENR |= Copy_u32Periphral ;break;
        case RCC_REGISTER_APB1 : RCC->APB1ENR |= Copy_u32Periphral ;break;
        case RCC_REGISTER_APB2 : RCC->APB2ENR |= Copy_u32Periphral ;break;
        default : local_errorState = Rcc_enuWrongPeriphralBusError;
    }
    return local_errorState;
}

Rcc_tenuErrorStatus Rcc_enuDisablePeriphral(u8 Copy_u8PeriphralBus , u32 Copy_u32Periphral){
    Rcc_tenuErrorStatus local_errorState = Rcc_enuOk;
    switch(Copy_u8PeriphralBus){
        case RCC_REGISTER_AHB1 : RCC->AHB1ENR &= (~Copy_u32Periphral) ;break;
        case RCC_REGISTER_AHB2 : RCC->AHB2ENR &= (~Copy_u32Periphral) ;break;
        case RCC_REGISTER_APB1 : RCC->APB1ENR &= (~Copy_u32Periphral) ;break;
        case RCC_REGISTER_APB2 : RCC->APB2ENR &= (~Copy_u32Periphral) ;break;
        default : local_errorState = Rcc_enuWrongPeriphralBusError;
    }
    return local_errorState;
}

// Rcc_tenuErrorStatus Rcc_enuCfgBusPrescalers(u32 Copy_u32Prescaler){

// }
