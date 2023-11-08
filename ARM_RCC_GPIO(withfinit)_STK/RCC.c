
#include "STD_TYPES.h"
#include "BIT_UTILS.h"
#include "RCC.h"
#include "RCC_prv.h"
#include "RCC_cfg.h"




Rcc_tenuErrorStatus Rcc_enuSelectSysCLk(u8 Copy_u8SysClk, u8 Copy_u8OldSysClk) {
    Rcc_tenuErrorStatus RCC_enuErrorState = Rcc_enuOk;
    u8 Counter = 0;
    if (Copy_u8SysClk != RCC_CLK_HSE && Copy_u8SysClk != RCC_CLK_HSI && Copy_u8SysClk != RCC_CLK_PLL) {
        RCC_enuErrorState = RCC_enuInvalid_ScrPll_Error;
    } else {
        switch (Copy_u8SysClk) {
            case RCC_CLK_HSE:
                if (!GET_BIT(MRCC->CR, 16U)) {
                    SET_BIT(MRCC->CR, 16U);
                } else {
                    RCC_enuErrorState = RCC_enuPll_IS_On_Error;
                }

                /*Disable BYP*/
                CLR_BIT(MRCC->CR, 18U);
                /* Input system Clk */
                SET_BIT(MRCC->CFGR, 0U);
                CLR_BIT(MRCC->CFGR, 1U);
                break;

            case RCC_CLK_HSI:
                if (!GET_BIT(MRCC->CR, 0U)) {
                    SET_BIT(MRCC->CR, 0U);
                } else {
                    RCC_enuErrorState = RCC_enuPll_IS_On_Error;
                }

                /* Input system Clk */
                CLR_BIT(MRCC->CFGR, 0U);
                CLR_BIT(MRCC->CFGR, 1U);
                break;

            case RCC_CLK_PLL:
                /*1-Enable HSE */
                if (!GET_BIT(MRCC->CR, 16U)) {
                    SET_BIT(MRCC->CR, 16U);
                } else {
                    RCC_enuErrorState = RCC_enuPll_IS_On_Error;
                }

                /*2- EN PLL*/
                if (!GET_BIT(MRCC->CR, 24U)) {
                    SET_BIT(MRCC->CR, 24U);
                } else {
                    RCC_enuErrorState = RCC_enuPll_IS_On_Error;
                }

                break;
            default:
                break;
        }
    }
    return RCC_enuErrorState;
}


Rcc_tenuErrorStatus Rcc_enuControlCLk(u8 Copy_u8ControlHSI, u8 Copy_u8ControlHSE, u8 Copy_u8ControlPLL) {
    Rcc_tenuErrorStatus RCC_enuErrorState = Rcc_enuOk;

    if (Copy_u8ControlHSI != RCC_CNTROL_HSION && Copy_u8ControlHSI != RCC_CNTROL_HSIOFF) {
        RCC_enuErrorState = RCC_enuUnLogicActionError;
    } else {
        if (Copy_u8ControlHSI == RCC_CNTROL_HSION) {
            if (!GET_BIT(MRCC->CR, 0U)) {
                SET_BIT(MRCC->CR, 0U); 
            } else {
                RCC_enuErrorState = RCC_enuPll_IS_On_Error;
            }
        } else if (Copy_u8ControlHSI == RCC_CNTROL_HSIOFF) {
            if (GET_BIT(MRCC->CR, 0U)) {
                CLR_BIT(MRCC->CR, 0U); 

            } else {
                RCC_enuErrorState = RCC_enuPll_IS_On_Error;
            }
        }
    }

    if (Copy_u8ControlHSE != RCC_CNTROL_HSEON && Copy_u8ControlHSE != RCC_CNTROL_HSEOFF) {
        RCC_enuErrorState = RCC_enuUnLogicActionError;
    } else {
        if (Copy_u8ControlHSE == RCC_CNTROL_HSEON) {
            if (!GET_BIT(MRCC->CR, 16U)) {
                SET_BIT(MRCC->CR, 16U); 
            } else {
                RCC_enuErrorState = RCC_enuPll_IS_On_Error;
            }
        } else if (Copy_u8ControlHSE == RCC_CNTROL_HSEOFF) {
            if (GET_BIT(MRCC->CR, 16U)) {
                CLR_BIT(MRCC->CR, 16U); 
            } else {
                RCC_enuErrorState = RCC_enuPll_IS_On_Error;
            }
        }
    }

    if (Copy_u8ControlPLL != RCC_CNTROL_PLLON && Copy_u8ControlPLL != RCC_CNTROL_PLLOFF) {
        RCC_enuErrorState = RCC_enuUnLogicActionError;
    } else {
        if (Copy_u8ControlPLL == RCC_CNTROL_PLLON) {
            if (!GET_BIT(MRCC->CR, 24U)) {
                SET_BIT(MRCC->CR, 24U); 
            } else {
                RCC_enuErrorState = RCC_enuPll_IS_On_Error;
            }
        } else if (Copy_u8ControlPLL == RCC_CNTROL_PLLOFF) {
            if (GET_BIT(MRCC->CR, 24U)) {
                CLR_BIT(MRCC->CR, 24U); 
            } else {
                RCC_enuErrorState = RCC_enuPll_IS_On_Error;
            }
        }
    }

    return RCC_enuErrorState;
}


