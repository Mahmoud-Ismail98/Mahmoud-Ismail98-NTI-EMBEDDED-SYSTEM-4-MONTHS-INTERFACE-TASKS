#include "../../../services/Bit_utils.h"
#include "../../../services/Std_types.h"
#include "../../../MCAL/PORT/include/port.h"
#include "../../../MCAL/DIO/include/DIO.h"
//#include "../../MCAL/DIO/include/DIO_cfg.h"
//#include "../../MCAL/DIO/include/DIO_private.h"
#include "../../../HAL/LCD/LCD_interface.h"
#include "../../../HAL/KEYPAD/KEYPAD.h"
#include <util/delay.h>

u8 count_input_num=0;
u8 key_pressed=11;
u16 arr_passed_input[];
u16 result=0;
u16 arr_sim[10];
#define key_freed   11	  
u8 operation_end=1;


u8 calculate_inputSIM(u16 arr[])
{
	u16 operend1=0;
	u16 operend2=0;
	u16 logic_operation;
	u8 operation_offset;

	u16 logic_operation_result;
	

	for (u8 i=0;i<count_input_num;i++)
	{
		if (arr[i]>9)
		{
			logic_operation=arr[i];
			operation_offset=i;
			break;
		}
	}

	for (u8 y=0;y<operation_offset;y++)
	{
		operend1+=arr[y]*pow(10,(operation_offset-(y+1)));
	}
	for (u8 z=operation_offset+1;z<count_input_num;z++)
	{
		operend2+=arr[z]*pow(10,(count_input_num-(z+1)));
	}
	if (logic_operation==0xFF)
	{
	  logic_operation_result=operend1/operend2;
			
	}
	else if(logic_operation==0xFA)
	{
		logic_operation_result=operend1*operend2;
	}
	else if(logic_operation==0xFD)
	{
		logic_operation_result=operend1-operend2;
	}
	else if(logic_operation==0xFB)
	{
		logic_operation_result=operend1+operend2;
	}			
	return logic_operation_result;
}
/*
u8 calculate_input(u8 arr[])
{
	//u16 logic_operation;
	//u8 operation_offset;
	u16 logic_operation_result;
	
	//u16 operend1=0;
	//u16 operend2=0;
	for (u8 i=0;i<count_input_num;i++)
	{
		if (arr[i]>9)
		{
			logic_operation=arr[i];
			operation_offset=i;
			break;
		}
	}
	for (u8 y=0;y<operation_offset;y++)
	{
		//operend1+=arr[y]*(10^(operation_offset-y));
		 operend1+=arr[y]*pow(10,(operation_offset-(y+1)));
	}
	for (u8 y=operation_offset+1;y<count_input_num;y++)
	{
		//operend2+=arr[y]*(10^(count_input_num-y));
		operend2+=arr[y]*pow(10,(count_input_num-(y+1)));		
	}
		if (logic_operation==0xFF)
		{
			logic_operation_result=operend1/operend2;
			
		}
		else if(logic_operation==0xFA)
		{
			logic_operation_result=operend1*operend2;
		}
		else if(logic_operation==0xFD)
		{
			logic_operation_result=operend1-operend2;
		}
		else if(logic_operation==0xFB)
		{
			logic_operation_result=operend1+operend2;
		}
		return logic_operation_result;
/*	switch(logic_operation)
	{
		case 0xFF:
		logic_operation_result=operend1/operend2;
		break;
		
		case 0xFA:
		logic_operation_result=operend1*operend2;
		break;
		
		case 0xFD:
		logic_operation_result=operend1-operend2;
		break;
		
		case 0xFB :
		logic_operation_result=operend1+operend2;
		break;
		
		default:
		break;
		
	}
	
	return logic_operation_result;*/
//}
//
int main(void)
{
   LCD_voidInit();
   KEYPAD_voidInit(); 
while(1){ 
	LCD_voidWriteString("enter");  
   LCD_voidSetCursor(5,1);
   operation_end=0;
   key_pressed=key_freed;
   while (operation_end==0)
   { 
   KEYPAD_FindKey(&key_pressed); 
  if(key_pressed == 0x0D)
  {
	  LCD_voidWriteCharacter(key_pressed+'0');
	  _delay_ms(200);
	  result= calculate_inputSIM(arr_sim);	  
	  lcd_voidSendNumber(&result);
	  _delay_ms(1000);
	  _delay_ms(200);
	  count_input_num=0;
	  key_pressed=key_freed;
	  operation_end=1;
	  LCD_voidClear();
  }
  else if (key_pressed!=key_freed)
  {
	  arr_sim[count_input_num++]=key_pressed;
	 LCD_voidWriteCharacter(key_pressed+'0');
	 _delay_ms(300);
	 key_pressed=key_freed;
	 KEYPAD_FindKey(&key_pressed);		  
  }
  else
  {
  }
 } 
 
   } 
}
