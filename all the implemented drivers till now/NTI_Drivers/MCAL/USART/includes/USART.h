/*
 * USART.h
 *
 *  Created on: Oct 28, 2023
 *      Author: Ismail
 */

#ifndef MCAL_USART_USART_H_
#define MCAL_USART_USART_H_
#include "../../../Services/Std_types.h"
#include "USART_cfg.h"
#include "USART_prv.h"
void USART_Init();
void USART_SendChar(u8 TransmittedChar);
u8 USART_ReceiveChar();
void USART_SendString(pu8 P_TransmittedString);
void USART_ReceiveString(pu8 P_ReceiveString);


#endif /* MCAL_USART_USART_H_ */
