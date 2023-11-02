/*
 * ADC_prv.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Ismail
 */

#ifndef MCAL_ADC_ADC_PRV_H_
#define MCAL_ADC_ADC_PRV_H_

#define ADMUX		*((volatile u8*)0x27)
#define ADCSRA		*((volatile u8*)0x26)
#define ADCLH		*((volatile u16*)0x24)
#define SFIOR		*((volatile u8*)0x50)

/*3 VOLTAGE REFRENCES CONTROLLED BY THE TWO BIT 7 ,6 FROM ADMUX REG*/
#define REFS1 			7
#define REFS0			6
#define VREF_AREF_PIN   0
#define VREF_AVCC_PIN   1
#define VREF_2_56V_INTERNAL  3

#define ADEN 			7
#define ADSC            6
#define ADIF			4
#define ADPS2			2
#define ADPS1			1
#define ADPS0			0
#define ADIE            3
#define PRESCALER_DIVIDE_BY_2 		1
#define PRESCALER_DIVIDE_BY_4 		2
#define PRESCALER_DIVIDE_BY_8 		3
#define PRESCALER_DIVIDE_BY_16 		4
#define PRESCALER_DIVIDE_BY_32 		5
#define PRESCALER_DIVIDE_BY_64 		6
#define PRESCALER_DIVIDE_BY_128 	7

/*LEFT OR RIGHT ADJUST BY SETTING OR CLEARING BIT ADLAR(BIT 5) FROM THE ADMUX REG*/
#define ADLAR 			  5
#define ADC_RIGHT_ADJUST  0
#define ADC_LEFT_ADJUST   1

#define ADC_CHANNEL_INPUT_MASK 0X1F      //0001 1111
#define ADC_ADMUX_REG_MASK 0XE0          //1110 0000

#endif /* MCAL_ADC_ADC_PRV_H_ */
