/*
 * UART.h
 */


#ifndef UART_H_
#define UART_H_

/*

*/
void UART_voidInit();

void UART_voidTransmit(u8 Copy_u8Data);

void UART_voidRecieve(u8* Copy_u8Data);

void UART_voidTransmitInterruptEnable();
void UART_voidTransmitInterruptDisable();

void UART_voidRecieveInterruptEnable();
void UART_voidRecieveInterruptDisable();
 

void UART_SetCallBackRX ( void (*Fptr_RX) (void) );

void UART_SetCallBackTX ( void (*Fptr_TX) (void) );
 

#endif /* UART_H_ */