#ifndef ADC_PRIV_H 
#define ADC_PRIV_H
/* ADMUX - ADC Multiplexer Selection Register */
#define ADMUX       *((volatile u8 *)27) /* Address of ADMUX Register */
#define ADMUX_REFS1  7 /* Reference Selection Bit 1 */
#define ADMUX_REFS0  6 /* Reference Selection Bit 0 */
#define ADMUX_ADLAR  5 /* ADC Left Adjust Result */
#define ADMUX_MUX4   4 /* Analog Channel Selection Bit 4 */
#define ADMUX_MUX3   3 /* Analog Channel Selection Bit 3 */
#define ADMUX_MUX2   2 /* Analog Channel Selection Bit 2 */
#define ADMUX_MUX1   1 /* Analog Channel Selection Bit 1 */
#define ADMUX_MUX0   0 /* Analog Channel Selection Bit 0 */

/* ADCSRA - ADC Control and Status Register A */
#define ADCSRA       *((volatile u8 *)26) /* Address of ADCSRA Register */
#define ADCSRA_ADEN  7 /* ADC Enable */
#define ADCSRA_ADSC  6 /* ADC Start Conversion */
#define ADCSRA_ADATE 5 /* ADC Auto Trigger Enable */
#define ADCSRA_ADIF  4 /* ADC Interrupt Flag */
#define ADCSRA_ADIE  3 /* ADC Interrupt Enable */
#define ADCSRA_ADPS2 2 /* ADC Prescaler Select Bit 2 */
#define ADCSRA_ADPS1 1 /* ADC Prescaler Select Bit 1 */
#define ADCSRA_ADPS0 0 /* ADC Prescaler Select Bit 0 */

/* ADCH - ADC Data Register High Byte */
#define ADCH        *((volatile u8 *)25) /* Address of ADCH Register */

        /* ADC - ADC Data Register Low Byte */
       /* Accessing The 10_Bits By Casting It To u16 */
#define ADC         *((volatile u8 *)16) /* Address of ADC Register */




#endif