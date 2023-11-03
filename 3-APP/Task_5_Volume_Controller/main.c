#include "Std_types.h"
#include "Bit_utils.h"
#include <util/delay.h>
#include "PORT.h"
#include "DIO.h"
#include "CLCD.h"
#include "GIE.h"
#include "EXTI.h"
#include "ADC.h"
void callBackFuncEXTI();
void callBackFuncADC();

u8 customChar1[8] = {0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00011111,0b00011111};

u8 customChar2[8] = {0b00000000,0b00000000,0b00000000,0b00000000,0b00011111,0b00011111,0b00011111,0b00011111};

u8 customChar3[8] = {0b00000000,0b00000000,0b00011111,0b00011111,0b00011111,0b00011111,0b00011111,0b00011111};

u8 customChar4[8] = {0b00011111,0b00011111,0b00011111,0b00011111,0b00011111,0b00011111,0b00011111,0b00011111};

u16 GLOBAL_digitalVal = 0;
u8 flag = 0;
void main(void){
	PORT_enuInit();
	GIE_vidInit();
	CLCD_VidInit();
	CLCD_VidCreatCustomCharacter(customChar1, 1);
	CLCD_VidCreatCustomCharacter(customChar2, 2);
	CLCD_VidCreatCustomCharacter(customChar3, 3);
	CLCD_VidCreatCustomCharacter(customChar4, 4);

	EXTI_voidInit();
	ADC_voidInit();


	EXTI_enuErrorStateInt1SetCallBack(&callBackFuncEXTI);
	CLCD_VidDisplayString("Volume = ");
	ADC_enuSetCallBackFunc(&callBackFuncADC);
	u16 prevAdcRead = 0 ;

	while(1){
		ADC_voidReadChannel(ADC_SINGLE_CHANNEL_0, ADC_PRESCALER_DIV_FACTOR_128, ADC_RESOLUTION_16BIT, &GLOBAL_digitalVal);
		if (prevAdcRead == 0){
			prevAdcRead = GLOBAL_digitalVal;
		}
		if (GLOBAL_digitalVal > prevAdcRead + 40){
			CLCD_VidGoToXY(0,9);
			CLCD_VidDisplayCharacter(1);
			CLCD_VidDisplayCharacter(2);
			CLCD_VidDisplayCharacter(3);
			CLCD_VidDisplayCharacter(4);
			CLCD_VidDisplayString("        ");
		}else if (GLOBAL_digitalVal > prevAdcRead + 30){
			CLCD_VidGoToXY(0,9);
			CLCD_VidDisplayCharacter(1);
			CLCD_VidDisplayCharacter(2);
			CLCD_VidDisplayCharacter(3);
			CLCD_VidDisplayString("        ");
		}else if (GLOBAL_digitalVal > prevAdcRead + 20){
			CLCD_VidGoToXY(0,9);
			CLCD_VidDisplayCharacter(1);
			CLCD_VidDisplayCharacter(2);
			CLCD_VidDisplayString("        ");
		}else if (GLOBAL_digitalVal > prevAdcRead + 10){
			CLCD_VidGoToXY(0,9);
			CLCD_VidDisplayCharacter(1);
			CLCD_VidDisplayString("        ");
		}else if (GLOBAL_digitalVal <= prevAdcRead ){
			CLCD_VidGoToXY(0,9);
			CLCD_VidDisplayString("          ");
		}

		_delay_ms(500);
	}
}
void callBackFuncEXTI(){
//		CLCD_VidGoToXY(3,0);
//		CLCD_VidDisplayString("INTTTTTTTTTT");
		TGL_BIT(flag,0);
}

void callBackFuncADC(){
//	CLCD_VidGoToXY(3,0);
//	CLCD_VidDisplayString("Adc val updated");

}
