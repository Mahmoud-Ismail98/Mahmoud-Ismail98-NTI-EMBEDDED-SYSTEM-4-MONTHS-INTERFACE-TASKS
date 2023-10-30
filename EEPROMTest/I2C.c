#include "Std_types.h"
#include "Bit_utils.h"

#include "I2C.h"
#include "I2C_prv.h"
#include "I2C_cfg.h"
#include "PORT.h"
#include "DIO_int.h"

void I2C_voidInit(void)
{
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,0);
	
	TWBR = 2;
	TWAR = 0x02;
	TWCR = 0x44;
}
void I2C_voidTransmitStartCondition(void)
{
	u8 TWCR_reg = 0;
	SET_BIT(TWCR_reg,2);
	SET_BIT(TWCR_reg,7);
	SET_BIT(TWCR_reg,5);
	TWCR = TWCR_reg;
	while(GET_BIT(TWCR,7) == 0);
	//DIO_enum_WriteChannel(DIO_u8PORTAPIN0, DIO_u8High);
}
void I2C_voidMasterTransmitSlaveAddress(u8 Copy_u8SlaveAddress, u8 Copy_u8SignalStatus)
{
	u8 TWCR_reg = 0;
	SET_BIT(TWCR_reg,2);
	SET_BIT(TWCR_reg,7);
	u8 Local_u8Address = (Copy_u8SlaveAddress<<1)|Copy_u8SignalStatus;
	TWDR = Local_u8Address;
	TWCR = TWCR_reg;
	while(GET_BIT(TWCR,7) == 0);
	//DIO_enum_WriteChannel(DIO_u8PORTAPIN0, DIO_u8High);

}
void I2C_voidMasterTransmitData(u8 Copy_u8Data)
{
	u8 TWCR_reg = 0;
	SET_BIT(TWCR_reg,2);
	SET_BIT(TWCR_reg,7);
	TWDR = Copy_u8Data;
	TWCR = TWCR_reg;
	while(GET_BIT(TWCR,7) == 0);
	//DIO_enum_WriteChannel(DIO_u8PORTAPIN0, DIO_u8High);
}
void I2C_voidMasterReadData(pu8 Ptr_pu8ReadData)
{
	u8 TWCR_reg = 0;
	SET_BIT(TWCR_reg,2);
	//SET_BIT(TWCR_reg,6);
	SET_BIT(TWCR_reg,7);
	TWCR = TWCR_reg;
	while(GET_BIT(TWCR,7) == 0);
	*Ptr_pu8ReadData = TWDR;
}
void I2C_voidTransmitStopCondition(void)
{
	u8 TWCR_reg = 0;
	SET_BIT(TWCR_reg,2);
	SET_BIT(TWCR_reg,7);
	SET_BIT(TWCR_reg,4);
	TWCR = TWCR_reg;
	while(GET_BIT(TWCR,4) == 1);
	DIO_enum_WriteChannel(DIO_u8PORTAPIN0, DIO_u8High);
	SET_BIT(TWCR,7);
}
