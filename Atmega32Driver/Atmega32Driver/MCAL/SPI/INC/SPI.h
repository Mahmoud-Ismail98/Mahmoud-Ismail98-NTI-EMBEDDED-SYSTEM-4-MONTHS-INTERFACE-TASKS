/*
 * SPI.h
 *
 * Created: 10/29/2023 1:57:11 PM
 *  Author: HP
 */ 


#ifndef SPI_H_
#define SPI_H_



/*Interrupt Options*/
#define SPI_Interrupt_Disable 0
#define SPI_Interrupt_Enable  1


/*Data Order Options*/
#define SPI_MSB_FIRST    0
#define SPI_LSB_FIRST    1


/*Master or Slave Select*/
#define SPI_SLAVE_MODE    0
#define SPI_MASTER_MODE   1


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
#define SPI_CLOCK_64              7


typedef enum SPI_ERORSTATE{
    SPI_OK,SPI_NULLPTR
}SPI_ERORSTATE;


void SPI_voidInit(void);
SPI_ERORSTATE SPI_DataTranceiver(u8 Copy_u8DataToTransmit,pu8 Copy_u8DataToRecive);
SPI_ERORSTATE SPI_AsynchDataRecive(pu8 Copy_u8DataToRecive);
void SPI_DataTranceiverString(pu8 Add_pu8SendStr,pu8 Add_pu8ReciveStr) ;
#endif /* SPI_H_ */