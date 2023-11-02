/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 24 Oct 2023                                                           */
/************************************************************************************/
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

typedef enum{
    TIMER_OK,
    TIMER0_INIT_NOK,
    TIMER1_INIT_NOK,
    TIMER0_CALL_NOK,
    TIMER1_CALL_NOK,
    TIMER0_CMATCH_NOK,
    TIMER1_CMATCH_NOK,
}TIMEREnum;

/* Macros for Timers Mode */
#define TIMER_NORMAL_MODE               0
#define TIMER_CTC_MODE                  1  
#define TIMER_FAST_PWM_MODE             2  
#define TIMER_PHASE_CORR_MODE           3    
   

TIMEREnum TIMER_TIMEREnumTimer0Init(u8 copy_u8TimerMode);
TIMEREnum TIMER_TIMEREnumTimer0Callback(u8 copy_u8TimerMode,void (*copy_pfTimer0)(void));
TIMEREnum TIMER_TIMEREnumTimer0SetCompMatchValue (u8 copy_u8Value);

TIMEREnum TIMER_TIMEREnumTimer1Init(u8 copy_u8TimerMode);
TIMEREnum TIMER_TIMEREnumTimer1Callback(u8 copy_u8TimerMode,void (*copy_pfTimer1)(void));
TIMEREnum TIMER_TIMEREnumTimer1SetCompMatchValue (u16 copy_u16CompValueA,u16 copy_u16CompValueB,u16 copy_u16ICR1Value);

#endif