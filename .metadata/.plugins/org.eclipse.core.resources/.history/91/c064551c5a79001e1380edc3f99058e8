#ifndef ADC_PRV_H_
#define ADC_PRV_H_
            
			

#define ADMUX  *((volatile u8*)0x27)			
#define ADCSRA  *((volatile u8*)0x26)			
#define ADCH  *((volatile u8*)0x25)			
#define ADCL  *((volatile u8*)0x24)			

#define ADC_DATA	*((volatile u16*)0x24)	
#define ENABLE	1
#define DISABLE 0

#define AREF_PIN		0			
#define AVCC			1			
#define internal2Volt	2

#define	PRESCALLER_2	0
#define	PRESCALLER_4	2
#define	PRESCALLER_8	3
#define	PRESCALLER_16	4
#define	PRESCALLER_32	5
#define	PRESCALLER_64	6
#define	PRESCALLER_128	7



#define ADLAR			5
#define	REFS0			6
#define REFS1			7
			

#define ADEN			7
#define ADSC			6
#define ADIF			4
#define ADIE			3

void __vector_16 (void)  __attribute__((signal));

#endif
