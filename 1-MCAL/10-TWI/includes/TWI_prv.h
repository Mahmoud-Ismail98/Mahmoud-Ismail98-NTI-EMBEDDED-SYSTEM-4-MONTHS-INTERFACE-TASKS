/*****************************************************************************/
/*****************************************************************************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : TWI                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef TWI_PRV_H
#define TWI_PRV_H

/*
addresses of spi registers
*/
#define TWBR         *((volatile u8*)0x20)
#define TWSR         *((volatile u8*)0x21)
#define TWAR         *((volatile u8*)0x22)
#define TWDR         *((volatile u8*)0x23)
#define TWCR         *((volatile u8*)0x56)


#define INTERRUPT_ENABLE                0
#define TWI_ENABLE                      2
#define TWI_WRITE_COLLISION_FLAG        3
#define TWI_STOP_CONDITION              4
#define TWI_START_CONDITION             5
#define TWI_ENABLE_ACK                  6
#define INTERRUPT_FLAG                  7




#endif 
