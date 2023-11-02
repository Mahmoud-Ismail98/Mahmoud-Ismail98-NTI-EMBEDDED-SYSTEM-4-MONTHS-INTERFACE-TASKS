/*
 * USART_prv.h
 *
 *  Created on: Oct 28, 2023
 *      Author: Ismail
 */

#ifndef MCAL_USART_USART_PRV_H_
#define MCAL_USART_USART_PRV_H_

#define USART_SYNCHRONOUS_MODE  1
#define USART_ASYNCHRONOUS_MODE 0

#define USART_PARITY_DISABLED 0
#define USART_PARITY_ODD      1
#define USART_PARITY_EVEN     2

#define USART_ONE_STOP_BIT 0
#define USART_TWO_STOP_BIT 1

#define USART_FIVE_DATA_BITS         0
#define USART_SIX_DATA_BITS          1
#define USART_SEVEN_DATA_BITS        2
#define USART_EIGHT_DATA_BITS        3
#define USART_NINE_DATA_BITS         4

//baud rates

#define USART_2400                   416
#define USART_4800                   208
#define USART_9600                   104
#define USART_19200                  52
#define USART_38400                  26



#define UDR              *((volatile u8*)0x2C)
#define UCSRA            *((volatile u8*)0x2B)
#define UCSRB            *((volatile u8*)0x2A)
#define UCSRC            *((volatile u8*)0x40)
#define UBRRL            *((volatile u8*)0x29)
#define UBRRH            *((volatile u8*)0x40)

#endif /* MCAL_USART_USART_PRV_H_ */
