/*
 * SPI_prv.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Ismail
 */

#ifndef MCAL_SPI_SPI_PRV_H_
#define MCAL_SPI_SPI_PRV_H_

#define SPCR  *((volatile u8*)0x2D)
#define SPSR  *((volatile u8*)0x2E)
#define SPDR  *((volatile u8*)0x2F)

/* SPCR Register */
#define SPIE	7
#define SPE		6
#define DORD	5
#define MSTR	4
#define CPOL	3
#define CPHA	2
#define SPR1	1
#define SPR0	0

/* SPSR Register */
#define SPIF      7
#define WCOL      6
#define SPI2X     0


/*OPTIONS FOR MSPI_MODE*/
#define SPI_MASTER_MODE  0
#define SPI_SLAVE_MODE   1


/*OPTIONS FOR INTRUUPT*/
#define SPI_INTERRUPT_MODE_ENABLED   0
#define SPI_INTERRUPT_MODE_DISABLED   1



/*OPTIONS FOR POLARITY*/
#define SPI_POL_ACTIVE_HIGH         1
#define SPI_POL_ACTIVE_LOW          0


/*OPTIONS FOR PHASE*/
#define SPI_PHASE_SAMPLE_AT_LEADING     0
#define SPI_PHASE_SAMPLE_AT_TRAILLING   1


/*OPTIONS FOR DATA ORDER*/
#define SPI_DORD_MSB_FIRST                    0
#define SPI_DORD_LSB_FIRST                    1

/*OPTIONS FOR DOUBLESPEED CLK OFF (SPI2X) IS LOW*/
#define SPI_CLOCK_FCPU_4                      0
#define SPI_CLOCK_FCPU_16                     1
#define SPI_CLOCK_FCPU_64                     2
#define SPI_CLOCK_FCPU_128                    3


/*OPTIONS FOR DOUBLE SPEED CLK ON* WHEN (SPI2X) IS HIGH*/
#define SPI_DCLOCK_FCPU_2                     4
#define SPI_DCLOCK_FCPU_8                     5
#define SPI_DCLOCK_FCPU_32                    6
#define SPI_DCLOCK_FCPU_64                    7


#define SPI_CLOCK_MODE_DOUBLE_SPEED_ON        0
#define SPI_CLOCK_MODE_DOUBLE_SPEED_OFF       1
#define CLOCK_MASK                             0b00000011

#endif /* MCAL_SPI_SPI_PRV_H_ */
