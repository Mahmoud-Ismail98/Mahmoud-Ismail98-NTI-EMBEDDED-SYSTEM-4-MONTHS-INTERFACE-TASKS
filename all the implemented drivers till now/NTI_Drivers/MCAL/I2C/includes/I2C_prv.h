/*
 * I2C_prv.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Ismail
 */

#ifndef MCAL_I2C_I2C_PRV_H_
#define MCAL_I2C_I2C_PRV_H_

//TWI REG
#define TWDR  *((volatile u8*)0x23)
#define TWAR  *((volatile u8*)0x22)
#define TWSR  *((volatile u8*)0x21)
#define TWBR  *((volatile u8*)0x20)
#define TWCR  *((volatile u8*)0x56)


//TWCR PINS
#define TWINT		7
#define TWEA      	6
#define TWSTA		5
#define TWSTO		4
#define TWWC		3
#define TWEN 		2
#define TWIE		0


#define TWI_INTERUPT_DISABLED  0
#define TWI_INTERUPT_ENABLED   1

#define TWI_PRESCALER_BY_1   0
#define TWI_PRESCALER_BY_4   1
#define TWI_PRESCALER_BY_16  2
#define TWI_PRESCALER_BY_64  3
#define TWI_TWAR_ADD_MASK    0x01
#define TWI_TWSR_STATUSCODE_MASK    0xF8


/*status codes*/

#define TWI_STATUS_CODE_START_COND_ACK          0x08
#define TWI_STATUS_CODE_REPEATEDSTART_COND_ACK  0x10
#define TWI_STATUS_CODE_SLAVE_ADD_WR_ACK        0x18
#define TWI_STATUS_CODE_DATA_SENT_ACK           0x28
#define TWI_STATUS_CODE_SLAVE_ADD_R_ACK         0x40
#define TWI_STATUS_CODE_DATA_RECIEVED_ACK       0x50
#define TWI_STATUS_CODE_STOP_COND_ACK           0xA0


#define GENERALCALL 0B0000000

typedef enum
{
	NoError,
WrongAddressPassed,
StartConditionFailed,
RepeatedStartConditionFailed,
SlaveAddressWithWriteFailed,
SlaveAddressWithReadFailed,
SendingDataFailed,
RecevingDataFailed,
ReadingDataFailed,
StopConditionFailed



}TWI_ErrorState;

#endif /* MCAL_I2C_I2C_PRV_H_ */
