/*
 * SSDISPLAY.c
 *
 * Created: 10/25/2023 6:29:51 PM
 *  Author: HP
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>

#include "Std_types.h"
#include "Bit_utils.h"
#include "DIO.h"
#include "SSDISPLAY.h"
#include "SSDISPLAY_prv.h"
#include "SSDISPLAY_cfg.h"


SSDISPLAY_enuErrorStatus SSDISPLAY_enuWriteNumber(u8 Copy_u8Number,u8 Copy_u8Seg) {
    SSDISPLAY_enuErrorStatus Loc_tenuStatus = SSDISPLAY_OK;
    if((Copy_u8Number<0)||(Copy_u8Number>9))
    {
        Loc_tenuStatus = SSDISPLAY_WRONGNUMBER;
    }
    else{
        switch(Copy_u8Seg)
        {
            case 1:
                DIO_enuWriteChannel(SSDISPLAY_BCD_10, GET_BIT(Copy_u8Number, 0));
                DIO_enuWriteChannel(SSDISPLAY_BCD_11, GET_BIT(Copy_u8Number, 1));
                DIO_enuWriteChannel(SSDISPLAY_BCD_12, GET_BIT(Copy_u8Number, 2));
                DIO_enuWriteChannel(SSDISPLAY_BCD_13, GET_BIT(Copy_u8Number, 3));

            break;
            case 2:
                DIO_enuWriteChannel(SSDISPLAY_BCD_20, GET_BIT(Copy_u8Number, 0));
                DIO_enuWriteChannel(SSDISPLAY_BCD_21, GET_BIT(Copy_u8Number, 1));
                DIO_enuWriteChannel(SSDISPLAY_BCD_22, GET_BIT(Copy_u8Number, 2));
                DIO_enuWriteChannel(SSDISPLAY_BCD_23, GET_BIT(Copy_u8Number, 3));

            break;
            case 3:
                DIO_enuWriteChannel(SSDISPLAY_BCD_30, GET_BIT(Copy_u8Number, 0));
                DIO_enuWriteChannel(SSDISPLAY_BCD_31, GET_BIT(Copy_u8Number, 1));
                DIO_enuWriteChannel(SSDISPLAY_BCD_32, GET_BIT(Copy_u8Number, 2));
                DIO_enuWriteChannel(SSDISPLAY_BCD_33, GET_BIT(Copy_u8Number, 3));

            break;
            case 4:
                DIO_enuWriteChannel(SSDISPLAY_BCD_40, GET_BIT(Copy_u8Number, 0));
                DIO_enuWriteChannel(SSDISPLAY_BCD_41, GET_BIT(Copy_u8Number, 1));
                DIO_enuWriteChannel(SSDISPLAY_BCD_42, GET_BIT(Copy_u8Number, 2));
                DIO_enuWriteChannel(SSDISPLAY_BCD_43, GET_BIT(Copy_u8Number, 3));

            break;                       
        }

        
   
    }
    return Loc_tenuStatus;
}










