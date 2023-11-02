/*
 * SPI_cfg.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Ismail
 */

#ifndef MCAL_SPI_SPI_CFG_H_
#define MCAL_SPI_SPI_CFG_H_

/*Options for SPI Mode
 *1-SPI_MASTER_MODE
 *2-SPI_SLAVE_MODE*/

#define SPI_SET_MODE SPI_MASTER_MODE

/*Options for Interrupt
 *1-SPI_INTERRUPT_ON
 *2-SPI_INTERRUPT_OFF*/

#define SPI_INTERRUPT_MODE SPI_INTERRUPT_OFF

/*Options for POLARITY
 *1-SPI_POL_ACTIVE_HIGH
 *2-SPI_POL_ACTIVE_LOW*/

#define SPI_POLARITY_MODE SPI_POL_ACTIVE_HIGH

/*Options for PHASE
 *1-SPI_PHASE_SAMPLE_AT_LEADING
 *2-SPI_PHASE_SAMPLE_AT_TRAILING*/

#define SPI_PHASE_MODE SPI_PHASE_SAMPLE_AT_LEADING

/*Options for DATA ORDERED
 *1-SPI_DORD_MSB_FIRST
 *2-SPI_DORD_LSB_FIRST*/

#define SPI_DORD_MODE SPI_DORD_MSB_FIRST


/*Options for CLOCK
 *WHEN SPI2X IS LOW
 *1-SPI_CLOCK_FCPU_4
 *2-SPI_CLOCK_FCPU_16
 *3-SPI_CLOCK_FCPU_64
 *4-SPI_CLOCK_FCPU_128
 *
 *WHEN SPI2X IS HIGH
 *5-SPI_CLOCK_FCPU_2
 *6-SPI_CLOCK_FCPU_8
 *7-SPI_CLOCK_FCPU_32
 **/

#define SPI_CLOCK_MODE SPI_CLOCK_FCPU_128


/*Options for Double Speed
 *1-SPI_DOUBLE_SPEED_OFF
 *2-SPI_DOUBLE_SPEED_ON*/

#define SPI_DOUBLE_SPEED_MODE SPI_DOUBLE_SPEED_OFF

#endif /* MCAL_SPI_SPI_CFG_H_ */
