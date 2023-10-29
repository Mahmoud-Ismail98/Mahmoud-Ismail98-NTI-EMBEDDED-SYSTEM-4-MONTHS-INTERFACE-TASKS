#ifndef INC_MCAL_ADC_ADC_CFG_H_
#define INC_MCAL_ADC_ADC_CFG_H_


/*CHOOSE
 * AREF_PIN
 * AVCC
 * internal2Volt				*/
#define	Refernce_Selection 		AVCC

/* choose 			ENABLE - DISABLE                                    */
#define	LEFT_ADJUST				DISABLE

/*please watch the Analog Channel and gain selection table*/
#define	ANALOG_CHANNELS_GAIN_SELECTION		0

/*Choose from Prescaller
 * PRESCALLER_2
 * PRESCALLER_4
 * PRESCALLER_8
 * PRESCALLER_16
 * PRESCALLER_32
 * PRESCALLER_64
 * PRESCALLER_128
 *
 * */
#define	ADC_Prescaller			PRESCALLER_2
/* choose interrpt choice 	ENABLE - DISABLE                           */
#define Interrupt_EN			ENABLE
#endif
