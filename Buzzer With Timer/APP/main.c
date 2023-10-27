/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../OTHERS/std_types.h"
#include "../OTHERS/common_macros.h"
#include "../MCAL/PORT/INCLUDES/port.h"
#include "../MCAL/DIO/INCLUDES/dio.h"
#include "../MCAL/GIE/INCLUDES/gie.h"
#include "../MCAL/TIMER1/INCLUDES/timer1.h"
#include "../HAL/LCD/INCLUDES/lcd.h"
#include "../HAL/KEYPAD/INCLUDES/keypad.h"
#include <util/delay.h>

#define ENTER_BUTTON 'D'

volatile uint8 g_counting_flag = 0;

void BuzzerOn(void)
{
	DIO_writePin(DIO_PORTB_ID,DIO_PIN0_ID,DIO_HIGH_PIN);
	LCD_displayStringRowColumn("Done    ",LCD_ROW_4_ID,LCD_COLUMN_01_ID);
	GIE_setInterruptStatus(GIE_DISABLE); /* Until create a Timer Disable function. */
}

void InitSystem(void)
{
	PORT_init();
	LCD_init();
	TIMER1_setCallBackFunction(TIMER1_COMPARE_MATCH_MODE,BuzzerOn);
	GIE_setInterruptStatus(GIE_ENABLE);
}

uint32 ReadTimeValue(void)
{
	uint32 LOC_timeValue = 0;
	uint8 LOC_pressedKey = '\0';

	LCD_moveCursor(LCD_ROW_2_ID,LCD_COLUMN_01_ID);

	do
	{
		KEYPAD_getPressedKey(&LOC_pressedKey);

		if((LOC_pressedKey != '\0') && (LOC_pressedKey != ENTER_BUTTON))
		{
			LCD_displayCharacter(LOC_pressedKey);
			LOC_timeValue = ((LOC_timeValue * 10) + (LOC_pressedKey - '0'));
		}

	}while(LOC_pressedKey != ENTER_BUTTON);

	return LOC_timeValue;
}

void InitCounter(uint32 a_timeValue)
{
	TIMER1_configurations g_TIMER1_configurations = {a_timeValue,TIMER1_COMPARE_MATCH_MODE,TIMER1_PRESCALER_1,TIMER1_NON_PWM_NO_OUTPUT,TIMER1_NON_PWM_NO_OUTPUT};
    TIMER1_init(&g_TIMER1_configurations);
}

int main(void)
{
	InitSystem();
	LCD_displayString("Time Value (ms): ");

	InitCounter(ReadTimeValue());
	LCD_displayStringRowColumn("Wait...",LCD_ROW_4_ID,LCD_COLUMN_01_ID);

	while(1);
}
