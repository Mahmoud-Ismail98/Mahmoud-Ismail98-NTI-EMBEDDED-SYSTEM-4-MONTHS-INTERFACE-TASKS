/*
 * GIE.c
 *
 * Created: 10/22/2023 3:29:07 PM
 *  Author: ahmed radwan
 */ 
#include "../../SERVICES/Standard_Data_Types.h"
#include "../../SERVICES/Bit_Wise_Operations.h"
#include "GIE_PRIV.h"
#include "GIE_CFG.h"
#include "GIE.h"

void GIE_INIT(void)
{
 	switch(GIE_STATE)
	 {
		 case ENABLE_GIE:
		 SREG=8;
		 SET_BIT(SREG,7);
		 break;
		 case DISABLE_GIE:
		 CLR_BIT(SREG,7);
		 break;
	 }
	 
}
void GIE_Enable(void)
{
	SET_BIT(SREG,7);
}
void GIE_Disable(void)
{
	CLR_BIT(SREG,7);
}
u8 GIE_Get_Status(void)
{
	return GET_BIT(SREG,7);
}