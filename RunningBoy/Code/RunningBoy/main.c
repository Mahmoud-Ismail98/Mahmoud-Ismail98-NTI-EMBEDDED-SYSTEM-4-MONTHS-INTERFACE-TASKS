/*
 * test_PORT.c
 *
 * Created: 10/21/2023 2:19:27 PM
 * Author : FADY
 */ 
 #define F_CPU 8000000UL
 #include <util/delay.h>
#include "Bit_utils.h"
#include "Std_types.h"

#include "PORT.h"
#include "DIO.h"
#include "LCD.h"
#include "KEYPAD.h"
#include <stdlib.h>

u8 LCD_BOY[8] ={
  0b00100,
  0b01010,
  0b00100,
  0b11111,
  0b00100,
  0b01110,
  0b10001,
  0b00000
	};


u8 LCD_Ground[8] ={
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111
};

u8 LCD_Ladder[8] ={
  0b00000,
  0b00000,
  0b00000,
  0b00001,
  0b00010,
  0b00100,
  0b01000,
  0b10000
};

u8 LCD_obsticale[8] ={
  0b00000,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100
};

  void Runningboy_Init()
  {
    u8 Loc_u8ROW=0;
    u8 Loc_u8COL=0;
    
    for(Loc_u8ROW=0;Loc_u8ROW<4;Loc_u8ROW++){  
        for(Loc_u8COL=0;Loc_u8COL<20;Loc_u8COL++){
        
             switch(Loc_u8ROW)
             {
                case 0:
                if(Loc_u8COL==0)
                {
                    LCD_Goto_xy(LCD_ROW_0, Loc_u8COL);
                    LCD_VOidSendChar(0); 
                }
                else
                {
                LCD_Goto_xy(LCD_ROW_0, Loc_u8COL);
                LCD_VOidSendChar(1);
                
                }
                break ;
                case 1:
                LCD_Goto_xy(LCD_ROW_1, Loc_u8COL);
                LCD_VOidSendChar(1);
                
                break;
                case 2:
                LCD_Goto_xy(LCD_ROW_2, Loc_u8COL);
                LCD_VOidSendChar(1);
                
                break;
                case 3:
                LCD_Goto_xy(LCD_ROW_3, Loc_u8COL);
                LCD_VOidSendChar(1);
                
                break;
                default :
                break;
             } 
        
        }    
        
    }
  }

void Runningboy_First()
  {
    u8 Loc_u8ROW=0;
    u8 Loc_u8COL=0;
    
    for(Loc_u8ROW=0;Loc_u8ROW<4;Loc_u8ROW++){  
        for(Loc_u8COL=0;Loc_u8COL<20;Loc_u8COL++){
        
             switch(Loc_u8ROW)
             {
                case 0:
                LCD_Goto_xy(LCD_ROW_0, Loc_u8COL-1);
                LCD_VOidSendChar(1);               
                LCD_Goto_xy(LCD_ROW_0, Loc_u8COL);
                LCD_VOidSendChar(0);
                LCD_Goto_xy(LCD_ROW_0, Loc_u8COL+1);
                LCD_VOidSendChar(1); 
                if(Loc_u8COL==19)
                {
                LCD_Goto_xy(LCD_ROW_0, 19);
                LCD_VOidSendChar(0);

                }
                else
                {

                }

                _delay_ms(50);
                break ;
                case 1:
                LCD_Goto_xy(LCD_ROW_0,19);
                LCD_VOidSendChar(1); 
                LCD_Goto_xy(LCD_ROW_1, Loc_u8COL-1);
                LCD_VOidSendChar(1);               
                LCD_Goto_xy(LCD_ROW_1, Loc_u8COL);
                LCD_VOidSendChar(0); 
                LCD_Goto_xy(LCD_ROW_1, Loc_u8COL+1);
                LCD_VOidSendChar(1);
                if(Loc_u8COL==19)
                {
                LCD_Goto_xy(LCD_ROW_1, 19);
                LCD_VOidSendChar(0);

                }
                else
                {

                }
                _delay_ms(50);
                break;
                case 2:
                LCD_Goto_xy(LCD_ROW_1,19);
                LCD_VOidSendChar(1); 
                LCD_Goto_xy(LCD_ROW_2, Loc_u8COL-1);
                LCD_VOidSendChar(1);               
                LCD_Goto_xy(LCD_ROW_2, Loc_u8COL);
                LCD_VOidSendChar(0); 
                LCD_Goto_xy(LCD_ROW_2, Loc_u8COL+1);
                LCD_VOidSendChar(1);
                 if(Loc_u8COL==19)
                {
                LCD_Goto_xy(LCD_ROW_2, 19);
                LCD_VOidSendChar(0);

                }
                else
                {

                } 
                _delay_ms(50);              
                break;
                case 3:
                LCD_Goto_xy(LCD_ROW_2,19);
                LCD_VOidSendChar(1); 
                LCD_Goto_xy(LCD_ROW_3, Loc_u8COL-1);
                LCD_VOidSendChar(1);               
                LCD_Goto_xy(LCD_ROW_3, Loc_u8COL);
                LCD_VOidSendChar(0); 
                LCD_Goto_xy(LCD_ROW_3, Loc_u8COL+1);
                LCD_VOidSendChar(1);
                if(Loc_u8COL==19)
                {
                LCD_Goto_xy(LCD_ROW_3, 19);
                LCD_VOidSendChar(0);
                LCD_Goto_xy(LCD_ROW_3,19);
                LCD_VOidSendChar(1); 
                }
                else
                {

                }
                _delay_ms(50);
                break;
                default :
                break;
             } 
        
        }    
        
    }
    LCD_Goto_xy(LCD_ROW_3, 19);
    LCD_VOidSendChar(0); 
    _delay_ms(50);
    LCD_Goto_xy(LCD_ROW_3, 19);
    LCD_VOidSendChar(1);
  }
