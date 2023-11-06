/*
 * LCD_cfg.h
 *
 * Created: 10/21/2023 2:19:27 PM
 *  Author: FADY
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_



#define SET_FUNCTION_8BIT_5x8_OneLine      0x30
#define SET_FUNCTION_8BIT_5x8_TwoLine      0x38
#define Display_On_Off_Control             0x0C
#define Display_clear                      0x01
#define Entry_Mode_Set                     0x

#define Cursor_Enable                      0x0E
/**************************************************************/
#define DDRAM_Address            0x80
#define CGRAM_Address            0x40

#define LCDData_PORT            Port_B


/************************** CTRL PINS **********************************/
#define LCDCTR_PORT              Port_A
#define LCD_EN_PIN         		 Pin_0
#define LCD_RS_PIN         		 Pin_1
#define LCD_RW_PIN         		 Pin_2
#endif /* LCD_CFG_H_ */
