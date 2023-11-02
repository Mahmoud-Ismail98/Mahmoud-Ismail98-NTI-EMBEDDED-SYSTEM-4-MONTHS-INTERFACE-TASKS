/*
 * I2C_prv.h
 */ 


#ifndef I2C_PRV_H_
#define I2C_PRV_H_

#define TWCR   (*(volatile u8 *)0x56)
#define TWBR   (*(volatile u8 *)0x20)
#define TWSR   (*(volatile u8 *)0x21)
#define TWAR   (*(volatile u8 *)0x22)
#define TWDR   (*(volatile u8 *)0x23)

#define TWPS0   0 // TWSR reg
#define TWPS1   1

#define TWEA   6 // TWCR reg
#define TWSTO  4
#define TWSTA  5
#define TWEN   2





#define ps_1   1
#define ps_4   4
#define ps_16  16
#define ps_64  64

#define TWGCE  0  //TWAR reg
#endif /* I2C_PRV_H_ */