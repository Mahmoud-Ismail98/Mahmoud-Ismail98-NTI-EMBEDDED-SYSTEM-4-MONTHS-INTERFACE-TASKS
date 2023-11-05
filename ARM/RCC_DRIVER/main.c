#include "STD_TYPES.h"
#include "BIT_UTILS.h"
#include "RCC.h"

int main()
{
	
	Rcc_enuSelectSysCLk(RCC_CLK_HSI,RCC_CLK_HSI);
	while(1)
	{
	}
	return 0;
}
