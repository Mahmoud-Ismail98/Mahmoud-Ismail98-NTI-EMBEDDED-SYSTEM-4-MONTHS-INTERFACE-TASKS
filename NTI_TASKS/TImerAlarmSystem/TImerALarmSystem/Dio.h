

#ifndef MCAL_DIO_DRIVER_DIO_H_
#define MCAL_DIO_DRIVER_DIO_H_

#include"Std_types.h"

#define	DIO_u8PORTA 				0
#define	DIO_u8PORTB 				1
#define	DIO_u8PORTC 				2
#define	DIO_u8PORTD 				3

/*ENUM*/
typedef enum {
Dio_enuOk,
Dio_enuChannelError,
Dio_enuLevelError,
Dio_enuDirectionError,
Dio_enuNullPointerError,
Dio_enuPortRangeError
}Dio_tenuErrorStatus;

/*MACROS*/
#define DIO_u8LEVEL_HIGH 	1
#define DIO_u8LEVEL_LOW 	0

/*PORTA*/
#define DIO_u8CHANNEL00            0
#define DIO_u8CHANNEL01            1
#define DIO_u8CHANNEL02            2
#define DIO_u8CHANNEL03            3
#define DIO_u8CHANNEL04            4
#define DIO_u8CHANNEL05            5
#define DIO_u8CHANNEL06            6
#define DIO_u8CHANNEL07            7
/*PORTB*/
#define DIO_u8CHANNEL08            8
#define DIO_u8CHANNEL09            9
#define DIO_u8CHANNEL10            10
#define DIO_u8CHANNEL11            11
#define DIO_u8CHANNEL12            12
#define DIO_u8CHANNEL13            13
#define DIO_u8CHANNEL14            14
#define DIO_u8CHANNEL15            15

/*PORTC*/
#define DIO_u8CHANNEL16            16
#define DIO_u8CHANNEL17            17
#define DIO_u8CHANNEL18            18
#define DIO_u8CHANNEL19            19
#define DIO_u8CHANNEL20            20
#define DIO_u8CHANNEL21            21
#define DIO_u8CHANNEL22            22
#define DIO_u8CHANNEL23            23

/*PORTD*/
#define DIO_u8CHANNEL24            24
#define DIO_u8CHANNEL25            25
#define DIO_u8CHANNEL26            26
#define DIO_u8CHANNEL27            27
#define DIO_u8CHANNEL28            28
#define DIO_u8CHANNEL29            29
#define DIO_u8CHANNEL30            30
#define DIO_u8CHANNEL31            31


/*PROTOTYPES*/
Dio_tenuErrorStatus  Dio_enuWriteChannel(u8 Copy_u8ChannelId , u8 Copy_u8Level);
Dio_tenuErrorStatus  Dio_enuReadChannel(u8 Copy_u8ChannelId , pu8 Add_pu8ChannelLevel);
Dio_tenuErrorStatus  Dio_enuWritePort(u8 Copy_u8PortId , u8 Copy_u8Value);
Dio_tenuErrorStatus  Dio_enuReadPort(u8 Copy_u8PortId , pu8 Add_pu8PortValue);
Dio_tenuErrorStatus  Dio_enuFlipChannel(u8 Copy_u8ChannelId );


#endif /* MCAL_DIO_DRIVER_DIO_H_ */
