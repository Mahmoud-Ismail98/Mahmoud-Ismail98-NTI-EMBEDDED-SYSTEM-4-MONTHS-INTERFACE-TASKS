
#include"../../4-SERVICS/Std_types.h"
#include"../../4-SERVICS/Bit_utils.h"
#include"DIO_Private.h"
#include"DIO_Int.h"



/*Main used Method*/
void MDIO_VidSetPinDirection(u8 Copy_u8Port,
							 u8 Copy_u8Pin ,
							 u8 Copy_u8Direction){

if (Copy_u8Direction == Pin_Input){
   switch (Copy_u8Port) {
	   case Port_A : CLR_BIT(DDRA,Copy_u8Pin);break;
	   case Port_B : CLR_BIT(DDRB,Copy_u8Pin);break;
	   case Port_C : CLR_BIT(DDRC,Copy_u8Pin);break;
	   case Port_D : CLR_BIT(DDRD,Copy_u8Pin);break;
   }
	
}
else if (Copy_u8Direction == Pin_Output) {
	
	switch (Copy_u8Port) {
	   case Port_A : SET_BIT(DDRA,Copy_u8Pin);break;
	   case Port_B : SET_BIT(DDRB,Copy_u8Pin);break;
	   case Port_C : SET_BIT(DDRC,Copy_u8Pin);break;
	   case Port_D : SET_BIT(DDRD,Copy_u8Pin);break;
   }
	
}

}
							   
							   
void MDIO_VidSetPinValue(u8 Copy_u8Port,
						 u8 Copy_u8Pin ,
						 u8 Copy_u8Value){

if (Copy_u8Value == Pin_Low){
   switch (Copy_u8Port) {
	   case Port_A : CLR_BIT(PORTA,Copy_u8Pin);break;
	   case Port_B : CLR_BIT(PORTB,Copy_u8Pin);break;
	   case Port_C : CLR_BIT(PORTC,Copy_u8Pin);break;
	   case Port_D : CLR_BIT(PORTD,Copy_u8Pin);break;
   }
	
   }
else if (Copy_u8Value == Pin_High) {
	
	switch (Copy_u8Port) {
	   case Port_A : SET_BIT(PORTA,Copy_u8Pin);break;
	   case Port_B : SET_BIT(PORTB,Copy_u8Pin);break;
	   case Port_C : SET_BIT(PORTC,Copy_u8Pin);break;
	   case Port_D : SET_BIT(PORTD,Copy_u8Pin);break;
   }
	
}

}

							   
void MDIO_VidGetPinValue(u8 Copy_u8Port,
						 u8 Copy_u8Pin ,
						 u8 *pu8Value){
	switch (Copy_u8Port) {
		case Port_A : *pu8Value = GET_BIT(PINA,Copy_u8Pin);break;
		case Port_B : *pu8Value = GET_BIT(PINB,Copy_u8Pin);break;
		case Port_C : *pu8Value = GET_BIT(PINC,Copy_u8Pin);break;
		case Port_D : *pu8Value = GET_BIT(PIND,Copy_u8Pin);break;		
		
	}

}

/*********************************************/
/* Methods on Port */


void MDIO_VidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction){

	switch (Copy_u8Port){

	case Port_A : DDRA = Copy_u8Direction ; break;
	case Port_B : DDRB = Copy_u8Direction ; break;
	case Port_C : DDRC = Copy_u8Direction ; break;
	case Port_D : DDRD = Copy_u8Direction ; break;

	}
}


void MDIO_VidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value){

	switch (Copy_u8Port){

	case Port_A : PORTA = Copy_u8Value ; break;
	case Port_B : PORTB = Copy_u8Value ; break;
	case Port_C : PORTC = Copy_u8Value ; break;
	case Port_D : PORTD = Copy_u8Value ; break;

	}
}


void MDIO_VidGetPortValue(u8 Copy_u8Port,u8 *pu8Value){

	switch (Copy_u8Port){

	case Port_A : *pu8Value = PINA ; break;
	case Port_B : *pu8Value = PINB ; break;
	case Port_C : *pu8Value = PINC ; break;
	case Port_D : *pu8Value = PIND ; break;

	}
}
