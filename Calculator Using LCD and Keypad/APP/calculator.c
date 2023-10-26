/*
=======================================================================================================================
Author       : Mamoun
Module       : Simple Calculator
File Name    : calculator.c
Date Created : Oct 26, 2023
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../OTHERS/std_types.h"
#include "../OTHERS/common_macros.h"
#include "../MCAL/PORT/INCLUDES/port.h"
#include "../MCAL/DIO/INCLUDES/dio.h"
#include "../HAL/KEYPAD/INCLUDES/keypad.h"
#include "../HAL/LCD/INCLUDES/lcd.h"
#include "calculator.h"

/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/

uint32 g_operands[5] = {0};
uint8 g_operations[4] = {0};
uint8 g_operandsCounter = 0;
uint8 g_operationsCounter = 0;

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/
int main(void)
{
	InitSystem();
	while(1)
	{
		uint8 LOC_userInput = '\0';
		KEYPAD_getPressedKey(&LOC_userInput);
		CheckUserInput(LOC_userInput);
	}
}

void InitSystem(void)
{
	PORT_init();
	LCD_init();
}

void CheckUserInput(uint8 a_userInput)
{
	static uint32 LOC_numberHolder = 0;

	switch (a_userInput)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		LCD_displayCharacter(a_userInput);
		LOC_numberHolder = ((LOC_numberHolder * 10) + (a_userInput - '0'));
		break;

	case '*':
	case '/':
	case '+':
	case '-':
		if((g_operandsCounter == 0) && (LOC_numberHolder == 0))
		{
			LCD_clearScreen();
			LCD_displayString("Wrong Operation");
		}

		else
		{
			LCD_displayString(" ");
			LCD_displayCharacter(a_userInput);
			LCD_displayString(" ");

			*(g_operations + g_operationsCounter) = a_userInput;
			g_operationsCounter++;

			*(g_operands + g_operandsCounter) = LOC_numberHolder;
			LOC_numberHolder = 0;
			g_operandsCounter++;
		}

		break;

	case '=':
		if(g_operandsCounter == 0)
		{
			LCD_clearScreen();
			LCD_displayString("Wrong Operation");
		}

		else
		{
			LCD_displayString(" ");
			LCD_displayCharacter(a_userInput);
			LCD_displayString(" ");

			*(g_operands + g_operandsCounter) = LOC_numberHolder;
			LOC_numberHolder = 0;
			g_operandsCounter++;

			Calculator();
		}

		break;

	case 'C':
		LCD_clearScreen();
		LOC_numberHolder = 0;
		g_operandsCounter = 0;
		g_operationsCounter = 0;
		break;

	default:
		/* Do Nothing. */
		break;
	}
}

void Calculator(void)
{
	uint32 LOC_result = *(g_operands + 0);

	for(uint8 iterator = 0; iterator < g_operationsCounter; iterator++)
	{
		switch (*(g_operations + iterator))
		{
		case '*':
			LOC_result *= *(g_operands + iterator + 1);
			break;

		case '/':
			LOC_result /= *(g_operands + iterator + 1);
			break;

		case '+':
			LOC_result += *(g_operands + iterator + 1);
			break;

		case '-':
			LOC_result -= *(g_operands + iterator + 1);
			break;

		default:
			/* Do Nothing. */
			break;

		}
	}

	LCD_displayInteger(LOC_result);
}