void Runningboy_Second()
  {
    LCD_Goto_xy(LCD_ROW_0,13);
    LCD_VOidSendChar(' ');
   
    u8 Loc_u8COL=0;
        for(Loc_u8COL=0;Loc_u8COL<20;Loc_u8COL++){
                if(Loc_u8COL<13)
                {
                LCD_Goto_xy(LCD_ROW_0, Loc_u8COL-1);
                LCD_VOidSendChar(1);               
                LCD_Goto_xy(LCD_ROW_0, Loc_u8COL);
                LCD_VOidSendChar(0);
                if(Loc_u8COL!=12)
                {
                    LCD_Goto_xy(LCD_ROW_0, Loc_u8COL+1);
                    LCD_VOidSendChar(1); 
                }

                _delay_ms(50);                    
                }  
                else if(Loc_u8COL==13)
                {
                LCD_Goto_xy(LCD_ROW_0, 12);
                LCD_VOidSendChar(1); 
                LCD_Goto_xy(LCD_ROW_0, 13);
                LCD_VOidSendChar(0);
                _delay_ms(50); 
                LCD_Goto_xy(LCD_ROW_0,13);
                LCD_VOidSendChar(' ');
                _delay_ms(50);
                LCD_Goto_xy(LCD_ROW_1, 13);
                LCD_VOidSendChar(0);               
                _delay_ms(50);
                
                }
                else
                {
   
                LCD_Goto_xy(LCD_ROW_1, Loc_u8COL-2);
                LCD_VOidSendChar(1);               
                LCD_Goto_xy(LCD_ROW_1, Loc_u8COL-1);
                LCD_VOidSendChar(0); 
                LCD_Goto_xy(LCD_ROW_1, Loc_u8COL);
                LCD_VOidSendChar(1);   
                _delay_ms(50);

                }

             } 
    LCD_Goto_xy(LCD_ROW_1, 18);
    LCD_VOidSendChar(0); 
    LCD_Goto_xy(LCD_ROW_1, 18);
    LCD_VOidSendChar(1);
    LCD_Goto_xy(LCD_ROW_1, 19);
    LCD_VOidSendChar(0); 
    LCD_Goto_xy(LCD_ROW_1, 19);
    LCD_VOidSendChar(1); 

  
  }

