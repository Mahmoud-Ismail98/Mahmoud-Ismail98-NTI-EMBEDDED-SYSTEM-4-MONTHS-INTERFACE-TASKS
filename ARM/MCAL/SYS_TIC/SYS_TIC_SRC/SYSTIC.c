/*
 * SYSTIC.c
 *
 *  Created on: Nov 7, 2023
 *      Author: computer store
 */

#include<MCAL/SYS_TIC/SYS_TIC_Includes/SYSTIC.h>

void (* Systick_GP_Cbf) (void);

Systick_tenuErrorStatus Systick_Init(SysTic_CFG_t *SysTic_CFG)
{
	Systick_GP_Cbf = SysTic_CFG->Systick_Cbf;

	//set the prescaler
	Cortex_M4_SysTic->CTRL &= ~(1 << 2);
	Cortex_M4_SysTic->CTRL |= SysTic_CFG->CLKSOURCE;

	//set the interrupt state
	Cortex_M4_SysTic->CTRL &= ~(1 << 1);
	Cortex_M4_SysTic->CTRL |= SysTic_CFG->TICKINT_State;
	return Systick_enuOk;
}

void Systick_Start(uint64 Time_us)
{
	//assume that the AHB Clock is 16 MHZ because we cannot check the flags that indicates
	// which clock is selected as system clock in keil
	uint32 sysclock = 16;
	uint32 prescaler = 8;
	if(((Cortex_M4_SysTic->CTRL >> 2) & 1) == 1)
	{
		prescaler = 1;
	}
	uint32 TicTime = 1000000 * prescaler/sysclock;
	uint32 N_Tics = Time_us*1000000 / TicTime ;
	Cortex_M4_SysTic->LOAD = (N_Tics & 0x00FFFFFF);
	Cortex_M4_SysTic->CTRL |= SYSTICK_EN;

}

void Systick_Stop(void)
{
	Cortex_M4_SysTic->CTRL &= ~(1 << 0);
	Cortex_M4_SysTic->LOAD = 0;
	Cortex_M4_SysTic->VAL = 0;
}
