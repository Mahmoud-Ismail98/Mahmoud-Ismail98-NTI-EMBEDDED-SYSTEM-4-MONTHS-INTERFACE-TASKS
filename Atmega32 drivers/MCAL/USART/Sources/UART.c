/*
 * UART.c
 */
#include "Std_types.h"
#include "Bit_utils.h"
#include "UART_prv.h"
#include "UART_cfg.h"
#include "UART.h"


void (*Global_Fptr_RX)(void) = NULL;
void (*Global_Fptr_TX)(void) = NULL;

void UART_voidInit()
{
	/*SET CLOCK MODE*/
	#if UART_CLOCKMODE==UART_Asynch
	SET_BIT(UCSRC,URSEL);   //Enable Writing on UCSRC
	CLR_BIT(UCSRC,UMSEL);
	#elif UART_CLOCKMODE==UART_Synch
	SET_BIT(UCSRC,URSEL);
	SET_BIT(UCSRC,UMSEL);
	#endif

	/*SET MODE*/
	//SET_BIT(UCSRC,URSEL);
	UCSRB &=  0xE7;  ////////////////////////////////////
	UCSRB = UCSRB | (UART_MODE<<3);

	/*SET SPEED MODE*/
	#if UART_SPEED_MODE == UART_DOUBLESPEED_ENABLED
	SET_BIT(UCSRA,U2X);
	#elif UART_SPEED_MODE == UART_DOUBLESPEED_DISABLED
	CLR_BIT(UCSRA,U2X);
	#endif

	/*SET BaudRate*/
	#if UART_BAUDRATE == BUAD_2400
	SET_BIT(UBRRH,0);
	#endif
	UBRRL = UART_BAUDRATE;

	/*SET PARITY*/
	SET_BIT(UCSRC,URSEL);
	UCSRC &= 0xCF;
	UCSRC = UCSRC | (UART_PARITY<<4);

	/*SET DATA SIZE*/
	#if UART_DATASIZE == UART_9_Bit
	SET_BIT(UCSRB,UCSZ2);
	SET_BIT(UCSRC,UCSZ1);
	SET_BIT(UCSRC,UCSZ0);
	#else
	SET_BIT(UCSRC,URSEL);
	UCSRC &= 0xF9;
	UCSRC = UCSRC | (UART_DATASIZE<<1);
	#endif

	/*SET STOP BITS*/
	#if UART_STOPBITS==UART_1_Bit
	CLR_BIT(UCSRC,3);
	#elif UART_STOPBITS==UART_2_Bit
	SET_BIT(UCSRC,3);
	#endif
}

void UART_voidTransmit(u8 Copy_u8Data)
{
	while(GET_BIT(UCSRA,UDRE) == 0);
	UDR = Copy_u8Data;
}

void UART_voidRecieve(u8* Copy_u8Data)
{
	while(GET_BIT(UCSRA,RXC) == 0);
	*Copy_u8Data = UDR;
}

void UART_voidTransmitInterruptEnable()
{
	SET_BIT(UCSRB,TXCIE);
}
void UART_voidTransmitInterruptDisable()
{
CLR_BIT(UCSRB,TXCIE);
}

void UART_voidRecieveInterruptEnable()
{
SET_BIT(UCSRB,RXCIE);
}

void UART_voidRecieveInterruptDisable()
{
CLR_BIT(UCSRB,RXCIE);
}

void UART_SetCallBackRX ( void (*Fptr_RX) (void) )
{
	Global_Fptr_RX = Fptr_RX;
}
void UART_SetCallBackTX ( void (*Fptr_TX) (void) )
{
	Global_Fptr_TX = Fptr_TX;
}

ISR __vector_15   //TX
{
	Global_Fptr_TX();
}
ISR __vector_13 //RX
{
	Global_Fptr_RX();
}