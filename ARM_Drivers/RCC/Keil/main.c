#include "std_types.h"
#include "utile.h"
#include "RCC.h"

int main (void){
	u8 Ready;
	Rcc_enuCnfgrPll(4,431,RCC_Q_DIVBY_2,RCC_PLLSRC_HSI,RCC_Q_DIVBY_4);
	Rcc_enuControlCLk(RCC_CNTROL_HSIOFF,RCC_CNTROL_HSEON,RCC_CNTROL_PLLOFF);
	Rcc_enuSelectSysCLk(RCC_CLK_PLL);
	Rcc_enuCheckCLk(RCC_CLK_PLL,&Ready);
	Rcc_enuCfgBusPrescalers(RCC_AHB_DIV2);
	Rcc_enuEnablePeriphral(RCC_REGISTER_AHB1,AHB1_GPIOA_EN);
	Rcc_enuDisablePeriphral(RCC_REGISTER_AHB1,AHB1_GPIOA_EN);
	while(1);
	return 0;
}