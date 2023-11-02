/*
 * lcd_prv.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef LCD_PRV_H_
#define LCD_PRV_H_

/* LCD16 base addresses Commands for move curser*/
#define LCD16_1ST_ROW_BASE_ADDRESS            (0X00)
#define LCD16_2ND_ROW_BASE_ADDRESS            (0X40)
#define LCD16_3RD_ROW_BASE_ADDRESS            (0X10)
#define LCD16_4TH_ROW_BASE_ADDRESS            (0X50)

/* LCD20 base addresses Commands for move curser*/
#define LCD20_1ST_ROW_BASE_ADDRESS            (0X00)
#define LCD20_2ND_ROW_BASE_ADDRESS            (0X40)
#define LCD20_3RD_ROW_BASE_ADDRESS            (0X14)
#define LCD20_4TH_ROW_BASE_ADDRESS            (0X54)
#define LCD_SET_CURSOR_LOCATION               (0X80)

/* general LCD Commands for initialization */
#define LCD_SCREEN_CLEAR                     (0x01)
#define LCD_RETURN_HOME                      (0x02)
#define LCD_CURSOR_OFF                       (0X0C)
#define LCD_CURSOR_ON                        (0x0E)
#define LCD_NUMBER_OF_LOCATIONS_IN_CGRAM     (8)
#define LCD_CGRAM_BASE_ADDRESS               (0X40)
#define LCD_SHIFT_DISPLAY_RIGHT              (0X05)
#define LCD_SHIFT_ENTIRE_DISPLAY_RIGHT       (0X1C)
/*LCD Commands for 8 BITS MODE initialization*/

/*function set*/
#define LCD8_TWO_LINES                        (0X38)


/*LCD Commands for 4 BITS MODE initialization*/
#define LCD4_1_LINE_SET_COMMAND               (0X20)
#define LCD4_2_LINES_INIT1_COMMAND            (0X33)
#define LCD4_2_LINES_INIT2_COMMAND            (0X32)
#define LCD4_2_LINES_SET_COMMAND              (0X28)

/*LCD Commands for 4 BITS MODE initialization*/
#define LCD8_1_LINE_SET_COMMAND               (0X30)
#define LCD8_2_LINES_COMMAND                  (0X38)


#endif /* LCD_PRV_H_ */
