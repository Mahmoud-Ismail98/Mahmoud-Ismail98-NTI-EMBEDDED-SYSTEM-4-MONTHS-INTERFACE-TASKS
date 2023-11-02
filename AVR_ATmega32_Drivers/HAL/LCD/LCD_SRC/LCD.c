/*
 * LCD.c
 *
 * Created: 10/21/2023 12:30:01 PM
 *  Author: Mohamed Alaa
 */ 

#ifndef F_CPU
#define F_CPU 8000000
#endif 

#include <HAL/LCD/LCD_Includes/LCD.h>
#include <HAL/LCD/LCD_Includes/LCD_Private.h>
#include <HAL/LCD/LCD_Includes/LCD_CFG.h>
#include <util/delay.h>
#include <MCAL/PORT/PORT_Includes/Port.h>
#include <MCAL/DIO/DIO_Includes/DIO.h>
#include <Services/Bit_utils.h>

void LCD_Init(void)
{
	Port_Set_Pin_Mode(LCD_RS_PORT, LCD_RS_PIN, PIN_Output_Low);
	Port_Set_Pin_Mode(LCD_EN_PORT, LCD_EN_PIN, PIN_Output_Low);
	Port_Set_Pin_Mode(LCD_D4_PORT, LCD_D4_PIN, PIN_Output_Low);
	Port_Set_Pin_Mode(LCD_D5_PORT, LCD_D5_PIN, PIN_Output_Low);
	Port_Set_Pin_Mode(LCD_D6_PORT, LCD_D6_PIN, PIN_Output_Low);
	Port_Set_Pin_Mode(LCD_D7_PORT, LCD_D7_PIN, PIN_Output_Low);
	_delay_ms(50); //delay according to data sheet


#ifdef	LCD_8Bit_Mode

	LCD_Send_Command(LCD_Return_Home);
	LCD_Send_Command(LCD_8Bit);
	LCD_Send_Command(LCD_Display_Clear);
	_delay_ms(4);
	LCD_Send_Command(LCD_Shift_Cursor_Disp_fix);
	_delay_ms(1);
	LCD_Send_Command(LCD_Display_On);
	_delay_ms(1);
	
#endif

#ifdef	LCD_4Bit_Mode
LCD_Send_Command(LCD_Return_Home);
LCD_Send_Command(LCD_4Bit);
LCD_Send_Command(LCD_Display_Clear);
	_delay_ms(4);
LCD_Send_Command(LCD_Shift_Cursor_Disp_fix);
	_delay_ms(1);
LCD_Send_Command(LCD_Display_On);
	_delay_ms(1);
#endif

}

void LCD_Display_Character(uint8 Data)
{
	DIO_Write_Channel(LCD_RS_PORT, LCD_RS_PIN, PIN_High);
	//DIO_Write_Channel(LCD_RW_PORT, LCD_RW_PIN, PIN_Low);			//always ground in Eta32
	LCD_Helper_Send_Data_Bus(Data);
}

void LCD_Display_String(const Puint8 Data)
{
	uint32 Index = 0;
	while(Data[Index] != '\0')
	{
		LCD_Display_Character(Data[Index]);
		Index++;
	}
}

void LCD_Display_Number(uint64 Data)
{
	uint8 Str_Data[20] = {0}; //all elements are 0, assuming number is 19 digit although the uint32 max no has a number of digits less than 20
	uint8 Index = 18; // the element before the last element in the array Str_Data
	if(Data == 0)
		LCD_Display_Character('0');
	
	while(Data)
	{
		Str_Data[Index] = (Data % 10) + '0';
		Data /= 10;
		Index--;
	}
	if(Index != 18)
		LCD_Display_String(&Str_Data[Index+1]);
}

void LCD_Send_Command(uint8 Data)
{
	DIO_Write_Channel(LCD_RS_PORT, LCD_RS_PIN, PIN_Low);
	//DIO_Write_Channel(LCD_RW_PORT, LCD_RW_PIN, PIN_Low);			//always ground in Eta32
	
	LCD_Helper_Send_Data_Bus(Data);
}

