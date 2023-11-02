/*
 * I2C.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Ismail
 */

#ifndef MCAL_I2C_I2C_H_
#define MCAL_I2C_I2C_H_

#include "../../../Services/Bit_utils.h"
#include "../../../Services/Std_types.h"
#include "I2C_prv.h"
#include "I2C_cfg.h"
void TWI_Master_Init(u8 SelfSlaveAddress);
void TWI_Slave_Init(u8 SlaveAddress);
void TWI_SendStartCondition();
void TWI_SendData(u8 SlaveAdress ,u8 Transmitted_data);
void TWI_SendDataOnly(u8 Transmitted_data);
void TWI_SendAdressWithRead(u8 SlaveAdress);
void TWI_SendAdressWithWrite(u8 SlaveAdress);
void TWI_SendStopCondition();
void TWI_SendRepeatedStart();
void TWI_SendStart();


TWI_ErrorState TWI_STATUS_ERROR();
#endif /* MCAL_I2C_I2C_H_ */
