/*
 * Application.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Ismail
 */
#include"../MCAL/PORT/PORT.h"
#include"../MCAL/DIO/DIO.h"
#include"../HAL/LCD/LCD.h"
#include"../MCAL/ADC/ADC.h"
#include"../MCAL/GIE/GIE.h"
#include"../MCAL/EXIT/EXIT.h"
#include <util/delay.h>



/* this application is display potentiometer reading in voltage on lCD and
when button is pressed the display range changes
*/
#include <util/delay.h>
u8 conv[2]="mV";
u8 data[12]= "ADC OUTPUT:";
u32 volt=0;
u16 Reading=0;
u8 flag =0;

void Interrupt_SwitchReading(void){
	if(flag ==0){
		flag =1;
	}
	else if (flag ==1){
		flag =0;
	}

}

int main (){

	Port_enuSetPinDirection(0,PORT_u8INPUT);
	Port_enuSetPinDirection(26,PORT_u8INPUT);
	Port_enuSetPinMode(26,PORT_u8INPUT_PULLUP);
	Dio_enuWriteChannel(26,DIO_u8LEVEL_HIGH);
	ADC_Init();
	EXIT0_Init();
	LCDInit4BitMode();
	EXTI_voidCallBack(Interrupt_SwitchReading,EXTI_LINE0);
	GIEMode(GIE_ENABLE);
	while(1){
	if(flag ==0){
		Reading = ADC_StartConversion(ADC_CHANNEL_0);
		volt =(Reading*5)/1023;
		LCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
		LCD_WriteString(data); 	_delay_ms(40);
		LCD_SetCursorPosition(LCD_LINE_0,12); 	_delay_ms(40);
		LCD_WriteNumber(volt); 	_delay_ms(40);
		LCD_SetCursorPosition(LCD_LINE_1,14); 	_delay_ms(40);
		LCD_WriteChar4Bit('V'); 	_delay_ms(40);
		LCD_SetCursorPosition(LCD_LINE_0,0);
		_delay_ms(40);
	}
	else if (flag ==1)
	{
		Reading = ADC_StartConversion(ADC_CHANNEL_0);
		volt =1000*(Reading*5.00)/1023;
		LCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
					LCD_WriteString(data);
					_delay_ms(40);
					LCD_SetCursorPosition(LCD_LINE_0,12);
					_delay_ms(40);
					LCD_WriteNumber(volt);
					_delay_ms(40);
					LCD_SetCursorPosition(LCD_LINE_1,14);
					_delay_ms(40);
					LCD_WriteString(conv);
					_delay_ms(40);
					LCD_SetCursorPosition(LCD_LINE_0,0);

	}


		}
	return 0;


}
