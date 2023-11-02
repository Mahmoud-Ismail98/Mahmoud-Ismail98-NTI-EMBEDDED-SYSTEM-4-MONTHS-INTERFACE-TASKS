/*
 * app.c
 *
 * Created: 11/1/2023 7:05:47 PM
 *  Author: sharb
 */ 

#include "std_types.h"
#include "../../MCAL/PORT/includes/PORT.h"
#include "../../HAL/LCD/includes/Lcd.h"
#include "../includes/app.h"


#include "util/delay.h"

u8 gl_u8_ManShape[] = {0b00000100,0b00001110,0b00010101,0b00000100,0b00001010,0b00010001,0b00010001};
void app_init(void)
{
	PORT_voidInit();
	LCD_vidInit();
	LCD_vidCreateCustomCharacter(gl_u8_ManShape,MAN_INDEX);
}


void app_start(void)
{
	
	while(1)
	{
		welcomeScreen();
		Screen_one();
		Screen_two();
		Screen_three();
		GameOver();
		while(1);
	}
}


void welcomeScreen(void)
{
	u8 loc_u8_itrator = TRUE;
	LCD_vidClrDisplay();
	LCD_vidGoToXY(0,5);
	LCD_vidDisplayString("WELCOME...");
	LCD_vidGoToXY(1,5);
	LCD_vidDisplayString("Crazy Man");
	for (;loc_u8_itrator<20;loc_u8_itrator++)
	{
		LCD_vidGoToXY(3,loc_u8_itrator);
		LCD_vidDisplayCharacter(MAN_INDEX);
		LCD_vidGoToXY(3,loc_u8_itrator-1);
		LCD_vidDisplayCharacter(" ");
		_delay_ms(150);
		
	}
}
void Screen_one(void)
{
	LCD_vidClrDisplay();
	u8 loc_u8_rowItrator = FALSE;
	u8 loc_u8_colItrator = FALSE;
	for(;loc_u8_colItrator<20;loc_u8_colItrator++)
	{
	    LCD_vidGoToXY(0,loc_u8_colItrator);
	    LCD_vidDisplayCharacter('_');
		LCD_vidGoToXY(1,loc_u8_colItrator);
		LCD_vidDisplayCharacter('_');
		LCD_vidGoToXY(2,loc_u8_colItrator);
		LCD_vidDisplayCharacter('_');
		LCD_vidGoToXY(3,loc_u8_colItrator);
		LCD_vidDisplayCharacter('_');
    }
	
	for(loc_u8_colItrator=TRUE;loc_u8_colItrator<20;loc_u8_colItrator++)
	{
		LCD_vidGoToXY(0,loc_u8_colItrator);
		LCD_vidDisplayCharacter(MAN_INDEX);
		LCD_vidGoToXY(0,loc_u8_colItrator-1);
		LCD_vidDisplayCharacter('_');
		_delay_ms(150);
	}
	LCD_vidGoToXY(0,loc_u8_colItrator-1);
	LCD_vidDisplayCharacter('_');
	for(loc_u8_colItrator=TRUE;loc_u8_colItrator<20;loc_u8_colItrator++)
	{
		LCD_vidGoToXY(1,loc_u8_colItrator);
		LCD_vidDisplayCharacter(MAN_INDEX);
		LCD_vidGoToXY(1,loc_u8_colItrator-1);
		LCD_vidDisplayCharacter('_');
		_delay_ms(150);
	}
	LCD_vidGoToXY(1,loc_u8_colItrator-1);
	LCD_vidDisplayCharacter('_');
	for(loc_u8_colItrator=TRUE;loc_u8_colItrator<20;loc_u8_colItrator++)
	{
		LCD_vidGoToXY(2,loc_u8_colItrator);
		LCD_vidDisplayCharacter(MAN_INDEX);
		LCD_vidGoToXY(2,loc_u8_colItrator-1);
		LCD_vidDisplayCharacter('_');
		_delay_ms(150);
	}
	LCD_vidGoToXY(2,loc_u8_colItrator-1);
	LCD_vidDisplayCharacter('_');
	for(loc_u8_colItrator=TRUE;loc_u8_colItrator<20;loc_u8_colItrator++)
	{
		LCD_vidGoToXY(3,loc_u8_colItrator);
		LCD_vidDisplayCharacter(MAN_INDEX);
		LCD_vidGoToXY(3,loc_u8_colItrator-1);
		LCD_vidDisplayCharacter('_');
		_delay_ms(150);
	}
	LCD_vidGoToXY(3,loc_u8_colItrator-1);
	LCD_vidDisplayCharacter('_');

}
void Screen_two(void)
{
	LCD_vidClrDisplay();
	u8 loc_u8_rowItrator = FALSE;
	u8 loc_u8_colItrator = FALSE;
	for(;loc_u8_colItrator<20;loc_u8_colItrator++)
	{
		if (loc_u8_colItrator == 5)
		{
			LCD_vidGoToXY(0,loc_u8_colItrator);
			LCD_vidDisplayCharacter(' ');
		}
		else
		{
			LCD_vidGoToXY(0,loc_u8_colItrator);
			LCD_vidDisplayCharacter('_');
		}
		LCD_vidGoToXY(1,loc_u8_colItrator);
		LCD_vidDisplayCharacter('_');
		LCD_vidGoToXY(2,loc_u8_colItrator);
		LCD_vidDisplayCharacter('_');
		LCD_vidGoToXY(3,loc_u8_colItrator);
		LCD_vidDisplayCharacter('_');
	}
	for(loc_u8_colItrator=TRUE;loc_u8_colItrator<20;loc_u8_colItrator++)
	{
		if (loc_u8_colItrator == 5)break;
		LCD_vidGoToXY(0,loc_u8_colItrator);
		LCD_vidDisplayCharacter(MAN_INDEX);
		LCD_vidGoToXY(0,loc_u8_colItrator-1);
		LCD_vidDisplayCharacter('_');
		_delay_ms(150);
	}
	LCD_vidGoToXY(0,loc_u8_colItrator-1);
	LCD_vidDisplayCharacter('_');
	LCD_vidGoToXY(0,loc_u8_colItrator);
	LCD_vidDisplayCharacter('_');
	LCD_vidGoToXY(1,10);
	LCD_vidDisplayCharacter(' ');
	for(loc_u8_colItrator=5;loc_u8_colItrator<20;loc_u8_colItrator++)
	{
		if (loc_u8_colItrator == 10)break;
		LCD_vidGoToXY(1,loc_u8_colItrator);
		LCD_vidDisplayCharacter(MAN_INDEX);
		LCD_vidGoToXY(1,loc_u8_colItrator-1);
		LCD_vidDisplayCharacter('_');
		_delay_ms(150);
	}
	LCD_vidGoToXY(1,loc_u8_colItrator-1);
	LCD_vidDisplayCharacter('_');
	LCD_vidDisplayCharacter('_');
	for(loc_u8_colItrator=10;loc_u8_colItrator<20;loc_u8_colItrator++)
	{
		LCD_vidGoToXY(2,loc_u8_colItrator);
		LCD_vidDisplayCharacter(MAN_INDEX);
		LCD_vidGoToXY(2,loc_u8_colItrator-1);
		LCD_vidDisplayCharacter('_');
		_delay_ms(150);
	}
	LCD_vidGoToXY(2,loc_u8_colItrator-1);
	LCD_vidDisplayCharacter('_');
	for(loc_u8_colItrator=TRUE;loc_u8_colItrator<20;loc_u8_colItrator++)
	{
		LCD_vidGoToXY(3,loc_u8_colItrator);
		LCD_vidDisplayCharacter(MAN_INDEX);
		LCD_vidGoToXY(3,loc_u8_colItrator-1);
		LCD_vidDisplayCharacter('_');
		_delay_ms(150);
	}
	LCD_vidGoToXY(3,loc_u8_colItrator-1);
	LCD_vidDisplayCharacter('_');
}
void Screen_three(void)
{
	LCD_vidClrDisplay();
	u8 loc_u8_rowItrator = FALSE;
	u8 loc_u8_colItrator = FALSE;
	for(;loc_u8_colItrator<20;loc_u8_colItrator++)
	{
		if (loc_u8_colItrator == 8)
		{
			LCD_vidGoToXY(0,loc_u8_colItrator);
			LCD_vidDisplayCharacter(' ');
		}
		else
		{
			LCD_vidGoToXY(0,loc_u8_colItrator);
			LCD_vidDisplayCharacter('_');
		}
		LCD_vidGoToXY(1,loc_u8_colItrator);
		LCD_vidDisplayCharacter('_');
		LCD_vidGoToXY(2,loc_u8_colItrator);
		LCD_vidDisplayCharacter('_');
		LCD_vidGoToXY(3,loc_u8_colItrator);
		LCD_vidDisplayCharacter('_');
	}
	for(loc_u8_colItrator=TRUE;loc_u8_colItrator<20;loc_u8_colItrator++)
	{
		if (loc_u8_colItrator == 8)break;
		LCD_vidGoToXY(0,loc_u8_colItrator);
		LCD_vidDisplayCharacter(MAN_INDEX);
		LCD_vidGoToXY(0,loc_u8_colItrator-1);
		LCD_vidDisplayCharacter('_');
		_delay_ms(150);
	}
	LCD_vidGoToXY(0,loc_u8_colItrator-1);
	LCD_vidDisplayCharacter('_');
	LCD_vidGoToXY(0,loc_u8_colItrator);
	LCD_vidDisplayCharacter('_');
	LCD_vidGoToXY(1,10);
	LCD_vidDisplayCharacter(' ');
	for(loc_u8_colItrator=5;loc_u8_colItrator<20;loc_u8_colItrator++)
	{
		if (loc_u8_colItrator == 10)break;
		LCD_vidGoToXY(1,loc_u8_colItrator);
		LCD_vidDisplayCharacter(MAN_INDEX);
		LCD_vidGoToXY(1,loc_u8_colItrator-1);
		LCD_vidDisplayCharacter('_');
		_delay_ms(150);
	}
	LCD_vidGoToXY(1,loc_u8_colItrator-1);
	LCD_vidDisplayCharacter('_');
	LCD_vidDisplayCharacter('_');
	LCD_vidGoToXY(1,12);
	LCD_vidDisplayCharacter(' ');
	LCD_vidGoToXY(2,12);
	LCD_vidDisplayCharacter('/');
	for(loc_u8_colItrator=10;loc_u8_colItrator<20;loc_u8_colItrator++)
	{
		if (loc_u8_colItrator == 12)break;
		LCD_vidGoToXY(2,loc_u8_colItrator);
		LCD_vidDisplayCharacter(MAN_INDEX);
		LCD_vidGoToXY(2,loc_u8_colItrator-1);
		LCD_vidDisplayCharacter('_');
		_delay_ms(150);
	}
	LCD_vidGoToXY(2,loc_u8_colItrator-1);
	LCD_vidDisplayCharacter('_');
	LCD_vidDisplayCharacter('_');
	LCD_vidGoToXY(1,16);
	LCD_vidDisplayCharacter(' ');
	
	for(loc_u8_colItrator=12;loc_u8_colItrator<20;loc_u8_colItrator++)
	{
		if (loc_u8_colItrator == 16)break;
		LCD_vidGoToXY(1,loc_u8_colItrator);
		LCD_vidDisplayCharacter(MAN_INDEX);
		LCD_vidGoToXY(1,loc_u8_colItrator-1);
		LCD_vidDisplayCharacter('_');
		_delay_ms(150);
	}
	LCD_vidGoToXY(1,loc_u8_colItrator-1);
	LCD_vidDisplayCharacter('_');
	LCD_vidDisplayCharacter('_');
	for(loc_u8_colItrator=16;loc_u8_colItrator<20;loc_u8_colItrator++)
	{
		LCD_vidGoToXY(2,loc_u8_colItrator);
		LCD_vidDisplayCharacter(MAN_INDEX);
		LCD_vidGoToXY(2,loc_u8_colItrator-1);
		LCD_vidDisplayCharacter('_');
		_delay_ms(150);
	}
	LCD_vidGoToXY(2,loc_u8_colItrator-1);
	LCD_vidDisplayCharacter('_');
	LCD_vidDisplayCharacter('_');
	LCD_vidGoToXY(3,15);
	LCD_vidDisplayCharacter('|');
	for(loc_u8_colItrator=TRUE;loc_u8_colItrator<20;loc_u8_colItrator++)
	{
		if (loc_u8_colItrator == 15)break;
		LCD_vidGoToXY(3,loc_u8_colItrator);
		LCD_vidDisplayCharacter(MAN_INDEX);
		LCD_vidGoToXY(3,loc_u8_colItrator-1);
		LCD_vidDisplayCharacter('_');
		_delay_ms(150);
	}
	LCD_vidGoToXY(3,loc_u8_colItrator-1);
	LCD_vidDisplayCharacter('_');
}
void GameOver(void)
{
	u8 loc_u8_itrator = TRUE;
	LCD_vidClrDisplay();
	LCD_vidGoToXY(0,5);
	LCD_vidDisplayString("GAMEOVER!");
	LCD_vidGoToXY(1,5);
	LCD_vidDisplayString("Lazy Man");
	for (;loc_u8_itrator<20;loc_u8_itrator++)
	{
		LCD_vidGoToXY(3,loc_u8_itrator);
		LCD_vidDisplayCharacter(MAN_INDEX);
		LCD_vidGoToXY(3,loc_u8_itrator-1);
		LCD_vidDisplayCharacter('.');
		_delay_ms(200);
		
	}
}