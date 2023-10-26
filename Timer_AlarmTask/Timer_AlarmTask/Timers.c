/*
 * Timers.c
 *
 * Created: 10/24/2023 11:15:51 AM
 *  Author: Wael
 */

#include "Timers.h"
#include "Timers_prv.h"
void (*OVF_Callback) (void) = NULL;
void Timer0_voidInit(Timer0_enuMode Copy_enuMode, Timer0_enuScaler Copy_enuScaler,Timer0_enuOC0Mode Copy_enuOC0Mode)
{
	/*Set Mode*/
	switch(Copy_enuMode)
	{
		case Timer0_NormalMode :
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		break;

		case Timer0_CTCMode :
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;

		case Timer0_FastPwmMode :
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
		case Timer0_PhaseCorrectMode :
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		break;
	}

	/*Set Prescaler*/
	TCCR0 &= 0xF8;
	TCCR0 |= Copy_enuScaler;

	/*SET OC0 Mode*/
	TCCR0 &= 0xCF;
	TCCR0 |= (Copy_enuOC0Mode<<4);
}


void Timer0_voidOVF_InterruptEnable()
{
	SET_BIT(TIMSK,TOIE0);
}
void Timer0_voidOVF_InterruptDisable()
{
	CLR_BIT(TIMSK,TOIE0);
}


void Timer0_voidOC_InterruptEnable()
{
	SET_BIT(TIMSK,OCIE0);
}
void Timer0_voidOC_InterruptDisable()
{
	CLR_BIT(TIMSK,OCIE0);
}


void Timer0_voidOVF_SetCallBack(void (*Fptr) (void))
{
	OVF_Callback = Fptr;
}





ISR(TIMER0_OVF)
{
	if(OVF_Callback != NULL)
	{
		OVF_Callback();
	}

}
