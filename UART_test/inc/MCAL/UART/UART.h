/*
 * UART.h
 *
 *  Created on: Ù¢Ù¨â€�/Ù¡Ù â€�/Ù¢Ù Ù¢Ù£
 *      Author: ascom
 */

#ifndef MCAL_UART_INC_UART_H_
#define MCAL_UART_INC_UART_H_


#define ASYNC	0
#define SYNC	1

#define Parity_Disabled 	 0
#define Parity_Even			 2
#define Parity_Odd			 3



#define STOP_1bit			0
#define STOP_2bit		    1

#define Character_num5			0
#define Character_num6			1
#define Character_num7			2
#define Character_num8			3
#define Character_num9			7


#define Falling			0
#define Raising			1



#define Buad_Normal_MODE			0

#define Buad_Double_Speed_mode		1


void UART_init(void);

void UART_SendCharacter(u8 Character);
void UART_ReceveCharacter(u8 *Character);
u16 BUAD_RATE(u32 BuadRate,u32 F_CLOCK,u8 Operating_mode);

//void UARR_SendCharacter(u8 Character);
//void UARR_SendCharacter(u8 Character);

#endif /* MCAL_UART_INC_UART_H_ */
