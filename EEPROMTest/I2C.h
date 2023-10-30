#ifndef I2C_H_
#define I2C_H_

#define Write	0
#define Read 	1

void I2C_voidInit(void);
void I2C_voidTransmitStartCondition(void);
void I2C_voidMasterTransmitSlaveAddress(u8 Copy_u8SlaveAddress, u8 Copy_u8SignalStatus);
void I2C_voidMasterTransmitData(u8 Copy_u8Data);
void I2C_voidMasterReadData(pu8 Ptr_pu8ReadData);
void I2C_voidTransmitStopCondition(void);



#endif
