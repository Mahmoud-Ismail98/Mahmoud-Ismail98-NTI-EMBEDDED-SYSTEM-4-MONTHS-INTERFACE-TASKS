/*
 * EXTI.c
 *
 * Created: 10/22/2023 9:29:51 AM
 *  Author: Wael
 */
#include "Std_types.h"
#include "Bit_utils.h"

#include "../inc/EXTI_prv.h"
#include "../inc/EXTI_cfg.h"
#include "../inc/EXTI.h"

static void (*EXTI_INT0_Fptr) (void)=NULL;
static void (*EXTI_INT1_Fptr) (void)=NULL;
static void (*EXTI_INT2_Fptr) (void)=NULL;


void EXTI_voidEnable(u8 Copy_u8EXTI_PIN)
{
	switch(Copy_u8EXTI_PIN){
		case EXTI_INT0:
		SET_BIT(EXTI_GICR,INT0);
		break;
		case EXTI_INT1:
		SET_BIT(EXTI_GICR,INT1);
		break;
		case EXTI_INT2:
		SET_BIT(EXTI_GICR,INT2);
		break;
	}
}

void EXTI_voidSetPinMode(u8 Copy_u8EXTI_PIN,u8 Copy_u8EXTI_PinMode)
{
	switch(Copy_u8EXTI_PIN){
		case EXTI_INT0:
		switch(Copy_u8EXTI_PinMode){
			case EXTI_LOW:
			CLR_BIT(EXTI_MCUCR,ISC00);
			CLR_BIT(EXTI_MCUCR,ISC01);
			break;
			case EXTI_ONCHANGE:
			SET_BIT(EXTI_MCUCR,ISC00);
			CLR_BIT(EXTI_MCUCR,ISC01);
			break;
			case EXTI_FALLING:
			CLR_BIT(EXTI_MCUCR,ISC00);
			SET_BIT(EXTI_MCUCR,ISC01);
			break;
			case EXTI_RISING:
			SET_BIT(EXTI_MCUCR,ISC00);
			SET_BIT(EXTI_MCUCR,ISC01);
			break;

		}
		break;
		case EXTI_INT1:
		switch(Copy_u8EXTI_PinMode){
			case EXTI_LOW:
			CLR_BIT(EXTI_MCUCR,ISC10);
			CLR_BIT(EXTI_MCUCR,ISC11);
			break;
			case EXTI_ONCHANGE:
			SET_BIT(EXTI_MCUCR,ISC10);
			CLR_BIT(EXTI_MCUCR,ISC11);
			break;
			case EXTI_FALLING:
			CLR_BIT(EXTI_MCUCR,ISC10);
			SET_BIT(EXTI_MCUCR,ISC11);
			break;
			case EXTI_RISING:
			SET_BIT(EXTI_MCUCR,ISC10);
			SET_BIT(EXTI_MCUCR,ISC11);
			break;

		}
		break;
		case EXTI_INT2:
		switch(Copy_u8EXTI_PinMode){
			case EXTI_FALLING:
			CLR_BIT(EXTI_MCUCSR,ISC2);
			break;
			case EXTI_RISING:
			SET_BIT(EXTI_MCUCSR,ISC2);
			break;
			default:
			CLR_BIT(EXTI_MCUCSR,ISC2);
		}
		break;
	}
}

void EXTI_voidDisable(u8 Copy_u8EXTI_PIN)
{
	switch(Copy_u8EXTI_PIN){
		case EXTI_INT0:
		CLR_BIT(EXTI_GICR,INT0);
		break;
		case EXTI_INT1:
		CLR_BIT(EXTI_GICR,INT1);
		break;
		case EXTI_INT2:
		CLR_BIT(EXTI_GICR,INT2);
		break;
	}
}
void EXTI_voidSetCallBack(u8 Copy_u8EXTI_PIN, void (*CallBack_func) (void))
{
	switch(Copy_u8EXTI_PIN){
		case EXTI_INT0:
		EXTI_INT0_Fptr=CallBack_func;
		break;
		case EXTI_INT1:
		EXTI_INT1_Fptr=CallBack_func;
		break;
		case EXTI_INT2:
		EXTI_INT2_Fptr=CallBack_func;
		break;

	}

}




ISR(EXTI_INT0_vect)
{

	if (EXTI_INT0_Fptr!=NULL)
	{
		EXTI_INT0_Fptr();
	}
}
ISR(EXTI_INT1_vect)
{
	if (EXTI_INT1_Fptr!=NULL)
	{
		EXTI_INT1_Fptr();
	}
}
ISR(EXTI_INT2_vect)
{
	if (EXTI_INT2_Fptr!=NULL)
	{
		EXTI_INT2_Fptr();
	}
}


