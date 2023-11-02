/*
 * spi_cfg.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef MCAL_SPI_CFG_H_
#define MCAL_SPI_CFG_H_


//#define SPI_DOUBLE_SPEED

/*
SPI_POLARITY_IDLE_LOW
SPI_POLARITY_IDLE_HIGH
*/
#define SPI_POLARITY                                 SPI_POLARITY_IDLE_LOW

/*
SPI_PHASE_READ
SPI_PHASE_WRITE
*/
#define SPI_PHASE                                    SPI_PHASE_READ

/*
SPI_LEAST_SIG_BIT_FIRST
SPI_MOST_SIG_BIT_FIRST
*/
#define SPI_LEAST_MOST_SIG_BIT_FIRST                 SPI_LEAST_SIG_BIT_FIRST

#ifdef  SPI_DOUBLE_SPEED
/*
SPI_PRESCALER_2_double_speed
SPI_PRESCALER_8_double_speed
SPI_PRESCALER_32_double_speed
SPI_PRESCALER_64_double_speed
*/
#endif

#ifndef  SPI_DOUBLE_SPEED
/*
SPI_PRESCALER_4_NORMAL_SPEED
SPI_PRESCALER_16_NORMAL_SPEED
SPI_PRESCALER_64_NORMAL_SPEED
SPI_PRESCALER_128_NORMAL_SPEED
*/
#endif

#define SPI_FREQUENCY_PRESCALER                      SPI_PRESCALER_4_NORMAL_SPEED


#endif /* MCAL_SPI_CFG_H_ */
