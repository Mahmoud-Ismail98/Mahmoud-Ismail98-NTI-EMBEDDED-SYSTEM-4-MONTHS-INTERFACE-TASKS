#include "../inc/LIB/Std_types.h"
#include "../inc/LIB/Bit_utils.h"
#include "../inc/MCAL/UART/UART.h"

#include "../inc/MCAL/UART/UART_cfg.h"
#include "../inc/MCAL/UART/UART_prv.h"


void UART_init(void)
{
	/* Accessing UCRSC*/
	SET_BIT(UCSRC,URSLE);

	/* Set the UART MODE  ASYNC/SYNC*/
#if (UART_MODE == ASYNC)
	CLR_BIT(UCSRC,UMSEL);
#elif (UART_MODE == SYNC)
	SET_BIT(UCSRC,UMSEL);
#endif
	/* Select the Parity mode*/
	UCSRC = (UCSRC & 0b11001111)|(Parity_MODES<<4);
	/* Select the STOP mode*/
	UCSRC = (UCSRC & 0b11110111)|(STOP_MODE<<3);

	/* Check if 9_bit */
#if (Character_Size_MODE == Character_num9)
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
	SET_BIT(UCSRB,UCSZ2);
#else
	CLR_BIT(UCSRB,UCSZ2);
	UCSRC = (UCSRC & 0b11111001)|(Character_Size_MODE<<1);
#endif


	/*UArt Polarity*/
	UCSRC = (UCSRC & 0b11111110)|(UART_Polarity);

	/*Set the Baud Rate*/
	CLR_BIT(UCSRB,URSLE);

	u16 registerVal ;
	registerVal = BUAD_RATE(UART_BaudRate,UART_FClock, UART_OperationMode);

	UBRRL = (u8)registerVal;
	UBRRH = (u8)((registerVal>>8)&15); /* 1111 0011 0101 1010*/
	/*  0000 0000 1111 0011*/
	//UBRRL = 51;
	//UBRRH = 0;
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);

	/* Parity mode*/

}

u16 BUAD_RATE(u32 BuadRate,u32 F_CLOCK,u8 Operating_mode)
{
	u16 returnVal;
	switch(Operating_mode)
	{
	case Buad_Normal_MODE:
		CLR_BIT(UCSRA,U2X);
		returnVal = (F_CLOCK/(16*BuadRate))-1;
		break;
	case Buad_Double_Speed_mode:
		SET_BIT(UCSRA,U2X);
		returnVal = (u16)(F_CLOCK/(8*BuadRate))-1;
		break;
	}
	return returnVal;

}


void UART_SendCharacter(u8 Character)
{
	u8 Loc_Charcter = Character ;
	while(GET_BIT(UCSRA,UDRE) == 0);
	UDR = Loc_Charcter;
}
void UART_ReceveCharacter(u8 *Character)
{
	u8 Loc_Charcter = Character ;
	while(GET_BIT(UCSRA,RXC) == 0);
	Loc_Charcter = UDR;
	*Character = Loc_Charcter;
}
