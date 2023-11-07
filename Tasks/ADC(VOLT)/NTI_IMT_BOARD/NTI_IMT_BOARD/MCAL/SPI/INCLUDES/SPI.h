/*
 * SPI.h
 *
 * Created: 10/28/2023 11:37:43 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef SPI_H_
#define SPI_H_


typedef enum{
	SPI_STATUS_FAILED,
	SPI_STATUS_OK,
	SPI_NULL_PTR_ERR
	}SPI_ERROR_STATUS_t;

void SPI_vidInit();


#endif /* SPI_H_ */