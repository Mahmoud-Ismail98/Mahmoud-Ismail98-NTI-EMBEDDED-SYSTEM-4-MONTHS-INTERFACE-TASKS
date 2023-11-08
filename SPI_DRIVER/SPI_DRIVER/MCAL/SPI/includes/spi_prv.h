/*
 * spi_prv.h
 *
 * Created: 10/28/2023 11:00:16 PM
 *  Author: sharb
 */ 


#ifndef SPI_PRV_H_
#define SPI_PRV_H_

#include "std_types.h"

#define SPCR					       (*(vu8*)(0x2D))
#define SPSR					       (*(vu8*)(0x2E))
#define SPDR					       (*(vu8*)(0x2F))

								       
								       
								       
								       
#define SPIE					       7
#define SPE 					       6
#define DORD 					       5
#define MSTR 					       4
#define CPOL 					       3
#define CPHA 					       2
#define SPR1 					       1
#define SPR0					       0
								       
#define SPIF					       7
#define WCOL 					       6
#define SPI2X					       0
								       
								       
#define SPI_DATA_ORDER_LSB             0
#define SPI_DATA_ORDER_MSB             1
								       
#define SPI_CLK_IDLE_LOW               0
#define SPI_CLK_IDLE_HIGH              1

#define SPI_CLK_PHASE_SAMPLE_LEADING   0
#define SPI_CLK_PHASE_SETUP_LEADING    1


#define SPI_CLK_PRESCALER_4            0
#define SPI_CLK_PRESCALER_16           1
#define SPI_CLK_PRESCALER_64           2
#define SPI_CLK_PRESCALER_128          3


#define SPI_DOUBLE_SPEED_ON            0
#define SPI_DOUBLE_SPEED_OFF           1



//#define SLAVE_ENABLE()  (SPIPORT &=~ (1<<SS_PIN))
//#define SLAVE_DISABLE() (SPIPORT |=  (1<<SS_PIN))

#endif /* SPI_PRV_H_ */