#include "../../../services/Bit_utils.h"
#include "../../../services/Std_types.h"
#include "../../../MCAL/PORT/include/port.h"
#include "../../../MCAL/DIO/include/DIO.h"
#include "../../../MCAL/PORT/include/port_private.h"
//#include "../../MCAL/DIO/include/DIO_cfg.h"
//#include "../../../MCAL/DIO/include/DIO_private.h"

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

void T0delayms(u16 n){
	LCD_voidWriteString("ALARM");
	for(s8 i = n; i >= 0; i--){
			LCD_voidSetCursor(10,0);
			lcd_voidSendNumber(&i);
			LCD_voidWriteCharacter(' ');			
			T0delayOnems();
		}		
	}

u8 calculate_inputSIM(u16 arr[])
{
	u16 operend1=0;
	u16 operend2=0;
	u16 logic_operation_result;
	for (u8 y=0;y<count_input_num;y++)
	{
		operend1+=arr[y]*pow(10,(count_input_num-(y+1)));
	}

	logic_operation_result=operend1+operend2;
			
	return logic_operation_result;
}

int main(void)
{
	Port_setPinDirection(PORTC_PIN4,PIN_OUTPUT);
   LCD_voidInit();
   KEYPAD_voidInit();
	LCD_voidWriteString("set alarm value ");
//	LCD_voidSetCursor(5,1);    
//while(1){ 
   operation_end=0;
   key_pressed=key_freed;
   while (operation_end==0)
{ 
KEYPAD_FindKey(&key_pressed); 
if(key_pressed == 0x0D)
  {
	  result= calculate_inputSIM(arr_sim);	  
	  lcd_voidSendNumber(&result);
	  count_input_num=0;
	  key_pressed=key_freed;
	  operation_end=1;
	  LCD_voidClear();
	  T0delayms(result);
		//DIO_WritrPin(PORTB_PIN4,HIGH_LEVEL);
		TGL_REG(PORTB,4);
		_delay_ms(300);	  
	  LCD_voidClear();	  
	  //TGL_REG(PORTB,4);
	//  DIO_WritrPin(PORTB_PIN4,HIGH_LEVEL);
	  _delay_ms(1000);

  }
  else if (key_pressed!=key_freed)
  {
	  arr_sim[count_input_num++]=key_pressed;
	 LCD_voidWriteCharacter(key_pressed+'0');
	 _delay_ms(400);
	 key_pressed=key_freed;
	 KEYPAD_FindKey(&key_pressed);		  
  }

 } 
 

}
