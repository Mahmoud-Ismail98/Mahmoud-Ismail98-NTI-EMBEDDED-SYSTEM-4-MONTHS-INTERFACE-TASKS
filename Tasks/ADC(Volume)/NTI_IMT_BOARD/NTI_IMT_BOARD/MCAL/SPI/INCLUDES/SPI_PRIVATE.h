/*
 * SPI_PRIVATE.h
 *
 * Created: 10/28/2023 11:38:06 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/*Interrupt Options*/
#define SPI_Interrupt_Enable  1
#define SPI_Interrupt_Disable 0

/*Data Order Options*/
#define SPI_LSB_FIRST    1
#define SPI_MSB_FIRST    0

/*Master or Slave Select*/
#define SPI_MASTER_MODE   1
#define SPI_SLAVE_MODE    0

/*CLOCK  POLARITY*/
#define SPI_LEADING_EDGE_RISING  0
#define SPI_LEADING_EDGE_FALLING 1

/*Clock Phase Options*/
#define SPI_LEADING_EDGE_SAMPLE   0
#define SPI_LEADING_EDGE_SETUP    1

/*SPI CLOCK RATE SELECT*/
#define SPI_CLOCK_4               0
#define SPI_CLOCK_16              1
#define SPI_CLOCK_64              2
#define SPI_CLOCK_128             3
#define SPI_CLOCK_2               4
#define SPI_CLOCK_8               5
#define SPI_CLOCK_32              6
#define SPI_CLOCK_64_double_speed             7

/*OPTIONS FOR SPI SPEED*/
#define SPI_NORMAL_SPEED        0
#define SPI_DOUBLE_SPEED        1



#define    SPCR   ((*(volatile pu8)0x2D))   //SPI Control Register
	/*SPCR PINS*/
	#define SPCR_SPIE   7 //SPI Interrupt Enable
	#define SPCR_SPE    6 //SPI Enable
	#define SPCR_DORD   5 //Data Order LSB OR MSB
	#define SPCR_MSTR   4 //Master Slave Select
	#define SPCR_CPOL   3 //Clock Polarity
	#define SPCR_CPHA   2 //Clock Phase
	#define SPCR_SPR1   1 //SPI Clock Rate Select 1
	#define SPCR_SPR0   0 //SPI Clock Rate Select 0
	
#define SPSR  ((*(volatile pu8)0x2E))		// SPI Status Register
	/*SPSR PINS*/
	#define SPSR_SPIF   7  //SPI INTERRUPT FLAG
	#define SPSR_WCOL   6  //Write COLlision Flag
	#define SPSR_SPI2X  0  //SPI Double Speed Bit
	
#define SPDR ((*(volatile pu8)0x2F))	  //SPI DATA REGISTER

#endif /* SPI_PRIVATE_H_ */