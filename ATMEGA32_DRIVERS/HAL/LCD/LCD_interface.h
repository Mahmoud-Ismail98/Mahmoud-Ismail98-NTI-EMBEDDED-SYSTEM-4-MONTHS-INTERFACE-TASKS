

#ifndef LCD_H_
#define LCD_H_ 

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_FunctionSet4bit 0x28          // 4-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position
#define LCD_4bit_INT1       0x33           // Init 4-BIt 
#define LCD_4bit_INT2       0x32           // Init 4-BIt
#define LCD_4_BIT           (4U)
#define LCD_4_BIT           (8U)


/***************************************************************************************/
/********************************** Fucntion Definition ********************************/
/***************************************************************************************/



/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidInit(void);

/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidSendCommand(u8 u8CmdCpy);

/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteCharctr(u8 u8DataCpy);

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/

void LCD_vidWriteString (u8* pu8StringCpy);


/***************************************************************************************/
/* Description: Set the cursor position on the LCD screen                             */
/* Input: Row - The row number (0 for the first row, 1 for the second row)            */
/*        Column - The column number (0 to 15) within the specified row                */
/* Output: None                                                                      */
/***************************************************************************************/
void LCD_voidSetCursor(u8 Row, u8 Column);


/***************************************************************************************/
/* Description: Display an integer on the LCD screen.                                */
/* Input: a_integerNumber - The integer to be displayed on the LCD screen.           */
/* Output: None                                                                      */
/***************************************************************************************/
void LCD_displayInteger(u64 a_integerNumber);



/***************************************************************************************/
/* Description: Move the cursor of the LCD to the specified X and Y position.         */
/* Input: Copy_u8XPos - The X position to move the cursor to (0 to 15).               */
/*        Copy_u8YPos - The Y position to move the cursor to (0 or 1 for 2-line LCD). */
/* Output: None                                                                      */
/***************************************************************************************/
void LCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);


/***************************************************************************************/
/* Description: Write a custom special character to the CGRAM of the LCD.             */
/* Input: copy_u8Pattern - Pointer to an array containing the custom character data.  */
/*        copy_u8PatternNumber - The pattern number to assign (0 to 7).                */
/* Output: None                                                                      */
/***************************************************************************************/
void LCD_voidWriteSpecialCharacter(u8* copy_u8Pattern, u8 copy_u8PatternNumber);

/***************************************************************************************/
/* Description: Clear the display and return the cursor to the home position.         */
/* Input: None                                                                       */
/* Output: None                                                                      */
/***************************************************************************************/
void LCD_CLEAR(void);

#endif /* LCD_H_ */
