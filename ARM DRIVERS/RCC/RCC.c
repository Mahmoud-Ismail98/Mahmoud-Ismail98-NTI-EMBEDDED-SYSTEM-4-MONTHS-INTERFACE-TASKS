#include "std_types.h"
#include "bit_utils.h"

#include "RCC.h"

// This macro is used as the maximum number of iterations in a while loop to wait for a specific condition to be met.
#define MAX_WAITING_TIME            20000

// defining the bit positions of certain flags in the RCC (Reset and Clock Control) register.
#define PLLRDY                      25
#define PLLON                       24
#define HSERDY                      17
#define HSEON                       16
#define HSIRDY                      1
#define HSION                       0

// structure contains multiple members, each representing a specific register in the RCC.
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



// defining the base address of the RCC (Reset and Clock Control) register in the stm32f401 .
#define RCC ((volatile RCC_t*) 0x40023800)



/**
 * This function selects the system clock source and enables it.
 * 
 * @param Copy_u8SysClk represents the system clock source.
 * 
 * @return a variable of type Rcc_tenuErrorStatus, which represents the error status of the function.
 */
Rcc_tenuErrorStatus Rcc_enuSelectSysCLk(u8 Copy_u8SysClk){
    Rcc_tenuErrorStatus local_errorState = Rcc_enuOk; 
    u32 Loc_u32CountDown = MAX_WAITING_TIME;
    switch (Copy_u8SysClk){
        case RCC_CLK_PLL :
            while(Peripheral_BitBand(RCC->CR, PLLRDY) == 0 && (Loc_u32CountDown > 1) ){
                Loc_u32CountDown--;
            } 
            Peripheral_BitBand(RCC->CR, PLLON) = 1;
            break;
        case RCC_CLK_HSE :
            while(Peripheral_BitBand(RCC->CR, HSERDY) == 0 && (Loc_u32CountDown > 1) ){
                Loc_u32CountDown--;
            }
            Peripheral_BitBand(RCC->CR, HSEON) = 1;
            break;
        case RCC_CLK_HSI : 
            while(Peripheral_BitBand(RCC->CR, HSIRDY) == 0 && (Loc_u32CountDown > 1) ){
                Loc_u32CountDown--;
            }
            Peripheral_BitBand(RCC->CR, HSION)  = 1;
            break;
        default : local_errorState = Rcc_enuInvalidClk ; break; 
    }
    if (Loc_u32CountDown == 0){
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

/**
 * This function controls the state of the HSI, HSE, and PLL clocks and returns an error status.
 * 
 * @param Copy_u8ControlHSI This parameter is used to control the HSI (High-Speed Internal) clock
 * @param Copy_u8ControlHSE This parameter is used to control the HSE (High-SpeedExternal) clock
 * @param Copy_u8ControlPLL This parameter is used to control the PLL (Phase-Locked Loop) clock.
 * 
 * @return a variable of type Rcc_tenuErrorStatus, which represents the error status of the function.
 */
Rcc_tenuErrorStatus Rcc_enuControlCLk(u8 Copy_u8ControlHSI  ,u8 Copy_u8ControlHSE ,u8 Copy_u8ControlPLL){
    Rcc_tenuErrorStatus local_errorState = Rcc_enuOk; 

    switch (Copy_u8ControlPLL){
    case RCC_CNTROL_PLLON : Peripheral_BitBand(RCC->CR, PLLON) = 1;break;
    case RCC_CNTROL_PLLOFF : Peripheral_BitBand(RCC->CR, PLLON) = 0;break;
    default : local_errorState = Rcc_enuInvalidClk ; break; 
    }

    switch (Copy_u8ControlHSE){
    case RCC_CNTROL_HSEON : Peripheral_BitBand(RCC->CR, HSEON) = 1;break;
    case RCC_CNTROL_HSEOFF : Peripheral_BitBand(RCC->CR, HSEON) = 0;break;
    default : local_errorState = Rcc_enuInvalidClk ; break; 
    }

    switch (Copy_u8ControlHSI){
    case RCC_CNTROL_HSION : Peripheral_BitBand(RCC->CR, HSION) = 1;break;
    case RCC_CNTROL_HSIOFF : Peripheral_BitBand(RCC->CR, HSION) = 0;break;
    default : local_errorState = Rcc_enuInvalidClk ; break; 
    }
    return local_errorState;
}

/**
 * This function checks the status of a specific clock source and returns the result.
 * 
 * @param Copy_u8CLk This parameter represents the clock source to be checked.
 * @param Add_pu8RdyStatus This parameter is a pointer to an unsigned 8-bit integer. It
 * is used to store the status of the clock specified by the Copy_u8CLk parameter. The status can be
 * either 0 or 1, indicating whether the clock is ready or not.
 * 
 * @return a variable of type Rcc_tenuErrorStatus, which represents the error status of the function.
 */
Rcc_tenuErrorStatus Rcc_enuCheckCLk(u8 Copy_u8CLk, pu8 Add_pu8RdyStatus){
    Rcc_tenuErrorStatus local_errorState = Rcc_enuOk;
    if (Add_pu8RdyStatus == NULL){
        local_errorState = RCC_enuNullPointerError;
    }else {
        switch (Copy_u8CLk){
            case RCC_CLK_PLL :*Add_pu8RdyStatus = (u8)Peripheral_BitBand(RCC->CR, PLLON) ;break;
            case RCC_CLK_HSE :*Add_pu8RdyStatus = (u8)Peripheral_BitBand(RCC->CR, HSEON) ;break;
            case RCC_CLK_HSI :*Add_pu8RdyStatus = (u8)Peripheral_BitBand(RCC->CR, HSION ) ;break;
            default : local_errorState = Rcc_enuInvalidClk ;break; 
        }
    }
    return local_errorState;
}

/**
 * This function configures the PLL (Phase-Locked Loop) settings in the RCC registers.
 * 
 * @param COPY_u8M This parameter represents the value to be set for the PLLM division factor.
 * It determines the division factor for the PLL input clock.
 * @param Copy_u16N This parameter represents the PLL multiplication factor.
 * @param Copy_u8P This parameter represents the PLL division factor for the main PLL (PLLCLK) output.
 * @param Copy_u8SrcPll This parameter is used to select the source of the PLL (Phase-Locked Loop) clock.
 * @param Copy_u8Q This parameter represents the PLL division factor for PLLQ.
 * 
 * @return a variable of type Rcc_tenuErrorStatus, which represents the error status of the function.
 */
Rcc_tenuErrorStatus Rcc_enuCnfgrPll(u8 COPY_u8M , u16 Copy_u16N , u8 Copy_u8P , u8 Copy_u8SrcPll , u8 Copy_u8Q){
    Rcc_tenuErrorStatus local_errorState = Rcc_enuOk;

    if (Copy_u8Q <= 1){
        local_errorState = RCC_enuInvalid_Q_Error;
    }else if (Copy_u8P > 4){
        local_errorState = RCC_enuInvalid_P_Error;
    }else if (COPY_u8M <= 1){
        local_errorState = RCC_enuInvalid_M_Error;
    }
    switch (Copy_u16N){
        case 0: local_errorState = RCC_enuInvalid_N_Error; break;
        case 1: local_errorState = RCC_enuInvalid_N_Error; break;
        case 432: local_errorState = RCC_enuInvalid_N_Error; break;
        case 433: local_errorState = RCC_enuInvalid_N_Error; break;
        case 511: local_errorState = RCC_enuInvalid_N_Error; break;
    }
    RCC->PLLCFGR &= 0xFFFFFFE0;
    RCC->PLLCFGR |= COPY_u8M;
    
    RCC->PLLCFGR &= 0xFFFF803F;
    RCC->PLLCFGR |= (Copy_u16N << 6);
    
    RCC->PLLCFGR &= 0xFFFCFFFF;
    RCC->PLLCFGR |= (Copy_u8P << 16);
    
    RCC->PLLCFGR &= 0xF0FFFFFF;
    RCC->PLLCFGR |= (Copy_u8Q << 22);

    u8 PLLsourceState = 0;
    Rcc_enuCheckCLk(Copy_u8SrcPll, &PLLsourceState);
    if (PLLsourceState != 1){
        local_errorState = RCC_enuInvalid_ScrPll_Error;
    } 
    Peripheral_BitBand(RCC->PLLCFGR,22) = Copy_u8SrcPll;

    return local_errorState;
}

/**
 * This function enables a peripheral on a specific bus in the RCC peripheral.
 * 
 * @param Copy_u8PeriphralBus This parameter represents the bus on which the peripheral is connected.
 * @param Copy_u32Periphral This parameter represents the peripheral that you want to enable. 
 * 
 * @return  a variable of type Rcc_tenuErrorStatus, which represents the error status of the function.
 */
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

/**
 * This function disables a peripheral on a specific bus in the RCC peripheral.
 * 
 * @param Copy_u8PeriphralBus This parameter represents the bus on which the peripheral is connected.
 * @param Copy_u32Periphral This parameter represents the peripheral that you want to disable. 
 * 
 * @return  a variable of type Rcc_tenuErrorStatus, which represents the error status of the function.
 */
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

/**
 * This function configures the bus prescalers for the RCC module.
 * 
 * @param Copy_u32Prescaler The parameter represents the desired prescaler value for configuring the 
 * bus prescaler in the RCC (Reset and Clock Control) module. The value of Copy_u32Prescaler determines 
 * the division factor for the respective bus prescaler.
 * 
 * @return a variable of type Rcc_tenuErrorStatus, which represents the error status of the function.
 */
Rcc_tenuErrorStatus Rcc_enuCfgBusPrescalers(u32 Copy_u32Prescaler){
    Rcc_tenuErrorStatus local_errorState = Rcc_enuOk;
    u8 countDefaultCases = 0 ;
    switch(Copy_u32Prescaler){
        case RCC_APB2_NOTDIV: RCC->CFGR &= RCC_APB2_NOTDIV ;break;
        case RCC_APB1_NOTDIV: RCC->CFGR &= RCC_APB1_NOTDIV ;break;
        case RCC_AHB_NOTDIV : RCC->CFGR &= RCC_AHB_NOTDIV  ;break;
        default : countDefaultCases ++;
    }

    switch(Copy_u32Prescaler){
        case RCC_APB2_DIV2 : RCC->CFGR |= RCC_APB2_DIV2  ;break;
        case RCC_APB2_DIV4 : RCC->CFGR |= RCC_APB2_DIV4  ;break;
        case RCC_APB2_DIV8 : RCC->CFGR |= RCC_APB2_DIV8  ;break;
        case RCC_APB2_DIV16: RCC->CFGR |= RCC_APB2_DIV16 ;break;
        default : countDefaultCases ++;
    }

    switch(Copy_u32Prescaler){
        case RCC_APB1_DIV2 : RCC->CFGR |= RCC_APB1_DIV2  ;break;
        case RCC_APB1_DIV4 : RCC->CFGR |= RCC_APB1_DIV4  ;break;
        case RCC_APB1_DIV8 : RCC->CFGR |= RCC_APB1_DIV8  ;break;
        case RCC_APB1_DIV16: RCC->CFGR |= RCC_APB1_DIV16 ;break;
        default : countDefaultCases ++;
    }

    switch(Copy_u32Prescaler){
        case RCC_AHB_DIV2   : RCC->CFGR |= RCC_AHB_DIV2   ;break;
        case RCC_AHB_DIV4   : RCC->CFGR |= RCC_AHB_DIV4   ;break;
        case RCC_AHB_DIV8   : RCC->CFGR |= RCC_AHB_DIV8   ;break;
        case RCC_AHB_DIV16  : RCC->CFGR |= RCC_AHB_DIV16  ;break;
        case RCC_AHB_DIV64  : RCC->CFGR |= RCC_AHB_DIV64  ;break;
        case RCC_AHB_DIV128 : RCC->CFGR |= RCC_AHB_DIV128 ;break;
        case RCC_AHB_DIV256 : RCC->CFGR |= RCC_AHB_DIV256 ;break;
        case RCC_AHB_DIV512 : RCC->CFGR |= RCC_AHB_DIV512 ;break;
        default : countDefaultCases ++;
    }

    if (countDefaultCases == 4){
        local_errorState = Rcc_enuWrongBusPrescalerError;
    }


    return local_errorState;
}
