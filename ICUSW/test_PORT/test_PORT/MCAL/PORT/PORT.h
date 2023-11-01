/*
 * PORT.h
 *
 * Created: 10/20/2023 11:58:38 AM
 *  Author: FADY
 */

#ifndef PORT_H_
#define PORT_H_



#define PORT_OUTPUT_LOW         0
#define PORT_OUTPUT_HIGH        1
#define PORT_INPUT_FLOATING     2
#define PORT_INPUT_PULLUP       3


#define PORT_PORTA 0
#define PORT_PORTB 1
#define PORT_PORTC 2
#define PORT_PORTD 3

/*PORTA PINS*/
#define PORT_PIN_0              0
#define PORT_PIN_1              1
#define PORT_PIN_2              2
#define PORT_PIN_3              3
#define PORT_PIN_4              4
#define PORT_PIN_5              5
#define PORT_PIN_6              6
#define PORT_PIN_7              7
/*PORTB PINS*/
#define PORT_PIN_8              8
#define PORT_PIN_9              9
#define PORT_PIN_10             10
#define PORT_PIN_11             11
#define PORT_PIN_12             12
#define PORT_PIN_13             13
#define PORT_PIN_14             14
#define PORT_PIN_15             15
/*PORTC PINS*/
#define PORT_PIN_16             16
#define PORT_PIN_17             17
#define PORT_PIN_18             18
#define PORT_PIN_19             19
#define PORT_PIN_20             20
#define PORT_PIN_21             21
#define PORT_PIN_22             22
#define PORT_PIN_23             23
/*PORTD PINS*/
#define PORT_PIN_24             24
#define PORT_PIN_25             25
#define PORT_PIN_26             26
#define PORT_PIN_27             27
#define PORT_PIN_28             28
#define PORT_PIN_29             29
#define PORT_PIN_30             30
#define PORT_PIN_31             31


#define PORT_OUTPUT        0
#define PORT_INPUT         1





typedef enum PORT_tenuErrorStatus {
    PORT_WRONGPIN,
    PORT_WRONGDIRECTION,
    PORT_WRONGMODE,
    PORT_OK,
} PORT_tenuErrorStatus;

/* PROTOTYPES */
void PORT_VoidInit(void);
PORT_tenuErrorStatus Port_enuSetPinMode(u8 Copy_u8PinNum,u8 Copy_u8PinMode);
PORT_tenuErrorStatus Port_enuSetPinDirection(u8 Copy_u8PinNum,u8 Copy_u8PinDirection);

#endif 
