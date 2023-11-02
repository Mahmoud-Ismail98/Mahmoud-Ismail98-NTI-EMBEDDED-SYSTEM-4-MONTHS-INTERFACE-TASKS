/*
 * BUZZER.c
 *
 *  Created on: Aug 5, 2023
 *      Author: Ahmed Dwidar
 */

#include "buzzer.h"


void Buzzer_init(void)
{
	setPinDirection(BUZZER_PIN,PIN_OUTPUT);

	dio_writePin(BUZZER_PIN,LOGIC_LOW);
}

void Buzzer_on(void)
{
	dio_writePin(BUZZER_PIN,LOGIC_HIGH);
}

void Buzzer_off(void)
{
	dio_writePin(BUZZER_PIN,LOGIC_LOW);
}
