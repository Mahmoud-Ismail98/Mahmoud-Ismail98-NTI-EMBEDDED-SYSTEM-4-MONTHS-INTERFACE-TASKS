/*
 * keyPad.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Ahmed Dwidar
 */
#include"keyPad.h"
#include"util/delay.h"

static u8 KEYPAD_4x4_adjustKeyNumber(u8 rows,u8 cols);

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
					return KEYPAD_4x4_adjustKeyNumber(row,col);
					}
				}
				setPinDirection(KEYPAD_FIRST_ROW_PIN_ID+row,PIN_INPUT);
					_delay_ms(5);
			}

	 }
}

static u8 KEYPAD_4x4_adjustKeyNumber(u8 rows,u8 cols)
{
	u8 keypad_button = 0;

	u8 buttonNumber[4][4] = {{7,8,9,'%'},{4,5,6,'*'},{1,2,3,'-'},{13,0,'=','+'}};


	keypad_button = buttonNumber[rows][cols];
	return keypad_button;

}

