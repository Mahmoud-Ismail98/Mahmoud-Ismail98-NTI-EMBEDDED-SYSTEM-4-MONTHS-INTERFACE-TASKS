/*
 * EXIT.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Online
 */

#ifndef COTS_1_MCAL_5_EXIT_INCLUDE_EXIT_H_
#define COTS_1_MCAL_5_EXIT_INCLUDE_EXIT_H_

/********************************************************************/
/*********************** REGISTERS ********************************/

#define ADMUX      *((volatile u8*)0x27)
#define ADMUX_REFS1        7
#define ADMUX_REFS0        6
#define ADMUX_ADLAR        5



#define ADCSRA 		 *((volatile u8 *)0x26)
#define ADCSRA_ADEN          7
#define ADCSRA_ADSC          6
#define ADCSRA_ADATE         5
#define ADCSRA_ADIF          4
#define ADCSRA_ADIE          3
#define ADCSRA_ADPS2         2
#define ADCSRA_ADPS1         1
#define ADCSRA_ADPS0         0

#define ADCH   		 *((volatile u8*)0x25)
#define ADCH_ADC9 			15
#define ADCH_ADC8			14
#define ADCH_ADC7			13
#define ADCH_ADC6			12
#define ADCH_ADC5			11
#define ADCH_ADC4			10
#define ADCH_ADC3			9
#define ADCH_ADC2			8

#define ADCL		*((volatile u8*)0x24)
#define ADCL_ADC1 	 	    7
#define ADCL_ADC0 		    6

/********************************************************************/
/*********************** ADC CHANNALS ******************************/

#define SingleEnded_ADC0           00000
#define SingleEnded_ADC1    	   00001
#define SingleEnded_ADC2   		   00010
#define SingleEnded_ADC3     	   00011
#define SingleEnded_ADC4     	   00100
#define SingleEnded_ADC5     	   00101
#define SingleEnded_ADC6     	   00110
#define SingleEnded_ADC7     	   00111

/********************************************************************/
/*********************** ERROR STATES ********************************/
typedef enum {
ADC_EnmOk ,
ADC_EnmError,
ADC_EnmAdjustError,
ADC_EnmVoltageError
}ADC_tenuErrorStatus;

/********************************************************************/
/************************* PROTOTYPES ******************************/

void ADC_voidInit(void);
ADC_tenuErrorStatus ADC_u8StartConversionSynch(u8 Copy_u8Channal, pu8 Copy_pu8Reading);
ADC_tenuErrorStatus ADC_u8StartConversionAsynch(u8 Copy_u8Channal, pu8 Copy_pu8Reading, void (*Copy_VNatifacationFunc)(void));

#endif /* COTS_1_MCAL_5_EXIT_INCLUDE_EXIT_H_ */






