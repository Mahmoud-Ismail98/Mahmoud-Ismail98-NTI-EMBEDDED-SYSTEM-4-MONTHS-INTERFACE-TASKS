/*
 * USART.c
 *
 * Created: 10/28/2023 11:14:45 AM
 *  Author: ahmed radwan
 */ 

#include <util/delay.h>
#include "../../SERVICES/Standard_Data_Types.h"
#include "../../SERVICES/Bit_Wise_Operations.h"
#include "../PORT/PORT.h"
#include "USART_PRIV.h"
#include "USART.h"

static void USART_vidSetBaudrate(u32 Baudrate);
void USART_INT(void){
	SET_BAUD_RATE();
	RX_MODE_ENABLE();
	TX_MODE_ENABLE();
	UCSRC_ACCCES();
	Stop_Bit_Selec();
	slect_8bit();
	USART_ASYN_SLECT();
}
void USART_vidRECIVE_Blokind(u8 *data)
{
	//RX_MODE_ENABLE();
	while(!USART_Receive_Complete());
		*data=UDR;

}
void USART_vidTRANSMIT_Blokind(u8 data)
{
	//TX_MODE_ENABLE();
	while(!USART_Data_Register_Empty());
	UDR=data;	
}
static void USART_vidSetBaudrate(u32 Baudrate)
{
	u32 locBudrateregval=F_CPU/(16*Baudrate)-1;
	UBRRH_ACCCES();
	UBRRH=Baudrate>>8;
	UBRRL=(u8)Baudrate;
}