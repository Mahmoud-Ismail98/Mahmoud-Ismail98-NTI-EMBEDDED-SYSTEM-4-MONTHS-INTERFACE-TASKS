#include "../../../services/Bit_utils.h"
#include "../../../services/Std_types.h"
#include "../../../MCAL/PORT/include/port.h"
#include "../../../MCAL/DIO/include/DIO.h"
#include <util/delay.h>

u8 check_hole=0;
u8 check_ramp=0;
u8 check_wall=0;
u8 game_over=0;
void hole(u8 raw,u8 col)
{
	LCD_voidSetCursor(col,raw);
	LCD_voidWriteCharacter(' ');
	check_hole=1;
}
void ramp(u8 raw,u8 col)
{
	LCD_voidSetCursor(col,raw);
	LCD_voidWriteCharacter('/');
	check_ramp=1;
}
void wall(u8 raw,u8 col)
{
	LCD_voidSetCursor(col,raw);
	LCD_voidWriteCharacter('|');
	check_wall=1;
}
int main(void)
{
	//  unsigned char Character1[8] = { 0x00, 0x0A, 0x15, 0x11, 0x0A, 0x04, 0x00, 0x00 };  /* Custom char set for alphanumeric LCD Module */
	char customChar1[8] = {
		0b11111,
		0b10001,
		0b11111,
		0b00100,
		0b00100,
		0b11111,
		0b00100,
		00100
	};
	char customChar2[8] = {
		0x0E,
		0x0E,
		0x0E,
		0x0E,
		0x0E,
		0x0E,
		0x0E,
		0x0E
	};
	LCD_voidInit(); 
	LCD_voidCustomChar(0, customChar1);   
	LCD_voidCustomChar(1, customChar2);  	
	//LCD_voidWriteCharacter(0); 
	for (u8 raw=0; raw<4;raw++)
	{

		for (u8 col=0;col<20;col++)
		{
			if (col==0)
			{
				//continue;
				//LCD_voidWriteCharacter('|');
				//continue;
			}
			LCD_voidSetCursor(col,raw);
			LCD_voidWriteCharacter('_');
		}
	}
	LCD_voidSetCursor(0,0);
	while(game_over==0)
	{
	for (u8 raw=0; raw<4;raw++)
	{
		if (check_hole==0 && raw==0)
		{
			hole(0,6);	
		}

		else if (check_ramp==0 && raw==2)
		{
			raw=1;
			ramp(1,6);
			
		}	
		
		else if (check_ramp==2&&check_wall==0&&raw==2)
		{
			wall(2,15);
		//	raw=0;
		}
			
		for (u8 col=0;col<20;col++)
		{
			if (col==6 && raw==0&&check_hole==1)
			{
				raw=1;
				col=5;
				check_hole=2;
				continue;
				//col;
			}
			if (col==6 && raw==1 && check_ramp==1&&check_wall==0)
			{
				LCD_voidWriteCharacter('_'); 
				raw=0;
				check_ramp=2;
			}
			if (col==15 && check_wall==1)
			{
				game_over=1;
				break;
			}
		   LCD_voidSetCursor(col,raw);
		   LCD_voidWriteCharacter(0); 
		   _delay_ms(100);
		   LCD_voidSetCursor(col,raw);
		   LCD_voidWriteCharacter('_'); 
		}
		if (game_over==1)
		{
				
		   LCD_voidSendCommand(0x01);   // clear display
		   LCD_voidSetCursor(4,1);
		   LCD_voidWriteString("game over");
		   break;

		}
	}
	}	
}
