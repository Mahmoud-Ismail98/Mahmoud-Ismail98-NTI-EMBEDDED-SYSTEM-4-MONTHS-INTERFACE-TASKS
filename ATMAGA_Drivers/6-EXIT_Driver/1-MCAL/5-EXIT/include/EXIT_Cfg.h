/*
 * EXIT_Cfg.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Online
 */

#ifndef COTS_1_MCAL_5_EXIT_INCLUDE_EXIT_CFG_H_
#define COTS_1_MCAL_5_EXIT_INCLUDE_EXIT_CFG_H_

/* optional for interrupt
 * 1- FALLIND_EDGE
 * 2- RISING_EDGE
 * 3- LOW
 * 4- ON_CHANGE
 */
/*******************************************************************/
/********************** FOR INT0 **********************************/
#define EXTI_INT0            FALLIND_EDGE
#define EXTI_INT0_State      ENABLE


/*******************************************************************/
/********************** FOR INT1 **********************************/

#define EXTI_INT1            RISING_EDGE
#define EXTI_INT1_State      DISABLE

/*******************************************************************/
/********************** FOR INT2 **********************************/

#define EXTI_INT2          	FALLIND_EDGE
#define EXTI_INT2_State     DISABLE

#endif /* COTS_1_MCAL_5_EXIT_INCLUDE_EXIT_CFG_H_ */
