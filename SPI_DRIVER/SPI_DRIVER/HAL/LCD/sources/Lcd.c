/*
 * Lcd.c
 *
 * Created: 10/20/2023 5:06:14 AM
 *  Author: sharb
 */ 

#include "std_types.h"
#include "bit_math.h"
#include "../../../MCAL/DIO/includes/Dio.h"
#include "../includes/Lcd_prv.h"
#include "../includes/Lcd.h"
#include "../includes/Lcd_cfg.h"
#define  F_CPU   1000000UL
#include "util/delay.h"


extern DIO_enu_PinId_t gl_enu_LCD_dataPins[LCD_MODE];

/*
 * function		: LCD_vidInit
 * description 	: func to set LCD initialization 
                  before you call this function make sure that chosen pins in cfg.h and cfg.c are configured as output_low in PORT_cfg.h
 * input param 	: void
 * return		: void
 * */
void LCD_vidInit(void)
{
	_delay_ms(50);
	
	LCD_vidSendCommand(LCD_CURSOR_HOME);
	#if   LCD_MODE == LCD_4_BIT_MODE
	LCD_vidSendCommand(LCD_4_BIT_MODE_SELECTION);
	#elif LCD_MODE == LCD_8_BIT_MODE
	LCD_vidSendCommand(LCD_8_BIT_MODE_SELECTION);
	#else
	#error "LCD MODE ERROR CHECK MACRO IN Lcd_cfg.h file"
	#endif
	
	LCD_vidSendCommand(LCD_CLEAR_DISPLAY);
	_delay_ms(4);

	LCD_vidSendCommand(LCD_ENTRY_MODE_CURSOR_INCREMENT);
	_delay_ms(1);

	LCD_vidSendCommand(LCD_DISPLAY_ON_CURSOR_ON_NO_BLINK);
	_delay_ms(1);
}
void LCD_vidSendCommand(u8 arg_u8_command)
{
	u8 loc_u8_itrator;
	DIO_enu_WriteChannel(RS_PIN,DIO_PIN_LEVEL_LOW); // CHOOSE COMMAND
	DIO_enu_WriteChannel(RW_PIN,DIO_PIN_LEVEL_LOW); // CHOOSE WRITE
	#if   LCD_MODE == LCD_4_BIT_MODE
	u8 loc_u8_temp = FALSE;
	loc_u8_temp    = (arg_u8_command & 0xF0)>>4;
	
	for(loc_u8_itrator = FALSE ; loc_u8_itrator < LCD_4_BIT_MODE ; loc_u8_itrator++ )
	{
		DIO_enu_WriteChannel(gl_enu_LCD_dataPins[loc_u8_itrator],GET_BIT(loc_u8_temp,loc_u8_itrator));
	}
	
	DIO_enu_WriteChannel(E_PIN,DIO_PIN_LEVEL_HIGH); // Enable High
	_delay_ms(1);
	DIO_enu_WriteChannel(E_PIN,DIO_PIN_LEVEL_LOW); // Enable Low
	_delay_us(200);
	
	loc_u8_temp    = (arg_u8_command & 0x0F);
	
	for(loc_u8_itrator = FALSE ; loc_u8_itrator < LCD_4_BIT_MODE ; loc_u8_itrator++ )
	{
		DIO_enu_WriteChannel(gl_enu_LCD_dataPins[loc_u8_itrator],GET_BIT(loc_u8_temp,loc_u8_itrator));
	}
	
	DIO_enu_WriteChannel(E_PIN,DIO_PIN_LEVEL_HIGH); // Enable High
	_delay_ms(1);
	DIO_enu_WriteChannel(E_PIN,DIO_PIN_LEVEL_LOW); // Enable Low
	_delay_ms(2);

	
	#elif LCD_MODE == LCD_8_BIT_MODE
	
	for(loc_u8_itrator = FALSE ; loc_u8_itrator < LCD_8_BIT_MODE ; loc_u8_itrator++ )
	{
		DIO_enu_WriteChannel(gl_enu_LCD_dataPins[loc_u8_itrator],GET_BIT(arg_u8_command,loc_u8_itrator));
	}
	
	DIO_enu_WriteChannel(E_PIN,DIO_PIN_LEVEL_HIGH); // Enable High
	_delay_ms(1);
	DIO_enu_WriteChannel(E_PIN,DIO_PIN_LEVEL_LOW); // Enable Low
	_delay_ms(2);
	#else
	#error "LCD MODE ERROR CHECK MACRO IN Lcd_cfg.h file"
	#endif
}
void LCD_vidDisplayCharacter(u8 arg_u8_data)
{
	u8 loc_u8_itrator;
	DIO_enu_WriteChannel(RS_PIN,DIO_PIN_LEVEL_HIGH); // CHOOSE DATA
	DIO_enu_WriteChannel(RW_PIN,DIO_PIN_LEVEL_LOW); // CHOOSE WRITE
	#if   LCD_MODE == LCD_4_BIT_MODE
	u8 loc_u8_temp = FALSE;
	loc_u8_temp    = (arg_u8_data & 0xF0)>>4;
	
	for(loc_u8_itrator = FALSE ; loc_u8_itrator < LCD_4_BIT_MODE ; loc_u8_itrator++ )
	{
		DIO_enu_WriteChannel(gl_enu_LCD_dataPins[loc_u8_itrator],GET_BIT(loc_u8_temp,loc_u8_itrator));
	}
	
	DIO_enu_WriteChannel(E_PIN,DIO_PIN_LEVEL_HIGH); // Enable High
	_delay_ms(1);
	DIO_enu_WriteChannel(E_PIN,DIO_PIN_LEVEL_LOW); // Enable Low
	_delay_us(200);
	
	loc_u8_temp    = (arg_u8_data & 0x0F);
	
	for(loc_u8_itrator = FALSE ; loc_u8_itrator < LCD_4_BIT_MODE ; loc_u8_itrator++ )
	{
		DIO_enu_WriteChannel(gl_enu_LCD_dataPins[loc_u8_itrator],GET_BIT(loc_u8_temp,loc_u8_itrator));
	}
	
	DIO_enu_WriteChannel(E_PIN,DIO_PIN_LEVEL_HIGH); // Enable High
	_delay_ms(1);
	DIO_enu_WriteChannel(E_PIN,DIO_PIN_LEVEL_LOW); // Enable Low
	_delay_ms(2);

	
	#elif LCD_MODE == LCD_8_BIT_MODE
	
	for(loc_u8_itrator = FALSE ; loc_u8_itrator < LCD_8_BIT_MODE ; loc_u8_itrator++ )
	{
		DIO_enu_WriteChannel(gl_enu_LCD_dataPins[loc_u8_itrator],GET_BIT(arg_u8_data,loc_u8_itrator));
	}
	
	DIO_enu_WriteChannel(E_PIN,DIO_PIN_LEVEL_HIGH); // Enable High
	_delay_ms(1);
	DIO_enu_WriteChannel(E_PIN,DIO_PIN_LEVEL_LOW); // Enable Low
	_delay_ms(2);
	#else
	#error "LCD MODE ERROR CHECK MACRO IN Lcd_cfg.h file"
	#endif
}
void LCD_vidCreateCustomCharacter(u8 *arg_u8_data_array,u8 arg_u8_index)
{
	u8 loc_u8_itrator = FALSE;
	if (arg_u8_index < CGRAM_MAX_INDEX)  // CGRAM only store 8 characters
	{
		LCD_vidSendCommand(LCD_SET_CGRAM_ADDR_CMD + (arg_u8_index*CGRAM_INDEX_BYTES));
		_delay_ms(1);
		for ( ; loc_u8_itrator < CGRAM_INDEX_BYTES ; loc_u8_itrator++)
		{
			LCD_vidDisplayCharacter(arg_u8_data_array[loc_u8_itrator]);
		}
		
		LCD_vidSendCommand(LCD_SET_DDRAM_ADDR_CMD);
	}
}
void LCD_vidGoToXY(u8 arg_u8_row,u8 arg_u8_col)
{
	if(arg_u8_row == 0)
	{
	   LCD_vidSendCommand(LCD_SET_DDRAM_ADDR_CMD + 0 + arg_u8_col);
	}
	else if (arg_u8_row == 1)
	LCD_vidSendCommand(LCD_SET_DDRAM_ADDR_CMD + 0x40 + arg_u8_col);
	else if (arg_u8_row == 2)
	LCD_vidSendCommand(LCD_SET_DDRAM_ADDR_CMD + 0x14 + arg_u8_col);
	else if (arg_u8_row == 3)
	LCD_vidSendCommand(LCD_SET_DDRAM_ADDR_CMD + 0x54 + arg_u8_col);
}
void LCD_vidDisplayString(u8 *arg_u8_string)
{
	u8 loc_u8_itartor = FALSE;
	while(arg_u8_string[loc_u8_itartor] != STR_NULL)
	{
		LCD_vidDisplayCharacter(arg_u8_string[loc_u8_itartor++]);
	}
}
void LCD_vidDisplayNumber(u32 arg_u32_number)
{
	u8 loc_u8_inverse = TRUE;
	
	while(arg_u32_number != FALSE)
	{
		loc_u8_inverse*=10;
		loc_u8_inverse+=arg_u32_number%10;
		arg_u32_number/=10;
	}
	
	while(loc_u8_inverse != TRUE)
	{
		LCD_vidDisplayCharacter((loc_u8_inverse%10)+'0');
		loc_u8_inverse/=10;
	}
}
void LCD_vidClrDisplay(void)
{
	LCD_vidSendCommand(LCD_CLEAR_DISPLAY);
	_delay_ms(4);
	LCD_vidSendCommand(LCD_CURSOR_HOME);
	_delay_ms(4);

}