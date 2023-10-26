/*
 * ADCProjectOne.c
 *
 * Created: 10/25/2023 12:46:44 PM
 * Author : 20101
 */ 

#include <avr/io.h>
#include "Std_types.h"
#include "Bit_utils.h"



#include "Port.h"
#include "Dio.h"
#include "LCD_interface.h"
#include "ADC.h"
#include "GI_Int.h"
#include "EXTI.h"

void EXTI_SWITCH(void);
void ADCNotifcation(void);
u8 switchFlag =1  ; 

u8 ADC_READING =0  ; 
u8 ADC_Reading_synchoronus ; 
int main(void)
{
	
	Port_vidInit(); 
	LCD_vidInit();
	ADC_voidInit();
    GIE_voidEnableGlobalInterrupt();
    ExtI_voidInitialize();
    ExtI_voidSetCallBack(&EXTI_SWITCH);
   //LCD_displayInteger(ADC_Reading_synchoronus);
    while (1) 
    {
       	ADC_u8StartConversionSynchoronus(1,  &ADC_Reading_synchoronus);
		
		if (  switchFlag == 1 )
		{
			LCD_voidGotToXY(0,0);
			LCD_displayInteger(ADC_Reading_synchoronus);
		    LCD_vidWriteString("VOLT  "); 
		}
		else 
		{
			LCD_voidGotToXY(0,0);
          LCD_displayInteger(ADC_Reading_synchoronus * 1000);
          LCD_vidWriteString("Milli_VOLT") ;
		}
		
		
    }
}

void EXTI_SWITCH(void)
 {
  switchFlag ^= 1 ; 
 }
