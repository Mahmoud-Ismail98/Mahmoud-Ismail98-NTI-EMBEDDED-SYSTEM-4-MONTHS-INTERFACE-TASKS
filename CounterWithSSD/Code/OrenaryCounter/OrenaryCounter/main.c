/*
 * OrenaryCounter.c
 *
 * Created: 11/2/2023 9:08:00 AM
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
#include "SSDISPLAY.h"
volatile u8 x_temp = 1;
volatile u8 y_temp = 0;
volatile u8 i_temp = 1;
volatile u8 j_temp = 1;
volatile u8 Glo_u8Flag=0;

void Counter_StartButton()
{
        Glo_u8Flag = 1;
}
void Counter_StopButton()
{
        Glo_u8Flag = 0;
}
void Counter_RestartButton()
{
     Glo_u8Flag = 3;
    x_temp = 1;
    y_temp = 0;
    i_temp = 1;
    j_temp = 1;   
}

void SSDISPLAY_App() {
    for (u8 i = i_temp; i_temp <= 9 ; ) {
        for (u8 j = j_temp; j_temp <= 9; ) {
            for (u8 x = x_temp; x_temp <= 9 ; ) {
                for (u8 y = y_temp; y_temp <= 9 ; ) {
                    if (Glo_u8Flag == 1) {
                        y = y_temp++;
                        SSDISPLAY_enuWriteNumber(y, 1);
                        _delay_ms(50);
                    }
                    else if(Glo_u8Flag == 0) {
                        y_temp =y;
                    }
                    else if(Glo_u8Flag == 3)
                    {

                        SSDISPLAY_enuWriteNumber(0, 1);
                        SSDISPLAY_enuWriteNumber(0, 2);
                        SSDISPLAY_enuWriteNumber(0, 3);
                        SSDISPLAY_enuWriteNumber(0, 4);
                        return;
                    }
                }
                if (Glo_u8Flag == 1) {
                    x = x_temp++;
                    y_temp=0;
                    SSDISPLAY_enuWriteNumber(0, 1);
                    SSDISPLAY_enuWriteNumber(x, 2);
                    _delay_ms(50);
                }
                else if(Glo_u8Flag == 0)
                {
                    x_temp =x;
                }
                else if(Glo_u8Flag == 3) 
                {
                    SSDISPLAY_enuWriteNumber(0, 1);
                    SSDISPLAY_enuWriteNumber(0, 2);
                    SSDISPLAY_enuWriteNumber(0, 3);
                    SSDISPLAY_enuWriteNumber(0, 4);
                 
                    return;
                }
            }

            if (Glo_u8Flag == 1) {
                j = j_temp++;
                x_temp=0;
                SSDISPLAY_enuWriteNumber(0, 2);
                SSDISPLAY_enuWriteNumber(j, 3);
                _delay_ms(50);
            }
            else if(Glo_u8Flag == 0) 
            {
                j_temp =j;
            }
            else if(Glo_u8Flag == 3)
            {
                 SSDISPLAY_enuWriteNumber(0, 1);
                 SSDISPLAY_enuWriteNumber(0, 2);
                 SSDISPLAY_enuWriteNumber(0, 3);
                 SSDISPLAY_enuWriteNumber(0, 4);

                 return;
            }
        }

        if (Glo_u8Flag == 1) {
            i = i_temp++;
            j_temp=0;
            SSDISPLAY_enuWriteNumber(0, 3);
            SSDISPLAY_enuWriteNumber(i, 4);
            _delay_ms(50);
        }
        else if(Glo_u8Flag == 0) 
        {
            i_temp =i;
        }
        else if(Glo_u8Flag == 3)
        {
            SSDISPLAY_enuWriteNumber(0, 1);
            SSDISPLAY_enuWriteNumber(0, 2);
            SSDISPLAY_enuWriteNumber(0, 3);
            SSDISPLAY_enuWriteNumber(0, 4);

            return;
        }
    }
}

int main(void)
{
    PORT_VoidInit();
    GIE_globalInterruptEnable();
    EXT_InterruptPirefralEnable(EXT_0,EXT_RISING_EDGE);
    EXT_InterruptPirefralEnable(EXT_1,EXT_RISING_EDGE);
    EXT_InterruptPirefralEnable(EXT_2,EXT_RISING_EDGE);
    EXTINT_voidSetCallBack(Counter_StartButton,EXT_0);
    EXTINT_voidSetCallBack(Counter_StopButton,EXT_1);
    EXTINT_voidSetCallBack(Counter_RestartButton,EXT_2);
    while (1) 
    {
        SSDISPLAY_App();
    }
}

