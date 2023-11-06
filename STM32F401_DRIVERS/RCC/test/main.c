
#include "Std_types.h"
#include "Bit_utils.h"
#include "rcc.h"

//u8 check_clk_on_flag;
int main(void)
{
	
	
//	Rcc_enuCheckCLk(RCC_CLK_HSE,&check_clk_on_flag);
//	Rcc_enuCnfgrPll(u8 COPY_u8M , u16 Copy_u16N , u8 Copy_u8P , u8 Copy_u8SrcPll , u8 Copy_u8Q);
// PLL_VCO = (HSE_VALUE or HSI_VALUE / PLL_M) * PLL_N 	
//COPY_u8M=16 : PLL_M division to 16 to get the comparison frequency as 1 MHz 
//	Copy_u16N = 192    PLL_N 192*1MHZ (192),
// Copy_u8SrcPll=0 ---0: HSI clock selected as PLL
// SYSCLK = PLL_VCO / PLL_P */	
//Copy_u8P=1 (VCO/ PLLP(2))

Rcc_enuCnfgrPll(16,192,1,0,0);	
Rcc_enuSelectSysCLk(RCC_CLK_PLL,RCC_HSE_disable);
Rcc_enuControlCLk(RCC_CNTROL_HSION,RCC_CNTROL_HSEON,RCC_CNTROL_PLLON);	
Rcc_enuEnablePeriphral(RCC_REGISTER_AHB1 , AHB1_GPIOA_EN);
Rcc_enuCfgBusPrescalers(RCC_AHB_DIV4);	
//Rcc_enuEnablePeriphral(RCC_REGISTER_AHB1 , AHB1_GPIOB_EN);	

//Rcc_enuDisablePeriphral(RCC_REGISTER_AHB1 ,AHB1_GPIOA_EN);	

	return 0;
}	




