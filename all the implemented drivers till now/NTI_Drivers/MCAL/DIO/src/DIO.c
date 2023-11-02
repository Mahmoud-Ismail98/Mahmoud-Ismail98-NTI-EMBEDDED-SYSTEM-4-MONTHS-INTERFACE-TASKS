/*
 * DIO.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Ismail
 */

#include"../../../Services/Bit_utils.h"
#include"../../../Services/Std_types.h"
#include "../../PORT/includes/PORT.h"
#include"../includes/DIO.h"
#include"../includes/DIO_prv.h"
#include"../includes/DIO_cfg.h" //THIS FILE IS INCLUDED INCASE THE DRIVER IS CONFIGURABLE IN THE FUTURE.

/*Channel is the pin */

Dio_EnumErrorState  Dio_enuWriteChannel(u8 Copy_u8ChannelId , u8 Copy_u8Level){
	Dio_EnumErrorState LOCEnumReturnState = Dio_Ok;
	u8 LOC_u8Port;
	u8 LOC_u8Pin;
	if (Copy_u8ChannelId > DIO_u8MAXNUMBER_OF_PINS){
		LOCEnumReturnState =Dio_ChannelError;
	}
	else if(Copy_u8Level>DIO_u8MAXNUMBER_OF_LEVELS){
		LOCEnumReturnState= Dio_LevelError;
	}
	else{
		LOC_u8Port = Copy_u8ChannelId / DIO_u8REGISTER_SIZE;
		LOC_u8Pin = Copy_u8ChannelId % DIO_u8REGISTER_SIZE;


	switch (LOC_u8Port) {

			case DIO_u8PORTA:
				if (GET_BIT(DDRA,LOC_u8Pin) == DIO_u8OUTPUT) {
					switch (Copy_u8Level) {

					case DIO_u8LEVEL_HIGH:
						SET_BIT(PORTA, LOC_u8Pin);
						break;

					case DIO_u8LEVEL_LOW:
						CLR_BIT(PORTA, LOC_u8Pin);
						break;

					}
				} else {
					LOCEnumReturnState = Dio_DirectionError;
				}
				break;
			case DIO_u8PORTB:
							if (GET_BIT(DDRB,LOC_u8Pin) == DIO_u8OUTPUT) {
								switch (Copy_u8Level) {

								case DIO_u8LEVEL_HIGH:
									SET_BIT(PORTB, LOC_u8Pin);
									break;

								case DIO_u8LEVEL_LOW:
									CLR_BIT(PORTB, LOC_u8Pin);
									break;

								}
							} else {
								LOCEnumReturnState = Dio_DirectionError;
							}
							break;

			case DIO_u8PORTC:
							if (GET_BIT(DDRC,LOC_u8Pin) == DIO_u8OUTPUT) {
								switch (Copy_u8Level) {

								case DIO_u8LEVEL_HIGH:
									SET_BIT(PORTC, LOC_u8Pin);
									break;

								case DIO_u8LEVEL_LOW:
									CLR_BIT(PORTC, LOC_u8Pin);
									break;

								}
							} else {
								LOCEnumReturnState = Dio_DirectionError;
							}
							break;
			case DIO_u8PORTD:
							if (GET_BIT(DDRD,LOC_u8Pin) == DIO_u8OUTPUT) {
								switch (Copy_u8Level) {

								case DIO_u8LEVEL_HIGH:
									SET_BIT(PORTD, LOC_u8Pin);
									break;

								case DIO_u8LEVEL_LOW:
									CLR_BIT(PORTD, LOC_u8Pin);
									break;

								}
							} else {
								LOCEnumReturnState = Dio_DirectionError;
							}
							break;
	}
	}
return LOCEnumReturnState;
}
Dio_EnumErrorState  Dio_enuReadChannel(u8 Copy_u8ChannelId , pu8 Add_pu8ChannelLevel){

	Dio_EnumErrorState LOCEnumReturnState = Dio_Ok;
		u8 LOC_u8Pin;
		u8 LOC_u8Port;
	if (Add_pu8ChannelLevel== NULL){
		LOCEnumReturnState =Dio_NullPointerError;
	}
	else if (Copy_u8ChannelId > DIO_u8MAXNUMBER_OF_PINS){
		LOCEnumReturnState =Dio_ChannelError;
	}
	else{

		LOC_u8Port = Copy_u8ChannelId / DIO_u8REGISTER_SIZE;
		LOC_u8Pin = Copy_u8ChannelId % DIO_u8REGISTER_SIZE;

		switch (LOC_u8Port){
		case DIO_u8PORTA :
			if (GET_BIT(DDRA,LOC_u8Pin) == DIO_u8INPUT) {

					*Add_pu8ChannelLevel = GET_BIT(PINA, LOC_u8Pin);
				}
			else {
							LOCEnumReturnState = Dio_DirectionError;
						}
						break;
		case DIO_u8PORTB :
					if (GET_BIT(DDRB,LOC_u8Pin) == DIO_u8INPUT) {

							*Add_pu8ChannelLevel = GET_BIT(PINB, LOC_u8Pin);
						}
					else {
									LOCEnumReturnState = Dio_DirectionError;
								}
								break;
		case DIO_u8PORTC :
					if (GET_BIT(DDRC,LOC_u8Pin) == DIO_u8INPUT) {

							*Add_pu8ChannelLevel = GET_BIT(PINC, LOC_u8Pin);
						}
					else {
									LOCEnumReturnState = Dio_DirectionError;
								}
								break;

		case DIO_u8PORTD :
					if (GET_BIT(DDRD,LOC_u8Pin) == DIO_u8INPUT) {

							*Add_pu8ChannelLevel = GET_BIT(PIND, LOC_u8Pin);
						}
					else {
									LOCEnumReturnState = Dio_DirectionError;
								}
								break;


		}
	}

return LOCEnumReturnState;
}
Dio_EnumErrorState  Dio_enuWritePort(u8 Copy_u8PortId , u8 Copy_u8Value){
	Dio_EnumErrorState LOCEnumReturnState = Dio_Ok;
	if (Copy_u8PortId > DIO_u8MAXNUMBER_OF_PORTS ){
		LOCEnumReturnState = Dio_PortRangeError;
	}
	else {
		switch (Copy_u8PortId){
			case DIO_u8PORTA:
							ASSIGN_REG(PORTA, Copy_u8Value);
							break;
			case DIO_u8PORTB:
							ASSIGN_REG(PORTB, Copy_u8Value);
							break;
			case DIO_u8PORTC:
							ASSIGN_REG(PORTC, Copy_u8Value);
							break;
			case DIO_u8PORTD:
						ASSIGN_REG(PORTD, Copy_u8Value);
						break;


	}

}
	return LOCEnumReturnState;
}
Dio_EnumErrorState  Dio_enuReadPort(u8 Copy_u8PortId , pu8 Add_pu8PortValue){
	Dio_EnumErrorState LOCEnumReturnState = Dio_Ok;
		if (Copy_u8PortId > DIO_u8MAXNUMBER_OF_PORTS ){
			LOCEnumReturnState = Dio_PortRangeError;
		}
		if(Add_pu8PortValue == NULL){
			LOCEnumReturnState = Dio_NullPointerError;
		}
		else {
			switch (Copy_u8PortId){
				case DIO_u8PORTA:
					*Add_pu8PortValue = PINA;
								break;
				case DIO_u8PORTB:
					*Add_pu8PortValue = PINB;
								break;
				case DIO_u8PORTC:
					*Add_pu8PortValue = PINC;
								break;
				case DIO_u8PORTD:
					*Add_pu8PortValue = PIND;
							break;


		}

	}
		return LOCEnumReturnState;
}
Dio_EnumErrorState  Dio_enuFlipChannel(u8 Copy_u8ChannelId ){

	Dio_EnumErrorState LOCEnumReturnState = Dio_Ok;
		u8 LOC_u8Pin;
		u8 LOC_u8Port;
 if (Copy_u8ChannelId > DIO_u8MAXNUMBER_OF_PINS){
			LOCEnumReturnState =Dio_ChannelError;
		}
		else{
			LOC_u8Port = Copy_u8ChannelId / DIO_u8REGISTER_SIZE;
			LOC_u8Pin = Copy_u8ChannelId % DIO_u8REGISTER_SIZE;
			switch (LOC_u8Port) {

					case DIO_u8PORTA:
						if (GET_BIT(DDRA,LOC_u8Pin) == DIO_u8OUTPUT) {
							TGL_BIT(PORTA,LOC_u8Pin);

						}
						break;

					case DIO_u8PORTB:
						if (GET_BIT(DDRB,LOC_u8Pin) == DIO_u8OUTPUT) {
							TGL_BIT(PORTB,LOC_u8Pin);

						}
						break;

					case DIO_u8PORTC:

						if (GET_BIT(DDRC,LOC_u8Pin) == DIO_u8OUTPUT) {
							TGL_BIT(PORTC,LOC_u8Pin);

						}
						break;

					case DIO_u8PORTD:

						if (GET_BIT(DDRD,LOC_u8Pin) == DIO_u8OUTPUT) {
							TGL_BIT(PORTD,LOC_u8Pin);
						}
						break;
			}

		}
	return LOCEnumReturnState;
}
Dio_EnumErrorState  DIO_SetNibbleValue(u8 Copy_u8PinStart,u8 Copy_u8PortNumber,u8 Copy_u8Value){
	Dio_EnumErrorState LOCEnumReturnState = Dio_Ok;
	u8 Loc_u8Value =Copy_u8Value;
		 Loc_u8Value=((Loc_u8Value&(0x0F))<<Copy_u8PinStart);
		if((Copy_u8PinStart<=4)&&(Copy_u8PinStart>=0)){
		switch (Copy_u8PortNumber){
		case DIO_u8PORTA :
			//mask port A
			PORTA&=(~((0x0F)<<Copy_u8PinStart));
			PORTA|=Loc_u8Value;
			break;
			case DIO_u8PORTB:
				PORTB&=(~(0X0F<<Copy_u8PinStart));
				PORTB|=Loc_u8Value;
			break;
			case DIO_u8PORTC:
				PORTC&=(~(0X0F<<Copy_u8PinStart));
				PORTC|=Loc_u8Value;
			break;
			case DIO_u8PORTD:
				PORTD&=(~(0X0F<<Copy_u8PinStart));
				PORTD|=Loc_u8Value;
			break;
			default:{
				LOCEnumReturnState= Dio_PortRangeError;
			break;	/*WRONG PORT PASSED*/
			}


		}
		}
		else{
			/*wrong PINStartNumber*/
			LOCEnumReturnState= Dio_ChannelError;
		}


return LOCEnumReturnState;
}
