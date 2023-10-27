/*
=======================================================================================================================
Author       : Mamoun
Module       : 
File Name    : BoyStory.c
Date Created : Oct 26, 2023
Description  : 
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../OTHERS/std_types.h"
#include "../OTHERS/common_macros.h"
#include "../MCAL/PORT/INCLUDES/port.h"
#include "../MCAL/DIO/INCLUDES/dio.h"
#include "../HAL/LCD/INCLUDES/lcd.h"
#include "BoyStory.h"
#include <util/delay.h>

/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/



/*=====================================================================================================================
                                      < Private Functions Prototypes >
=====================================================================================================================*/



/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : 
 * [Description]   : 
 * [Arguments]     : <>      -> 
 *                   <>      -> 
 * [return]        : The function returns void.
 ====================================================================================================================*/
int main(void)
{
	InitSystem();

	while(1)
	{
		CreateFrame1();
		MoveFrame1();
		CreateFrame2();
		MoveFrame2();
		CreateFrame3();
		MoveFrame3();
	}
}

void InitSystem(void)
{
	PORT_init();
	LCD_init();
	CreateStorySympols();
}

void CreateStorySympols(void)
{
	uint8 sympols[3][8] = {{0x0E,0x0E,0x04,0x0E,0x15,0x0E,0x11,0x00},
                           {0x00,0x01,0x03,0x07,0x0F,0x1F,0x1F,0x00},
			               {0x04,0x0E,0x1F,0x1F,0x04,0x04,0x1F,0x00}};

	for(uint8 iterator = 0; iterator < 3; iterator++)
	{
		LCD_createCustomCharacter(*(sympols + iterator),iterator);
	}
}

void CreateFrame1(void)
{
	uint8 frame1[][20] = {{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	                  {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
					  {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
					  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}};

	for(uint8 row_iterator = 0; row_iterator < 4; row_iterator++)
	{
		LCD_moveCursor(row_iterator,0);
		for(uint8 column_iterator = 0; column_iterator < 20; column_iterator++)
		{
			LCD_displayCharacter(*(*(frame1 + row_iterator) + column_iterator));
		}
	}

	_delay_ms(1000);
}

void MoveFrame1(void)
{
	LCD_moveCursor(1,0);
	LCD_displayCharacter(0);
	_delay_ms(100);

	for(uint8 step = 1; step < 20; step++)
	{
		LCD_moveCursor(1,step);
		LCD_displayCharacter(0);
		LCD_moveCursor(1,step - 1);
		LCD_displayCharacter('_');
		_delay_ms(100);
	}

	LCD_moveCursor(1,19);
	LCD_displayCharacter('_');
	_delay_ms(150);

	for(uint8 step = 1; step < 20; step++)
	{
		LCD_moveCursor(2,step);
		LCD_displayCharacter(0);
		LCD_moveCursor(2,step - 1);
		LCD_displayCharacter('_');
		_delay_ms(100);
	}

	LCD_moveCursor(2,19);
	LCD_displayCharacter('_');
	_delay_ms(150);
}

void CreateFrame2(void)
{
	uint8 frame1[][20] = {{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	                  {'_','_','_','_','_','_','_','_','_',' ','_','_','_','_','_','_','_','_','_','_'},
					  {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
					  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}};

	for(uint8 row_iterator = 0; row_iterator < 4; row_iterator++)
	{
		LCD_moveCursor(row_iterator,0);
		for(uint8 column_iterator = 0; column_iterator < 20; column_iterator++)
		{
			LCD_displayCharacter(*(*(frame1 + row_iterator) + column_iterator));
		}
	}
}

void MoveFrame2(void)
{
	LCD_moveCursor(1,0);
	LCD_displayCharacter(0);

	for(uint8 step = 1; step < 10; step++)
	{
		LCD_moveCursor(1,step);
		LCD_displayCharacter(0);
		LCD_moveCursor(1,step - 1);
		LCD_displayCharacter('_');
		_delay_ms(100);
	}

	LCD_moveCursor(1,9);
	LCD_displayCharacter(' ');
	LCD_moveCursor(2,9);
	LCD_displayCharacter(0);
	_delay_ms(200);

	for(uint8 step = 10; step < 20; step++)
	{
		LCD_moveCursor(2,step);
		LCD_displayCharacter(0);
		LCD_moveCursor(2,step - 1);
		LCD_displayCharacter('_');
		_delay_ms(100);
	}

	LCD_moveCursor(2,19);
	LCD_displayCharacter('_');
	_delay_ms(150);
}

void CreateFrame3(void)
{
	uint8 frame1[][20] = {{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	                  {'_','_','_','_','_','_','_','_','_',' ','_','_','_','_','_','_','_','_','_','_'},
					  {'_','_','_','_','_','_','_','_','_',1,'_','_','_','_','_','_','_','_','_','_'},
					  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}};

	for(uint8 row_iterator = 0; row_iterator < 4; row_iterator++)
	{
		LCD_moveCursor(row_iterator,0);
		for(uint8 column_iterator = 0; column_iterator < 20; column_iterator++)
		{
			LCD_displayCharacter(*(*(frame1 + row_iterator) + column_iterator));
		}
	}
}

void MoveFrame3(void)
{
	LCD_moveCursor(2,0);
	LCD_displayCharacter(0);

	for(uint8 step = 1; step < 10; step++)
	{
		LCD_moveCursor(2,step);
		LCD_displayCharacter(0);
		LCD_moveCursor(2,step - 1);
		LCD_displayCharacter('_');
		_delay_ms(100);
	}

	LCD_moveCursor(1,9);
	LCD_displayCharacter(0);
	LCD_moveCursor(2,9);
	LCD_displayCharacter(1);
	_delay_ms(200);

	for(uint8 step = 10; step < 20; step++)
	{
		LCD_moveCursor(1,step);
		LCD_displayCharacter(0);
		LCD_moveCursor(1,step - 1);
		LCD_displayCharacter('_');
		_delay_ms(100);
	}

	LCD_moveCursor(1,19);
	LCD_displayCharacter('_');
	_delay_ms(150);
}
