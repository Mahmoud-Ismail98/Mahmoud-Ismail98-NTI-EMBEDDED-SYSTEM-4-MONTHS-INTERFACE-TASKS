/*
 * KEYPAD.c
 *
 * Created: 10/25/2023 6:24:51 PM
 *  Author: HP
 */ 

#define F_CPU 8000000UL			
#include <util/delay.h>	
		
#include "../../../services/Std_types.h"
#include "../../../services/Bit_utils.h"
#include "../../../MCAL/DIO/INC/DIO.h"
#include "../INC/KEYPAD.h"
#include "../INC/KEYPAD_prv.h"
#include "../INC/KEYPAD_cfg.h"


const u8 KEYPAD_Au8Keys[4][4]= {
  { '7', '8', '9', '/' },
  { '4', '5', '6', '*' },
  { '1', '2', '3', '-' },
  { 'C', '0', '=', '+' }
};

const u8 KEYPAD_Au8RowsPins[4]={KEYPAD_u8_R1_PIN,KEYPAD_u8_R2_PIN,KEYPAD_u8_R3_PIN,KEYPAD_u8_R4_PIN};
const u8 KEYPAD_Au8ColsPins[4]={KEYPAD_u8_C1_PIN,KEYPAD_u8_C2_PIN,KEYPAD_u8_C3_PIN,KEYPAD_u8_C4_PIN};


KEYPAD_tenuErorStatus KEYPAD_u8GetKeyState(pu8 Copy_pu8ReturnedKey)
{
	u8 Loc_u8ErrorState = KEYPAD_OK;
	u8 Loc_u8RowsCounter,Loc_u8ColsCounter,Loc_u8PinValue,Loc_u8Flag = 0;
	if(Copy_pu8ReturnedKey != NULL)
	{
		*Copy_pu8ReturnedKey = KEYPAD_NOT_PRESSED;
		/* Activate Each Row => For loop on the pins of the rows */
		for(Loc_u8RowsCounter = 0; Loc_u8RowsCounter <= 3 ; Loc_u8RowsCounter++)
		{
			DIO_enuWriteChannel(KEYPAD_Au8RowsPins[Loc_u8RowsCounter],KEYPAD_PIN_LOW);
			/* Check Which Input Pin Has Zero */
			for(Loc_u8ColsCounter = 0; Loc_u8ColsCounter <= 3 ; Loc_u8ColsCounter++)
			{
				DIO_enuReadChannel(KEYPAD_Au8ColsPins[Loc_u8ColsCounter],&Loc_u8PinValue);
				if(Loc_u8PinValue == KEYPAD_PIN_LOW)/* Switch is Pressed */
				{
					/* Debouncing */
					_delay_ms(20);
					DIO_enuReadChannel(KEYPAD_Au8ColsPins[Loc_u8ColsCounter],&Loc_u8PinValue);
					/* Check if the Pin is still equal LOW */
					while(Loc_u8PinValue == KEYPAD_PIN_LOW)
					{
						DIO_enuReadChannel(KEYPAD_Au8ColsPins[Loc_u8ColsCounter],&Loc_u8PinValue);
					}
					*Copy_pu8ReturnedKey = KEYPAD_Au8Keys[Loc_u8RowsCounter][Loc_u8ColsCounter];
					Loc_u8Flag = 1;
					break;						
				}
			}
			/* Deactivate Row */
			DIO_enuWriteChannel(KEYPAD_Au8RowsPins[Loc_u8RowsCounter],KEYPAD_PIN_HIGH);
			if(Loc_u8Flag == 1)
			{	
				break;	
			}
		}
	}
	else
	{
		Loc_u8ErrorState = KEYPAD_NULLPTR;
	}
	return Loc_u8ErrorState;
}



