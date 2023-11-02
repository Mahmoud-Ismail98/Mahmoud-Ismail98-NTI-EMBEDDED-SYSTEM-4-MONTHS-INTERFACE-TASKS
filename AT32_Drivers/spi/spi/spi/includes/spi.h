/*
 * spi.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef MCAL_SPI_H_
#define MCAL_SPI_H_

#include"../Mcal/dio.h"
#include"../Mcal/port.h"
#include"spi_cfg.h"
#include"spi_prv.h"
#include"../Services/std_types.h"
#include"../Services/common_macros.h"
/* spi polarity set*/
#define SPI_POLARITY_IDLE_LOW           LOGIC_LOW
#define SPI_POLARITY_IDLE_HIGH          LOGIC_HIGH

/* spi phase set*/
#define SPI_PHASE_READ                  LOGIC_LOW
#define SPI_PHASE_WRITE                 LOGIC_HIGH

/* spi bit sent first*/
#define SPI_LEAST_SIG_BIT_FIRST         LOGIC_HIGH
#define SPI_MOST_SIG_BIT_FIRST          LOGIC_LOW

/* spi mode set*/
#define SPI_MASTER_MODE                 LOGIC_HIGH
#define SPI_slave_MODE                 LOGIC_HIGH

#ifdef  SPI_DOUBLE_SPEED
/* spi prescalers set*/
#define SPI_PRESCALER_2_double_speed           0
#define SPI_PRESCALER_8_double_speed           1
#define SPI_PRESCALER_32_double_speed          2
#define SPI_PRESCALER_64_double_speed          3

#endif
/* spi prescalers set*/
#define SPI_PRESCALER_4_NORMAL_SPEED           0
#define SPI_PRESCALER_16_NORMAL_SPEED          1
#define SPI_PRESCALER_64_NORMAL_SPEED          2
#define SPI_PRESCALER_128_NORMAL_SPEED         3

/* functions prototype*/
void SPI_master_init(void);
void SPI_slave_init(void);
u8 SPI_sendReceive(u8 frame);
void SPI_sendReceiveString(pu8 stringSend);
//pu8 SPI_receiveString(void);



#endif /* MCAL_SPI_H_ */
