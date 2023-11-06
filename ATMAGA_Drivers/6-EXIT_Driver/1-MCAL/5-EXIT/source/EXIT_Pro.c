/*
 * EXIT_Pro.c
 *
 *  Created on: Oct 24, 2023
 *      Author: Online
 */
#include "../../../4-SERVICS/Std_types.h"
#include "../../../4-SERVICS/Bit_utils.h"
#include "../../5-EXIT/include/EXIT.h"
#include "../../5-EXIT/include/EXIT_Cfg.h"
#include "../../5-EXIT/include/EXIT_Prv.h"
/* Global Pointer To Function To Hold INT0 ISR Address */
void (*Global_pvINT0NotFunction)(void)= NULL;
/* Global Pointer To Function To Hold INT1 ISR Address */
void (*Global_pvINT1NotFunction)(void)= NULL;
/* Global Pointer To Function To Hold INT2 ISR Address */
void (*Global_pvINT2NotFunction)(void)= NULL;

void EXTI_voidInt0Init(void){
          #if EXTI_INT0 == FALLIND_EDGE
			SET_BIT(MCUCR,MCUCR_ISC01);
			CLR_BIT(MCUCR,MCUCR_ISC00);

          #elif EXTI_INT0 == ON_CHANGE
			SET_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);

		#elif EXTI_INT0 == LOW
	    	CLR_BIT(MCUCR,MCUCR_ISC00);
	        CLR_BIT(MCUCR,MCUCR_ISC01);


           #elif EXTI_INT0 == RISING_EDGE
			SET_BIT(MCUCR,MCUCR_ISC01);
			SET_BIT(MCUCR,MCUCR_ISC00);
           #endif
	/* check peripheral interrrupt enable initial state */
#if EXTI_INT0_State == ENABLE
	      SET_BIT(GICR,GICR_INT0);
#elif EXTI_INT1_State == DISABLE
	      CLR_BIT(GICR,GICR_INT0);
#endif
}
void EXTI_voidInt1Init(void){

#if EXTI_INT1 == LOW
		CLR_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);

        #elif EXTI_INT1 == ON_CHANGE
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);

        #elif EXTI_INT1 == FALLIND_EDGE
		SET_BIT(MCUCR,MCUCR_ISC11);
		CLR_BIT(MCUCR,MCUCR_ISC10);

        #elif EXTI_INT1 == RISING_EDGE
		SET_BIT(MCUCR,MCUCR_ISC11);
		SET_BIT(MCUCR,MCUCR_ISC10);
        #endif
		/* check peripheral interrrupt enable initial state */
#if EXTI_INT1_State == ENABLE
			SET_BIT(GICR,GICR_INT1);
#elif  EXTI_INT1_State == DISABLE
			CLR_BIT(GICR,GICR_INT1);
#endif
}
void EXTI_voidInt2Init(void){
       #if EXTI_INT2 == FALLIND_EDGE
		CLR_BIT(MCUCSR,MCUCSR_ISC2);

        #elif EXTI_INT2 == RISING_EDGE
		SET_BIT(MCUCSR,MCUCSR_ISC2);
        #endif
		/* check peripheral interrrupt enable initial state */
#if EXTI_INT2_State == ENABLE
		SET_BIT(GICR,GICR_INT2);
#elif  EXTI_INT2_State == DISABLE
		CLR_BIT(GICR,GICR_INT2);
#endif
}
EXIT_tenuErrorStatus EXTI_voidSetInt0SenseControl(u8 Copy_u8SenseControl){
	u8 State_u8Error = EXIT_EnmOk;
	switch (Copy_u8SenseControl){
	case Low:
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		break;
	case ON_CHANGE:
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
	    break;
	case FALLIND_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC01);
		CLR_BIT(MCUCR,MCUCR_ISC00);
	    break;
	case RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(MCUCR,MCUCR_ISC00);
		break;
	default: State_u8Error = EXIT_EnmControlLevelError;

	}
	return State_u8Error;
}
EXIT_tenuErrorStatus EXTI_voidSetInt1SenseControl(u8 Copy_u8SenseControl){
	u8 State_u8Error = EXIT_EnmOk;
	switch (Copy_u8SenseControl){
	case Low:
		CLR_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
		break;
	case ON_CHANGE:
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
	    break;
	case FALLIND_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC11);
		CLR_BIT(MCUCR,MCUCR_ISC10);
	    break;
	case RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC11);
		SET_BIT(MCUCR,MCUCR_ISC10);
		break;
	default: State_u8Error = EXIT_EnmControlLevelError;
	}
	return State_u8Error;
}
EXIT_tenuErrorStatus EXTI_voidSetInt2SenseControl(u8 Copy_u8SenseControl){
	u8 State_u8Error = EXIT_EnmOk;
		switch (Copy_u8SenseControl){
		case FALLIND_EDGE:
			CLR_BIT(MCUCSR,MCUCSR_ISC2);
		    break;
		case RISING_EDGE:
			SET_BIT(MCUCSR,MCUCSR_ISC2);
			break;
		default: State_u8Error = EXIT_EnmControlLevelError;
		}
		return State_u8Error;
}
EXIT_tenuErrorStatus EXTI_voidInt0Control(u8 Copy_u8Int0State){
	u8 State_u8Error = EXIT_EnmOk;
			switch (Copy_u8Int0State){
			case ENABLE:
				SET_BIT(GICR,GICR_INT0);
			    break;
			case DISENABLE:
				CLR_BIT(GICR,GICR_INT0);
				break;
			default: State_u8Error = EXIT_EnmControlError;
			}
		return State_u8Error;
}
EXIT_tenuErrorStatus EXTI_voidInt1Control(u8 Copy_u8Int1State){
	u8 State_u8Error = EXIT_EnmOk;
				switch (Copy_u8Int1State){
				case ENABLE:
					SET_BIT(GICR,GICR_INT1);
				    break;
				case DISENABLE:
					CLR_BIT(GICR,GICR_INT1);
					break;
				default: State_u8Error = EXIT_EnmControlError;
				}
			return State_u8Error;
}
EXIT_tenuErrorStatus EXTI_voidInt2Control(u8 Copy_u8Int2State){
	u8 State_u8Error = EXIT_EnmOk;
				switch (Copy_u8Int2State){
				case ENABLE:
					SET_BIT(GICR,GICR_INT2);
				    break;
				case DISENABLE:
					CLR_BIT(GICR,GICR_INT2);
					break;
				default: State_u8Error = EXIT_EnmControlError;
				}
			return State_u8Error;
}
void EXTI_voidInt0SetCallBack(void (*Copy_pvNotificationFunction)(void)){
	Global_pvINT0NotFunction = Copy_pvNotificationFunction;
}
void EXTI_voidInt1SetCallBack(void (*Copy_pvNotificationFunction)(void)){
	Global_pvINT1NotFunction = Copy_pvNotificationFunction;
}
void EXTI_voidInt2SetCallBack(void (*Copy_pvNotificationFunction)(void)){
	Global_pvINT2NotFunction = Copy_pvNotificationFunction;
}
 void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(Global_pvINT0NotFunction != NULL){
		Global_pvINT0NotFunction();
	}
}
 void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(Global_pvINT1NotFunction != NULL){
		Global_pvINT1NotFunction();
	}
}
 void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(Global_pvINT2NotFunction != NULL){
		Global_pvINT2NotFunction();
	}
}




