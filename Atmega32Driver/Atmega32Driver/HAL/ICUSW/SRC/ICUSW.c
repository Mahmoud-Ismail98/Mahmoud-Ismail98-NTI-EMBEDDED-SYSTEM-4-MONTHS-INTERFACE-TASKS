/*
 * ICUSW.c
 *
 * Created: 10/27/2023 12:53:46 PM
 *  Author: HP
 */ 
#include "../../../services/Std_types.h"
#include "../../../services/Bit_utils.h"
#include "../../../MCAL/DIO/INC/DIO.h"
#include "../../../MCAL/TIMER/INC/TIMER.h"
#include "../../../MCAL/EXT_INT/INC/EXT.h"
#include "../INC/ICUSW.h"
#include "../INC/ICUSW_prv.h"
#include "../INC/ICUSW_cfg.h"

void EXT_INTCallBackfunction(void);

volatile static u16 ICUSW_u16OnPeriod;
volatile static u16 ICUSW_u16OffPeriod;

void ICUSW_voidEnableSWICU(void)
{
	Timer_voidInit();
	EXT_InterruptPirefralEnable(EXT_0,EXT_RISING_EDGE);
	EXTINT_voidSetCallBack(&EXT_INTCallBackfunction,EXT_0);
}
void ICUSW_voidDisableSWICU(void)
{
	EXT_InterruptPirefralDisable(EXT_0);
}


ICUSW_ErrorState ICUSW_u8GetOnPeriod(pu16 Copy_pu16OnPeriod)
{
    ICUSW_ErrorState Loc_u8ReturnState = ICUSW_OK;
    if (Copy_pu16OnPeriod == NULL)
    {
        Loc_u8ReturnState = ICUSW_NULLPTR;
    }
    else
    {
        *Copy_pu16OnPeriod = ICUSW_u16OnPeriod;
    }
    return Loc_u8ReturnState;
}

ICUSW_ErrorState ICUSW_u8GetTotalPeriod(pu32 Copy_pu32TotalPeriod)
{
    ICUSW_ErrorState Loc_u8ReturnState = ICUSW_OK;
    if (Copy_pu32TotalPeriod == NULL)
    {
        Loc_u8ReturnState = ICUSW_NULLPTR;
    }
    else
    {
        *Copy_pu32TotalPeriod = (u32)(ICUSW_u16OnPeriod + ICUSW_u16OffPeriod);
    }
    return Loc_u8ReturnState;
}

ICUSW_ErrorState ICUSW_u8GetDutyCycle(pu8 Copy_pu8DutyCycle)
{
    ICUSW_ErrorState Loc_u8ReturnState = ICUSW_OK;
    if (Copy_pu8DutyCycle == NULL)
    {
        Loc_u8ReturnState = ICUSW_NULLPTR;
    }
    else
    {
        *Copy_pu8DutyCycle = (u8)(((u32)ICUSW_u16OnPeriod * 100) / (ICUSW_u16OnPeriod + ICUSW_u16OffPeriod));
    }
    return Loc_u8ReturnState;
}

void EXT_INTCallBackfunction(void)
{
	volatile static u16 Local_u16CounterValue = 0;
	volatile static u16 Local_u16OldValue     = 0;
	volatile static u8  Local_u8Flag          = 0;
	Timer_voidGetTimer1CounterValue(&Local_u16CounterValue);
	if(Local_u8Flag == 0)/* Raising Edge */
	{
		/* Measure Off Period */
		ICUSW_u16OffPeriod = Local_u16CounterValue - Local_u16OldValue;
		/* Trig source int Falling edge */
		EXT_InterruptPirefralEnable(EXT_0,EXT_FALLING_EDGE);
 
		Local_u8Flag = 1;

	}
	else if(Local_u8Flag == 1)
	{
		/* Measure On Period */
		ICUSW_u16OnPeriod = Local_u16CounterValue - Local_u16OldValue;
		/* Trig source int Raising edge */
		EXT_InterruptPirefralEnable(EXT_0,EXT_RISING_EDGE);

		Local_u8Flag = 0;

	}
	Local_u16OldValue = Local_u16CounterValue;
}