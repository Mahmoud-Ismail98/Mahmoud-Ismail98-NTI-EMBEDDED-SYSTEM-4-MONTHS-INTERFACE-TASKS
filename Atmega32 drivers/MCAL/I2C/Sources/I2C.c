/*
 * I2C.c
 */ 
#include "Bit_utils.h"
#include "Std_types.h"
#include "I2C_prv.h"
#include "I2C_cfg.h"
#include "I2C.h"
I2C_Init(void) {
	
	TWBR = 0x03; // setting bit rate
	#if prescaler == ps_1
		CLR_BIT(TWSR,TWPS0);
		CLR_BIT(TWSR,TWPS1);
		
	#elif prescaler == ps_4
	SET_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);
	
	#elif prescaler == ps_16
	SET_BIT(TWSR,TWPS1);
	CLR_BIT(TWSR,TWPS0);
	
	#elif prescaler == ps_64
	SET_BIT(TWSR,TWPS1);
	SET_BIT(TWSR,TWPS0);
	#endif
	
}

void I2C_Enable (void){
	SET_BIT (TWCR,TWEN);
}
void I2C_Disable(void){
	CLR_BIT (TWCR,TWEN);
}

void Slave_Transmit (){
	I2C_Enable();
	GIE_INIT();
	SET_BIT(TWCR,0);
	CLR_BIT (TWCR,TWSTO);
	CLR_BIT (TWCR,TWSTA);
	SET_BIT (TWCR,TWEA);
	SET_BIT(SREG,7);
	
}