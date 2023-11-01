/*
 * test_PORT.c
 *
 * Created: 10/21/2023 2:19:27 PM
 * Author : FADY
 */ 
#include "SERVICES/Bit_utils.h"
#include "SERVICES/Std_types.h"

#include "MCAL/PORT/PORT.h"
#include "MCAL/DIO/DIO.h"
#include "HAL/LCD/LCD.h"
#include "HAL/ICUSW/ICUSW.h"
#include "HAL/KEYPAD/KEYPAD.h"
#include <stdlib.h>




  
    
   volatile u16 Loc_u16OnPeriod=0;
   volatile u32 Loc_u16TotalPeriod=0;
   volatile u8 Loc_u16OnDutyCycle=0;

int main() {
    GIE_globalInterruptEnable();
   PORT_VoidInit();
   LCD_VoidInit();
   ICUSW_voidEnableSWICU();


    while (1) {
        ICUSW_u8GetOnPeriod(&Loc_u16OnPeriod);
        ICUSW_u8GetTotalPeriod(&Loc_u16TotalPeriod);
        ICUSW_u8GetDutyCycle(&Loc_u16OnDutyCycle);
        LCD_Goto_xy(LCD_ROW_0,LCD_COL_0);
       LCD_VoidSendString("On Period");
       LCD_Goto_xy(LCD_ROW_0,LCD_COL_11);
       LCD_VoidSendNumbers(Loc_u16OnPeriod);
       LCD_Goto_xy(LCD_ROW_1,LCD_COL_0);
       LCD_VoidSendString("OFF Period");
       LCD_Goto_xy(LCD_ROW_1,LCD_COL_11);
       LCD_VoidSendNumbers(Loc_u16TotalPeriod-Loc_u16OnPeriod);

       LCD_Goto_xy(LCD_ROW_2,LCD_COL_0);
       LCD_VoidSendString("Duty Cycle");
       LCD_Goto_xy(LCD_ROW_2,LCD_COL_11);
       LCD_VoidSendNumbers(Loc_u16OnDutyCycle);
       
    }

    return 0;
}

