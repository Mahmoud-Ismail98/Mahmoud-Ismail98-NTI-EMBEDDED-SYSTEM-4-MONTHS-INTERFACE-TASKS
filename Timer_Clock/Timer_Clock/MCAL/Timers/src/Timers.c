/*
 * Timers.c
 *
 * Created: 10/24/2023 11:15:51 AM
 *  Author: Wael
 */
#include "Std_types.h"
#include "Bit_utils.h"
#include "../inc/Timers.h"
#include "../inc/Timers_prv.h"

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
void Timer0_voidSetTCNT(u8 Copy_u8Val)
{
	TCNT0 = Copy_u8Val;
}

u8 Timer0_u8GetTCNT()
{
	return TCNT0;
}


ISR(TIMER0_OVF)
{
	if(OVF_Callback != NULL)
	{
		OVF_Callback();
	}

}


/////////////////////////////////////////////////////////////////////
void Timer1_voidInit(Timer1Mode_type Copy_enuMode, Timer1Scaler_type Copy_enuScaler)
{
	switch (Copy_enuMode)
	{
		case TIMER1_NORMAL_MODE:
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_CTC_ICR_TOP_MODE:
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;

		case TIMER1_CTC_OCRA_TOP_MODE:
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
		break;

		case TIMER1_FASTPWM_ICR_TOP_MODE:
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;

		case TIMER1_FASTPWM_OCRA_TOP_MODE:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;

		case TIMER1_FASTPWM_8BIT_MODE:
		SET_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);

	}


	TCCR1B&=0XF8;
	TCCR1B|=Copy_enuScaler;

}

void Timer1_voidSETOC1AMode(OC1A_Mode_type Copy_enuMode)
{
	switch (Copy_enuMode)
	{
		case OCRA_DISCONNECTED:
		CLR_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_TOGGLE:
		SET_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_NON_INVERTING:
		CLR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_INVERTING:
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
	}
}
void Timer1_voidSETOC1BMode(OC1B_Mode_type Copy_enuMode)
{
	switch (Copy_enuMode)
	{
		case OCRB_DISCONNECTED:
		CLR_BIT(TCCR1A,COM1B0);
		CLR_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_TOGGLE:
		SET_BIT(TCCR1A,COM1B0);
		CLR_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_NON_INVERTING:
		CLR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_INVERTING:
		SET_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
	}
}

void Timer1_voidSETOC1A(u16 Copy_u16Val)
{
	if (Copy_u16Val > 0xffff)
	{

	}
	else
	{
		OCR1A = Copy_u16Val;
	}
}
void Timer1_voidSETOC1B(u16 Copy_u16Val)
{
	if (Copy_u16Val > 0xffff)
	{

	}
	else
	{
		OCR1B = Copy_u16Val;
	}
}

