/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : ADC                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef ADC_CFG_H
#define ADC_CFG_H

/** Options
 *      ADC_REFERENCE_AREF_Internal_Vref_turned_off                   
 *      ADC_REFERENCE_AVCC_with_external_capacitor_at_AREF_pin        
 *      ADC_REFERENCE_Internal_Voltage                                
 */
#define ADC_REFERENCE       ADC_REFERENCE_Internal_Voltage

/** Options
 *      ADC_RIGHT_ADJUST                   
 *      ADC_LEFT_ADJUST        
 */
#define ADC_ADJUST          ADC_LEFT_ADJUST

#endif
