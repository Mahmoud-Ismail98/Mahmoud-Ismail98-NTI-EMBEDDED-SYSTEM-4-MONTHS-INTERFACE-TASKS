/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 23 Oct 2023                                                           */
/************************************************************************************/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

typedef enum{
    ADC_Read_OK,
    ADC_Read_NOK,
}ADCEnum;

/* Macros for the channels */
#define ADC_CHANNEL_0               0
#define ADC_CHANNEL_1               1
#define ADC_CHANNEL_2               2
#define ADC_CHANNEL_3               3
#define ADC_CHANNEL_4               4
#define ADC_CHANNEL_5               5
#define ADC_CHANNEL_6               6
#define ADC_CHANNEL_7               7

void ADC_voidInit(void);
ADCEnum ADC_ADCEnumReadSync(u8 copy_u8Channel,pu16 copy_pu16DigitalValue);
ADCEnum ADC_ADCEnumReadAsync(u8 copy_u8Channel,pu16 copy_pu16DigitalValue,void (*copy_pf)(void));

#endif
