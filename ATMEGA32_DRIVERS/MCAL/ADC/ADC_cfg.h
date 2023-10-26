#ifndef ADC_CONFIG_H 
#define ADC_CONFIG_H
//The following decides what will be your VRef you can choose between
/*
 * AREF
 * AVCC_CAPACITOR_AT_AREF
 * INTERNAL_2_56_VOLTAGE_REFERENCE
 */
#define VOLTAGE_REFERENCE_SELECTION AVCC_CAPACITOR_AT_AREF

/*The following decides if the ADC conversion will be right or left adjusted
if right adjusted the ADCH will contain the 2 MSB(Most significant Bits)
of conversion and ADCL will contain the other 8. if it is left adjusted the
ADCH will contain the 8 MSB and ADCL will contain last 2*/
/*
 * LEFT_ADJUSTED
 * RIGHT_ADJUSTED
 */
#define ADC_CONVERSION_FORM LEFT_ADJUSTED
/*the following configures the analog channel if it will be single ended input (SEI)
input or differential input (DI) with positive P and negative N bits and a
gain G
 */
/*
 * SEI_ADC0
 * SEI_ADC1
 * SEI_ADC2
 * SEI_ADC3
 * SEI_ADC4
 * SEI_ADC5
 * SEI_ADC6
 * SEI_ADC7
 * DI_PADC0_NADC0_G10
 * DI_PADC1_NADC0_G10
 * DI_PADC0_NADC0_G200
 * DI_PADC1_NADC0_G200
 * DI_PADC2_NADC2_G10
 * DI_PADC3_NADC2_G10
 * DI_PADC2_NADC2_G200
 * DI_PADC3_NADC2_G200
 * DI_PADC0_NADC1_G1
 * DI_PADC1_NADC1_G1
 * DI_PADC2_NADC1_G1
 * DI_PADC3_NADC1_G1
 * DI_PADC4_NADC1_G1
 * DI_PADC5_NADC1_G1
 * DI_PADC6_NADC1_G1
 * DI_PADC7_NADC1_G1
 * DI_PADC0_NADC2_G1
 * DI_PADC1_NADC2_G1
 * DI_PADC2_NADC2_G1
 * DI_PADC3_NADC2_G1
 * DI_PADC4_NADC2_G1
 * DI_PADC5_NADC2_G1
 * SEI_1_22V
 * SEI_0V
  */
#define ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE SEI_ADC0
//the following configuration enables you enable or disable ADC
/*
 * ENABLED
 * DISABLED
 */
#define ADC_ENABLE ENABLED
//the following configuration allows you to enable auto trigger mode
//selection of trigger source will be later
/*
 * ENABLED
 * DISABLED
 */
#define ADC_AUTO_TRIGGER_ENABLE DISABLED
//for the following update this feature will be always disabled
//the following configuration enables you to enable interrupt when
//ADC completes the conversion
/*
 * ENABLED
 * DISABLED
 */
#define ADC_INTERRUPT_ENABLE DISABLED 

//The following configuration allows you to choose the factor between the XTAL frequency and the
//input clock to the ADC
//for 10bits resolution clock frequency should be between 50KHz and 200KHz to get full resolution, for 8bits frequency could be higher to get better sample rate
/*
 * DIVISION_FACTOR_2
 * DIVISION_FACTOR_2
 * DIVISION_FACTOR_4
 * DIVISION_FACTOR_8
 * DIVISION_FACTOR_16
 * DIVISION_FACTOR_32
 * DIVISION_FACTOR_64
 * DIVISION_FACTOR_128
 */

#define ADC_PRESCALER_SET_BITS  DIVISION_FACTOR_128

//thE following configurations allows you to choose source that
//auto triggers the conversion whether it is
/*
*FREE_RUNNING_MODE
*ANALOG_COMAPARTOR
*EXTERNAL_INTERRUPT_REQUEST_0
*TIMER_OR_COUNTER0_COMPARE_MATCH
*TIMER_OR_COUNTER0_OVERFLOW
*TIMER_OR_COUNTER1_COMPARE_MATCH_B
*TIMER_OR_COUNTER1_OVERFLOW
*TIMER_OR_COUNTER1_CAPTURE_EVENT
*/
#define AUTO_TRIGGER_SOURCE FREE_RUNNING_MODE






#endif