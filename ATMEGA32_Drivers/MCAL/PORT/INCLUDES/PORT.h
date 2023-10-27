/*
 * PORT.h
 *
 * Created: 10/20/2023 11:57:37 AM
 *  Author: Mahmoud Tariq
 */ 


#ifndef PORT_H_
#define PORT_H_

/*PIN MODES*/
#define INPUT_FLOATING 0
#define INPUT_PULL_UP 1
#define OUTPUT_HIGH 2
#define OUTPUT_LOW 3

/*Macros For Setting Direction*/
#define PORT_PIN_OUTPUT 1
#define PORT_PIN_INPUT  0

/*Macros For Setting Logic Level*/
#define PORT_PIN_HIGH   1
#define PORT_PIN_LOW    0

#define CONC(A,B,C,D,E,F,G,H)			CONC_HELPER(A,B,C,D,E,F,G,H)
#define CONC_HELPER(A,B,C,D,E,F,G,H)	0b##A##B##C##D##E##F##G##H 

#define PORT_PORTA 0
#define PORT_PORTB 1
#define PORT_PORTC 2
#define PORT_PORTD 3
/* PORT A Pin Numbers*/
#define PORTA_PIN0  0
#define PORTA_PIN1  1
#define PORTA_PIN2  2
#define PORTA_PIN3  3
#define PORTA_PIN4  4
#define PORTA_PIN5  5
#define PORTA_PIN6  6
#define PORTA_PIN7  7


/* PORT B Pin Numbers*/
#define PORTB_PIN0  8
#define PORTB_PIN1  9
#define PORTB_PIN2  10
#define PORTB_PIN3  11
#define PORTB_PIN4  12
#define PORTB_PIN5  13
#define PORTB_PIN6  14
#define PORTB_PIN7  15

/* PORT C Pin Numbers*/
#define PORTC_PIN0  16
#define PORTC_PIN1  17
#define PORTC_PIN2  18
#define PORTC_PIN3  19
#define PORTC_PIN4  20
#define PORTC_PIN5  21
#define PORTC_PIN6  22
#define PORTC_PIN7  23

/* PORT D Pin Numbers*/
#define PORTD_PIN0  24
#define PORTD_PIN1  25
#define PORTD_PIN2  26
#define PORTD_PIN3  27
#define PORTD_PIN4  28
#define PORTD_PIN5  29
#define PORTD_PIN6  30
#define PORTD_PIN7  31

typedef enum{
	PORT_Status_Ok,
	PORT_Status_Fail,
	PORT_Pin_NO_ERR,
	PORT_NO_ERR,
	PORT_Logic_Level_ERR,
	PORT_Null_ptr_ERR
	
	
	}PORT_enuErrorStatus;
/*Function ProtoTypes*/

void PORT_vInit(void);
PORT_enuErrorStatus PORT_enuSetPinDirection(u8 copy_PinNm,u8 copy_PinDirection);
PORT_enuErrorStatus PORT_enuSetPinMode(u8 copy_PinNm,u8 copy_PinMode);
	
	





#endif /* PORT_H_ */