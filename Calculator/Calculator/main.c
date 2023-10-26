/*
 * Calculator.c
 *
 * Created: 10/26/2023 3:57:22 PM
 * Author : Ahmed Wael

 -> Description:
 Calculator using keypad and LCD

 -> Peripherals & Drivers Used:
 DIO,
 LCD,
 KeyPad

 THIS IS ONLY VERSION 1, THERE ARE MANY DEVELOPMENTS.

 */
#define F_CPU 16000000
#include "util/delay.h"
#include "Bit_utils.h"
#include "Std_types.h"
#include "Dio.h"
#include "Port.h"
#include "Keypad.h"
#include "LCD.h"


#define INPUT_BUFFER_SIZE 10
u8 Global_u8InputBuffer[INPUT_BUFFER_SIZE] = {0};

void Calc_voidFlushInputBuffer()
{
	for(u8 i = 0; i <INPUT_BUFFER_SIZE;i++)
	{
		Global_u8InputBuffer[i] = 0;
	}
}
void Calc_voidGetInput()
{
	u8 Local_u8Button = 0;
	u8 Local_u8StrPointer=0;
	do{
		KeyPad_voidGetButton(&Local_u8Button);
		if(Local_u8Button != 0  && Local_u8Button != '=')
		{
			Global_u8InputBuffer[Local_u8StrPointer] = Local_u8Button;
			LCD_voidDisplayChar(Global_u8InputBuffer[Local_u8StrPointer]);
			Local_u8StrPointer++;
			Local_u8Button=0;
		}
	}while(Local_u8Button != '=');
	Global_u8InputBuffer[Local_u8StrPointer+1] = 0;
}

s32 Calc_s32Calculate_Result()
{
	u8 Local_u8StrPointer=0;

	u32 Local_u32FirstOperand=0;
	while(Global_u8InputBuffer[Local_u8StrPointer] >= '0' && Global_u8InputBuffer[Local_u8StrPointer]<='9')
	{
		Local_u32FirstOperand = (Local_u32FirstOperand*10) + Global_u8InputBuffer[Local_u8StrPointer]-'0';
		Local_u8StrPointer++;
	}

	u8 Local_u8Operation = Global_u8InputBuffer[Local_u8StrPointer];
	Local_u8StrPointer++;

	u32 Local_u32SecondOperand=0;
	while(Global_u8InputBuffer[Local_u8StrPointer])
	{
		Local_u32SecondOperand = (Local_u32SecondOperand*10) + Global_u8InputBuffer[Local_u8StrPointer]-'0';
		Local_u8StrPointer++;
	}

	s32 Local_s32Result=0;
	if(Local_u8Operation == '+')
	{
		Local_s32Result = Local_u32FirstOperand + Local_u32SecondOperand;
	}
	else if(Local_u8Operation == '-')
	{
		Local_s32Result = Local_u32FirstOperand - Local_u32SecondOperand;
	}
	else if(Local_u8Operation == '*')
	{
		Local_s32Result = Local_u32FirstOperand * Local_u32SecondOperand;
	}
	else if(Local_u8Operation == '/')
	{
		Local_s32Result = Local_u32FirstOperand / Local_u32SecondOperand;
	}
	return Local_s32Result;
}


int main(void)
{
	Port_vidInit();
	LCD_voidInit();

	s32 Result;
	u8 Local_u8Temp;

	while (1)
	{
		Calc_voidGetInput();
		Result = Calc_s32Calculate_Result();
		LCD_voidGoToXY(0,1);
		LCD_voidDisplayNumbers(Result);
		Calc_voidFlushInputBuffer();
		do{
			KeyPad_voidGetButton(&Local_u8Temp);
		}while(Local_u8Temp != '.');
		LCD_voidClear();
		Local_u8Temp=0;
	}
}

