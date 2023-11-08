/*
 * I2C.c
 *
 * Created: 10/30/2023 12:03:13 PM
 *  Author: sharb
 */ 



#include "std_types.h"
#include "bit_math.h"
#include "../includes/I2C_prv.h"
#include "../includes/I2C_cfg.h"
#include "../includes/I2C.h"

#define F_CPU 8000000UL
#define F_TWI 400000UL
#define myTWPS 1
#define BITRATE ((F_CPU/F_TWI)-16)/(2*(4^myTWPS))

void TWI_MasterInit(u8 address)
{
	TWBR = BITRATE;
	//TWAR = address;
}

void TWI_SlaveInit(u8 address)
{
	TWAR=address;		/* Assign Address in TWI address register */
	TWCR=(1<<TWEN)|(1<<TWEA)|(1<<TWINT);/* Enable TWI, Enable ack generation */
}
void TWI_SlaveListen(u8 *data)
{
	while(!(TWCR&(1<<TWINT)));	/* Wait to be addressed */
	*data = TWDR;
}
u8 TWI_start(u8 address,u8 readWriteBit)
{
	u8 loc_u8_ret = 0;
	if(readWriteBit == 0)
	CLR_BIT(address,0);
	else address|=(1<<0);
	TWCR = (1<<TWSTA) | (1<<TWEN)  | (1<<TWINT);
	while (!(TWCR&(1<<TWINT)));
	if(TWI_status() == 0x08)
	{
		TWDR = address;
		TWCR = (1<<TWEN)  | (1<<TWINT);
		while (!(TWCR&(1<<TWINT)));
		if(TWI_status()==0x18)
		{
			//ack
		}
		else if (TWI_status()==0x20)
		{
			//nack
		}
		else
		{
			//error
			loc_u8_ret = 2;
		}
	}
	else
	{
		//error
		loc_u8_ret = 1;
	}
	
	return loc_u8_ret;
}

void TWI_repeated_start(void)
{
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while ( !(GET_BIT(TWCR,TWINT)) );
	TWDR = 0xA1;
	TWCR = (1<<TWEN)  | (1<<TWINT);
}
u8 TWI_stop()
{
	TWCR = (1<<TWEN) | (1<<TWSTO) | (1<<TWINT);
	while(TWCR&(1<<TWSTO));
	return  (TWI_status());
}
u8 TWI_status()
{
	return (TWSR & 0xF8);
}


u8 TWI_data(u8 data)
{
	TWDR = data;
	TWCR = (1<<TWEN) | (1<<TWINT);
	while(!(TWCR&(1<<TWINT)));
	return (TWI_status());
}
u8 TWI_readACK(void)
{
	TWCR = (1<<TWEN) | (1<<TWINT) | (1<<TWEA);
	while(!(TWCR&(1<<TWINT)));
	return TWDR;
}
u8 TWI_readNACK(void)
{
	TWCR = (1<<TWEN) | (1<<TWINT);
	while(!(TWCR&(1<<TWINT)));
	return TWDR;
}