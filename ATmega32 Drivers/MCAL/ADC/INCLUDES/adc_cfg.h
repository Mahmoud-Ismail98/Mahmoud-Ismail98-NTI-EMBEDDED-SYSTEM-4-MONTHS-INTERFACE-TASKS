/*
=======================================================================================================================
Author       : Mamoun
Module       : ADC
File Name    : adc_cfg.h
Date Created : Oct 23, 2023
Description  : Configuration file for the ATmega32 ADC driver.
=======================================================================================================================
*/


#ifndef MCAL_ADC_INCLUDES_ADC_CFG_H_
#define MCAL_ADC_INCLUDES_ADC_CFG_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* The ADC only has two API interface modes: [ADC_USING_POLLING - ADC_USING_INTERRUPT]. */
#define ADC_API_INTERFACE_MODE                              (ADC_USING_INTERRUPT)

#endif /* MCAL_ADC_INCLUDES_ADC_CFG_H_ */
