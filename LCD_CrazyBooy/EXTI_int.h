#ifndef EXTI_INT_H_
#define EXTI_INT_H_

#define	EXTI0	0
#define	EXTI1	1
#define	EXTI2	2

#define	LOW_LEVEL				0
#define	ANY_LOGICAL_CHANGE		1
#define	FALLING_EDGE			2
#define	RISING_EDGE				3





void EXTI_voidInit(void);
void EXTI_voidEnableInt(u8 Copy_u8IntID);
void EXTI_voidDisableInt(u8 Copy_u8IntID);
void EXTI_voidSetSignal(u8 Copy_u8IntID,u8 Copy_u8SignalID);
void EXTI_voidSetCallBack(u8 Copy_u8IntID, void(*PTR)(void));

#endif
