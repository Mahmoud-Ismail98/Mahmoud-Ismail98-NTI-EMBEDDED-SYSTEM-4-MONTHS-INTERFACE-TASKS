#include "std_types.h"
#include "util.h"
#include "STK.h" 


void MSTK_voidInit(void)
{
	MSTK -> MSTK_CTRL = 0x00000002;
}
Systick_tenuErrorStatus MSTK_voidTimerState(MSTK_State_t Copy_MstkState)
{
	Systick_tenuErrorStatus ERROR_STATE = Systick_enuOk;
	if (Copy_MstkState == MSTK_DISABLE )
	{
	  CLR_BIT(	MSTK -> MSTK_CTRL , 0);
	}
	else if (Copy_MstkState == MSTK_ENABLE)
	{
		SET_BIT(	MSTK -> MSTK_CTRL , 0);
	}
	else
	{
		ERROR_STATE = Systick_enuErrorTimeMs;
	}
	return ERROR_STATE;
}
Systick_tenuErrorStatus MSTK_voidIntStatus(MSTK_INT_State_t Copy_MstkIntState)
{
	Systick_tenuErrorStatus ERROR_STATE = Systick_enuOk;
	
	if (Copy_MstkIntState == MSTK_INT_DISABLE )
	{
     CLR_BIT(	MSTK -> MSTK_CTRL , 1);
	}
	else if (Copy_MstkIntState == MSTK_INT_ENABLE)
	{
		SET_BIT(	MSTK -> MSTK_CTRL , 1);
	}
	else
	{
		ERROR_STATE = Systick_enuErrorStatus;
	}
	return ERROR_STATE;
}


void _delay_ms(u32 Copy_u32Time)
{
	// Initialize Timer
	MSTK_voidInit(); // INT --> Enable , AHB/8 , Timer = Stop
	// Polling
	MSTK_voidIntStatus(MSTK_INT_DISABLE);
	// load reg
	MSTK->MSTK_LOAD = Copy_u32Time * 2000;
	// val reg (Reset --> Reload)
	MSTK->MSTK_VAL = 0;
	//Enable Timer
	MSTK_voidTimerState(MSTK_ENABLE);
	// wait Flag Polling
	while(MSTK_u8ReadFlag() == 0);
	// stop Timer
	MSTK_voidTimerState(MSTK_DISABLE);
}
void _delay_us(u32 Copy_u32Time)
{
	// Initialize Timer
	MSTK_voidInit(); // INT --> Enable , AHB/8 , Timer = Stop
	// Polling
	MSTK_voidIntStatus(MSTK_INT_DISABLE);
	// load reg
	MSTK->MSTK_LOAD = Copy_u32Time * 2;
	// val reg (Reset --> Reload)
	MSTK->MSTK_VAL = 0;
	//Enable Timer
	MSTK_voidTimerState(MSTK_ENABLE);
	// wait Flag Polling
	while(MSTK_u8ReadFlag() == 0);
	// stop Timer
	MSTK_voidTimerState(MSTK_DISABLE);
	
}


u8 MSTK_u8ReadFlag(void)
{
		return (GET_BIT(MSTK->MSTK_CTRL,16));

}
void MSTK_voidStart(u32 Copy_u32Preload)
{
	
	// load reg
	MSTK->MSTK_LOAD = Copy_u32Preload;
	// val reg (Reset --> Reload)
	MSTK->MSTK_VAL = 0;
	//Enable Timer
	MSTK_voidTimerState(MSTK_ENABLE);
	// wait Flag Polling
	while(MSTK_u8ReadFlag() == 0);
}