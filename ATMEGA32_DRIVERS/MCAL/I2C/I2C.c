#include <avr/io.h>
#include "Std_types.h"
#include "Bit_utils.h"
#include "I2C.h"
#include "I2C_priv.h"

/* Function: TWI_voidMasterInit
 * Description: Initializes the I2C communication module as a master with the specified slave address.
 * Inputs:
 *   - copy_u8SlaveAddress: The address of the slave device.
 * Outputs: None
 */
void TWI_voidMasterInit(u8 copy_u8SlaveAddress) {
    /* Set Clock Frequency To 400Kbps (TWBR = 2) */
    TWBR = 2;

    /* Clear the 2 Bits of TWPS */
    CLR_BIT(TWSR, TWPS0);
    CLR_BIT(TWSR, TWPS1);

    /* Initialize the Node Address */
    if (copy_u8SlaveAddress != 0) {
        TWAR = copy_u8SlaveAddress << 1;
    }

    /* Enable TWI */
    SET_BIT(TWCR, TWEN);
}

/* Function: TWI_voidSlave
 * Description: Initializes the I2C communication module as a slave with the specified slave address.
 * Inputs:
 *   - copy_u8SlaveAddress: The address of the slave device.
 * Outputs: None
 */
void TWI_voidSlave(u8 copy_u8SlaveAddress) {
    /* Initialize the Node Address */
    TWAR = copy_u8SlaveAddress << 1;

    /* Enable TWI */
    SET_BIT(TWCR, TWEN);
}

/* Function: TWI_SendStartCondition
 * Description: Sends a start condition on the I2C bus.
 * Inputs: None
 * Outputs:
 *   - Error_Status: The status of the operation (NO_Error, StartConditionError).
 */
TWI_ErrStatus TWI_SendStartCondition(void) {
    TWI_ErrStatus Error_Status = NO_Error;

    /* Send Start Condition on the Bus */
    SET_BIT(TWCR, TWSTA);

    /* Clear The Interrupt Flag To Start The Previous Operation */
    SET_BIT(TWCR, TWINT);

    /* Wait until the Interrupt Flag Is Raised Again */
    while (GET_BIT(TWCR, TWINT) == 0);

    /* Check The Status On The Status Register */
    if ((TWSR & 0xF8) != TW_START) {
        Error_Status = StartConditionError;
    } else {
        /* Do nothing */
    }

    return Error_Status;
}

/* Function: TWI_Repeat_Start
 * Description: Sends a repeated start condition on the I2C bus.
 * Inputs: None
 * Outputs:
 *   - Error_Status: The status of the operation (NO_Error, RepeatStartError).
 */
TWI_ErrStatus TWI_Repeat_Start(void) {
    TWI_ErrStatus Error_Status = NO_Error;

    /* Send Start Condition on the Bus */
    SET_BIT(TWCR, TWSTA);

    /* Clear The Interrupt Flag To Start The Previous Operation */
    SET_BIT(TWCR, TWINT);

    /* Wait until the Interrupt Flag Is Raised Again */
    while (GET_BIT(TWCR, TWINT) == 0);

    /* Check The Status On The Status Register */
    if ((TWSR & 0xF8) != TW_REP_START) {
        Error_Status = RepeatStartError;
    } else {
        /* Do nothing */
    }

    return Error_Status;
}

/* Function: TWI_SendSlaveAdresssWithWrite
 * Description: Sends a slave address with write request on the I2C bus.
 * Inputs:
 *   - copy_u8SlaveAddress: The address of the slave device.
 * Outputs:
 *   - Error_Status: The status of the operation (NO_Error, SlaveAddressWithWrite).
 */
TWI_ErrStatus TWI_SendSlaveAdresssWithWrite(u8 copy_u8SlaveAddress) {
    TWI_ErrStatus Error_Status = NO_Error;

    /* Clear Start Condition Bit */
    CLR_BIT(TWCR, TWSTA);

    /* Set The Slave Address in the 7 MSB in the Data Register */
    TWDR = copy_u8SlaveAddress << 1;

    /* Write Request */
    CLR_BIT(TWDR, 0);

    /* Clear The Interrupt Flag To Start The Previous Operation */
    SET_BIT(TWCR, TWINT);

    /* Wait until the Interrupt Flag Is Raised Again */
    while (GET_BIT(TWCR, TWINT) == 0);

    /* Check The Status On The Status Register */
    if ((TWSR & 0xF8) != TW_MT_SLA_ACK) {
        Error_Status = SlaveAddressWithWrite;
    } else {
        /* Do nothing */
    }

    return Error_Status;
}

