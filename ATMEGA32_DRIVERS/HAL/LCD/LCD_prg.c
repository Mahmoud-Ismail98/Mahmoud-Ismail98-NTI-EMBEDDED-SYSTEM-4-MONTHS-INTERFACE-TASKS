#include "util/delay.h"

#define F_CPU 16000000
#include "Std_types.h"
#include "Bit_utils.h"

#include "Port.h"
#include "Dio.h"

#include "LCD_interface.h"
#include "LCD_cfg.h"


/*
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PD7|---------------->|D7        |
 |        PD6|---------------->|D6        |
 |        PD5|---------------->|D5        |
 |        PD4|---------------->|D4        |
 |        PD3|---------------->|D3        |
 |        PD2|---------------->|D2        |
 |        PD1|---------------->|D1        |
 |        PD0|---------------->|D0        |
 |           |                 |          |
 |        PA2|---------------->|E         |
 |        PA1|---------------->|RW        |
 |        PA0|---------------->|RS        |
 -----------                   ----------
 */

/***************************************************************************************/
/********************************** Fucntion Definition ********************************/
/***************************************************************************************/

/***************************************************************************************/
/********************************** Macros *********************************************/
/***************************************************************************************/


/***************************************************************************************/
/********************************** Constant Variables *********************************/
/***************************************************************************************/



/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/


void LCD_vidInit(void)
{
 

 #if LCD_MODE == LCD_4_BIT 
	/* Delay 15ms to ensure the initialization of the LCD driver */
	_delay_ms(15);
   
 LCD_vidSendCommand(LCD_4bit_INT1) ; 
 LCD_vidSendCommand(LCD_4bit_INT2) ;
 LCD_vidSendCommand(lcd_FunctionSet4bit) ; 
 LCD_vidSendCommand(lcd_DisplayOn) ;
 LCD_vidSendCommand(lcd_Clear) ;
 
 
_delay_ms(1);

#elif LCD_MODE == LCD_8_BIT

	_delay_ms(30);
   
 LCD_vidSendCommand(lcd_EntryMode) ; 
 LCD_vidSendCommand(lcd_FunctionSet8bit) ; 
 LCD_vidSendCommand(lcd_DisplayOn) ;
 LCD_vidSendCommand(lcd_Clear) ;
 
	

}


/***************************************************************************************/
/* Description: Send a configuration command to the LCD driver.                       */
/* Input: u8CmdCpy - The command number to be sent.                                    */
/* Output: None                                                                      */
/***************************************************************************************/
void LCD_vidSendCommand(u8 u8CmdCpy)
{
    /* Set RS to LOW (indicating a command, not data) */
    Dio_enuWriteChannel(RS_PIN, DIO_u8LEVEL_LOW);

    /* Set R/W to LOW (indicating a write operation) */
    Dio_enuWriteChannel(RW_PIN, DIO_u8LEVEL_LOW);

    /* Delay to ensure stability */
    _delay_ms(1);

    /* Set E to HIGH to load the command */
    Dio_enuWriteChannel(EN_PIN, DIO_u8LEVEL_HIGH);

    /* Load the command on the data bus */
    Dio_enuWriteChannel(DATA_PIN4, GET_BIT(u8CmdCpy, 4));
    Dio_enuWriteChannel(DATA_PIN5, GET_BIT(u8CmdCpy, 5));
    Dio_enuWriteChannel(DATA_PIN6, GET_BIT(u8CmdCpy, 6));
    Dio_enuWriteChannel(DATA_PIN7, GET_BIT(u8CmdCpy, 7));

    /* Delay to ensure proper data setup */
    _delay_ms(1);

    /* Set E to LOW to execute the command */
    Dio_enuWriteChannel(EN_PIN, DIO_u8LEVEL_LOW);

    /* Delay to let the command execute */
    _delay_ms(1);

    /* Set E to HIGH for the second nibble */
    Dio_enuWriteChannel(DATA_PIN4, GET_BIT(u8CmdCpy, 0));
    Dio_enuWriteChannel(DATA_PIN5, GET_BIT(u8CmdCpy, 1));
    Dio_enuWriteChannel(DATA_PIN6, GET_BIT(u8CmdCpy, 2));
    Dio_enuWriteChannel(DATA_PIN7, GET_BIT(u8CmdCpy, 3));

    /* Delay to ensure proper data setup */
    _delay_ms(1);

    /* Set E to LOW to complete the command execution */
    Dio_enuWriteChannel(EN_PIN, DIO_u8LEVEL_LOW);

    /* Delay for 1ms to let the LCD execute the command */
    _delay_ms(1);
}


