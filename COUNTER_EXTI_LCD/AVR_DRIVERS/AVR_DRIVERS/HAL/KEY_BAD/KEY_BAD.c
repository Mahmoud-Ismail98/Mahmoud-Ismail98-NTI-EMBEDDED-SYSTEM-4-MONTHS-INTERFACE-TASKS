/*
 * KEY_BAD.c
 *
 * Created: 10/22/2023 12:19:24 PM
 *  Author: ahmed radwan
 */ 
#define F_CPU 16000000UL
#include "../../SERVICES/Standard_Data_Types.h"
#include "../../MCAL/PORT/PORT.h"
#include "../../MCAL/DIO/DIO.h"
#include "KEY_BAD.h"
u8 KeyBad[NO_OF_ROWS][NO_OF_COLUMS]={{'7','8','9','/'},
									 {'4','5','6','*'},
									 {'1','2','3','-'},
									 {'c','0','=','+'}};
KEY_BAD_tenuErrorStatus key_bad_Init(KEY_BAD_ST*key_bad)
{
	KEY_BAD_tenuErrorStatus key_bad_status=KEY_BAD_E_OK;
	if(NULL==key_bad)
	{
		key_bad_status=KEY_BAD_NULL_PTR;
	}
	else
	{
		for(u8 row_counter=0; row_counter<NO_OF_ROWS;row_counter++)
		{
			Port_enuSetpinMode(key_bad->key_bad_rows_pins[row_counter],PIN_MODE_OUTPUT_HIGH);
		}	
		for(u8 col_counter=0; col_counter<NO_OF_COLUMS;col_counter++ )
		{
			Port_enuSetpinMode(key_bad->key_bad_col_pins[col_counter],PIN_CFG_MODE_INPUT_PULLUP);
		}	
	}
	return key_bad_status;
}
KEY_BAD_tenuErrorStatus key_bad_Get_value(KEY_BAD_ST*key_bad,ptr_u8 value)
{
	KEY_BAD_tenuErrorStatus key_bad_status=KEY_BAD_E_OK;
	u8 locla_value='$';
	if(NULL==key_bad)
	{
		key_bad_status=KEY_BAD_NULL_PTR;
	}
	else
	{
		for(u8 row_counter=0;row_counter<NO_OF_ROWS;row_counter++)
		{
			Dio_enuWriteChannel(key_bad->key_bad_rows_pins[row_counter],DIO_PIN_LOW);
			for(u8 col_counter=0;col_counter<NO_OF_COLUMS;col_counter++)
			{
				Dio_enuReadChannel(key_bad->key_bad_rows_pins[col_counter],&locla_value);
				if(locla_value==0)
				{
					*value=KeyBad[row_counter][col_counter];
				}
			}
			Dio_enuWriteChannel(key_bad->key_bad_rows_pins[row_counter],DIO_PIN_HIGH);
		}
	}
	return key_bad_status;
}
