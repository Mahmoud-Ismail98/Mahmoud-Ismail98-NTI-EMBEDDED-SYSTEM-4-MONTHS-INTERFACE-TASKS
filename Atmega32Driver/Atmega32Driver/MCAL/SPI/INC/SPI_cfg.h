/*
 * SPI_cfg.h
 *
 * Created: 10/29/2023 1:58:51 PM
 *  Author: HP
 */ 


#ifndef SPI_CFG_H_
#define SPI_CFG_H_


/*Options FOR SPI Interrupt
1-SPI_Interrupt_Enable
2-SPI_Interrupt_Enable

*/
#define SPI_INTERRUPT_MODE    SPI_Interrupt_Disable



/*Options FOR data order
1-SPI_LSB_FIRST 
2-SPI_MSB_FIRST 

*/
#define SPI_DATA_ORDER       SPI_LSB_FIRST


/*Options FOR MASTER OR SLAVE
1-SPI_MASTER_MODE
2-SPI_SLAVE_MODE

*/
#define SPI_MODE       SPI_SLAVE_MODE

/*Options FOR CLOCK POLARITY
1-SPI_LEADING_EDGE_RISING
2-SPI_LEADING_EDGE_FALLING

*/
#define SPI_CLOCK_POLARITY      SPI_LEADING_EDGE_RISING

/*Options FOR CLOCK PHASE
1-SPI_LEADING_EDGE_SAMPLE 
2-SPI_LEADING_EDGE_SETUP

*/
#define SPI_CLOCK_PHASE			SPI_LEADING_EDGE_SAMPLE 


/*Options FOR CLOCK RATE SELECT
1-SPI_CLOCK_4
2-SPI_CLOCK_16
3-SPI_CLOCK_64
4-SPI_CLOCK_128
5-SPI_CLOCK_2
6-SPI_CLOCK_8
7-SPI_CLOCK_32
*/
#define SPI_CLOCK_RATE_SELECT			SPI_CLOCK_128

/*OPTIONS FOR SPI SPEED
1-SPI_NORMAL_SPEED
2-SPI_DOUBLE_SPEED
*/
#define SPI_SPEED  SPI_NORMAL_SPEED   //if double speed is used spi_clock_2 is not supported and will be modified to spi_clock_4 by default




#endif /* SPI_CFG_H_ */