/*
 * LCD_prv.h
 *
 * Created: 10/21/2023 2:19:27 PM
 *  Author: FADY
 */ 


#ifndef LCD_PRV_H
#define LCD_PRV_H

#define LCD_PIN_HIGH   DIO_CHANNEL_HIGH
#define LCD_PIN_LOW    DIO_CHANNEL_LOW


#define LCD_4BIT_MODE   0
#define LCD_8BIT_MODE   1


#define LCD_4MODE_SET		    	0x02
#define LCD_8MODE_SET               0x38
#define lCD_2LINE_SET				0x28   
#define LCD_DISPLAY_ON_CURSOR_OFF 	0x0c
#define LCD_SHIFT_CURSOR_SET		0x06
#define LCD_CLEAR_LCD 				0x01
#define LCD_CURSOR_HOME				0x80

  




#endif