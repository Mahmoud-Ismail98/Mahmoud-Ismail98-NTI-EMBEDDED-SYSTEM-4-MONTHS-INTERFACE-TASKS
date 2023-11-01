/*
 * volume.c
 *
 * Created: 11/1/2023 4:21:22 PM
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
#include "LCD.h"
#include "KEYPAD.h"
volatile u8 glo_u8Flag = 0;
void Volt_voidISR()
{
        glo_u8Flag ^= 1;
}
void VoltageDisplay(void) {
    float Loc_f32Voltage = 0;
    u32 Loc_u32ADCValue = 0;
    u8 Loc_u8Choose = 0;
    u8 Loc_u8Flag = 0;

    // Read ADC value
    ADC_voidGetADCValue(&Loc_u32ADCValue);

    if (glo_u8Flag == 1) {
        // Display in millivolts
        Loc_f32Voltage = (5000 * Loc_u32ADCValue) / 1023;
        LCD_Goto_xy(LCD_ROW_0, LCD_COL_10);
        LCD_VoidSendNumbers(Loc_f32Voltage);
        LCD_VoidSendString("mV");
    } else {
        // Display in volts
        Loc_f32Voltage = (5000 * Loc_u32ADCValue) / 1023;
        LCD_Goto_xy(LCD_ROW_0, LCD_COL_10);
        LCD_VoidSendNumbers(Loc_f32Voltage/1000);
        LCD_VoidSendString("V      ");
    }

}


int main(void)
{
   
    
    
    PORT_VoidInit();
    ADC_voidinit();
    LCD_VoidInit();
    LCD_VoidClear();
    
    GIE_globalInterruptEnable();
    EXT_InterruptPirefralEnable(EXT_0,EXT_RISING_EDGE);
    EXTINT_voidSetCallBack(Volt_voidISR,0);
    ADC_AaynchStartConversion(7);
    

    LCD_Goto_xy(LCD_ROW_0,LCD_COL_0);
    LCD_VoidSendString("Volte : ");
    while (1) 
    {
        VoltageDisplay();
    }
}

