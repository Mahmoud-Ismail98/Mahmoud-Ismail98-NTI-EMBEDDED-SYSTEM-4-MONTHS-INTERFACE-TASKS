/*
 * main.c
 *
 *  Created on: Oct 28, 2023
 *      Author: Online
 */
#include "../4-SERVICS/Std_types.h"
#include "../4-SERVICS/Bit_utils.h"
#include "../1-MCAL/01-DIO/DIO_Int.h"
#include "../2-HAL/LCD/LCD.h"
#include "util/delay.h"
int main (){
MDIO_VidSetPortDirection(Port_B,0xFF);
MDIO_VidSetPinDirection(Port_A,Pin_0,Pin_Output);
MDIO_VidSetPinDirection(Port_A,Pin_1,Pin_Output);
MDIO_VidSetPinDirection(Port_A,Pin_2,Pin_Output);

u8 Pattern2[]={
		 0b00000,
		 0b00000,
		 0b00000,
		 0b00000,
		 0b00000,
		 0b00000,
		 0b00000,
		 0b11111
};
u8 PAttern1[]={
		 0b01110,
		 0b01110,
		 0b00100,
		 0b01110,
		 0b10101,
		 0b01110,
		 0b10001,
		 0b00000
};
	CLCD_VoidInit();


	while (1){
		for (u8 i=0; i<16 ; i++){
		CLCD_voidCreateSpeacialCharater(PAttern1,0,0,i);
		_delay_ms(80);
CLCD_voidClearDisplay();
		}
	}


}
