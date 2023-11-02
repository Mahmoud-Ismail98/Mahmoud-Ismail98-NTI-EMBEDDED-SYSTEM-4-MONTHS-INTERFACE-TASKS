/*
 * ADC_PRIVATE.h
 *
 * Created: 10/26/2023 6:43:31 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/*ADC Multiplexer Selection Register*/
#define ADMUX ((*(volatile pu8)0x27))
/*ADMUX BITS*/
#define ADMUX_REFS1  7    //Reference Voltage selection bit 1
#define ADMUX_REFS0  6    //Reference Voltage selection bit 0
#define ADMUX_ADLAR  5    //ADC Left Adjust Result (1 to turn on left adjust)
#define ADMUX_MUX4   4    //Analog Channel and gain selection bit 4
#define ADMUX_MUX3   3	  //Analog Channel and gain selection bit 3
#define ADMUX_MUX2   2    //Analog Channel and gain selection bit 2
#define ADMUX_MUX1   1    //Analog Channel and gain selection bit 1
#define ADMUX_MUX0   0    //Analog Channel and gain selection bit 0

/*ADC Control and Status Register A*/
#define ADCSRA ((*(volatile pu8) 0x26))
/*ADCSRA BITS*/
#define ADCSRA_ADEN  7   //ADC ENABLE BIT
#define ADCSRA_STARTCONV  6   //ADC START CONVERSION
#define ADCSRA_ADATE 5   //ADC Auto Trigger Enable
#define ADCSRA_ADIF  4   //ADC Interrupt Flag
#define ADCSRA_ADIE  3   //ADC Interrupt Enable
#define ADCSRA_ADPS2 2   //ADC Prescaler Select BIT2
#define ADCSRA_ADPS1 1   //ADC Prescaler Select BIT1
#define ADCSRA_ADPS0 0   //ADC Prescaler Select BIT0

/*ADC Data Register High Byte*/
#define ADCH ((*(volatile pu8) 0x25))

/*ADC Data Register Low Byte*/
#define ADCL ((*(volatile pu8) 0x24))

/*Special FunctionIO Register – SFIOR*/
#define SFIOR ((*(volatile pu8) 0x50))
/*SFIOR BITS*/
#define SFIOR_ADTS2 7
#define SFIOR_ADTS1 6
#define SFIOR_ADTS0 5




#endif /* ADC_PRIVATE_H_ */