/*
 * LCD.C
 *
 * Created: 10/21/2023 2:19:27 PM
 *  Author: FADY
 */ 
#define F_CPU 8000000UL			
#include <util/delay.h>	
		
#include "Std_types.h"
#include "Bit_utils.h"
#include "DIO.h"
#include "LCD.h"
#include "LCD_prv.h"
#include "LCD_cfg.h"



void LCD_VoidSendDataBus( u8 Copy_u8Data )
{
#if	LCD_MODE	==	LCD_4BIT_MODE 
	/*SENDING HIGH NIBBLE*/
	DIO_enuWriteChannel(LCD_PIN_DATA_4,GET_BIT(Copy_u8Data,4));
	DIO_enuWriteChannel(LCD_PIN_DATA_5,GET_BIT(Copy_u8Data,5));
	DIO_enuWriteChannel(LCD_PIN_DATA_6,GET_BIT(Copy_u8Data,6));
	DIO_enuWriteChannel(LCD_PIN_DATA_7,GET_BIT(Copy_u8Data,7));
	/* Enable pulse */
	DIO_enuWriteChannel(LCD_PIN_EN,LCD_PIN_HIGH);
	_delay_us(1);
	DIO_enuWriteChannel(LCD_PIN_EN,LCD_PIN_LOW);
	_delay_us(200);

	/*SENDING HIGH NIBBLE*/
	DIO_enuWriteChannel(LCD_PIN_DATA_4,GET_BIT(Copy_u8Data,0));
	DIO_enuWriteChannel(LCD_PIN_DATA_5,GET_BIT(Copy_u8Data,1));
	DIO_enuWriteChannel(LCD_PIN_DATA_6,GET_BIT(Copy_u8Data,2));
	DIO_enuWriteChannel(LCD_PIN_DATA_7,GET_BIT(Copy_u8Data,3));

	/* Enable pulse */
	DIO_enuWriteChannel(LCD_PIN_EN,LCD_PIN_HIGH);
	_delay_us(1);
	DIO_enuWriteChannel(LCD_PIN_EN,LCD_PIN_LOW);
	_delay_us(200);
#elif	LCD_MODE	==	LCD_8BIT_MODE 
	/*SENDING HIGH NIBBLE*/
	DIO_enuWriteChannel(LCD_PIN_DATA_0,GET_BIT(Copy_u8Data,0));
	DIO_enuWriteChannel(LCD_PIN_DATA_1,GET_BIT(Copy_u8Data,1));
	DIO_enuWriteChannel(LCD_PIN_DATA_2,GET_BIT(Copy_u8Data,2));
	DIO_enuWriteChannel(LCD_PIN_DATA_3,GET_BIT(Copy_u8Data,3));
	DIO_enuWriteChannel(LCD_PIN_DATA_4,GET_BIT(Copy_u8Data,4));
	DIO_enuWriteChannel(LCD_PIN_DATA_5,GET_BIT(Copy_u8Data,5));
	DIO_enuWriteChannel(LCD_PIN_DATA_6,GET_BIT(Copy_u8Data,6));
	DIO_enuWriteChannel(LCD_PIN_DATA_7,GET_BIT(Copy_u8Data,7));

	/* Enable pulse */
	DIO_enuWriteChannel(LCD_PIN_EN,LCD_PIN_HIGH);
	_delay_us(1);
	DIO_enuWriteChannel(LCD_PIN_EN,LCD_PIN_LOW);
	_delay_us(200);

#endif
}

void LCD_VoidInit (void)			
{			
	_delay_ms(20);	
	/* LCD Power ON delay always >20ms */
	DIO_enuWriteChannel(LCD_PIN_RS,LCD_PIN_LOW);
	/*  4 bit initialization of LCD  */
#if	LCD_MODE	==	LCD_4BIT_MODE 
	LCD_VoidSendDataBus(LCD_4MODE_SET);	
	/* 2 line, 5*7 matrix in 4-bit mode */	
	LCD_VoidSendDataBus(lCD_2LINE_SET);
#elif	LCD_MODE	==	LCD_8BIT_MODE
	LCD_VoidSendDataBus(LCD_8MODE_SET);	
#endif		
	/* Display on cursor off*/
	LCD_VoidSendDataBus(LCD_DISPLAY_ON_CURSOR_OFF);
	/* Increment cursor (shift cursor to right)*/	
	LCD_VoidSendDataBus(LCD_SHIFT_CURSOR_SET);	
	/* Clear display screen*/	
	LCD_VoidSendDataBus(LCD_CLEAR_LCD);		
	_delay_ms(2);
}


