/*
 * PORT.c
 *
 * Created: 10/20/2023 11:58:19 AM
 *  Author: Mahmoud Tariq
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_CFG.h"
#include "PORT_PRIVATE.h"
#include "PORT.h"




void PORT_vInit(){
	
	#undef  INPUT_FLOATING 
	#undef  INPUT_PULL_UP 
	#undef  OUTPUT_HIGH 
	#undef  OUTPUT_LOW 
	
	#define INPUT_FLOATING 0
	#define INPUT_PULL_UP 0
	#define OUTPUT_HIGH 1
	#define OUTPUT_LOW 1
	
	DDRA = CONC(PORT_PINMODE07,PORT_PINMODE06,PORT_PINMODE05,PORT_PINMODE04,PORT_PINMODE03,PORT_PINMODE02,PORT_PINMODE01,PORT_PINMODE00); 	
	DDRB = CONC(PORT_PINMODE15,PORT_PINMODE14,PORT_PINMODE13,PORT_PINMODE12,PORT_PINMODE11,PORT_PINMODE10,PORT_PINMODE09,PORT_PINMODE08);
	DDRC = CONC(PORT_PINMODE23,PORT_PINMODE22,PORT_PINMODE21,PORT_PINMODE20,PORT_PINMODE19,PORT_PINMODE18,PORT_PINMODE17,PORT_PINMODE16);
	DDRD = CONC(PORT_PINMODE31,PORT_PINMODE30,PORT_PINMODE29,PORT_PINMODE28,PORT_PINMODE27,PORT_PINMODE26,PORT_PINMODE25,PORT_PINMODE24);
	
	#undef  INPUT_FLOATING
	#undef  INPUT_PULL_UP
	#undef  OUTPUT_HIGH
	#undef  OUTPUT_LOW
	
	#define INPUT_FLOATING 0
	#define INPUT_PULL_UP 1
	#define OUTPUT_HIGH 1
	#define OUTPUT_LOW 0
	
	PORTA = CONC(PORT_PINMODE07,PORT_PINMODE06,PORT_PINMODE05,PORT_PINMODE04,PORT_PINMODE03,PORT_PINMODE02,PORT_PINMODE01,PORT_PINMODE00);
	PORTB = CONC(PORT_PINMODE15,PORT_PINMODE14,PORT_PINMODE13,PORT_PINMODE12,PORT_PINMODE11,PORT_PINMODE10,PORT_PINMODE09,PORT_PINMODE08);
	PORTC = CONC(PORT_PINMODE23,PORT_PINMODE22,PORT_PINMODE21,PORT_PINMODE20,PORT_PINMODE19,PORT_PINMODE18,PORT_PINMODE17,PORT_PINMODE16);
	PORTD = CONC(PORT_PINMODE31,PORT_PINMODE30,PORT_PINMODE29,PORT_PINMODE28,PORT_PINMODE27,PORT_PINMODE26,PORT_PINMODE25,PORT_PINMODE24);
	
	#define INPUT_FLOATING 0
	#define INPUT_PULL_UP 1
	#define OUTPUT_HIGH 2
	#define OUTPUT_LOW 3
	
}



PORT_enuErrorStatus PORT_enuSetPinMode(u8 copy_PinNm,u8 copy_PinMode){	
	PORT_enuErrorStatus Return_val = PORT_Status_Fail; //initializing Return Status
	
	u8 PortNum = copy_PinNm /8;   // Get Port Number
	u8 PinNum = copy_PinNm  % 8; // Get Pin Number
	
	if     (PortNum>3)     Return_val = PORT_NO_ERR;
	else if(PinNum>31)     Return_val = PORT_Pin_NO_ERR;
	
	if(copy_PinMode != 0 && copy_PinMode != 1 && copy_PinMode != 2  && copy_PinMode != 3 ) Return_val = PORT_Logic_Level_ERR;
	
	
switch(PortNum){
	
	case 0 :
	if		(1 == copy_PinMode) {SET_BIT(PORTA,PinNum);CLR_BIT(DDRA,PinNum); Return_val = PORT_Status_Ok;   }      //Setting Required Pin & Updating Status
	else if (0 == copy_PinMode) {CLR_BIT(PORTA,PinNum);CLR_BIT(DDRA,PinNum); Return_val = PORT_Status_Ok;   }      //Clearing Required Pin & Updating Status
	else if (2 == copy_PinMode) {SET_BIT(PORTA,PinNum);SET_BIT(DDRA,PinNum); Return_val = PORT_Status_Ok;   }      //Setting Required Pin & Updating Status
	else if (3 == copy_PinMode) {CLR_BIT(PORTA,PinNum);SET_BIT(DDRA,PinNum); Return_val = PORT_Status_Ok;   }      //Clearing Required Pin & Updating Status
	break;
	case 1 :
	if		(1 == copy_PinMode) {SET_BIT(PORTB,PinNum);CLR_BIT(DDRB,PinNum); Return_val = PORT_Status_Ok;   }      //Setting Required Pin & Updating Status
	else if (0 == copy_PinMode) {CLR_BIT(PORTB,PinNum);CLR_BIT(DDRB,PinNum); Return_val = PORT_Status_Ok;   }      //Clearing Required Pin & Updating Status
	else if (2 == copy_PinMode) {SET_BIT(PORTB,PinNum);SET_BIT(DDRB,PinNum); Return_val = PORT_Status_Ok;   }      //Setting Required Pin & Updating Status
	else if (3 == copy_PinMode) {CLR_BIT(PORTB,PinNum);SET_BIT(DDRB,PinNum); Return_val = PORT_Status_Ok;   }      //Clearing Required Pin & Updating Status
	break;
	case 2 :
	if		(1 == copy_PinMode) {SET_BIT(PORTC,PinNum);CLR_BIT(DDRC,PinNum); Return_val = PORT_Status_Ok;   }      //Setting Required Pin & Updating Status
	else if (0 == copy_PinMode) {CLR_BIT(PORTC,PinNum);CLR_BIT(DDRC,PinNum); Return_val = PORT_Status_Ok;   }      //Clearing Required Pin & Updating Status
	else if (2 == copy_PinMode) {SET_BIT(PORTC,PinNum);SET_BIT(DDRC,PinNum); Return_val = PORT_Status_Ok;   }      //Setting Required Pin & Updating Status
	else if (3 == copy_PinMode) {CLR_BIT(PORTC,PinNum);SET_BIT(DDRC,PinNum); Return_val = PORT_Status_Ok;   }      //Clearing Required Pin & Updating Status
	break;
	case 3 :
	if		(1 == copy_PinMode) {SET_BIT(PORTD,PinNum);CLR_BIT(DDRD,PinNum); Return_val = PORT_Status_Ok;   }      //Setting Required Pin & Updating Status
	else if (0 == copy_PinMode) {CLR_BIT(PORTD,PinNum);CLR_BIT(DDRD,PinNum); Return_val = PORT_Status_Ok;   }      //Clearing Required Pin & Updating Status
	else if (2 == copy_PinMode) {SET_BIT(PORTD,PinNum);SET_BIT(DDRD,PinNum); Return_val = PORT_Status_Ok;   }      //Setting Required Pin & Updating Status
	else if (3 == copy_PinMode) {CLR_BIT(PORTD,PinNum);SET_BIT(DDRD,PinNum); Return_val = PORT_Status_Ok;   }      //Clearing Required Pin & Updating Status
	break;
	default:   //If Port Number is Out Of Range Status will remain as initialized
	break;
	
}
return Return_val;

	
	
}

PORT_enuErrorStatus PORT_enuSetPinDirection(u8 copy_PinNm,u8 copy_PinDirection){
	
	PORT_enuErrorStatus Return_val = PORT_Status_Fail; //initializing Return Status
	
	
	if(copy_PinNm>31) Return_val = PORT_Pin_NO_ERR;
	else if (copy_PinDirection>1) Return_val=PORT_Logic_Level_ERR;
	else{
		u8 PortNum = copy_PinNm /8;   // Get Port Number
		u8 PinNum = copy_PinNm  % 8; // Get Pin Number
		switch(PortNum){
			
			case 0 :
				if		(1 == copy_PinDirection) {SET_BIT(DDRA,PinNum); Return_val = PORT_Status_Ok;  }    //Setting Required Pin & Updating Status
				else if (0 == copy_PinDirection) {CLR_BIT(DDRA,PinNum); Return_val = PORT_Status_Ok;   }    //Clearing Required Pin & Updating Status		                         
			break;
			case 1 :
				if      (1 == copy_PinDirection) {SET_BIT(DDRB,PinNum); Return_val = PORT_Status_Ok;}
				else if (0 == copy_PinDirection) {CLR_BIT(DDRB,PinNum); Return_val = PORT_Status_Ok;}
			break;
			case 2 :
				if      (1 == copy_PinDirection) {SET_BIT(DDRC,PinNum); Return_val = PORT_Status_Ok;}
				else if (0 == copy_PinDirection) {CLR_BIT(DDRC,PinNum); Return_val = PORT_Status_Ok;}
			break;
			case 3 :
				if		(1 == copy_PinDirection) {SET_BIT(DDRD,PinNum); Return_val = PORT_Status_Ok;}
				else if (0 == copy_PinDirection) {CLR_BIT(DDRD,PinNum); Return_val = PORT_Status_Ok;}
			break;
			default:  
			Return_val = PORT_NO_ERR;
			break;
			
		}
				}
		return Return_val;
	
	
}
/*
PORT_enuErrorStatus  PORT_enuSetPinDirection(u8 Copy_u8PinNum , u8 Copy_u8PinDirection) {

	PORT_enuErrorStatus LOC_enuReturnStatus = PORT_Status_Ok;

	
	u8 LOC_u8Port;
	u8 LOC_u8Pin;


		LOC_u8Port = Copy_u8PinNum / 8;
		LOC_u8Pin = Copy_u8PinNum % 8;
		switch (LOC_u8Port) {
			case PORT_PORTA:

			if (Copy_u8PinDirection == PORT_PIN_OUTPUT) {

				
				SET_BIT(DDRA, LOC_u8Pin);

				} else {

		
				CLR_BIT(DDRA, LOC_u8Pin);
			}
			break;

			
			case PORT_PORTB:

			
			if (Copy_u8PinDirection == PORT_PIN_OUTPUT) {

				
				SET_BIT(DDRB, LOC_u8Pin);

				} else {

				
				CLR_BIT(DDRB, LOC_u8Pin);
			}

			break;
			
			case PORT_PORTC:

			
			if (Copy_u8PinDirection == PORT_PIN_OUTPUT) {

				
				SET_BIT(DDRC, LOC_u8Pin);

				} else {

				
				CLR_BIT(DDRC, LOC_u8Pin);

			}

			break;
			
			case PORT_PORTD:

			
			if (Copy_u8PinDirection == PORT_PIN_OUTPUT) {

				
				SET_BIT(DDRD, LOC_u8Pin);

				} else {

				
				CLR_BIT(DDRD, LOC_u8Pin);

			}

			break;
		}
	

	
	return LOC_enuReturnStatus;
}
*/