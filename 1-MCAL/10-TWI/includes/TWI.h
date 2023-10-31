/*****************************************************************************/
/*****************************************************************************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : TWI                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef TWI_H
#define TWI_H


void TWI_voidMasterInit(u8 Copy_u8SlaveAddress);

void TWI_voidSlaveInit(u8 Copy_u8MasterAsSlaveAddress);

void TWI_SendStartCondition(void);

void TWI_SendRepeatedStartCondition(void);

void TWI_SendStopCondition(void);

void TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

void TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

void TWI_MasterWriteDataByte(u8 Copy_u8DataByte);

void TWI_MasterReadDataByte(u8 *Copy_pu8DataByte);



#endif 
