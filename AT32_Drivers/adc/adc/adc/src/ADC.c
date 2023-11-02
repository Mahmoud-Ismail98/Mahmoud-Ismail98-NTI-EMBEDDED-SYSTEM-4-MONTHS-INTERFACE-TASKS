/*
 * ADC.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Ahmed Dwidar
 */
#include"ADC.h"
#include"ADC_cfg.h"
#include"ADC_prv.h"
#include<avr/io.h>
#include<avr/interrupt.h>

void(*ADCClbk_ptr)(void) = NULL;

ISR(ADC_vect)
{
	if(ADCClbk_ptr != NULL)
	{
		ADCClbk_ptr();
	}
}


void ADC_init(void)
{
	ASSIGN_REG(ADMUX,0X00);
	ASSIGN_REG(ADCSRA,0X00);

	SET_BIT(ADMUX,REFS0);

	SET_BIT(ADCSRA,ADEN);

	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);

//	ASSIGN_FIRST_TWO_BITS(ADCSRA,ADC_SELECT_PRESCALER);
	SET_BIT(ADCSRA,ADIE);
}

ADC_errorStatus ADC_readChannel(u8 channel_id)
{
	ADC_errorStatus return_errorStatus = ADC_OK;

	if(ADC_REF_VOLT_VALUE > ADC_MAX_INPUT_VOLTAGE)
	{
		return_errorStatus = refVoltage_error;
	}
	else if(ADC_SELECT_PIN_TO_READ > MAX_PIN_ID)
	{
		return_errorStatus = pin_error;
	}

	else
	{
		channel_id &= 0x07;
		ADMUX &= 0xE0;
		ADMUX = ADMUX | channel_id;

		SET_BIT	(ADCSRA,ADSC);
	}
	return return_errorStatus;
}
void ADC_setCallBack(void(*loc_ADCClbk_ptr)(void))
{
	ADCClbk_ptr = loc_ADCClbk_ptr;
}

void ADC_disable(void)
{
	ASSIGN_REG(ADMUX,0X00);
	ASSIGN_REG(ADCSRA,0X00);
}
