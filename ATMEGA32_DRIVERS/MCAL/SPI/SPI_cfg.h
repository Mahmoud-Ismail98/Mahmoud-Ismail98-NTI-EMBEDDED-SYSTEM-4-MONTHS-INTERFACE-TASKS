/*
 * SPI_cfg.h
 *
 * Created: 10/29/2023 2:11:36 PM
 *  Author: 20101
 */ 


#ifndef SPI_CFG_H_
#define SPI_CFG_H_


#define SPI_INTERRUPT_ENABLE      DISABLE
#define DATA_ORDER_MODE           MSB_FIRST
#define CLOCK_PLOARITY_MODE       LEAD_FALLING_TRAILING_RISING
#define CLOCK_PHASE_MODE          LEAD_SETUP_TRAILING_SAMPLE
#define SCK_FREQUENCY             FOSC_4

#define S_Pin0                    DIO_u8CHANNEL00
#define S_Pin1                    DIO_u8CHANNEL01
#define S_Pin2                    DIO_u8CHANNEL02
#define S_Pin3                    DIO_u8CHANNEL03




#endif /* SPI_CFG_H_ */