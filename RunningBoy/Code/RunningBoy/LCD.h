/*
 * LCD.h
 *
 * Created: 10/21/2023 2:19:27 PM
 *  Author: FADY
 */ 


#ifndef LCD_H_
#define LCD_H_

#define LCD_ROW_0       0x00
#define LCD_ROW_1       0x40
#define LCD_ROW_2       0x14
#define LCD_ROW_3       0x54


#define LCD_COL_0       0
#define LCD_COL_1       1
#define LCD_COL_2       2
#define LCD_COL_3       3
#define LCD_COL_4       4
#define LCD_COL_5       5
#define LCD_COL_6       6
#define LCD_COL_7       7
#define LCD_COL_8       8
#define LCD_COL_9       9
#define LCD_COL_10      10
#define LCD_COL_11      11
#define LCD_COL_12      12
#define LCD_COL_13      13
#define LCD_COL_14      14
#define LCD_COL_15      15
#define LCD_COL_16      16
#define LCD_COL_17      17
#define LCD_COL_18      18
#define LCD_COL_19      19

void LCD_VoidInit (void);
void LCD_VOidSendChar( u8 Copy_u8Data );
void LCD_VoidSendString (pu8 Copy_Addu8Str)	;
void LCD_Goto_xy(u8 Copy_u8Row, u8 Copy_u8Col)	;
void LCD_VoidSendNumbers(float Copy_f32Number);
void LCD_VoidClear(void);
void LCD_VoidCreateSpectialChar(u8 Copy_u8Index, pu8 Copy_u8Data);



#endif /* LCD1_H_ */