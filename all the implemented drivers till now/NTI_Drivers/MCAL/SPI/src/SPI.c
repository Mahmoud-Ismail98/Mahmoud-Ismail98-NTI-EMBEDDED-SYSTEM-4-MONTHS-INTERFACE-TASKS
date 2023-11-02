/*
 * SPI.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Ismail
 */
#include "../../../Services/Std_types.h"
#include "../../../Services/Bit_utils.h"
#include <util/delay.h>
#include "../../../MCAL/PORT/includes/PORT.h"
#include "../../../MCAL/DIO/includes/DIO.h"
#include "../../../MCAL/GIE/includes/GIE.h"
#include "../includes/SPI.h"
#include "../includes/SPI_cfg.h"
#include "../includes/SPI_prv.h"

void (*ptr)(void) = NULL;

void SPI_MasterInit()
{

	/*Set SS / MOSI / SCK  as output pins for master*/

		Port_enuSetPinDirection(12,PORT_u8OUTPUT);		//SS
		Port_enuSetPinDirection(13,PORT_u8OUTPUT);		//MOSI
		Port_enuSetPinDirection(14,PORT_u8INPUT);        //MISO
		Port_enuSetPinDirection(15,PORT_u8OUTPUT);		//SCK

		/*set SS to high */
		Dio_enuWriteChannel(12,DIO_u8LEVEL_HIGH);

	//Set Data Order

#if SPI_DORD_MODE==SPI_DORD_MSB_FIRST
	CLR_BIT(SPCR,5);
#elif SPI_DORD_MODE==SPI_DORD_LSB_FIRST
	SET_BIT(SPCR,5);
#endif

	//Set Clock Polarity
#if SPI_POLARITY_MODE==SPI_POL_ACTIVE_HIGH
	CLR_BIT(SPCR,3);
#elif SPI_POLARITY_MODE==SPI_POL_ACTIVE_LOW
	SET_BIT(SPCR,3);
#endif

	//Set Clock Phase
#if SPI_PHASE_MODE==SPI_PHASE_SAMPLE_AT_LEADING
	CLR_BIT(SPCR,2);
#elif SPI_PHASE_MODE==SPI_PHASE_SAMPLE_AT_TRAILING
	SET_BIT(SPCR,2);
#endif

	//Set Interrupt Mode
#if SPI_INTERRUPT_MODE==SPI_INTERRUPT_OFF
	CLR_BIT(SPCR,7);
#elif SPI_INTERRUPT_MODE==SPI_INTERRUPT_ON
	SET_BIT(SPCR,7);
#endif

//Set Clock

//Set Double Speed Bit Mode
#if SPI_DOUBLE_SPEED_MODE==SPI_DOUBLE_SPEED_OFF
	CLR_BIT(SPSR,0);
#elif SPI_DOUBLE_SPEED_MODE==SPI_DOUBLE_SPEED_ON
	SET_BIT(SPSR,0);
#endif


	SPCR&=(~CLOCK_MASK);
	SPCR|=SPI_CLOCK_MODE;

	//Set Mode as Master
	SET_BIT(SPCR,4);

	//Enable SPI
	SET_BIT(SPCR,6);

}
void SPI_SlaveInit()
{

	/*Set SS / MOSI / SCK  as output pins for SLAVE*/
			//Port_enuSetPinMode(12,PORT_u8INPUT_PULLUP);
			Port_enuSetPinDirection(12,PORT_u8INPUT);		//SS
			Port_enuSetPinDirection(13,PORT_u8INPUT);		//MOSI
			Port_enuSetPinDirection(14,PORT_u8OUTPUT);        //MISO
			Port_enuSetPinDirection(15,PORT_u8INPUT);		//SCK





	//Set Data Order
#if SPI_DORD_MODE==SPI_DORD_MSB_FIRST
	CLR_BIT(SPCR,5);
#elif SPI_DORD_MODE==SPI_DORD_LSB_FIRST
	SET_BIT(SPCR,5);
#endif

	//Set Clock Polarity
#if SPI_POLARITY_MODE==SPI_POL_ACTIVE_HIGH
	CLR_BIT(SPCR,3);
#elif SPI_POLARITY_MODE==SPI_POL_ACTIVE_LOW
	SET_BIT(SPCR,3);
#endif

	//Set Clock Phase
#if SPI_PHASE_MODE==SPI_PHASE_SAMPLE_AT_LEADING
	CLR_BIT(SPCR,2);
#elif SPI_PHASE_MODE==SPI_PHASE_SAMPLE_AT_TRAILING
	SET_BIT(SPCR,2);
#endif

	//Set Interrupt Mode
#if SPI_INTERRUPT_MODE==SPI_INTERRUPT_OFF
	CLR_BIT(SPCR,7);
#elif SPI_INTERRUPT_MODE==SPI_INTERRUPT_ON
	SET_BIT(SPCR,7);
#endif

	//Set Mode as Slave
	CLR_BIT(SPCR,4);

	//Enable SPI
	SET_BIT(SPCR,6);

}

void SPI_Send(u8 Copy_u8TransmittedValue)
{
	//Put Data in SPDR
	SPDR=Copy_u8TransmittedValue;
	//Poll On SPIF Flag
	while(!(SPSR & (1<<SPIF)));
	//return SPDR;
}
u8 SPI_Receive(){

		//Poll On SPIF Flag
	while(!(SPSR & (1<<SPIF)));
		return SPDR;
}

void SPI_SendString(pu8 P_TransmittedString){
	u8 Loc_Counter=0;
		while(P_TransmittedString[Loc_Counter]!='\0')
		{
			SPI_Send(P_TransmittedString[Loc_Counter]);
			_delay_ms(5);
			Loc_Counter++;
		}

}

void SPI_ReceiveString (pu8 P_ReceiveString){

	u8 Local_u8Current =0;
		u8 Local_u8Counter =0;
		 while(1)
		 {
			 (Local_u8Current)=SPI_Receive();
			 if(Local_u8Current == ' ')
			 {
				 P_ReceiveString[Local_u8Counter] ='\0';
				 break;
			 }
			 P_ReceiveString[Local_u8Counter] = Local_u8Current;
			 Local_u8Counter++;
		 }


	}




void __vector_12(void) {
	if (ptr != NULL) {
		ptr();
	}
}

void SPI_voidCallBack( void (*Copy_pvoidCallBack) (void)){
	if (Copy_pvoidCallBack != NULL) {
		ptr = Copy_pvoidCallBack;
		}

}
