/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
/* Description ! 16x2 Character LCD for chip LMB161A                                   */
/* Release Date! 28/6/2016                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/

/********************************** Header Files INCLUSIONS ****************************/

#include "util/delay.h"

#define F_CPU 16000000
#include "Std_types.h"
#include "Bit_utils.h"

#include "Port.h"
#include "Dio.h"

#include "LCD_interface.h"
#include "LCD_cfg.h"
/***************************************************************************************/

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
	
	/* Delay 15ms to ensure the initialization of the LCD driver */
	_delay_ms(15);
   
 LCD_vidSendCommand(LCD_4bit_INT1) ; 
 LCD_vidSendCommand(LCD_4bit_INT2) ;
 LCD_vidSendCommand(lcd_FunctionSet4bit) ; 
 LCD_vidSendCommand(lcd_DisplayOn) ;
 LCD_vidSendCommand(lcd_Clear) ;
 
 
_delay_ms(1);


	

}


/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidSendCommand(u8 u8CmdCpy)
{

	/* Set RS to LOW */
	Dio_enuWriteChannel(RS_PIN, DIO_u8LEVEL_LOW);

	/* Set R/W to LOW */
	Dio_enuWriteChannel(RW_PIN, DIO_u8LEVEL_LOW);

	/* Set E to HIGH  */	
	_delay_ms(1);
	Dio_enuWriteChannel(EN_PIN , DIO_u8LEVEL_HIGH);

	/* Load Command on Data bus */
	   
	Dio_enuWriteChannel(DATA_PIN4 , GET_BIT(u8CmdCpy ,4)) ;
	Dio_enuWriteChannel(DATA_PIN5 , GET_BIT(u8CmdCpy ,5)) ;
	Dio_enuWriteChannel(DATA_PIN6 , GET_BIT(u8CmdCpy ,6)) ;
	Dio_enuWriteChannel(DATA_PIN7 , GET_BIT(u8CmdCpy ,7)) ;
	
	_delay_ms(1);
	
	Dio_enuWriteChannel(EN_PIN , DIO_u8LEVEL_LOW);
	
	_delay_ms(1);

	/* Set E to LOW */	
	Dio_enuWriteChannel(EN_PIN, DIO_u8LEVEL_HIGH);

	/* Wait for E to settle */
	_delay_ms(1);

	 /* Set E to HIGH */
	
	Dio_enuWriteChannel(DATA_PIN4 , GET_BIT(u8CmdCpy ,0)) ;
	Dio_enuWriteChannel(DATA_PIN5 , GET_BIT(u8CmdCpy ,1)) ;
	Dio_enuWriteChannel(DATA_PIN6 , GET_BIT(u8CmdCpy ,2)) ;
	Dio_enuWriteChannel(DATA_PIN7 , GET_BIT(u8CmdCpy ,3)) ;
	 
	  _delay_ms(1) ;
	
  	Dio_enuWriteChannel(EN_PIN, DIO_u8LEVEL_LOW);
	  
   /* Delay for 1ms to let the LCD execute command */
   /* SetE To HIGH */ 
   	_delay_ms(1);

	//Dio_enuWriteChannel(EN_PIN, DIO_u8LEVEL_LOW);

  /* Delay for 1ms to let the LCD execute command */	
	

}

