/*
 * _7segment.c
 *
 * Created: 11/2/2023 11:49:48 AM
 *  Author: sharb
 */ 




#include "std_types.h"
#include "bit_math.h"
#include "../../../MCAL/DIO/includes/Dio.h"
#include "../includes/7segment_cfg.h"
#include "../includes/7segment.h"




#define   BIT0            0
#define   BIT1            1
#define   BIT2            2
#define   BIT3            3


/*
NAME: _7SEGMENT_vidDisplay
DESC: Display Number from 0 to 9 on specific seven segment
ARGS: u8 number to be displayed, u8 selection of seven segment
RET : void

*/

void _7SEGMENT_vidDisplay(u8 arg_u8_num,u8 arg_u8_select)
{
	//// DISABLE ALL Enables
	DIO_enu_WriteChannel(_7SEGMENT_ENABLE_1,DIO_PIN_LEVEL_LOW);
	DIO_enu_WriteChannel(_7SEGMENT_ENABLE_2,DIO_PIN_LEVEL_LOW);
	DIO_enu_WriteChannel(_7SEGMENT_ENABLE_3,DIO_PIN_LEVEL_LOW);
	DIO_enu_WriteChannel(_7SEGMENT_ENABLE_4,DIO_PIN_LEVEL_LOW);
	
	// write Data
	DIO_enu_WriteChannel(_7SEGMENT_DATA_A,GET_BIT(arg_u8_num,BIT0));
	DIO_enu_WriteChannel(_7SEGMENT_DATA_B,GET_BIT(arg_u8_num,BIT1));
	DIO_enu_WriteChannel(_7SEGMENT_DATA_C,GET_BIT(arg_u8_num,BIT2));
	DIO_enu_WriteChannel(_7SEGMENT_DATA_D,GET_BIT(arg_u8_num,BIT3));
	
	// Enable Select
	if (arg_u8_select == FOURTH_7SEGMENT)
	DIO_enu_WriteChannel(_7SEGMENT_ENABLE_1,DIO_PIN_LEVEL_HIGH);
	else if (arg_u8_select == THIRD_7SEGMENT)
	DIO_enu_WriteChannel(_7SEGMENT_ENABLE_2,DIO_PIN_LEVEL_HIGH);
	else if (arg_u8_select == SECOND_7SEGMENT)
	DIO_enu_WriteChannel(_7SEGMENT_ENABLE_3,DIO_PIN_LEVEL_HIGH);
	else if (arg_u8_select == FIRST_7SEGMENT)
	DIO_enu_WriteChannel(_7SEGMENT_ENABLE_4,DIO_PIN_LEVEL_HIGH);
}