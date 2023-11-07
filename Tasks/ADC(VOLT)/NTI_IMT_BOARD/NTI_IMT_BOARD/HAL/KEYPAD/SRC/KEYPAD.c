/*
 * KEYPAD.c
 *
 * Created: 10/22/2023 10:59:58 PM
 *  Author: Mahmoud Tariq
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "DIO.h"
#include "PORT.h"
#include "KEYPAD.h"
#include "KEYPAD_CFG.h"
#include "KEYPAD_PRIVATE.h"

void KeyPad_vidInit(void){
	PORT_enuSetPinMode(KEYPAD_col1,INPUT_PULL_UP);
	PORT_enuSetPinMode(KEYPAD_col2,INPUT_PULL_UP);
	PORT_enuSetPinMode(KEYPAD_col3,INPUT_PULL_UP);
	PORT_enuSetPinMode(KEYPAD_col4,INPUT_PULL_UP);
	
	PORT_enuSetPinDirection(KEYPAD_row1,PORT_PIN_OUTPUT);
	PORT_enuSetPinDirection(KEYPAD_row2,PORT_PIN_OUTPUT);
	PORT_enuSetPinDirection(KEYPAD_row3,PORT_PIN_OUTPUT);
	PORT_enuSetPinDirection(KEYPAD_row4,PORT_PIN_OUTPUT);
}

void KeyPad_vidWriteRows(u8 pattern){
	
	DIO_enuWriteChannel(KEYPAD_row1,GET_BIT(pattern,0));
	DIO_enuWriteChannel(KEYPAD_row2,GET_BIT(pattern,1));
	DIO_enuWriteChannel(KEYPAD_row3,GET_BIT(pattern,2));
	DIO_enuWriteChannel(KEYPAD_row4,GET_BIT(pattern,3));
}

void KeyPad_vidReadcols(pu8 add){
	u8 temp;
	DIO_enuReadChannel(KEYPAD_col1,&temp);
	*add |= temp<<0;
	DIO_enuReadChannel(KEYPAD_col2,&temp);
	*add |= temp<<1;
	DIO_enuReadChannel(KEYPAD_col3,&temp);
	*add |= temp<<2;
	DIO_enuReadChannel(KEYPAD_col4,&temp);
	*add |= temp<<3;
}

u8 KEYPAD_u8GetKey(void){
	 u8 Local_u8PressedButton = 0x00;
	 u8 Local_u8Symbol = 0x00 ;
	 while (Local_u8Symbol == 0x00){
		 for(int i = 0 ; i < 4 ; i++){
			 KeyPad_vidWriteRows(TGLWITHOUTASSIGN_BIT(0X0F, i));
			 KeyPad_vidReadcols(&Local_u8PressedButton);
			 //            _delay_ms(50);
			 switch (Local_u8PressedButton){
				 case KEYPAD_pattern1:
				 Local_u8Symbol = SYMBOLS[(i*4) + 0]; break;
				 case KEYPAD_pattern2:
				 Local_u8Symbol = SYMBOLS[(i*4) + 1]; break;
				 case KEYPAD_pattern3:
				 Local_u8Symbol = SYMBOLS[(i*4) + 2]; break;
				 case KEYPAD_pattern4:
				 Local_u8Symbol = SYMBOLS[(i*4) + 3]; break;
			 }
		 }
	 }

	 return Local_u8Symbol;
 }
	


