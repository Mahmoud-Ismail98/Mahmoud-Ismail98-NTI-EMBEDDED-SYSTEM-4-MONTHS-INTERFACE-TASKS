/*
 * I2C_PRIVATE.h
 *
 * Created: 10/30/2023 4:59:30 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

/*TWI Bit Rate Register*/
#define TWBR     (*((volatile pu8)0x20))

/*TWI Control Register*/
#define TWCR    (*((volatile pu8)0x56))
	/*Control Register Bits*/
	#define TWCR_WINT   7    // TWI Interrupt Flag
	#define TWCR_TWEA   6    // TWI Enable Acknowledge Bit
	#define TWCR_TWSTA  5    // TWI START Condition Bit
	#define TWCR_TWSTO  4    // TWI STOP Condition Bit 
	#define TWCR_TWWC   3    // TWI Write Collision Flag 
	#define TWCR_TWEN   2    // TWI Enable Bit
	//#define TWCR_Res   1    // Reserved Bit (always read as zero)
	#define TWCR_TWIE   0    // TWI Interrupt Enable
	
/*TWI Status Register */
#define TWSR    (*((volatile pu8)0x21)))
	/*Status Register Bits*/
	#define TWSR_TWS7    7    // TWI Status BIT 7
	#define TWSR_TWS6    6    // TWI Status BIT 6
	#define TWSR_TWS5    5    // TWI Status BIT 5
	#define TWSR_TWS4    4    // TWI Status BIT 4
	#define TWSR_TWS3    3    // TWI Status BIT 3
	//#define TWSR_BIT2   2    // Reserved Bit (Always read as zero)
	#define TWSR_TWPS1   1    // TWI Prescaler Bit 1
	#define TWSR_TWPS0   0    // TWI Prescaler Bit 0
	
/*TWI Data Register – TWDR*/
#define TWDR    (*((volatile pu8)0x23)))

/*TWI (Slave) Address Register – TWAR*/
#define TWAR    (*((volatile pu8)0x22)))
	/*TWAR Register Bits*/
	//BITS FROM 7 TO 1 ARE FOR SLAVE ADRESS
	#define  TWAR_TWGCE 0  //TWI General Call Recognition Enable Bit
	
/*====================TWI ACKNOLDGMENT OPTIONS================*/
#define TWI_ACK_OFF          0
#define TWI_ACK_ON           1	



#endif /* I2C_PRIVATE_H_ */