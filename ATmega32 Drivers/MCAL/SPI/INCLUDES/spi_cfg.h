/*
=======================================================================================================================
Author       : Mamoun
Module       : SPI
File Name    : spi_cfg.h
Date Created : Oct 29, 2023
Description  : Configuration file for the ATmega32 SPI driver.
=======================================================================================================================
*/


#ifndef MCAL_SPI_INCLUDES_SPI_CFG_H_
#define MCAL_SPI_INCLUDES_SPI_CFG_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* The device can only configured as [SPI_MASTER_MODE or SPI_SLAVE_MODE]. */
#define SPI_DEVICE_MODE                              (SPI_SLAVE_MODE)

/* Pre-agreed message message initializer and terminator between the master and slaves. */
#define SPI_MESSAGE_INITIALIZER                      '>'
#define SPI_MESSAGE_TERMINATOR                       ';'

#endif /* MCAL_SPI_INCLUDES_SPI_CFG_H_ */
