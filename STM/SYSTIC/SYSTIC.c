/*
 * SYSTIC.c
 *
 *  Created on: Nov 8, 2023
 *      Author: Ismail
 */
#include "Std_types.h"
#include "Bit_utils.h"
#include "SYSTIC.h"
typedef struct{
	volatile u32 STK_CTRL;
	volatile u32 STK_LOAD;
	volatile u32 STK_VAL;
	volatile u32 STK_CALIB;

}SYSTICK_t;
#define SYSTICK_PRESCALER					SYSTICK_PRESCALER_DIV8
#define  SYSTICK_BASEADDRESS   			0xE000E010
#define  SYSTICK					((SYSTICK_t*)(SYSTICK_BASEADDRESS))
Systick_Cbf SystickCallback;
extern Systick_tenuErrorStatus Systick_Init(u32 Copy_TimeMs){
	Systick_tenuErrorStatus  Loc_enuErrorStatus= Systick_enuOk;
#if		 SYSTICK_PRESCALER ==  SYSTICK_PRESCALER_DIV8
	u32 LocStepCounter = (SysTick_CLKSource_HCLK/8000) ;

#else
	u32 LocStepCounter = SysTick_CLKSource_HCLK/1000 ;

#endif
	LocStepCounter *= Copy_TimeMs;
	if(LocStepCounter & VALIDATE_RELOADVALUE){
		Loc_enuErrorStatus = Systick_enuErrorTimeMs;

	}

	else{
		SYSTICK->STK_LOAD = LocStepCounter;
		SYSTICK->STK_VAL = 0;
		SYSTICK->STK_CTRL = SYSTICK_PRESCALER_DIV1;
	}
	return Loc_enuErrorStatus ;

}
extern void Systick_Start(void){
	SYSTICK->STK_CTRL |= SYSTICK_ENABLE;
}
extern void Systick_Stop(void){
	SYSTICK->STK_CTRL &= ~1;
}

extern Systick_tenuErrorStatus Systick_RegisterCbf(Systick_Cbf Add_pfCbf)
{
	Systick_tenuErrorStatus  Loc_enuErrorStatus= Systick_enuOk;
	if(Add_pfCbf == NULL)
	{
		Loc_enuErrorStatus = Systick_enuErrorNullPointer;
	}
	else
	{
		SystickCallback = Add_pfCbf;
	}

	return Loc_enuErrorStatus;
}


