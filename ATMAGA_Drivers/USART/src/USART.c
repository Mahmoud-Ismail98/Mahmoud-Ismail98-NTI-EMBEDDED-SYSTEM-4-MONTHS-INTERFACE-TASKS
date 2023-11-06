
 #include "../../SERVICES/Std_types.h"
#include "../../SERVICES/Bit_utils.h"
#include "USART.h"
#include "USART_prv.h"
#include "USART_cfg.h"

volatile u8  Global_u8DataToSend;
volatile u8 Global_u8DataToRecive;

void USART_voidInit(void)
{
/* Set baud rate */

UBRRL_Reg = (u8)USART_BAUD_RATE;
#if  USART_RX_STATE  == USART_RX_ENABLE  
    SET_BIT(UCSRB_Reg,UCSRB_RXEN);
#elif USART_RX_STATE  == USART_RX_DISABLE  
    CLR_BIT(UCSRB_Reg,UCSRB_RXEN);
#endif

#if  USART_TX_STATE  == USART_TX_ENABLE  
    SET_BIT(UCSRB_Reg,UCSRB_TXEN);
#elif USART_TX_STATE  == USART_TX_DISABLE 
    CLR_BIT(UCSRB_Reg,UCSRB_TXEN);
#endif

u8 Loc_u8UCSRC = 0b10000000;
/* Set frame format: 8data, 2stop bit */

#if USART_MODE_SELECT ==   USART_ASYNCH_MODE
    CLR_BIT(Loc_u8UCSRC,UCSRC_UMSEL);
#elif USART_MODE_SELECT ==   USART_SYNCH_MODE
    SET_BIT(Loc_u8UCSRC,UCSRC_UMSEL);
#endif
#if USART_PARITY_BIT_MODE == USART_PARITY_BIT_Disabled
    CLR_BIT(Loc_u8UCSRC,UCSRC_UPM0);
    CLR_BIT(Loc_u8UCSRC,UCSRC_UPM1);
#elif USART_PARITY_BIT_MODE == USART_PARITY_BIT_Enabled_EVEN
    CLR_BIT(Loc_u8UCSRC,UCSRC_UPM0);
    SET_BIT(Loc_u8UCSRC,UCSRC_UPM1);
#elif USART_PARITY_BIT_MODE == USART_PARITY_BIT_Enabled_ODD
    SET_BIT(Loc_u8UCSRC,UCSRC_UPM0);
    SET_BIT(Loc_u8UCSRC,UCSRC_UPM1);

#endif

#if USART_STOPBIT_MODE  ==USART_2STOPBIT_MODE
    SET_BIT(Loc_u8UCSRC,UCSRC_USBS);
#elif USART_STOPBIT_MODE  USART_1STOPBIT_MODE
    CLR_BIT(Loc_u8UCSRC,UCSRC_USBS);
#endif
#if USART_DATABIT_MODE == USART_5BIT_DATA_BITS
    CLR_BIT(Loc_u8UCSRC,UCSRC_UCSZ0);
    CLR_BIT(Loc_u8UCSRC,UCSRC_UCSZ1);
    CLR_BIT(UCSRB_Reg,UCSRB_UCSZ2);
#elif USART_DATABIT_MODE == USART_6BIT_DATA_BITS
    SET_BIT(Loc_u8UCSRC,UCSRC_UCSZ0);
    CLR_BIT(Loc_u8UCSRC,UCSRC_UCSZ1);
    CLR_BIT(UCSRB_Reg,UCSRB_UCSZ2);
#elif USART_DATABIT_MODE == USART_7BIT_DATA_BITS
    CLR_BIT(Loc_u8UCSRC,UCSRC_UCSZ0);
    SET_BIT(Loc_u8UCSRC,UCSRC_UCSZ1);
    CLR_BIT(UCSRB_Reg,UCSRB_UCSZ2);
#elif USART_DATABIT_MODE == USART_8BIT_DATA_BITS
    SET_BIT(Loc_u8UCSRC,UCSRC_UCSZ0);
    SET_BIT(Loc_u8UCSRC,UCSRC_UCSZ1);
    CLR_BIT(UCSRB_Reg,UCSRB_UCSZ2);
#elif USART_DATABIT_MODE == USART_9BIT_DATA_BITS
    SET_BIT(Loc_u8UCSRC,UCSRC_UCSZ0);
    SET_BIT(Loc_u8UCSRC,UCSRC_UCSZ1);
    SET_BIT(UCSRB_Reg,UCSRB_UCSZ2);

#endif

UCSRC_Reg =	Loc_u8UCSRC ;
 SET_BIT(UCSRB_Reg,UCSRB_RXCIE);
 SET_BIT(UCSRB_Reg,UCSRB_TXCIE);
}


void USART_Transmit( u8 data )
{

while ( GET_BIT( UCSRA_Reg,UCSRA_UDRE)==0 );

/* Put data into buffer, sends the data */
UDR_Reg = data;
}

u8 USART_Receive( void )
{
/* Wait for data to be received */
while ( GET_BIT( UCSRA_Reg,UCSRA_RXC)==0 );

return UDR_Reg;
}


void USART_TransmitString(pu8 str) {
    while (*str != '\0') {
       
        while ( GET_BIT( UCSRA_Reg,UCSRA_UDRE)==0 );

       
        UDR_Reg = *str;

        str++;  
    }
}


void USART_ReceiveString(pu8 buffer, u8 buffer_size) {
    u8 received_char;
    u8 index = 0;

    do {
        while ( GET_BIT( UCSRA_Reg,UCSRA_RXC)==0 );

        received_char = UDR_Reg;

        if (index < buffer_size - 1) {
            buffer[index] = received_char;
            index++;
        }
    } while (received_char != '\0' && index < buffer_size - 1);

    
    buffer[index] = '\0';
}

void USART_ASYNCH_GetData(pu8 Copy_u8RecevingData)
{
    *Copy_u8RecevingData = Global_u8DataToRecive;
}
void USART_ASYNCH_SendData(pu8 Copy_u8RecevingData)
{
    Global_u8DataToSend=*Copy_u8RecevingData ;
}






void __vector_13(void) __attribute__((signal));
void __vector_13(void) {
    UDR_Reg = Global_u8DataToSend;
}


void __vector_15(void) __attribute__((signal));
void __vector_15(void) {
    Global_u8DataToRecive = UDR_Reg;
}
