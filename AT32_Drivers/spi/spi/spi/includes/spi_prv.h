/*
 * spi_prv.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef MCAL_SPI_PRV_H_
#define MCAL_SPI_PRV_H_

/*
bits index inside register
*/
#define BIT_NU0                      0
#define BIT_NU1                      1
#define BIT_NU2                      2
#define BIT_NU3                      3
#define BIT_NU4                      4
#define BIT_NU5                      5
#define BIT_NU6                      6
#define BIT_NU7                      7

/*
addresses of spi registers
*/
#define SPDR        ( *( (volatile u8*)0x2F) )
#define SPSR        ( *( (volatile u8*)0x2E) )
#define SPCR        ( *( (volatile u8*)0x2D) )

/*
bits of spi index inside register
*/
#define SPI_ENABLE                 BIT_NU6
#define SPI_INTERRUPT_ENABLE       BIT_NU7
#define SPI_DATA_ORDER             BIT_NU5
#define SPI_MASTER_SLAVE_SELECT    BIT_NU4
#define SPI_POLARITY_SET           BIT_NU3
#define SPI_PHASE_SET              BIT_NU2

/*
flag bit of spi index inside register
*/
#define SPI_INTERRUPT_FLAG                     BIT_NU7

/*
set value of flag bit in spi
*/
#define SPI_INTERRUPT_FLAG_IS_SET               LOGIC_HIGH

#endif /* MCAL_SPI_PRV_H_ */
