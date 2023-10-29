/**************************************************************************/
/* Filename						: USART.c                            */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: 28 Oct 2023  	           	 	      	 */
/* Version 	 					: V01                                     */
/* MicroController  			: AVR 								  	  */
/* Trainee At					: NTI (4 Months)						  */
/* Instructor					: Mahmoud Embabi						  */
/**************************************************************************/



#ifndef MCAL_USART_SOURCE_USART_C_
#define MCAL_USART_SOURCE_USART_C_

/********************************** Includes *********************************************/


#include "../../../SERIVICES/include/STD_TYPES.h"
#include "../../../SERIVICES/include/BIT_UTILS.h"
#include "../../../SERIVICES/include/MAGIC_NUMBERS.h"
#include "../../../SERIVICES/include/HELPERS.h"
#include "../../DIO/include/DIO.h"
#include <util/delay.h>
#include "../include/USART_config.h"
#include "../include/USART.h"
#include "../include/USART_private.h"


/********************************** Macros Declarations *******************************/


/********************************** Macros Function Declarations *********************/


/********************************** Data Type Declarations ****************************/




/********************************** Software Interfaces Declarations *******************/
Usart_StatusErrorType Usart_enuInit(const Usart_ConfigType* Address_Usart){

	Usart_StatusErrorType Loc_enuUsartStatus = USART_STATUS_OK;
	u16 Loc_u16BuadRateEquation ;
	u16 Loc_u16TempUsrc = 0b10000000;

	if(Address_Usart == NULL){
		Loc_enuUsartStatus = USART_STATUS_NULL_POINTER_ADDRESS;
	}
	else{

		/* Enable Tx, RX */
		SET_BIT(UCSRB ,UCSRB_RX_EN_BIT );
		SET_BIT(UCSRB ,UCSRB_TX_EN_BIT );


		/* Select Data Size */
		Usart_SelectCharacterSize(Address_Usart->character_size);

		/* Select Parity Bit */
		Usart_SelectParityBitConfg(Address_Usart->parity_bits);

		/* Select STOP Bit */
		Usart_SelectStopBitConfig(Address_Usart->stop_bits);

		/* Select Sync Mode */
		Usart_SelectStopBitConfig(Address_Usart->stop_bits);


//		Usart_SelectUbbrhReg();
		switch(Address_Usart->sync_mode){

			case USAR_SELECT_ASYNCHRONOUS_MODE:
				Loc_u16BuadRateEquation = (USART_F_CPU/16.0/Address_Usart->baude_rate)-1;
				ASSIGN_REG(UBRRL,(u8)Loc_u16BuadRateEquation);
//				ASSIGN_REG(UBRRH,((u8)Loc_u16BuadRateEquation)>>8);
				break;

			case USAR_SELET_SYNCHRONOUS_MODE:

			break;

		}

	}
		return Loc_enuUsartStatus;
}



Usart_StatusErrorType Usart_enuTransmitCharBlocking(const Usart_ConfigType* Address_Usart, u16 Copy_u16Data){

	Usart_StatusErrorType Loc_enuUsartStatus = USART_STATUS_OK;

	if(Address_Usart == NULL){
		Loc_enuUsartStatus = USART_STATUS_NULL_POINTER_ADDRESS;
	}
	else{

		while(Usart_IsRegisterDataEmpty() == ZERO_VALUE);

			UDR = (u8)Copy_u16Data;
	}
		return Loc_enuUsartStatus;
}

Usart_StatusErrorType Usart_enuReceiveBlocking(const Usart_ConfigType* Address_Usart, u16* Address_Data){

	Usart_StatusErrorType Loc_enuUsartStatus = USART_STATUS_OK;

	if(Address_Usart == NULL || Address_Data == NULL){
		Loc_enuUsartStatus = USART_STATUS_NULL_POINTER_ADDRESS;
	}
	else{

		while(Usart_IsRecevingDone() == ZERO_VALUE);

		*Address_Data = UDR ;
	}
		return Loc_enuUsartStatus;
}


Usart_StatusErrorType Usart_enuTransmitStringBlocking(const Usart_ConfigType* Address_Usart, u8* Address_Data){

	Usart_StatusErrorType Loc_enuUsartStatus = USART_STATUS_OK;
	u8 Loc_u8Counter = ZERO_VALUE;

	if(Address_Usart == NULL || Address_Data == NULL){
		Loc_enuUsartStatus = USART_STATUS_NULL_POINTER_ADDRESS;
	}
	else{
		while(Address_Data[Loc_u8Counter] ){
			Loc_enuUsartStatus = Usart_enuTransmitCharBlocking(Address_Usart,Address_Data[Loc_u8Counter++]);
		}
	}
		return Loc_enuUsartStatus;
}






#endif /* MCAL_USART_SOURCE_USART_C_ */
