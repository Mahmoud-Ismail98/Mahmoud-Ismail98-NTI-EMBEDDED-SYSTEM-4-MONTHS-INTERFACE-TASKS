#include "Std_types.h"
#include "Bit_utils.h"

#include "TIMER0_int.h"
#include "TIMER0_prv.h"
#include "TIMER0_cfg.h"

volatile u32 Global_u32NumOfTicKs = 0; 
volatile u32 Global_u32NumOfOVs   = 0;
volatile u32 Global_u32TempOfOVs  = 0;
void (*Global_voidPtrToFunc)(void)=NULL;
void TIMER0_voidInit(void)
{
	#if   TIMER0_MODE == Normal_MODE
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);

	#elif TIMER0_MODE == Phase_CorrectPWM_MODE
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	#elif TIMER0_MODE == CTC_MODE
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	#elif TIMER0_MODE == FastPWM_MODE
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	#endif
	
	TCCR0 = (TCCR0&0b11001111)|CTC_PWMOUTMODE;
	TCCR0 = (TCCR0&0b11111000)|Clock_PRESCALLER;
	
}
void TIMER0_voidSetCallBack(void(*Ptr_voidCallBackFunc)(void))
{
	Global_voidPtrToFunc = Ptr_voidCallBackFunc;
}
void TIMER0_voidInterruptEnable(u8 Copy_u8InterruptType)
{
	TIMSK = (TIMSK&0b11111100)|Copy_u8InterruptType;
}
void TIMER0_voidSetTimeOnNormalMode(u32 Copy_u32MicroS,u32 prescaller)
{
	f32 Local_f32TimFreq   = (f32)AVR_CLOCK/ prescaller;
	u32 Local_u32TimTicks  = (u32)(Copy_u32MicroS * Local_f32TimFreq);
	Global_u32NumOfTicKs   = Local_u32TimTicks % 256;
	Global_u32NumOfOVs     = Local_u32TimTicks / 256;
	Global_u32TempOfOVs    = Global_u32NumOfOVs;
	if (Global_u32NumOfOVs == 0)
	{
		TCNT0 = 256 - Global_u32NumOfTicKs;
	}
	else if(Global_u32NumOfOVs > 0)
	{
		TCNT0 = 0;
	}

}
void TIMER0_voidSetTimeOnCTCMode(u32 Copy_u32MicroS,u32 prescaller)
{
	f32 Local_f32TimFreq   = (f32)AVR_CLOCK /prescaller;
	u32 Local_u32TimTicks  = (u32)(Copy_u32MicroS * Local_f32TimFreq);
	Global_u32NumOfTicKs   = Local_u32TimTicks % 256;
	Global_u32NumOfTicKs   = Local_u32TimTicks % 256;
	Global_u32NumOfOVs     = Local_u32TimTicks / 256;
	Global_u32TempOfOVs    = Global_u32NumOfOVs;
	if (Global_u32NumOfOVs == 0)
	{
		TCNT0 = 0;
		OCR0  =  Global_u32NumOfTicKs;
	}
	else if(Global_u32NumOfOVs > 0)
	{
		TCNT0 = 0;
		OCR0  = 255;
	}	
}
void TIMER0_voidSetPWM(u8 Copy_u8PWMDutyperiod)
{
	OCR0 = Copy_u8PWMDutyperiod;
}
void __vector_10 (void)
{
	#if   TIMER0_interrupt == COMPARE_MATCH_INT
	static volatile u8 Flag=1;
	if(Flag == 2)
	{
		Global_voidPtrToFunc();
		Flag=1;
	}
	if(Global_u32NumOfOVs>0)
	{
		OCR0  = 255;
		Global_u32NumOfOVs--;
	}
	else if (Global_u32NumOfOVs == 0)
	{
		OCR0  =  Global_u32NumOfTicKs;
		Global_u32NumOfOVs = Global_u32TempOfOVs;
		Flag = 2;
	}
	#endif
}
void __vector_11 (void)
{

	#if   TIMER0_interrupt == OVERFLOW_INT
	static volatile u8 Flag=1;
	if(Flag == 2)
	{
		Global_voidPtrToFunc();
		Flag=1;
	}
	if(Global_u32NumOfOVs>0)
	{
		//TCNT0 = 0;
		Global_u32NumOfOVs--;
	}
	else if (Global_u32NumOfOVs == 0)
	{
		TCNT0 = 256 - Global_u32NumOfTicKs;
		Global_u32NumOfOVs = Global_u32TempOfOVs;
		Flag = 2;
	}
	#endif	
}
