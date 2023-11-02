/*
 * L35.h
 *
 * Created: 23/10/2023 11:27:49 
 *  Author: EGYPT
 */ 


#ifndef LM35_H_
#define LM35_H_


#define ADC_RESOLUTION_10_BIT 0
#define ADC_RESOLUTION_8_BIT  1



typedef struct
{
	u8 Copy_u8LM35Channel ;
	u8 Copy_u8ADCVoltageReference ;       /* Vref = 5 , 2.56 , External  */
	u8 Copy_u8ADCResolution ;            /* ADC_RESOLUTION_10_BIT or ADC_RESOLUTION_8_BIT  */
} LM35_CONFIG ;

void LM35_u8GetValue (LM35_CONFIG * lm35 , u16 * Copy_u8Value) ;




#endif /* LM35_H_ */