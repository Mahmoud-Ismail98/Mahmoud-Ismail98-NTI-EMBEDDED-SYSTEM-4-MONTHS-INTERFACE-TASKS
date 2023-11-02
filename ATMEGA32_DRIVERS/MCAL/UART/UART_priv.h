#ifndef UART_PRIV_H
#define UART_PRV_H


#define UCSRA   *((volatile u8*) 0x2B)
/*UCSRA*/
#define U2X						1
#define UDRE					5
#define TXC						6
#define RXC						7

#define UCSRB   *((volatile u8*) 0x2A)
/*UCSRB*/
#define RXCIE					7
#define TXCIE					6
#define UDRIE					5
#define RXEN					4
#define TXEN					3
#define UCSZ2					2
#define RXB8					1
#define TXB8					0

#define UCSRC   *((volatile u8*) 0x40)
/*UCSRC*/
#define URSEL					7
#define UMSEL					6
#define UPM1					5
#define UPM0					4
#define USBS					3
#define UCSZ1					2
#define UCSZ0					1

#define UBRRL   *((volatile u8*) 0x29)
#define UDR     *((volatile u8*) 0x2C)





#endif