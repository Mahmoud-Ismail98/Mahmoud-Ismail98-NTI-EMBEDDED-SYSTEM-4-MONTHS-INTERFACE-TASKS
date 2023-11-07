/*
 * SPI.c
 *
 * Created: 10/28/2023 11:38:16 PM
 *  Author: Mahmoud Tariq
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CLCK.h"

#include "SPI.h"
#include "SPI_CFG.h"
#include "SPI_PRIVATE.h"

volatile u8 Global_u8DataToRecive ;

void SPI_vidInit(){
	
	/*Enable SPI peripheral*/
	SET_BIT(SPCR,SPCR_SPE);
	/*INTERRUPT ENABLE OPTIONS Initialization*/
	
	#if ( SPI_INTERRUPT_MODE == SPI_Interrupt_Enable)
		SET_BIT( SPCR,SPCR_SPIE);
	#elif (SPI_INTERRUPT_MODE == SPI_Interrupt_Disable)
		CLR_BIT( SPCR,SPCR_SPIE);
	#endif
	
	
	/*Data Order Initialization*/
	
	#if (SPI_DATA_ORDER == SPI_LSB_FIRST)
		SET_BIT(SPCR,SPCR_DORD);
	#elif (SPI_DATA_ORDER == SPI_MSB_FIRST)
		CLR_BIT(SPCR,SPCR_DORD);
	#endif
	
	/*MASTER OR SLAVE INITTIALIZATION*/
	#if (SPI_MODE == SPI_MASTER_MODE)
		SET_BIT(SPCR,SPCR_MSTR);
	#elif (SPI_MODE == SPI_SLAVE_MODE)
		CLR_BIT(SPCR,SPCR_MSTR);
	#endif
	
	
	/*SPI SPEED MOOD & FREQ PRESCALER INIT*/
	#if (SPI_SPEED == SPI_NORMAL_SPEED)
			#if (SPI_CLOCK_RATE_SELECT == SPI_CLOCK_2)
				SET_BIT(SPSR,SPSR_SPI2X);
				CLR_BIT(SPCR,SPCR_SPR1);
				CLR_BIT(SPCR,SPCR_SPR0);
			#elif (SPI_CLOCK_RATE_SELECT == SPI_CLOCK_4)
				CLR_BIT(SPSR,SPSR_SPI2X);
				CLR_BIT(SPCR,SPCR_SPR1);
				CLR_BIT(SPCR,SPCR_SPR0);
			#elif (SPI_CLOCK_RATE_SELECT == SPI_CLOCK_16)
				CLR_BIT(SPSR,SPSR_SPI2X);
				CLR_BIT(SPCR,SPCR_SPR1);
				SET_BIT(SPCR,SPCR_SPR0);
			#elif (SPI_CLOCK_RATE_SELECT == SPI_CLOCK_64)
				CLR_BIT(SPSR,SPSR_SPI2X);
				SET_BIT(SPCR,SPCR_SPR1);
				CLR_BIT(SPCR,SPCR_SPR0);
			#elif (SPI_CLOCK_RATE_SELECT == SPI_CLOCK_32)
				SET_BIT(SPSR,SPSR_SPI2X);
				SET_BIT(SPCR,SPCR_SPR1);
				CLR_BIT(SPCR,SPCR_SPR0);
			#elif (SPI_CLOCK_RATE_SELECT == SPI_CLOCK_128)
				CLR_BIT(SPSR,SPSR_SPI2X);
				SET_BIT(SPCR,SPCR_SPR1);
				SET_BIT(SPCR,SPCR_SPR0);
			#elif (SPI_CLOCK_RATE_SELECT == SPI_CLOCK_8)
				SET_BIT(SPSR,SPSR_SPI2X);
				CLR_BIT(SPCR,SPCR_SPR1);
				SET_BIT(SPCR,SPCR_SPR0);
			#endif
	#elif (SPI_SPEED == SPI_DOUBLE_SPEED)
			#if (SPI_CLOCK_RATE_SELECT == SPI_CLOCK_2)   //Not supported and exchanged to SPI_CLOCK_4
			CLR_BIT(SPSR,SPSR_SPI2X);
			CLR_BIT(SPCR,SPCR_SPR1);
			CLR_BIT(SPCR,SPCR_SPR0);
			#elif (SPI_CLOCK_RATE_SELECT == SPI_CLOCK_4)
			CLR_BIT(SPSR,SPSR_SPI2X);
			CLR_BIT(SPCR,SPCR_SPR1);
			CLR_BIT(SPCR,SPCR_SPR0);
			#elif (SPI_CLOCK_RATE_SELECT == SPI_CLOCK_16)
			CLR_BIT(SPSR,SPSR_SPI2X);
			CLR_BIT(SPCR,SPCR_SPR1);
			SET_BIT(SPCR,SPCR_SPR0);
			#elif (SPI_CLOCK_RATE_SELECT == SPI_CLOCK_64)
			CLR_BIT(SPSR,SPSR_SPI2X);
			SET_BIT(SPCR,SPCR_SPR1);
			CLR_BIT(SPCR,SPCR_SPR0);
			#elif (SPI_CLOCK_RATE_SELECT == SPI_CLOCK_32)
			SET_BIT(SPSR,SPSR_SPI2X);
			SET_BIT(SPCR,SPCR_SPR1);
			CLR_BIT(SPCR,SPCR_SPR0);
			#elif (SPI_CLOCK_RATE_SELECT == SPI_CLOCK_128)
			CLR_BIT(SPSR,SPSR_SPI2X);
			SET_BIT(SPCR,SPCR_SPR1);
			SET_BIT(SPCR,SPCR_SPR0);
			#elif (SPI_CLOCK_RATE_SELECT == SPI_CLOCK_8)
			SET_BIT(SPSR,SPSR_SPI2X);
			CLR_BIT(SPCR,SPCR_SPR1);
			SET_BIT(SPCR,SPCR_SPR0);
			#endif
	
	#endif
	
	
	#if SPI_CLOCK_POLARITY == SPI_LEADING_EDGE_RISING
	CLR_BIT(SPCR,SPCR_CPOL);
	#elif SPI_CLOCK_POLARITY == SPI_LEADING_EDGE_FALLING
	SET_BIT(SPCR,SPCR_CPOL);
	#elif SPI_CLOCK_PHASE == SPI_LEADING_EDGE_SAMPLE
	CLR_BIT(SPCR,SPCR_CPHA);
	#elif SPI_CLOCK_PHASE == SPI_LEADING_EDGE_SETUP
	SET_BIT(SPCR,SPCR_CPHA);
	#endif	
}
SPI_ERROR_STATUS_t SPI_DataTranceiver(u8 Copy_u8DataToTransmit,pu8 Copy_u8DataToRecive){
	SPI_ERROR_STATUS_t Loc_ErorState = SPI_STATUS_FAILED;
	if(NULL == Copy_u8DataToRecive)
	{
		Loc_ErorState = SPI_NULL_PTR_ERR;
	}
	else
	{
		SPDR = Copy_u8DataToTransmit;
		while(GET_BIT(SPSR,SPSR_SPIF)==0);
		*Copy_u8DataToRecive = SPDR;
	}
	return Loc_ErorState;
}
SPI_ERROR_STATUS_t SPI_AsynchDataRecive(pu8 Copy_u8DataToRecive){
	SPI_ERROR_STATUS_t Loc_ErorState = SPI_STATUS_OK;
	if(NULL == Copy_u8DataToRecive)
	{
		Loc_ErorState = SPI_NULL_PTR_ERR;
	}
	else
	{
		*Copy_u8DataToRecive = Global_u8DataToRecive;
	}
	return Loc_ErorState;
}

void SPI_DataTranceiverString(pu8 Add_pu8SendStr,pu8 Add_pu8ReciveStr) {
	while (*Add_pu8SendStr != '\0') {
		SPI_DataTranceiver(*(Add_pu8SendStr++),Add_pu8ReciveStr++);
	}
	*Add_pu8ReciveStr = '\0';
}


void __vector_12(void) __attribute__((signal));
void __vector_12(void){
	Global_u8DataToRecive = SPDR;
}
