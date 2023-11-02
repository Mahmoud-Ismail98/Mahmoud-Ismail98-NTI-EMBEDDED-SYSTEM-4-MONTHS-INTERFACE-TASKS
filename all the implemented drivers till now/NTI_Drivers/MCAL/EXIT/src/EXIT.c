/*
 * EXIT_Program.c
 *
 *  Created on: Oct 21, 2022
 *      Author: Ismail
 */

/*1)set the sense control
 * 2)Enable PIE(peripheral interrupt enable )
 * 3) ENABLE GIE
 */
#include "../../../Services/Std_types.h"
#include "../../../Services/Bit_utils.h"
#include"../includes/EXIT.h"
#include"../includes/EXIT_cfg.h"



void EXIT0_Init(){
#if EXIT_SENSE_CONTROL_STATE==EXIT_LOW_LEVEL
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif EXIT_SENSE_CONTROL_STATE==EXIT_ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif EXIT_SENSE_CONTROL_STATE==EXIT_RISING_EDGE
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,0);
#elif EXIT_SENSE_CONTROL_STATE==EXIT_FALLING_EDGE
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,0);
#endif
/*enable interrupt on int0*/
	SET_BIT(GICR,6);

}
void EXIT0_Disable(){
	CLR_BIT(GICR,6);


}
void EXIT1_Init(){
#if EXIT_SENSE_CONTROL_STATE==EXIT_LOW_LEVEL
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif EXIT_SENSE_CONTROL_STATE==EXIT_ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif EXIT_SENSE_CONTROL_STATE==EXIT_RISING_EDGE
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,0);
#elif EXIT_SENSE_CONTROL_STATE==EXIT_FALLING_EDGE
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,0);
#endif
/*enable interrupt on int1*/
	SET_BIT(GICR,7);


}
void EXIT_Set_Sense_Control(u8 Copy_u8Interrupt_ID, u8 Copy_u8Mode){

if(Copy_u8Interrupt_ID == EXTI_LINE0){
	switch (Copy_u8Mode){
	case EXIT_LOW_LEVEL:
		CLR_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);

		break;
	case EXIT_ANY_LOGICAL_CHANGE :
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	break;
	case EXIT_RISING_EDGE:
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,0);
	break;
	case EXIT_FALLING_EDGE:
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,0);
	break;
	default:
		/*wrong  number passed */
		break;
	}
	SET_BIT(GICR,6);
}

if(Copy_u8Interrupt_ID == EXTI_LINE1){
	switch (Copy_u8Mode){
	case EXIT_LOW_LEVEL:
		CLR_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
		break;
	case EXIT_ANY_LOGICAL_CHANGE :
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	break;
	case EXIT_RISING_EDGE:
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,0);
	break;
	case EXIT_FALLING_EDGE:
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,0);
	break;
	default:
		/*wrong  number passed */
		break;
	}
	SET_BIT(GICR,7);
}
if(Copy_u8Interrupt_ID == EXTI_LINE1){
	switch (Copy_u8Mode){
	case EXIT_LOW_LEVEL:
		CLR_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
		break;
	case EXIT_ANY_LOGICAL_CHANGE :
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	break;
	case EXIT_RISING_EDGE:
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,0);
	break;
	case EXIT_FALLING_EDGE:
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,0);
	break;
	default:
		/*wrong  number passed */
		break;
	}
	SET_BIT(GICR,5);
}

}
void EXIT2_Init(){

#if EXIT_SENSE_CONTROL_STATE==EXIT_RISING_EDGE
	CLR_BIT(MCUCSR,0);
#elif EXIT_SENSE_CONTROL_STATE==EXIT_FALLING_EDGE
	SET_BIT(MCUCSR,0);
#endif
/*enable interrupt on int2*/
	SET_BIT(GICR,5);
}

void EXTI_voidClearFlag(u8 Copy_u8Line) {
	switch (Copy_u8Line) {
	case EXTI_LINE0:
		SET_BIT(GIFR, GIFR_INTF0_BIT);
		break;
	case EXTI_LINE1:
		SET_BIT(GIFR, GIFR_INTF1_BIT);
		break;
	case EXTI_LINE2:
		SET_BIT(GICR, GICR_INT2_BIT);
		break;
	}
}
void EXTI_voidCallBack(void (*Copy_pvoidCallBack)(void), u8 Copy_u8EXTILine) {

	if (Copy_pvoidCallBack != NULL) {
		gptr[Copy_u8EXTILine] = Copy_pvoidCallBack;
	}
}

void __vector_1(void) {
	if (gptr[0] != NULL) {
		gptr[0]();
		EXTI_voidClearFlag(EXTI_LINE0);
	}
}

void __vector_2(void) {
	if (gptr[1] != NULL) {
		gptr[1]();
		EXTI_voidClearFlag(EXTI_LINE1);
	}
}

void __vector_3(void) {
	if (gptr[2] != NULL) {
		gptr[2]();
		EXTI_voidClearFlag(EXTI_LINE2);

	}
}
