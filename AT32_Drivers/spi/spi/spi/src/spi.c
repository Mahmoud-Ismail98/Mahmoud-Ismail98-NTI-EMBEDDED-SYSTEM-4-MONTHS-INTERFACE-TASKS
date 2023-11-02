/*
 * spi.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Ahmed Dwidar
 */
#include"spi.h"

void SPI_master_init(void)
{
	SET_BIT(SPCR,SPI_ENABLE);
	SET_BIT(SPCR,SPI_MASTER_SLAVE_SELECT);

	ASSIGN_FIRST_TWO_BITS(SPCR,SPI_FREQUENCY_PRESCALER);
	SPSR &= ~(1<<0);
#if(SPI_POLARITY == SPI_POLARITY_IDLE_HIGH)
	SET_BIT(SPCR,SPI_POLARITY_SET);
#else
	CLEAR_BIT(SPCR,SPI_POLARITY_SET);
#endif

#if(SPI_PHASE == SPI_PHASE_WRITE)
	SET_BIT(SPCR,SPI_PHASE_SET);
#else
	CLEAR_BIT(SPCR,SPI_PHASE_SET);
#endif

#if(SPI_LEAST_MOST_SIG_BIT_FIRST == SPI_LEAST_SIG_BIT_FIRST)
	SET_BIT(SPCR,SPI_DATA_ORDER);
#else
	CLEAR_BIT(SPCR,SPI_PHASE_SET,SPI_DATA_ORDER);
#endif


}
void SPI_slave_init(void)
{
	SET_BIT(SPCR,SPI_ENABLE);
	CLEAR_BIT(SPCR,SPI_MASTER_SLAVE_SELECT);

	ASSIGN_FIRST_TWO_BITS(SPCR,SPI_FREQUENCY_PRESCALER);

#if(SPI_POLARITY == SPI_POLARITY_IDLE_HIGH)
	SET_BIT(SPCR,SPI_POLARITY_SET);
#else
	CLEAR_BIT(SPCR,SPI_POLARITY_SET);
#endif

#if(SPI_PHASE == SPI_PHASE_WRITE)
	SET_BIT(SPCR,SPI_PHASE_SET);
#else
	CLEAR_BIT(SPCR,SPI_PHASE_SET);
#endif

#if(SPI_LEAST_MOST_SIG_BIT_FIRST == SPI_LEAST_SIG_BIT_FIRST)
	SET_BIT(SPCR,SPI_DATA_ORDER);
#else
	CLEAR_BIT(SPCR,SPI_PHASE_SET,SPI_DATA_ORDER);
#endif

}

u8 SPI_sendReceive(u8 frame)
{
	SPDR = frame;

	while(GET_BIT(SPSR,SPI_INTERRUPT_FLAG) != SPI_INTERRUPT_FLAG_IS_SET ){}
		return SPDR;
}
void SPI_sendString(pu8 stringSend)
{
	u8 iterator = 0;

	while(stringSend[iterator] != '/0')
	{
		SPI_sendReceive(stringSend[iterator]);
		iterator++;
	}
}
//void SPI_receiveString(pu8 string)
//{
//	u8 iterator = 0;
//
//	while(string[iterator] != '/0')
//	{
//		string[iterator] = SPI_sendReceive();
//		iterator++;
//	}
//
//}

