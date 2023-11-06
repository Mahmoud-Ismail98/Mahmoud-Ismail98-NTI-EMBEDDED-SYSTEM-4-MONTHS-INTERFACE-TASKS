
#ifndef _DIO_INT_H_
#define _DIO_INT_H_

/*Available controller Ports */
typedef enum {
	
	Port_A,
	Port_B,
	Port_C,
	Port_D
}et_Port;


/*Available controller Pins */
typedef enum {
	
	Pin_0,
	Pin_1,
	Pin_2,
	Pin_3,
	Pin_4,
	Pin_5,
	Pin_6,
	Pin_7
}et_PIN;


/*Available controller pin direction*/
typedef enum {
	
	Pin_Input,
	Pin_Output,
}et_Direcion;

/*Available controller pin value*/
typedef enum {
	
	Pin_Low,
	Pin_High,
	
}et_Vlaue;



void MDIO_VidSetPinDirection(u8 Copy_u8Port,
							  u8 Copy_u8Pin ,
							  u8 Copy_u8Direction);
							   
							   
void MDIO_VidSetPinValue(u8 Copy_u8Port,
						 u8 Copy_u8Pin ,
						 u8 Copy_u8Value);
							   
							   
void MDIO_VidGetPinValue(u8 Copy_u8Port,
						 u8 Copy_u8Pin ,
						 u8 *pu8Value);

/******************************************************/
/* DIO Port control */

void MDIO_VidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction);


void MDIO_VidSetPortValue(u8 Copy_u8Port,
						  u8 Copy_u8Value);


void MDIO_VidGetPortValue(u8 Copy_u8Port,
						  u8 *pu8Value);


#endif
