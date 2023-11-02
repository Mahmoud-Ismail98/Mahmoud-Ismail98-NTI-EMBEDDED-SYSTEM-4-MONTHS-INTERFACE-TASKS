/*
 * I2C_priv.h
 *
 * Created: 10/30/2023 2:12:53 PM
 *  Author: 20101
 */ 


#ifndef I2C_PRIV_H_
#define I2C_PRIV_H_

#define TWBR (*(volatile u8 *) 0x20)

#define TWCR (*(volatile u8 *) 0x56)
#define TWINT 7
#define TWEA  6
#define TWSTA 5
#define TWSTO 4
#define TWWC  3
#define TWEN  2
#define TWIE  0

#define TWDR (*(volatile u8 *) 0x23)


#define TWAR (*(volatile u8 *) 0x22)
#define TWA6  7
#define TWA5  6
#define TWA4  5
#define TWA3  4
#define TWA2  3
#define TWA1  2
#define TWA0  1
#define TWGCE 0

#define TWSR (*(volatile u8 *) 0x21)
#define TWS7	7
#define TWS6	6
#define TWS5	5
#define TWS4	4
#define TWS3	3
#define TWS2	2 //reserved
#define TWPS1	1
#define TWPS0	0







#endif /* I2C_PRIV_H_ */