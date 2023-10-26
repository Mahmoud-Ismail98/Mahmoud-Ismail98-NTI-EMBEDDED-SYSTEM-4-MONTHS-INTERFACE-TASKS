/*
 * dio.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Dwidar
 */
#include"dio.h"
#include"dio_prv.h"
#include"dio_cfg.h"
#include<avr/io.h>
DIO_errorStatus dio_writePin(u8 pin_id, u8 value)
{
	DIO_errorStatus return_errorStatus = Dio_Ok;
	u8 loc_port;

	u8 loc_pin;

	if(pin_id > NUM_OF_PINS)
	{
		return_errorStatus = Dio_pinError;
	}
	else if(value > NUM_OF_LEVELS)
	{
		return_errorStatus = Dio_levelError;
	}
	else
	{
		loc_pin = pin_id % NUM_OF_PINS_PER_PORT;
		loc_port = pin_id / NUM_OF_PINS_PER_PORT;

		switch(loc_port)
		{

		case DIO_PORTA:

			switch (value)
			{

			case DIO_HIGH:

				SET_BIT(PORTA, loc_pin);

				break;

			case DIO_LOW:

				CLEAR_BIT(PORTA, loc_pin);

				break;
			}
			break;

		case DIO_PORTB:

			switch (value)
			{

			case DIO_HIGH:

				SET_BIT(PORTB, loc_pin);

				break;

			case DIO_LOW:

				CLEAR_BIT(PORTB, loc_pin);

				break;


			}
			break;


		case DIO_PORTC:

			switch (value)
			{

			case DIO_HIGH:

				SET_BIT(PORTC, loc_pin);

				break;

			case DIO_LOW:

				CLEAR_BIT(PORTC, loc_pin);

				break;

			}
			break;



		case DIO_PORTD:

			switch (value)
			{

			case DIO_HIGH:

				SET_BIT(PORTD, loc_pin);

				break;

			case DIO_LOW:

				CLEAR_BIT(PORTD, loc_pin);

				break;


			break;
			}


		}
	}

	return return_errorStatus;
}
DIO_errorStatus dio_readPin(u8 pin_id, pu8 level)
{
	DIO_errorStatus return_errorStatus = Dio_Ok;
	u8 loc_port;

	u8 loc_pin;

	if(pin_id > NUM_OF_PINS)
	{
		return_errorStatus = Dio_pinError;
	}
	else if(level == NULL)
	{
		return_errorStatus = Dio_NullPointerError;
	}
	else
	{
		loc_pin = pin_id % NUM_OF_PINS_PER_PORT;
		loc_port = pin_id / NUM_OF_PINS_PER_PORT;

		switch(loc_port)
		{

		case DIO_PORTA:

			if (GET_BIT(DDRA,loc_pin) == PORT_INPUT)
			{
				*level = GET_BIT(PINA, loc_pin);
			}
			else
			{
				return_errorStatus = Dio_directionError;
			}
				break;


		case DIO_PORTB:

			if (GET_BIT(DDRB,loc_pin) == PORT_INPUT)
			{
				*level = GET_BIT(PINB, loc_pin);
			}
			else
			{
				return_errorStatus = Dio_directionError;
			}
				break;



		case DIO_PORTC:

			if (GET_BIT(DDRC,loc_pin) == PORT_INPUT)
			{

				*level = GET_BIT(PINC, loc_pin);

			}
			else
			{
				return_errorStatus = Dio_directionError;
			}

				break;


		case DIO_PORTD:

			if (GET_BIT(DDRD,loc_pin) == PORT_INPUT)
			{

				*level = GET_BIT(PIND, loc_pin);

			}
			else
			{
				return_errorStatus = Dio_directionError;
			}
				break;

		}
	}

	return return_errorStatus;
}
DIO_errorStatus dio_writePort(u8 port_id, u8 value)
{
	DIO_errorStatus return_errorStatus = Dio_Ok;

	if (port_id > NUM_OF_PORTS) {

		return_errorStatus = Dio_portError;
	}

	else {

		switch (port_id) {

		case DIO_PORTA:

			ASSIGN_REG(PORTA, value);

			break;

		case DIO_PORTB:

			ASSIGN_REG(PORTB, value);

			break;

		case DIO_PORTC:

			ASSIGN_REG(PORTC, value);

			break;

		case DIO_PORTD:

			ASSIGN_REG(PORTD, value);

			break;

		}

	}

	return return_errorStatus;
}
DIO_errorStatus dio_readPort(u8 port_id, pu8 level)
{
	DIO_errorStatus return_errorStatus = Dio_Ok;

	if (level == NULL) {

		return_errorStatus = Dio_NullPointerError;
	}

	else if (port_id > NUM_OF_PORTS)
	{

		return_errorStatus = Dio_portError;
	}

	else
	{

		switch (port_id) {

		case DIO_PORTA:

			*level = PINA;

			break;

		case DIO_PORTB:

			*level = PINB;

			break;

		case DIO_PORTC:

			*level = PINC;

			break;

		case DIO_PORTD:

			*level = PIND;

			break;

		}

	}
	return return_errorStatus;
}
DIO_errorStatus dio_tooglePin(u8 pin_id)
{
	DIO_errorStatus return_errorStatus = Dio_Ok;
	u8 loc_pin;
	u8 loc_port;

	if (pin_id > NUM_OF_PINS)
	{

		return_errorStatus = Dio_pinError;
	}

	else
	{
		loc_pin = pin_id % NUM_OF_PINS_PER_PORT;
		loc_port = pin_id / NUM_OF_PINS_PER_PORT;

		switch (loc_port)
		{

		case DIO_PORTA:

			if (GET_BIT(DDRA,loc_pin) == PORT_OUTPUT)
			{
				TOGGLE_BIT(PORTA, loc_pin);
			}
			break;

		case DIO_PORTB:

			if (GET_BIT(DDRB,loc_pin) == PORT_OUTPUT)
			{
				TOGGLE_BIT(PORTB, loc_pin);
			}
			break;

		case DIO_PORTC:

			if (GET_BIT(DDRC,loc_pin) == PORT_OUTPUT)
			{
				TOGGLE_BIT(PORTC, loc_pin);
			}
			break;

		case DIO_PORTD:

			if (GET_BIT(DDRD,loc_pin) == PORT_OUTPUT)
			{
				TOGGLE_BIT(PORTD, loc_pin);
			}
			break;

		}

	}
	return return_errorStatus;
}
