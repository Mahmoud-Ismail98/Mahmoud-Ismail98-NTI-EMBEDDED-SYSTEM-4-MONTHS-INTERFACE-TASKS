/*
 * ADC.h
 *
 * Created: 10/26/2023 6:43:15 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef ADC_H_
#define ADC_H_
//======================Pin Configuration for ATMEGA32=============================

#define ADC_CHANNEL0   0
#define ADC_CHANNEL1   1
#define ADC_CHANNEL2   2
#define ADC_CHANNEL3   3
#define ADC_CHANNEL4   4
#define ADC_CHANNEL5   5
#define ADC_CHANNEL6   6
#define ADC_CHANNEL7   7

typedef enum{
	ADC_STATUS_FAILED,
	ADC_STATUS_OK,
	ADC_CHANNEL_NO_ERR,
	ADC_NULL_PTR_ERR
}ADC_enuErrorStatus_t;

void ADC_vidInit(void);
void ADC_vidDeInit(void);
ADC_enuErrorStatus_t ADC_ReadChannel(u8 copy_u8ADC_Channel ,pu16 add_pu16ADCValue);
void ADC_SetCallBack( void (*pF) (void) );


#endif /* ADC_H_ */