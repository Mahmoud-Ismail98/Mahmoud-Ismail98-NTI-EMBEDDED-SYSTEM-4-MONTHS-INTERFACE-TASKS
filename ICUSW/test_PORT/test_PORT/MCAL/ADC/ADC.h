/*
 * ADC.h
 *
 * Created: 10/22/2023 11:55:32 AM
 *  Author: FADY
 */
#ifndef ADC_H
#define ADC_H
#include "../../SERVICES/Std_types.h"
#include "../../SERVICES/Bit_utils.h"



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
#endif