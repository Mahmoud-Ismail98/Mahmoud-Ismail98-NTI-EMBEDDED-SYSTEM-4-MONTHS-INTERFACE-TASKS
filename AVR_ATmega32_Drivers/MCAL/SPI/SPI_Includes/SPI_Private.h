/*
 * SPI_Private.h
 *
 * Created: 10/29/2023 12:33:43 PM
 *  Author: computer store
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

//======================================================
//includes
//======================================================
#include "MCAL/SPI/SPI_Includes/SPI.h"
#include "MCAL/SPI/SPI_Includes/SPI_CFG.h"
#include "MCAL/PORT/PORT_Includes/Port.h"
#include "MCAL/DIO/DIO_Includes/DIO.h"
#include "Services/Bit_utils.h"
#include "Services/Std_types.h"
#include "Services/vect_table.h"

 
//======================================================
//SPI_Registers
//======================================================
#define SPDR			(*(volatile uint8 *)0x2F)
#define SPSR			(*(volatile uint8 *)0x2E)
#define SPCR			(*(volatile uint8 *)0x2D)

//======================================================
//Registers bits
//======================================================

//SPCR
#define SPIE	7
#define SPE		6
#define DORD	5
#define MSTR	4
#define CPOL	3
#define CPHA	2
#define SPR1	1
#define SPR0	0

//SPSR
#define SPIF	7
#define WCOL	6
#define SPI2X	0



#define MOSI_PORT_ADD	PORTB_ADD	
#define MISO_PORT_ADD	PORTB_ADD
#define SCK_PORT_ADD	PORTB_ADD
#define SS_PORT_ADD		PORTB_ADD

#define MOSI_PIN	PORT_PIN5
#define MISO_PIN	PORT_PIN6
#define SCK_PIN		PORT_PIN7
#define SS_PIN		PORT_PIN4

#endif /* SPI_PRIVATE_H_ */