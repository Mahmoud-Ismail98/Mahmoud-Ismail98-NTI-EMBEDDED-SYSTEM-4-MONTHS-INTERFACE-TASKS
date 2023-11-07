#include "Std_types.h"
#include "Bit_utils.h"
#include "systic.h"


typedef struct{
	volatile u32 STK_CTRL;
	volatile u32 STK_LOAD;
	volatile u32 STK_VAL;
	volatile u32 STK_CALIB;
}SYSTICK_struct;

#define SYSTICK ((volatile SYSTICK_struct * )(0xE000E010))

#define  AHB_8                      0
#define  Processor_clock_AHB        1
#define systick_Clock AHB_8   

Systick_Cbf SysticK_C_BF;
volatile u32 COUNTER_MS=0;
extern Systick_tenuErrorStatus Systick_Init(u32 Copy_TimeMs)
{
u32 num_tick_in_ms=0;	
Systick_tenuErrorStatus  Loc_enuErrorStatus= Systick_enuOk;
#if		 systick_Clock ==  AHB_8
	num_tick_in_ms=2000; //that when suppose we work on HSI	        
#elif
	num_tick_in_ms=16000;  //that when suppose we work on HSI	
    SET_BIT((SYSTICK->STK_CTRL),2)

#endif
	COUNTER_MS=Copy_TimeMs;
		SYSTICK->STK_LOAD = num_tick_in_ms;
		SYSTICK->STK_VAL = 0;
    SET_BIT((SYSTICK->STK_CTRL),1);    //ENABLE EXCEPTION PIN 
	return Loc_enuErrorStatus ;
}

extern void Systick_Start(void)
{
	SET_BIT((SYSTICK->STK_CTRL),0);  //enable systick clock 
}

extern void Systick_Stop(void)
{
	SYSTICK->STK_LOAD= 0;
	SYSTICK->STK_VAL= 0;
	CLR_BIT((SYSTICK->STK_CTRL),0);   // disable systick 
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
		SysticK_C_BF = Add_pfCbf;
	}
	return Loc_enuErrorStatus;
}

void SysTick_Handler (void)
{
	COUNTER_MS--;  //isr is excuted every ms 
	if(COUNTER_MS==0)
	{
		SysticK_C_BF();
		Systick_Stop();
    CLR_BIT((SYSTICK->STK_CTRL),1); 		
	}
}

