/*
 * LCD.c
 *
 * Created: 10/21/2023 9:29:31 AM
 *  Author: Ahmed Wael
 */

#define F_CPU 16000000
#include "util/delay.h"


#include "Bit_Utils.h"
#include "Std_Types.h"

#include "../inc/LCD_prv.h"
#include "../inc/LCD_cfg.h"
#include "../inc/LCD.h"

 /*4 BIT MODE INIT*/
static void LCD_voidSendCommand(u8 Copy_u8Command)
{
	Dio_enuWriteChannel(RS,DIO_u8LEVEL_LOW);
	/*Send High Nipple*/
	Dio_enuWriteChannel(D7,GET_BIT(Copy_u8Command,7));
	Dio_enuWriteChannel(D6,GET_BIT(Copy_u8Command,6));
	Dio_enuWriteChannel(D5,GET_BIT(Copy_u8Command,5));
	Dio_enuWriteChannel(D4,GET_BIT(Copy_u8Command,4));
	/*EN Pulse*/
	Dio_enuWriteChannel(EN,DIO_u8LEVEL_HIGH);
	_delay_ms(1);
	Dio_enuWriteChannel(EN,DIO_u8LEVEL_LOW);
	_delay_ms(1);
	/*Send Low Nipple*/
	Dio_enuWriteChannel(D7,GET_BIT(Copy_u8Command,3));
	Dio_enuWriteChannel(D6,GET_BIT(Copy_u8Command,2));
	Dio_enuWriteChannel(D5,GET_BIT(Copy_u8Command,1));
	Dio_enuWriteChannel(D4,GET_BIT(Copy_u8Command,0));
	/*EN Pulse*/
	Dio_enuWriteChannel(EN,DIO_u8LEVEL_HIGH);
	_delay_ms(1);
	Dio_enuWriteChannel(EN,DIO_u8LEVEL_LOW);
	_delay_ms(1);
}

static void LCD_voidSendData(u8 Copy_u8Data)
{
	Dio_enuWriteChannel(RS,DIO_u8LEVEL_HIGH);
	/*Send High Nipple*/
	Dio_enuWriteChannel(D7,GET_BIT(Copy_u8Data,7));
	Dio_enuWriteChannel(D6,GET_BIT(Copy_u8Data,6));
	Dio_enuWriteChannel(D5,GET_BIT(Copy_u8Data,5));
	Dio_enuWriteChannel(D4,GET_BIT(Copy_u8Data,4));
	/*EN Pulse*/
	Dio_enuWriteChannel(EN,DIO_u8LEVEL_HIGH);
	_delay_ms(1);
	Dio_enuWriteChannel(EN,DIO_u8LEVEL_LOW);
	_delay_ms(1);
	/*Send Low Nipple*/
	Dio_enuWriteChannel(D7,GET_BIT(Copy_u8Data,3));
	Dio_enuWriteChannel(D6,GET_BIT(Copy_u8Data,2));
	Dio_enuWriteChannel(D5,GET_BIT(Copy_u8Data,1));
	Dio_enuWriteChannel(D4,GET_BIT(Copy_u8Data,0));
	/*EN Pulse*/
	Dio_enuWriteChannel(EN,DIO_u8LEVEL_HIGH);
	_delay_ms(1);
	Dio_enuWriteChannel(EN,DIO_u8LEVEL_LOW);
	_delay_ms(1);
}

void LCD_voidInit()
{
	_delay_ms(50);

	LCD_voidSendCommand(0x02); //Dummy Data for Init
	LCD_voidSendCommand(LCD_FunctionSetCommand);
	_delay_ms(1);

	LCD_voidSendCommand(LCD_DisplayOnOffCommand);
	_delay_ms(1);

	LCD_voidSendCommand(LCD_DisplayClearCommand);
	_delay_ms(2);

	LCD_voidSendCommand(LCD_EntryModeCommand);
	_delay_ms(2);
}

void LCD_voidDisplayChar(u8 Copy_u8Character)
{
	LCD_voidSendData(Copy_u8Character);
}

void LCD_voidDisplayString(u8* Ptr_u8String)
{
	u8 i;
	for(i=0;Ptr_u8String[i];i++)
	{
		LCD_voidDisplayChar(Ptr_u8String[i]);
	}
}



void LCD_voidGoToXY(u8 Copy_u8X, u8 Copy_u8Y)
{
	if(Copy_u8Y == 0)
	{
		LCD_voidSendCommand(0x80+Copy_u8X);
	}
	else if(Copy_u8Y == 1)
	{
		LCD_voidSendCommand(0x80+0x40+Copy_u8X);
	}
	else if(Copy_u8Y == 2)
	{
		LCD_voidSendCommand(0x80+0x14+Copy_u8X);
	}
	else if(Copy_u8Y == 3)
	{
		LCD_voidSendCommand(0x80+0x54+Copy_u8X);
	}

}

void LCD_voidCreateCustomChar(pu8 Copy_pu8CharArray, u8 Copy_u8CharAddress)
{
	u8 Local_u8add = (0b01000000) | (Copy_u8CharAddress<<3);
	LCD_voidSendCommand(Local_u8add);
	for(u8 i = 0 ; i < 8 ; i++)
	{
		LCD_voidSendData(Copy_pu8CharArray[i]);
	}
}


void LCD_voidDisplayNumbers(u32 Copy_u32Number)
{
	u8 rem,i=0,str[16];
	s8 j;
	if (Copy_u32Number==0)
	{
		LCD_voidDisplayChar('0');
		return;
	}
	if (Copy_u32Number<0)
	{
		Copy_u32Number=Copy_u32Number*(-1);
		LCD_voidDisplayChar('-');
	}

	while(Copy_u32Number)
	{
		rem=Copy_u32Number%10;
		rem=rem+'0';
		str[i]=rem;
		i++;
		Copy_u32Number=Copy_u32Number/10;
	}

	for (j=i-1;j>=0;j--)
	{
		LCD_voidDisplayChar(str[j]);
	}
}

void LCD_voidClear()
{
	LCD_voidSendCommand(0x01);
	_delay_ms(1);
}

