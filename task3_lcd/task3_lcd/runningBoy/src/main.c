/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Dwidar
 */

#include "../includes/Hal/lcd.h"


void runningBoy_dispaly(void)
{
	u8 customChar[] = {
			  0b00100,
			  0b01110,
			  0b01111,
			  0b01001,
			  0b10010,
			  0b10010,
			  0b01010,
			  0b01110
			};
	LCD_creatCustomCharacter(customChar,0);

	u8 row = 0,col = 0;
	u8 flag = 0;

	while( (row < 2) || (col < 16) )
	{

		if(col == 15 && row == 1)
		{
			row = 0;
			col = 0;
		}
		if(flag == 2)
		{
			flag = 0;
			col = 9;
			row = 1;

		}
		if( (row == 1 ) && ( col == 7) )
		{
			row = 0;
			col = 6;
			flag++;
		}
    	LCD_moveCurser(1,8);
    	LCD_displayCharacter('/');

		LCD_moveCurser(row,col);

		LCD_displayCharacter(0);

		LCD_sendCommand(0xc0);

		_delay_ms(200);
		LCD_clearScreen();

		if(col == 15)
		{
			row++;
			col = 0;

		}


		col++;
	}


}

int main(void)
{

	port_init();
	LCD_init();


    while(1)
    {
    	runningBoy_dispaly();
    }
}

