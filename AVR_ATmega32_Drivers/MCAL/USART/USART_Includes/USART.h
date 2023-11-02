/*
 * UART.h
 *
 * Created: 10/27/2023 7:28:35 AM
 *  Author: computer store
 */ 


#ifndef USART_H_
#define USART_H_

#include "Services/std_types.h"
typedef struct 
{
	uint8  selectMode;
	uint8  parityState;
	uint8  stopBits;
	uint8  DataBits;
	uint16 BaudRate;
	void(*ptrfuncSend)(void);
	void(*ptrfuncRec)(void);
	
}USART_cfg_t;

//==========================================================
//Configuration Macros 
//==========================================================

//@ref USART_selectMode
#define USART_Mode_NormalAsynchronous		((uint8)0)
#define USART_Mode_Synchronous		        ((uint8)1)
#define USART_Mode_DoubleASynchronous		((uint8)2)


//@ref USART_parityState
#define USART_No_Parity						((uint8)0)		
#define USART_Odd_Parity					((uint8)2)
#define USART_Even_Parity					((uint8)3)


//@ref USART_stopBits
#define USART_stopBits1						((uint8)0)
#define USART_stopBits2						((uint8)1)

//@ref USART_DataBits
#define USART_DataBits5						((uint8)0)
#define USART_DataBits6						((uint8)1)
#define USART_DataBits7						((uint8)2)
#define USART_DataBits8						((uint8)3)
#define USART_DataBits9						((uint8)4)

//@ref USART_DataBits
#define USART_BAUD_2400						((uint16)2400)
#define USART_BAUD_4800						((uint16)4800)
#define USART_BAUD_9600						((uint16)9600)
#define USART_BAUD_14400				    ((uint16)14400)
#define USART_BAUD_19200				    ((uint16)19200)



#define USART_INT_Rx						((uint8)0)
#define USART_INT_Tx						((uint8)1)


//==========================================================
//ApIs_Prototypes Macros
//==========================================================
void USART_init(USART_cfg_t* ptr_USART_cfg);
void USART_Enable_Interrupt(uint8 Interrupt_Type);
void USART_Disable_Interrupt(uint8 Interrupt_Type);
void USART_TransmitChar(uint8 arg_u8_char);
void USART_RecieveChar(uint8 *ptr_u8_char);
void USART_TransmitString(uint8 *ptr_u8_string);
void USART_RecieveString(uint8 *ptr_u8_string);
#endif /* UART_H_ */