/*
 * exInterrupt.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Ahmed Dwidar
 */
#include"exInterrupt.h"
#include"avr/interrupt.h"

static void(*clbck_ptr[2])(void);


ISR(INT0_vect)
{
	if(clbck_ptr[0] != NULL)
	{
		clbck_ptr[0]();
	}
}

ISR(INT1_vect)
{
	if(clbck_ptr[1] != NULL)
	{
		clbck_ptr[1]();
	}
}
void callBack(void(*loc_clbk_ptr)(void), u8 index)
{
	clbck_ptr[index] = loc_clbk_ptr;
}

void exInt0_enable(u8 trigger)
{
	SET_BIT(GICR,BIT_6);
	ASSIGN_FIRST_TWO_BITS(MCUCR,trigger);
}
void exInt0_disable(void)
{
	setPinDirection(PORT_PIN26_ID,PIN_OUTPUT);
	CLEAR_BIT(GICR,BIT_6);
}
void exInt1_enable(u8 trigger)
{
	SET_BIT(GICR,BIT_7);
	ASSIGN_SECOND_TWO_BITS(MCUCR,trigger);
}
void exInt1_disable(void)
{
	setPinDirection(PORT_PIN27_ID,PIN_INPUT);
	CLEAR_BIT(GICR,BIT_7);
}
void exInt2_enable(u8 trigger)
{
	SET_BIT(GICR,BIT_5);
	SET_BIT(MCUCSR,BIT_5);
}
void exInt2_disable(void)
{
	setPinDirection(PORT_PIN28_ID,PIN_INPUT);
	CLEAR_BIT(GICR,BIT_5);
}
