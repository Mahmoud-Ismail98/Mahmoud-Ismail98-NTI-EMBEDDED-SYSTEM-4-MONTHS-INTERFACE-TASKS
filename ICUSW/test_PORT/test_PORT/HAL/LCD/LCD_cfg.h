/*
 * LCD_cfg.h
 *
 * Created: 10/21/2023 2:19:27 PM
 *  Author: FADY
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/*TO CONFIGURE THE MODE 
OPYIANS :   LCD_4BIT_MODE
            LCD_8BIT_MODE        */


#define LCD_MODE	LCD_4BIT_MODE 

/*TO CONFIGURE LCD PINS 
OPYIANS :   DIO_CHANNEL_0
            ..............
            ..............
            ..............
            DIO_CHANNEL_31        */
#define LCD_PIN_RS  DIO_CHANNEL_8  
#define LCD_PIN_EN  DIO_CHANNEL_9 

#define LCD_PIN_DATA_0    DIO_CHANNEL_8
#define LCD_PIN_DATA_1    DIO_CHANNEL_9
#define LCD_PIN_DATA_2    DIO_CHANNEL_10
#define LCD_PIN_DATA_3    DIO_CHANNEL_11
#define LCD_PIN_DATA_4    DIO_CHANNEL_12
#define LCD_PIN_DATA_5    DIO_CHANNEL_13
#define LCD_PIN_DATA_6    DIO_CHANNEL_14
#define LCD_PIN_DATA_7    DIO_CHANNEL_15



#endif /* LCD_CFG_H_ */