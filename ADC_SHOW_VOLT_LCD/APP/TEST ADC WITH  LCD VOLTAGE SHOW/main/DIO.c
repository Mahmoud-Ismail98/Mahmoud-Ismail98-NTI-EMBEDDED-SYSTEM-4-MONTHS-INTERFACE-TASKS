#include "../../../MCAL/DIO/include/DIO_cfg.h"
#include "../../../MCAL/DIO/include/DIO_private.h"

#include "../../../services/Std_types.h"
#include "../../../services/Bit_utils.h"
#include "../../../MCAL/DIO/include/DIO.h"






DIO_ERROR_TYPES DIO_WritrPin(u8 pin_id,u8 level_value)
{
	DIO_ERROR_TYPES ERROR_LOCRET =NO_ERROR;
	u8 loc_pin_id =pin_id % 8;

	u8 loc_port_num=pin_id/8;
	switch(loc_port_num)
	{
		case u8PORTA:
		if (GET_BIT(DDRA,loc_pin_id)==PIN_OUTPUT)
		{
			switch (level_value)
			{
				case HIGH_LEVEL:
				SET_BIT(PORTA,loc_pin_id);
				break;
				case LOW_LEVEL:
				CLR_BIT(PORTA,loc_pin_id);
				break;
			}
		}
		else
		{	ERROR_LOCRET=PIN_DIRECTION_ERROR;
		}
		break;
		case u8PORTB:
		if (GET_BIT(DDRB,loc_pin_id)==PIN_OUTPUT)
		{
			switch (level_value)
			{
				case HIGH_LEVEL :
				SET_BIT(PORTB,loc_pin_id);
				break;
				case LOW_LEVEL : 
				CLR_BIT(PORTB,loc_pin_id);
				break;
			}
		}
		else
		{	ERROR_LOCRET=PIN_DIRECTION_ERROR;
		}
		break;
		
		case u8PORTC:
		if (GET_BIT(DDRC,loc_pin_id)==PIN_OUTPUT)
		{
			switch (level_value)
			{
				case HIGH_LEVEL :
				SET_BIT(PORTC,loc_pin_id);
				break;
				case  LOW_LEVEL :
				CLR_BIT(PORTC,loc_pin_id);
				break;
			}
		}
		else
		{	ERROR_LOCRET=PIN_DIRECTION_ERROR;
		}
		break;

		case u8PORTD:
		if (GET_BIT(DDRD,loc_pin_id)==PIN_OUTPUT)
		{
			switch (level_value)
			{
				case HIGH_LEVEL:
				SET_BIT(PORTD,loc_pin_id);
				break;
				case LOW_LEVEL:
				CLR_BIT(PORTD,loc_pin_id);
				break;
			}
		}
		else
		{	ERROR_LOCRET=PIN_DIRECTION_ERROR;
		}
		break;
	}
	return ERROR_LOCRET;
}

DIO_ERROR_TYPES  DIO_READ_PIN(u8 pin_id,u8 *ptr_val)
{
	DIO_ERROR_TYPES ERROR_LOCRET=NO_ERROR;
	//u8 *ptr_val= ptr_val;

	u8 loc_pin_id =pin_id % 8;
	u8 loc_port_num=pin_id/8;
	
	switch(loc_port_num)
	{
		case u8PORTA:
		if(GET_BIT(DDRA,loc_pin_id)==PIN_INPUT)
		*ptr_val=(GET_BIT(PINA,loc_pin_id));
		
		else   ERROR_LOCRET=PIN_DIRECTION_ERROR;
		
		case u8PORTB:
		if(GET_BIT(DDRB,loc_pin_id)==PIN_INPUT)
		*ptr_val=(GET_BIT(PINB,loc_pin_id));
		
		else   ERROR_LOCRET=PIN_DIRECTION_ERROR;
		
		break;
		
		case u8PORTC:
		if(GET_BIT(DDRC,loc_pin_id)==PIN_INPUT)
		*ptr_val=(GET_BIT(PINC,loc_pin_id));
		
		else   ERROR_LOCRET=PIN_DIRECTION_ERROR;
		
		break;
		
		case u8PORTD:
		if(GET_BIT(DDRD,loc_pin_id)==PIN_INPUT)
		*ptr_val=(GET_BIT(PIND,loc_pin_id));
		
		else   ERROR_LOCRET=PIN_DIRECTION_ERROR;
		
		break;
		
		default :
		ERROR_LOCRET = PORT_ERROR;
		break;
	}
	
	return ERROR_LOCRET;

}


DIO_ERROR_TYPES  DIO_WritePort(u8 port_num,u8 port_value)
{
	DIO_ERROR_TYPES ERROR_LOCRET =NO_ERROR;
	
	switch(port_num)
	{
		case u8PORTA:
		PORTA = port_value;
		break;
		
		case u8PORTB:
		PORTA = port_value;
		break;

		case u8PORTC:
		PORTC = port_value;
		break;

		case u8PORTD:
		PORTD = port_value;
		break;
		
		default:
		ERROR_LOCRET=PORT_ERROR;
		
	}
	return ERROR_LOCRET;
}

DIO_ERROR_TYPES  DIO_ReadPort(u8 port_num,u8 *ptr_val)
{
	
	DIO_ERROR_TYPES ERROR_LOCRET =NO_ERROR;
	
	//u8 *ptr_val =ptr_val;
	switch(port_num)
	{
		case u8PORTA:
		*ptr_val=PINA;
		break;
		
		case u8PORTB:
		*ptr_val=PINB;
		break;

		case u8PORTC:
		*ptr_val=PINC;
		break;

		case u8PORTD:
		*ptr_val=PIND;
		break;
		
		default:
		ERROR_LOCRET=PORT_ERROR;
	}

	return ERROR_LOCRET;
}