/*
 * USART_CFG.h
 *
 * Created: 10/28/2023 11:13:28 AM
 *  Author: Mahmoud Tariq
 */ 


#ifndef USART_CFG_H_
#define USART_CFG_H_


/*USART BAUDE RATE OPTIONS
110, 300, 600,1200, 2400, 4800, 9600, 14400, 19200, 38400, 57600, 115200, 128000 and 256000 
*/

#define USART_BAUDRATE 2400
#define F_CPU 8000000UL




//UCSRA Register/
#define    UCSRA_RXC                 7
#define    UCSRA_TXC                 6
#define    UCSRA_UDRE                5
#define    UCSRA_FE                  4
#define    UCSRA_DOR                 3
#define    UCSRA_PE                  2
#define    UCSRA_U2x                 1
#define    UCSRA_MPCM                0

//UCSRB Register/
#define    UCSRB_RXCIE               7
#define    UCSRB_TXCIE               6
#define    UCSRB_UDRIE               5
#define    UCSRB_RXEN                4
#define    UCSRB_TXEN                3
#define    UCSRB_UCSZ2               2
#define    UCSRB_RXB8                1
#define    UCSRB_TXB8                0

//UCSRC Register/
#define    UCSRC_URSEL               7
#define    UCSRC_UMSEL               6
#define    UCSRC_UPM1                5
#define    UCSRC_UPM0                4
#define    UCSRC_USBS                3
#define    UCSRC_UCSZ1               2
#define    UCSRC_UCSZ0               1
#define    UCSRC_UCPOL               0

/*Interrupt Options [1]Enable/[0]DISABLE*/
#define    USART_INTERRUPT_DISABLED            1
#define    USART_INTERRUPT_ENABLED             0

/*Operating Mode Options [1]Enable/[0]DISABLE*/
#define    USART_MODE_ASYNCHRONOUS        1
#define    USART_MODE_SYNCHRONOUS         0

/*Parity Options [1]Enable/[0]DISABLE*/
#define    USART_NO_PARITY           1
#define    USART_EVEN_PARITY         0
#define    USART_ODD_PARITY          0

/*Stop Bits Options [1]Enable/[0]DISABLE*/
#define    _One_STOP_BIT          1
#define    _Two_STOP_BIT          0

/*Word Size Options [1]Enable/[0]DISABLE*/
#define   USART_WORDSIZE_5_BITS            0
#define   USART_WORDSIZE_6_BITS            0
#define   USART_WORDSIZE_7_BITS            0
#define   USART_WORDSIZE_8_BITS            1
#define   USART_WORDSIZE_9_BITS            0






#endif /* USART_CFG_H_ */