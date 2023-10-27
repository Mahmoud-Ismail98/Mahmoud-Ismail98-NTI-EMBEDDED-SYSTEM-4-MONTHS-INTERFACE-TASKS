/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : KEYPAD              **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/
#ifndef KEYPAD_CFG_H
#define KEYPAD_CFG_H

/* configure row pins */
#define KEYPAD_PIN_ROW_0                        PORT_C_CHANNEL_5
#define KEYPAD_PIN_ROW_1                        PORT_C_CHANNEL_4
#define KEYPAD_PIN_ROW_2                        PORT_C_CHANNEL_3
#define KEYPAD_PIN_ROW_3                        PORT_C_CHANNEL_2

/* configure column pins */
#define KEYPAD_PIN_COL_0                        PORT_D_CHANNEL_7
#define KEYPAD_PIN_COL_1                        PORT_D_CHANNEL_6
#define KEYPAD_PIN_COL_2                        PORT_D_CHANNEL_5
#define KEYPAD_PIN_COL_3                        PORT_D_CHANNEL_3

/* configure each button symbol */
#define KEYPAD_KEY_1_SYMBOL                     '7'
#define KEYPAD_KEY_2_SYMBOL                     '8'
#define KEYPAD_KEY_3_SYMBOL                     '9'
#define KEYPAD_KEY_4_SYMBOL                     '/'

#define KEYPAD_KEY_5_SYMBOL                     '4'                                
#define KEYPAD_KEY_6_SYMBOL                     '5'                               
#define KEYPAD_KEY_7_SYMBOL                     '6'                               
#define KEYPAD_KEY_8_SYMBOL                     '*'

#define KEYPAD_KEY_9_SYMBOL                     '1'                                
#define KEYPAD_KEY_10_SYMBOL                    '2'                                
#define KEYPAD_KEY_11_SYMBOL                    '3'                                
#define KEYPAD_KEY_12_SYMBOL                    '-'

#define KEYPAD_KEY_13_SYMBOL                    'c'
#define KEYPAD_KEY_14_SYMBOL                    '0'                                
#define KEYPAD_KEY_15_SYMBOL                    '='
#define KEYPAD_KEY_16_SYMBOL                    '+'

#endif