/***************************************************************************************/
/* Description: Write a character to the LCD screen.                                  */
/* Input: u8DataCpy - The character data to send.                                    */
/* Output: None                                                                      */
/***************************************************************************************/
void LCD_vidWriteCharctr(u8 u8DataCpy)
{
    /* Set RS to HIGH (indicating data, not a command) */
    Dio_enuWriteChannel(RS_PIN, DIO_u8LEVEL_HIGH);

    /* Set R/W to LOW (indicating a write operation) */
    Dio_enuWriteChannel(RW_PIN, DIO_u8LEVEL_LOW);

    /* Set E to HIGH to load the data */
    Dio_enuWriteChannel(EN_PIN, DIO_u8LEVEL_HIGH);

    /* Load the data on the data bus */
    Dio_enuWriteChannel(DATA_PIN4, GET_BIT(u8DataCpy, 4));
    Dio_enuWriteChannel(DATA_PIN5, GET_BIT(u8DataCpy, 5));
    Dio_enuWriteChannel(DATA_PIN6, GET_BIT(u8DataCpy, 6));
    Dio_enuWriteChannel(DATA_PIN7, GET_BIT(u8DataCpy, 7));

    /* Delay to ensure proper data setup */
    _delay_ms(1);

    /* Set E to LOW to execute the data write */
    Dio_enuWriteChannel(EN_PIN, DIO_u8LEVEL_LOW);

    /* Delay to let the data write complete */
    _delay_ms(1);

    /* Set E to HIGH for the second nibble */
    Dio_enuWriteChannel(DATA_PIN4, GET_BIT(u8DataCpy, 0));
    Dio_enuWriteChannel(DATA_PIN5, GET_BIT(u8DataCpy, 1));
    Dio_enuWriteChannel(DATA_PIN6, GET_BIT(u8DataCpy, 2));
    Dio_enuWriteChannel(DATA_PIN7, GET_BIT(u8DataCpy, 3));

    /* Delay to ensure proper data setup */
    _delay_ms(1);

    /* Set E to LOW to complete the data write */
    Dio_enuWriteChannel(EN_PIN, DIO_u8LEVEL_LOW);

    /* Delay for 1ms to let the LCD execute the write operation */
    _delay_ms(1);
}

/***************************************************************************************/
/* Description: Write a string on the LCD screen.                                     */
/* Input: pu8StringCpy - Pointer to the string to be displayed.                        */
/* Output: None                                                                      */
/***************************************************************************************/
void LCD_vidWriteString(u8* pu8StringCpy)
{
    u8 iteration = 0;

    while (pu8StringCpy[iteration] != '\0')
    {
        /* Write each character of the string on the LCD */
        LCD_vidWriteCharctr(pu8StringCpy[iteration]);

        iteration++;
    }

    /* Delay to allow the LCD to display the characters */
    _delay_ms(2);
}



/***************************************************************************************/
/* Description! Interface to start the writing process at certain digit in the LCD     */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/

