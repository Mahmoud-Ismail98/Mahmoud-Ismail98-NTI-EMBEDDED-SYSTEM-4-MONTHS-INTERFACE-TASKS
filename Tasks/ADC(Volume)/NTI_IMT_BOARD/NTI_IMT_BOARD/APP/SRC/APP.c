/*
 * APP.c
 *
 * Created: 10/20/2023 11:04:12 PM
 *  Author: Mahmoud Tariq
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CLCK.h"
#include "util/delay.h"

#include "PORT.h"
#include "DIO.h"

#include "LCD.h"

#include "APP.h"

void APP_vidInit(void){
	PORT_vInit();
	LCD_vid4Bit_Init();
	ADC_vidInit();	
}