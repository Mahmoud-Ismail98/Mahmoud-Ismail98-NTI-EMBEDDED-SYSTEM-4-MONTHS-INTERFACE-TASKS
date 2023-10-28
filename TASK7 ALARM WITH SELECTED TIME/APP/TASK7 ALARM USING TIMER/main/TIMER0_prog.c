#include "../../../services/Bit_utils.h"
#include "../../../services/Std_types.h"
#include "../../../MCAL/TIMER0/TIMER0_private.h"
#include "../../../MCAL/TIMER0/TIMER0_Interface.h"
#include "../../../MCAL/PORT/include/port.h"
#include "../../../MCAL/TIMER0/TIMER0_Interface.h"
void TIMER0_voidMode(void)
{
#if TIMER_MODE==NORMAL_MODE
	 CLR_BIT(TCCR0,6);
	 CLR_BIT(TCCR0,3);
#elif TIMER_MODE==PWM_OR_PHASE_COTROL
	{
		SET_BIT(TCCR0,6) ;
		CLR_BIT(TCCR0,3);
	}

#elif TIMER_MODE==CTC_MODE
	{
		CLR_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);

	}
#elif TIMER_MODE==FAST_PWM_MODE
	{
		SET_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);
	}
#else
	{}

#endif
}



void TIMER0_voidCOModeNonPwm(void)//Compare Output Mode, non-PWM Mode
{
#if Compare_Output_Mode==normal
	{
	 CLR_BIT(TCCR0,4);
	 CLR_BIT(TCCR0,5);
	}
#elif Compare_Output_Mode==toggle_OC0
	{
		SET_BIT(TCCR0,4);
		CLR_BIT(TCCR0,5);
	}

#elif Compare_Output_Mode==clear_OC0
	{
		CLR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);

	}
#elif Compare_Output_Mode==set_OC0
	{
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5)	;

	}
#else
	{}

#endif
}
void TIMER0_voidCOModeFastPwm(void)// Compare Output Mode, Fast PWM Mode(1)
{
#if comp_Fast_Pwm==normal //normal
	{
	 CLR_BIT(TCCR0,4);
	 CLR_BIT(TCCR0,5);
	}
#elif comp_Fast_Pwm==reversed//Reserved
	{
		SET_BIT(TCCR0,4);
		CLR_BIT(TCCR0,5);
	}
#elif comp_Fast_Pwm==clear_OC0  //Clear OC0 on compare match, set OC0 at TOP
	{
		CLR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);

	}
#elif comp_Fast_Pwm==set_OC0 //Set OC0 on compare match, clear OC0 at TOP
	{
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5)	;

	}
#else
	{}

#endif


}

void TIMER0_voidCOMPhaseCorrectPWM(void) //Compare Output Mode, Phase Correct PWM Mode(1)
{
#if comp_phaseCorrect_Pwm==normal //normal
	{

	 CLR_BIT(TCCR0,4);
	 CLR_BIT(TCCR0,5)	;

	}
#elif comp_phaseCorrect_Pwm==reversed//Reserved
	{
		SET_BIT(TCCR0,4) ;
		CLR_BIT(TCCR0,5);


	}

#elif comp_phaseCorrect_Pwm==clear_OC0  /*Clear OC0 on compare match when up-counting. Set OC0 on compare
														match when downcounting.*/
	{
		CLR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);

	}
#elif comp_phaseCorrect_Pwm==set_OC0 /*Set OC0 on compare match when up-counting. Clear OC0 on compare
												match when downcounting*/
	{
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5)	;

	}
#else
	{}

#endif

}


