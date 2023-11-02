/*
 * timer.c
 *
 *  Created on: Oct 24, 2023
 *      Author: Ahmed Dwidar
 */

#include"timer.h"
#include<avr/io.h>

void(*timerClbk_ptr[4])(void);


//ISR(TIMER0_COMPA_vect)
//{
//	if(timerClbk_ptr[1] != NULL)
//	{
//		timerClbk_ptr[1]();
//	}
//}
//
//ISR(TIMER0_COMPB_vect)
//{
//	if(timerClbk_ptr[2] != NULL)
//	{
//		timerClbk_ptr[2]();
//	}
//}
//ISR(TIMER1_CAPT_vect)
//{
//	if(timerClbk_ptr[3] != NULL)
//	{
//		timerClbk_ptr[3]();
//	}
//}


void timer_setCallBack(void(*funClbk_ptr)(void), u8 index)
{
	timerClbk_ptr[index] = funClbk_ptr;
}


void timer_init(void)
{
	TCNT0 = TIMER_INITIAL_VALUE;

//	SET_BIT(TCCR0,FOC0);
//	SET_BIT(TCCR0,CS00);
//	SET_BIT(TCCR0,CS02);

	ASSIGN_FIRST_TWO_BITS(TCCR0,TIMER_SELECT_PRESCALER);

	SET_BIT(TIMSK,TOIE0);
//	SET_BIT(TCCR0,WGM01);

//	ASSIGN_THIRD_TWO_BITS(TCCR0,TIMER_NORMAL_NONE_PWM);

}
void Timer0_deInit(void)
{
	TCNT0 = 0;
	TCCR0 = 0;
}

void timer_setPwm(u16 compareValue)
{
	setPinDirection(TIMER_ZERO_OC_PIN,PIN_OUTPUT);

	OCR0 = compareValue;

//	SET_BIT(TCCR0,WGM00);
//	SET_BIT(TCCR0,WGM01);
//	SET_BIT(TCCR0,COM00);
//	SET_BIT(TCCR0,CS01);

	CLEAR_BIT(TCCR0,FOC0);

	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);

}

void timer_getValue(u16 *timerRead)
{
	*timerRead = TCNT0;
}

//u8 timer_getPwmOnPeriod(u16 *timerPwmOnRead)
//{
//	u8 loc_onPeriod;
//
//}
//u8 timer_getPwmTotalPeriod(u32 *timerPwmTotalRead)
//{
//	u8 loc_totalPeriod;
//}
//u8 timer_getPwmDutycycle(u8 *timerPwmDutycycleRead)
//{
//	u8 loc_totalPeriod,loc_onPeriod;
//	u8 loc_dutyCycle;
//
//	loc_totalPeriod = timer_getPwmTotalPeriod();
//	loc_onPeriod = timer_getPwmOnPeriod();
//
//	loc_dutyCycle = ( loc_onPeriod - (loc_totalPeriod - loc_onPeriod) ) / (loc_totalPeriod);
//
//	if(loc_dutyCycle < 0)
//	{
//		loc_dutyCycle *= -1;
//	}
//
//	return loc_dutyCycle;
//
//}
//void ICU_init(void)
//{
//	TCNT1 = TIMER_INITIAL_VALUE;
//	ICR1 = TIMER_INITIAL_VALUE;
//
//	ASSIGN_SECOND_TWO_BITS(TCCR1A,3);
//
//	ASSIGN_FIRST_TWO_BITS(TCCR1B,ICU_PRESCALER_F_CPU_8);
//
//	SET_BIT(TCCR1B,ICU_NOISE_CANCELER_BIT);
//#if(ICU_EDGE_TYPE == ICU_RISING_EDGE)
//	SET_BIT(TCCR1B,ICU_EDGE_SELECT_BIT);
//#elif(ICU_EDGE_TYPE == ICU_FALLING_EDGE)
//	CLEAR_BIT(TCCR1B,ICU_EDGE_SELECT_BIT);
//#endif
//
//	SET_BIT(TIMSK,ICU_INTERRUPT_ENABLE);
//
//}
//void ICU_setEdgeDetectionType(const u8 edgeType)
//{
//#if(edgeType == ICU_RISING_EDGE)
//	SET_BIT(TCCR1B,ICU_EDGE_SELECT_BIT);
//#elif(edgeType == ICU_FALLING_EDGE)
//	CLEAR_BIT(TCCR1B,ICU_EDGE_SELECT_BIT);
//#endif
//}
//u16 ICU_getInputCaptureValue(void)
//{
//	return ICR1;
//}
//void ICU_clearTimerValue(void)
//{
//	CLEAR_REG(TCNT1);
//}
//void ICU_deint(void)
//{
//	CLEAR_REG(TCCR1A);
//	CLEAR_REG(TCCR1B);
//	CLEAR_REG(TCNT1);
//	CLEAR_REG(ICR1);
//
//	CLEAR_BIT(TIMSK,ICU_INTERRUPT_ENABLE);
//
//	timerClbk_ptr[4] = NULL;
//}
