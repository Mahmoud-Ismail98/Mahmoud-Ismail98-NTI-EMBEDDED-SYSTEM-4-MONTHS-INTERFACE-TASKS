/*
 * Timer.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Online
 */

#ifndef COTS_1_MCAL_3_TIMER_INCLUDE_TIMER_H_
#define COTS_1_MCAL_3_TIMER_INCLUDE_TIMER_H_




#define TIMER0_STOP                 0
#define TIMER0_DIV_BY_1             1
#define TIMER0_DIV_BY_8             8
#define TIMER0_DIV_BY_64            64
#define TIMER0_DIV_BY_256           256
#define TIMER0_DIV_BY_1024          1024

/**************************************************/
#define TIMER0_u8_NORMAL     0
#define TIMER0_u8_CTC        1
#define TIMER0_u8_FASTPWM    2
#define TIMER0_u8_PHASEPWM   3
/*******************************************************************/
/*********************** PROTOTYRYS ********************************/
typedef enum {
Timer_EnmOk ,
Timer_EnmModeError ,
Timer_EnmPrescallerError ,
}Timer_tenuErrorStatus;

Timer_tenuErrorStatus Timer0_voidInit(void);
void TIMERS_voidTimer0CTCSetCallBackFunction (void(*Copy_pvCTCFunction)(void));
void Timer_voidSetPWM(u16 Copy_u16CompareValue);
void TIMERS_voidTIMER0SetCompareMatchValue(u8 Copy_u8CompareMatchValue);
void Timer_voidGetTimerCountValue(u16 * Copy_u16CounterValue);
u8 Timer_u8GetPWMOnPeriod (u16 * Copy_pu16onPeriod);
u8 Timer_u8GetTotalPWMOnPeriod (u32 * Copy_pu32TotalPeriod);
u8 Timer_u8GetPWMDutyCycle (u8 * Copy_pu8DutyCycle);


void TIMERS_voidTimer1SetOverflowValue (u16 Copy_u16OverflowValue);
void TIMERS_voidTimer1ChannelASetCompareMatchValue(u16 Copy_u16CompareMatchValue);
void TIMERS_voidTimer1ChannelBSetCompareMatchValue(u16 Copy_u16CompareMatchValue);
/************************* ICU PROTOTYPES *******************************/

void ICU_voidSetSenseControl (u8 Copy_u8SenseControl);
void TIMERS_voidICUSetCallBackFunction (void(*Copy_pvICUFunction)(void));
u16 ICU_u16ReadInputCapture (void);
void ICU_voidSetEnableIntterrupt (u8 Copy_u8Interrupt);
#endif /* COTS_1_MCAL_3_TIMER_INCLUDE_TIMER_H_ */