void LCD_voidSetCursor(u8 Row, u8 Column)
{

	#if (LCD_TYPE == LCD_16_2)
	u8 firstAddressPositionsTable[] = {0x80,0xC0};
		
	#elif (LCD_TYPE == LCD_20_1)
	u8 firstAddressPositionsTable[] = {0x80};
	
	#elif (LCD_TYPE == LCD_20_2)
	u8 firstAddressPositionsTable[] = {0x80,0xC0};
	
	#elif (LCD_TYPE == LCD_20_4)
	u8 firstAddressPositionsTable[] = {0x80,0xC0,0x94,0xD4};
	
	#elif (LCD_TYPE == LCD_40_2)
	u8 firstAddressPositionsTable[] = {0x80,0xC0};
	#else
	
	#error
	"wrong type of LCD entered, please enter correct LCD type"
	
	#endif



	u8 position = firstAddressPositionsTable[Row - 1] + Column-1;
	if (position <=0xE7)
	{
		LCD_vidSendCommand(position);
	}
	else
	{

	}

}

/***************************************************************************************/
/* Description: Display an integer on the LCD screen.                                */
/* Input: a_integerNumber - The integer to be displayed.                               */
/* Output: None                                                                      */
/***************************************************************************************/
void LCD_displayInteger(u64 a_integerNumber)
{	
	// Check if the integer is 0
	if(a_integerNumber == 0)
	{
		// Display '0' on the LCD
		LCD_vidWriteCharctr('0');
	}
	else
	{
		// Initialize a variable to store the reversed number
		u64 LOC_reversedNumber = 1;

		// Reverse the input number
		while(a_integerNumber != 0)
		{
			LOC_reversedNumber = (LOC_reversedNumber * 10) + (a_integerNumber % 10);
			a_integerNumber /= 10;
		}

		// Display the reversed number
		while(LOC_reversedNumber != 1)
		{
			LCD_vidWriteCharctr((LOC_reversedNumber % 10) + '0');
			LOC_reversedNumber /= 10;
		}
	}
}


/***************************************************************************************/
/* Description: Positions the cursor on the LCD screen to the specified row and column. */
/* Input:      Copy_u8XPos - The target row (0 or 1).                               */
/*             Copy_u8YPos - The target column (0 to 15).                            */
/* Output:     None                                                                 */
/***************************************************************************************/
void LCD_voidGotToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
    u8 Local_u8Address;

    if (Copy_u8XPos == 0)
    {
        // If X position is 0 (first row), set address to Y position.
        Local_u8Address = Copy_u8YPos;
    }
    else if (Copy_u8XPos == 1)
    {
        // If X position is 1 (second row), set address to Y position + 0x40 (offset for the second row).
        Local_u8Address = Copy_u8YPos + 0x40;
    }

    // Send a command to the LCD to set the cursor to the specified address + 128 (0x80).
    LCD_vidSendCommand(Local_u8Address + 128);
}




/***************************************************************************************/
/* Description: Writes a special character pattern to the LCD screen.                  */
/* Input:      copy_u8Pattern - Pointer to an array containing the character pattern. */
/*             copy_u8PatternNumber - The pattern number (0 to 7) to write to.          */
/* Output:     None                                                                 */
/***************************************************************************************/
void LCD_voidWriteSpecialCharacter(u8* copy_u8Pattern, u8 copy_u8PatternNumber)
{
    u8 LOC_u8CGRAMAdrress = 0;
    u8 LOC_u8Iterator;

    // Calculate the CGRAM address based on the pattern number (each pattern occupies 8 bytes).
    LOC_u8CGRAMAdrress = copy_u8PatternNumber * 8;

    // Send a command to set the CGRAM address to the LCD by adding 64 to the pattern address.
    LCD_vidSendCommand(LOC_u8CGRAMAdrress + 64);

    // Write the character pattern data to CGRAM, one byte at a time.
    for (LOC_u8Iterator = 0; LOC_u8Iterator < 8; LOC_u8Iterator++)
    {
        LCD_vidWriteCharctr(*(copy_u8Pattern + LOC_u8Iterator));
    }

    // Return to DDRAM to display the pattern.
    LCD_vidSendCommand(0x80);
}



 
/***************************************************************************************/
/* Description: Clears the LCD screen by sending the clear command.                   */
/* Input:      None                                                                 */
/* Output:     None                                                                 */
/***************************************************************************************/
void LCD_CLEAR(void)
{
    // Send the clear command to the LCD to clear the screen.
    LCD_vidSendCommand(lcd_Clear);
}
