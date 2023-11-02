/*
 * ADC.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Ismail
 */
#include "../includes/ADC.h"
#include"../../../Services/Bit_utils.h"
#include"../../../Services/Std_types.h"
#include "../../GIE/includes/GIE.h"

	/**
	 * Init:
	 * 1-Select Vreference
	 * 2-Set Prescalar
	 * 3-Select Left/Right Adjust
	 * 4-Enable ADC
	 * Start Conversion:
	 * 1-Set Channel
	 * 2-Start Conversion
	 * 3-Poll on ADIF flag
	 * 4-Return ADC value
	 */
void ADC_Init(void){

		//Set Vreference
	#if ADC_SET_VREF==VREF_AREF_PIN
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
	#elif ADC_SET_VREF==VREF_AVCC_PIN
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
	#elif ADC_SET_VREF==VREF_2_56V_INTERNAL
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
	#else
		#error "Wrong Voltage reference Chosen"
	#endif

		//Set Prescalar
	#if ADC_SET_PRESCALAR==PRESCALER_DIVIDE_BY_2
	SET_BIT(ADCSRA,ADPS0);
	CLR_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS2);

	#elif ADC_SET_PRESCALAR==PRESCALER_DIVIDE_BY_4
	CLR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS2);
	#elif ADC_SET_PRESCALAR==PRESCALER_DIVIDE_BY_8
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS2);
	#elif ADC_SET_PRESCALAR==PRESCALER_DIVIDE_BY_16
	CLR_BIT(ADCSRA,ADPS0);
	CLR_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	#elif ADC_SET_PRESCALAR==PRESCALER_DIVIDE_BY_32
	SET_BIT(ADCSRA,ADPS0);
	CLR_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	#elif ADC_SET_PRESCALAR==PRESCALER_DIVIDE_BY_64
	CLR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	#elif ADC_SET_PRESCALAR==PRESCALER_DIVIDE_BY_128
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	#else
	#error"Wrong Prescalar Chosen"
	#endif

	//RIGHT/Adjust
	#if ADC_SET_ADJUST_LEVEL==ADC_RIGHT_ADJUST
	CLR_BIT(ADMUX,ADLAR);
	#elif ADC_SET_ADJUST_LEVEL==ADC_LEFT_ADJUST
	SET_BIT(ADMUX,ADLAR);
	#endif
	/*Enable ADC*/
	SET_BIT(ADCSRA,ADEN);
	}

u16 ADC_StartConversion(u8 Copy_u8ADC_Channel)
	{
		//Set Channel
		u8 Loc_u8ADC_Channel;
		 Loc_u8ADC_Channel =Copy_u8ADC_Channel&ADC_CHANNEL_INPUT_MASK;
		ADMUX&=ADC_ADMUX_REG_MASK;
		ADMUX|=Loc_u8ADC_Channel;
		//set global Interrupt enable flag
		GIEMode(GIE_ENABLE);

		//Start Conversion
		SET_BIT(ADCSRA,ADSC);

		//Poll on the Flag the flag is 1 when conversion is done
		while(GET_BIT(ADCSRA,ADIF)==0);

		//Conversion finished
		return ADCLH;
	}

void ADC_Stop(void){
	CLR_BIT(ADMUX,ADEN);
}
void __vector_16(void){

 SET_BIT(ADCSRA ,ADSC);
}
