/*
 * TIMER.h
 *
 * Created: 10/24/2023 11:35:38 AM
 *  Author: FADY
 */
#ifndef TIMER_H
#define TIMER_H



typedef enum TIMER_ErrorState{
    TIMER_NULLPTR,TIMER_OK
}TIMER_ErrorState;






void Timer_voidInit(void);
void Timer_voidSetCallBack(void(*Copy_pfNotification)(void),u8 Copy_u8TimerIntIndex);
void Timer_voidSetPWM(u16 Copy_u16CompareValue);
void Timer_voidGetTimer1CounterValue(pu16  Copy_u16CounterValue);
TIMER_ErrorState TImer_u8GetPWMOnPeriod   (pu16  Copy_pu16OnPeriod);
TIMER_ErrorState TImer_u8GetPWMTotalPeriod(pu32  Copy_pu32TotalPeriod);
TIMER_ErrorState TImer_u8GetPWMDutyCycle  (pu8   Copy_pu8DutyCycle);
void TIMER0_delay(u8 ms);
void Timer0_SetCounter(u16 Copy_u16Seconds);
void Timer0_GETCounter(pu16 Copy_u16Seconds);
void Timer0_GETCounterUp(pu16 Copy_u16Seconds);


#endif