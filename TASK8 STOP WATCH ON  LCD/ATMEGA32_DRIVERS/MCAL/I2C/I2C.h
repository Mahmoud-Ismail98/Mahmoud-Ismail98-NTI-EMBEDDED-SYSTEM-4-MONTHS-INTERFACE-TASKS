/*
 * I2C.h
 *
 * Created: 30/10/2023 12:30:28 م
 *  Author: mkora
 */ 


#ifndef I2C_H_
#define I2C_H_


#define TWCR		*((volatile u8*)0x56)		/*TWI Control Register*/
#define TWINT	7							/*Interrupt Flag*/
#define TWEA	6                           /*Enable Acknowledge*/
#define TWSTA	5                           /*Start Condition*/
#define TWSTO	4                           /*Stop Condition*/
#define TWWC	3                           /*Write Collision*/
#define TWEN	2                           /*Enable*/
#define TWIE	0                           /*Interrupt Enable*/

#define TWDR 		*((volatile u8*)0x23)       /*TWI Data Register*/

#define	TWAR		*((volatile u8*)0x22)       /*TWI Address Register*/
#define TWAR_TWGCE	0							/*General Call recognition Enable*/

#define TWSR		*((volatile u8*)0x21)       /*TWI Status Register*/
#define TWSR_TWPS0	0							/*Prescaler Bit0*/
#define TWSR_TWPS1	1							/*Prescaler Bit1*/

#define TWBR		*((volatile u8*)0x20)       /*TWI Bit Rate Register*/

u8 I2C_Start(char write_address);
u8 I2C_Write(u8 data);
//char I2C_Read_Ack(void)	



#endif /* I2C_H_ */