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
#include "../inc/SERVICE/SW_ICU/SW_ICU.h"

int main(void)
{
	SW_ICU_voidInit();
	M_GIE_void_EnableGlobalInterrupt();
	u8 TON = 0;
	u8 TOFF = 0;
	u16 DUTY ;
	 LCD_voidInit();
	 PORT_voidInit();
	 LCD_voidInit();
	SW_ICU_voidGetTON_TOFFVals(&TON, &TOFF);
	DUTY = TON+TOFF;
	//SW_ICU_voidGetTON_TOFFVals(&TON, &TOFF);
	while(1)
	{
		SW_ICU_voidGetTON_TOFFVals(&TON, &TOFF);
		_delay_ms(1000);
		M_GIE_void_DisableGlobalInterrupt();
		LCD_voidSetCursorToX_y(LCD_ROW0,LCD_Coloumn0);
		LCD_voidWriteNumbers(TOFF);
		M_GIE_void_EnableGlobalInterrupt();
	}
	return 0;
}

