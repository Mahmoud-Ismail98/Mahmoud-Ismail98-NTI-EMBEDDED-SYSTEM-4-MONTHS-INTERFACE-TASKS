/*
 * timer.c
 *
 * Created: 10/24/2023 12:19:46 AM
 *  Author: sharpel
 */ 



#include "std_types.h"
#include "bit_math.h"
#include "vect_table.h"
#include "timer_prv.h"
#include "timer.h"
#include "timer_cfg.h"


static void(*arr_ptrFunc[NUM_OF_TIMERS])(void)={PTR_NULL,PTR_NULL,PTR_NULL};
static u32 sgl_u32_timer0_NOVF   = FALSE ;
static u8  sgl_u8_timer0_InitVal = FALSE ;

volatile u32 vgl_u32_timer0_CurrentNOVF   = FALSE ;

void TIMER0_init(void)
{
	#if    TIMER0_SELECT_MODE ==  TIMER0_NORMAL_MODE
	
	CLR_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);
	
	#elif  TIMER0_SELECT_MODE ==  TIMER0_PWM_PHASE_MODE
	
	CLR_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);
	
	#elif  TIMER0_SELECT_MODE ==  TIMER0_CTC_MODE
	
	SET_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);
	
	#elif  TIMER0_SELECT_MODE ==  TIMER0_FAST_PWM_MODE
	
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);
	
	// config pwm inverting
	#if   FAST_PWM_INVERTED == PWM_INVERTED
	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,COM00);
	#elif FAST_PWM_INVERTED == PWM_NON_INVERTED
	SET_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);
	#else
	#error "FAST_PWM_INVERTED Config Error"
	#endif
	
	
	#else
	#error "TIMER0_SELECT_MODE Config Error"
	#endif
	
	
	#if     TIMER0_SELECT_INTERRUPT == TIMER0_INTERRUPT_ENABLE
	
	// check on mode
	#if  TIMER0_SELECT_MODE ==  TIMER0_CTC_MODE
	SET_BIT(TIMSK,OCIE0);
	#elif TIMER0_SELECT_MODE ==  TIMER0_NORMAL_MODE
	SET_BIT(TIMSK,TOIE0);
	#endif
	
	#elif   TIMER0_SELECT_INTERRUPT == TIMER0_INTERRUPT_DISABLE
	
	// check on mode
	#if  TIMER0_SELECT_MODE ==  TIMER0_CTC_MODE
	CLR_BIT(TIMSK,OCIE0);
	#elif TIMER0_SELECT_MODE ==  TIMER0_NORMAL_MODE
	CLR_BIT(TIMSK,TOIE0);
	#endif
	
	#else
	#error "TIMER0_SELECT_MODE Config Error"
	#endif
}


void TIMER0_deInit(void)
{
	TCCR0 = FALSE;
	CLR_BIT(TIMSK,OCIE0);
	CLR_BIT(TIMSK,TOIE0);
}
void TIMER0_stop(void)
{
	CLR_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS00);
}
enum_TIMER_ErrorStatus_t TIMER0_setTimeAndStart(u32 arg_u32_time,enum_TIME_UNIT_t arg_enum_timeUnit,enum_TIMER_RUN_STATUS_t arg_enum_runStatus)
{
	enum_TIMER_ErrorStatus_t loc_enum_returnStatus = TIMER0_OKAY;
	f32 loc_f32_timerClock;
	u32 loc_u32_timeConv ;
	u32 loc_u32_timeDeired;
	if( arg_enum_timeUnit >= TIME_UNIT_MAX)
	{
		loc_enum_returnStatus = TIME_UNIT_ERROR;
	}
	else if ( arg_enum_runStatus >= TIMER_RUN_MAX)
	{
		loc_enum_returnStatus = TIMER_RUN_ERROR;
	}
	else
	{
	      loc_f32_timerClock = (TIMER0_SELECT_CLOCK/TIMER0_SELECT_FREQ);
		  if ( arg_enum_timeUnit == TIME_IN_MILLI)
		  {
			  loc_u32_timeConv = arg_u32_time*MILLI_CONV;
		  }
		  else if ( arg_enum_timeUnit == TIME_IN_SECOND)
		  {
			  loc_u32_timeConv = arg_u32_time*SEC_CONV;
		  }
		  else
		  {
			  loc_u32_timeConv = arg_u32_time;
		  }
		  
		  loc_u32_timeDeired    = loc_u32_timeConv/loc_f32_timerClock ;
		  sgl_u32_timer0_NOVF   = loc_u32_timeDeired / TIMER0_REG_SIZE;
		  sgl_u8_timer0_InitVal = TIMER0_REG_SIZE - (loc_u32_timeDeired%TIMER0_REG_SIZE);
		 
		  
		  TCNT0 = sgl_u8_timer0_InitVal;
		   sgl_u32_timer0_NOVF++;
		  
		  if( arg_enum_runStatus == TIMER_RUN_ASYNCH)
		  {
			  #if  TIMER0_SELECT_MODE ==  TIMER0_CTC_MODE
			  SET_BIT(TIMSK,OCIE0);
			  #elif TIMER0_SELECT_MODE ==  TIMER0_NORMAL_MODE
			  SET_BIT(TIMSK,TOIE0);
			  
			  #endif
			  TIMER0_START();
		  }
		  else
		  {
			  #if  TIMER0_SELECT_MODE ==  TIMER0_CTC_MODE
			  CLR_BIT(TIMSK,OCIE0);
			  #elif TIMER0_SELECT_MODE ==  TIMER0_NORMAL_MODE
			  CLR_BIT(TIMSK,TOIE0);
			  #endif
			  
			  TIMER0_START();
			  // block timer
			  TIMER0_BLOCK();
		  }
	}
	
	
	return loc_enum_returnStatus;
}

