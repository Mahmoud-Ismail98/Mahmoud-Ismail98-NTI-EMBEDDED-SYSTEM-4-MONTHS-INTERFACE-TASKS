/*
 * Dio.c
 *
 * Created: 10/20/2023 12:21:14 AM
 *  Author: sharpel
 */ 

#include "std_types.h"
#include "bit_math.h"
#include "../includes/Dio_prv.h"
#include "../includes/Dio.h"
#include "../includes/Dio_cfg.h"

DIO_enu_return_status_t DIO_enu_WriteChannel(DIO_enu_PinId_t arg_enu_pinId,DIO_enu_PinLevel_t arg_enu_pinLevel)
{
	DIO_enu_return_status_t loc_enu_return_status = STATUS_DIO_OKAY;
	u8 loc_u8_pinNumber  = arg_enu_pinId % REG_SIZE ;
	u8 loc_u8_portNumber = arg_enu_pinId / REG_SIZE ;
	
	if( arg_enu_pinId >= DIO_PINID_ERROR)
	{
		loc_enu_return_status = STATUS_DIO_PIN_NUMBER_ERROR;
	}
	else if( arg_enu_pinLevel >= DIO_PIN_LEVEL_ERROR)
	{
		loc_enu_return_status = STATUS_DIO_PIN_LEVEL_CHOICE_ERROR;
	}
	else
	{
		switch(loc_u8_portNumber)
		{
			case DIO_PORT_NUMBER_A :
			{
				(arg_enu_pinLevel == DIO_PIN_LEVEL_LOW)?CLR_BIT(DIO_PORTA,loc_u8_pinNumber):SET_BIT(DIO_PORTA,loc_u8_pinNumber);
				break;
			}
			
			case DIO_PORT_NUMBER_B :
			{
				(arg_enu_pinLevel == DIO_PIN_LEVEL_LOW)?CLR_BIT(DIO_PORTB,loc_u8_pinNumber):SET_BIT(DIO_PORTB,loc_u8_pinNumber);
				break;
			}
			
			case DIO_PORT_NUMBER_C :
			{
				(arg_enu_pinLevel == DIO_PIN_LEVEL_LOW)?CLR_BIT(DIO_PORTC,loc_u8_pinNumber):SET_BIT(DIO_PORTC,loc_u8_pinNumber);
				break;
			}
			
			case DIO_PORT_NUMBER_D :
			{
				(arg_enu_pinLevel == DIO_PIN_LEVEL_LOW)?CLR_BIT(DIO_PORTD,loc_u8_pinNumber):SET_BIT(DIO_PORTD,loc_u8_pinNumber);
				break;
			}
			
		    
		}
	}
	
	
	return loc_enu_return_status;
}
DIO_enu_return_status_t DIO_enu_ReadChannel(DIO_enu_PinId_t arg_enu_pinId,u8 *ptr_value)
{
	DIO_enu_return_status_t loc_enu_return_status = STATUS_DIO_OKAY;
	u8 loc_u8_pinNumber  = arg_enu_pinId % REG_SIZE ;
	u8 loc_u8_portNumber = arg_enu_pinId / REG_SIZE ;
	
	if(ptr_value == PTR_NULL)
	{
		loc_enu_return_status = STATUS_DIO_NULL_PTR_ERROR;
	}
	else if( arg_enu_pinId >= DIO_PINID_ERROR)
	{
		loc_enu_return_status = STATUS_DIO_PIN_NUMBER_ERROR;
	}
	else
	{
		switch(loc_u8_portNumber)
		{
			case DIO_PORT_NUMBER_A :
			{
				*ptr_value = GET_BIT(DIO_PINA,loc_u8_pinNumber);
				break;
			}
			
			case DIO_PORT_NUMBER_B :
			{
				*ptr_value = GET_BIT(DIO_PINB,loc_u8_pinNumber);
				break;
			}
			
			case DIO_PORT_NUMBER_C :
			{
				*ptr_value = GET_BIT(DIO_PINC,loc_u8_pinNumber);
				break;
			}
			
			case DIO_PORT_NUMBER_D :
			{
				*ptr_value = GET_BIT(DIO_PIND,loc_u8_pinNumber);
				break;
			}
			
		}
	}
	
	
	return loc_enu_return_status;
}
DIO_enu_return_status_t DIO_enu_WritePort(DIO_enu_PortNumber_t arg_enu_portNumber,u8 arg_u8_value)
{
	DIO_enu_return_status_t loc_enu_return_status = STATUS_DIO_OKAY;
	
	if( arg_enu_portNumber >= DIO_PORT_NUMBER_ERROR)
	{
		loc_enu_return_status = STATUS_DIO_PORT_NUMBER_CHOICE_ERROR;
	}
	else
	{
		switch(arg_enu_portNumber)
		{
			case DIO_PORT_NUMBER_A :
			{
				ASSIGN_REG(DIO_PORTA,arg_u8_value);
 				break;
			}
			
			case DIO_PORT_NUMBER_B :
			{
				ASSIGN_REG(DIO_PORTB,arg_u8_value);
				break;
			}
			
			case DIO_PORT_NUMBER_C :
			{
				ASSIGN_REG(DIO_PORTC,arg_u8_value);
				break;
			}
			
			case DIO_PORT_NUMBER_D :
			{
				ASSIGN_REG(DIO_PORTD,arg_u8_value);
				break;
			}
			
			
		}
	}
	
	
	return loc_enu_return_status;
}
DIO_enu_return_status_t DIO_enu_ReadPort(DIO_enu_PortNumber_t arg_enu_portNumber,u8 *ptr_value)
{
	DIO_enu_return_status_t loc_enu_return_status = STATUS_DIO_OKAY;
	if(ptr_value == PTR_NULL)
	{
		loc_enu_return_status = STATUS_DIO_NULL_PTR_ERROR;
	}
	else if( arg_enu_portNumber >= DIO_PORT_NUMBER_ERROR)
	{
		loc_enu_return_status = STATUS_DIO_PORT_NUMBER_CHOICE_ERROR;
	}
	else
	{
		switch(arg_enu_portNumber)
		{
			case DIO_PORT_NUMBER_A :
			{
				*ptr_value = DIO_PINA;
				break;
			}
			
			case DIO_PORT_NUMBER_B :
			{
				*ptr_value = DIO_PINB;
				break;
			}
			
			case DIO_PORT_NUMBER_C :
			{
				*ptr_value =DIO_PINC;
				break;
			}
			
			case DIO_PORT_NUMBER_D :
			{
				*ptr_value = DIO_PIND;
				break;
			}
			
		
		}
	}
	
	
	return loc_enu_return_status;
}
DIO_enu_return_status_t DIO_enu_FlipChannel(DIO_enu_PinId_t arg_enu_pinId)
{
	DIO_enu_return_status_t loc_enu_return_status = STATUS_DIO_OKAY;
	u8 loc_u8_pinNumber  = arg_enu_pinId % REG_SIZE ;
	u8 loc_u8_portNumber = arg_enu_pinId / REG_SIZE ;
	
	if( arg_enu_pinId >= DIO_PINID_ERROR)
	{
		loc_enu_return_status = STATUS_DIO_PIN_NUMBER_ERROR;
	}
	else
	{
		switch(loc_u8_portNumber)
		{
			case DIO_PORT_NUMBER_A :
			{
				TGL_BIT(DIO_PORTA,loc_u8_pinNumber);
				break;
			}
			
			case DIO_PORT_NUMBER_B :
			{
				TGL_BIT(DIO_PORTB,loc_u8_pinNumber);
				break;
			}
			
			case DIO_PORT_NUMBER_C :
			{
				TGL_BIT(DIO_PORTC,loc_u8_pinNumber);
				break;
			}
			
			case DIO_PORT_NUMBER_D :
			{
				TGL_BIT(DIO_PORTD,loc_u8_pinNumber);
				break;
			}
			
		
		}
	}
	
	
	return loc_enu_return_status;
}
DIO_enu_return_status_t DIO_enu_FlipPort(DIO_enu_PortNumber_t arg_enu_portNumber)
{
	DIO_enu_return_status_t loc_enu_return_status = STATUS_DIO_OKAY;
	
	if( arg_enu_portNumber >= DIO_PORT_NUMBER_ERROR)
	{
		loc_enu_return_status = STATUS_DIO_PORT_NUMBER_CHOICE_ERROR;
	}
	else
	{
		switch(arg_enu_portNumber)
		{
			case DIO_PORT_NUMBER_A :
			{
				ASSIGN_REG(DIO_PORTA,(~DIO_PORTA));
				break;
			}
			
			case DIO_PORT_NUMBER_B :
			{
				ASSIGN_REG(DIO_PORTB,(~DIO_PORTB));
				break;
			}
			
			case DIO_PORT_NUMBER_C :
			{
				ASSIGN_REG(DIO_PORTC,(~DIO_PORTC));
				break;
			}
			
			case DIO_PORT_NUMBER_D :
			{
				ASSIGN_REG(DIO_PORTD,(~DIO_PORTD));
				break;
			}
			
			
		}
	}
	
	
	return loc_enu_return_status;
}
