/*
 * EXTI.h
 *
 * Created: 10/22/2023 9:29:51 AM
 *  Author: Wael
 */ 

#ifndef EXTI_H_
#define EXTI_H_
#include "EXTI_prv.h"
/*
Copy_u8EXTI_PIN Options:
					EXTI_INT0
					EXTI_INT1
					EXTI_INT2
*/


/*
Copy_u8EXTI_PinMode Options:
					EXTI_FALLING
					EXTI_RISING
					EXTI_LOW
					EXTI_ONCHANGE
*/

void EXTI_voidEnable(u8 Copy_u8EXTI_PIN);
void EXTI_voidSetPinMode(u8 Copy_u8EXTI_PIN,u8 Copy_u8EXTI_PinMode);

void EXTI_voidDisable(u8 Copy_u8EXTI_PIN);

void EXTI_voidSetCallBack(u8 Copy_u8EXTI_PIN, void (*CallBack_func) (void));


#endif