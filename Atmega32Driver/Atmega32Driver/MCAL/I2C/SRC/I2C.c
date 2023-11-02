/*
 * I2C.c
 *
 * Created: 10/30/2023 12:15:38 PM
 *  Author: HP
 */ 

#include "../../../SERVICES/Bit_utils.h"
#include "../../../SERVICES/Std_types.h"

#include "../INC/I2C.h"
#include "../INC/I2C_prv.h"
#include "../INC/I2C_cfg.h"



void I2C_voidMasterInit(void)
{
	//Set Prescalar Value 0
	CLR_BIT(TWSR_Reg,TWSR_TWPS0);
	CLR_BIT(TWSR_Reg,TWSR_TWPS1);
	//CLK 400kHZ
	TWBR_Reg = 32;

	//Enable Ack
	SET_BIT(TWCR_Reg,TWCR_TWEA);
	//Enable I2C Peripheral
	SET_BIT(TWCR_Reg,TWCR_TWEN);
}

void I2C_voidSlaveInit(u8 Copy_u8Address)
{
	TWAR_Reg = Copy_u8Address<<1;

	//Enable Ack
	SET_BIT(TWCR_Reg,TWCR_TWEA);
	//Enable I2C Peripheral
	SET_BIT(TWCR_Reg,TWCR_TWEN);

}

I2C_enuErrorState I2C_enuSendStartCondition(void)
{
	I2C_enuErrorState Local_enuReturnState = I2C_OK;

	/* Send Start Condition */
	SET_BIT(TWCR_Reg,TWCR_TWSTA);

	/* Clear Flag */
	SET_BIT(TWCR_Reg,TWCR_TWINT);

	/* Polling on The Flag */
	while(GET_BIT(TWCR_Reg,TWCR_TWINT) == 0);

	/* Check on ACK */
	if((TWSR_Reg & 0xF8) != TWI_START)
	{
		Local_enuReturnState = I2C_SC_Error;
	}

	return Local_enuReturnState;
}

I2C_enuErrorState I2C_enuSendRepeatedStartCondition(void)
{
	I2C_enuErrorState Local_enuReturnState = I2C_OK;

	/* Send Start Condition */
	SET_BIT(TWCR_Reg,TWCR_TWSTA);

	/* Clear Flag */
	SET_BIT(TWCR_Reg,TWCR_TWINT);

	/* Polling on The Flag */
	while(GET_BIT(TWCR_Reg,TWCR_TWINT) == 0);

	/* Check on ACK */
	if((TWSR_Reg & 0xF8) != TWI_REP_START)
	{
		Local_enuReturnState = I2C_RSC_Error;
	}

	return Local_enuReturnState;
}

I2C_enuErrorState I2C_enuSendSlaveAddWithWrite(u8 Copy_u8SlaveAdd)     /*0b01011000*/
{
	I2C_enuErrorState Local_enuReturnState = I2C_OK;

	TWDR_Reg = Copy_u8SlaveAdd<<1;

	/* Write operation */
	CLR_BIT(TWDR_Reg,0);

	/* Clear Start Condition Bit */
	CLR_BIT(TWCR_Reg,TWCR_TWSTA);

	/* Clear Flag */
	SET_BIT(TWCR_Reg,TWCR_TWINT);

	/* Polling on The Flag */
	while(GET_BIT(TWCR_Reg,TWCR_TWINT) == 0);

	/* Check on ACK */
	if((TWSR_Reg & 0xF8) != TWI_MT_SLA_W_ACK)
	{
		Local_enuReturnState = I2C_NACK_ADD;
	}

	return Local_enuReturnState;
}

I2C_enuErrorState I2C_enuSendSlaveAddWithRead(u8 Copy_u8SlaveAdd)
{
	I2C_enuErrorState Local_enuReturnState = I2C_OK;

	TWDR_Reg = Copy_u8SlaveAdd<<1;

	/* Write operation */
	SET_BIT(TWDR_Reg,0);

	/* Clear Start Condition Bit */
	CLR_BIT(TWCR_Reg,TWCR_TWSTA);

	/* Clear Flag */
	SET_BIT(TWCR_Reg,TWCR_TWINT);

	/* Polling on The Flag */
	while(GET_BIT(TWCR_Reg,TWCR_TWINT) == 0);

	/* Check on ACK */
	if((TWSR_Reg & 0xF8) != TWI_MT_SLA_R_ACK)
	{
		Local_enuReturnState = I2C_NACK_ADD;
	}

	return Local_enuReturnState;

}

