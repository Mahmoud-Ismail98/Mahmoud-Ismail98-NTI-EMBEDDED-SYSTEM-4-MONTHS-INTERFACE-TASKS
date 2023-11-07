/*
 * KEYPAD_CFG.h
 *
 * Created: 10/22/2023 10:59:27 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_


#define KEYPAD_row1         PORTC_PIN5
#define KEYPAD_row2			PORTC_PIN4
#define KEYPAD_row3			PORTC_PIN3
#define KEYPAD_row4			PORTC_PIN2

#define KEYPAD_col1			PORTD_PIN7
#define KEYPAD_col2			PORTD_PIN6
#define KEYPAD_col3			PORTD_PIN5
#define KEYPAD_col4			PORTD_PIN4

#define KEYPAD_pattern1		    14     
#define KEYPAD_pattern2		    13
#define KEYPAD_pattern3		    11
#define KEYPAD_pattern4		    7
#define KEYPAD_default_pattern  15


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

#define KEYPAD_KEY_13_SYMBOL                    'E'
#define KEYPAD_KEY_14_SYMBOL                    '0'
#define KEYPAD_KEY_15_SYMBOL                    '='
#define KEYPAD_KEY_16_SYMBOL                    '+'

#endif /* KEYPAD_CFG_H_ */