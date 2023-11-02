/*
 * SPI.c
 *
 * Created: 10/29/2023 12:34:26 PM
 *  Author: computer store
 */ 

#include "MCAL/SPI/SPI_Includes/SPI_Private.h"
SPI_CFG_t GSPI_CFG = {0};

void SPI_Init(SPI_CFG_t* SPI_CFG)
{
	GSPI_CFG = * SPI_CFG;
	switch (GSPI_CFG.Master_Slave_Select)
	{
		case SPI_Master:
		Port_Set_Pin_Mode(MOSI_PORT_ADD, MOSI_PIN, PIN_Output_Low);
		Port_Set_Pin_Mode(SCK_PORT_ADD, SCK_PIN, PIN_Output_Low);
		Port_Set_Pin_Mode(SS_PORT_ADD, SS_PIN, PIN_Output_High);
		break;
	
		case SPI_Slave:
		Port_Set_Pin_Mode(MISO_PORT_ADD, MISO_PIN, PIN_Output_Low);
		break;
	}
	SPCR = 0;
	SPCR |= ( (GSPI_CFG.Master_Slave_Select << MSTR) | (GSPI_CFG.Data_Order << DORD) | (GSPI_CFG.Interrupt_State << SPIE) | (1<<CPHA) );
	
	switch(GSPI_CFG.SPI_Prescaler)
	{
		case SPI_Prescaler_4:
		SPCR &= ~(3 << SPR0);
		CLR_BIT(SPSR, SPI2X);
		break;
		
		case SPI_Prescaler_8:
		SPCR &= ~(3 << SPR0);
		SPCR |=  (1 << SPR0);
		SET_BIT(SPSR, SPI2X);
		break;
		
		case SPI_Prescaler_16:
		SPCR &= ~(3 << SPR0);
		SPCR |=  (1 << SPR0);
		CLR_BIT(SPSR, SPI2X);
		break;
		
		case SPI_Prescaler_32:
		SPCR &= ~(3 << SPR0);
		SPCR |=  (2 << SPR0);
		SET_BIT(SPSR, SPI2X);
		break;
		
		case SPI_Prescaler_64:
		SPCR &= ~(3 << SPR0);
		SPCR |=  (3 << SPR0);
		SET_BIT(SPSR, SPI2X);
		break;
		
		case SPI_Prescaler_128:
		SPCR &= ~(3 << SPR0);
		SPCR |=  (3 << SPR0);
		CLR_BIT(SPSR, SPI2X);
		break;
	}
	
	SET_BIT(SPCR, SPE); //enable SPI
}

void SPI_Transfer(uint8* Data)
{
	volatile uint8 Temp =0;
	switch (GSPI_CFG.Master_Slave_Select)
	{
		case SPI_Master:
		//working by polling
		DIO_Write_Channel(SS_PORT_ADD, SS_PIN, PIN_Low);
		SPDR = *Data;
		while(!GET_BIT(SPSR, SPIF));
		DIO_Write_Channel(SS_PORT_ADD, SS_PIN, PIN_High);
		Temp = SPSR;
		*Data = SPDR;

		//to be done working by interrupt in for future extension
		
		break;
		
		case SPI_Slave:
		//working by interrupt
				
		//to be done working by polling for future extension
		//slave read only
		 Temp = SPDR;
		 SPDR = *Data;
		*Data = Temp;
		break;
	}		
}

void SPI_Slave_Set_Initial(uint8* Data)
{
	SPDR = *Data;
}

ISR(SPI_STC_INT)
{
	GSPI_CFG.PRT_SPI_CallBack();
}
