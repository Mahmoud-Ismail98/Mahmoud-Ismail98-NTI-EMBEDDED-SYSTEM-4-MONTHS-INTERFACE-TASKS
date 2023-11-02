/*
 * UART_prv.h
 *
 *  Created on: Ù¢Ù¨â€�/Ù¡Ù â€�/Ù¢Ù Ù¢Ù£
 *      Author: ascom
 */

#ifndef MCAL_UART_INC_UART_PRV_H_
#define MCAL_UART_INC_UART_PRV_H_

#define UDR *((u8 volatile*) 0x2C)
#define UCSRA *((u8 volatile*) 0x2B)
#define UCSRB *((u8 volatile*) 0x2A)
#define UCSRC *((u8 volatile*) 0x40)
#define UBRRL *((u8 volatile*) 0x29)
#define UBRRH *((u8 volatile*) 0x40)
#define UMSEL	6
#define URSLE	7
#define UCSZ2	2


#define U2X		1

#define TXEN 	3
#define RXEN 	4

#define UDRE 	5
#define RXC		7





#endif /* MCAL_UART_INC_UART_PRV_H_ */
