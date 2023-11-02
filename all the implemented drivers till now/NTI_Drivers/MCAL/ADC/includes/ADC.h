/*
 * ADC.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Ismail
 */
#include"ADC_cfg.h"
#include "ADC_prv.h"
#include"../../../Services/Std_types.h"
#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_
/*IF THE VALUE FOR THOSE 4 BIT IN ADMUX REG EXEED 7, DIFFERNTIAL MODE WITH GAIN
 * IS USED, CHECK TABLE 84 PAGE 213 FROM DATASHEET FOR MORE INFO
 * NOT TESTED ON ALL devices in PDIP Package. This feature is only guaranteed to work for devices in TQFP and MLF Packages
 */
#define ADC_CHANNEL_0  0
#define ADC_CHANNEL_1  1
#define ADC_CHANNEL_2  2
#define ADC_CHANNEL_3  3
#define ADC_CHANNEL_4  4
#define ADC_CHANNEL_5  5
#define ADC_CHANNEL_6  6
#define ADC_CHANNEL_7  7

/*ADC Function Prototypes*/
void ADC_Init(void);
u16 ADC_StartConversion(u8 Copy_u8ADC_Channel);
void ADC_Stop(void);
void __vector_16 (void) __attribute__((signal));
#endif /* MCAL_ADC_ADC_H_ */
