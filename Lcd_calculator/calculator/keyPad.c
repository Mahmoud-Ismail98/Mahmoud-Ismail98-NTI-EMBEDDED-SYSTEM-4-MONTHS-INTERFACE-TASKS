/*
 * keyPad.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Ahmed Dwidar
 */
#include"keyPad.h"
#include"util/delay.h"

static u8 KEYPAD_4x4_adjustKeyNumber(u8 button_number);

u8 KEYPAD_getPressedKey(void)
{
	u8 row,col;
	setPinDirection(KEYPAD_FIRST_ROW_PIN_ID, PIN_INPUT);
	setPinDirection(KEYPAD_FIRST_ROW_PIN_ID +1, PIN_INPUT);
	setPinDirection(KEYPAD_FIRST_ROW_PIN_ID+2, PIN_INPUT);
	setPinDirection(KEYPAD_FIRST_ROW_PIN_ID+3,PIN_INPUT);

	setPinDirection(KEYPAD_FIRST_COL_PIN_ID, PIN_INPUT);
	setPinDirection(KEYPAD_FIRST_COL_PIN_ID +1, PIN_INPUT);
	setPinDirection(KEYPAD_FIRST_COL_PIN_ID+2, PIN_INPUT);
	setPinDirection(KEYPAD_FIRST_COL_PIN_ID+3, PIN_INPUT);

	 while(1)
	 {
			for(row=0 ; row<KEYPAD_NUM_ROWS ; row++)
			{
				setPinDirection(KEYPAD_FIRST_ROW_PIN_ID+row,PIN_OUTPUT);
				dio_writePin(KEYPAD_FIRST_ROW_PIN_ID+row, KEYPAD_BUTTON_PRESSED);

				for(col=0 ; col<KEYPAD_NUM_COLS ; col++)
				{

					if(dio_readPin(KEYPAD_FIRST_COL_PIN_ID+col)== KEYPAD_BUTTON_PRESSED)
					{
						return KEYPAD_4x4_adjustKeyNumber((row*KEYPAD_NUM_COLS)+col+1);
					}
				}
				setPinDirection(KEYPAD_FIRST_ROW_PIN_ID+row,PIN_INPUT);
					_delay_ms(5);
			}

	 }
}

static u8 KEYPAD_4x4_adjustKeyNumber(u8 button_number)
{
	u8 keypad_button = 0;
	switch(button_number)
	{
		case 1: keypad_button = 7;
				break;
		case 2: keypad_button = 8;
				break;
		case 3: keypad_button = 9;
				break;
		case 4: keypad_button = '%';
				break;
		case 5: keypad_button = 4;
				break;
		case 6: keypad_button = 5;
				break;
		case 7: keypad_button = 6;
				break;
		case 8: keypad_button = '*';
				break;
		case 9: keypad_button = 1;
				break;
		case 10: keypad_button = 2;
				break;
		case 11: keypad_button = 3;
				break;
		case 12: keypad_button = '-';
				break;
		case 13: keypad_button = 13;
				break;
		case 14: keypad_button = 0;
				break;
		case 15: keypad_button = '=';
				break;
		case 16: keypad_button = '+';
				break;
		default: keypad_button = button_number;
				break;
	}
	return keypad_button;
}
