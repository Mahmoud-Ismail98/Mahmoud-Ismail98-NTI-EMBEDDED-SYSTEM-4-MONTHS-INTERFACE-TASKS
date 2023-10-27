/*
 * ADC.h
 *
 * Created: 10/23/2023 11:21:02 AM
 *  Author: ahmed radwan
 */ 


#ifndef ADC_H_
#define ADC_H_

#define ADC_SET_INTERNAL_v_Refrance()   SET_BIT(ADMUX,6)

#define ADC_DATA_LEFT_SHIFT()		    SET_BIT(ADMUX,5)
#define ADC_DATA_RIFHT_SHIFT()		    CLR_BIT(ADMUX,5)

#define ADC_SELECT_CHANNEL(channel)    ASSIGN_L_NIB(ADMUX,channel)

#define ADC_ENABLE()					SET_BIT(ADCSRA,7)
#define ADC_DISABLE()					CLR_BIT(ADCSRA,7) 

#define ADC_PRESCALER_128()                   ADCSRA|=0x07

#define ADC_START_CONV()					SET_BIT(ADCSRA,6)
#define ADC_STOP_CONV()						CLR_BIT(ADCSRA,6)

#define ADC_CLEAR_FLAG()						CLR_BIT(ADCSRA,4)
#define ADC_CONV_DONE()						    GET_BIT(ADCSRA,4)


 typedef enum {
	 ADC0,
	 ADC1,
	 ADC2,
	 ADC3,
	 ADC4,
	 ADC5,
	 ADC6,
	 ADC7
	 }ADC_enuTChanel;
	 
 void ADC_INIT(void);
 void ADC_DEINIT(void);
 void ADC_SET_Callback(void (*ADC_CALLBack_ISR)(void));
 void ADC_GET_CONV_ISR(ADC_enuTChanel channel,u16* result);
 void ADC_GET_CONV_BOOLING(ADC_enuTChanel,ptr_u16 result);
 



#endif /* ADC_H_ */