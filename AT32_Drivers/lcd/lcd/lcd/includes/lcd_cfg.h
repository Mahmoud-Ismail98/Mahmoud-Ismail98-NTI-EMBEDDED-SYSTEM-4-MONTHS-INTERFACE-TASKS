/*
 * lcd_cfg.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include"lcd.h"

#define LCD_RS_PORT_ID                 LCD_PORTB
#define LCD_RS_PIN_ID                  PORT_PIN8_ID

#define LCD_E_PORT_ID                  LCD_PORTB
#define LCD_E_PIN_ID                   PORT_PIN9_ID

/* 8_bit mode port */
#define LCD_DATA_PORT_ID               LCD_PORTA

/* 4_bit pins */
#define LCD_DB4_PIN_ID                PORT_PIN0_ID
#define LCD_DB5_PIN_ID                PORT_PIN1_ID
#define LCD_DB6_PIN_ID                PORT_PIN2_ID
#define LCD_DB7_PIN_ID                PORT_PIN3_ID

#define LCD_NUM_OF_COLUMNS            LCD_16_COLS

#if((LCD_NUM_OF_COLUMNS != LCD_16_COLS) &&(LCD_NUM_OF_COLUMNS != LCD_20_COLS))
#error "Number of cols should be equal to 16 or 20"
#endif

/*
FOUR_BITS_MODE
EIGHT_BITS_MODE
 * */
#define DATA_BITS_MODE              EIGHT_BITS_MODE

#if((DATA_BITS_MODE != FOUR_BITS_MODE) &&(DATA_BITS_MODE != EIGHT_BITS_MODE))
#error "Number of Data bits should be equal to 4 or 8"
#endif

#endif /* LCD_CFG_H_ */
