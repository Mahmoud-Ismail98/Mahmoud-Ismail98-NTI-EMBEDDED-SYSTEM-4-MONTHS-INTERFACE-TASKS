/*
 * UART_cfg.h
 *
 *  Created on: ٢٨‏/١٠‏/٢٠٢٣
 *      Author: ascom
 */

#ifndef MCAL_UART_INC_UART_CFG_H_
#define MCAL_UART_INC_UART_CFG_H_


#define UART_MODE		ASYNC

#define Parity_MODES		Parity_Disabled


#define STOP_MODE			STOP_1bit


#define Character_Size_MODE		Character_num8
/* Uart Polarity*/
#define UART_Polarity		Falling

/* Set the Buad Rate */
#define UART_BaudRate			9600
#define UART_FClock				8000000
#define UART_OperationMode		Buad_Normal_MODE

#endif /* MCAL_UART_INC_UART_CFG_H_ */
