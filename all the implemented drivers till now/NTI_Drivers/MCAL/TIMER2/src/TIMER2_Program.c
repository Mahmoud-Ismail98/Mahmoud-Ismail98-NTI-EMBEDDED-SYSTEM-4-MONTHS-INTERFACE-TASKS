/*
 * MTIMER2_Program.c
 *
 *  Created on: Dec 8, 2022
 *      Author: Ismail
 */
#include "../includes/TIMER2_Interface.h"

#define CRYSTALFREQUENCY 16000000
u32 Timer2u32NumberofOVFs = 0;
//#define SREG *((volatile u8*)(0x5f))

u32 Timer2u32NumOfCompareMatches = 0;

u8  Timer2u8RemainingTicks= 0;

void (*Timer2voidCallBack) (void) = NULL;


void Timer2Init() {

	#if	TIMER2_MODE		==		NORMAL
	CLR_BIT(TCCR2,WGM21); CLR_BIT(TCCR2,WGM20);
	SET_BIT(TIMSK,TOIE2);
	#elif		TIMER2_MODE		==		CTC
	SET_BIT(TCCR2,WGM21); CLR_BIT(TCCR2,WGM20);
	SET_BIT(TIMSK,OCIE2);
	#endif
	SET_BIT(SREG,1);

}


void  Timer2SetTime(u32 Local_u32_DesiredTime)
{
	u32 Local_u32_TickTime =0;
	u32 Local_u32_NumberOfTicks=0;
	Local_u32_TickTime		=	MTIMER2_PRESCALER/CRYSTALFREQUENCY;
	 Local_u32_NumberOfTicks =	((Local_u32_DesiredTime*1000)/Local_u32_TickTime);
	#if	TIMER2_MODE		==		NORMAL
	Timer2u32NumberofOVFs		=	Local_u32_NumberOfTicks/256;
	Timer2u8RemainingTicks			=	Local_u32_NumberOfTicks%256;
	if (Timer2u8RemainingTicks != 0)
	{
		TCNT2 = 256 - Timer2u8RemainingTicks;
		Timer2u32NumberofOVFs++;
	}
	#elif		TIMER2_MODE		==		CTC
	u8 Local_u8_Division_Factor = 255;
	while(Local_u32_NumberOfTicks < Local_u8_Division_Factor)
	{
		Local_u8_Division_Factor--;
	}
	while(Local_u32_NumberOfTicks%Local_u8_Division_Factor != 0)
	{
		Local_u8_Division_Factor--;
	}
	Timer2u32NumOfCompareMatches = Local_u32_NumberOfTicks/ Local_u8_Division_Factor;
	OCR2 = Local_u8_Division_Factor-1;
	#endif

}


void Timer2Start()
{
	#if	MTIMER2_PRESCALER	==		PRESCALER_1
	CLR_BIT(TCCR2,CS22); CLR_BIT(TCCR2,CS21);	SET_BIT(TCCR2,CS20);
	#elif MTIMER2_PRESCALER	==		PRESCALER_8
	CLR_BIT(TCCR2,CS22); SET_BIT(TCCR2,CS21);	CLR_BIT(TCCR2,CS20);
	#elif MTIMER2_PRESCALER	==		PRESCALER_64
	CLR_BIT(TCCR2,CS22); SET_BIT(TCCR2,CS21);	SET_BIT(TCCR2,CS20);
	#elif MTIMER2_PRESCALER	==		PRESCALER_256
	SET_BIT(TCCR2,CS22); CLR_BIT(TCCR2,CS21);	SET_BIT(TCCR2,CS20);
	#elif MTIMER2_PRESCALER	==		PRESCALER_1024
	SET_BIT(TCCR2,CS22); SET_BIT(TCCR2,CS21);	SET_BIT(TCCR2,CS20);
	#endif
}

void Timer2Stop()
{
	CLR_BIT(TCCR2,CS22);
	CLR_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS20);
}


void PWM2Init()
{
	Port_enuSetPinDirection(31,PORT_u8OUTPUT);


	#if	PWM2_MODE		==		FAST_PWM
	SET_BIT(TCCR2,WGM21);
	SET_BIT(TCCR2,WGM20);
	#elif PWM2_MODE		==		PHASE_CORRECT
	CLR_BIT(TCCR2,WGM21);
	SET_BIT(TCCR2,WGM20);
	#endif

	#if	OUTPUT_MODE		==		NON_INVERTED
	SET_BIT(TCCR2,COM21);
	CLR_BIT(TCCR2,COM20);
	#elif OUTPUT_MODE		==		INVERTED
	SET_BIT(TCCR2,COM21);
	SET_BIT(TCCR2,COM20);
	#endif

}

void PWM2SetDutyCycle(u8 Local_u8DesiredDutyCycle)
{
	#if	OUTPUT_MODE	==	NON_INVERTED

	if(Local_u8DesiredDutyCycle == 0)
	{
		SET_BIT(TCCR2,COM21);
		SET_BIT(TCCR2,COM20);
		OCR2 = (255 -((Local_u8DesiredDutyCycle *256)/100));
	}
	else
	{
		SET_BIT(TCCR2,COM21);
		CLR_BIT(TCCR2,COM20);
		OCR2 = (((Local_u8DesiredDutyCycle *256) /100) - 1);
	}

	#elif OUTPUT_MODE	==	INVERTED
	if(Local_u8_DesiredDutyCycle == 100)
	{
		SET_BIT(TCCR2,COM21);
		CLR_BIT(TCCR2,COM20);
		OCR2 = (((Local_u8_DesiredDutyCycle * 256) / 100) - 1);
	}
	else
	{
		SET_BIT(TCCR2,COM21);
		SET_BIT(TCCR2,COM20);
		OCR2 = (255 - ((Local_u8_DesiredDutyCycle *256)/100));
	}
	#endif

}

void PWM2Start()
{
	Timer2Start();
	Port_enuSetPinDirection(31,PORT_u8OUTPUT);
}

void PWM2Stop()
{
	Timer2Stop();

}





void Timer2SetCallBack	(void (*Local_void_ptr) (void))
{
	Timer2voidCallBack = Local_void_ptr;
}

 //#if			TIMER2_MODE		==		NORMAL
/*void ISR(TIMER2_OVF_vect)
 {
 	static u32 Local_u32_OVFCounter = 0;
	Local_u32_OVFCounter  ++;
 	if (Local_u32_OVFCounter  == Timer2u32NumberofOVFs)
 	{
		Timer2_void_CallBack();
		Local_u32_OVFCounter  =	0;
		TCNT0 = 256 - Timer2u8RemainingTicks;

 	}
 }
 #elif		TIMER2_MODE		==		CTC
 ISR(TIMER2_COMP_vect)
 {
 	static u32 Local_u32_CTCCounter = 0;
 	Local_u32_CTCCounter  ++;
 	if (Local_u32_CTCCounter  == Timer2_u32_NumOfCompareMatch)
 	{
 		MTimer2_void_CallBack();
		Local_u32_CTCCounter  =	0;
 	}
}
 #endif
 */
