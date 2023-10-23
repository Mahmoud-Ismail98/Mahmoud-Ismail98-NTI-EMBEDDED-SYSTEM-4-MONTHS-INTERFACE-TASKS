/*
 * MEXIT_Interface.h
 *
 *  Created on: Oct 21, 2022
 *      Author: Ismail
 */

#ifndef MCAL_EXIT_EXIT_H_
#define MCAL_EXIT_EXIT_H_

#define EXTI_LINE0		0
#define EXTI_LINE1		1
#define EXTI_LINE2		2

/*prototypes*/
void EXIT0_Init();
void EXIT1_Init();
void EXIT2_Init();
void EXIT2_Set_Sense_Control(u8 Copy_u8Interrupt_ID, u8 Copy_u8Mode);//during run time to change//
void EXTI_voidClearFlag( u8 Copy_u8Line );
void EXTI_voidCallBack( void (*Copy_pvoidCallBack) (void) , u8 Copy_u8EXTILine);



#endif /* MCAL_EXIT_EXITH_ */