Rcc_tenuErrorStatus Rcc_enuCheckCLk(u8 Copy_u8CLk, pu8 Add_pu8RdyStatus) {
    Rcc_tenuErrorStatus RCC_enuErrorState = Rcc_enuOk;

    if (Copy_u8CLk != RCC_CLK_HSI && Copy_u8CLk != RCC_CLK_HSE && Copy_u8CLk != RCC_CLK_PLL) {
        RCC_enuErrorState = RCC_enuUnLogicActionError;
    } else {
        switch (Copy_u8CLk) {
            case RCC_CLK_HSI:
                *Add_pu8RdyStatus = GET_BIT(MRCC->CR, 0U);
                break;
            case RCC_CLK_HSE:
                *Add_pu8RdyStatus = GET_BIT(MRCC->CR, 16U);
                break;
            case RCC_CLK_PLL:
                *Add_pu8RdyStatus = GET_BIT(MRCC->CR, 24U);
                break;
            default:
                break;
        }
    }

    return RCC_enuErrorState;
}


Rcc_tenuErrorStatus Rcc_enuCnfgrPll(u8 COPY_u8M, u16 Copy_u16N, u8 Copy_u8P, u8 Copy_u8SrcPll, u8 Copy_u8Q) {
    Rcc_tenuErrorStatus RCC_enuErrorState = Rcc_enuOk;

    switch (Copy_u8SrcPll) {
        case RCC_PLLSRC_HSI:
            CLR_BIT(MRCC->PLLCFGR, 22);
            MRCC->PLLCFGR |= COPY_u8M << 0;
            MRCC->PLLCFGR |= Copy_u16N << 6;
            MRCC->PLLCFGR |= Copy_u8P << 16;
            MRCC->PLLCFGR |= Copy_u8Q << 24;
            break;

        case RCC_PLLSRC_HSE:
            SET_BIT(MRCC->PLLCFGR, 22);
            MRCC->PLLCFGR |= COPY_u8M << 0;
            MRCC->PLLCFGR |= Copy_u16N << 6;
            MRCC->PLLCFGR |= Copy_u8P << 16;
            MRCC->PLLCFGR |= Copy_u8Q << 24;
            break;

        default:
            RCC_enuErrorState = RCC_enuInvalid_ScrPll_Error;
            break;
    }

    return RCC_enuErrorState;
}


Rcc_tenuErrorStatus Rcc_enuEnablePeriphral(u8 Copy_u8PeriphralBus, u32 Copy_u32Periphral) {
    Rcc_tenuErrorStatus RCC_enuErrorState = Rcc_enuOk;

    switch (Copy_u8PeriphralBus) {
        case RCC_REGISTER_AHB1:
            MRCC->AHB1ENR |= Copy_u32Periphral;
            break;
        case RCC_REGISTER_AHB2:
            MRCC->AHB2ENR |= Copy_u32Periphral;
            break;
        case RCC_REGISTER_APB1:
            MRCC->APB1ENR |= Copy_u32Periphral;
            break;
        case RCC_REGISTER_APB2:
            MRCC->APB2ENR |= Copy_u32Periphral;
            break;
        default:
            RCC_enuErrorState = Rcc_enuWrongPeriphralBusError;
            break;
    }

    return RCC_enuErrorState;
}


Rcc_tenuErrorStatus Rcc_enuDisablePeriphral(u8 Copy_u8PeriphralBus, u32 Copy_u32Periphral) {
    Rcc_tenuErrorStatus RCC_enuErrorState = Rcc_enuOk;

    switch (Copy_u8PeriphralBus) {
        case RCC_REGISTER_AHB1:
            MRCC->AHB1ENR &= ~Copy_u32Periphral;
            break;
        case RCC_REGISTER_AHB2:
            MRCC->AHB2ENR &= ~Copy_u32Periphral;
            break;
        case RCC_REGISTER_APB1:
            MRCC->APB1ENR &= ~Copy_u32Periphral;
            break;
        case RCC_REGISTER_APB2:
            MRCC->APB2ENR &= ~Copy_u32Periphral;
            break;
        default:
            RCC_enuErrorState = Rcc_enuWrongPeriphralBusError;
            break;
    }

    return RCC_enuErrorState;
}
