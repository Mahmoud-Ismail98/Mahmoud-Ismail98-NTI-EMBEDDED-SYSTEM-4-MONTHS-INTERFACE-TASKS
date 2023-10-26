

#ifndef DIO_H_
#define DIO_H_

#include"Std_types.h"
   
   /* DIO PORTS */
#define	DIO_u8PORTA 				0
#define	DIO_u8PORTB 				1
#define	DIO_u8PORTC 				2
#define	DIO_u8PORTD 				3

 /* Return Errors*/
typedef enum {
Dio_enuOk,
Dio_enuChannelError,
Dio_enuLevelError,
Dio_enuDirectionError,
Dio_enuNullPointerError,
Dio_enuPortRangeError
}Dio_tenuErrorStatus;

    /*DIO_LEVELS*/
#define DIO_u8LEVEL_HIGH 	1
#define DIO_u8LEVEL_LOW 	0

/*PORTA_PINS*/
#define DIO_u8PORTA_CHANNEL00            0
#define DIO_u8PORTA_CHANNEL01            1
#define DIO_u8PORTA_CHANNEL02            2
#define DIO_u8PORTA_CHANNEL03            3
#define DIO_u8PORTA_CHANNEL04            4
#define DIO_u8PORTA_CHANNEL05            5
#define DIO_u8PORTA_CHANNEL06            6
#define DIO_u8PORTA_CHANNEL07            7




/*PORTB_PINS*/
#define DIO_uPORTB_CHANNEL08            8
#define DIO_uPORTB_CHANNEL09            9
#define DIO_uPORTB_CHANNEL10            10
#define DIO_uPORTB_CHANNEL11            11
#define DIO_uPORTB_CHANNEL12            12
#define DIO_uPORTB_CHANNEL13            13
#define DIO_uPORTB_CHANNEL14            14
#define DIO_uPORTB_CHANNEL15            15

/*PORTC_PINS*/
#define DIO_u8PORTC_CHANNEL16            16
#define DIO_u8PORTC_CHANNEL17            17
#define DIO_u8PORTC_CHANNEL18            18
#define DIO_u8PORTC_CHANNEL19            19
#define DIO_u8PORTC_CHANNEL20            20
#define DIO_u8PORTC_CHANNEL21            21
#define DIO_u8PORTC_CHANNEL22            22
#define DIO_u8PORTC_CHANNEL23            23

/*PORTD_PINS*/
#define DIO_u8PORTD_CHANNEL24            24
#define DIO_u8PORTD_CHANNEL25            25
#define DIO_u8PORTD_CHANNEL26            26
#define DIO_u8PORTD_CHANNEL27            27
#define DIO_u8PORTD_CHANNEL28            28
#define DIO_u8PORTD_CHANNEL29            29
#define DIO_u8PORTD_CHANNEL30            30
#define DIO_u8PORTD_CHANNEL31            31










                             /*PROTOTYPES*/

Dio_tenuErrorStatus  Dio_enuWriteChannel(u8 Copy_u8ChannelId , u8 Copy_u8Level);
Dio_tenuErrorStatus  Dio_enuReadChannel(u8 Copy_u8ChannelId , pu8 Add_pu8ChannelLevel);
Dio_tenuErrorStatus  Dio_enuWritePort(u8 Copy_u8PortId , u8 Copy_u8Value);
Dio_tenuErrorStatus  Dio_enuReadPort(u8 Copy_u8PortId , pu8 Add_pu8PortValue);
Dio_tenuErrorStatus  Dio_enuFlipChannel(u8 Copy_u8ChannelId );


#endif /* MCAL_DIO_DRIVER_DIO_H_ */
