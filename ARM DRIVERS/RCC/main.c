#include "std_types.h"
#include "bit_utils.h"

#include "RCC.h"

int main(void){
    u8 Loc;
    u8* p = NULL;
    Rcc_enuSelectSysCLk(RCC_CLK_HSE);
    Rcc_enuCheckCLk(RCC_CLK_HSE, &Loc);
    Rcc_enuCheckCLk(RCC_CLK_HSI,&Loc);
    Rcc_enuCheckCLk(RCC_CLK_PLL, p);
    Rcc_enuControlCLk(RCC_CNTROL_HSION, RCC_CNTROL_HSEOFF, RCC_CNTROL_PLLON);
	
	return 0;
}
