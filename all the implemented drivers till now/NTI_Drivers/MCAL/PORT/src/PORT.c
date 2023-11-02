/*
 * PORT.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Ismail
 */
#include"../../../Services/Bit_utils.h"
#include"../../../Services/Std_types.h"
#include"../includes/PORT.h"
#include"../includes/PORT_cfg.h"


void Port_Init(void)
{
#undef 	PORT_u8INPUT_FLOATING
#define PORT_u8INPUT_FLOATING	0

#undef 	PORT_u8INPUT_PULLUP
#define PORT_u8INPUT_PULLUP		0

	DDRA = CONC(PORT_u8MODE_PIN7,PORT_u8MODE_PIN6,PORT_u8MODE_PIN5,PORT_u8MODE_PIN4,PORT_u8MODE_PIN3,PORT_u8MODE_PIN2,PORT_u8MODE_PIN1,PORT_u8MODE_PIN0);
	DDRB = CONC(PORT_u8MODE_PIN15,PORT_u8MODE_PIN14,PORT_u8MODE_PIN13,PORT_u8MODE_PIN12,PORT_u8MODE_PIN11,PORT_u8MODE_PIN10,PORT_u8MODE_PIN9,PORT_u8MODE_PIN8);
	DDRC = CONC(PORT_u8MODE_PIN23,PORT_u8MODE_PIN22,PORT_u8MODE_PIN21,PORT_u8MODE_PIN20,PORT_u8MODE_PIN19,PORT_u8MODE_PIN18,PORT_u8MODE_PIN17,PORT_u8MODE_PIN16);
	DDRD = CONC(PORT_u8MODE_PIN31,PORT_u8MODE_PIN30,PORT_u8MODE_PIN29,PORT_u8MODE_PIN28,PORT_u8MODE_PIN27,PORT_u8MODE_PIN26,PORT_u8MODE_PIN25,PORT_u8MODE_PIN24);

#undef 	PORT_u8INPUT_FLOATING
#define PORT_u8INPUT_FLOATING	0

#undef 	PORT_u8OUTPUT_LOW
#define PORT_u8OUTPUT_LOW		0

#undef 	PORT_u8INPUT_PULLUP
#define PORT_u8INPUT_PULLUP		1

	PORTA = CONC(PORT_u8MODE_PIN7,PORT_u8MODE_PIN6,PORT_u8MODE_PIN5,PORT_u8MODE_PIN4,PORT_u8MODE_PIN3,PORT_u8MODE_PIN2,PORT_u8MODE_PIN1,PORT_u8MODE_PIN0);
	PORTB = CONC(PORT_u8MODE_PIN15,PORT_u8MODE_PIN14,PORT_u8MODE_PIN13,PORT_u8MODE_PIN12,PORT_u8MODE_PIN11,PORT_u8MODE_PIN10,PORT_u8MODE_PIN9,PORT_u8MODE_PIN8);
	PORTC = CONC(PORT_u8MODE_PIN23,PORT_u8MODE_PIN22,PORT_u8MODE_PIN21,PORT_u8MODE_PIN20,PORT_u8MODE_PIN19,PORT_u8MODE_PIN18,PORT_u8MODE_PIN17,PORT_u8MODE_PIN16);
	PORTD = CONC(PORT_u8MODE_PIN31,PORT_u8MODE_PIN30,PORT_u8MODE_PIN29,PORT_u8MODE_PIN28,PORT_u8MODE_PIN27,PORT_u8MODE_PIN26,PORT_u8MODE_PIN25,PORT_u8MODE_PIN24);
//undefine because the binary values must be ' 0 or '1' then redefine to avoid conflicts
#undef 	PORT_u8INPUT_PULLUP
#undef 	PORT_u8OUTPUT_LOW
#undef 	PORT_u8INPUT_FLOATING
//re-defining again to their initial
#define PORT_u8OUTPUT_LOW 		0
#define PORT_u8INPUT_FLOATING 	2
#define PORT_u8INPUT_PULLUP 	3

}

Port_EnumErrorStatus Port_enuSetPinDirection(u8 Copy_u8PinNum , u8 Copy_u8PinDirection) {

	Port_EnumErrorStatus LOC_EnumReturn = Ok;
	u8 LOC_u8Port;
	u8 LOC_u8Pin;


	if (Copy_u8PinNum>PORT_u8TOTALNUMBER_OF_PINS) {
		LOC_EnumReturn = PinError;
			}

	 else if (Copy_u8PinDirection>PORT_u8NUMBER_OF_DIRECTION) {
		 LOC_EnumReturn = ModeError;
	        }

	 else {
		 //no error so the input is correct so we proceed//
		LOC_u8Port = Copy_u8PinNum / PORT_u8REGISTER_SIZE; //to know which port
		LOC_u8Pin = Copy_u8PinNum % PORT_u8REGISTER_SIZE; //to know which pin
//if Pin direction is not set, it's cleared
		switch (LOC_u8Port) {
		case PORT_u8PORTA:

			if (Copy_u8PinDirection == PORT_u8OUTPUT) {
				SET_BIT(DDRA, LOC_u8Pin);
			} else {
				CLR_BIT(DDRA, LOC_u8Pin);
			}
			break;
		case PORT_u8PORTB:


			if (Copy_u8PinDirection == PORT_u8OUTPUT) {
				SET_BIT(DDRB, LOC_u8Pin);
			} else {
				CLR_BIT(DDRB, LOC_u8Pin);
			}

			break;

		case PORT_u8PORTC:

			if (Copy_u8PinDirection == PORT_u8OUTPUT) {
				SET_BIT(DDRC, LOC_u8Pin);
			} else {
				CLR_BIT(DDRC, LOC_u8Pin);
			}

			break;

		case PORT_u8PORTD:

			if (Copy_u8PinDirection == PORT_u8OUTPUT) {
				SET_BIT(DDRD, LOC_u8Pin);
			} else {
				CLR_BIT(DDRD, LOC_u8Pin);
			}

			break;
		}
	}

	/*RETURN ERROR TYPE*/
	return LOC_EnumReturn;
}


