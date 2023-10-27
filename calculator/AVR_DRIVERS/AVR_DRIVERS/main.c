/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include "SERVICES/Standard_Data_Types.h"
#include "SERVICES/Bit_Wise_Operations.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/DIO/DIO.h"
#include "HAL/BUTTON/BUTTON.h"
#include "HAL/7_SEGMENT/7_SEGMENT.h"
#include "HAL/LCD/LCD_COMANDS.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/GIE/GIE.h"
#include "MCAL/EXTI/EXTI.h"
#include "MCAL/TIMER0/TIMER0.h"
#include "HAL/KEY_PAD/KEY_PAD.h"


void over_Flow_ISR(void);
void math_error_display(void);
void clculate(void);
void clculate2(void);
f32 result=0;
volatile u8 SECONDS = 0;

LCD_4BIT_ST lcd = {.lcd_pins[0] = PIN_B0_ID_8,
                   .lcd_pins[1] = PIN_B1_ID_9,
                   .lcd_pins[2] = PIN_B2_ID_10,
                   .lcd_pins[3] = PIN_B4_ID_12,
                   .lcd_pin_rs = PIN_A3_ID_3,
                   .lcd_pin_e = PIN_A2_ID_2};

KEY_PAD_ST keypad = {
    .key_pad_rows_pins[0] = DIO_C5_ID_21,
    .key_pad_rows_pins[1] = DIO_C4_ID_20,
    .key_pad_rows_pins[2] = DIO_C3_ID_19,
    .key_pad_rows_pins[3] = DIO_C2_ID_18,
    .key_pad_col_pins[0] = DIO_D7_ID_31,
    .key_pad_col_pins[1] = DIO_D6_ID_30,
    .key_pad_col_pins[2] = DIO_D5_ID_29,
    .key_pad_col_pins[3] = DIO_D3_ID_27,
};
u8 keypad_value = '@';
u8 key_status = KEY_NOT_PRESSED;
u8 counter=0;
u32 inputs[20];
u8 force_clear=1;
int main(void) {
  Port_vidInit();
  GIE_INIT();
  LCD_vidInit_4bit(&lcd);
  LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
  key_pad_Init(&keypad);
  TIMER0_INT();
  TIMER0_SET_OVRRFLOW_CALLBACK(over_Flow_ISR);
  while (1) {
	  if (KEY_PRESSED == key_status) {
		  switch(keypad_value){
		  case 'c':
			key_status=KEY_NOT_PRESSED;
			LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
			LCD_vidSendcommand_4bit(&lcd,LCD_CURSOR_HOME);
			counter=0;
			for (u8 i=0;i<counter;i++)
			{
				inputs[i]=0;
			}
			force_clear=1;
			break;
		  case'=':
		   if (force_clear)
		   {
				key_status=KEY_NOT_PRESSED;
				force_clear=0;
				clculate2();
		   }
		    break;
		  default:
			key_status=KEY_NOT_PRESSED;
			inputs[counter]=keypad_value;
			counter++;
			if(counter>=20)
			{
				LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
				LCD_vidGotoXY_4bit(&lcd,2,5);
				LCD_vidDisplayString_4bit(&lcd,"maximum range");
			}
			break;
		  }
;
	  }
  }
}


void math_error_display(void)
{
	LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
	LCD_vidGotoXY_4bit(&lcd,2,5);
	LCD_vidDisplayString_4bit(&lcd,"math error");
}



void clculate2(void){
	f32 f_operand=0;
	f32 s_operand=0;
	u8 operatorr=0;
	u8 indecator=1;
	s8 sign_helper1=1;
	s8 sign_helper2=1;
	f32 result=0;
	u8 firstsign_lock=0;
	u8 secondsign_lock=1;
	if(inputs[0]=='/'||inputs[0]=='*')
	{
		 math_error_display();
		return ;
	}
	for(u8 local_counter=0;local_counter<counter;local_counter++)
	{
		if(inputs[local_counter]>='0'&&inputs[local_counter]<='9'&&indecator==1)
		{
			f_operand=f_operand*10+inputs[local_counter]%48;//take first operand
			firstsign_lock=1;
			//indecator=2;
		}
		else if(inputs[local_counter]>='0'&&inputs[local_counter]<='9'&&indecator==3)
		{
			s_operand=s_operand*10+inputs[local_counter]%48;
		}

		else if(indecator==1&&inputs[local_counter]=='-'&&firstsign_lock==0)
		{
			sign_helper1=-1;
			firstsign_lock=1;
		}
		else if(indecator==3&&inputs[local_counter]=='-')
		{
			sign_helper2=-1;
		}
		else if(indecator==1&&operatorr==0)
		{
			indecator=3;// ready to take second operand
			operatorr=inputs[local_counter];
		}

	}
	 f_operand*=sign_helper1;
	 s_operand*=sign_helper2;
	switch(operatorr)
	{
		case '+':
			result=(f32)f_operand+s_operand;
			break;
		case '-':
			result=(f32)f_operand-s_operand;
			break;
		case '/':
			if(s_operand==0)
			{
				math_error_display();
				return ;
				break;
			}
			result=(f32)f_operand/s_operand;
			break;
		case '*':
			result=(f32)f_operand*s_operand;
			break;
	}
	if(result<0)
	{
		LCD_vidDisplayChar_4bit(&lcd,'-');
		result=result*-1;
	}
	LCD_vidDisplayFloatNumber_4bit(&lcd,result);
	return ;
}
/*
void clculate(void){
	f32 f_operand=0;
	f32 s_operand=0;
	f32 result=0;
	u8 operator=0;
	u8 indecator=1;
	s8 sign_helper=-1;
	if(inputs[0]=='/'||inputs[0]=='*')
	{
		math_error_display();
		return ;
	}
	for(u8 local_counter=0;local_counter<counter;local_counter++)
	{
		if(inputs[local_counter]>='0'&&inputs[local_counter]<='9'&&indecator==1)
		{
			f_operand=f_operand*10+inputs[local_counter]%48;//take first operand
		}
		else if(inputs[local_counter]>='0'&&inputs[local_counter]<='9'&&indecator==2)
		{
			s_operand=s_operand*10+inputs[local_counter]%48;
		}
		else
		{
			indecator=2;// ready to take second operand
			operator=inputs[local_counter];
		}
	}
	switch(operator)
	{
		case '+':
		result=(f32)f_operand+s_operand;
		break;
		case '-':
		result=(f32)f_operand-s_operand;
		break;
		case '/':
		if(s_operand==0)
		{
			math_error_display();
			break;
		}
		result=(f32)f_operand/s_operand;
		break;
		case '*':
		result=(f32)f_operand*s_operand;
		break;
	}
	if(result<0)
	{
		LCD_vidDisplayChar_4bit(&lcd,'-');
		result=result*-1;
	}
	LCD_vidDisplayFloatNumber_4bit(&lcd,result);
	return ;
}
void over_Flow_ISR(void) {
	SECONDS++;// get the keypad by timer isr
	if (SECONDS == 15) {
		SECONDS = 0;
		key_status = key_pad_Get_value(&keypad, &keypad_value);
		if (KEY_PRESSED == key_status) {
			LCD_vidDisplayChar_4bit(&lcd, keypad_value);
		}
	}
}
*/