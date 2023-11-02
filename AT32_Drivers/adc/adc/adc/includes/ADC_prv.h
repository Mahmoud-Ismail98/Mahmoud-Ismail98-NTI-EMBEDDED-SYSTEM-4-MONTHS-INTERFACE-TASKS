/*
 * ADC_prv.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef MCAL_ADC_PRV_H_
#define MCAL_ADC_PRV_H_

#define ADC_MIN_REQ       50
#define ADC_MAX_REQ       200

#define ADC_PORT          DIO_PORTA

#define ADMUX         ( *( (volatile u8*)0x27) )
#define ADCSRA        ( *( (volatile u8*)0x26) )
#define ADCH          ( *( (volatile u8*)0x25) )

#endif /* MCAL_ADC_PRV_H_ */
