/*
 * LCD.h
 *
 * Created: 10/22/2023 10:05:26 AM
 *  Author: Mahmoud Tariq
 */ 


#ifndef LCD_H_
#define LCD_H_

typedef enum{
	LCD_Status_Fail,
	LCD_Status_Ok,
	LCD_PinNO_ERR,
	LCD_NULLpTR,ERR
	}LCD_enuERR_STATUS;

/*Functions ProtoTypes  */
void LCD_vidSendCMD(u8 CMD);
void LCD_vid4Bit_Init(void);
void LCD_vidSendFallingEdge(void);
void LCD_vidDisplayChar(u8 copy_char);
void LCD_vidDisplayString (pu8 add_string);
void LCD_vidDisplayInt(u64 copy_int);
void LCD_vidMoveCusrsor(u8 copy_x , u8 copy_y);
void LCD_vidDisplayCustomChar(pu8 add_custom_char,u8 copy_u8Index);
void LCD_vidClearDisplay(void);
void LCD_vidSetCursorHome(void);











#endif /* LCD_H_ */