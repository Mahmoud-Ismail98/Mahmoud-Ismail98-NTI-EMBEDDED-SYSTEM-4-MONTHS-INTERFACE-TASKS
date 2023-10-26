/*
 * port.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Ahmed Dwidar
 */
#include"port.h"
#include"port_prv.h"
#include"port_config.h"
#include<avr/io.h>
/*initialize based on user configuration*/

void port_init(void)
{
#undef PIN_INPUT_FLOATING
#define PIN_INPUT_FLOATING           0


#undef PIN_INPUT_PULL_UP
#define PIN_INPUT_PULL_UP 	         1

#undef PIN_OUTPUT_LOW
#define PIN_OUTPUT_LOW               0

#undef PIN_OUTPUT_HIGH
#define PIN_OUTPUT_HIGH              1

	DDRA = CONC(DIO_u8_PIN0,DIO_u8_PIN1,DIO_u8_PIN2,DIO_u8_PIN3,DIO_u8_PIN4,DIO_u8_PIN5,DIO_u8_PIN6,DIO_u8_PIN7);
	DDRB = CONC(DIO_u8_PIN8,DIO_u8_PIN9,DIO_u8_PIN10,DIO_u8_PIN11,DIO_u8_PIN12,DIO_u8_PIN13,DIO_u8_PIN14,DIO_u8_PIN15);
	DDRC = CONC(DIO_u8_PIN16,DIO_u8_PIN17,DIO_u8_PIN18,DIO_u8_PIN19,DIO_u8_PIN20,DIO_u8_PIN21,DIO_u8_PIN22,DIO_u8_PIN23);
	DDRD = CONC(DIO_u8_PIN24,DIO_u8_PIN25,DIO_u8_PIN26,DIO_u8_PIN27,DIO_u8_PIN28,DIO_u8_PIN29,DIO_u8_PIN30,DIO_u8_PIN31);

#undef PIN_OUTPUT_LOW
#define PIN_OUTPUT_LOW               0

#undef PIN_OUTPUT_HIGH
#define PIN_OUTPUT_HIGH              1

	PORTA = CONC(DIO_u8_PIN0,DIO_u8_PIN1,DIO_u8_PIN2,DIO_u8_PIN3,DIO_u8_PIN4,DIO_u8_PIN5,DIO_u8_PIN6,DIO_u8_PIN7);
	PORTB = CONC(DIO_u8_PIN8,DIO_u8_PIN9,DIO_u8_PIN10,DIO_u8_PIN11,DIO_u8_PIN12,DIO_u8_PIN13,DIO_u8_PIN14,DIO_u8_PIN15);
	PORTC = CONC(DIO_u8_PIN16,DIO_u8_PIN17,DIO_u8_PIN18,DIO_u8_PIN19,DIO_u8_PIN20,DIO_u8_PIN21,DIO_u8_PIN22,DIO_u8_PIN23);
	PORTD = CONC(DIO_u8_PIN24,DIO_u8_PIN25,DIO_u8_PIN26,DIO_u8_PIN27,DIO_u8_PIN28,DIO_u8_PIN29,DIO_u8_PIN30,DIO_u8_PIN31);

#undef PIN_INPUT_FLOATING
#undef PIN_INPUT_PULL_UP
#undef PIN_OUTPUT_HIGH

#define PIN_OUTPUT_HIGH             2
#define PIN_INPUT_PULL_UP           3
#define PIN_INPUT_FLOATING          4

}

