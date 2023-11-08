/*
 * I2C_Driver.c
 *
 * Created: 10/30/2023 12:01:05 PM
 * Author : sharb
 */ 

#include "std_types.h"
#include "MCAL/PORT/includes/PORT.h"
#include "HAL/EEPROM/includes/eeprom.h"
#include "HAL/LCD/includes/Lcd.h"
#define  F_CPU 8000000UL
#include "util/delay.h"


u8 charTest[] = "HELLO From MCU";
u8 Test[50] = "";
int main(void)
{
	u8 state = 0;
    PORT_voidInit();
	LCD_vidInit();
	eeprom_init();
    while (1) 
    {
		if(state == 0)
		{
			eeprom_write_string(0x0000,charTest);
			state = 1;
		}
		else if (state == 1)
		{
			eeprom_read_string(0x0000,Test);
			_delay_ms(100);
			state = 2;
		}
		else if (state == 2)
		{
			LCD_vidDisplayString(Test);
			state =3;
		}
		
		
		
		_delay_ms(10);
    }
}

