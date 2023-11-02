#include "../LIB/Include/STD_TYPES.h"
#include "../LIB/Include/BIT_MATH.h"
#include "../MCAL/PORT/Include/PORT_interface.h"
#include "../MCAL/DIO/Include/DIO_interface.h"
#include "../HAL/LCD/Include/LCD_interface.h"
#include "../HAL/KPD/Include/KPD_interface.h"
#define F_CPU   8000000UL
#include <util/delay.h>

int main(void)
{
	PORT_voidInit();
	LCD_voidInit();
	u32 local_u32Num1=0,local_u32Num2=0;
	s32 loca_u32Result,loca_u32Remainder;
	u8 local_u8Operation;
	u8 local_u8KpdRead;
	LCD_voidGoToXY(LCD_u8_ROW1,LCD_u8_COL4);
	LCD_u8DisplayString("Simple");
	LCD_voidGoToXY(LCD_u8_ROW2,LCD_u8_COL2);
	LCD_u8DisplayString("Calculator");
	_delay_ms(2000);
	LCD_voidDisplayClear();
	while(1)
	{
		KPD_KPDEnumGetKeyState(&local_u8KpdRead);
		if(local_u8KpdRead != KPD_u8_KEY_NOT_PRESSED)
		{
			if((local_u8KpdRead != '+')&&(local_u8KpdRead != '-')&&(local_u8KpdRead != '/')&&(local_u8KpdRead != '*')
					&&(local_u8KpdRead != 'c')&&(local_u8KpdRead != '='))
			{
				local_u32Num1 = (local_u32Num1*10) + local_u8KpdRead;
				LCD_voidGoToXY(LCD_u8_ROW1,LCD_u8_COL0);
				LCD_voidDisplayNumber(local_u32Num1);
			}
			else if((local_u8KpdRead == '+')||(local_u8KpdRead == '-')||(local_u8KpdRead == '/')||(local_u8KpdRead == '*'))
			{
				local_u8Operation = local_u8KpdRead;
				LCD_voidDisplayCharacter(local_u8Operation);
				do
				{
					KPD_KPDEnumGetKeyState(&local_u8KpdRead);
					if(local_u8KpdRead != KPD_u8_KEY_NOT_PRESSED)
					{
						if((local_u8KpdRead != '+')&&(local_u8KpdRead != '-')&&(local_u8KpdRead != '/')&&(local_u8KpdRead != '*')
								&&(local_u8KpdRead != 'c')&&(local_u8KpdRead != '='))
						{
							local_u32Num2 = (local_u32Num2*10) + local_u8KpdRead;
							LCD_voidDisplayNumber(local_u32Num2);
							LCD_voidDisplayClear();
							LCD_voidDisplayNumber(local_u32Num1);
							LCD_voidDisplayCharacter(local_u8Operation);
							LCD_voidDisplayNumber(local_u32Num2);
						}
						else if(local_u8KpdRead == '=')
						{
							LCD_voidDisplayCharacter('=');
							switch(local_u8Operation)
							{
								case '+':
									loca_u32Result = local_u32Num1 + local_u32Num2;
									LCD_voidDisplayNumber(loca_u32Result);
									break;
								case '-':
									loca_u32Result = local_u32Num1 - local_u32Num2;
									LCD_voidDisplayNumber(loca_u32Result);
									break;
								case '*':
									loca_u32Result = local_u32Num1 * local_u32Num2;
									LCD_voidDisplayNumber(loca_u32Result);
									break;
								case '/':
									loca_u32Result = local_u32Num1 / local_u32Num2;
									LCD_voidDisplayNumber(loca_u32Result);
									loca_u32Remainder = local_u32Num1 % local_u32Num2;
									LCD_voidDisplayCharacter('.');
									LCD_voidDisplayNumber(loca_u32Remainder);
									break;
							}
						}
					}
				}while(local_u8KpdRead != 'c');
				LCD_voidDisplayClear();
				local_u32Num1 = 0;
				local_u32Num2 = 0;
				loca_u32Result = 0;
			}
			else if(local_u8KpdRead == 'c')
			{
				LCD_voidDisplayClear();
				local_u32Num1 = 0;
				local_u32Num2 = 0;
				loca_u32Result = 0;
			}
		}
	}
	return 0;
}
