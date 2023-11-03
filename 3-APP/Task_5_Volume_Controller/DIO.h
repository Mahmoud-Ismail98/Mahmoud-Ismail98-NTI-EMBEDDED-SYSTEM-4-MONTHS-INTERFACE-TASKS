/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : DIO                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef DIO_H
#define DIO_H


/* defining PORT A ID and his channels */
#define PORTA_ID                            0
#define PORT_A_CHANNEL_0                    0
#define PORT_A_CHANNEL_1                    1
#define PORT_A_CHANNEL_2                    2
#define PORT_A_CHANNEL_3                    3
#define PORT_A_CHANNEL_4                    4
#define PORT_A_CHANNEL_5                    5
#define PORT_A_CHANNEL_6                    6
#define PORT_A_CHANNEL_7                    7

/* defining PORT A ID and his channels */
#define PORTB_ID                            1
#define PORT_B_CHANNEL_0                    8
#define PORT_B_CHANNEL_1                    9
#define PORT_B_CHANNEL_2                    10
#define PORT_B_CHANNEL_3                    11
#define PORT_B_CHANNEL_4                    12
#define PORT_B_CHANNEL_5                    13
#define PORT_B_CHANNEL_6                    14
#define PORT_B_CHANNEL_7                    15

/* defining PORT A ID and his channels */
#define PORTC_ID                            2
#define PORT_C_CHANNEL_0                    16
#define PORT_C_CHANNEL_1                    17
#define PORT_C_CHANNEL_2                    18
#define PORT_C_CHANNEL_3                    19
#define PORT_C_CHANNEL_4                    20
#define PORT_C_CHANNEL_5                    21
#define PORT_C_CHANNEL_6                    22
#define PORT_C_CHANNEL_7                    23

/* defining PORT A ID and his channels */
#define PORTD_ID                            3
#define PORT_D_CHANNEL_0                    24
#define PORT_D_CHANNEL_1                    25
#define PORT_D_CHANNEL_2                    26
#define PORT_D_CHANNEL_3                    27
#define PORT_D_CHANNEL_4                    28
#define PORT_D_CHANNEL_5                    29
#define PORT_D_CHANNEL_6                    30
#define PORT_D_CHANNEL_7                    31

#define DIO_CHANNEL_LEVEL_LOW               0
#define DIO_CHANNEL_LEVEL_HIGH              1

/**
 * This function is used to set the level of a specific pin in the port. 
 * 
 * @param Copy_u8ChannelId which represents the pin number.
 * 
 * @param Copy_u8Level which represents the desired level for the pin. 
 * 
 * @return a value which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus DIO_enuWriteChannel(u8 Copy_u8ChannelId, u8 Copy_u8Level);

/**
 * This function is used to read the level of a specific pin in the port. 
 * 
 * @param Copy_u8ChannelId which represents the pin number.
 * 
 * @param Add_pu8ChannelLevel which is a pointer to a u8 to save the current pin level. 
 * 
 * @return a value which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus DIO_enuReadChannel(u8 Copy_u8ChannelId, pu8 Add_pu8ChannelLevel);

/**
 * This function is used to set the level for a full port . 
 * 
 * @param Copy_u8PortId indicates which port we want change it's value.
 * 
 * @param Copy_u8Value the value to be copped to the specific port. 
 * 
 * @return a value which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus DIO_enuWritePort(u8 Copy_u8PortId,u8 Copy_u8Value);

/**
 * This function is used to read the level of a specific port. 
 * 
 * @param Copy_u8PortId which represents the port we want read it's value.
 * 
 * @param Add_pu8PortValue which is a pointer to a u8 to save the current port value. 
 * 
 * @return a value which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus DIO_enuReadPort(u8 Copy_u8PortId, pu8 Add_pu8PortValue);

/**
 * This function is used to flip the level of a specific pin. 
 * 
 * @param Copy_u8ChannelId which represents the pin we want flip it's level.
 * 
 * @return a value which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus DIO_enuFlipChannel(u8 Copy_u8ChannelId);

#endif
