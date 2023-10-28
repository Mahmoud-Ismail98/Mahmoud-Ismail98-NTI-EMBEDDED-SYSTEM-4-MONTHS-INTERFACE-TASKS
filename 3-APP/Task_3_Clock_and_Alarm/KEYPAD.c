/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : KEYPAD              **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/
#include "Std_types.h"
#include "Bit_utils.h"
#include <util/delay.h>

#include "DIO.h"

#include "KEYPAD.h"
#include "KEYPAD_cfg.h"
#include "KEYPAD_prv.h"


void static KEYPAD_prvWritePins(u8 Copy_u8Pattern){
    DIO_enuWriteChannel(KEYPAD_PIN_ROW_0, GET_BIT(Copy_u8Pattern, 0));
    DIO_enuWriteChannel(KEYPAD_PIN_ROW_1, GET_BIT(Copy_u8Pattern, 1));
    DIO_enuWriteChannel(KEYPAD_PIN_ROW_2, GET_BIT(Copy_u8Pattern, 2));
    DIO_enuWriteChannel(KEYPAD_PIN_ROW_3, GET_BIT(Copy_u8Pattern, 3));
}

void static KEYPAD_prvReadPins(pu8 Copy_pu8Pattern){
    u8 temp = 0x00;
    *Copy_pu8Pattern = 0x00;
    DIO_enuReadChannel(KEYPAD_PIN_COL_0, &temp);
    *Copy_pu8Pattern |=  temp << 0;
    DIO_enuReadChannel(KEYPAD_PIN_COL_1, &temp);
    *Copy_pu8Pattern |=  temp << 1;
    DIO_enuReadChannel(KEYPAD_PIN_COL_2, &temp);
    *Copy_pu8Pattern |=  temp << 2;
    DIO_enuReadChannel(KEYPAD_PIN_COL_3, &temp);
    *Copy_pu8Pattern |=  temp << 3;
    if (*Copy_pu8Pattern != 0){
//    	_delay_us(2750);
    }
}

u8 KEYPAD_u8GetButton(){
    u8 Local_u8PressedButton = 0x00;
    u8 Local_u8Symbol = 0x00 ;
    while (Local_u8Symbol == 0x00){
        for(int i = 0 ; i < 4 ; i++){
            KEYPAD_prvWritePins(TGLWITHOUTASSIGN_BIT(0x0F, i));
            KEYPAD_prvReadPins(&Local_u8PressedButton);
            _delay_ms(35);
            switch (Local_u8PressedButton){
            case 0b00001110:
                Local_u8Symbol = SYMBOLS[(i*4) + 0]; break;
            case 0b00001101:
                Local_u8Symbol = SYMBOLS[(i*4) + 1]; break;
            case 0b00001011:
                Local_u8Symbol = SYMBOLS[(i*4) + 2]; break;
            case 0b00000111:
                Local_u8Symbol = SYMBOLS[(i*4) + 3]; break;
            }
        }
    }

    return Local_u8Symbol;
}
