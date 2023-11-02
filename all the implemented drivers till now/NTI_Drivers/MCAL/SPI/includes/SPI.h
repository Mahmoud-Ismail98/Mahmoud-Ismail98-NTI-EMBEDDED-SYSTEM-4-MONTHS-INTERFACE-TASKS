/*
 * SPI.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Ismail
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_
#include "../../../Services/Std_types.h"

void SPI_MasterInit();

void SPI_SlaveInit();

void SPI_Send(u8 Copy_u8TransmittedValue);
u8 SPI_Receive();
void SPI_SendString(pu8 P_TransmittedString);
void SPI_ReceiveString(pu8 P_ReceiveString);
void __vector_12(void) __attribute__((signal));
void SPI_voidCallBack( void (*Copy_pvoidCallBack) (void));
#endif /* MCAL_SPI_SPI_H_ */
