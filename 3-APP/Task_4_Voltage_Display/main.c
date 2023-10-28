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
u16 GLOBAL_digitalVal = 0;
u8 flag = 0;
void main(void){
	PORT_enuInit();
	GIE_vidInit();
	CLCD_VidInit();
	EXTI_voidInit();
	ADC_voidInit();
	EXTI_enuErrorStateInt1SetCallBack(&callBackFuncEXTI);
	CLCD_VidDisplayString("Volt = ");
	ADC_enuSetCallBackFunc(&callBackFuncADC);
	u16 currAdcRead = 0;
	u16 prevAdcRead = 0 ;

	while(1){
		ADC_voidReadChannel(ADC_SINGLE_CHANNEL_0, ADC_PRESCALER_DIV_FACTOR_128, ADC_RESOLUTION_16BIT, &currAdcRead);
//		ADC_voidReadChannelAsynch(ADC_SINGLE_CHANNEL_0, ADC_PRESCALER_DIV_FACTOR_128, ADC_RESOLUTION_16BIT, &GLOBAL_digitalVal);
//		u16 currAdcRead = GLOBAL_digitalVal;
		if (currAdcRead != prevAdcRead){
			if(flag == 0){
				CLCD_VidGoToXY(0,7);
				u16 volt = ((f32)currAdcRead / 1023) * 5;
				u16 per = (currAdcRead % 204) * 100;
				per /= 204;
				CLCD_VidDisplayNumber(volt);
				CLCD_VidDisplayCharacter('.');
				CLCD_VidDisplayNumber(per);
				CLCD_VidDisplayString("V     ");
			}
			else if (flag == 1){
				CLCD_VidGoToXY(0,7);
				u16 volt = ((f32)currAdcRead / 1023) * 5;
				u16 per = (currAdcRead % 204) * 100;
				per /= 204;
				CLCD_VidDisplayNumber(volt);
//				CLCD_VidDisplayCharacter('.');
				CLCD_VidDisplayNumber(per*10);
				CLCD_VidDisplayString("mV");
			}
		}
		prevAdcRead	= currAdcRead;
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