I2C_enuErrorState I2C_enuMasterSendDataByte(u8 Copy_u8Data)
{
	I2C_enuErrorState Local_enuReturnState = I2C_OK;
	TWDR_Reg = Copy_u8Data;

	/* Clear Flag */
	SET_BIT(TWCR_Reg,TWCR_TWINT);

	/* Polling on The Flag */
	while(GET_BIT(TWCR_Reg,TWCR_TWINT) == 0);

	/* Check on ACK */
	if((TWSR_Reg & 0xF8) != TWI_MT_DATA_ACK)
	{
		Local_enuReturnState = I2C_NACK_DATA;
	}


	return Local_enuReturnState;
}

I2C_enuErrorState I2C_enuMasterReadDataByte(pu8  Copy_pu8ReturnData)
{
	I2C_enuErrorState Local_enuReturnState = I2C_OK;

	/* Clear Flag To start The Operation */

	SET_BIT(TWCR_Reg,TWCR_TWINT);

	/* Polling on The Flag */
	while(GET_BIT(TWCR_Reg,TWCR_TWINT) == 0);

	/* Check on ACK */
	if((TWSR_Reg & 0xF8) != TWI_MR_DATA_ACK)
	{
		Local_enuReturnState = I2C_NACK_DATA;
	}
	else
	{
		*Copy_pu8ReturnData = TWDR_Reg;
	}


	return Local_enuReturnState;
}

void I2C_voidSendStopCondition(void)
{
	/* Stop Condition */
	SET_BIT(TWCR_Reg,TWCR_TWSTO);

	/* Clear Flag */
	SET_BIT(TWCR_Reg,TWCR_TWINT);
}

// int8_t I2C_enuSlaveListen(void)
// {
//     while (1)
//     {
//         uint8_t status;
//         while (!(TWCR_Reg & (1 << TWINT_Bit)));  /* Wait to be addressed */
//         status = TWSR_Reg & 0xF8;  /* Read TWI status register */

//         if (status == 0x60 || status == 0x68)  /* Own SLA+W received & ack returned */
//         {
//             return 0;  /* Return 0 to indicate ack returned */
//         }
//         if (status == 0xA8 || status == 0xB0)  /* Own SLA+R received & ack returned */
//         {
//             return 1;  /* Return 1 to indicate ack returned */
//         }
//         if (status == 0x70 || status == 0x78)  /* General call received & ack returned */
//         {
//             return 2;  /* Return 2 to indicate ack returned */
//         }
//         else
//         {
//             continue;
//         }
//     }
// }

// int8_t I2C_enuSlaveTransmit(uint8_t Copy_u8Data)
// {
//     uint8_t status;
//     TWDR_Reg = Copy_u8Data; /* Write data to TWDR to be transmitted */
//     TWCR_Reg = (1 << TWEN_Bit) | (1 << TWINT_Bit) | (1 << TWEA_Bit); /* Enable TWI & clear interrupt flag */

//     while (!(TWCR_Reg & (1 << TWINT_Bit))) /* Wait until TWI finishes its current job */
//     {
//         /* Empty loop */
//     }

//     status = TWSR_Reg & 0xF8; /* Read TWI status register */

//     if (status == 0xA0) /* Check for STOP/REPEATED START received */
//     {
//         TWCR_Reg |= (1 << TWINT_Bit); /* Clear interrupt flag & return -1 */
//         return -1;
//     }

//     if (status == 0xB8) /* Check for data transmitted & ack received */
//     {
//         return 0; /* If yes, then return 0 */
//     }

//     if (status == 0xC0) /* Check for data transmitted & nack received */
//     {
//         TWCR_Reg |= (1 << TWINT_Bit); /* Clear interrupt flag & return -2 */
//         return -2;
//     }

//     if (status == 0xC8) /* Last byte transmitted with ack received */
//     {
//         return -3; /* If yes, then return -3 */
//     }
//     else
//     {
//         return -4; /* else return -4 */
//     }
// }
