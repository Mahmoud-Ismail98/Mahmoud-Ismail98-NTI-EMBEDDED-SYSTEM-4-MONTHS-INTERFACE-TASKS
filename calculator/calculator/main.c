/*
 * test_PORT.c
 *
 * Created: 10/21/2023 2:19:27 PM
 * Author : FADY
 */ 
#include "Bit_utils.h"
#include "Std_types.h"

#include "PORT.h"
#include "DIO.h"
#include "LCD.h"
#include "KEYPAD.h"
#include <stdlib.h>

u8 Global_u8Operator;
const u8 Global_u8arrCustomCharCrossSign[8] = {
  0b00000,
  0b00000,
  0b10001,
  0b01010,
  0b00100,
  0b01010,
  0b10001,
  0b00000
};


u32 GetNumericInput() {
    u8 Loc_u8key;
    u8 Loc_u8ArrNumStr[16] = "";
    u8 Loc_u8Idx = 0;
    u32 Loc_u8Num =0;
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
                }else if (Loc_u8key == '+' || Loc_u8key == '-'  || Loc_u8key == '/') {
                    
                    LCD_VOidSendChar(Loc_u8key);
                    Global_u8Operator = Loc_u8key;
                    Loc_u8ArrNumStr[Loc_u8Idx] = '\0';
                     Loc_u8Num = atof(Loc_u8ArrNumStr);
                    return Loc_u8Num;
                } else if (Loc_u8key == '*' ) {
                    LCD_VOidSendChar(0);
                    Global_u8Operator = Loc_u8key;
                    Loc_u8ArrNumStr[Loc_u8Idx] = '\0';
                     Loc_u8Num = atof(Loc_u8ArrNumStr);
                    return Loc_u8Num;
                }
                else if (Loc_u8key == 'C') {
                    LCD_VoidClear();
                    Loc_u8Idx = 0;
                } 
                
                break;
            default:
                
                break;
        }
    }
}


int main() {
        PORT_VoidInit();
        LCD_VoidInit();
        LCD_VoidClear();
        LCD_VoidCreateSpectialChar(0,Global_u8arrCustomCharCrossSign);
        float Loc_f32Num1;
        float Loc_f32Num2; 
        float Loc_f32Result;

    while (1) {
        LCD_Goto_xy(LCD_ROW_0, LCD_COL_0);
         Loc_f32Num1 = GetNumericInput();
         Loc_f32Num2 = GetNumericInput();
        

        switch (Global_u8Operator) {
            case '+':
                Loc_f32Result = Loc_f32Num1 + Loc_f32Num2;
                break;
            case '-':
                Loc_f32Result = (Loc_f32Num1 - Loc_f32Num2);
                break;
            case '*':
                Loc_f32Result = Loc_f32Num1 * Loc_f32Num2;
                break;
            case '/':
                if (Loc_f32Num2 != 0) {
                    Loc_f32Result = Loc_f32Num1 / Loc_f32Num2;
                } else {
                    LCD_VoidClear();
                    LCD_Goto_xy(LCD_ROW_0, LCD_COL_0);
                    LCD_VoidSendString("Error: Division by 0");
                    continue;
                }
                break;
            default:
                LCD_VoidClear();
                LCD_Goto_xy(LCD_ROW_0, LCD_COL_0);
                LCD_VoidSendString("Error: Invalid Global_u8Operator");
                continue;
        }

        LCD_Goto_xy(LCD_ROW_3, LCD_COL_14);
        
        LCD_VoidSendNumbers(Loc_f32Result);
    }

    return 0;
}
