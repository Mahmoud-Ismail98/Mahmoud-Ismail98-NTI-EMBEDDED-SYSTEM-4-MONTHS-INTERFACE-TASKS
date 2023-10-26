/*
 * lcd.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef LCD_H_
#define LCD_H_

#include"../Services/std_types.h"
#include"lcd_prv.h"
#include"lcd_cfg.h"
#include"../Mcal/dio.h"
#include"../Mcal/port.h"
#include<avr/io.h>
#include<util/delay.h>

/*lcd mode*/
#define FOUR_BITS_MODE                4
#define EIGHT_BITS_MODE               8

/*lcd number of columns*/
#define LCD_16_COLS                   16
#define LCD_20_COLS                   20

/*cols macros*/
#define COL0          0
#define COL1          1
#define COL2          2
#define COL3          3
#define COL4          4
#define COL5          5
#define COL6          6
#define COL7          7
#define COL8          8
#define COL9          9
#define COL10         10
#define COL11         11
#define COL12         12
#define COL13         13
#define COL14         14
#define COL15         15
#define COL16         16
#define COL17         17
#define COL18         18
#define COL19         19

/*LCD 4bits mode pins*/
#define LCD_PORTA                     0
#define LCD_PORTB                     1
#define LCD_PORTC                     2
#define LCD_PORTD                     3

/* functions prototypes */
void LCD_init(void);

void LCD_sendCommand(u8 command);

void LCD_displayCharacter(u8 character);

void LCD_creatCustomCharacter(pu8 character, u8 index);

void LCD_moveCurser(u8 row,u8 col);

void LCD_displayString(pu8 str);

void LCD_displayStringRowColumn(u8 row,u8 col,pu8 str);

void LCD_displayNumber(u32 number);

void LCD_clearScreen(void);

void shiftDisplay_right(void);


#endif /* LCD_H_ */
