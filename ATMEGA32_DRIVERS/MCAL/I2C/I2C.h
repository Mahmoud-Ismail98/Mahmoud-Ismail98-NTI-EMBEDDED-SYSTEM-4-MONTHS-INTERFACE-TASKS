/*
 * I2C.h
 *
 * Created: 10/30/2023 2:11:47 PM
 *  Author: 20101
 */ 


#ifndef I2C_H_
#define I2C_H_


typedef enum
{
	NO_Error ,
	StartConditionError ,
	RepeatStartError ,
	SlaveAddressWithWrite ,
	SlaveAddressWithRead ,
	MasterWriteByteError ,
	MAsterReadByteError ,
}TWI_ErrStatus;


#define TW_MT_ARB_LOST      0x38
#define TW_MR_ARB_LOST      0x38
#define TW_START            0x08
#define TW_REP_START        0x10
#define TW_MT_SLA_ACK       0x18
#define TW_MT_DATA_ACK      0x28
#define TW_MR_DATA_NOT_ACK  0x58
#define TW_MR_SLA_NOT_ACK   0x48
#define TW_MT_SLA_NOT_ACK   0x20
#define TW_MT_DATA_NOT_ACK  0x30
#define TW_MR_DATA_ACK      0x50
#define TW_MR_SLA_ACK       0x40


#endif /* I2C_H_ */