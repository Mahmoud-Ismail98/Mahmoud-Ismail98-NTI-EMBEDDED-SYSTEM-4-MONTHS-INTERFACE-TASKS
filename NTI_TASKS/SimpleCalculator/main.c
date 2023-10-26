#include "LCD_interface.h"
#include "KEYPAD.h"
#include "Port.h"
#include "Dio.h"
#include <util/delay.h>

int main(void)
{
	/* System Initialization */
	Port_vidInit();
	LCD_vidInit();

	unsigned char arr[6] = {NOT_PRESSED, NOT_PRESSED, NOT_PRESSED, NOT_PRESSED, NOT_PRESSED, NOT_PRESSED};
	unsigned short res;
	unsigned char counter = 0;

	while (1)
	{
		/* Read a key press into the array until a key is pressed */
		do
		{
			arr[counter] = GET_KEY_PRESSED();
		} while (arr[counter] == NOT_PRESSED);

		/* Check if the pressed key is an operator or 'A' or '=' */
		if (arr[counter] == 'A' || arr[counter] == '=' || arr[counter] == '+' || arr[counter] == '-' || arr[counter] == '*' || arr[counter] == '/')
		{
			/* Clear the LCD and reinitialize it */
			LCD_CLEAR();
			LCD_vidInit();
		}
		else
		{
			/* Write the character to the LCD */
			LCD_vidWriteCharctr(arr[counter]);
		}
		counter++;
		_delay_ms(300);

		/* Read the next key press into the array */
		do
		{
			arr[counter] = GET_KEY_PRESSED();
		} while (arr[counter] == NOT_PRESSED);

		/* Check if the pressed key is an operator or 'A' or '=' */
		if (arr[counter] == 'A' || arr[counter] == '=' || arr[counter] == '+' || arr[counter] == '-' || arr[counter] == '*' || arr[counter] == '/')
		{
			/* Clear the LCD and reinitialize it */
			LCD_CLEAR();
			LCD_vidInit();
		}
		else
		{
			/* Write the character to the LCD */
			LCD_vidWriteCharctr(arr[counter]);
		}
		counter++;
		_delay_ms(300);

		/* Read the next key press into the array */
		do
		{
			arr[counter] = GET_KEY_PRESSED();
		} while (arr[counter] == NOT_PRESSED);

		/* Check if the pressed key is 'A' or '=' */
		if (arr[counter] == 'A' || arr[counter] == '=')
		{
			/* Clear the LCD and reinitialize it */
			LCD_CLEAR();
			LCD_vidInit();
		}
		else
		{
			/* Write the character to the LCD */
			LCD_vidWriteCharctr(arr[counter]);
		}
		counter++;
		_delay_ms(300);

		/* Read the next key press into the array */
		do
		{
			arr[counter] = GET_KEY_PRESSED();
		} while (arr[counter] == NOT_PRESSED);

		/* Check if the pressed key is an operator or 'A' or '=' */
		if (arr[counter] == 'A' || arr[counter] == '=' || arr[counter] == '+' || arr[counter] == '-' || arr[counter] == '*' || arr[counter] == '/')
		{
			/* Clear the LCD and reinitialize it */
			LCD_CLEAR();
			LCD_vidInit();
		}
		else
		{
			/* Write the character to the LCD */
			LCD_vidWriteCharctr(arr[counter]);
		}
		counter++;
		_delay_ms(300);

		/* Read the final key press into the array */
		do
		{
			arr[counter] = GET_KEY_PRESSED();
		} while (arr[counter] == NOT_PRESSED);

		/* Check if the final pressed key is '=' */
		if (arr[counter] == '=')
		{
			/* Write '=' to the LCD */
			LCD_vidWriteCharctr(arr[counter]);

			/* Calculate and display the result based on the previous key presses */
			switch (arr[counter - 3])
			{
				case '+':
				/* Perform addition and display the result */
				res = (arr[counter - 4] - 48) + ((arr[counter - 5] - 48) * 10) + ((arr[counter - 2] - 48) * 10) + (arr[counter - 1] - 48);
				if (res >= 100 && res < 1000)
				{
					LCD_vidWriteCharctr((res / 100) + 48);
					LCD_vidWriteCharctr(((res / 10) % 10) + 48);
					LCD_vidWriteCharctr((res % 10) + 48);
				}
				else if (res >= 10 && res < 100)
				{
					LCD_vidWriteCharctr((res / 10) + 48);
					LCD_vidWriteCharctr((res % 10) + 48);
				}
				else if (res < 10)
				{
					LCD_vidWriteCharctr(res + 48);
				}
				break;
				case '-':
				/* Perform subtraction and display the result */
				res = ((arr[counter - 4] - 48) + ((arr[counter - 5] - 48) * 10)) - (((arr[counter - 2] - 48) * 10) + (arr[counter - 1] - 48));
				if (res >= 100 && res < 1000)
				{
					LCD_vidWriteCharctr((res / 100) + 48);
					LCD_vidWriteCharctr(((res / 10) % 10) + 48);
					LCD_vidWriteCharctr((res % 10) + 48);
				}
				else if (res >= 10 && res < 100)
				{
					LCD_vidWriteCharctr((res / 10) + 48);
					LCD_vidWriteCharctr((res % 10) + 48);
				}
				else if (res < 10)
				{
					LCD_vidWriteCharctr(res + 48);
				}
				break;
				case '*':
				/* Perform multiplication and display the result */
				res = ((arr[counter - 4] - 48) + ((arr[counter - 5] - 48) * 10)) * (((arr[counter - 2] - 48) * 10) + (arr[counter - 1] - 48));
				if (res >= 1000 && res < 10000)
				{
					LCD_vidWriteCharctr((res / 1000) + 48);
					LCD_vidWriteCharctr(((res / 100) % 10) + 48);
					LCD_vidWriteCharctr(((res / 10) % 10) + 48);
					LCD_vidWriteCharctr((res % 10) + 48);
				}
				else if (res >= 100 && res < 1000)
				{
					LCD_vidWriteCharctr((res / 100) + 48);
					LCD_vidWriteCharctr(((res / 10) % 10) + 48);
					LCD_vidWriteCharctr((res % 10) + 48);
				}
				else if (res >= 10 && res < 100)
				{
					LCD_vidWriteCharctr((res / 10) + 48);
					LCD_vidWriteCharctr((res % 10) + 48);
				}
				else if (res < 10)
				                   
			    {
				 LCD_vidWriteCharctr(res + 48);
				 }
				 break;
				 case '/':
				 /* Perform division and display the result */
				 res = ((arr[counter - 4] - 48) + ((arr[counter - 5] - 48) * 10)) / (((arr[counter - 2] - 48) * 10) + (arr[counter - 1] - 48));
				 if (res >= 100 && res < 1000)
				 {
				     LCD_vidWriteCharctr((res / 100) + 48);
				     LCD_vidWriteCharctr(((res / 10) % 10) + 48);
				     LCD_vidWriteCharctr((res % 10) + 48);
				 }
				 else if (res >= 10 && res < 100)
				 {
				     LCD_vidWriteCharctr((res / 10) + 48);
				     LCD_vidWriteCharctr((res % 10) + 48);
				 }
				 else if (res < 10)
				 {
				     LCD_vidWriteCharctr(res + 48);
				 }
				 break;
				 default:
				 break;
			         }
		         }
		         else
		         {
			         LCD_CLEAR();
			         LCD_vidInit();
		         }
		         _delay_ms(200);
	             }
     }

