/*
 * SPI.c
 */ 
#include "Std_types.h"
#include "Bit_utils.h"
#include <util/delay.h>

#include "Port.h"
#include "Dio.h"
#include "SPI_PRIV.h"
#include "SPI_CFG.h"
#include "SPI.h"


u8* SPI_INT_READ_REG=0;
void (*SPI_CALL_BACK_FN_ISR) (void)=NULL;
SPI_enuError_T spi_INT(SPI_st_T*SPI)
{
	SPI_FREQ(SPI->freq_cfg);
	switch(SPI->dataorder)
	{
		case SPI_MSB_FIRST_CFG :
			SPI_MSB_FIRST();
		    break;
		case SPI_LSB_FIRST_CFG:
			SPI_LSB_FIRST();
			break;
		default:
		   break;	
	}
		switch(SPI->mode_s)
		{		
			case SPI_SLAVE_MODE :
				SPI_SLAVE_MODE_SLECT();	
			    Port_enuSetPinDirection(pin13,OUT_PIN);//MISO 
				SetPinMode(pin11,INPUT_PULLUP);//ss
				break;
			case SPI_MASTER_MODE:
				Port_enuSetPinDirection(pin12,OUT_PIN);//MOSI 
				SetPinMode(pin11,OUTPUT_HIGH);//ss
				Port_enuSetPinDirection(pin14,OUT_PIN);//SCK
				SPI_MASTER_MODE_SLECT()	;
				break;
			default:
			 break;
		}
		switch (SPI->CLK_polarity)
		{
			case SPI_CLOCK_IDEL_LOW :
				SPI_CLOCK_IDLE_LOW();
				break;
			case SPI_CLOCK_IDEL_HIGH :
				SPI_CLOCK_IDLE_HIGH();
				break;
			default:
				break;
		}
		switch(SPI->CLK_phase)	
		{			
			case SPI_CLOCK_SAMPLE_LEADING :
				SPI_CLOCK_LEADING_SAMPLE();
				break;
			case SPI_CLOCK_SAMPLE_TRAILING:
				SPI_CLOCK_TRAILING_SAMPLE();
				break;
			default:
			break;
		}
		if(SPI->SPI_interrupt_cfg==SPI_INT_EN_CFG)
		{
			 SPI_INT_ENABLE();
			 if(SPI->SPI_CALL_BACK!=NULL)
			 {
				 SPI_CALL_BACK_FN_ISR=SPI->SPI_CALL_BACK;
			 }
			 
		}
		SPI_ENABLE();

}
SPI_enuError_T spi_transmit(SPI_st_T*SPI,u8 data)
{
	Dio_enuWriteChannel(pin11,OUTPUT_LOW);
	SPDR = data;
	while (!SPI_INT_FLAG_STATUS());
	Dio_enuWriteChannel(pin11,OUTPUT_HIGH);
}
SPI_enuError_T spi_Recive_polling(SPI_st_T*SPI,u8*rdata){
	
	while (!SPI_INT_FLAG_STATUS());
	*rdata=SPDR;
	
}
SPI_enuError_T spi_SendRecive(u8 data,u8* recived)
{
	Dio_enuWriteChannel(pin11,OUTPUT_LOW);
	_delay_ms(10);
	SPDR = data;
	while (!SPI_INT_FLAG_STATUS());
	_delay_ms(10);
	*recived=SPDR;
	//Dio_enuWriteChannel(PIN_B4_ID_12,PIN_MODE_OUTPUT_HIGH);
}
SPI_enuError_T spi_SendRecive_ASYNC(u8 data,u8* recived)
{
	Dio_enuWriteChannel(pin11,OUTPUT_LOW);
	SPI_INT_READ_REG=recived;
	SPDR = data;
}
SPI_enuError_T spi_Recive_ASYNC(u8* recived)
{
	SPI_INT_READ_REG=recived;
}
SPI_enuError_T spi_Update_Recive(u8 data,u8* recived)
{ 
	
	
	while (!SPI_INT_FLAG_STATUS());
	_delay_ms(10);
	*recived=SPDR;
	_delay_ms(10);
	SPDR = data;
	
}
void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	if(SPI_INT_READ_REG!=NULL)
	{
		*SPI_INT_READ_REG=SPDR;
	}
	else
	{
		
	}
}