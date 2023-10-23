/*
 * LCD.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Ismail
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_
#include "LCD_cfg.h"
#include "LCD_prv.h"
#include"../../MCAL/DIO/DIO.h"
#include"../../MCAL/PORT/PORT.h"


/*Macros For Users*/
#define LCD_LINE_0 0
#define LCD_LINE_1 1
#define LCD_LINE_2 2
#define LCD_LINE_3 3
/*add the generated special char array values here

u8 Spicialchar_StickMan[8] = {
		  0x1F,
		  0x11,
		  0x1F,
		  0x04,
		  0x1F,
		  0x04,
		  0x0A,
		  0x11
		};
*/


void LCDInit4BitMode();
void LCD_WriteCommand4Bit(u8 Copy_u8Command);
void LCD_WriteChar4Bit(u8 Copy_u8Data);
void LCD_WriteString(u8 *u8Copy_u8String);
void LCD_SetCursorPosition(u8 Copy_u8LineNumber,u8 Copy_u8PositionNumber);
void LCD_WriteNumber(u32 Copy_u8Number);
void LCD_CustomChar (pu8 AddCustomChar,u8 index);

#endif /* HAL_LCD_LCD_H_ */
