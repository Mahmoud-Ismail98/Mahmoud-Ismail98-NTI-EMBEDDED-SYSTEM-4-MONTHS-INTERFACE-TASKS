/*
 * SegBCD.h
 *
 * Created: 10/21/2023 9:29:51 AM
 *  Author: Wael
 */ 


#ifndef LCD_H_
#define LCD_H_

void LCD_voidInit(void);

void LCD_voidDisplayChar(u8 Copy_u8Character);

void LCD_voidCreateCustomChar(pu8 Copy_pu8CharArray, u8 Copy_u8CharAddress);

void LCD_voidDisplayString(u8* Ptr_u8String);

void LCD_voidGoToXY(u8 Copy_u8X, u8 Copy_u8Y);

void LCD_voidDisplayNumbers(u32 Copy_u32Number);

void LCD_voidClear();


#endif /* LCD_H_ */