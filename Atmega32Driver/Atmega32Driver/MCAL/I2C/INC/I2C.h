/*
 * I2C.h
 *
 * Created: 10/30/2023 12:14:37 PM
 *  Author: HP
 */ 


#ifndef I2C_H_
#define I2C_H_
typedef enum I2C_enuErrorState{
    I2C_OK,I2C_NACK_ADD,I2C_NACK_DATA,I2C_SC_Error,I2C_RSC_Error
}I2C_enuErrorState;

void I2C_voidMasterInit(void);
void I2C_voidSlaveInit(u8 Copy_u8Address);
I2C_enuErrorState I2C_enuSendStartCondition(void);
I2C_enuErrorState I2C_enuSendRepeatedStartCondition(void);
I2C_enuErrorState I2C_enuSendSlaveAddWithWrite(u8 Copy_u8SlaveAdd) ;
I2C_enuErrorState I2C_enuSendSlaveAddWithRead(u8 Copy_u8SlaveAdd);
I2C_enuErrorState I2C_enuMasterSendDataByte(u8 Copy_u8Data);
I2C_enuErrorState I2C_enuMasterReadDataByte(pu8  Copy_pu8ReturnData);
void I2C_voidSendStopCondition(void);


#endif /* I2C_H_ */