/*
 * SPI.h
 *
 * Created: 10/29/2023 2:11:21 PM
 *  Author: 20101
 */ 


#ifndef SPI_H_
#define SPI_H_


void SPI_voidInitialize(void);
u8 SPI_Transmit ( u8 copy_u8Data );
u8 SPI_Receiver (void);




#endif /* SPI_H_ */