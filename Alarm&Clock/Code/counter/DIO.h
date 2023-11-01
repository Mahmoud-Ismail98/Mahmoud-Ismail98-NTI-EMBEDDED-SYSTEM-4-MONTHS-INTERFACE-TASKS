/*
 * DIO.h
 *
 * Created: 10/20/2023 11:58:38 AM
 *  Author: FADY
 */ 


#ifndef DIO_H_
#define DIO_H_

/*PORTA*/
#define DIO_CHANNEL_0       0
#define DIO_CHANNEL_1       1
#define DIO_CHANNEL_2       2
#define DIO_CHANNEL_3       3
#define DIO_CHANNEL_4       4
#define DIO_CHANNEL_5       5
#define DIO_CHANNEL_6       6
#define DIO_CHANNEL_7       7
/*PORTB*/
#define DIO_CHANNEL_8       8
#define DIO_CHANNEL_9       9       
#define DIO_CHANNEL_10      10      
#define DIO_CHANNEL_11      11      
#define DIO_CHANNEL_12      12
#define DIO_CHANNEL_13      13
#define DIO_CHANNEL_14      14
#define DIO_CHANNEL_15      15
/*PORTC*/
#define DIO_CHANNEL_16      16
#define DIO_CHANNEL_17      17
#define DIO_CHANNEL_18      18
#define DIO_CHANNEL_19      19
#define DIO_CHANNEL_20      20
#define DIO_CHANNEL_21      21
#define DIO_CHANNEL_22      22
#define DIO_CHANNEL_23      23
/*PORTD*/
#define DIO_CHANNEL_24      24
#define DIO_CHANNEL_25      25
#define DIO_CHANNEL_26      26
#define DIO_CHANNEL_27      27
#define DIO_CHANNEL_28      28
#define DIO_CHANNEL_29      29
#define DIO_CHANNEL_30      30
#define DIO_CHANNEL_31      31


#define DIO_PORT_OUTPUT       0xFF
#define DIO_PORT_INPUT        0x0-

#define DIO_PORT_HIGH 	      0xFF
#define DIO_PORT_LOW	      0x00

#define DIO_CHANNEL_OUTPUT        1
#define DIO_CHANNEL_INPUT         0

#define DIO_CHANNEL_HIGH 	      1
#define DIO_CHANNEL_LOW	          0

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

typedef enum DIO_tenuErrorStatus  {
	DIO_WRONGCHANNEL,      
	DIO_WRONGLEVEL,        
	DIO_WRONGPORT,         
	DIO_NULLPTR,          
	DIO_OK,               
	DIO_WRONGDIR           
}DIO_tenuErrorStatus;





DIO_tenuErrorStatus DIO_enuWriteChannel(u8 Copy_u8ChannelId , u8 Copy_u8Level);
DIO_tenuErrorStatus DIO_enuReadChannel(u8 Copy_u8ChannelId , pu8 Add_Pu8ChannelLevel);
DIO_tenuErrorStatus Dio_enuWritePort(u8 Copy_u8PortId , u8 Copy_u8Level);
DIO_tenuErrorStatus DIO_enuFlipChannel(u8 Copy_u8ChannelId );

/* PROTOTYPES*/
#endif /* DIO_H_ */