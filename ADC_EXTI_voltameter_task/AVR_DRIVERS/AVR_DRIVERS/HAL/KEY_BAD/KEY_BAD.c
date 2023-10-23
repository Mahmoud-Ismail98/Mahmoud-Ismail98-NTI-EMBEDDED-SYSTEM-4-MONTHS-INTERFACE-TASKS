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
KEY_BAD_tenuErrorStatus key_bad_Init(KEY_BAD_ST*key_bad)
{
	KEY_BAD_tenuErrorStatus key_bad_status=KEY_BAD_E_OK;
	if(NULL==key_bad)
	{
		key_bad_status=KEY_BAD_NULL_PTR;
	}
	else
	{
		for(u8 row_counter=0; row_counter<NO_OF_ROWS;row_counter )
		{
			Port_enuSetpinMode(key_bad->key_bad_rows_pins[row_counter],PIN_MODE_OUTPUT_HIGH);
		}	
		for(u8 col_counter=0; col_counter<NO_OF_COLUMS;col_counter++ )
		{
			Port_enuSetpinMode(key_bad->key_bad_col_pins[col_counter],PIN_MODE_INPUT);
		}	
	}
	return key_bad_status;
}
KEY_BAD_tenuErrorStatus key_bad_Get_value(KEY_BAD_ST*key_bad,ptr_u8 value)
{
	KEY_BAD_tenuErrorStatus key_bad_status=KEY_BAD_E_OK;
	if(NULL==key_bad)
	{
		key_bad_status=KEY_BAD_NULL_PTR;
	}
	else
	{
		for(u8 row_counter=0;row_counter<NO_OF_ROWS;row_counter++)
		{
			
		}
	}
	return key_bad_status;
}
