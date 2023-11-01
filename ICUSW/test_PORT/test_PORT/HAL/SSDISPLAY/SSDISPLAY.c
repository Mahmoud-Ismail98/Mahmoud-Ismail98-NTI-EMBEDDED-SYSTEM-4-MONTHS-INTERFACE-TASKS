/*
 * SSDISPLAY.c
 *
 * Created: 10/25/2023 6:29:51 PM
 *  Author: HP
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>

#include "../../SERVICES/Std_types.h"
#include "../../SERVICES/Bit_utils.h"
#include "../../MCAL/DIO/DIO.h"
#include "SSDISPLAY.h"
#include "SSDISPLAY_prv.h"
#include "SSDISPLAY_cfg.h"


SSDISPLAY_tenuErrorStatus SSDISPLAY_tenuWriteNumber(u8 Copy_u8Number) {
    SSDISPLAY_tenuErrorStatus Loc_tenuStatus = SSDISPLAY_OK;
    if((Copy_u8Number<0)&&(Copy_u8Number>10000)&&(Copy_u8Number>9))
    {
        Loc_tenuStatus = SSDISPLAY_WRONGNUMBER;
    }
    else{
        DIO_enuWriteChannel(SSDISPLAY_BCD_0, GET_BIT(Copy_u8Number, 0));
        DIO_enuWriteChannel(SSDISPLAY_BCD_1, GET_BIT(Copy_u8Number, 1));
        DIO_enuWriteChannel(SSDISPLAY_BCD_2, GET_BIT(Copy_u8Number, 2));
        DIO_enuWriteChannel(SSDISPLAY_BCD_3,GET_BIT(Copy_u8Number, 3));
   
    }
    return Loc_tenuStatus;
}

void SSDISPLAY_VoidWriteNumberInSpecificSegmant(u16 Copy_u16Number) {
  u8 Loc_u8Index = 0;
    
    // Array to store the segments to choose from 
    u8 Loc_u8ArrSegments[] = {SSDISPLAY_COM_0, SSDISPLAY_COM_1, SSDISPLAY_COM_2, SSDISPLAY_COM_3};
    
    while ((Copy_u16Number > 0) || (Loc_u8Index <= 3)) {
        DIO_enuWriteChannel(Loc_u8ArrSegments[Loc_u8Index], SSDISPLAY_PIN_LOW);
       
       
        SSDISPLAY_tenuWriteNumber((u8)(Copy_u16Number % 10));
        
      
		 DIO_enuWriteChannel(Loc_u8ArrSegments[Loc_u8Index], SSDISPLAY_PIN_HIGH);
    
        Loc_u8Index++;
        Copy_u16Number /= 10;
    }


}


