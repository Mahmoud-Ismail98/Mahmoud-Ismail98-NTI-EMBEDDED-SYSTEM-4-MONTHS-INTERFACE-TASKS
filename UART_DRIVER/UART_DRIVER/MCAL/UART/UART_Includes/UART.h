/*
 * UART.h
 *
 * Created: 10/27/2023 7:28:35 AM
 *  Author: sharb
 */ 


#ifndef UART_H_
#define UART_H_

#include "std_types.h"
typedef struct 
{
	u8  selectMode;
	u8  parityState;
	u8  stopBits;
	u8  DataBits;
	u16 BaudRate;
	void(*ptrfuncSend)(void);
	void(*ptrfuncRec)(void);
	
}USART_cfg_t;

//==========================================================
//Configuration Macros 
//==========================================================

//@ref USART_selectMode
#define USART_Mode_NormalAsynchronous		((u8)0)
#define USART_Mode_Synchronous		        ((u8)1)
#define USART_Mode_DoubleASynchronous		((u8)2)


//@ref USART_parityState
#define USART_No_Parity						((u8)0)		
#define USART_Odd_Parity					((u8)2)
#define USART_Even_Parity					((u8)3)


//@ref USART_stopBits
#define USART_stopBits1						((u8)0)
#define USART_stopBits2						((u8)1)

//@ref USART_DataBits
#define USART_DataBits5						((u8)0)
#define USART_DataBits6						((u8)1)
#define USART_DataBits7						((u8)2)
#define USART_DataBits8						((u8)3)
#define USART_DataBits9						((u8)4)

//@ref USART_DataBits
#define USART_BAUD_2400						((u16)2400)
#define USART_BAUD_4800						((u16)4800)
#define USART_BAUD_9600						((u16)9600)
#define USART_BAUD_14400				    ((u16)14400)
#define USART_BAUD_19200				    ((u16)19200)



#define USART_INT_Rx						((u8)0)
#define USART_INT_Tx						((u8)1)


//==========================================================
//ApIs_Prototypes Macros
//==========================================================
void USART_init(USART_cfg_t* ptr_USART_cfg);
void USART_Enable_Interrupt(u8 Interrupt_Type);
void USART_Disable_Interrupt(u8 Interrupt_Type);
void USART_TransmitChar(u8 arg_u8_char);
void USART_RecieveChar(u8 *ptr_u8_char);
void USART_TransmitString(u8 *ptr_u8_string);
void USART_RecieveString(u8 *ptr_u8_string);
#endif /* UART_H_ */