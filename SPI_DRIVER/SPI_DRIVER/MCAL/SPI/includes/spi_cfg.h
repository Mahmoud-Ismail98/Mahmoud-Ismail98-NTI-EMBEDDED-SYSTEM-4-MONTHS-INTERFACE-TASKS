/*
 * spi_cfg.h
 *
 * Created: 10/28/2023 10:59:50 PM
 *  Author: sharpel
 */ 


#ifndef SPI_CFG_H_
#define SPI_CFG_H_

#include "../../PORT/includes/PORT.h"

// Configure SPI pins

#define SS_PIN						   PORTB_PIN4
#define MOSI_PIN					   PORTB_PIN5
#define MISO_PIN					   PORTB_PIN6
#define CLK_PIN						   PORTB_PIN7

/*
   OPTIONS :
   1-SPI_DATA_ORDER_LSB
   2-SPI_DATA_ORDER_MSB
*/
#define SPI_DATA_ORDER         SPI_DATA_ORDER_LSB


/*
   OPTIONS :
   1-SPI_CLK_IDLE_LOW
   2-SPI_CLK_IDLE_HIGH
*/
#define SPI_CLK_POLARITY      SPI_CLK_IDLE_HIGH

/*
   OPTIONS :
   1-SPI_CLK_PHASE_SAMPLE_LEADING
   2-SPI_CLK_PHASE_SETUP_LEADING
*/
#define SPI_CLK_PHASE        SPI_CLK_PHASE_SAMPLE_LEADING

/*
   OPTIONS :
   1-SPI_CLK_PRESCALER_4            
   2-SPI_CLK_PRESCALER_16           
   3-SPI_CLK_PRESCALER_64           
   4-SPI_CLK_PRESCALER_128                     
*/
#define SPI_CLK_RATE         SPI_CLK_PRESCALER_4


/*
   OPTIONS :
   1-SPI_DOUBLE_SPEED_ON
   2-SPI_DOUBLE_SPEED_OFF
*/
#define SPI_DOUBLE_SPEED    SPI_DOUBLE_SPEED_ON




#endif /* SPI_CFG_H_ */