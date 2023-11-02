/*
 * ADC.h
 *
 * Created: 10/22/2023 11:55:32 AM
 *  Author: FADY
 */
#ifndef ADC_H
#define ADC_H



/*to choose which channel */
#define ADC_Channel_0   0
#define ADC_Channel_1   1
#define ADC_Channel_2   2
#define ADC_Channel_3   3
#define ADC_Channel_4   4
#define ADC_Channel_5   5
#define ADC_Channel_6   6
#define ADC_Channel_7   7

/*to choose referene */
#define ADC_AREF        0
#define ADC_AVCC        1
#define ADC_Internal    3


typedef enum ADC_ErrorStatus{
    A_OK,ADC_WrongChannel,ADC_NULLPTR
}ADC_ErrorStatus;


void ADC_voidinit(void);
ADC_ErrorStatus ADC_StartConverstion(u8 Copy_u8Channel,pu16 Ptr_addData);
void ADC_Disable(void);
ADC_ErrorStatus ADC_AaynchStartConversion(u8 Copy_u8Channel) ;
void ADC_voidSetCallBackHandler( void (*ADC_SetCallBackFunc)(u16 Copy_ADCValue));
void ADC_voidGetADCValue(pu16 Add_pu16Value);
#endif