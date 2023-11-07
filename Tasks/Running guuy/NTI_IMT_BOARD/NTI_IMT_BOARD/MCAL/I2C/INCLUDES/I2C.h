/*
 * I2C.h
 *
 * Created: 10/30/2023 4:59:06 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef I2C_H_
#define I2C_H_

typedef enum{
	I2C_STATUS_FAILED,
	I2C_STATUS_OK,
	I2C_NULL_PTR_ERR
	}enu_I2C_STATUS_t;
void I2C_vidInit(void);
enu_I2C_STATUS_t I2C_enuSendChar(pu8 add_pu8Data);
enu_I2C_STATUS_t I2C_enuRecieveChar(pu8 add_pu8Data);

#endif /* I2C_H_ */