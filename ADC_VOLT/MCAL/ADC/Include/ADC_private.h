/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 23 Oct 2023                                                           */
/************************************************************************************/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* Registers Definition */
#define ADC_u8_ADMUX_REG                *((volatile u8 *)0x27)
#define ADC_u8_ADCSRA_REG               *((volatile u8 *)0x26)
#define ADC_u8_ADCL_REG                 *((volatile u8 *)0x24)
#define ADC_u8_ADCH_REG                 *((volatile u8 *)0x25)
#define ADC_u16_ADC_REG                 *((volatile u16 *)0x24)
#define ADC_u8_SFIOR_REG                *((volatile u8 *)0x50)

/* Macros for Register's Bits */
// ADMUX
#define ADC_u8_MUX0_BIT               0
#define ADC_u8_MUX1_BIT               1
#define ADC_u8_MUX2_BIT               2
#define ADC_u8_MUX3_BIT               3
#define ADC_u8_MUX4_BIT               4
#define ADC_u8_ADLAR_BIT              5
#define ADC_u8_REFS0_BIT              6
#define ADC_u8_REFS1_BIT              7
// ADCSRA
#define ADC_u8_ADPS0_BIT              0
#define ADC_u8_ADPS1_BIT              1
#define ADC_u8_ADPS2_BIT              2
#define ADC_u8_ADIE_BIT               3
#define ADC_u8_ADIF_BIT               4
#define ADC_u8_ADATE_BIT              5
#define ADC_u8_ADSC_BIT               6
#define ADC_u8_ADEN_BIT               7
// SFIOR
#define ADC_u8_PSR10_BIT              0
#define ADC_u8_PSR2_BIT               1
#define ADC_u8_PUD_BIT                2
#define ADC_u8_ACME_BIT               3
#define ADC_u8_ADTS0_BIT              5
#define ADC_u8_ADTS1_BIT              6
#define ADC_u8_ADTS2_BIT              7

/* Macros for voltages */
#define ADC_VCC_VOLT                  0
#define ADC_REF_VOLT                  1
#define ADC_INT_VOLT                  2

/* Macros for adjust */
#define ADC_RIGHT_ADJUST              0
#define ADC_LEFT_ADJUST               1

/* Macros for start conversion */
#define ADC_SINGLE_MODE               0
#define ADC_FREE_RUNNING_MODE         1


#endif