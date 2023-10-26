
#include "../../../services/Std_types.h"
#include "../../../services/Bit_utils.h"
#include <util/delay.h>
#include "../../../MCAL/PORT/include/port.h"
#include "../../../MCAL/DIO/include/DIO.h"
#include "../../../HAL//LCD/LCD_config.h"
#include "../../../HAL//LCD/LCD_interface.h"


#define HIGH_LEVEL 1
#define LOW_LEVEL 0

void LCD_voidInit(void)
{



	Port_setPinDirection(D0_PIN,PIN_OUTPUT);
	Port_setPinDirection(D1_PIN,PIN_OUTPUT);
	Port_setPinDirection(D2_PIN,PIN_OUTPUT);
	Port_setPinDirection(D3_PIN,PIN_OUTPUT);
	Port_setPinDirection(D4_PIN,PIN_OUTPUT);
	Port_setPinDirection(D5_PIN,PIN_OUTPUT);
	Port_setPinDirection(D6_PIN,PIN_OUTPUT);
	Port_setPinDirection(D7_PIN,PIN_OUTPUT);

	Port_setPinDirection(RS_PIN,PIN_OUTPUT);
	Port_setPinDirection(RW_PIN,PIN_OUTPUT);
	Port_setPinDirection(EN_PIN,PIN_OUTPUT);
	
	_delay_ms(5);
	_delay_ms(20);       //wait for start initialization
	LCD_voidSendCommand(0x38);   //8bit mode
	LCD_voidSendCommand(0x0E);   //curser not be blinking
	LCD_voidSendCommand(0x01);   // clear display
	_delay_ms(2);
	//LCD_voidSendCommand(0x06);   //INCREAMENT CURSOR TO RIGHT

}

void LCD_voidWriteCharacter(u8 Character)
{

	DIO_WritrPin(RW_PIN,LOW_LEVEL);
	DIO_WritrPin(RS_PIN,HIGH_LEVEL);
	//DIO_WritePin(RW_PORT,RW_PIN,LOW_LEVEL);

	DIO_WritrPin(D0_PIN,GET_BIT(Character,0));
	DIO_WritrPin(D1_PIN,GET_BIT(Character,1));
	DIO_WritrPin(D2_PIN,GET_BIT(Character,2));
	DIO_WritrPin(D3_PIN,GET_BIT(Character,3));
	DIO_WritrPin(D4_PIN,GET_BIT(Character,4));
	DIO_WritrPin(D5_PIN,GET_BIT(Character,5));
	DIO_WritrPin(D6_PIN,GET_BIT(Character,6));
	DIO_WritrPin(D7_PIN,GET_BIT(Character,7));

	DIO_WritrPin(EN_PIN,HIGH_LEVEL);
	_delay_ms(00);
	DIO_WritrPin(EN_PIN,LOW_LEVEL);

}
void LCD_voidSendCommand(u8 Command)
{
	DIO_WritrPin(RS_PIN,LOW_LEVEL);
	DIO_WritrPin(RW_PIN,LOW_LEVEL);

	DIO_WritrPin(D0_PIN,GET_BIT(Command,0));
	DIO_WritrPin(D1_PIN,GET_BIT(Command,1));
	DIO_WritrPin(D2_PIN,GET_BIT(Command,2));
	DIO_WritrPin(D3_PIN,GET_BIT(Command,3));
	DIO_WritrPin(D4_PIN,GET_BIT(Command,4));
	DIO_WritrPin(D5_PIN,GET_BIT(Command,5));
	DIO_WritrPin(D6_PIN,GET_BIT(Command,6));
	DIO_WritrPin(D7_PIN,GET_BIT(Command,7));

	DIO_WritrPin(EN_PIN,HIGH_LEVEL);
		_delay_us(1);
	//_delay_ms(2);				
	DIO_WritrPin(EN_PIN,LOW_LEVEL);
		_delay_us(100);
		_delay_ms(10);


}
void LCD_voidCustomChar (unsigned char loc, unsigned char *msg)
{
	unsigned char i;
	if(loc<8)
	{
		LCD_voidSendCommand (0x40 + (loc*8));	/* Command 0x40  point CGRAM address */
		for(i=0;i<8;i++)	/* Write 8 byte for generation of 1 character */
		LCD_voidWriteCharacter(msg[i]);
	}
	  LCD_voidSendCommand(0x80); //shift back to DDRAM location 0
}
void LCD_voidWriteString(u8 *string)
{

	while(*string!='\0')
	{
		LCD_voidWriteCharacter(*string);
		string++;

	}


}
u8 ARR_LOC_ROWS[]={0x80,0xC0,0x94,0xD4};
/*void LCD_voidSetCursor(u8 x,u8 y)
{
	
	LCD_voidSendCommand(ARR_LOC_ROWS[x-1]+(y-1));
}
*/
void LCD_voidSetCursor(u8 x, u8 y)
{
	if((x<20)&&(y<4))
	{
		
		u8 loc_address;
		switch(y)
		{
			case 0:loc_address=0x80+0x00; break;
			case 1:loc_address=0x80+0x40; break;
			case 2:loc_address=0x80+0x14; break;						
			case 3:loc_address=0x80+0x54; break;			
		}	
		LCD_voidSendCommand(loc_address+x);   
		}		
}

void LCD_voidClear(void)
{
	LCD_voidSendCommand(0x01);
}

void Lcd_voidShiftRight(void)
{
	LCD_voidSendCommand(0x1C);
	//LCD_voidSendCommand(0x14);   //INCREAMENT CURSOR TO RIGHT
}

void Lcd_voidShiftLeft(void)
{
	LCD_voidSendCommand(0x18);
}


