#include "../LIB/Include/STD_TYPES.h"
#include "../LIB/Include/BIT_MATH.h"
#include "../MCAL/PORT/Include/PORT_interface.h"
#include "../MCAL/DIO/Include/DIO_interface.h"
#include "../HAL/LCD/Include/LCD_interface.h"
#define F_CPU   8000000UL
#include <util/delay.h>

int main(void)
{
	u8 local_u8CustArr[8] = {0x0E,0x0E,0x04,0x0E,0x15,0x04,0x0A,0x11};
	PORT_voidInit();
	LCD_voidInit();
	LCD_voidGoToXY(LCD_u8_ROW1,LCD_u8_COL0);
	LCD_u8DisplayString("________________");
	LCD_voidGoToXY(LCD_u8_ROW2,LCD_u8_COL0);
	LCD_u8DisplayString("________________");
		for(u8 iterator = 0;iterator < 32;iterator++)
		{
			if(iterator < 16)
			{
				LCD_voidCreateCustomCharacter(local_u8CustArr,0,LCD_u8_ROW1,iterator);
				_delay_ms(150);
				LCD_voidGoToXY(LCD_u8_ROW1,iterator);
				LCD_voidDisplayCharacter('_');
			}
			else
			{
				LCD_voidCreateCustomCharacter(local_u8CustArr,0,LCD_u8_ROW2,iterator-16);
				_delay_ms(150);
				LCD_voidGoToXY(LCD_u8_ROW2,iterator-16);
				LCD_voidDisplayCharacter('_');
			}
		}
		LCD_voidGoToXY(LCD_u8_ROW1,LCD_u8_COL0);
		LCD_u8DisplayString("_______ ________");
		LCD_voidGoToXY(LCD_u8_ROW2,LCD_u8_COL0);
		LCD_u8DisplayString("________________");
		for(u8 count = 0;count < 16;count++)
		{
			if(count < 8)
			{
				LCD_voidCreateCustomCharacter(local_u8CustArr,0,LCD_u8_ROW1,count);
				_delay_ms(150);
				LCD_voidGoToXY(LCD_u8_ROW1,count);
				LCD_voidDisplayCharacter('_');
			}
			else
			{
				LCD_voidCreateCustomCharacter(local_u8CustArr,0,LCD_u8_ROW2,count-1);
				_delay_ms(150);
				LCD_voidGoToXY(LCD_u8_ROW2,count-1);
				LCD_voidDisplayCharacter('_');
			}
		}
		LCD_voidGoToXY(LCD_u8_ROW1,LCD_u8_COL0);
		LCD_u8DisplayString("_______ ________");
		LCD_voidGoToXY(LCD_u8_ROW2,LCD_u8_COL0);
		LCD_u8DisplayString("_______/________");
		for(u8 count = 0;count < 16;count++)
		{
			if(count < 8)
			{
				LCD_voidCreateCustomCharacter(local_u8CustArr,0,LCD_u8_ROW2,count);
				_delay_ms(150);
				LCD_voidGoToXY(LCD_u8_ROW2,count);
				LCD_voidDisplayCharacter('_');
			}
			else
			{
				LCD_voidCreateCustomCharacter(local_u8CustArr,0,LCD_u8_ROW1,count-1);
				_delay_ms(150);
				LCD_voidGoToXY(LCD_u8_ROW1,count-1);
				LCD_voidDisplayCharacter('_');
			}
		}
		LCD_voidGoToXY(LCD_u8_ROW1,LCD_u8_COL0);
		LCD_u8DisplayString("____________|___");
		LCD_voidGoToXY(LCD_u8_ROW2,LCD_u8_COL0);
		LCD_u8DisplayString("________________");
		for(u8 count = 0;count < 13;count++)
		{
			LCD_voidCreateCustomCharacter(local_u8CustArr,0,LCD_u8_ROW1,count);
			_delay_ms(150);
			LCD_voidGoToXY(LCD_u8_ROW1,count);
			LCD_voidDisplayCharacter('_');
		}
		LCD_voidDisplayClear();
		LCD_voidGoToXY(LCD_u8_ROW1,LCD_u8_COL3);
		LCD_u8DisplayString("H A H A !");
		while(1);
	return 0;
}


