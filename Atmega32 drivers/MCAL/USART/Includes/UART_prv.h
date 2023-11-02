/*
 * UART_prv.h
 */


#ifndef UART_PRV_H_
#define UART_PRV_H_

#define UART_Asynch		0 //USMEL in UCSRC
#define	UART_Synch		1


#define UART_TRANSMITTER			1		//RXEN and TXEN in UCSRB
#define	UART_RECIEVER				2
#define	UART_TRANSMITTER_RECIEVER	3


#define UART_DOUBLESPEED_ENABLED	1
#define	UART_DOUBLESPEED_DISABLED	0



#define BUAD_2400	416		//UBRR
#define	BUAD_4800	207
#define	BUAD_9600	103
#define	BUAD_14_4k	68
#define	BUAD_19_2k	51
#define	BUAD_28_8k	34
#define	BUAD_38_4k	25
#define	BUAD_57_6k	16
#define	BUAD_76_8k	12
#define	BUAD_115_2k	8
#define	BUAD_230_4k	3
#define	BUAD_250k	3


#define UART_PARITY_DISABLED 0   //UPM0, UPM1 in UCSRC
#define	UART_PARITY_EVEN	 2
#define	UART_PARITY_ODD		 3

#define UART_5_Bit 0   //UCSZ in UCSRC
#define	UART_6_Bit 1
#define	UART_7_Bit 2
#define	UART_8_Bit 3
#define	UART_9_Bit 4


#define UART_1_Bit 0 //USBS in UCSRC
#define UART_2_Bit 1
///////////////////////////////////////////////////////////


#define UDR       (*(volatile u8*)0x2c)
#define UBRRL	  (*(volatile u8*)0x29)
#define UBRRH	  (*(volatile u8*)0x40)
#define UCSRA     (*(volatile u8*)0x2B)

#define UCSRB     (*(volatile u8*)0x2A)
#define TXCIE     6
#define RXCIE     7
#define UCSRC     (*(volatile u8*)0x40)

#define UMSEL	  6
#define URSEL     7
#define U2X       1
#define TXEN      3
#define RXEN      4
#define UDRE      5
#define TXC       6
#define RXC       7
#define DOR       3
#define MPCM      0
#define PE        2
#define FE        4
#define UPM0      4
#define UPM1      5
#define UDRE      5
#define UCSZ2	  2
#define UCSZ1	  2
#define UCSZ0	  1

#endif /* UART_PRV_H_ */