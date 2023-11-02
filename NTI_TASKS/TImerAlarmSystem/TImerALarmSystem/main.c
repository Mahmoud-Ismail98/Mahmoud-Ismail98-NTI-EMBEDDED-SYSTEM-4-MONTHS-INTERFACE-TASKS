
#include <avr/io.h>
#include <util/delay.h>

#include "Port.h"
#include "Dio.h"
#include "Timer.h"
#include "GI_Int.h"
#include "LCD_interface.h"
#include "KEYPAD.h"

int8_t second = 0, minut = 0, hour = 0;

u8 KEY_Value ; 
u8 KEY   ;
s8 Value ; 

s8 Val = 0;
void Timer_Alarm_System (void);

int main(void)
{
    Port_vidInit() ; 
	LCD_vidInit() ;
    TIMER0_u8SetCallBack(&Timer_Alarm_System);

	second = 0;
	minut = 0;
	hour = 0;
	LCD_voidGotToXY(0,4) ; 
	LCD_vidWriteString(" 1.CLOCK") ; 
	
	LCD_voidGotToXY(1,4) ;
	LCD_vidWriteString(" 2.ALARM") ;
	
	_delay_ms(30000) ; 
	LCD_CLEAR() ; 
	
	

GIE_voidEnableGlobalInterrupt() ;
	
	
	 do
	 {
		 KEY_Value = GET_KEY_PRESSED() ;
		 
	 }while(KEY_Value == NOT_PRESSED) ;
	 LCD_vidWriteCharctr(KEY_Value) ;
	 Val = KEY_Value - '0';
	 
	 LCD_voidGotToXY(0,2);
	 LCD_vidWriteCharctr(KEY_Value);
	 TIMER0_Init();
	 
	while (1)
	 {
		 
		    switch (KEY_Value)
			{
				
			
			case '1' : 
			LCD_vidWriteString("CLOCK"); 
			_delay_ms(20000) ; 
			LCD_CLEAR() ; 
				while (1) {
					// Display the time
					LCD_vidSendCommand(0x82);
					LCD_vidWriteCharctr(':');
					LCD_vidSendCommand(0x85);
					LCD_vidWriteCharctr(':');
					
					// Display hour
					LCD_vidSendCommand(0x80);
					LCD_vidWriteCharctr(hour / 10 + '0');
					LCD_vidSendCommand(0x81);
					LCD_vidWriteCharctr(hour % 10 + '0');
					
					// Display minutes
					LCD_vidSendCommand(0x83);
					LCD_vidWriteCharctr(minut / 10 + '0');
					LCD_vidSendCommand(0x84);
					LCD_vidWriteCharctr(minut % 10 + '0');
					
					// Display seconds
					LCD_vidSendCommand(0x86);
					LCD_vidWriteCharctr(second / 10 + '0');
					LCD_vidSendCommand(0x87);
					LCD_vidWriteCharctr(second % 10 + '0');
					
					// Delay for one second
					_delay_ms(1000);
					
					// Increment the second
					second++;
					
					if (second == 60) {
						second = 0;
						minut++;
						
						if (minut == 60) {
							minut = 0;
							hour++;
							
							if (hour == 24) {
								hour = 0;
							}
						}
					}
				}
				break ; 
			
			case '2' : 
			
			LCD_vidWriteString("ALARM") ; 
			_delay_ms(20000) ; 
			LCD_CLEAR() ; 
		   
			do 
			{
			KEY = GET_KEY_PRESSED() ;
			
		   }while(KEY == NOT_PRESSED) ;
		Value = KEY - '0';
		
		LCD_voidGotToXY(0,2);
		LCD_vidWriteCharctr(KEY);
		
		
			
			}
			
		
			}
	 }


void Timer_Alarm_System (void)
{
	static u16 Static_Counter  = 0 ;
	 Static_Counter ++ ; 
	 if (Static_Counter == 62*Value)
	 {
		Dio_enuWriteChannel(DIO_u8CHANNEL03, DIO_u8LEVEL_HIGH);
	    LCD_vidWriteString(" ALARM_ON");	
		Static_Counter = 0 ;
		 
	 }
}
