

#include "stm32f401xc.h"
#include "std_types.h"
#include "bit_math.h"
#include "SysTick_prv.h"
#include "SysTick_cfg.h"
#include "SysTick.h"


static u32 sgl_u32_SystemClock  = F_CPU;
static u32 sgl_u32_NumOfOVF     = FALSE;
static u32 sgl_u32_RemainTicks  = FALSE;
static u8  sgl_u8_IntStatus     = SYSTICK_TICKINT;
Systick_Cbf gl_Systick_Cbf      = PTR_NULL;
/*PROTOYPE FOR Systick_Init FUNCTION */
Systick_tenuErrorStatus Systick_Init(u32 Copy_TimeMs)
{
	// return status
	Systick_tenuErrorStatus loc_enu_Systick_returnValue = Systick_enuOk;
	// local to store desired ticks
	f32 loc_f32_tickTime     = (f32)SYSTICK_CLKSOURCE*1000000/SystemCoreClock;
	u32 loc_u32_DesiredTicks = ((Copy_TimeMs*TOMICROCONV)/loc_f32_tickTime);
  sgl_u32_NumOfOVF         = loc_u32_DesiredTicks/MAX_REG_TICKS;
	sgl_u32_RemainTicks      = (loc_u32_DesiredTicks%MAX_REG_TICKS);
	sgl_u32_NumOfOVF++;
	STK_REG(STK_LOAD)        = sgl_u32_RemainTicks;
	STK_REG(STK_VAL)         = FALSE;
	// Disable Systick To Make CFG
	CLR_BIT(STK_REG(STK_CTRL),ENABLE);
	// config prescaller
	#if      SYSTICK_CLKSOURCE == SYSTICK_AHB_DIV_8
	// clear CLKSOURCE Bit in STK_CTRL Reg
	CLR_BIT(STK_REG(STK_CTRL),CLKSOURCE);
	
	#elif    SYSTICK_CLKSOURCE == SYSTICK_AHB_PROCESSOR
	
	// set CLKSOURCE Bit in STK_CTRL Reg
	SET_BIT(STK_REG(STK_CTRL),CLKSOURCE);
	
	#else
	
	// cfg error
	#error "ERROR IN SYSTICK_CLKSOURCE MACRO CFG"
	
	#endif
	
	// config Interrupt
	#if      SYSTICK_TICKINT == SYSTICK_INT_DISABLE
	
	NVIC_DisableIRQ(SysTick_IRQn);
	// clear TICKINT Bit in STK_CTRL Reg
	CLR_BIT(STK_REG(STK_CTRL),TICKINT);
	#elif    SYSTICK_TICKINT == SYSTICK_INT_ENABLE
	NVIC_EnableIRQ(SysTick_IRQn);
	// set TICKINT Bit in STK_CTRL Reg
	SET_BIT(STK_REG(STK_CTRL),TICKINT);
	
	#else
	
	// cfg error
	#error "ERROR IN SYSTICK_TICKINT MACRO CFG"
	
	#endif
	
	return loc_enu_Systick_returnValue;
}
/*PROTOYPE FOR Systick_RegisterCbf FUNCTION */
Systick_tenuErrorStatus Systick_RegisterCbf(Systick_Cbf Add_pfCbf)
{
	// return status
	Systick_tenuErrorStatus loc_enu_Systick_returnValue = Systick_enuOk;
	
	if (Add_pfCbf == PTR_NULL)
	{
		loc_enu_Systick_returnValue = Systick_enuErrorNullPointer;
	}
	else
	{
		gl_Systick_Cbf = Add_pfCbf;
	}
	return loc_enu_Systick_returnValue;
}
/*PROTOTYPE FOR Systick_Start FUNCTION*/
void Systick_Start(void)
{
	u32 loc_u32_PollingCounter = FALSE;
	// start counter
	CLR_BIT(STK_REG(STK_CTRL),COUNTFLAG);
	SET_BIT(STK_REG(STK_CTRL),ENABLE);
	if ( sgl_u8_IntStatus == SYSTICK_INT_ENABLE)
	{
		// do nothinge
	}
	else
	{
		while (1)
		{
			while(!GET_BIT(STK_REG(STK_CTRL),COUNTFLAG));
			loc_u32_PollingCounter++;
			if (loc_u32_PollingCounter == 1)
			{
				STK_REG(STK_LOAD)   = MAX_REG_TICKS-1;
			}
			if ( loc_u32_PollingCounter == sgl_u32_NumOfOVF)
				{
					STK_REG(STK_LOAD)   = sgl_u32_RemainTicks;
					break;
				}
		}
		
	}
	
}


/*PROTOTYPE FOR Systick_Stop FUNCTION*/
void Systick_Stop(void)
{
	CLR_BIT(STK_REG(STK_CTRL),ENABLE);
	STK_REG(STK_LOAD)        = sgl_u32_RemainTicks;
	STK_REG(STK_VAL)         = FALSE;
}

void Systick_UpdateFreq(u32 Copy_CPU_FREQ)
{
	sgl_u32_SystemClock = Copy_CPU_FREQ;
}



void SysTick_Handler(void)
{
	static u32 sloc_u32_Counter = FALSE;
	sloc_u32_Counter++;
	if (sloc_u32_Counter == 1)
	{
		STK_REG(STK_LOAD)   = MAX_REG_TICKS-1;
	}
	if ( sloc_u32_Counter == sgl_u32_NumOfOVF)
	{
		 if (gl_Systick_Cbf != PTR_NULL)
		 {
			 gl_Systick_Cbf();
		 }
		 STK_REG(STK_LOAD)   = sgl_u32_RemainTicks;
		 sloc_u32_Counter    = FALSE;
	}
}