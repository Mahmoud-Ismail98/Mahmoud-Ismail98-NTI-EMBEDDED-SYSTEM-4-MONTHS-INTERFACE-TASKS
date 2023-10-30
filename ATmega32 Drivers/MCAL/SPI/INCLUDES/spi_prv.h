/*
=======================================================================================================================
Author       : Mamoun
Module       : SPI
File Name    : spi_prv.h
Date Created : Oct 29, 2023
Description  : Private file for the ATmega32 SPI driver.
=======================================================================================================================
*/


#ifndef MCAL_SPI_INCLUDES_SPI_PRV_H_
#define MCAL_SPI_INCLUDES_SPI_PRV_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* SPI API interface modes: [Interrupt or Polling]. */
#define SPI_USING_POLLING                                (0U)
#define SPI_USING_INTERRUPT                              (1U)

/* SPI device modes: [Master or Slave]. */
#define SPI_SLAVE_MODE                                   (0)
#define SPI_MASTER_MODE                                  (1)

#define SPI_DUMMY_BYTE                                   (0XFF)

#endif /* MCAL_SPI_INCLUDES_SPI_PRV_H_ */
