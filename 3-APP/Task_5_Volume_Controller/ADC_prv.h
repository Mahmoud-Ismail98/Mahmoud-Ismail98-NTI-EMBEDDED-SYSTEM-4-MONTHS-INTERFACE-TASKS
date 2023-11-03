/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : ADC                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef ADC_PRV_H
#define ADC_PRV_H

static void ADC_prvENABLE();
static void ADC_prvDISABLE();

/*ADC Multiplexer Selection Register*/
#define ADMUX   *((volatile u8*) 0x27)


/*ADC Control and Status Register A*/
#define ADCSRA   *((volatile u8*) 0x26) 

/*ADC Data Register – ADCL*/
#define ADCL   *((volatile u8*) 0x24) 

/*ADC Data Register – ADCH*/
#define ADCH   *((volatile u8*) 0x25) 

#define ADCDATA *((volatile u16*) 0x24)

/*Special FunctionIO Register*/
#define SFIOR   *((volatile u8*) 0x50) 


#define ADC_MULTIPLEXER_SELECTION_MASK      0b11100000
#define ADC_PRESCALER_MASK                  0b11111000
#define ADC_REFERENCE_AREF_Internal_Vref_turned_off                     0
#define ADC_REFERENCE_AVCC_with_external_capacitor_at_AREF_pin          1
#define ADC_REFERENCE_Internal_Voltage                                  2

#define ADC_RIGHT_ADJUST                0
#define ADC_LEFT_ADJUST                 1


#endif