void TIMER0_START(void)
{
	#if    TIMER0_SELECT_CLOCK == TIMER0_NO_PRESCALER
	SET_BIT(TCCR0,CS00);
	#elif  TIMER0_SELECT_CLOCK == TIMER0_8_PRESCALER
	SET_BIT(TCCR0,CS01);
	#elif  TIMER0_SELECT_CLOCK == TIMER0_64_PRESCALER
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	#elif  TIMER0_SELECT_CLOCK == TIMER0_256_PRESCALER
	SET_BIT(TCCR0,CS02);
	#elif  TIMER0_SELECT_CLOCK == TIMER0_1024_PRESCALER
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	#else
	#error "TIMER0_SELECT_CLOCK CONFIG ERROR"
	#endif
}

static void TIMER0_BLOCK(void)
{
	static u32 sloc_u32_CounterOvf = FALSE ;
    while(sloc_u32_CounterOvf != sgl_u32_timer0_NOVF)
	{
		while(!GET_BIT(TIFR,TOV0));
		sloc_u32_CounterOvf++;
	}
	sloc_u32_CounterOvf = FALSE ;
	sgl_u32_timer0_NOVF = FALSE;
}
enum_TIMER_ErrorStatus_t TIMER0_setPWMAndStart(u8 arg_u8_dutyCycle)
{
	enum_TIMER_ErrorStatus_t loc_enum_returnVal = TIMER0_OKAY;
	if( arg_u8_dutyCycle > 100)
	{
		loc_enum_returnVal = TIMER0_PWM_DUTY_ERROR;
	}
	else
	{
		#if (TIMER0_SELECT_MODE == TIMER0_NORMAL_MODE) || (TIMER0_SELECT_MODE == TIMER0_CTC_MODE)
		
		loc_enum_returnVal = TIMER_MODE_ERROR;
		
		#elif TIMER0_SELECT_MODE == TIMER0_FAST_PWM_MODE
		
		// case of fast pwm
		#if   FAST_PWM_INVERTED_OPTION == PWM_INVERTED
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		#elif FAST_PWM_INVERTED_OPTION == PWM_NON_INVERTED
		SET_BIT(TCCR0,COM01);
		#else
		#error "FAST_PWM_INVERTED_OPTION CONFIG ERROR"
		#endif
		#endif
		
		if ( loc_enum_returnVal == TIMER0_OKAY)
		{
			// make ocr0 pin (PORTB PIN3) as output in port driver
			OCR0  = ((arg_u8_dutyCycle*TIMER0_REG_SIZE)/MAX_DUTY)-ONE_TICK;
		}
		else
		{
			//do nothing
		}
		
	}
	return loc_enum_returnVal;
}
enum_TIMER_ErrorStatus_t TIMER0_changeMode(enum_TIMER_MODE_t arg_enum_TimerMode);
enum_TIMER_ErrorStatus_t TIMER0_setcallBack(void(*ptrFunc)(void))
{
	enum_TIMER_ErrorStatus_t loc_enum_retVal = TIMER0_OKAY;
	if(ptrFunc == PTR_NULL)
	{
		loc_enum_retVal = CALL_BACK_IS_NULL_ERROR;
	}
	else
	{
		arr_ptrFunc[TIMER0_INDEX] = ptrFunc;
	}
	
	return loc_enum_retVal;
}
void GET_TIMER0_VAL(u32 *ptr_num_of_ticks)
{
	
	*ptr_num_of_ticks = ((vgl_u32_timer0_CurrentNOVF*256) + TCNT0)*(TIMER0_SELECT_FREQ/TIMER0_SELECT_CLOCK) ;
}

void CLR_TIMER0_VAL(void)
{
	
	vgl_u32_timer0_CurrentNOVF = 0 ;
	TCNT0 = 0;
}

f32 GET_tickTimeinMicro(void)
{
	return (TIMER0_SELECT_FREQ)/(TIMER0_SELECT_CLOCK);
}
ISR(TIM0_OVF_INT)
{
	//vgl_u32_timer0_CurrentNOVF++;
	static u32 sloc_u32_counterOVF = FALSE;
	sloc_u32_counterOVF++;
	if( sloc_u32_counterOVF == sgl_u32_timer0_NOVF)
	{
		if(arr_ptrFunc[TIMER0_INDEX] != PTR_NULL)
		{
			arr_ptrFunc[TIMER0_INDEX]();
			sloc_u32_counterOVF = 0;
		}
		
	}
}


