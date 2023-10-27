/*
 * DIO.h
 *
 * Created: 10/20/2023 12:00:02 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef DIO_H_
#define DIO_H_
/*PORTA*/
#define DIO_Channel00    0
#define DIO_Channel01    1
#define DIO_Channel02    2
#define DIO_Channel03    3
#define DIO_Channel04    4
#define DIO_Channel05    5
#define DIO_Channel06    6
#define DIO_Channel07    7
/*PORTB*/
#define DIO_Channel08    8
#define DIO_Channel09    9
#define DIO_Channel10    10
#define DIO_Channel11    11
#define DIO_Channel12    12
#define DIO_Channel13    13
#define DIO_Channel14    14
#define DIO_Channel15    15
/*PORTC*/
#define DIO_Channel16    16
#define DIO_Channel17    17
#define DIO_Channel18    18
#define DIO_Channel19    19
#define DIO_Channel20    20
#define DIO_Channel21    21
#define DIO_Channel22    22
#define DIO_Channel23    23
/*PORTD*/
#define DIO_Channel23    23
#define DIO_Channel24    24
#define DIO_Channel25    25
#define DIO_Channel26    26
#define DIO_Channel27    27
#define DIO_Channel28    28
#define DIO_Channel29    29
#define DIO_Channel30    30
#define DIO_Channel31    31

/*DIO Ports */
#define	DIO_PORTA 				0
#define	DIO_PORTB 				1
#define	DIO_PORTC 				2
#define	DIO_PORTD 				3

#define DIO_HIGH  1
#define DIO_LOW   0
#define DIO_OUTPUT 1
#define DIO_INPUT 0
typedef enum{
	DIO_Status_Ok,
	DIO_Status_Fail,
	DIO_Pin_NO_ERR,
	DIO_PORT_NO_ERR,
	DIO_Logic_Level_ERR,
	DIO_Direction_ERR,
	DIO_Null_ptr_ERR
	
	
}DIO_enuErrorStatus;


/*Function ProtoTypes*/

DIO_enuErrorStatus DIO_enuWriteChannel (u8 copy_u8ChannelId    ,u8 copy_u8Level);
DIO_enuErrorStatus DIO_enuReadChannel  (u8 copy_u8ChannelId    ,u8 Add_pu8ChannelLevel);
DIO_enuErrorStatus DIO_enuWritePort    (u8 copy_u8PortId       ,u8 copy_Value);
DIO_enuErrorStatus DIO_enuReadPort     (u8 copy_u8ChannelId    ,pu8 Add_pu8PortValue);
DIO_enuErrorStatus DIO_enuFlipChannel  (u8 copy_u8ChannelId);







#endif /* DIO_H_ */