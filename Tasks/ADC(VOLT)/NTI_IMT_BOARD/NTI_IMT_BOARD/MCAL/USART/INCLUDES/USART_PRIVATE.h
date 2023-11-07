/*
 * USART_PRIVATE.h
 *
 * Created: 10/28/2023 11:13:42 AM
 *  Author: Mahmoud Tariq
 */ 


#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

#define    UDR    ((*(volatile pu8)0x2C))
#define    UCSRA  ((*(volatile pu8)0x2B))
#define    UCSRB  ((*(volatile pu8)0x2A))
#define    UCSRC  ((*(volatile pu8)0x40))
#define    UBRRL  ((*(volatile pu8)0x29))
#define    UBRRH  ((*(volatile pu8)0x40))


#endif /* USART_PRIVATE_H_ */