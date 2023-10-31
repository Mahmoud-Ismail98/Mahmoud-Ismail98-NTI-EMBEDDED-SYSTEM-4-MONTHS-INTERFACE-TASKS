/*****************************************************************************/
/*****************************************************************************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : USART               **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/
#include "Std_types.h"
#include "Bit_utils.h"

#include "USART.h"
#include "USART_prv.h"
#include "USART_cfg.h"


void USART_voidInit(){

    u8 Local_u8WriteToUCSRC = 0b10000000;


// init Baud Rate
    // enable receiver 
    SET_BIT(UCSRB,RXEN);
    // enable transmitter 
    SET_BIT(UCSRB,TXEN);

    // initialize character size (8 bit data)
    CLR_BIT(UCSRB, UCSZ2);
    SET_BIT(Local_u8WriteToUCSRC, UCSZ1);
    SET_BIT(Local_u8WriteToUCSRC, UCSZ0);
    
    // select Asynchronous mode 
    CLR_BIT(Local_u8WriteToUCSRC, UMSEL);

    // select Parity (even)
    SET_BIT(Local_u8WriteToUCSRC, UPM1);
    CLR_BIT(Local_u8WriteToUCSRC, UPM0);
    
    // select number of stop bits (1 bit)
    CLR_BIT(Local_u8WriteToUCSRC, USBS);

    // writing to the UCSRC
    UCSRC = Local_u8WriteToUCSRC;

    // should be 103
    u16 Local_u16UBRR_VALUE = (CPU_FREQ/ (16*BAUD_RATE) ) -1 ;

    UBRRH = Local_u16UBRR_VALUE >> 8 ;
     
    UBRRL = (u8)Local_u16UBRR_VALUE;

}

void USART_voidSendData(u16 Copy_u16Data){
    while(GET_BIT(UCSRA, UDRE) == 0);
    UDR = Copy_u16Data;
    while(GET_BIT(UCSRA, TXC) == 0);
    // clear the flag
    SET_BIT(UCSRA, TXC);
}

u16 USART_u16ReceiveData(pu8 Copy_u8Value){
    while(GET_BIT(UCSRA, RXC) == 0);
    *Copy_u8Value = UDR;
    return UDR;
}

