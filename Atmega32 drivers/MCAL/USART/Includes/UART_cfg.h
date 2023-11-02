/*3
 * UART_cfg.h
 */


#ifndef UART_CFG_H_
#define UART_CFG_H_

/*
Options:
	UART_Asynch
	UART_Synch
*/
#define UART_CLOCKMODE UART_Asynch

/*
Options:
	UART_TRANSMITTER
	UART_RECIEVER
	UART_TRANSMITTER_RECIEVER
*/
#define UART_MODE UART_TRANSMITTER_RECIEVER

/*
Options:
	UART_DOUBLESPEED_ENABLED
	UART_DOUBLESPEED_DISABLED
*/

#define UART_SPEED_MODE UART_DOUBLESPEED_DISABLED
/*
Options:
	BUAD_2400
	BUAD_4800
	BUAD_9600
	BUAD_14_4k
	BUAD_19_2k
	BUAD_28_8k
	BUAD_38_4k
	BUAD_57_6k
	BUAD_76_8k
	BUAD_115_2k
	BUAD_230_4k
	BUAD_250k
	Note: '_' between numbers refer to '.'
*/
#define UART_BAUDRATE BUAD_9600



/*
Options:
	UART_PARITY_DISABLED
	UART_PARITY_EVEN
	UART_PARITY_ODD
*/
#define UART_PARITY UART_PARITY_DISABLED

/*
Options:
	UART_5_Bit
	UART_6_Bit
	UART_7_Bit
	UART_8_Bit
	UART_9_Bit
*/
#define UART_DATASIZE UART_8_Bit
/*
Options:
	UART_1_Bit
	UART_2_Bit
*/
#define UART_STOPBITS UART_1_Bit




#endif /* UART_CFG_H_ */