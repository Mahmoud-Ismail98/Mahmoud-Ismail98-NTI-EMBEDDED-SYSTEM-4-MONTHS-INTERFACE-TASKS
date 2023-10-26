#ifndef ADC_PRIV_H 
#define ADC_PRIV_H

#define ADMUX    *((volatile u8 *)27) /*ADC Multiplexer Selection Register */

#define ADMUX_REFS1   7  /*Reference Selection Bit 1*/  
#define ADMUX_REFS0   6    /*Reference Selection Bit 0*/ 
#define ADMUX_ADLAR   5    /*ADC Left Adjust Result */  
#define ADMUX_MUX4    4  
#define ADMUX_MUX3    3
#define ADMUX_MUX2    2
#define ADMUX_MUX1    1
#define ADMUX_MUX0    0 


#define IDLE      0
#define BUSY      1
     

#define ADCSRA    *((volatile u8 *)26) 
#define ADCSRA_ADEN     7    
#define ADCSRA_ADSC     6 
#define ADCSRA_ADATE    5
#define ADCSRA_ADIF     4 /* Interrupt Flag */
#define ADCSRA_ADIE     3 /* Interrupt Enable */
#define ADCSRA_ADPS2    2 /* Prscaler Bit 2 */
#define ADCSRA_ADPS1    1 /* Prscaler Bit 1 */
#define ADCSRA_ADPS0    0 /* Prscaler Bit 0 */

#define ADCH    *((volatile u8 *)25) /* ADC_HIGH_REGISTER */

#define ADC    *((volatile u16 *)24) /* ADC_LOW_REGISTER */


#define SFIOR  *((volatile u8 *)50)


#define ADTS2      7

#define ADTS1      6

#define ADTS0      5







#endif