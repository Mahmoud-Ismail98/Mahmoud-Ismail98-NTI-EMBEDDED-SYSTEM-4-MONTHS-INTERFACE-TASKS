/*
 * USART.h
 *
 * Created: 10/28/2023 11:15:04 AM
 *  Author: ahmed radwan
 */ 


#ifndef USART_H_
#define USART_H_

/*************************macros section***********************************/


#define  USART_Receive_Complete()		GET_BIT(UCSRA,7)
#define  USART_Transmit_Complete()		GET_BIT(UCSRA,6)
#define  USART_Data_Register_Empty()	GET_BIT(UCSRA,5)

#define  RX_INT_ENABLE()				SET_BIT(UCSRB,7)
#define  TX_INT_ENABLE()				SET_BIT(UCSRB,6)
#define  EMPTY_INT_ENABLE()				SET_BIT(UCSRB,5)


#define  RX_MODE_ENABLE()				   SET_BIT(UCSRB,4)
#define  TX_MODE_ENABLE()				   SET_BIT(UCSRB,3)


#define  UCSRC_ACCCES()                    SET_BIT(UCSRC,7)

#define  USART_ASYN_SLECT()                CLR_BIT(UCSRC,6)

#define  UBRRH_ACCCES()                    CLR_BIT(UCSRC,7)

#define SET_BAUD_RATE()                    (UBRRL|=0x67)
#define Stop_Bit_Selec()                   SET_BIT(UCSRC,3)
#define slect_8bit()                       (UCSRC|=0x03)


/************************* macros section end ***********************************/


/*********************************** user defined data types section ***********************************/


/*********************************** user defined data types section end ***********************************/



/*****************function prototypes section*******************************************/

void USART_INT(void);
void USART_vidRECIVE_Bloking(u8 *data);
void USART_vidTRANSMIT_Blokind(u8 data);

/*****************function prototypes section end*******************************************/











#endif /* USART_H_ */