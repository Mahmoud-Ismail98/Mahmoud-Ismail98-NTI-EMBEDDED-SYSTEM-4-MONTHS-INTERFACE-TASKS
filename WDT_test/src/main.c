/*
 * main.c
 *
 *  Created on: Oct 27, 2023
 *      Author: bishoy18126
 */
#include "../inc/LIB/Std_types.h"
#include "../inc/LIB/Bit_utils.h"
#include "../inc/HAL/KEYPAD/KEYPAD_int.h"
#include "../inc/HAL/LCD/LCD.h"
#include "../inc/MCAL/ADC/ADC_int.h"
#include "../inc/MCAL/DIO/DIO_int.h"
#include "../inc/MCAL/EXTI/EXTI_int.h"
#include "../inc/MCAL/GIE/GIE_int.h"
#include "../inc/MCAL/PORT/PORT.h"
#include "../inc/MCAL/TIMER0/TIMER0_int.h"
#include "../inc/MCAL/WDT/WDT.h"
#include <util/delay.h>

int main(void)
{
	WDT_voidEnablePeripheral(WDT_Prescaller7);
	_delay_ms (9000);
	while(1)
	{
		DIO_enum_FlipChannel(DIO_u8PORTAPIN0);
		_delay_ms (1000);
	}
	return 0;
}