Port_EnumErrorStatus Port_enuSetPinMode(u8 Copy_u8PinNum, u8 Copy_u8PinMode) {

	Port_EnumErrorStatus LOC_EnumReturn = Ok;
	u8 LOC_u8Port;
	u8 LOC_u8Pin;

	if (Copy_u8PinNum > PORT_u8TOTALNUMBER_OF_PINS) {
		LOC_EnumReturn = PinError;

	} else if (Copy_u8PinMode > PORT_u8INPUT_PULLUP) {
		LOC_EnumReturn = ModeError;
	} else {

		LOC_u8Port = Copy_u8PinNum / PORT_u8REGISTER_SIZE; //TO GET PORT EX: (31/8=3, WHICH 3 IS PORTD)
		LOC_u8Pin = Copy_u8PinNum % PORT_u8REGISTER_SIZE; //TO GET WHICH PIN EX: (31%8=7, WHICH 7 IS PIN7)

		switch (LOC_u8Port) {


		case PORT_u8PORTA:
			switch (Copy_u8PinMode) {
			case PORT_u8OUTPUT_LOW:
				SET_BIT(DDRA, LOC_u8Pin);
				CLR_BIT(PORTA, LOC_u8Pin);
				break;

			case PORT_u8OUTPUT_HIGH:
				SET_BIT(DDRA, LOC_u8Pin);
				SET_BIT(PORTA, LOC_u8Pin);
				break;

			case PORT_u8INPUT_FLOATING:
				CLR_BIT(DDRA, LOC_u8Pin);
				CLR_BIT(PORTA, LOC_u8Pin);
				break;

			case PORT_u8INPUT_PULLUP:
				CLR_BIT(DDRA, LOC_u8Pin);
				SET_BIT(PORTA, LOC_u8Pin);
				break;
			}
			break;

		case PORT_u8PORTB:
			switch (Copy_u8PinMode) {
			case PORT_u8OUTPUT_LOW:
				SET_BIT(DDRB, LOC_u8Pin);
				CLR_BIT(PORTB, LOC_u8Pin);
				break;
			case PORT_u8OUTPUT_HIGH:
				SET_BIT(DDRB, LOC_u8Pin);
				SET_BIT(PORTB, LOC_u8Pin);
				break;

			case PORT_u8INPUT_FLOATING:
				CLR_BIT(DDRB, LOC_u8Pin);
				CLR_BIT(PORTB, LOC_u8Pin);
				break;

			case PORT_u8INPUT_PULLUP:
				CLR_BIT(DDRB, LOC_u8Pin);
				SET_BIT(PORTB, LOC_u8Pin);
				break;
			}
			break;

		case PORT_u8PORTC:
			switch (Copy_u8PinMode) {
			case PORT_u8OUTPUT_LOW:
				SET_BIT(DDRC, LOC_u8Pin);
				CLR_BIT(PORTC, LOC_u8Pin);
				break;

			case PORT_u8OUTPUT_HIGH:
				SET_BIT(DDRC, LOC_u8Pin);
				SET_BIT(PORTC, LOC_u8Pin);
				break;

			case PORT_u8INPUT_FLOATING:
				CLR_BIT(DDRC, LOC_u8Pin);
				CLR_BIT(PORTC, LOC_u8Pin);
				break;

			case PORT_u8INPUT_PULLUP:
				CLR_BIT(DDRC, LOC_u8Pin);
				SET_BIT(PORTC, LOC_u8Pin);
				break;

			}

			break;

		case PORT_u8PORTD:

			switch (Copy_u8PinMode) {

			case PORT_u8OUTPUT_LOW:
				SET_BIT(DDRD, LOC_u8Pin);
				CLR_BIT(PORTD, LOC_u8Pin);
				break;

			case PORT_u8OUTPUT_HIGH:
				SET_BIT(DDRD, LOC_u8Pin);
				SET_BIT(PORTD, LOC_u8Pin);
				break;

			case PORT_u8INPUT_FLOATING:
				CLR_BIT(DDRD, LOC_u8Pin);
				CLR_BIT(PORTD, LOC_u8Pin);
				break;

			case PORT_u8INPUT_PULLUP:
				CLR_BIT(DDRD, LOC_u8Pin);
				SET_BIT(PORTD, LOC_u8Pin);
				break;

			}

			break;
		}
	}

	return LOC_EnumReturn;
}
