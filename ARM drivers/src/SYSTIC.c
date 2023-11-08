
#include "Std_types.h"
#include "Bit_utils.h"

#include "SYSTIC.h"
#include "SYSTIC_prv.h"
#include "SYSTIC_cfg.h"

void STK_voidInit(void)
{
	#if STK_CLK == AHB 
	SET_BIT(STK->CTRL,2);
	#elif	STK_CLK == AHB_8
	CLR_BIT(STK->CTRL,2);
	#endif
	
	#if STK_INT == STK_INTenable 
	SET_BIT(STK->CTRL,1);
	#elif	STK_INT == STK_INTdisable
	CLR_BIT(STK->CTRL,1);
	#endif
	SET_BIT(STK->CTRL,0);
}
void SET_DELAY(u32 MicroSecond)
{
	u32 NumOfTicks = MicroSecond*2;
	u32 NumOfOVS = NumOfTicks / 16777216;
	u32 NumOfRestTicks = NumOfTicks%16777216;
	while(NumOfOVS !=0)
	{
		STK->LOAD = 16777215;
		if(GET_BIT(STK->CTRL,16) == 1)
		{
			CLR_BIT(STK->CTRL,16);
		}
		NumOfOVS--;
	}
	STK->LOAD = NumOfRestTicks;
	while(GET_BIT(STK->CTRL,16) != 1);
	CLR_BIT(STK->CTRL,16);
}