/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : EXTI                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef EXTI_H
#define EXTI_H

#define EXTI_LOW_LEVEL      1
#define EXTI_RISING_EDGE    2
#define EXTI_FALLING_EDGE   3
#define EXTI_ON_CHANGE      4

#define EXTI_ENABLE         1
#define EXTI_DISABLE        2

#define INT0                6
#define INT1                7
#define INT2                5


void EXTI_voidInit(void);

tenuErrorStatus EXTI_enuErrorStateInt0SetCallBack(void (*Copy_pvInt0Func)(void));

tenuErrorStatus EXTI_enuErrorStateInt1SetCallBack(void (*Copy_pvInt1Func)(void));

tenuErrorStatus EXTI_enuErrorStateInt2SetCallBack(void (*Copy_pvInt2Func)(void));

#endif