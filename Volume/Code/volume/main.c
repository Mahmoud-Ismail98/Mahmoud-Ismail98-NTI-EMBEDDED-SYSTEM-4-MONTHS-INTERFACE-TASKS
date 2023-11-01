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
#include "PORT.h"
#include "DIO.h"
#include "ADC.h"
#include "LCD.h"


u8 ADC_Level_1[8] ={
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b00000
	};


u8 ADC_Level_2[8] ={
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111,
  0b00000
};

u8 ADC_Level_3[8] ={
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111,
  0b11111,
  0b00000
};

u8 ADC_Level_4[8] ={
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b00000
};
u8 ADC_Muted[8] ={
  0b00000,
  0b00000,
  0b11001,
  0b10110,
  0b10110,
  0b11001,
  0b00000,
  0b00000
};

void VolumeDisply(void)
{
    u32 Loc_u8Volume=0,Loc_u8ADCValue=0;
    ADC_voidGetADCValue(&Loc_u8ADCValue);
    //ADC_StartConverstion(7,&Loc_u8ADCValue);
    Loc_u8Volume = (5000*Loc_u8ADCValue)/1024;


       if(Loc_u8Volume==0)
    {
        
        LCD_Goto_xy(LCD_ROW_1,LCD_COL_10);
        LCD_VOidSendChar(4);

    }
    else if(Loc_u8Volume<=1000)
    {
        
        LCD_Goto_xy(LCD_ROW_1,LCD_COL_10);
        LCD_VOidSendChar(0);
        LCD_Goto_xy(LCD_ROW_1,LCD_COL_11);
        LCD_VOidSendChar(' ');
        LCD_Goto_xy(LCD_ROW_1,LCD_COL_12);
        LCD_VOidSendChar(' ');
        LCD_Goto_xy(LCD_ROW_1,LCD_COL_13);
        LCD_VOidSendChar(' ');
    }
    else if((Loc_u8Volume>1000)&&(Loc_u8Volume<=2000))
    {
        LCD_Goto_xy(LCD_ROW_1,LCD_COL_10);
        LCD_VOidSendChar(0);
        LCD_Goto_xy(LCD_ROW_1,LCD_COL_11);
        LCD_VOidSendChar(1);
        LCD_Goto_xy(LCD_ROW_1,LCD_COL_12);
        LCD_VOidSendChar(' ');
        LCD_Goto_xy(LCD_ROW_1,LCD_COL_13);
        LCD_VOidSendChar(' ');
    }
    else if((Loc_u8Volume>2000)&&(Loc_u8Volume<=3000))
    {
        LCD_Goto_xy(LCD_ROW_1,LCD_COL_10);
        LCD_VOidSendChar(0);
        LCD_Goto_xy(LCD_ROW_1,LCD_COL_11);
        LCD_VOidSendChar(1);
        LCD_Goto_xy(LCD_ROW_1,LCD_COL_12);
        LCD_VOidSendChar(2);
        LCD_Goto_xy(LCD_ROW_1,LCD_COL_13);
        LCD_VOidSendChar(' ');
     
    }
    else if((Loc_u8Volume>3000)&&(Loc_u8Volume<=5000))
    {
        LCD_Goto_xy(LCD_ROW_1,LCD_COL_10);
        LCD_VOidSendChar(0);
        LCD_Goto_xy(LCD_ROW_1,LCD_COL_11);
        LCD_VOidSendChar(1);
        LCD_Goto_xy(LCD_ROW_1,LCD_COL_12);
        LCD_VOidSendChar(2);
        LCD_Goto_xy(LCD_ROW_1,LCD_COL_13);
        LCD_VOidSendChar(3);
    }
    else
    {
        LCD_Goto_xy(LCD_ROW_1,LCD_COL_14);
        LCD_VOidSendChar(4);
    }
}

int main(void)
{
   
    
    
    PORT_VoidInit();
    ADC_voidinit();
    LCD_VoidInit();
    LCD_VoidClear();
    GIE_globalInterruptEnable();
    ADC_AaynchStartConversion(7);
    
    LCD_VoidCreateSpectialChar(0,ADC_Level_1);
    LCD_VoidCreateSpectialChar(1,ADC_Level_2);
    LCD_VoidCreateSpectialChar(2,ADC_Level_3);
    LCD_VoidCreateSpectialChar(3,ADC_Level_4);
    LCD_VoidCreateSpectialChar(4,ADC_Muted);
    LCD_Goto_xy(LCD_ROW_0,LCD_COL_0);
    LCD_VoidSendString("Volume");
    while (1) 
    {
        VolumeDisply();
    }
}

