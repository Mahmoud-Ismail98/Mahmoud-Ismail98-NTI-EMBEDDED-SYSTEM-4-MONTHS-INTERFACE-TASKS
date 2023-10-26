#include "../../../services/Bit_utils.h"
#include "../../../services/Std_types.h"
#include "../../../MCAL/PORT/include/port.h"
#include "../../../MCAL/DIO/include/DIO.h"
#include "../../../MCAL/ADC/ADC.h"
#include <util/delay.h>
//  unsigned char Character1[8] = { 0x00, 0x0A, 0x15, 0x11, 0x0A, 0x04, 0x00, 0x00 };  /* Custom char set for alphanumeric LCD Module */
char customChar1[8] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x1F,
  0x1F
};	
char customChar2[8] = { 
0x00,
0x00,
0x00,
0x00,
0x1F,
0x1F,
0x1F,
0x1F};
char customChar3[8] = {
	0x00,
	0x00,
	0x1F,
	0x1F,
	0x1F,
	0x1F,
	0x1F,
	0x1F
};
char customChar4[8] = {
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F
};
u16 ADC_RAED=0;
int main(void)
{
	ADC_voidInit();
	LCD_voidInit(); 
	LCD_voidCustomChar(0, customChar1); 
	LCD_voidCustomChar(1, customChar2); 
    LCD_voidCustomChar(2, customChar3); 
	LCD_voidCustomChar(3, customChar4); 			  
	//LCD_voidCustomChar(1, customChar2); 	
	ADC_read(ADC_CH0,&ADC_RAED);
	LCD_voidSetCursor(0,1);
    LCD_voidWriteString("VOLUME");
	u16 last_read=0;
	while (1)
	{
	 ADC_read(ADC_CH0,&ADC_RAED);
	 if (last_read==ADC_RAED)
	 {
		
	 } 
	 else
	 {	 
		if(ADC_RAED>0)//&&ADC_RAED<300)
		{
			LCD_voidSetCursor(9,1);
			LCD_voidWriteCharacter(0); 	
			//LCD_voidWriteCharacter(0); 
			LCD_voidWriteString("   ");	
		}
		if(ADC_RAED>=300)//&&ADC_RAED<=600)
		{
			LCD_voidSetCursor(10,1);
			LCD_voidWriteCharacter(1); 	
			LCD_voidWriteString("  ");
		}
		if(ADC_RAED>=600)//&&ADC_RAED<900)
		{
			LCD_voidSetCursor(11,1);
			LCD_voidWriteCharacter(2); 	
			LCD_voidWriteString(" ");	
		}
		if(ADC_RAED>=900)//&&ADC_RAED<1024)
		{
			LCD_voidSetCursor(12,1);
			LCD_voidWriteCharacter(3); 	
		}
		last_read=ADC_RAED;				
	}

}
	}
