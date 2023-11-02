/*
 * I2C_cfg.h
 *
 */ 


#ifndef I2C_CFG_H_
#define I2C_CFG_H_

/*
1- prescaler_1
2-prescaler_4
3-prescaler_16
4-prescaler_64
*/

#define prescaler ps_1

typedef enum{
	Master_Transmitter,
	Master_Reciever,
	slave_transmitter,
	slave_reciever
	
	}MODES;

#define NODE_MODE  Master_Transmitter

#endif /* I2C_CFG_H_ */