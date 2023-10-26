#include <util/delay.h>
#include "Bit_utils.h"
#include "Std_types.h"

#include "Port.h"
#include "Dio.h"
#include "ADC.h"
#include "EXTI.h"

u8 HAMADA[8] = {
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


void moveCharacterOnLCD(u8 row, u8 column, u8 character) {
	// Set the cursor to the specified row and column
	LCD_voidGotToXY(row, column);

	// Display the character at the new position
	LCD_vidWriteCharctr(character);
}
int main(void) {
  Port_vidInit();
  LCD_vidInit() ; 
  LCD_voidWriteSpecialCharacter(HAMADA , 0) ; 
	u8 characterToMove = 0;

	while (1) {
		

		   CreateFrame();
		for (u8 column = 0; column < 15; column++) {
			/*Clear the character at the previous position (if applicable)*/
			
			if (column > 0 ) 
			{
				
				moveCharacterOnLCD(0, column - 1, '_');
			} 

			// Display the character at the new position
			moveCharacterOnLCD(0, column, characterToMove);
			

			// Add a delay to control the speed of character movement
			_delay_ms(100); // Adjust the delay as needed
		}
		
		LCD_CLEAR()  ; 
		CreateFrame();

		
		
		for (u8 column = 0; column < 17; column++) {
			// Clear the character at the previous position (if applicable)
			if (column > 0) {
				moveCharacterOnLCD(1, column - 1, '_');
			}

			// Display the character at the new position
			moveCharacterOnLCD(1, column, characterToMove);

			// Add a delay to control the speed of character movement
			_delay_ms(100); // Adjust the delay as needed
		}
		
		LCD_CLEAR();
        CreateFrame2();
      for (u8 column = 0; column <=8; column++) {
	      // Clear the character at the previous position (if applicable)
	      if (column > 0) {
		      moveCharacterOnLCD(0, column - 1, '_');
	      }

	      // Display the character at the new position
	      moveCharacterOnLCD(0, column, characterToMove);
			

	      // Add a delay to control the speed of character movement
	      _delay_ms(100); // Adjust the delay as needed
      }
      LCD_CLEAR();
	  
	  for (u8 column = 8; column < 16; column++) {
		  // Clear the character at the previous position (if applicable)
		  if (column >= 8) {
			  moveCharacterOnLCD(1, column - 1, '_');
		  }

		  // Display the character at the new position
		  moveCharacterOnLCD(1, column, characterToMove);

		  // Add a delay to control the speed of character movement
		  _delay_ms(100); // Adjust the delay as needed
	  }
	  LCD_CLEAR();
	  
      CreateFrame3();
     for (u8 column = 0; column <=8; column++) {
	     // Clear the character at the previous position (if applicable)
	     if (column > 0) {
		     moveCharacterOnLCD(1, column - 1, '_');
	     }

	     // Display the character at the new position
	     moveCharacterOnLCD(1, column, characterToMove);

	     // Add a delay to control the speed of character movement
	     _delay_ms(100); // Adjust the delay as needed
     }
     LCD_CLEAR();
	 
     CreateFrame4();
     for (u8 column = 8; column < 16; column++) {
	     // Clear the character at the previous position (if applicable)
	     if (column >= 8) {
		     moveCharacterOnLCD(0, column - 1, '_');
	     }

	     // Display the character at the new position
	     moveCharacterOnLCD(0, column, characterToMove);

	     // Add a delay to control the speed of character movement
	     _delay_ms(100); // Adjust the delay as needed
     }
     LCD_CLEAR();
	 //CreateFrame5();
  for (u8 column = 0; column < 13; column++) {
	  /*Clear the character at the previous position (if applicable)*/
	  
	  if (column > 0) {
		  moveCharacterOnLCD(0, column - 1, '_');
	  }

	  // Display the character at the new position
	  moveCharacterOnLCD(0, column, characterToMove);

	  // Add a delay to control the speed of character movement
	  _delay_ms(500); // Adjust the delay as needed
  }
  LCD_CLEAR();
  LCD_voidGotToXY(0,0); 
  LCD_vidWriteString("H  A  H  A  !");
  _delay_ms(3000);
  LCD_CLEAR();
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
		LCD_voidGotToXY(row_iterator,0);
		for(u8 column_iterator = 0; column_iterator < 20; column_iterator++)
		{
			LCD_vidWriteCharctr(*(*(frame1 + row_iterator) + column_iterator));
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
		LCD_voidGotToXY(row_iterator,0);
		for(u8 column_iterator = 0; column_iterator < 20; column_iterator++)
		{
			LCD_vidWriteCharctr(*(*(frame1 + row_iterator) + column_iterator));
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
		LCD_voidGotToXY(row_iterator,1);
		for(u8 column_iterator = 0; column_iterator < 20; column_iterator++)
		{
			LCD_vidWriteCharctr(*(*(frame1 + row_iterator) + column_iterator));
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
		LCD_voidGotToXY(row_iterator,0);
		for(u8 column_iterator = 0; column_iterator < 20; column_iterator++)
		{
			LCD_vidWriteCharctr(*(*(frame1 + row_iterator) + column_iterator));
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
		LCD_voidGotToXY(row_iterator,0);
		for(u8 column_iterator = 0; column_iterator < 20; column_iterator++)
		{
			LCD_vidWriteCharctr(*(*(frame1 + row_iterator) + column_iterator));
		}
	}
}