/*
=======================================================================================================================
Author       : Mamoun
Project      : Counetr With SSD
File Name    : CounterWithSSD.c
Date Created : Oct 21, 2023
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
#include "CounterWithSSD.h"
#include <util/delay.h>

/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/

SSD_numberFormat g_sevenSegmentCounter = {0,0,0,0};

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/
int main(void)
{
    PORT_init();

    while(1)
    {
    	BUTTON_buttonStatus LOC_incrementButtonStatus = BUTTON_NOT_PRESSED;
    	BUTTON_buttonStatus LOC_decrementButtonStatus = BUTTON_NOT_PRESSED;
    	BUTTON_buttonStatus LOC_resetButtonStatus = BUTTON_NOT_PRESSED;

    	BUTTON_readButtonState(INCREMENT_BUTTON_PORT_ID,INCREMENT_BUTTON_PIN_ID,BUTTON_PULLDOWN_CONNECTION,&LOC_incrementButtonStatus);
    	BUTTON_readButtonState(DECREMENT_BUTTON_PORT_ID,DECREMENT_BUTTON_PIN_ID,BUTTON_PULLDOWN_CONNECTION,&LOC_decrementButtonStatus);
    	BUTTON_readButtonState(RESET_BUTTON_PORT_ID,RESET_BUTTON_PIN_ID,BUTTON_PULLDOWN_CONNECTION,&LOC_resetButtonStatus);

        if(LOC_incrementButtonStatus == BUTTON_PRESSED)
        {
            IncrementCounter();
            SSD_display();
        }

        else if(LOC_decrementButtonStatus == BUTTON_PRESSED)
        {
            DecrementCounter();
            SSD_display();
        }

        else if(LOC_resetButtonStatus == BUTTON_PRESSED)
        {
            ResetCounter();
            SSD_display();
        }

        else
        {
        	SSD_display();
        }
    }

    return 0;
}

void SSD_display(void)
{
	uint8 LOC_displayedNumber[SSD_NUM_OF_MPX_SSD] = {g_sevenSegmentCounter.units,
			                                         g_sevenSegmentCounter.tens,
			                                         g_sevenSegmentCounter.hundreds,
			                                         g_sevenSegmentCounter.thousands};

	for(uint8 ssd_iterator = 0; ssd_iterator < SSD_NUM_OF_MPX_SSD; ssd_iterator++)
	{
		SSD_displayNumber(*(LOC_displayedNumber + ssd_iterator));
		SSD_enableSevenSegment(ssd_iterator);
		_delay_ms(SSD_DISPLAY_DELAY);
	}
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
	uint8 portIDs[4] = {SSD_ENABLE1_PORT_ID,SSD_ENABLE2_PORT_ID,SSD_ENABLE3_PORT_ID,SSD_ENABLE4_PORT_ID};
	uint8 pinIDs[4] = {SSD_ENABLE1_PIN0_ID,SSD_ENABLE2_PIN0_ID,SSD_ENABLE3_PIN0_ID,SSD_ENABLE4_PIN0_ID};

    DIO_writePin(SSD_ENABLE1_PORT_ID,SSD_ENABLE1_PIN0_ID,DIO_LOW_PIN);
    DIO_writePin(SSD_ENABLE2_PORT_ID,SSD_ENABLE2_PIN0_ID,DIO_LOW_PIN);
    DIO_writePin(SSD_ENABLE3_PORT_ID,SSD_ENABLE3_PIN0_ID,DIO_LOW_PIN);
    DIO_writePin(SSD_ENABLE4_PORT_ID,SSD_ENABLE4_PIN0_ID,DIO_LOW_PIN);

    DIO_writePin(*(pinIDs + a_sevenSegementID),*(portIDs + a_sevenSegementID),DIO_HIGH_PIN);
}

void IncrementCounter(void)
{
	g_sevenSegmentCounter.units++;
	if(g_sevenSegmentCounter.units > 9)
	{
		g_sevenSegmentCounter.units = 0;
		g_sevenSegmentCounter.tens++;
		if(g_sevenSegmentCounter.tens > 9)
		{
			g_sevenSegmentCounter.tens = 0;
			g_sevenSegmentCounter.hundreds++;
			if(g_sevenSegmentCounter.hundreds > 9)
			{
				g_sevenSegmentCounter.hundreds = 0;
				g_sevenSegmentCounter.thousands++;
				if(g_sevenSegmentCounter.thousands > 9)
				{
					g_sevenSegmentCounter.thousands = 0;
				}
			}
		}
	}
}

void DecrementCounter(void)
{
	if(g_sevenSegmentCounter.units == 0)
	{
		if(g_sevenSegmentCounter.tens == 0)
		{
			if(g_sevenSegmentCounter.hundreds == 0)
			{
				if(g_sevenSegmentCounter.thousands == 0)
				{
					/* Do Nothing. */
				}
				else
				{
					g_sevenSegmentCounter.hundreds = 9;
					g_sevenSegmentCounter.thousands--;
				}
			}
			else
			{
				g_sevenSegmentCounter.tens = 9;
				g_sevenSegmentCounter.hundreds--;
			}
		}
		else
		{
			g_sevenSegmentCounter.units = 9;
			g_sevenSegmentCounter.tens--;
		}
	}
	else
	{
		g_sevenSegmentCounter.units--;
	}
}

void ResetCounter(void)
{
	g_sevenSegmentCounter.units = 0;
	g_sevenSegmentCounter.tens = 0;
	g_sevenSegmentCounter.hundreds = 0;
	g_sevenSegmentCounter.thousands = 0;
}
