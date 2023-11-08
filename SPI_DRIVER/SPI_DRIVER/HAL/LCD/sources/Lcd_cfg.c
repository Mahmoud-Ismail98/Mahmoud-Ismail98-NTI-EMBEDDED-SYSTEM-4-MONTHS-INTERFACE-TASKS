/*
 * Lcd_cfg.c
 *
 * Created: 10/21/2023 11:50:15 PM
 *  Author: Sharpel
 */ 

#include "std_types.h"
#include "../../../MCAL/DIO/includes/Dio.h"
#include "../includes/Lcd_prv.h"
#include "../includes/Lcd_cfg.h"



/*
 IMPORTANT : USER MUST MAKE SURE THAT ALL PINS ARE CONFIGURED AS OUTPUT IN PORT_CFG.H FILE
*/
#if LCD_MODE == LCD_4_BIT_MODE

DIO_enu_PinId_t gl_enu_LCD_dataPins[LCD_4_BIT_MODE] = {DIO_PORTB_PIN0,DIO_PORTB_PIN1,DIO_PORTB_PIN2,DIO_PORTB_PIN3};
	
#elif LCD_MODE == LCD_8_BIT_MODE

DIO_enu_PinId_t gl_enu_LCD_dataPins[LCD_8_BIT_MODE] =
{
	DIO_PORTA_PIN0,DIO_PORTA_PIN1,DIO_PORTA_PIN2,DIO_PORTA_PIN3,
	DIO_PORTA_PIN4,DIO_PORTA_PIN5,DIO_PORTA_PIN6,DIO_PORTA_PIN7,
};
#else

#error "Configuration Error see LCD_MODE MACRO"
#endif

