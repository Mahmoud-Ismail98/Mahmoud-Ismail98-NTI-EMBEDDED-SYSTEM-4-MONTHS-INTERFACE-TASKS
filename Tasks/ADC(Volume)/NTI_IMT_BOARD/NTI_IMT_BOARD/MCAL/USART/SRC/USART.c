/*
 * USART.c
 *
 * Created: 10/28/2023 11:14:18 AM
 *  Author: Mahmoud Tariq
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CLCK.h"

#include "PORT.h"
#include "DIO.h"
#include "USART_PRIVATE.h"
#include "USART_CFG.h"
#include "USART.h"

static u16 BAUD_PRESCALE = (F_CPU/ ((USART_BAUDRATE*16)-1));
void USART_vidInit(void){
	/*Baud Rate*/
	UBRRL = 51;
//UBRRL = (u8)(BAUD_PRESCALE);
CLR_BIT(UCSRC, UCSRC_URSEL);
	
	//UBRRH = (u8)(BAUD_PRESCALE>>8);

	//UBRRH = 51;
	//UBRRL = 0;
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);
	
	/*Initializing wanted mode*/
	
#if (1 == USART_MODE_ASYNCHRONOUS)
	SET_BIT(UCSRC, UCSRC_URSEL);
	CLR_BIT(UCSRC,UCSRC_UMSEL);
#elif (1 == USART_MODE_SYNCHRONOUS)
		SET_BIT(UCSRC, UCSRC_URSEL);
		SET_BIT(UCSRC,UCSRC_UMSEL);
#endif

/*Choosing Parity Mode*/
#if (1 == USART_NO_PARITY)
    SET_BIT(UCSRC, UCSRC_URSEL);
	CLR_BIT(UCSRC,UCSRC_UPM1);
	CLR_BIT(UCSRC,UCSRC_UPM0);
	
#elif  (1 == USART_EVEN_PARITY)
		SET_BIT(UCSRC, UCSRC_URSEL);
		SET_BIT(UCSRC,UCSRC_UPM1);
		CLR_BIT(UCSRC,UCSRC_UPM0);
		
#elif  (1 == USART_ODD_PARITY)
		SET_BIT(UCSRC, UCSRC_URSEL);
		SET_BIT(UCSRC,UCSRC_UPM1);
		SET_BIT(UCSRC,UCSRC_UPM0);
#endif

/*Stop Bit Select*/

#if (1 == _One_STOP_BIT )
	SET_BIT(UCSRC, UCSRC_URSEL);
	SET_BIT(UCSRC,UCSRC_USBS);

#elif (1 == _Two_STOP_BIT )
	SET_BIT(UCSRC, UCSRC_URSEL);
	CLR_BIT(UCSRC,UCSRC_USBS);	
#endif
/*Word Size*/
#if ( 1 == USART_WORDSIZE_8_BITS)
	SET_BIT(UCSRC, UCSRC_URSEL);
	SET_BIT(UCSRC,UCSRC_UCSZ0);
	SET_BIT(UCSRC,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#endif



#if (1 == USART_INTERRUPT_ENABLED)

	SET_BIT(UCSRB,UCSRB_RXCIE);
	SET_BIT(UCSRB,UCSRB_TXCIE);
	SET_BIT(UCSRB,UCSRB_RXCIE);
    SET_BIT(UCSRB,UCSRB_UDRIE);
    
	SET_BIT(UCSRB,UCSRB_RXCIE);
	  
#elif ( 1 == USART_INTERRUPT_DISABLED)
	 CLR_BIT(UCSRB,UCSRB_RXCIE);
	 CLR_BIT(UCSRB,UCSRB_TXCIE);
	 CLR_BIT(UCSRB,UCSRB_RXCIE);
	 CLR_BIT(UCSRB,UCSRB_UDRIE);
	 
	 CLR_BIT(UCSRB,UCSRB_RXCIE);
#endif
}

void USART_TX (u8 data){
	while(GET_BIT(UCSRA,UCSRA_UDRE) == 0);
	UDR = data;
}
u8 USART_u8Recieve(void)
{
	while(GET_BIT(UCSRA,UCSRA_RXC) == 0);
	return UDR;
}

u8 UART_enuRxChar(void)
{
	
	/* Wait till data is received */
	/*polling ..*/
	while(GET_BIT( UCSRA , UCSRA_RXC )  == 0 );  //USART Receive Complete

	/* Return the byte*/
	return UDR;

}

/***************************************************/

UART_enuErrorStatus UART_enuTxChar(u8 Copy_u8Char)
{
	UART_enuErrorStatus Error = USART_NOK;

	/* Wait for empty transmit buffer*/
	/*polling ..*/
	while((GET_BIT( UCSRA , UCSRA_UDRE ) )==0 );  //USART Data Register Empty
	UDR = Copy_u8Char ;

	//SET_BIT(UCSRA ,  UCSRA_TXC); //Clr flag by set it

	Error = USART_OK;
	return(Error);
}
void UART_vidTxString(u8* StringPtr)
{
	while(*StringPtr != '\0')
	{
		UART_enuTxChar(*StringPtr);
		StringPtr++;
	}
}

/****************************************************/

void UART_vidRxString(u8 AddString[])
{
	u8 Local_u8Current =0;
	u8 Local_u8Counter =0;
	while(1)
	{
		Local_u8Current = UART_enuRxChar();
		if(Local_u8Current == '\r')
		{
			AddString[Local_u8Counter] ='\0';
			break;
		}
		else
		{
		AddString[Local_u8Counter] = Local_u8Current;
		Local_u8Counter++;
		}
	}
}
/*
void USART_ReceiveStringNEW(pu8 buffer, u8 buffer_size) {
	
	u8 i = 0;

	do {
	buffer[i] = UART_enuRxChar();
	i++;
	} while (buffer[i] != '\0' && i < buffer_size - 1);

	
	//buffer[i] = '\0';
}*/