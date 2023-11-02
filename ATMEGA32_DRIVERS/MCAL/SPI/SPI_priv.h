/*
 * SPI_priv.h
 *
 * Created: 10/29/2023 2:14:41 PM
 *  Author: 20101
 */ 


#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_



#define SPCR *((volatile u8 *) 0x2D)

#define SPIE 7 //SPI interrupt enable
#define SPE 6 //SPI enable
#define DORD 5//data order bit
#define MSTR 4//Master/slave select
#define CPOL 3//clock polarity
#define CPHA 2//clock phase
#define SPR1 1 //Clock rate
#define SPR0 0 //clock rate

#define SPSR *((volatile u8 *) 0x2E)
#define SPIF 7 //SPI interrupt flag
#define WCOL 6 //write collision flag
#define SPI2X 0 //double SPI speed bit

#define SPDR *((volatile u8 *) 0x2F)




#endif /* SPI_PRIV_H_ */