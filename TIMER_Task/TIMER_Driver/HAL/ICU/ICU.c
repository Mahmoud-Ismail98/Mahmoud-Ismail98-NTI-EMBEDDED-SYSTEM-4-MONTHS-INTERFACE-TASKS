/*
 * ICU.c
 *
 * Created: 10/27/2023 3:10:04 AM
 *  Author: sharb
 */ 

#include "std_types.h"
#include "../MCAL/TIMER/timer.h"
#include "../MCAL/DIO/Dio.h"
#include "ICU.h"


void ICU_LOGIC(void);
//volatile u32 vg_u32_t1 =FALSE;
//volatile u32 vg_u32_t2 =FALSE;
//volatile u32 vg_u32_t3        =FALSE;
volatile u8  vg_u8_readDone   = FALSE;
volatile u32 vg_u32_onTime    = FALSE;
volatile u32 vg_u32_totalTime = FALSE;
volatile enum_EXT_INT_index_t vgl_enum_CurrentPin = EXT_INT_INDEX_MAX; 

void ICUSW_voidEnableICUSW(enum_EXT_INT_index_t arg_enum_MonitorPin)
{
	TIMER0_init();
	EXTINT_enum_Init(arg_enum_MonitorPin,EXT_INT_RISING_EDGE,ICU_LOGIC);
	vgl_enum_CurrentPin = arg_enum_MonitorPin;	
}
void ICUSW_voidDisableICUSW(void)
{
	TIMER0_deInit();
	EXTINT_enum_DeInit(vgl_enum_CurrentPin);
	vgl_enum_CurrentPin = EXT_INT_INDEX_MAX;
}
void ICUSW_voidGetOnPeriod(u32 *ptr_u32_onPeriod)
{

	*ptr_u32_onPeriod = vg_u32_onTime;
}
void ICUSW_voidGetTotalPeriod(u32 *ptr_u32_totalPeriod)
{

	*ptr_u32_totalPeriod = vg_u32_onTime;
}
void ICUSW_voidGetDutyCycle(u8 *ptr_u8_dutyCycle)
{

	*ptr_u8_dutyCycle = ((vg_u32_onTime)/(vg_u32_totalTime))*100;
}



void ICU_LOGIC(void)
{
	
	static u8 loc_u8_state = FALSE;
	if( vg_u8_readDone == FALSE)
	{
		if(loc_u8_state == FALSE)
		{
			CLR_TIMER0_VAL();
			TIMER0_START();
			loc_u8_state=1;
		}
		else if ( loc_u8_state == 1 )
		{
			GET_TIMER0_VAL(&vg_u32_totalTime);
			CLR_TIMER0_VAL();
			EXTINT_enum_Init(vgl_enum_CurrentPin,EXT_INT_FALLING_EDGE,ICU_LOGIC);
			loc_u8_state=2;
		}
		else if ( loc_u8_state == 2 )
		{
			GET_TIMER0_VAL(&vg_u32_onTime);
			EXTINT_enum_DeInit(vgl_enum_CurrentPin);
			CLR_TIMER0_VAL();
			loc_u8_state=0;
			vg_u8_readDone = TRUE;
		}
	}
	
	
	
}


void get_new_read(void)
{
	if( vg_u8_readDone == TRUE)
	{
		vg_u8_readDone = FALSE;
		EXTINT_enum_Init(vgl_enum_CurrentPin,EXT_INT_RISING_EDGE,ICU_LOGIC);
	}
	
}