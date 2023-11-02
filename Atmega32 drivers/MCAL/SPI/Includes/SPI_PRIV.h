/*
 * SPI_PRIV.h
 */ 


#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

#define SPCR         (*((volatile ptr_u8)0x2D))
#define SPSR         (*((volatile ptr_u8)0x2E))
#define SPDR         (*((volatile ptr_u8)0x2F))


#endif /* SPI_PRIV_H_ */