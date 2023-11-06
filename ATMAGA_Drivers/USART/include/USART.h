/

#ifndef USART_H_
#define USART_H_



#define USART_5BIT_DATA_BITS    0   
#define USART_6BIT_DATA_BITS    1
#define USART_7BIT_DATA_BITS    2
#define USART_8BIT_DATA_BITS    3
#define USART_9BIT_DATA_BITS    4

#define USART_RX_DISABLE     0
#define USART_RX_ENABLE      1

#define USART_TX_DISABLE     0
#define USART_TX_ENABLE      1

#define USART_1STOPBIT_MODE   0
#define USART_2STOPBIT_MODE   1



#define USART_ASYNCH_MODE  0
#define USART_SYNCH_MODE   1

#define USART_PARITY_BIT_Disabled         0
#define USART_PARITY_BIT_Enabled_EVEN     1
#define USART_PARITY_BIT_Enabled_ODD      2



#define USART_BAUDRATE_2400         416
#define USART_BAUDRATE_4800         208 
#define USART_BAUDRATE_9600         104 
#define USART_BAUDRATE_14_4k        34 
#define USART_BAUDRATE_19_2k        52

void USART_voidInit(void);
void USART_Transmit( u8 data );
u8 USART_Receive( void );
void USART_TransmitString(pu8 str);
void USART_ReceiveString(pu8 buffer, u8 buffer_size);
void USART_ASYNCH_GetData(pu8 Copy_u8RecevingData);
void USART_ASYNCH_SendData(pu8 Copy_u8RecevingData);

#endif /* USART_H_ */