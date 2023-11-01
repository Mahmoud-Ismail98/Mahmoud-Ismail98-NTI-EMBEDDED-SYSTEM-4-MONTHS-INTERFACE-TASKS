#include "../LIB/Include/STD_TYPES.h"
#include "../LIB/Include/BIT_MATH.h"
#include "../MCAL/PORT/Include/PORT_interface.h"
#include "../MCAL/DIO/Include/DIO_interface.h"
#include "../MCAL/GIE/Include/GIE_interface.h"
#include "../MCAL/EXTI/Include/EXTI_interface.h"
#include "../MCAL/ADC/Include/ADC_interface.h"
#include "../HAL/LCD/Include/LCD_interface.h"
#define F_CPU   8000000UL
#include <util/delay.h>

#define TRUE            1
#define FALSE           0

void volt_change(void);
u8 EXTI_u8Flag = TRUE;

int main(void)
{
	u16 local_u16DigitalValue;
	u16 local_u16AnalogalValue;
	u16 local_u16TempValue;
	u16 local_u16Remainder;
	PORT_voidInit();
	GIE_voidInt(GIE_u8_ENABLE);
	EXTI_EXTIEnumEnable(EXTI_u8_INT_0,EXTI_u8_FALLING);
	ADC_voidInit();
	LCD_voidInit();
	LCD_u8DisplayString("VOLT = ");
	while(1)
	{
		if(EXTI_u8Flag == TRUE)
		{
			ADC_ADCEnumReadSync(ADC_CHANNEL_0,&local_u16DigitalValue);
			local_u16AnalogalValue = (u16)((local_u16DigitalValue * 5000UL) / 1024);
			LCD_voidGoToXY(LCD_u8_ROW1,LCD_u8_COL7);
			LCD_voidDisplayNumber(local_u16AnalogalValue);
			LCD_voidGoToXY(LCD_u8_ROW1,LCD_u8_COL14);
			LCD_u8DisplayString("mv");
			EXTI_EXTIEnumSetCallback(EXTI_u8_INT_0,&volt_change);
		}
		else
		{
			ADC_ADCEnumReadSync(ADC_CHANNEL_0,&local_u16DigitalValue);
			local_u16AnalogalValue = (u16)((local_u16DigitalValue * 5000UL) / 1024);
			local_u16TempValue = local_u16AnalogalValue / 1000;
			local_u16Remainder = (local_u16AnalogalValue % 1000) / 10;
			LCD_voidGoToXY(LCD_u8_ROW1,LCD_u8_COL7);
			LCD_voidDisplayNumber(local_u16TempValue);
			LCD_voidDisplayCharacter('.');
			LCD_voidDisplayNumber(local_u16Remainder);
			LCD_voidGoToXY(LCD_u8_ROW1,LCD_u8_COL14);
			LCD_u8DisplayString(" v");
			EXTI_EXTIEnumSetCallback(EXTI_u8_INT_0,&volt_change);
		}
		EXTI_EXTIEnumSetCallback(EXTI_u8_INT_0,&volt_change);
	}
	return 0;
}

void volt_change(void)
{
	if(EXTI_u8Flag == TRUE)
	{
		EXTI_u8Flag = FALSE;
	}
	else
	{
		EXTI_u8Flag = TRUE;
	}
}


