#ifndef INC_MCAL_TIMER0_TIMER0_INT_H_
#define INC_MCAL_TIMER0_TIMER0_INT_H_


#define	OVERFLOW_INT					1
#define COMPARE_MATCH_INT				2
#define OVERFLOW_AND_COMPARE_MATCH_INT	3
#define DISABLE_INT						0


#define	NO_ClockSource					0
#define No_prescaller					1
#define Prescaller_8					2
#define Prescaller_64					3
#define Prescaller_256					4
#define Prescaller_1024					5
#define EXTERNAL_OnFallingEdge			6
#define EXTERNAL_OnRISINGEdge			7

void TIMER0_voidInit(void);
void TIMER0_voidSetCallBack(void(*Ptr_voidCallBackFunc)(void));
void TIMER0_voidSetTimeOnNormalMode(u32 Copy_u32MicroS,u32 prescaller);
void TIMER0_voidSetTimeOnCTCMode(u32 Copy_u32MicroS,u32 prescaller);
void TIMER0_voidSetPWM(u8 Copy_u8PWMDutyperiod);
void TIMER0_voidInterruptEnable(u8 Copy_u8InterruptType);
void TIMER0_voidSetTimerTicks(u8 Copy_u8TimerTicks);
u8 TIMER0_voidGetTimerTicks(void);
#endif
