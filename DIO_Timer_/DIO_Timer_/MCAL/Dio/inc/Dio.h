/*
 * Dio.h
 *
 *  Created on: Mar 4, 2022
 *      Author: MahmoudElImbabi
 */

#ifndef MCAL_DIO_DRIVER_DIO_H_
#define MCAL_DIO_DRIVER_DIO_H_
#include"Std_types.h"	 /*INCLUDING "Std_types.h" HEADER FILE */

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

#define DIO_u8OUTPUT				1
#define DIO_u8INPUT					0


/*PORT ID OPTIONS */
#define	DIO_u8PORTA 				0
#define	DIO_u8PORTB 				1
#define	DIO_u8PORTC 				2
#define	DIO_u8PORTD 				3



/*PORTA*/
#define DIO_u8CHANNEL00            0	//0
#define DIO_u8CHANNEL01            1	//1
#define DIO_u8CHANNEL02            2	//2
#define DIO_u8CHANNEL03            3	//3
#define DIO_u8CHANNEL04            4	//4
#define DIO_u8CHANNEL05            5	//5
#define DIO_u8CHANNEL06            6	//6
#define DIO_u8CHANNEL07            7	//7
/*PORTB*/
#define DIO_u8CHANNEL08            8    //0
#define DIO_u8CHANNEL09            9	//1
#define DIO_u8CHANNEL10            10	//2
#define DIO_u8CHANNEL11            11	//3
#define DIO_u8CHANNEL12            12	//4
#define DIO_u8CHANNEL13            13	//5
#define DIO_u8CHANNEL14            14	//6
#define DIO_u8CHANNEL15            15	//7

/*PORTC*/
#define DIO_u8CHANNEL16            16	//0
#define DIO_u8CHANNEL17            17	//1
#define DIO_u8CHANNEL18            18	//2
#define DIO_u8CHANNEL19            19	//3
#define DIO_u8CHANNEL20            20	//4
#define DIO_u8CHANNEL21            21	//5
#define DIO_u8CHANNEL22            22	//6
#define DIO_u8CHANNEL23            23	//7

/*PORTD*/
#define DIO_u8CHANNEL24            24	//0
#define DIO_u8CHANNEL25            25	//1
#define DIO_u8CHANNEL26            26	//2
#define DIO_u8CHANNEL27            27	//3
#define DIO_u8CHANNEL28            28	//4
#define DIO_u8CHANNEL29            29	//5
#define DIO_u8CHANNEL30            30	//6
#define DIO_u8CHANNEL31            31	//7


/*PROTOTYPES*/
Dio_tenuErrorStatus  Dio_enuWriteChannel(u8 Copy_u8ChannelId , u8 Copy_u8Level);
Dio_tenuErrorStatus  Dio_enuReadChannel(u8 Copy_u8ChannelId , pu8 Add_pu8ChannelLevel);
Dio_tenuErrorStatus  Dio_enuWritePort(u8 Copy_u8PortId , u8 Copy_u8Value);
Dio_tenuErrorStatus  Dio_enuReadPort(u8 Copy_u8PortId , pu8 Add_pu8PortValue);
Dio_tenuErrorStatus  Dio_enuFlipChannel(u8 Copy_u8ChannelId );


#endif /* MCAL_DIO_DRIVER_DIO_H_ */
