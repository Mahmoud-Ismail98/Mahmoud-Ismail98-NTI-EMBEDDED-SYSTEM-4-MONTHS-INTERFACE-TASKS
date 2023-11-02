/*
 * UART.h
 *
 * Created: 10/28/2023 1:31:04 PM
 *  Author: 20101
 */ 


#ifndef UART_H_
#define UART_H_


#define U2X                        0
#define NORMAL_TRANSMISSION_SPEED  1

#define Character_5_bit     0
#define Character_6_bit     1
#define Character_7_bit     2
#define Character_8_bit     3
#define Character_9_bit     4


#define ONE_STOP_BIT        0
#define TWO_STOP_BIT        1




#define NO_PARITY          0
#define EVEN_PARITY        1
#define ODD_PARITY         2



#define Asynchronous_Operation    0
#define Synchronous_Operation     1



#define BR_2400		416
#define BR_4800		207
#define BR_9600		103



/***API'S***/
void UART_voidInit(void);
void UART_SenfByte(u8 data);
void UART_SendString(u8 *str);
char UART_RecieveByte(void);
{
	u8 data ; 
	while (GET_BIT(UCSRA , RXC)==0) ; 
	
	data = UDR ;
	 
	 return data;  
}
u8 *UART_RecieveString(void);


















#endif /* UART_H_ */