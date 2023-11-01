#include "../LIB/Include/STD_TYPES.h"
#include "../LIB/Include/BIT_MATH.h"
#include "../MCAL/PORT/Include/PORT_interface.h"
#include "../MCAL/DIO/Include/DIO_interface.h"
#include "../MCAL/GIE/Include/GIE_interface.h"
#include "../MCAL/ADC/Include/ADC_interface.h"
#include "../HAL/LCD/Include/LCD_interface.h"
#define F_CPU   8000000UL
#include <util/delay.h>

u8 LCD_u8Vol1[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF};
u8 LCD_u8Vol2[8] = {0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF};
u8 LCD_u8Vol3[8] = {0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
u8 LCD_u8Vol4[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

u8 LCD_u8DelVol[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

int main(void)
{
	u16 local_u16DigitalValue;
	u16 local_u16AnalogalValue;
	u8 local_u8Flag = 0;
	PORT_voidInit();
	GIE_voidInt(GIE_u8_ENABLE);
	ADC_voidInit();
	LCD_voidInit();
	LCD_u8DisplayString("VOLUME = ");
	while(1)
	{
		ADC_ADCEnumReadSync(ADC_CHANNEL_0,&local_u16DigitalValue);
		local_u16AnalogalValue = (u16)((local_u16DigitalValue * 5000UL) / 1024);
		if(local_u8Flag == 0)
		{
			if((local_u16AnalogalValue >= 1000) && (local_u16AnalogalValue < 2000))
			{
				LCD_voidCreateCustomCharacter(LCD_u8Vol1,0,LCD_u8_ROW2,LCD_u8_COL10);
			}
			else if((local_u16AnalogalValue >= 2000) && (local_u16AnalogalValue < 3000))
			{
				LCD_voidCreateCustomCharacter(LCD_u8Vol2,1,LCD_u8_ROW2,LCD_u8_COL11);
			}
			else if((local_u16AnalogalValue >= 3000) && (local_u16AnalogalValue < 4000))
			{
				LCD_voidCreateCustomCharacter(LCD_u8Vol3,2,LCD_u8_ROW2,LCD_u8_COL12);
			}
			else if((local_u16AnalogalValue >= 4000) && (local_u16AnalogalValue < 5000))
			{
				LCD_voidCreateCustomCharacter(LCD_u8Vol4,3,LCD_u8_ROW2,LCD_u8_COL13);
				local_u8Flag = 1;
			}
		}
		else
		{
			if((local_u16AnalogalValue >= 3000) && (local_u16AnalogalValue < 4000))
			{
				LCD_voidCreateCustomCharacter(LCD_u8DelVol,3,LCD_u8_ROW2,LCD_u8_COL13);
			}
			else if((local_u16AnalogalValue >= 2000) && (local_u16AnalogalValue < 3000))
			{
				LCD_voidCreateCustomCharacter(LCD_u8DelVol,2,LCD_u8_ROW2,LCD_u8_COL12);
			}
			else if((local_u16AnalogalValue >= 1000) && (local_u16AnalogalValue < 2000))
			{
				LCD_voidCreateCustomCharacter(LCD_u8DelVol,1,LCD_u8_ROW2,LCD_u8_COL11);
			}
			else if((local_u16AnalogalValue >= 100) && (local_u16AnalogalValue < 1000))
			{
				LCD_voidCreateCustomCharacter(LCD_u8DelVol,0,LCD_u8_ROW2,LCD_u8_COL10);
				local_u8Flag = 0;
			}
		}
	}
	return 0;
}




