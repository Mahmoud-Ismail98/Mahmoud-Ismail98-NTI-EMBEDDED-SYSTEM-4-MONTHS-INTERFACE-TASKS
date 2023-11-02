/*
 * EXTI.h
 *
 * Created: 10/22/2023 3:43:10 PM
 *  Author: Mohamed Alaa
 */ 


#ifndef EXTI_H_
#define EXTI_H_

#include <Services/Std_types.h>

typedef enum 
{
	EXTI_No_Error,
	EXTI_Invalid_Configurations,
	EXTI_Invalid_Interrupt_Number,
	EXTI_Invalid_Detection_Argument,
	EXTI_PCallBack_is_Null
} EXTI_Error_State ;





#define EXTI_INT0				0
#define EXTI_INT1				1
#define EXTI_INT2				2


#define EXTI_Low_Level			0x00
#define EXTI_Any_Change			0x01
#define EXTI_Falling_Edge		0x02
#define EXTI_Rising_Edge		0x03
#define EXTI_Disabled			0x04


EXTI_Error_State EXTI_Init(void);
EXTI_Error_State EXTI_Enable(uint8 EXTI_INTx, uint8 EXTI_INTx_Detection, void (*EXTI_INTx_PCallBack)(void));
EXTI_Error_State EXTI_Disable(uint8 EXTI_INTx);


#endif /* EXTI_H_ */