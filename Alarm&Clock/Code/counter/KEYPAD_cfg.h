/*
 * KEYPAD_cfg.h
 *
 * Created: 10/25/2023 6:25:24 PM
 *  Author: HP
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

/*TO CONFIGURE KEYPAD PORT 
OPYIANS :   DIO_PORTA_Reg
            DIO_PORTB_Reg
            DIO_PORTC_Reg
            DIO_PORTD_Reg       */
#define KEYPAD_PORT             DIO_PORTD_Reg

/*TO CONFIGURE KEYPAD PINS 
OPYIANS :   DIO_PORTD_Reg
            ..............
            ..............
            ..............
            DIO_CHANNEL_31        */
#define KEYPAD_u8_R1_PIN   DIO_CHANNEL_8
#define KEYPAD_u8_R2_PIN   DIO_CHANNEL_9
#define KEYPAD_u8_R3_PIN   DIO_CHANNEL_10
#define KEYPAD_u8_R4_PIN   DIO_CHANNEL_11

#define KEYPAD_u8_C1_PIN   DIO_CHANNEL_12
#define KEYPAD_u8_C2_PIN   DIO_CHANNEL_13
#define KEYPAD_u8_C3_PIN   DIO_CHANNEL_14
#define KEYPAD_u8_C4_PIN   DIO_CHANNEL_15


#endif /* KEYPAD_CFG_H_ */