void LCD_VOidSendChar( u8 Copy_u8Data )
{
 DIO_enuWriteChannel(LCD_PIN_RS,LCD_PIN_HIGH);
 LCD_VoidSendDataBus( Copy_u8Data );
}


void LCD_VoidSendString (pu8 Copy_Addu8Str)		
{
	u32 Loc_u32Iterator;
	for(Loc_u32Iterator=0;Copy_Addu8Str[Loc_u32Iterator]!=NULL;Loc_u32Iterator++)		/* Send each char of string till the NULL */
	{
		LCD_VOidSendChar(Copy_Addu8Str[Loc_u32Iterator]);
	}
}


void LCD_Goto_xy (u8 Copy_u8Row, u8 Copy_u8Col)	
{
	DIO_enuWriteChannel(LCD_PIN_RS,LCD_PIN_LOW);
 	LCD_VoidSendDataBus( LCD_CURSOR_HOME + Copy_u8Row + Copy_u8Col );		
}

void LCD_VoidSendNumbers(float Copy_f32Number)
{
    u8 Loc_u8Array[20];
    u32 Loc_f32Number = (u32)(Copy_f32Number * 100);
    s8 Loc_s8Counter = 0;
    u8 isNegative = 0;

    if (Copy_f32Number < 0) {
        isNegative = 1;
        Loc_f32Number = -Loc_f32Number;
    }

    do {
        Loc_u8Array[Loc_s8Counter] = Loc_f32Number % 10;
        Loc_f32Number /= 10;
        Loc_s8Counter++;
    } while (Loc_f32Number > 0);

    if (isNegative) {
        LCD_VOidSendChar('-');
    }

    while (Loc_s8Counter > 0) {
        if (Loc_s8Counter == 2) {
            LCD_VOidSendChar('.');
        }
        Loc_s8Counter--;
        LCD_VOidSendChar(Loc_u8Array[Loc_s8Counter] + '0');
        _delay_us(2);
    }
}
void LCD_VoidSendInteger(u32 Copy_u32Number) {
    if (Copy_u32Number < 10) {
        LCD_VOidSendChar('0');  // Display leading zero
    }
    
    u8 Loc_u8Array[10];
    s8 Loc_s8Counter = 0;
    u8 isNegative = 0;

    if (Copy_u32Number < 0) {
        isNegative = 1;
        Copy_u32Number = -Copy_u32Number;
    }

    do {
        Loc_u8Array[Loc_s8Counter] = Copy_u32Number % 10;
        Copy_u32Number /= 10;
        Loc_s8Counter++;
    } while (Copy_u32Number > 0);

    if (isNegative) {
        LCD_VOidSendChar('-');
    }

    while (Loc_s8Counter > 0) {
        Loc_s8Counter--;
        LCD_VOidSendChar(Loc_u8Array[Loc_s8Counter] + '0');
        _delay_us(2);
    }
}


void LCD_VoidClear()
{	
	DIO_enuWriteChannel(LCD_PIN_RS,LCD_PIN_LOW);
	/* Clear display */
	LCD_VoidSendDataBus(LCD_CLEAR_LCD);		
	_delay_ms(2);
	/* Cursor at home position */
	LCD_VoidSendDataBus(LCD_CURSOR_HOME);		
}


void LCD_Calculator_Init() {
    LCD_VoidInit();
    LCD_VoidClear();
}

void LCD_VoidCreateSpectialChar(u8 Copy_u8Index, pu8 Copy_u8Data)
 {

	Copy_u8Index *= 8;
    DIO_enuWriteChannel(LCD_PIN_RS, LCD_PIN_LOW);
    LCD_VoidSendDataBus(0x40+Copy_u8Index); // Send CGRAM address
    DIO_enuWriteChannel(LCD_PIN_RS, LCD_PIN_HIGH);
    for (u8 i = 0; i < 8; i++) {
        LCD_VoidSendDataBus(Copy_u8Data[i]);
    }
}