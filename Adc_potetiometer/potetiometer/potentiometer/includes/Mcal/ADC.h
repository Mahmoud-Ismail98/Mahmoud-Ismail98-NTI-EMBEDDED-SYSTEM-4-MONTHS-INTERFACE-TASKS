/*
 * ADC.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef MCAL_ADC_H_
#define MCAL_ADC_H_

#include"../Services/common_macros.h"
#include"../Services/std_types.h"
#include"ADC_cfg.h"
#include"ADC_prv.h"
#include"port.h"
#include"dio.h"

typedef enum
{
	ADC_OK,
	pin_error,
	refVoltage_error,
	highFreq_error,
	lowFreq_arror
}ADC_errorStatus;

#define AREF_VOLTAGE                 0
#define AVCC_VOLTAGE                 1
#define INTERNAL_VOLTAGE             3

#define ADC_MIN_FREQ                 50000
#define ADC_MAX_FREQ                 200000
#define ADC_MAX_INPUT_VOLTAGE        5
#define MAX_PIN_ID                   7

#define ADC_PERCISION               1024

#define ADC_PIN0                   PORT_PIN0_ID
#define ADC_PIN1                   PORT_PIN1_ID
#define ADC_PIN2                   PORT_PIN2_ID
#define ADC_PIN3                   PORT_PIN3_ID
#define ADC_PIN4                   PORT_PIN4_ID
#define ADC_PIN5                   PORT_PIN5_ID
#define ADC_PIN6                   PORT_PIN6_ID
#define ADC_PIN7                   PORT_PIN7_ID

#define ADC_PRESC_2                  0
#define ADC_PRESC_4                  2
#define ADC_PRESC_8                  3
#define ADC_PRESC_16                 4
#define ADC_PRESC_32                 5
#define ADC_PRESC_64                 6
#define ADC_PRESC_128                7

#define BIT_NU0                      0
#define BIT_NU1                      1
#define BIT_NU2                      2
#define BIT_NU3                      3
#define BIT_NU4                      4
#define BIT_NU5                      5
#define BIT_NU6                      6
#define BIT_NU7                      7

#define ADLAR        BIT_NU5
#define ADEN         BIT_NU7
#define ADSC         BIT_NU6
#define ADATE        BIT_NU5
#define ADIF         BIT_NU4
#define ADIE         BIT_NU3

#define MAX_FREQUENCY                16000000
#define MID_FREQUENCY                8000000
#define MIN_FREQUENCY                1000000

void ADC_init(void);

ADC_errorStatus ADC_readChannel(u8 pin_id);

void ADC_setCallBack(void(*loc_ADCClbk_ptr)(void));

void ADC_disable(void);

#endif /* MCAL_ADC_H_ */
