
#include "Std_types.h"
#include "Bit_utils.h"

#include "Timer.h"
#include "Timer_Priv.h"

#include "Dio.h"

static volatile void (*TIMER0_pvCallBackFunc)(void) ;

void TIMER0_Init(void)
{
	/* FOCO*/ 
	TCCR0 |= (1 << 7) ; 
	
	/*Interrupt Over Flow */
	TIMSK |= (1<<0) ; 
	
	/**/
	TCNT0 = 0 ; 
	
	/*Prescaler : 1*/
	TCCR0 |= (1<<0);
	TCCR0 |= (1<<2);
	
}

u8 TIMER0_u8SetCallBack (void (*copy_pvCallBack)(void))
{
	if (copy_pvCallBack != NULL )
	{
		TIMER0_pvCallBackFunc = copy_pvCallBack ;
	}
}


void __vector_11(void) __attribute__((signal)) ;
void __vector_11(void)
{

	TIMER0_pvCallBackFunc();
	
}
