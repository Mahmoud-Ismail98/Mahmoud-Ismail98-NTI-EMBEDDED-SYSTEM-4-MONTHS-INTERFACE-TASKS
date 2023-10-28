/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : PORT                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef PORT_H
#define PORT_H

/* defining modes of the pins in the port driver. */ 
#define PORT_MODE_OUTPUT_LOW            0
#define PORT_MODE_OUTPUT_HIGH           1
#define PORT_MODE_INPUT_FLOATING        2
#define PORT_MODE_INPUT_PULLUP          3

/* defining Pins IDs for Port A*/
#define PORT_A_PIN_0                    0
#define PORT_A_PIN_1                    1
#define PORT_A_PIN_2                    2
#define PORT_A_PIN_3                    3
#define PORT_A_PIN_4                    4
#define PORT_A_PIN_5                    5
#define PORT_A_PIN_6                    6
#define PORT_A_PIN_7                    7

/* defining Pins IDs for Port B*/
#define PORT_B_PIN_0                    8
#define PORT_B_PIN_1                    9
#define PORT_B_PIN_2                    10
#define PORT_B_PIN_3                    11
#define PORT_B_PIN_4                    12
#define PORT_B_PIN_5                    13
#define PORT_B_PIN_6                    14
#define PORT_B_PIN_7                    15

/* defining Pins IDs for Port C*/
#define PORT_C_PIN_0                    16
#define PORT_C_PIN_1                    17
#define PORT_C_PIN_2                    18
#define PORT_C_PIN_3                    19
#define PORT_C_PIN_4                    20
#define PORT_C_PIN_5                    21
#define PORT_C_PIN_6                    22
#define PORT_C_PIN_7                    23

/* defining Pins IDs for Port D*/
#define PORT_D_PIN_0                    24
#define PORT_D_PIN_1                    25
#define PORT_D_PIN_2                    26
#define PORT_D_PIN_3                    27
#define PORT_D_PIN_4                    28
#define PORT_D_PIN_5                    29
#define PORT_D_PIN_6                    30
#define PORT_D_PIN_7                    31


#define PORT_directionInput             0
#define PORT_directionOutput            1

#define PORT_ModeLow                    0
#define PORT_ModeHigh                   1
#define PORT_ModeFloating               2
#define PORT_ModePullUp                 3


/**
* this function is used to initialize the port module. 
* It sets the initial configuration for all the pins in the port. 

* @return: a value which indicates whether the initialization was successful or if there was an error.
*/
tenuErrorStatus PORT_enuInit();

/**
 * This function is used to set the mode of a specific pin in the port. 
 * 
 * @param Copy_u8PinNum which represents the pin number.
 * 
 * @param Copy_u8PinMode which represents the desired mode for the pin. 
 * 
 * @return a value which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus PORT_enuSetPinMode(u8 Copy_u8PinNum, u8 Copy_u8PinMode);

/**
 * This function is used to set the direction of a specific pin in the port. 
 * 
 * @param Copy_u8PinNum which represents the pin number.
 * 
 * @param Copy_u8PinMode which represents the desired mode for the pin. 
 * 
 * @return a value which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus PORT_enuSetPinDirection(u8 Copy_u8PinNum, u8 Copy_u8PinDirection);


#endif