void TIMER0_voidClockSelect(void) //� Bit 2:0 � CS02:0: Clock Select
{
#if ClockSelect==No_Clk_Source
	{
	 CLR_BIT(TCCR0,0);
	 CLR_BIT(TCCR0,1);
	 CLR_BIT(TCCR0,2);

	}
#elif ClockSelect==CLK_DIV_BY_0
	{
	SET_BIT(TCCR0,0);
	 CLR_BIT(TCCR0,1);
	 CLR_BIT(TCCR0,2);

	}

#elif ClockSelect==CLK_DIV_BY_8
	{
		CLR_BIT(TCCR0,0);
		 SET_BIT(TCCR0,1);
		 CLR_BIT(TCCR0,2);

	}
#elif ClockSelect==CLK_DIV_BY_64
	{
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);

	}
#elif ClockSelect==CLK_DIV_BY_256
	{
		CLR_BIT(TCCR0,0);
		CLR_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);

	}
#elif ClockSelect==CLK_DIV_BY_1024
	{
		SET_BIT(TCCR0,0);
		CLR_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);

	}
#elif ClockSelect==ECS_ON_T0_FALLING_EDGE //External clock source on T0 pin. Clock on falling edge
	{
		CLR_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);

	}
#elif ClockSelect==ECS_ON_T0_RISING_EDGE //External clock source on T0 pin. Clock on rising edge
	{
		SET_BIT(TCCR0,0);
	    SET_BIT(TCCR0,1)	;
	    SET_BIT(TCCR0,2);

	}
#else
	{}

#endif

}
/*
ISR(TIMER0_OVF_vect)
{
	TMU_Cbk();
	TCNT0=131;
}

void Timer_init(void)
{
	TIMSK |= 1<<0;	//enable interrupt for timer
	TCCR0 |= 1<<1;	// TCCR0 for edjust the resolution
	TCNT0 =131;
}


void Timer_Start(void)
{
	TIMSK |= (1<<0);	//Enable interrupt for timer
}

void Timer_Stop(void)
{
	TIMSK &= ~(1<<0);	//disable interrupt for timer
}

*/
/*
static void (* TIMER_pvTimer0)(void) = NULL;
u8  Timer0SetCallBack(void(*capy_pf)(void))
{
		TIMER_pvTimer0=capy_pf;
}*/
void TIMER_GETTIMERCOUNT_VAL(u16 *copy_counter_val)
{
	*copy_counter_val=TCNT0;
}
void TIMER0_SET_COUNTER(u8 COUNT)
{
	TCNT0 = COUNT;
	
}


void TIMER_voidICUEnableInterrupt(void)
{
	SET_BIT(TIMSK,0);
}



void TIMER_voidICUDisableInterrupt(void)
{
	CLR_BIT(TIMSK,0);
}


/*
void  TIMER_u8GetPWMOnPeriod   (u16 * Copy_pu16OnPeriod)
{
		*Copy_pu16OnPeriod = TIMER_u16OnPeriod;
}


void TIMER_u8GetPWMTotalPeriod(u32 * Copy_pu32TotalPeriod)
{
		*Copy_pu32TotalPeriod = (u32)(TIMER_u16OnPeriod + Timeru16OffPeriod);
}



void TIMER_u8GetPWMDutyCycle  (u8  * Copy_pu8DutyCycle)
{

		*Copy_pu8DutyCycle =(u8)(((u32)TIMER_u16OnPeriod * 100) / (TIMER_u16OnPeriod + Timeru16OffPeriod));

}
*/

void T0delayOnems(){
	//setup Timer 0
	TCNT0 = 248;		//load count value for 1ms time delay
	TCNT0 = 20;
	TCCR0 = 0x00;
	TCCR0 = 0b00000101;	//normal mode with 1024 pre-scalar	
	while(!(TIFR & (1<<0)));	//wait until TOV0 flag is set
	TCCR0 = 0;		//turn off timer 0
	TIFR |= (1<<0);	//clear TOV0 flag
}
/*
void T0delayms(int n){
	for(int i = 0; i <= n; i++){
	//	LCD_voidWriteCharacter('0'+i);
	//	LCD_voidSetCursor(0,0);
		T0delayOnems();
	}
}*/
/*
ISR(TIMER0_COMP_vect)
{
	Timer0SetCallBack();
}*/	