/*set pin direction*/
port_errorStatus setPinDirection(u8 pin_id, u8 direction)
{
	port_errorStatus return_errorStatus = port_OK;
	u8 loc_pn;
	u8 loc_port;

	if(pin_id > NUM_OF_PINS)
	{
		return_errorStatus = pinError;
	}
	else if(direction > NUM_OF_DIRECTION)
	{
		return_errorStatus = pinDirectionError;
	}
	else
	{
		loc_pn = pin_id % NUM_OF_PINS_PER_PORT;
		loc_port = pin_id / NUM_OF_PINS_PER_PORT;

		switch(loc_port)
		{
		case PORT_PORTA:
			if (direction == PIN_OUTPUT_HIGH)
			{
				SET_BIT(DDRA, loc_pn);
			}
			else
			{
				CLEAR_BIT(DDRA, loc_pn);
			}
			break;

		case PORT_PORTB:
			if (direction == PIN_OUTPUT_HIGH)
			{
				SET_BIT(DDRB, loc_pn);
			}
			else
			{
				CLEAR_BIT(DDRB, loc_pn);
			}
			break;
		case PORT_PORTC:
			if (direction == PIN_OUTPUT_HIGH)
			{
				SET_BIT(DDRC, loc_pn);
			}
			else
			{
				CLEAR_BIT(DDRC, loc_pn);
			}
			break;
		case PORT_PORTD:
			if (direction == PIN_OUTPUT_HIGH)
			{
				SET_BIT(DDRD, loc_pn);
			}
			else
			{
				CLEAR_BIT(DDRD, loc_pn);
			}
			break;
		}
	}

		return return_errorStatus;


}
/*
*choose between four modes
*change the state of pin in specific time
* */
port_errorStatus setMode(u8 pin_id, u8 mode)
{
	port_errorStatus return_errorStatus = port_OK;
	u8 loc_port;

	u8 loc_pin;

	if(pin_id > NUM_OF_PINS)
	{
		return_errorStatus = pinError;
	}
	else if(mode > NUM_OF_MODES)
	{
		return_errorStatus = pinDirectionError;
	}
	else
	{
		loc_pin = pin_id % NUM_OF_PINS_PER_PORT;
		loc_port = pin_id / NUM_OF_PINS_PER_PORT;

		switch(loc_port)
		{

		case PORT_PORTA:

			switch (mode)
			{

			case PIN_OUTPUT_LOW:

				SET_BIT(DDRA, loc_pin);

				CLEAR_BIT(PORTA, loc_pin);

				break;

			case PIN_OUTPUT_HIGH:

				SET_BIT(DDRA, loc_pin);

				SET_BIT(PORTA, loc_pin);

				break;

			case PIN_INPUT_FLOATING:

				CLEAR_BIT(DDRA, loc_pin);

				CLEAR_BIT(PORTA, loc_pin);

				break;

			case PIN_INPUT_PULL_UP:

				CLEAR_BIT(DDRA, loc_pin);

				SET_BIT(PORTA, loc_pin);

				break;
			}
			break;

		case PORT_PORTB:

			switch (mode)
			{

			case PIN_OUTPUT_LOW:

				SET_BIT(DDRB, loc_pin);

				CLEAR_BIT(PORTB, loc_pin);

				break;

			case PIN_OUTPUT_HIGH:

				SET_BIT(DDRB, loc_pin);

				SET_BIT(PORTB, loc_pin);

				break;

			case PIN_INPUT_FLOATING:

				CLEAR_BIT(DDRB, loc_pin);

				CLEAR_BIT(PORTB, loc_pin);

				break;

			case PIN_INPUT_PULL_UP:

				CLEAR_BIT(DDRB, loc_pin);

				SET_BIT(PORTB, loc_pin);

				break;
			}
			break;


		case PORT_PORTC:

			switch (mode)
			{

			case PIN_OUTPUT_LOW:

				SET_BIT(DDRC, loc_pin);

				CLEAR_BIT(PORTC, loc_pin);

				break;

			case PIN_OUTPUT_HIGH:

				SET_BIT(DDRC, loc_pin);

				SET_BIT(PORTC, loc_pin);

				break;

			case PIN_INPUT_FLOATING:

				CLEAR_BIT(DDRC, loc_pin);

				CLEAR_BIT(PORTC, loc_pin);

				break;

			case PIN_INPUT_PULL_UP:

				CLEAR_BIT(DDRC, loc_pin);

				SET_BIT(PORTC, loc_pin);

				break;
			}
			break;



		case PORT_PORTD:

			switch (mode)
			{

			case PIN_OUTPUT_LOW:

				SET_BIT(DDRD, loc_pin);

				CLEAR_BIT(PORTD, loc_pin);

				break;

			case PIN_OUTPUT_HIGH:

				SET_BIT(DDRD, loc_pin);

				SET_BIT(PORTD, loc_pin);

				break;

			case PIN_INPUT_FLOATING:

				CLEAR_BIT(DDRD, loc_pin);

				CLEAR_BIT(PORTD, loc_pin);

				break;

			case PIN_INPUT_PULL_UP:

				CLEAR_BIT(DDRD, loc_pin);

				SET_BIT(PORTD, loc_pin);

				break;
			break;
			}


		}
	}

	return return_errorStatus;
}



