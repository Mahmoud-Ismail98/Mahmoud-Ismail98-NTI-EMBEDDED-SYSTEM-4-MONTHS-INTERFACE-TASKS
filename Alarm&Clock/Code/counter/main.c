/*
 * counter.c
 *
 * Created: 11/1/2023 7:20:48 PM
 * Author : HP
 */ 

 #define F_CPU 8000000UL
 
#include <util/delay.h>
#include "Bit_utils.h"
#include "Std_types.h"
#include "Gie.h"
#include "EXT.h"
#include "PORT.h"
#include "DIO.h"
#include "ADC.h"
#include "Timer.h"
#include "LCD.h"
#include "KEYPAD.h"


u16 GetNumericInput() {
    u8 Loc_u8key;
    u8 Loc_u8ArrNumStr[16] = "";
    u8 Loc_u8Idx = 0;
    u16 Loc_u8Num =0;
    while (1) {
        KEYPAD_tenuErorStatus status = KEYPAD_u8GetKeyState(&Loc_u8key);

        switch (status) {
            case KEYPAD_OK:
                if (Loc_u8key >= '0' && Loc_u8key <= '9') {
                    Loc_u8ArrNumStr[Loc_u8Idx] = Loc_u8key;
                    Loc_u8Idx++;
                    LCD_VOidSendChar(Loc_u8key);
                } else if (Loc_u8key == '=') {
                    Loc_u8ArrNumStr[Loc_u8Idx] = '\0';
                     Loc_u8Num = atoi(Loc_u8ArrNumStr);
                    return Loc_u8Num;
                }
                
                break;
            default:
                
                break;
        }
    }
}



void AlarmDisplay()
{
    u16 Loc_u16Counter=1;
    LCD_Goto_xy(LCD_ROW_0,LCD_COL_0);
    LCD_VoidSendString("Alarm");
    LCD_Goto_xy(LCD_ROW_1,LCD_COL_0);
    LCD_VoidSendString("Times in sc : ");
    LCD_Goto_xy(LCD_ROW_2,LCD_COL_0);
    u16 Loc_u16CountValue = GetNumericInput();
    Timer_voidInit();
    Timer0_SetCounter(Loc_u16CountValue);


    
    while(Loc_u16Counter!=0)
    {
        Timer0_GETCounter(&Loc_u16Counter);
        LCD_Goto_xy(LCD_ROW_3,LCD_COL_0);
        LCD_VoidSendInteger(Loc_u16Counter);
    }

   DIO_enuWriteChannel(DIO_CHANNEL_16,DIO_CHANNEL_HIGH);

    
}

void ClockDisplay() {
    u16 Loc_u16Counter = 0; // Initialize to 0
    LCD_Goto_xy(LCD_ROW_0, LCD_COL_0);
    LCD_VoidSendString("Clock");
    LCD_Goto_xy(LCD_ROW_1, LCD_COL_0);
    LCD_VoidSendString("HH:MM:SS ");
    LCD_Goto_xy(LCD_ROW_2, LCD_COL_0);
    Timer_voidInit();
    LCD_Goto_xy(LCD_ROW_3, LCD_COL_0);
    LCD_VoidSendString("00"); 
    LCD_VOidSendChar(':');
    LCD_VoidSendString("00");
    LCD_VOidSendChar(':');
    LCD_VoidSendString("00");
    while (1) { 
        Timer0_GETCounterUp(&Loc_u16Counter);
        LCD_Goto_xy(LCD_ROW_3, LCD_COL_0);
        LCD_VoidSendInteger(Loc_u16Counter / 3600); // Hours
        LCD_VOidSendChar(':');
        LCD_VoidSendInteger((Loc_u16Counter / 60) % 60); // Minutes
        LCD_Goto_xy(LCD_ROW_3, LCD_COL_5);
        LCD_VOidSendChar(':');
        LCD_VoidSendInteger(Loc_u16Counter % 60); // Seconds
    }
}


void ProgDisplay()
{
    
    LCD_Goto_xy(LCD_ROW_0,LCD_COL_0);
    LCD_VoidSendString("Choose Mode ");
    LCD_Goto_xy(LCD_ROW_1,LCD_COL_0);
    LCD_VoidSendString("1-Alarm");
    LCD_Goto_xy(LCD_ROW_2,LCD_COL_0);
    LCD_VoidSendString("2-Clock");
    LCD_Goto_xy(LCD_ROW_3,LCD_COL_0);
    u16 Loc_u16CountValue = GetNumericInput();
    if(Loc_u16CountValue == 1)
    {
        LCD_VoidClear();
        AlarmDisplay();
    }  
    else
    {
        LCD_VoidClear();
        ClockDisplay();
    }
    
}
int main(void)
{
    PORT_VoidInit();
    ADC_voidinit();
    LCD_VoidInit();
    LCD_VoidClear();
    
    GIE_globalInterruptEnable();
     ProgDisplay();

    while (1) 
    {
       
    }
}

