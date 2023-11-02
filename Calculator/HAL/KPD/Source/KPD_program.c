/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 22 Oct 2023                                                           */
/************************************************************************************/

#include "../../../LIB/Include/STD_TYPES.h"
#include "../../../LIB/Include/BIT_MATH.h"

#include "../../../MCAL/PORT/Include/PORT_interface.h"
#include "../../../MCAL/DIO/Include/DIO_interface.h"

#include "../Include/KPD_interface.h"
#include "../Include/KPD_private.h"
#include "../Include/KPD_config.h"

#define F_CPU   8000000UL
#include <util/delay.h>

const u8 KPD_Au8Keys[4][4] = KPD_KEYS;
/* Arrays for ROW Pins / COL Pins */
const u8 KPD_Au8RowPins[4] = {KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN,KPD_u8_R4_PIN};
const u8 KPD_Au8ColPins[4] = {KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN,KPD_u8_C4_PIN};


KPDEnum KPD_KPDEnumGetKeyState  (pu8 Copy_Pu8ReturnedKey)
{
	KPDEnum Local_KPDEnumErrorState = KPD_OK;
	u8 Local_u8RowCounter,Local_u8ColCounter,Local_u8PinValue,Local_u8Flag=0;
	if( Copy_Pu8ReturnedKey != NULL )
	{
		*Copy_Pu8ReturnedKey = KPD_u8_KEY_NOT_PRESSED;
		/* Activate Each Row Pin */
		for(Local_u8RowCounter = 0;Local_u8RowCounter <= 3;Local_u8RowCounter++)
		{
			DIO_DioEnumWriteChannel(KPD_u8_PORT,KPD_Au8RowPins[Local_u8RowCounter],DIO_u8_LOW);
			/* Check Col Pins are Pressed or Not */
			for(Local_u8ColCounter = 0;Local_u8ColCounter <= 3;Local_u8ColCounter++)
			{
				DIO_DioEnumReadChannel(KPD_u8_PORT,KPD_Au8ColPins[Local_u8ColCounter],&Local_u8PinValue);
				if(Local_u8PinValue == DIO_u8_LOW)  //switch is pressed
				{
					/* Debouncing */
					_delay_ms(20);
					/* Then Check Again */
					DIO_DioEnumReadChannel(KPD_u8_PORT,KPD_Au8ColPins[Local_u8ColCounter],&Local_u8PinValue);
					while (Local_u8PinValue == DIO_u8_LOW)
					{
					   DIO_DioEnumReadChannel(KPD_u8_PORT,KPD_Au8ColPins[Local_u8ColCounter],&Local_u8PinValue);	
					}
					*Copy_Pu8ReturnedKey = KPD_Au8Keys[Local_u8RowCounter][Local_u8ColCounter];
					Local_u8Flag = 1;
					break;
				}
			}
			/* DeActivate */
			DIO_DioEnumWriteChannel(KPD_u8_PORT,KPD_Au8RowPins[Local_u8RowCounter],DIO_u8_HIGH);
			if (Local_u8Flag == 1)
			{
				break;
			}
		}
	}
	else
	{
		Local_KPDEnumErrorState = KPD_OK;
	}
	return Local_KPDEnumErrorState;
}
