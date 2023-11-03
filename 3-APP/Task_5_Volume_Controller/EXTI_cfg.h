/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : EXTI                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef EXTI_CFG_H
#define EXTI_CFG_H

/*
    OPTIONS : 
        1- EXTI_ENABLE
        2- EXTI_DISABLE
*/


#define EXTI0_OPERATION                     EXTI_DISABLE
#define EXTI1_OPERATION                     EXTI_ENABLE
#define EXTI2_OPERATION                     EXTI_DISABLE


/*
    OPTIONS : 
        1- EXTI_LOW_LEVEL 
        2- EXTI_RISING_EDGE
        3- EXTI_FALLING_EDGE
        4- EXTI_ON_CHANGE
*/

#define EXTI0_SENSE_CONTROL                 EXTI_FALLING_EDGE
#define EXTI1_SENSE_CONTROL                 EXTI_FALLING_EDGE
#define EXTI2_SENSE_CONTROL                 EXTI_FALLING_EDGE



#endif
