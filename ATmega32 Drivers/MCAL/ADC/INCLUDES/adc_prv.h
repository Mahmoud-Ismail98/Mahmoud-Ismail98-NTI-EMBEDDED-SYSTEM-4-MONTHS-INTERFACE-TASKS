/*
=======================================================================================================================
Author       : Mamoun
Module       : ADC
File Name    : adc_prv.h
Date Created : Oct 23, 2023
Description  : Private file for the ATmega32 ADC driver.
=======================================================================================================================
*/


#ifndef MCAL_ADC_INCLUDES_ADC_PRV_H_
#define MCAL_ADC_INCLUDES_ADC_PRV_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* ADC API interface modes: [Interrupt or Polling]. */
#define ADC_USING_POLLING                                (0U)
#define ADC_USING_INTERRUPT                              (1U)

/*=====================================================================================================================
                                         < Function-like Macros >
=====================================================================================================================*/

#define ADC_SET_VOLTAGE_REF(ADC_REF_VAL)       (ADMUX = ((ADMUX & 0X3F) | (ADC_REF_VAL << 6)))
#define ADC_SET_CHANNEL(ADC_CHANNEL_ID)        (ADMUX = ((ADMUX & 0XF8) | (ADC_CHANNEL_ID & 0X07)))
#define ADC_SET_PRESCALER(ADC_PRESCALER_VAL)   (ADCSRA = ((ADCSRA & 0XF8) | (ADC_PRESCALER_VAL & 0X07)))

#endif /* MCAL_ADC_INCLUDES_ADC_PRV_H_ */
