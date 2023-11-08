/*
 * I2C.h
 *
 * Created: 10/30/2023 12:02:19 PM
 *  Author: sharb
 */ 


#ifndef I2C_H_
#define I2C_H_


void TWI_MasterInit(u8 address);
void TWI_SlaveInit(u8 address);
void TWI_SlaveListen(u8 *data);
u8 TWI_start(u8 address,u8 readWriteBit);
void TWI_repeated_start(void);
u8 TWI_stop();
u8 TWI_status();
u8 TWI_data(u8 data);
u8 TWI_readACK(void);
u8 TWI_readNACK(void);


#endif /* I2C_H_ */