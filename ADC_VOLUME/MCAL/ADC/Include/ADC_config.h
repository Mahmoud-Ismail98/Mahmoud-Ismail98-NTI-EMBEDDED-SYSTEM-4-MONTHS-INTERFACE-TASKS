/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 23 Oct 2023                                                           */
/************************************************************************************/
#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/* configuration of the input voltage to ADC */
/*      Options: ADC_REF_VOLT
                 ADC_VCC_VOLT
                 ADC_INT_VOLT                */
#define ADC_u8_VOLTAGE       ADC_VCC_VOLT

/* configuration of selection the adjust */
/*      Options: ADC_RIGHT_ADJUST
                 ADC_LEFT_ADJUST         */
#define ADC_u8_ADJUSR       ADC_RIGHT_ADJUST

/* configuration of selection the adjust */
/*      Options: ADC_SINGLE_MODE
                 ADC_FREE_RUNNING_MODE         */
#define ADC_u8_MODE       ADC_SINGLE_MODE

/* Macros for time out mechanism */
#define ADC_TIMEOUT_MECHANISM             50000

#endif
