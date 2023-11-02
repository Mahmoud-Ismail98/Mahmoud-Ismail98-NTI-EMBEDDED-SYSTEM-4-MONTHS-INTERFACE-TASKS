/*
 * timer.h
 *
 * Created: 10/24/2023 12:18:46 AM
 *  Author: sharb
 */ 


#ifndef TIMER_H_
#define TIMER_H_

typedef enum
{
	TIME_IN_MICRO,
	TIME_IN_MILLI,
	TIME_IN_SECOND,
	TIME_UNIT_MAX
}enum_TIME_UNIT_t;

typedef enum
{
	NORMAL_MODE,
	PWM_PHASE_CORRECT,
	CTC_MODE,
	FAST_PWM,
	TIMER_MODE_MAX
}enum_TIMER_MODE_t;

typedef enum
{
	TIMER_RUN_SYNCH,
	TIMER_RUN_ASYNCH,
	TIMER_RUN_MAX
}enum_TIMER_RUN_STATUS_t;
typedef enum
{
	TIMER0_OKAY,
	TIME_UNIT_ERROR,
	TIMER_RUN_ERROR,
	TIMER0_PWM_DUTY_ERROR,
	TIMER_MODE_ERROR,
	CALL_BACK_IS_NULL_ERROR
	
}enum_TIMER_ErrorStatus_t;


void TIMER0_init(void);
void TIMER0_deInit(void);
void TIMER0_stop(void);
void TIMER0_START(void);
enum_TIMER_ErrorStatus_t TIMER0_setTimeAndStart(u32 arg_u32_time,enum_TIME_UNIT_t arg_enum_timeUnit,enum_TIMER_RUN_STATUS_t arg_enum_runStatus);
enum_TIMER_ErrorStatus_t TIMER0_setPWMAndStart(u8 arg_u8_dutyCycle);
enum_TIMER_ErrorStatus_t TIMER0_changeMode(enum_TIMER_MODE_t arg_enum_TimerMode);
enum_TIMER_ErrorStatus_t TIMER0_setcallBack(void(*ptrFunc)(void));
void GET_TIMER0_VAL(u32 *ptr_num_of_ticks);
void CLR_TIMER0_VAL(void);
f32 GET_tickTimeinMicro(void);



#endif /* TIMER_H_ */