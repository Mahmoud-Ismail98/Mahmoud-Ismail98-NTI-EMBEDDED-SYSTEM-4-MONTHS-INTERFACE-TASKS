/*
 * EXIT_Cfg.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Online
 */

#ifndef COTS_1_MCAL_5_EXIT_INCLUDE_EXIT_CFG_H_
#define COTS_1_MCAL_5_EXIT_INCLUDE_EXIT_CFG_H_

/********************************************************************/
/******************** VOLTAGE REFERANCE ****************************/
/*
 * OPtional
 * 1- AVCC_WithExternalCapacitorAREFPin
 * 2- AREF_InternalVrefTurnedOff
 * 3- Internal2.56V_WithExternalCapacitorAtAREFPin
 */
#define Voltage_Referance    AVCC_WithExternalCapacitorAREFPin

/********************************************************************/
/*********************** LEFT ADIUST *******************************/
/*
 * OPtional
 * 1- Left_AdjustEnable
 * 2- Left_AdjustDisable
 */
#define Left_Adjust	    	 Left_AdjustEnable

/********************************************************************/
/*********************** ADC ENABLE *******************************/
/*
 * Optional
 * 1- ENABLE
 * 2-DISENABLE
 */
#define ADC_ENABLE				ENABLE

/********************************************************************/
/*********************** AUTO TRIGERRED *******************************/
/*
 * Optional
 * 1- ENABLE
 * 2- DISENABLE
 */
#define AuTRIGGER_ENABLE		 DISENABLE

/********************************************************************/
/*********************** ADC PRESCALER ******************************/
/*
 * Optional
 * 1- DIV_By_2
 * 2- DIV_By_4
 * 3- DIV_By_8
 * 4- DIV_By_16
 * 5- DIV_By_32
 * 6- DIV_By_64
 * 7- DIV_By_128
 */
#define  ADC_Prescaler            DIV_By_32

#define  ADC_u32TimeOut			  5000

#endif /* COTS_1_MCAL_5_EXIT_INCLUDE_EXIT_CFG_H_ */
