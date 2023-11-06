/*
 * EXIT.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Online
 */

#ifndef COTS_1_MCAL_5_EXIT_INCLUDE_EXIT_H_
#define COTS_1_MCAL_5_EXIT_INCLUDE_EXIT_H_

/********************************************************************/
/*********************** REGISTERS ********************************/

#define MCUCR            *((volatile u8*)0x55)
#define MCUCR_ISC11      3
#define MCUCR_ISC10      2
#define MCUCR_ISC01      1
#define MCUCR_ISC00      0

#define MCUCSR			 *((volatile u8 *)0x54)
#define	MCUCSR_ISC2		 6

#define GICR             *((volatile u8*)0x5B)
#define GICR_INT1        7
#define GICR_INT0        6
#define GICR_INT2        5

#define ENABLE           1
#define DISENABLE        0

/********************************************************************/
/*********************** ERROR STATES ********************************/
typedef enum {
EXIT_EnmOk ,
EXIT_EnmControlError,
EXIT_EnmControlLevelError
}EXIT_tenuErrorStatus;

/********************************************************************/
/************************* PROTOTYPES ******************************/

void EXTI_voidInt0Init(void);
void EXTI_voidInt1Init(void);
void EXTI_voidInt2Init(void);
EXIT_tenuErrorStatus EXTI_voidSetInt0SenseControl(u8 Copy_u8SenseControl);
EXIT_tenuErrorStatus EXTI_voidSetInt1SenseControl(u8 Copy_u8SenseControl);
EXIT_tenuErrorStatus EXTI_voidSetInt2SenseControl(u8 Copy_u8SenseControl);
EXIT_tenuErrorStatus EXTI_voidInt0Control(u8 Copy_u8Int0State);
EXIT_tenuErrorStatus EXTI_voidInt1Control(u8 Copy_u8Int1State);
EXIT_tenuErrorStatus EXTI_voidInt2Control(u8 Copy_u8Int1State);
void EXTI_voidInt0SetCallBack(void (*Copy_pvNotificationFunction)(void));
void EXTI_voidInt1SetCallBack(void (*Copy_pvNotificationFunction)(void));
void EXTI_voidInt2SetCallBack(void (*Copy_pvNotificationFunction)(void));
#endif /* COTS_1_MCAL_5_EXIT_INCLUDE_EXIT_H_ */