void Runningboy_Third()
{
    LCD_Goto_xy(LCD_ROW_1,13);
    LCD_VOidSendChar(2);
    LCD_Goto_xy(LCD_ROW_0,13);
    LCD_VOidSendChar(' ');
    
    u8 Loc_u8COL=0;
        for(Loc_u8COL=0;Loc_u8COL<20;Loc_u8COL++){
                if(Loc_u8COL<13)
                {
                LCD_Goto_xy(LCD_ROW_1, Loc_u8COL-1);
                LCD_VOidSendChar(1);               
                LCD_Goto_xy(LCD_ROW_1, Loc_u8COL);
                LCD_VOidSendChar(0);
                if(Loc_u8COL!=12)
                {
                    LCD_Goto_xy(LCD_ROW_1, Loc_u8COL+1);
                    LCD_VOidSendChar(1); 
                }

                _delay_ms(50);                    
                }  
                else if(Loc_u8COL==13)
                {
                LCD_Goto_xy(LCD_ROW_1, 12);
                LCD_VOidSendChar(1); 
                LCD_Goto_xy(LCD_ROW_1, 13);
                LCD_VOidSendChar(0);
                _delay_ms(50); 
                LCD_Goto_xy(LCD_ROW_1,13);
                LCD_VOidSendChar(2);
                _delay_ms(50);
                LCD_Goto_xy(LCD_ROW_0,13);
                LCD_VOidSendChar(' ');
                _delay_ms(50);
                LCD_Goto_xy(LCD_ROW_0, 13);
                LCD_VOidSendChar(0);               
                _delay_ms(50);
                
                }
                else
                {
                LCD_Goto_xy(LCD_ROW_0,13);
                LCD_VOidSendChar(' ');
                LCD_Goto_xy(LCD_ROW_0, Loc_u8COL-2);
                LCD_VOidSendChar(1);               
                LCD_Goto_xy(LCD_ROW_0, Loc_u8COL-1);
                LCD_VOidSendChar(0); 
                LCD_Goto_xy(LCD_ROW_0, Loc_u8COL);
                LCD_VOidSendChar(1);   
                _delay_ms(50);

                }

             } 

    LCD_Goto_xy(LCD_ROW_0, 18);
    LCD_VOidSendChar(0); 
    LCD_Goto_xy(LCD_ROW_0, 18);
    LCD_VOidSendChar(1);
    LCD_Goto_xy(LCD_ROW_0, 19);
    LCD_VOidSendChar(0); 
    LCD_Goto_xy(LCD_ROW_0, 19);
    LCD_VOidSendChar(1); 
}


void Runningboy_Fourth()
  {
    LCD_Goto_xy(LCD_ROW_1,13);
    LCD_VOidSendChar(1);
    LCD_Goto_xy(LCD_ROW_0,13);
    LCD_VOidSendChar(1);
    LCD_Goto_xy(LCD_ROW_1,10);
    LCD_VOidSendChar(3);
    u8 Loc_u8ROW=0;
    u8 Loc_u8COL=0;
    
    for(Loc_u8ROW=0;Loc_u8ROW<=1;Loc_u8ROW++){  
        for(Loc_u8COL=0;Loc_u8COL<20;Loc_u8COL++){
        
             switch(Loc_u8ROW)
             {
                case 0:
                LCD_Goto_xy(LCD_ROW_0, Loc_u8COL-1);
                LCD_VOidSendChar(1);               
                LCD_Goto_xy(LCD_ROW_0, Loc_u8COL);
                LCD_VOidSendChar(0);
                LCD_Goto_xy(LCD_ROW_0, Loc_u8COL+1);
                LCD_VOidSendChar(1); 
                if(Loc_u8COL==19)
                {
                LCD_Goto_xy(LCD_ROW_0, 19);
                LCD_VOidSendChar(0);

                }
                else
                {

                }

                _delay_ms(50);
                break ;
                case 1:

                if(Loc_u8COL<10)
                {
                LCD_Goto_xy(LCD_ROW_0,19);
                LCD_VOidSendChar(1); 
                LCD_Goto_xy(LCD_ROW_1, Loc_u8COL-1);
                LCD_VOidSendChar(1);               
                LCD_Goto_xy(LCD_ROW_1, Loc_u8COL);
                LCD_VOidSendChar(0); 
                LCD_Goto_xy(LCD_ROW_1, Loc_u8COL+1);
                LCD_VOidSendChar(1);
                 _delay_ms(50);
                }
                else
                {
                    break;
                }
                
                break;
                
                default :
                break;
             } 
        
        }    
        
    }
    LCD_Goto_xy(LCD_ROW_1,6);
    LCD_VoidSendString("GAME OVER");
    LCD_Goto_xy(LCD_ROW_1,19);
    LCD_VOidSendChar(1);
    _delay_ms(50);
  }
int main() {
        PORT_VoidInit();
        LCD_VoidInit();
        LCD_VoidClear();
        LCD_VoidCreateSpectialChar(0,LCD_BOY);
        LCD_VoidCreateSpectialChar(1,LCD_Ground);
        LCD_VoidCreateSpectialChar(2,LCD_Ladder);
        LCD_VoidCreateSpectialChar(3,LCD_obsticale);
        Runningboy_Init();
        Runningboy_First();
        Runningboy_Second();
        Runningboy_Third();
        Runningboy_Fourth();
    while (1) {

    }

    return 0;
}
