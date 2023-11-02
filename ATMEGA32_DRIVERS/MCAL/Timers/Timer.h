#ifndef TIMER_H_ 
#define TIMER_H_


#define NORMAL_MODE 0
#define PWM_PHASE_CORRECT_MODE 1
#define CTC_MODE 2
#define FAST_PWM_MODE 3

#define NORMAL_COMPARE_OUTPUT 0
#define SET_OC0_ON_COMPARE_MATCH 1
#define CLEAR_OC0_ON_COMPARE_MATCH 2

#define NORMAL_OUTPUT 0
#define SET_OC0_DOWNCOUNT_CLEAR_UPCOUNT 1
#define CLEAR_OC0_DOWNCOUNT_SET_UPCOUNT 2

#define NO_CLK 0
#define CLK_1 1
#define CLK_8 2
#define CLK_64 3
#define CLK_256 4
#define CLK_1024 5
#define EXTERNAL_ON_T0_COUNT_ON_FALLING_EDGE 6
#define EXTERNAL_ON_T0_COUNT_ON_RISING_EDGE 7




void Timer0_voidInitialize(void);
void Timer0_voidTimerBegin(void);
void Timer0_voidForceOutPutCompareMode(void);
void Timer0_voidEnableOutputCompareInterrupt(void);
void Timer0_voidEnableOverFlowInterrupt(void);
void Timer0_WriteInTCNT0(u8 time);
void Timer0_WriteInOCR0(u8 value);
void Timer0_SetCallBack(void (* TimerInterrupt_ptr)(void));

/*ICU*/


void ICU_VoidInit (void) ; 
u8 ICU_voidSetTriggerICUEdge (u8 copy_u8Edge );
void ICU_voidEnableInterrupt(void);
void ICU_voidDisableInterrupt(void);
u16 ICU_ReadInputCapture(void);
u8 ICU_u8SetCallBack (void (*copy_PvCallBack)(void));





/*Watch Dog Timer*/
void WDT_VoidEnable(void);
void WDT_VoidDisable(void);
u8 WDT_u8Sleep(u8 copy_u8SleepTime);







#endif