void LCD_GoTO_XY(uint8 Line, uint8 Column)
{
	LCD_Send_Command(LCD_DDRAM + Line + Column);
}

void LCD_Create_Custom_Character(Puint8 Custome_Character, uint8 Postion_Index)
{
	LCD_Send_Command(LCD_CGRAM + Postion_Index*8);
	DIO_Write_Channel(LCD_RS_PORT, LCD_RS_PIN, PIN_High);
	for(uint8 byte_Loc = 0; byte_Loc < 8; ++byte_Loc)
	{
		//DIO_Write_Channel(LCD_RW_PORT, LCD_RW_PIN, PIN_Low);			//always ground in Eta32
		LCD_Helper_Send_Data_Bus(Custome_Character[byte_Loc]);
	}
	LCD_Send_Command(LCD_DDRAM);
}


void LCD_Clear(void)
{
	LCD_Send_Command(LCD_Display_Clear);
}

static void LCD_Helper_Send_Data_Bus(uint8 Data)
{
	
	uint8 Bit_Value = 0;
	
#ifdef	LCD_8Bit_Mode

	Bit_Value = GET_BIT(Data, 0);
	DIO_Write_Channel(LCD_D0_PORT, LCD_D0_PIN, Bit_Value);
	Bit_Value = GET_BIT(Data, 1);
	DIO_Write_Channel(LCD_D1_PORT, LCD_D1_PIN, Bit_Value);		
	Bit_Value = GET_BIT(Data, 2);
	DIO_Write_Channel(LCD_D2_PORT, LCD_D2_PIN, Bit_Value);		
	Bit_Value = GET_BIT(Data, 3);
	DIO_Write_Channel(LCD_D3_PORT, LCD_D3_PIN, Bit_Value);
	Bit_Value = GET_BIT(Data, 4);
	DIO_Write_Channel(LCD_D4_PORT, LCD_D4_PIN, Bit_Value);
	Bit_Value = GET_BIT(Data, 5);
	DIO_Write_Channel(LCD_D5_PORT, LCD_D5_PIN, Bit_Value);	
	Bit_Value = GET_BIT(Data, 6);
	DIO_Write_Channel(LCD_D6_PORT, LCD_D6_PIN, Bit_Value);	
	Bit_Value = GET_BIT(Data, );
	DIO_Write_Channel(LCD_D7_PORT, LCD_D7_PIN, Bit_Value);
	LCD_Kick();
	
#endif


#ifdef	LCD_4Bit_Mode
	
	//send higher nibble
	Bit_Value = GET_BIT(Data, 4);
	DIO_Write_Channel(LCD_D4_PORT, LCD_D4_PIN, Bit_Value);
	Bit_Value = GET_BIT(Data, 5);
	DIO_Write_Channel(LCD_D5_PORT, LCD_D5_PIN, Bit_Value);
	Bit_Value = GET_BIT(Data, 6);
	DIO_Write_Channel(LCD_D6_PORT, LCD_D6_PIN, Bit_Value);
	Bit_Value = GET_BIT(Data, 7);
	DIO_Write_Channel(LCD_D7_PORT, LCD_D7_PIN, Bit_Value);
	LCD_Kick();

	//send Lower nibble
	Bit_Value = GET_BIT(Data, 0);
	DIO_Write_Channel(LCD_D4_PORT, LCD_D4_PIN, Bit_Value);
	Bit_Value = GET_BIT(Data, 1);
	DIO_Write_Channel(LCD_D5_PORT, LCD_D5_PIN, Bit_Value);
	Bit_Value = GET_BIT(Data, 2);
	DIO_Write_Channel(LCD_D6_PORT, LCD_D6_PIN, Bit_Value);
	Bit_Value = GET_BIT(Data, 3);
	DIO_Write_Channel(LCD_D7_PORT, LCD_D7_PIN, Bit_Value);
	LCD_Kick();

#endif	
	
	
}

static void LCD_Kick(void)
{
	DIO_Write_Channel(LCD_EN_PORT, LCD_EN_PIN, PIN_High);
	_delay_ms(1);
	
	DIO_Write_Channel(LCD_EN_PORT, LCD_EN_PIN, PIN_Low);
		_delay_us(200);
}
