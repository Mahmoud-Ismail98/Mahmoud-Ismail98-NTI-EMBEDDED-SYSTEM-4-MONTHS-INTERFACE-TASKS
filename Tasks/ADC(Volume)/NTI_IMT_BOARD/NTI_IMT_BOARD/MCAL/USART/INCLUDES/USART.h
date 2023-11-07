/*
 * USART.h
 *
 * Created: 10/28/2023 11:13:15 AM
 *  Author: Mahmoud Tariq
 */ 


#ifndef USART_H_
#define USART_H_


typedef enum
{
	USART_OK,
	USART_NOK,
	USART_LEVEL_ERROR,
	USART_OUT_OF_RANGE,
	USART_NULL_POINTER
}UART_enuErrorStatus;


void USART_vidInit(void);
u8 USART_u8Recieve(void);
void USART_TX (u8 data);
UART_enuErrorStatus UART_enuTxChar(u8 Copy_u8Char);
u8 UART_enuRxChar(void);
void UART_vidRxString(u8 AddString[]);
void UART_vidTxString(u8* StringPtr);
void USART_ReceiveStringNEW(pu8 buffer, u8 buffer_size);
#endif /* USART_H_ */