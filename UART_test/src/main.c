/*
 * main.c
 *
 *  Created on: Oct 28, 2023
 *      Author: bishoy18126
 */
#include "../inc/LIB/Std_types.h"
#include "../inc/LIB/Bit_utils.h"

#include "../inc/MCAL/PORT/PORT.h"
#include "../inc/MCAL/DIO/DIO_int.h"
#include "../inc/MCAL/UART/UART.h"
#include "../inc/HAL/LCD/LCD.h"
#include <util/delay.h>



int main(void)
{
	u8 data;
	LCD_voidInit();
	PORT_voidInit();
	UART_init();
	PORT_enumSET_PINDirection(PORT_u8PORTDPIN1,PORT_u8PINDIR_INPUT);
	PORT_enumSET_PINMODE(PORT_u8PORTDPIN1,PORT_u8PINMODE_INPUT_FLOATING);
	//_delay_ms(5000);
	LCD_voidInit();
	_delay_ms(1000);
	//f64 num =((f64)(80000/(16*96))-1);
	u64 num =BUAD_RATE(9600,8000000,0);
	while(1)
	{
		UART_ReceveCharacter(&data);
		//LCD_voidSetCursorToX_y(LCD_ROW0,LCD_Coloumn0);
		LCD_voidWriteChar(data);
		//LCD_voidWriteNumbers(num);
	}
	return 0;
}

