/*
 * KeyPad.h
 *
 * Created: 10/23/2023 11:15:51 AM
 *  Author: Wael
 */ 

#ifndef ADC_PRV_H_
#define ADC_PRV_H_

#define ADC_Prescaler_2   1
#define ADC_Prescaler_4   2
#define ADC_Prescaler_8   3
#define ADC_Prescaler_16  4
#define ADC_Prescaler_32  5
#define ADC_Prescaler_64  6
#define ADC_Prescaler_128 7

///////////////////////////////////////
#define ADC_VREF_AREF   0 
#define ADC_VREF_AVCC   1
#define ADC_VREF_INT256 3   //2.56V
////////////////////////////////////////
#define ADC_CH0  0 
#define ADC_CH1  1 
#define ADC_CH2  2 
#define ADC_CH3  3 
#define ADC_CH4  4 
#define ADC_CH5  5 
#define ADC_CH6  6 
#define ADC_CH7  7 
////////////////////////////////////////
/*Registers*/
#define ADMUX (*(volatile unsigned char*)0x27)
#define ADLAR 5
#define REFS0 6
#define REFS1 7

#define ADCSRA (*(volatile unsigned char*)0x26)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADIF  4
#define ADSC  6
#define ADEN  7

#define ADC_R (*(volatile unsigned short*)0x24)
/////////////////////////////////////////
/* ADC Vector */
#define ADC_vect  __vector_16

#endif
