/*
 * ADC.c
 *
 * Created: 10/23/2023 11:20:51 AM
 *  Author: ahmed radwan
 */ 
#include "../../SERVICES/Standard_Data_Types.h"
#include "../../SERVICES/Bit_Wise_Operations.h"
#include "../PORT/PORT.h"
#include "../PORT/PORT_PRIV.h"
#include "ADC_PRIV.h"
#include "ADC_CFG.h"
#include "ADC.h"
static void ADC_CALLBack(void);
 void ADC_INIT(void)
 { 
	 ADC_ENABLE();
	 ADC_SET_INTERNAL_v_Refrance();
	 ADC_PRESCALER_128();
 }
 void ADC_DEINIT(void)
 {
	 ADC_DISABLE();
 }
 void ADC_GET_CONV_BOOLING(ADC_enuTChanel channel,u16* result){
	 Port_enuSetpinDirection(PIN_A0_ID_0+channel,PIN_MODE_INPUT);
	 u8 LOW_byte=0;
	 u8 HIGH_byte=0;
	 ADC_SELECT_CHANNEL(channel);
	 ADC_START_CONV();
	 while(((ADCSRA>>4)&1)==0);
	 LOW_byte =ADCL;
	 HIGH_byte =ADCH;
	 *result=HIGH_byte*256+LOW_byte;
	 ADC_CLEAR_FLAG(); 
 }
 