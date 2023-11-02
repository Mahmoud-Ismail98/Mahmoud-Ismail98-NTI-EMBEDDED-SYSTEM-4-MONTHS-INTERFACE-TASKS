/*
 * Lcd.h
 *
 * Created: 10/20/2023 5:05:19 AM
 *  Author: Sharpel
 */ 


#ifndef LCD_H_
#define LCD_H_


/*
 * function		: LCD_vidInit
 * description 	: func to set LCD initialization
 * input param 	: void
 * return		: void
 * */
void LCD_vidInit(void);
void LCD_vidSendCommand(u8 arg_u8_command);
void LCD_vidDisplayCharacter(u8 arg_u8_data);
void LCD_vidCreateCustomCharacter(u8 *arg_u8_data_array,u8 arg_u8_index);
void LCD_vidGoToXY(u8 arg_u8_row,u8 arg_u8_col);
void LCD_vidDisplayString(u8 *arg_u8_string);
void LCD_vidDisplayNumber(u32 arg_u32_number);
void LCD_vidDisplayFloat(f32 arg_f32_number);
void LCD_vidClrDisplay(void);

#endif /* LCD_H_ */