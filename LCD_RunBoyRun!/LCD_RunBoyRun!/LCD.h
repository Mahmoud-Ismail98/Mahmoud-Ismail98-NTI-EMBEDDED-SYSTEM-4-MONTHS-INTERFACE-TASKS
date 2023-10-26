/*
 * LCD.h
 *
 * Created: 10/21/2023 9:29:51 AM
 *  Author: Ahmed Wael
 */


#ifndef LCD_H_
#define LCD_H_
/*
LCD_voidInit(void);
Description:
			Init LCD, Must be called at the beginning of the program
*/
void LCD_voidInit(void);




/*
LCD_voidDisplayChar(u8 Copy_u8Character);
Description:
			This function Displays Single character on LCD, character should be sent as ASCII
*/
void LCD_voidDisplayChar(u8 Copy_u8Character);




/*
LCD_voidCreateCustomChar(pu8 Copy_pu8CharArray, u8 Copy_u8CharAddress);
Description:
			This function creates a new character to display
			Args: 8 elements array to represent char, address of the character as the character will be displayed using this address
*/
void LCD_voidCreateCustomChar(pu8 Copy_pu8CharArray, u8 Copy_u8CharAddress);




/*
LCD_voidDisplayString(u8* Ptr_u8String);
Description:
			This function Displays string on LCD
*/
void LCD_voidDisplayString(u8* Ptr_u8String);



/*
 LCD_voidGoToXY(u8 Copy_u8X, u8 Copy_u8Y);
Description:
			This function sets the cursor of the LCD on X , Y; to type characters and strings at any position
*/
void LCD_voidGoToXY(u8 Copy_u8X, u8 Copy_u8Y);



/*
LCD_voidDisplayNumbers(u32 Copy_u32Number);
Description:
			This function Displays a number
*/
void LCD_voidDisplayNumbers(u32 Copy_u32Number);



/*
LCD_voidClear();
Description:
			This function Clears the LCD
*/
void LCD_voidClear();


#endif /* LCD_H_ */