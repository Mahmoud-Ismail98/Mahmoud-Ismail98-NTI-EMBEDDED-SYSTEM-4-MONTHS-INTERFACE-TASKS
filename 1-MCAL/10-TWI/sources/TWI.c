/*****************************************************************************/
/*****************************************************************************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : TWI                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "Std_types.h"
#include "Bit_utils.h"

#include "TWI.h"
#include "TWI_prv.h"
#include "TWI_cfg.h"

void TWI_voidMasterInit(u8 Copy_u8MasterAsSlaveAddress){
	TWBR = 2;

	TWAR = (Copy_u8MasterAsSlaveAddress<<1);
	
	SET_BIT(TWCR, TWI_ENABLE_ACK);

	SET_BIT(TWCR,TWI_ENABLE);
}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress){
	SET_BIT(TWCR, TWI_ENABLE_ACK);
	TWAR = (Copy_u8SlaveAddress<<1);

	SET_BIT(TWCR,TWI_ENABLE);
}

void TWI_SendStartCondition(void){

	SET_BIT(TWCR,TWI_START_CONDITION);

	SET_BIT(TWCR,INTERRUPT_FLAG);

	while(GET_BIT(TWCR,INTERRUPT_FLAG) ==0 ){}

}
void TWI_SendRepeatedStartCondition(void){
	u8 local_u8Var = 0;
	SET_BIT(local_u8Var, INTERRUPT_FLAG);
	SET_BIT(local_u8Var,TWI_START_CONDITION);
	SET_BIT(local_u8Var,TWI_ENABLE);
	TWCR |= local_u8Var;

	while(GET_BIT(TWCR,INTERRUPT_FLAG) ==0){}

}
void TWI_SendStopCondition(void){

	SET_BIT(TWCR,TWI_STOP_CONDITION);

	SET_BIT(TWCR,INTERRUPT_FLAG);
}

void TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress){
	
	TWDR = (Copy_u8SlaveAddress<<1);
	// CLR_BIT(TWDR,0);
	CLR_BIT(TWCR,TWI_START_CONDITION);

	SET_BIT(TWCR,INTERRUPT_FLAG);
	while(GET_BIT(TWCR,INTERRUPT_FLAG) == 0){}

}

void TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress){
	TWDR = (Copy_u8SlaveAddress<<1);
	SET_BIT(TWDR,0);
	CLR_BIT(TWCR,TWI_START_CONDITION);

	SET_BIT(TWCR,INTERRUPT_FLAG);
	while(GET_BIT(TWCR,INTERRUPT_FLAG) == 0){}
}

void TWI_MasterWriteDataByte(u8 Copy_u8DataByte){


	TWDR = Copy_u8DataByte;

    SET_BIT(TWCR,INTERRUPT_FLAG);
	while(GET_BIT(TWCR,INTERRUPT_FLAG) == 0){}

	
}

void TWI_MasterReadDataByte(u8 *Copy_pu8DataByte){

	SET_BIT(TWCR,INTERRUPT_FLAG);
	while(GET_BIT(TWCR,INTERRUPT_FLAG) == 0){}

	*Copy_pu8DataByte = TWDR;

}
