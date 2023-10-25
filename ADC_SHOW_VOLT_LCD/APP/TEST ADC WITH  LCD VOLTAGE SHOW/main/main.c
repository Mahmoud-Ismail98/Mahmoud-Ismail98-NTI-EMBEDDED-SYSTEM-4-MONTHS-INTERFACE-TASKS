#include "../../../services/Bit_utils.h"
#include "../../../services/Std_types.h"
#include "../../../MCAL/PORT/include/port.h"
#include "../../../MCAL/DIO/include/DIO.h"
#include "../../../HAL/LCD/LCD_interface.h"
#include "../../../MCAL/ADC/ADC.h"
#include "../../../MCAL/EXT_INTERUPT/external_interrupt.h"
#include "../../../MCAL/DIO/include/DIO_private.h"
#include <util/delay.h>



lcd_voidPrintFloat(float Float_val );
void PTR_TO_FUN(void);
float Float_val;
u16 adc_read=0;
#define LED_PIN PIN_ID2
volatile u8 check =0;
volatile u8 GLOBAL_VAR=99;
u8 last_state;
u16 previous_read=0;

void main(void)
{

	Global_Interrupt_EnablE();
	Port_setPinDirection(LED_PIN,PIN_OUTPUT);
	extrnal_int_init(EXT_INT0,INT_FALLING_EDGE,&PTR_TO_FUN);
	Port_SetPinMode(PIN_ID26,PIN_IN_PULLUP);//	set INTERUPT0 PIN input pullup 
	Enable_EXT_INT(EXT_INT0);	
	LCD_voidInit();
	ADC_voidInit();
	LCD_voidWriteString("VOLT =");	
	while(1){
	ADC_read(ADC_CH0,&adc_read);
	Float_val =(float)(adc_read*5)/1024; 
	if(previous_read !=adc_read)
	{
		lcd_voidPrintFloat(Float_val);
		previous_read=adc_read;		
	}
	}	
}


lcd_voidPrintFloat(float Float_val )
{
	check=(GET_BIT(PORTA,2));
	u16 value_lcd=0;
	u8 val_2=0;
	if(check==1)
	{
		value_lcd =(u16) Float_val;
		LCD_voidWriteCharacter(value_lcd+'0');
		LCD_voidWriteCharacter('.');
		Float_val=Float_val-value_lcd;
		value_lcd=(u16)(Float_val*100);
		val_2=value_lcd/10;
		LCD_voidWriteCharacter(val_2+'0');
		value_lcd%=10;
		LCD_voidWriteCharacter(value_lcd+'0');
		LCD_voidWriteCharacter(' ');
		LCD_voidWriteString("V ");
	}
	else
	{
		value_lcd =(u16) Float_val;
		LCD_voidWriteCharacter(value_lcd+'0');
		Float_val=Float_val-value_lcd;
		value_lcd=(u16)(Float_val*100);
		val_2=value_lcd/10;
		LCD_voidWriteCharacter(val_2+'0');
		value_lcd%=10;
		LCD_voidWriteCharacter(value_lcd+'0');
		LCD_voidWriteCharacter(' ');
		LCD_voidWriteString("mv");
	}
	LCD_voidSetCursor(6,0);

}
void PTR_TO_FUN(void)
{
	TGL_BIT(PORTA,LED_PIN);
}