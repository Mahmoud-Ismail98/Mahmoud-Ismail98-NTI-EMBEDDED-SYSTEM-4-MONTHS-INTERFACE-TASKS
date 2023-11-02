/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Dwidar
 */
#include"lcd.h"
#include"keypad.h"
#include<stdio.h>
#include<util/delay.h>

u8 op = 0;

u32 creatFirstOperand(u8 opand1[],u8 size)
{

	u8 i = 0;
	u8 flag = 0,op_index = 0,holder = 0;
	u32 n1;

	LCD_displayStringRowColumn(0,1,"PLZ enter n1");
	LCD_moveCurser(1,1);

	while (i < 5)
	{

		if(flag == 0)
		{
			_delay_ms(200);
			opand1[i] = KEYPAD_getPressedKey();
			if(opand1[i] == 43)
			{
				LCD_moveCurser(1,4);
				LCD_displayCharacter('+');
				op_index = i;
				op = opand1[i];
				break;
			}
			else if(opand1[i] == 45)
			{
				LCD_moveCurser(1,4);
				LCD_displayCharacter('-');
				op_index = i;
				op = opand1[i];
				break;
			}
			else if(opand1[i] == 42)
			{
				LCD_moveCurser(1,4);
				LCD_displayCharacter('*');
				op_index = i;
				op = opand1[i];
				break;
			}
			else if(opand1[i] == 37)
			{
				LCD_moveCurser(1,4);
				LCD_displayCharacter('/');
				op_index = i;
				op = opand1[i];
				break;
			}
			else
			{
				LCD_intgerToString(opand1[i]);
			}


		}
		flag++;

		if(flag == 1)
		{
			i++;
			flag = 0;
		}

	}
	i = 0;

	while(i < op_index)
	{
		n1 *= 10;
		n1 += opand1[i];

		i++;
	}
	return n1;

}

u32 creatSecondtOperand(u8 opand2[],u8 size)
{

	u8 i = 0;
	u8 flag = 0,op_index = 0;
	u32 n2;

	LCD_displayStringRowColumn(0,1,"PLZ enter n2");
	LCD_moveCurser(1,6);

	while (i < 5)
	{
		if(flag == 0)
		{
			_delay_ms(200);
			opand2[i] = KEYPAD_getPressedKey();
			if(opand2[i] ==61)
			{
				LCD_displayCharacter('=');
				op_index = i;
				break;
			}
			else
			{
				LCD_intgerToString(opand2[i]);
			}

		}
		flag++;

		if(flag == 1)
		{
			i++;
			flag = 0;
		}

	}
	i = 0;
	while(i < op_index)
	{
		n2 *= 10;
		n2 += opand2[i];

		i++;
	}

	return n2;

}

u32 operation(u32 n1, u32 n2)
{
	u32 result;
	if(op == 0)
	{
		LCD_clearScreen();
		LCD_displayStringRowColumn(0,1,"Error");
		return 0;
	}
	else
	{
		switch(op)
	{
		case 43:
			result = n1 + n2;
			break;
		case 45:
			result = n1 - n2;
			break;
		case 42:
			result = n1 * n2;
			break;
		case 37:
			result = n1 / n2;
			break;
	}
	}



	return result;
}


int main()
{
	u8 num1[5];
	u8 num2[5];

	u32 n1 = 0,n2 = 0;

	u32 result;

	port_init();
	LCD_init();

	while(1)
	{
		n1 = creatFirstOperand(num1,5);

		n2 = creatSecondtOperand(num2,5);

		result = operation(n1,n2);

		if(result >= 1000)
		{
			LCD_intgerToString(result);
		}
		else
		{
			LCD_intgerToString(result);
			LCD_displayCharacter(' ');
		}

		while(KEYPAD_getPressedKey() != 13){}


	}

}


