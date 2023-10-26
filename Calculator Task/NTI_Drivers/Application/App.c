/*
 * App.c
 *
 *  Created on: Oct 26, 2023
 *      Author: Ismail
 */

#include"../HAL/KeyPad/KeyPad.h"
#include "Calculator.h"

int main(){

	    LCDInit4BitMode();

	u8 key ;           	// Key char for keeping record of pressed key
    u16 num1, num2;       				// First number, second number
    u8 Op;    				// Function to be performed among two numbers
u8 msg []= "Calculator";
	LCD_SetCursorPosition(5,1);

	LCD_WriteString(msg);
	_delay_ms(3000);
	LCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);


    while(1)
    {
    key =keypressed();			 //get numb1
		LCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);         	// Clear LCD screen
		LCD_WriteChar4Bit(key);       		// SendEND the key pressed to LCD
        num1 = GetNumber(key);

        if(num1 != Error)            // If correct input then proceed, num1==Error means wrong input
        {
        	key =keypressed();		//get function
        	 LCD_WriteChar4Bit(key);             //Echo the key pressed to LCD
        	 Op = GetOperation(key);            //it checks for wrong Op
            if(Op!='e')                    //if correct input then proceed, Op=='e' means wrong input
            {
            	key =keypressed();		 	//get numb2
            	 LCD_WriteChar4Bit(key);   				//Echo the key pressed to LCD
                num2 = GetNumber(key);
                if(num2!=Error)  				//if correct input then proceed, num2==Error means wrong input
                {
                	key =keypressed();	//get equal sign
                	 LCD_WriteChar4Bit(key); //Echo the key pressed to LCD
                    if(key == '=')    //if = is pressed then proceed
                    {
                        switch(Op)    //switch on function
                        {
                        case '+':
                        	DispNumber(num1+num2);
                            break;
                        case '-':
                        	DispNumber(num1-num2);
                            break;
                        case '*':
                        	DispNumber(num1*num2);
                            break;
                        case '/':
                        	DispNumber(num1/num2);
                            break;
                        }
                    }
                    else   //key other then = here means error wrong input
                    {
                        if(key == 'C')     //if clear screen is pressed then clear screen and reset
                        	LCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
                        else
                        	DispError(0);     //Display wrong input error
                    }
                }
            }
        }

     }
return 0;
}
