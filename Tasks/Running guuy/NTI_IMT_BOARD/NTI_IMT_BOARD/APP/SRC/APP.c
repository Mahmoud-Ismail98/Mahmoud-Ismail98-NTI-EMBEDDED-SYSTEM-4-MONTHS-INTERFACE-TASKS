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
#include "GIE.h"
#include "EXTI.h"
#include "USART.h"
#include "GPTM.h"
#include "ADC.h"
#include "WDT.h"

#include "SSD.h"
#include "LM35.h"
#include "LCD.h"
#include "KEYPAD.h"

#include "APP.h"

void APP_vidInit(void){
	PORT_vInit();
	//GI_vidInit();
	//GPTM_TIMER0_vidInit();
	//EXTI_vidInit();
	//USART_vidInit();
	//lm35_VidInit();
	//KeyPad_vidInit();
	LCD_vid4Bit_Init();
		
	

	
}