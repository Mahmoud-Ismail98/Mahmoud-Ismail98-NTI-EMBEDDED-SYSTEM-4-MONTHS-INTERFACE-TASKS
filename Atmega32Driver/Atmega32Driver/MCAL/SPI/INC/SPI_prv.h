/*
 * SPI_prv.h
 *
 * Created: 10/29/2023 1:59:14 PM
 *  Author: HP
 */ 


#ifndef SPI_PRV_H_
#define SPI_PRV_H_




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




#endif /* SPI_PRV_H_ */