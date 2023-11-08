/*
 * UART.c
 *
 * Created: 10/28/2023 1:48:50 PM
 *  Author: sharb
 */ 


#include "../UART_Includes/UART_PRV.h"

USART_cfg_t g_USART_cfg = {0};
	
void (*gl_ptr_Transmit)(void) = PTR_NULL;
void (*gl_ptr_recieve)(void) = PTR_NULL;


void USART_init(USART_cfg_t* ptr_USART_cfg)
{
	u16 BaudCalculation = FALSE;
	
	g_USART_cfg = *ptr_USART_cfg;
	if (ptr_USART_cfg == PTR_NULL)
	{
		// invalid input
	}
	else
	{
		//select UCSRC
		SET_BIT(UCSRC,URSEL);
		//configure mode
		CLR_BIT(UCSRC, UMSEL);
		if ( g_USART_cfg.selectMode == USART_Mode_DoubleASynchronous)
		{
			UCSRC |= (USART_Mode_NormalAsynchronous << UMSEL);
			SET_BIT(UCSRA,U2X);
			BaudCalculation = ((F_CPU/(8UL*g_USART_cfg.BaudRate))-1);
		}
		else if (g_USART_cfg.selectMode == USART_Mode_NormalAsynchronous)
		{
			UCSRC |= (USART_Mode_NormalAsynchronous << UMSEL);
			BaudCalculation = ((F_CPU/(16UL*g_USART_cfg.BaudRate))-1);
		}
		else
		{
			UCSRC |= (g_USART_cfg.selectMode << UMSEL);
		}
		
		//configure databits size
		switch(g_USART_cfg.DataBits)
		{
			case USART_DataBits5: 
			CLR_BIT(UCSRC,UCSZ0);
			CLR_BIT(UCSRC,UCSZ1);
			CLR_BIT(UCSRB,UCSZ2);
			break;				
			case USART_DataBits6:
			SET_BIT(UCSRC,UCSZ0);
			CLR_BIT(UCSRC,UCSZ1);
			CLR_BIT(UCSRB,UCSZ2);
			break;				
			case USART_DataBits7:
			CLR_BIT(UCSRC,UCSZ0);
			SET_BIT(UCSRC,UCSZ1);
			CLR_BIT(UCSRB,UCSZ2);
			break;				
			case USART_DataBits8:
			SET_BIT(UCSRC,UCSZ0);
			SET_BIT(UCSRC,UCSZ1);
			CLR_BIT(UCSRB,UCSZ2);
			break;				
			case USART_DataBits9:
			SET_BIT(UCSRC,UCSZ0);
			SET_BIT(UCSRC,UCSZ1);
			CLR_BIT(UCSRB,UCSZ2);
			break;
			//handle error of data bits
			default:break;
			
		}
		//configure stop bits
		CLR_BIT(UCSRC, USBS);
		UCSRC |= (g_USART_cfg.stopBits << USBS);
		
		//configure parity
		UCSRC &= ~(3 << UPM0);
		UCSRC |= (g_USART_cfg.parityState << UPM0);
		
		//configure baudrate
		UBRRL = (0xFF&BaudCalculation);
		UBRRH = (BaudCalculation>>8);
		
		
		// store call backs
		
		gl_ptr_recieve  = g_USART_cfg.ptrfuncRec;
		gl_ptr_Transmit = g_USART_cfg.ptrfuncSend;
		// ENABLE tx and Rx
		
		SET_BIT(UCSRB,RXEN);
		SET_BIT(UCSRB,TXEN);
		
	}
}

void USART_Enable_Interrupt(u8 Interrupt_Type)
{
	switch(Interrupt_Type)
	{
		case USART_INT_Tx:
		SET_BIT(UCSRB, TXCIE);
		break;
		case USART_INT_Rx:
		SET_BIT(UCSRB, RXCIE);
		break;
	}
}
void USART_Disable_Interrupt(u8 Interrupt_Type)
{
	switch(Interrupt_Type)
	{
		case USART_INT_Tx:
		CLR_BIT(UCSRB, TXCIE);
		break;
		case USART_INT_Rx:
		CLR_BIT(UCSRB, RXCIE);
		break;
	}	
}

void USART_TransmitChar(u8 arg_u8_char)
{
	while(!GET_BIT(UCSRA, UDRE));
	UDR = arg_u8_char;
}
void USART_RecieveChar(u8 *ptr_u8_char)
{
	while(!GET_BIT(UCSRA, RXC));
	*ptr_u8_char = UDR ;
}
void USART_TransmitString(u8 *ptr_u8_string)
{
	u8 loc_u8_itrator = FALSE;
	while(ptr_u8_string[loc_u8_itrator] != '\0')
	{
		USART_TransmitChar(ptr_u8_string[loc_u8_itrator++]);
	}
	USART_TransmitChar('\0');
}
void USART_RecieveString(u8 *ptr_u8_string)
{
	u8 loc_u8_temp    = 0;
	u8 loc_u8_itrator = 0;
	while(loc_u8_temp != 13)
	{
		USART_RecieveChar(&loc_u8_temp);
		ptr_u8_string[loc_u8_itrator++] = loc_u8_temp ;
	}
	ptr_u8_string[--loc_u8_itrator] = 0;
}

ISR(USART_RXC_INT)
{
	if(gl_ptr_recieve != PTR_NULL)
	{
		gl_ptr_recieve();
	}
}