/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteCharctr(u8 u8DataCpy)
{

/* Set RS to LOW */
Dio_enuWriteChannel(RS_PIN, DIO_u8LEVEL_HIGH);

/* Set R/W to LOW */
Dio_enuWriteChannel(RW_PIN, DIO_u8LEVEL_LOW);

/* Set E to HIGH  */
Dio_enuWriteChannel(EN_PIN , DIO_u8LEVEL_HIGH);

/* Load Command on Data bus */

Dio_enuWriteChannel(DATA_PIN4 , GET_BIT(u8DataCpy ,4)) ;
Dio_enuWriteChannel(DATA_PIN5 , GET_BIT(u8DataCpy ,5)) ;
Dio_enuWriteChannel(DATA_PIN6 , GET_BIT(u8DataCpy ,6)) ;
Dio_enuWriteChannel(DATA_PIN7 , GET_BIT(u8DataCpy ,7)) ;

_delay_ms(1);
Dio_enuWriteChannel(EN_PIN , DIO_u8LEVEL_LOW);

_delay_ms(1);

/* Set E to LOW */
Dio_enuWriteChannel(EN_PIN, DIO_u8LEVEL_HIGH);

/* Wait for E to settle */
_delay_ms(1);

/* Set E to HIGH */

Dio_enuWriteChannel(DATA_PIN4 , GET_BIT(u8DataCpy ,0)) ;
Dio_enuWriteChannel(DATA_PIN5 , GET_BIT(u8DataCpy ,1)) ;
Dio_enuWriteChannel(DATA_PIN6 , GET_BIT(u8DataCpy ,2)) ;
Dio_enuWriteChannel(DATA_PIN7 , GET_BIT(u8DataCpy ,3)) ;

_delay_ms(1) ;

/* Delay for 1ms to let the LCD execute command */
/* SetE To HIGH */
Dio_enuWriteChannel(EN_PIN, DIO_u8LEVEL_LOW);

/* Delay for 1ms to let the LCD execute command */
_delay_ms(1);
}

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteString (u8* pu8StringCpy)
{


	u8 iteration=0;
	while (pu8StringCpy[iteration] != '\0')
{
		/* Write Character on LCD */
		LCD_vidWriteCharctr(pu8StringCpy[iteration]);

		iteration++;
}
		/* Delay to let the LCD show the character */
		_delay_ms(2);
	}



/***************************************************************************************/
/* Description! Interface to start the writing process at certain digit in the LCD     */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
/*
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

*/
void LCD_displayInteger(u64 a_integerNumber)
{	
	if(a_integerNumber == 0)
	{
		
		LCD_vidWriteCharctr('0');
	}
	else
	{
		u64 LOC_reversedNumber = 1;

		while(a_integerNumber != 0)
		{
			LOC_reversedNumber = (LOC_reversedNumber * 10) + (a_integerNumber % 10);
			a_integerNumber /= 10;
		}

		while(LOC_reversedNumber != 1)
		{
			LCD_vidWriteCharctr((LOC_reversedNumber % 10) + '0');
			LOC_reversedNumber /= 10;
		}
	}
}



void LCD_voidGotToXY (u8 Copy_u8XPos,u8 Copy_u8YPos )
{
	u8 Local_u8Address ; 
	if (Copy_u8XPos == 0 )
	{
		Local_u8Address = Copy_u8YPos;
		
	}
	else if (Copy_u8XPos == 1)
	{
		Local_u8Address = Copy_u8YPos +0x40 ; 
	}
		LCD_vidSendCommand(Local_u8Address + 128 );

}


void LCD_voidWriteSpecialCharacter(u8* copy_u8Pattern , u8 copy_u8PatternNumber )
{
	u8 LOC_u8CGRAMAdrress = 0 ;
	u8 LOC_u8Iterator ;
	/* Calculate CGRAM ADDRESS whose each block is 8 Bytes */
	LOC_u8CGRAMAdrress =  copy_u8PatternNumber* 8 ;
	
	/* Send CGRAM ADRREESS Command To LCD with Setting Bit 6 , Clearing Bit & */
	
	LCD_vidSendCommand(LOC_u8CGRAMAdrress+64);
	for (LOC_u8Iterator = 0 ; LOC_u8Iterator < 8 ; LOC_u8Iterator++)
	{
		LCD_vidWriteCharctr(*(copy_u8Pattern+LOC_u8Iterator));
	}
	/* Go Back To DDRAM TO Display The PAttern */
	//LCD_voidGotToXY(XPos , YPos);
	LCD_vidSendCommand(0x80);
	/* display The Pattern Written in The CG_RAM*/
	//LCD_vidWriteCharctr(copy_u8PatternNumber);
}


void LCD_CLEAR (void)
{
	LCD_vidSendCommand(lcd_Clear) ; 
}

