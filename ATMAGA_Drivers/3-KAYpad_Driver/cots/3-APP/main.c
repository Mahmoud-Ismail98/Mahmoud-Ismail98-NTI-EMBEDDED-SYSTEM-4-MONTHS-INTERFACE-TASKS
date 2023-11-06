/*
 * main.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Online
 */

#include "../4-SERVICS/Bit_utils.h"
#include "../4-SERVICS/Std_types.h"
#include "../1-MCAL/01-DIO/DIO_Int.h"
#include "../2-HAL/1-LCD/LCD.h"
#include "../2-HAL/2-Kpad/include/Kpad.h"
#include "util/delay.h"

u8 PATTERN[8] = {
	0b01110,
	0b01110,
	0b00100,
	0b00100,
	0b11111,
	0b11011,
	0b11011,
	0b00000
};


void CreateFrame(void);
void CreateFrame2(void);
void CreateFrame3(void);
void CreateFrame4(void);
void CreateFrame5(void);
int main(void) {
	MDIO_VidSetPortDirection(Port_B,0xFF);
	MDIO_VidSetPinDirection(Port_A,Pin_0,Pin_Output);
	MDIO_VidSetPinDirection(Port_A,Pin_1,Pin_Output);
	MDIO_VidSetPinDirection(Port_A,Pin_2,Pin_Output);
 CLCD_VoidInit();
  CLCD_voidCreateSpeacialCharater(PATTERN , 0,0,0) ;
	u8 characterToMove = 0;

	while (1) {


		   CreateFrame();
		for (u8 column = 0; column < 15; column++) {

			if (column > 0 )
			{

				SendCharacter(0, column - 1, '_');
			}

			SendCharacter(0, column, characterToMove);
			_delay_ms(100);
		}

		CLCD_voidClearDisplay() ;
		CreateFrame();



		for (u8 column = 0; column < 17; column++) {

			if (column > 0) {
				SendCharacter(1, column - 1, '_');
			}


			SendCharacter(1, column, characterToMove);


			_delay_ms(100);
		}

		CLCD_voidClearDisplay();
        CreateFrame2();
      for (u8 column = 0; column <=8; column++) {
	      if (column > 0) {
	    	  SendCharacter(0, column - 1, '_');
	      }

	      // Display the character at the new position
	      SendCharacter(0, column, characterToMove);


	      // Add a delay to control the speed of character movement
	      _delay_ms(100); // Adjust the delay as needed
      }
      CLCD_voidClearDisplay();

	  for (u8 column = 8; column < 16; column++) {
		  // Clear the character at the previous position (if applicable)
		  if (column >= 8) {
			  SendCharacter(1, column - 1, '_');
		  }

		  // Display the character at the new position
		  SendCharacter(1, column, characterToMove);

		  // Add a delay to control the speed of character movement
		  _delay_ms(100); // Adjust the delay as needed
	  }
	  CLCD_voidClearDisplay();

      CreateFrame3();
     for (u8 column = 0; column <=8; column++) {
	     // Clear the character at the previous position (if applicable)
	     if (column > 0) {
	    	 SendCharacter(1, column - 1, '_');
	     }

	     // Display the character at the new position
	     SendCharacter(1, column, characterToMove);

	     // Add a delay to control the speed of character movement
	     _delay_ms(100); // Adjust the delay as needed
     }
     CLCD_voidClearDisplay();

     CreateFrame4();
     for (u8 column = 8; column < 16; column++) {
	     // Clear the character at the previous position (if applicable)
	     if (column >= 8) {
	    	 SendCharacter(0, column - 1, '_');
	     }

	     // Display the character at the new position
	     SendCharacter(0, column, characterToMove);

	     // Add a delay to control the speed of character movement
	     _delay_ms(100); // Adjust the delay as needed
     }
     CLCD_voidClearDisplay();
	 //CreateFrame5();
  for (u8 column = 0; column < 13; column++) {
	  /*Clear the character at the previous position (if applicable)*/

	  if (column > 0) {
		  SendCharacter(0, column - 1, '_');
	  }

	  // Display the character at the new position
	  SendCharacter(0, column, characterToMove);

	  // Add a delay to control the speed of character movement
	  _delay_ms(500); // Adjust the delay as needed
  }
  CLCD_voidClearDisplay();
  CLCD_voidGoToXY(0,0);
  ClCD_voidSendString("Game Over");
  _delay_ms(3000);
  CLCD_voidClearDisplay();
  _delay_ms(3000);
}
	return 0;

}



void CreateFrame(void)
{
	u8 frame1[][15] = {
	{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
	{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
	};

	for(u8 row_iterator = 0; row_iterator < 2; row_iterator++)
	{
		CLCD_voidGoToXY(row_iterator,0);
		for(u8 column_iterator = 0; column_iterator < 16; column_iterator++)
		{
			CLCD_voidSendData(*(*(frame1 + row_iterator) + column_iterator));
		}
	}
}
void CreateFrame2(void)
{
	u8 frame1[][17] = {
		{'_','_','_','_','_','_','_','_','_','_','_','_','| '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	};

	for(u8 row_iterator = 0; row_iterator < 2; row_iterator++)
	{
		CLCD_voidGoToXY(row_iterator,0);
		for(u8 column_iterator = 0; column_iterator < 16; column_iterator++)
		{
			CLCD_voidSendData(*(*(frame1 + row_iterator) + column_iterator));
		}
	}
}
void CreateFrame3(void)
{
	u8 frame1[][17] = {
		{'_','_','_','_','_','_','_','_',' ',' ','_','_','_','_','_','_' },
		{'_','_','_','_','_','_','_','_','_','/','_','_','_','_','_','_','_'},
	};

	for(u8 row_iterator = 0; row_iterator < 2; row_iterator++)
	{
		CLCD_voidGoToXY(row_iterator,1);
		for(u8 column_iterator = 0; column_iterator < 16; column_iterator++)
		{
			CLCD_voidSendData(*(*(frame1 + row_iterator) + column_iterator));
		}
	}
}
void CreateFrame4(void)
{
	u8 frame1[][15] = {
		{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
		{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
	};

	for(u8 row_iterator = 0; row_iterator < 2; row_iterator++)
	{
		CLCD_voidGoToXY(row_iterator,0);
		for(u8 column_iterator = 0; column_iterator < 16; column_iterator++)
		{
			CLCD_voidSendData(*(*(frame1 + row_iterator) + column_iterator));
		}
	}
}


void CreateFrame5(void)
{
	u8 frame1[][15] = {
		{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
		{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
	};

	for(u8 row_iterator = 0; row_iterator < 2; row_iterator++)
	{
		CLCD_voidGoToXY(row_iterator,0);
		for(u8 column_iterator = 0; column_iterator < 16; column_iterator++)
		{
			CLCD_voidSendData(*(*(frame1 + row_iterator) + column_iterator));
		}
	}
}
