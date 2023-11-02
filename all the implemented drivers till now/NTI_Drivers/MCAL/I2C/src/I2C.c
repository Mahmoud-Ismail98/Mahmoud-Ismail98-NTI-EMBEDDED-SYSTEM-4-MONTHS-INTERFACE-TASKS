/*
 * I2C.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Ismail
 */

#include "../includes/I2C.h"
#include <util/delay.h>


void TWI_Master_Init(u8 SelfSlaveAddress){

CLR_BIT(TWCR,TWEN); // TWI INIT

TWBR = 12; //TO GET FREQUENCY 400KHZ

	//Prescaler for bit rate selection

		CLR_BIT(TWSR,0);
		CLR_BIT(TWSR,1);
		//SELF SLAVE ADRESS INCASE THE MASTER IS TURNED TO SLAVE
		TWAR&=TWI_TWAR_ADD_MASK;
		TWAR|=(SelfSlaveAddress<<1);
		//ENABLE TWI
		SET_BIT(TWCR,TWEN);
		_delay_ms(10);

}
void TWI_Slave_Init(u8 SlaveAddress){
			CLR_BIT(TWCR,TWEN);
			SET_BIT(TWCR,TWEA);
			TWAR&=TWI_TWAR_ADD_MASK;
			TWAR|=(SlaveAddress<<1);
			SET_BIT(TWCR,2);
			_delay_ms(10);
}


void TWI_SendData(u8 SlaveAdress ,u8 Transmitted_data){
	// Send START condition
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);

	/*Wait for TWINT Flag set. This indicates
	 *that the START condition has been
	 *transmitted
	 */
	while (!(TWCR & (1<<TWINT)));

	/*
	 * Check value of TWI Status Register. Mask
	* prescaler bits. If status different from
	*START go to ERROR
	*/

	/*Load SLA_W into TWDR Register. Clear
	TWINT bit in TWCR to start transmission
	of address
	*/
	TWDR = (SlaveAdress<<1);

	TWCR = (1<<TWINT) | (1<<TWEN);

	/*Wait for TWINT Flag set. This indicates
	that the SLA+W has been transmitted,
	and ACK/NACK has been received.
	 */
	while (!(TWCR & (1<<TWINT)));
	TWDR =Transmitted_data;
	TWCR = (1<<TWINT) | (1<<TWEN);


	while (!(TWCR & (1<<TWINT)));

	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);

}


void TWI_ReadData(u8 SlaveAdress ,pu8 Recieved_data){
	// Send START condition
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);

	/*Wait for TWINT Flag set. This indicates
	 *that the START condition has been
	 *transmitted
	 */
	while (!(TWCR & (1<<TWINT)));

	/*
	 * Check value of TWI Status Register. Mask
	* prescaler bits. If status different from
	*START go to ERROR
	*/
	/*Load SLA_R into TWDR Register. Clear
	TWINT bit in TWCR to start transmission
	of address
	*/
	TWDR = ((SlaveAdress<<1)|0x01);

	TWCR = (1<<TWINT) | (1<<TWEN);

	/*Wait for TWINT Flag set. This indicates
	that the SLA+W has been transmitted,
	and ACK/NACK has been received.
	 */
	while (!(TWCR & (1<<TWINT)));

	*Recieved_data = TWDR ;
	TWCR = (1<<TWINT) | (1<<TWEN);


	while (!(TWCR & (1<<TWINT)));

	if ((TWSR & 0xF8) != TWI_STATUS_CODE_DATA_SENT_ACK)
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);

}

void TWI_SendStart(){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	_delay_ms(10);
}
void TWI_SendRepeatedStart(){

	TWI_SendStart();
}

void TWI_SendStopCondition(){

	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
			//WAIT ON FLAG TO BE HIGH//
			while(GET_BIT(TWCR,7)==0);
			_delay_ms(10);

}
void TWI_SendAdressWithWrite(u8 SlaveAdress){
	/*Load SLA_W into TWDR Register. Clear
		TWINT bit in TWCR to start transmission
		of address
		*/
		TWDR = (SlaveAdress<<1);

		TWCR = (1<<TWINT) | (1<<TWEN);

		/*Wait for TWINT Flag set. This indicates
		that the SLA+W has been transmitted,
		and ACK/NACK has been received.
		 */
		while (!(TWCR & (1<<TWINT)));
		_delay_ms(10);

}

void TWI_SendAdressWithRead(u8 SlaveAdress){
	/*Load SLA_R into TWDR Register. Clear
	TWINT bit in TWCR to start transmission
	of address
	*/
	TWDR = ((SlaveAdress<<1)|0x01);

	TWCR = (1<<TWINT) | (1<<TWEN);

	/*Wait for TWINT Flag set. This indicates
	that the SLA+W has been transmitted,
	and ACK/NACK has been received.
	 */
	while (!(TWCR & (1<<TWINT)));
	_delay_ms(10);
}
void TWI_SendDataOnly(u8 Transmitted_data){
	TWDR =Transmitted_data;
	TWCR = (1<<TWINT) | (1<<TWEN);

	while (!(TWCR & (1<<TWINT)));

	_delay_ms(10);

}



