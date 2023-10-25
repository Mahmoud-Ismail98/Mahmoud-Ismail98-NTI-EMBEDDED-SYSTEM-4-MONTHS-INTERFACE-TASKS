#ifndef TIMER0_INT_H_
#define TIMER0_INT_H_

void TIMER0_voidInit(void);
void TIMER0_voidSetCallBack(void(*Ptr_voidCallBackFunc)(void));
void TIMER0_voidSetTimeOnNormalMode(u32 Copy_u32MicroS, u32 Copy_u32Prescaller);
void TIMER0_voidSetTimeOnCTCMode(u32 Copy_u32MicroS, u32 Copy_u32Prescaller);
void TIMER0_voidSetPWM(u8 Copy_u8PWMDutyperiod);


#endif
