/*
 * USART.c
 *
 *  Created on: Oct 28, 2023
 *      Author: Ismail
 */
#include "../includes/USART.h"
#include "../../../Services/Bit_utils.h"
#include "../../../MCAL/PORT/includes/PORT.h"
#include <util/delay.h>

void USART_Init(){

	//local variable to equal UCSRC reg to write all values at one time
	u8 Loc_UCSRC=0;

		/*Select Mode*/
	#if USART_OPERATING_MODE==USART_ASYNCHRONOUS_MODE
		CLR_BIT(Loc_UCSRC,6);
	#elif USART_OPERATING_MODE==USART_SYNCHRONOUS_MODE
		SET_BIT(Loc_UCSRC,6);
	#endif

		/*Select Parity*/
	#if USART_PARITY_MODE==USART_PARITY_DISABLED
		CLR_BIT(Loc_UCSRC,4);
		CLR_BIT(Loc_UCSRC,5);
	#elif USART_PARITY_MODE==USART_PARITY_EVEN
		CLR_BIT(Loc_UCSRC,4);
		SET_BIT(Loc_UCSRC,5);
	#elif USART_PARITY_MODE==USART_PARITY_ODD
		SET_BIT(Loc_UCSRC,4);
		SET_BIT(Loc_UCSRC,5);
	#endif

		/*Select Stop Bits*/
	#if USART_STOP_MODE==USART_ONE_STOP_BIT
		CLR_BIT(Loc_UCSRC,3);
	#elif USART_STOP_MODE==USART_TWO_STOP_BIT
		SET_BIT(Loc_UCSRC,3);
	#endif

		/*Set Data Bits Length */
	#if USART_DATA_SIZE==USART_FIVE_DATA_BITS
		CLR_BIT(Loc_UCSRC,1);
		CLR_BIT(Loc_UCSRC,2);
		CLR_BIT(UCSRB,2);
	#elif USART_DATA_SIZE==USART_SIX_DATA_BITS
		SET_BIT(Loc_UCSRC,1);
		CLR_BIT(Loc_UCSRC,2);
		CLR_BIT(UCSRB,2);
	#elif USART_DATA_SIZE==USART_SEVEN_DATA_BITS
		CLR_BIT(Loc_UCSRC,1);
		SET_BIT(Loc_UCSRC,2);
		CLR_BIT(UCSRB,2);
	#elif USART_DATA_SIZE==USART_EIGHT_DATA_BITS
		SET_BIT(Loc_UCSRC,1);
		SET_BIT(Loc_UCSRC,2);
		CLR_BIT(UCSRB,2);
	#elif USART_DATA_SIZE==USART_NINE_DATA_BITS
		SET_BIT(Loc_UCSRC,1);
		SET_BIT(Loc_UCSRC,2);
		SET_BIT(UCSRB,2);
	#endif

		/*Set Bit 7 in Local Variable*/
		SET_BIT(Loc_UCSRC,7);
		UCSRC=Loc_UCSRC;

		/*SETTING THE BAUD RATE*/
		UBRRL=USART_BAUD_RATE;

		/*Enable RXEN and TXEN*/
		SET_BIT(UCSRB,3);
		SET_BIT(UCSRB,4);

		Port_enuSetPinDirection(24,PORT_u8INPUT); //pin D0 RX
		Port_enuSetPinDirection(25,PORT_u8OUTPUT); //pin D1 TX
	}

void USART_SendChar(u8 TransmittedChar){
	/*Poll on UDRE Flag*/
		while(GET_BIT(UCSRA,5)==0);
		//Send Value to UDR
		UDR=TransmittedChar;
}
u8 USART_ReceiveChar(){


	/*Poll on RXC Flag*/

	while(GET_BIT(UCSRA,7)==0);

	//Save UDR Content
	return UDR;
}
void USART_SendString(pu8 P_TransmittedString){

	u8 Loc_Counter=0;

		while(P_TransmittedString[Loc_Counter]!='\0')
		{
			USART_SendChar(P_TransmittedString[Loc_Counter]);
			_delay_ms(50);
			Loc_Counter++;
		}

}
void USART_ReceiveString (pu8 P_ReceiveString){
	u8 Loc_Counter=0;

		while(1)
			{
				//Receive
			P_ReceiveString[Loc_Counter]=USART_ReceiveChar();

			if(P_ReceiveString[Loc_Counter]==' ')
			{
				break;
			}
			Loc_Counter++;
			}
	}

