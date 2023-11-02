#include <avr/io.h>
#include <util/delay.h>

#include "Std_types.h"
#include "Bit_utils.h"


#include "Dio.h"
#include "Port.h"
#include "SevenSegment.h"



StopWatchSystem_numberFormat g_clock_counter = {0,0,0,0};

int main(void)
{
	Port_vidInit();

	while(1)
	{	
		
		 if(CheckButtonPressed(DIO_u8PORTB,DIO_u8CHANNEL08) == BUTTON_PRESSED)
		 {
		 	IncrementCounter();
		 }

		 if(CheckButtonPressed(DIO_u8PORTB,DIO_u8CHANNEL09) == BUTTON_PRESSED)
		 {
		 	DecrementCounter();
		 }

		 if(CheckButtonPressed(DIO_u8PORTB,DIO_u8CHANNEL10) == BUTTON_PRESSED)
		 {
		 	ResetCounter();
		 }

		SSD_displayNumber(g_clock_counter.units);
		SSD_enableSevenSegment(0);
		_delay_ms(DISPLAY_DELAY);
		SSD_displayNumber(g_clock_counter.tens);
		SSD_enableSevenSegment(1);
		_delay_ms(DISPLAY_DELAY);
		SSD_displayNumber(g_clock_counter.hundreds);
		SSD_enableSevenSegment(2);
		_delay_ms(DISPLAY_DELAY);
		SSD_displayNumber(g_clock_counter.thousands);
		SSD_enableSevenSegment(3);
		_delay_ms(DISPLAY_DELAY);
	}
}
void SSD_displayNumber(u8 a_number)
{
	Dio_enuWriteChannel(SSD_DECODER_PIN0_ID,GET_BIT(a_number,0));
	Dio_enuWriteChannel(SSD_DECODER_PIN1_ID,GET_BIT(a_number,1));
	Dio_enuWriteChannel(SSD_DECODER_PIN2_ID,GET_BIT(a_number,2));
	Dio_enuWriteChannel(SSD_DECODER_PIN3_ID,GET_BIT(a_number,3));
}

void SSD_enableSevenSegment(u8 a_sevenSegementID)
{
	Dio_enuWriteChannel(SSD_ENABLE_PIN0_ID,DIO_u8LEVEL_LOW);
	Dio_enuWriteChannel(SSD_ENABLE_PIN1_ID,DIO_u8LEVEL_LOW);
	Dio_enuWriteChannel(SSD_ENABLE_PIN2_ID,DIO_u8LEVEL_LOW);
	Dio_enuWriteChannel(SSD_ENABLE_PIN3_ID,DIO_u8LEVEL_LOW);
	Dio_enuWriteChannel((SSD_ENABLE_PIN0_ID + a_sevenSegementID),DIO_u8LEVEL_HIGH);
}

buttonStatus CheckButtonPressed(u8 a_portID, u8 a_pinID)
{
	buttonStatus LOC_buttonStatus = BUTTON_NOT_PRESSED;
	Dio_enuReadChannel(a_pinID,&LOC_buttonStatus);

	if(LOC_buttonStatus == BUTTON_PRESSED)
	{
		LOC_buttonStatus = BUTTON_PRESSED;
	
	}
    

	return LOC_buttonStatus;
}

void IncrementCounter(void)
{
	g_clock_counter.units++;
	if(g_clock_counter.units > 9)
	{
		g_clock_counter.units = 0;
		g_clock_counter.tens++;
		if(g_clock_counter.tens > 9)
		{
			g_clock_counter.tens = 0;
     		g_clock_counter.hundreds++;
			if(g_clock_counter.hundreds > 9)
			{
				g_clock_counter.hundreds = 0;
				g_clock_counter.thousands++;
				if(g_clock_counter.thousands > 9)
				{
					g_clock_counter.thousands = 0;
				}
			}
		}
	}
}

void DecrementCounter(void)
{
	if(g_clock_counter.units == 0)
	{
		
		if(g_clock_counter.tens == 0)
		{
		   if(g_clock_counter.hundreds == 0)
			{
			}
				else
				{
					
					g_clock_counter.tens = 9 ;
					g_clock_counter.hundreds --   ;
				}
				
			}
			else
			{
				
				g_clock_counter.units = 9 ;
				g_clock_counter.tens --   ;
			}
			
		}
	
	else
	 {
		 g_clock_counter.units -- ; 
		 
		 
	  }
  }

void ResetCounter(void)
{
	g_clock_counter.units = 0;
	g_clock_counter.tens = 0;
	g_clock_counter.hundreds = 0;
	g_clock_counter.thousands = 0;
}
