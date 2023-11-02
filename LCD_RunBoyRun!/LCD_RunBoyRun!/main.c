/*
 * TEST.c
 *
 * Created: 10/21/2023 5:57:22 PM
 * Author : Wael
 */

#define F_CPU 16000000
#include "util/delay.h"

#include "Bit_utils.h"
#include "Std_types.h"
#include "MCAL/Port/inc/Port.h"
#include "MCAL/Dio/inc/Dio.h"
#include "HAL/LCD/inc/LCD.h"

#define MAN 0
#define MAN_ON_SHELF 1
#define SAD_MAN 2

u8 man[] = {
	0b01110,
	0b00100,
	0b01110,
	0b10101,
	0b00100,
	0b01010,
	0b10001,
	0b00000
};

u8 man_onshelf[] = {
	0b01110,
	0b00100,
	0b01110,
	0b10101,
	0b00100,
	0b01010,
	0b11111,
	0b00000
};

u8 Sad_man[] = {
	0b11111,
	0b10101,
	0b10101,
	0b11111,
	0b11011,
	0b11111,
	0b10001,
	0b11111

};
typedef enum
{
	Level_1,
	Level_2,
	Level_3
}Game_Level_t;
int main(void)
{
	Port_vidInit();
	LCD_voidInit();
	Game_Level_t Local_enuLevel = Level_1;
	LCD_voidDisplayString("____________________");
	LCD_voidGoToXY(0,1);
	LCD_voidDisplayString("____________________");
	LCD_voidGoToXY(0,3);
	LCD_voidDisplayString("^^^^^^^^^^^^^^^^^^^^");
	LCD_voidCreateCustomChar(man,0);
	LCD_voidCreateCustomChar(man_onshelf,1);
	LCD_voidCreateCustomChar(Sad_man,2);
	u8 Local_u8Level2Flag =0;
	u8 Local_X_Pos=0;
	u8 Local_Y_Pos=0;
	LCD_voidGoToXY(Local_X_Pos,Local_Y_Pos);
	LCD_voidDisplayChar(MAN_ON_SHELF);


    while (1)
    {
		switch(Local_enuLevel)
		{
			case Level_1:
			_delay_ms(200);
			Local_X_Pos++;
			if(Local_X_Pos == 20)
			{
				LCD_voidGoToXY(0,19);
				LCD_voidDisplayChar('_');
				Local_X_Pos =0;
				Local_Y_Pos++;
				if(Local_Y_Pos == 2)
				{
					Local_Y_Pos =0;
					Local_enuLevel = Level_2;
					break;
				}
			}
			LCD_voidGoToXY(Local_X_Pos,Local_Y_Pos);
			LCD_voidDisplayChar(MAN_ON_SHELF);
			LCD_voidGoToXY(Local_X_Pos-1,Local_Y_Pos);
			LCD_voidDisplayChar('_');
			break;

			case Level_2:
			/*Bulding ROWS with Empty Index*/
			if(Local_u8Level2Flag == 0)
			{
				LCD_voidGoToXY(7,Local_Y_Pos);
				LCD_voidDisplayChar(' ');
				LCD_voidGoToXY(13,1);
				LCD_voidDisplayChar(' ');
				Local_u8Level2Flag = 1;
			}
			/*Displaying the boy*/
			_delay_ms(200);
			Local_X_Pos++;
			if(Local_X_Pos == 7)
			{
				LCD_voidGoToXY(Local_X_Pos-1,Local_Y_Pos);
				LCD_voidDisplayChar('_');
				Local_Y_Pos =1;
			}
			if(Local_X_Pos == 13)
			{
				LCD_voidGoToXY(Local_X_Pos-1,Local_Y_Pos);
				LCD_voidDisplayChar('_');
				LCD_voidGoToXY(13,2);
				LCD_voidDisplayChar(MAN);
				_delay_ms(200);
				LCD_voidGoToXY(13,2);
				LCD_voidDisplayChar(' ');
				LCD_voidGoToXY(13,3);
				LCD_voidDisplayChar(SAD_MAN);
				LCD_voidGoToXY(0,2);
				LCD_voidDisplayString("THE END");
				return;
			}
			/*if(Local_X_Pos == 20)
			{
				LCD_voidGoToXY(0,19);
				LCD_voidDisplayChar('_');
				Local_X_Pos =0;
				Local_Y_Pos++;
				if(Local_Y_Pos == 2)
				{
					Local_Y_Pos =0;
					Local_u8Level2Flag = 0;
					LCD_voidGoToXY(13,0);
					LCD_voidDisplayChar('_');
					Local_enuLevel = Level_1;
				}

			}*/
			LCD_voidGoToXY(Local_X_Pos,Local_Y_Pos);
			LCD_voidDisplayChar(MAN_ON_SHELF);
			LCD_voidGoToXY(Local_X_Pos-1,Local_Y_Pos);
			LCD_voidDisplayChar('_');
			break;

		}

    }
}

