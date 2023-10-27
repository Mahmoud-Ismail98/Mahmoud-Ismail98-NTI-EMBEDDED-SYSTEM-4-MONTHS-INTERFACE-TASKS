/*
=======================================================================================================================
Author       : Mamoun
Project      : Stop Watch System
File Name    : StopWatchSystem.c
Date Created : Oct 26, 2023
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../OTHERS/std_types.h"
#include "../OTHERS/common_macros.h"
#include "../MCAL/PORT/INCLUDES/port.h"
#include "../MCAL/DIO/INCLUDES/dio.h"
#include "../HAL/BUTTON/INCLUDES/button.h"
#include "StopWatchSystem.h"
#include <util/delay.h>

/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/

SSD_numberFormat g_secondsCounter = {0,0,0,0};

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/
int main(void)
{
	PORT_init();

	while(1)
	{
		uint8 LOC_displayedNumber[SSD_NUM_OF_MPX_SSD] = {g_secondsCounter.units,
				                                         g_secondsCounter.tens,
				                                         g_secondsCounter.hundreds,
				                                         g_secondsCounter.thousands};

		static uint8 LOC_startCountFlag = 0;
		BUTTON_buttonStatus LOC_startButtonStatus = BUTTON_NOT_PRESSED;
		BUTTON_buttonStatus LOC_pauseButtonStatus = BUTTON_NOT_PRESSED;
		BUTTON_buttonStatus LOC_resetButtonStatus = BUTTON_NOT_PRESSED;

		BUTTON_readButtonState(START_BUTTON_PORT_ID,START_BUTTON_PIN_ID,BUTTON_PULLDOWN_CONNECTION,&LOC_startButtonStatus);
		BUTTON_readButtonState(PAUSE_BUTTON_PORT_ID,PAUSE_BUTTON_PIN_ID,BUTTON_PULLDOWN_CONNECTION,&LOC_pauseButtonStatus);
		BUTTON_readButtonState(RESET_BUTTON_PORT_ID,RESET_BUTTON_PIN_ID,BUTTON_PULLDOWN_CONNECTION,&LOC_resetButtonStatus);

		if(LOC_startButtonStatus == BUTTON_PRESSED)
		{
			DIO_writePin(DIO_PORTD_ID,DIO_PIN7_ID,DIO_HIGH_PIN);
			LOC_startCountFlag = 1;
		}

		else if(LOC_pauseButtonStatus == BUTTON_PRESSED)
		{
			LOC_startCountFlag = 0;
		}

		else if(LOC_resetButtonStatus == BUTTON_PRESSED)
		{
			ResetCounter();
			LOC_startCountFlag = 0;
		}

		for(uint8 time_counter = 0; time_counter < 20; time_counter++)
		{
			for(uint8 ssd_iterator = 0; ssd_iterator < SSD_NUM_OF_MPX_SSD; ssd_iterator++)
			{
				BUTTON_readButtonState(START_BUTTON_PORT_ID,START_BUTTON_PIN_ID,BUTTON_PULLDOWN_CONNECTION,&LOC_startButtonStatus);
				BUTTON_readButtonState(PAUSE_BUTTON_PORT_ID,PAUSE_BUTTON_PIN_ID,BUTTON_PULLDOWN_CONNECTION,&LOC_pauseButtonStatus);
				BUTTON_readButtonState(RESET_BUTTON_PORT_ID,RESET_BUTTON_PIN_ID,BUTTON_PULLDOWN_CONNECTION,&LOC_resetButtonStatus);

				SSD_displayNumber(*(LOC_displayedNumber + ssd_iterator));
				SSD_enableSevenSegment(ssd_iterator);
				_delay_ms(SSD_DISPLAY_DELAY);
			}

		}
		if(LOC_startCountFlag == 1)
		{
			IncrementCounter();
		}
	}

	return 0;
}

void SSD_displayNumber(uint8 a_number)
{
    DIO_writePin(SSD_DECODER_PORT_ID,SSD_DECODER_PIN0_ID,GET_BIT(a_number,0));
    DIO_writePin(SSD_DECODER_PORT_ID,SSD_DECODER_PIN1_ID,GET_BIT(a_number,1));
    DIO_writePin(SSD_DECODER_PORT_ID,SSD_DECODER_PIN2_ID,GET_BIT(a_number,2));
    DIO_writePin(SSD_DECODER_PORT_ID,SSD_DECODER_PIN3_ID,GET_BIT(a_number,3));
}

void SSD_enableSevenSegment(uint8 a_sevenSegementID)
{
    DIO_writePin(SSD_ENABLE_PORT_ID,SSD_ENABLE_PIN0_ID,DIO_LOW_PIN);
    DIO_writePin(SSD_ENABLE_PORT_ID,SSD_ENABLE_PIN1_ID,DIO_LOW_PIN);
    DIO_writePin(SSD_ENABLE_PORT_ID,SSD_ENABLE_PIN2_ID,DIO_LOW_PIN);
    DIO_writePin(SSD_ENABLE_PORT_ID,SSD_ENABLE_PIN3_ID,DIO_LOW_PIN);
    DIO_writePin(SSD_ENABLE_PORT_ID,(SSD_ENABLE_PIN0_ID + a_sevenSegementID),DIO_HIGH_PIN);
}

void IncrementCounter(void)
{
	DIO_togglePin(DIO_PORTD_ID,DIO_PIN7_ID);

	g_secondsCounter.units++;
	if(g_secondsCounter.units > 9)
	{
		g_secondsCounter.units = 0;
		g_secondsCounter.tens++;
		if(g_secondsCounter.tens > 9)
		{
			g_secondsCounter.tens = 0;
			g_secondsCounter.hundreds++;
			if(g_secondsCounter.hundreds > 9)
			{
				g_secondsCounter.hundreds = 0;
				g_secondsCounter.thousands++;
				if(g_secondsCounter.thousands > 9)
				{
					g_secondsCounter.thousands = 0;
				}
			}
		}
	}
}

void ResetCounter(void)
{
	g_secondsCounter.units = 0;
	g_secondsCounter.tens = 0;
	g_secondsCounter.hundreds = 0;
	g_secondsCounter.thousands = 0;
}
