/*
 * ADC.c
 *
 * Created: 10/23/2023 11:20:51 AM
 *  Author: ahmed radwan
 */ 
#include "../../../SERVICES/Standard_Data_Types.h"
#include "../../../SERVICES/Bit_Wise_Operations.h"
#include "../../PORT/PORT.h"
#include "../../PORT/PORT_PRIV.h"
#include "../Inc/ADC_PRIV.h"
#include "../Inc/ADC_CFG.h"
#include "../Inc/ADC.h"
static CALL_BACK_FN_TYPE ADC_CALLBack=NULL;
static void adc_int_cfg(stADC_cfg_t *ADC);
 /*void ADC_INIT(void)
 { 
	 ADC_ENABLE();
	 ADC_SET_INTERNAL_v_Refrance();
	 ADC_PRESCALER_128();
	 
 }*/
 void ADC_INIT(stADC_cfg_t *ADC)
 {
	 ADC_SET_V_Refrance(ADC->ADCvolt_refrance);
	 ADC_SET_PRESCALER(ADC->ADCprescaler);
	 adc_int_cfg(ADC);
	 ADC_ENABLE();
 }
  void ADC_SET_Callback(void (*ADC_CALLBack_ISR)(void))
 { 
	 ADC_CALLBack=ADC_CALLBack_ISR;
	 
 }
 void ADC_DEINIT(void)
 {
	 ADC_DISABLE();
	 ADC_DISABLE_INT(); 
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
  void ADC_GET_CONV_ISR(ADC_enuTChanel channel,u16* result){
	  Port_enuSetpinDirection(PIN_A0_ID_0+channel,PIN_MODE_INPUT);
	 // u8 LOW_byte=0;
	  //u8 HIGH_byte=0;
	  ADC_SELECT_CHANNEL(channel);
	  ADC_START_CONV();
	  /* while(((ADCSRA>>4)&1)==0);
	  LOW_byte =ADCL;
	  HIGH_byte =ADCH;
	  *result=HIGH_byte*256+LOW_byte;
	  ADC_CLEAR_FLAG();*/
  }
  
  
  static void adc_int_cfg(stADC_cfg_t *ADC)
  {
	  if(ADC_INT_ENABLE==ADC->Interrupt)
	  {
		 ADC_ENABLE_INT();
		 ADC_CALLBack=ADC->ADC_isr;
	  }
  }
  void __vector_18(void) __attribute__((signal));
  void __vector_18(void)
 {
   if(NULL!=ADC_CALLBack)
   {
	 ADC_CALLBack();  
	}
	  
  }
 