/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 21 Oct 2023                                                           */
/************************************************************************************/
#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H

/* Macros for configuration of KeyPad Array  */
#define KPD_u8_ROW_0_COL_0          7
#define KPD_u8_ROW_0_COL_1          8
#define KPD_u8_ROW_0_COL_2          9
#define KPD_u8_ROW_0_COL_3         '/'
#define KPD_u8_ROW_1_COL_0          4
#define KPD_u8_ROW_1_COL_1          5
#define KPD_u8_ROW_1_COL_2          6
#define KPD_u8_ROW_1_COL_3         '*'
#define KPD_u8_ROW_2_COL_0          1
#define KPD_u8_ROW_2_COL_1          2
#define KPD_u8_ROW_2_COL_2          3
#define KPD_u8_ROW_2_COL_3         '-'
#define KPD_u8_ROW_3_COL_0         '%'
#define KPD_u8_ROW_3_COL_1          0
#define KPD_u8_ROW_3_COL_2         '='
#define KPD_u8_ROW_3_COL_3         '+'

/* Macros for Keypad Port           */
/*      Options: DIO_u8_PORTA
                 DIO_u8_PORTB
                 DIO_u8_PORTC
                 DIO_u8_PORTD       */
#define KPD_u8_ROW_PORT             DIO_u8_PORTB
#define KPD_u8_COL_PORT             DIO_u8_PORTC

/* Macros for Row Pattern */
#define KPD_u8_ROW_PATT_0             0b00001110
#define KPD_u8_ROW_PATT_1             0b00001101
#define KPD_u8_ROW_PATT_2             0b00001011
#define KPD_u8_ROW_PATT_3             0b00000111

/* Macros for Column Pattern */

#define KPD_u8_COL_PATT_0             0b00001110
#define KPD_u8_COL_PATT_1             0b00001101
#define KPD_u8_COL_PATT_2             0b00001011
#define KPD_u8_COL_PATT_3             0b00000111

/* Macros for Row Pins            */
/*      Options: DIO_u8_PIN0
                 DIO_u8_PIN1
                 DIO_u8_PIN2
                 DIO_u8_PIN3
                 DIO_u8_PIN4
                 DIO_u8_PIN5
                 DIO_u8_PIN6
                 DIO_u8_PIN7       */
#define KPD_u8_ROW_PIN_0             DIO_u8_PIN0
#define KPD_u8_ROW_PIN_1             DIO_u8_PIN1
#define KPD_u8_ROW_PIN_2             DIO_u8_PIN2
#define KPD_u8_ROW_PIN_3             DIO_u8_PIN3
//Macros for Column Pins 
#define KPD_u8_COL_PIN_0             DIO_u8_PIN0
#define KPD_u8_COL_PIN_1             DIO_u8_PIN1
#define KPD_u8_COL_PIN_2             DIO_u8_PIN2
#define KPD_u8_COL_PIN_3             DIO_u8_PIN3

#endif