/* Function: TWI_SendSlaveAdresssWithRead
 * Description: Sends a slave address with read request on the I2C bus.
 * Inputs:
 *   - copy_u8SlaveAddress: The address of the slave device.
 * Outputs:
 *   - Error_Status: The status of the operation (NO_Error, SlaveAddressWithRead).
 */
TWI_ErrStatus TWI_SendSlaveAdresssWithRead(u8 copy_u8SlaveAddress) {
    TWI_ErrStatus Error_Status = NO_Error;

    /* Clear Start Condition Bit */
    CLR_BIT(TWCR, TWSTA);

    /* Set The Slave Address in the 7 MSB in the Data Register */
    TWDR = copy_u8SlaveAddress << 1;

    /* Read Request */
    SET_BIT(TWDR, 0);

    /* Clear The Interrupt Flag To Start The Previous Operation */
    SET_BIT(TWCR, TWINT);

    /* Wait until the Interrupt Flag Is Raised Again */
    while (GET_BIT(TWCR, TWINT) == 0);

    /* Check The Status On The Status Register */
    if ((TWSR & 0xF8) != TW_MR_SLA_ACK) {
        Error_Status = SlaveAddressWithRead;
    } else {
        /* Do nothing */
    }

    return Error_Status;
}

/* Function: TWI_MasterWriteDataByte
 * Description: Writes a data byte on the I2C bus as a master.
 * Inputs:
 *   - copy_u8DataByte: The data byte to be written.
 * Outputs:
 *   - Error_Status: The status of the operation (NO_Error, MasterWriteByteError).
 */
TWI_ErrStatus TWI_MasterWriteDataByte(u8 copy_u8DataByte) {
    TWI_ErrStatus Error_Status = NO_Error;

    /* Write The Data Byte */
    TWDR = copy_u8DataByte;

    /* Clear The Interrupt Flag To Start The Previous Operation */
    SET_BIT(TWCR, TWINT);

    /* Wait until the Interrupt Flag Is Raised Again */
    while (GET_BIT(TWCR, TWINT) == 0);

    /* Check The Status On The Status Register */
    if ((TWSR & 0xF8) != TW_MT_DATA_ACK) {
        Error_Status = MasterWriteByteError;
    } else {
        /* Do nothing */
    }

    return Error_Status;
}

/* Function: TWI_MasterReadDataByte
 * Description: Reads a data byte from the I2C bus as a master.
 * Inputs:
 *   - copy_u8DataByte: Pointer to store the received data byte.
 * Outputs:
 *   - Error_Status: The status of the operation (NO_Error, MAsterReadByteError).
 */
TWI_ErrStatus TWI_MasterReadDataByte(u8 *copy_u8DataByte) {
    TWI_ErrStatus Error_Status = NO_Error;

    /* Enable Master Generating Acknowledge bit */
    SET_BIT(TWCR, TWEA);

    /* Clear The Flag to allow The Slave To write Data and the master to receive */
    SET_BIT(TWCR, TWINT);

    /* Wait until the Interrupt Flag Is Raised Again */
    while (GET_BIT(TWCR, TWINT) == 0);

    /* Check The Status On The Status Register */
    if ((TWSR & 0xF8) != TW_MR_DATA_ACK) {
        Error_Status = MAsterReadByteError;
    } else {
        /* Read The Received Data */
        *copy_u8DataByte = TWDR;
    }

    return Error_Status;
}

/* Function: TWI_SendStopCondition
 * Description: Sends a stop condition on the I2C bus.
 * Inputs: None
 * Outputs: None
 */
void TWI_SendStopCondition(void) {
    /* Generate Stop Condition On the Bus */
    SET_BIT(TWCR, TWSTO);

    /* Clear The Flag to allow The Slave To write Data and the master to receive */
    SET_BIT(TWCR, TWINT);
}