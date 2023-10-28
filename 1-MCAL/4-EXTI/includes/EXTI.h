/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : EXTI                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef EXTI_H
#define EXTI_H

#define EXTI_LOW_LEVEL      1
#define EXTI_RISING_EDGE    2
#define EXTI_FALLING_EDGE   3
#define EXTI_ON_CHANGE      4

#define EXTI_ENABLE         1
#define EXTI_DISABLE        2

#define INT0                6
#define INT1                7
#define INT2                5

/**
 * EXTI0 Configurations. 
 */
typedef struct 
{
    /*
        OPTIONS : 
            1- EXTI_ENABLE
            2- EXTI_DISABLE
    */
    u8 EXTI_OPERATION ;
    /*
        OPTIONS : 
            1- EXTI_LOW_LEVEL 
            2- EXTI_RISING_EDGE
            3- EXTI_FALLING_EDGE
            4- EXTI_ON_CHANGE
    */
    u8 EXTI_SENSE_CONTROL;
}EXTI0_CFG;

/**
 * EXTI1 Configurations. 
 */
typedef struct 
{
    /*
        OPTIONS : 
            1- EXTI_ENABLE
            2- EXTI_DISABLE
    */
    u8 EXTI_OPERATION ;
    /*
        OPTIONS : 
            1- EXTI_LOW_LEVEL 
            2- EXTI_RISING_EDGE
            3- EXTI_FALLING_EDGE
            4- EXTI_ON_CHANGE
    */
    u8 EXTI_SENSE_CONTROL;
}EXTI1_CFG;

/**
 * EXTI2 Configurations. 
 */
typedef struct 
{
    /*
        OPTIONS : 
            1- EXTI_ENABLE
            2- EXTI_DISABLE
    */
    u8 EXTI_OPERATION ;
    /*
        OPTIONS : 
            1- EXTI_LOW_LEVEL 
            2- EXTI_RISING_EDGE
            3- EXTI_FALLING_EDGE
            4- EXTI_ON_CHANGE
    */
    u8 EXTI_SENSE_CONTROL;
}EXTI2_CFG;

/**
 * This function is Initialize all external interrupts pins. 
 */
void EXTI_voidInit(void);

/**
 * This function is used to Initialize EXTI0. 
 * 
 * @param EXTI0_cfg represents the EXTI0 Configurations.
 */
void EXTI0_voidInit(EXTI0_CFG* EXTI0_cfg);

/**
 * This function is used to Initialize EXTI1. 
 * 
 * @param EXTI1_cfg represents the EXTI1 Configurations.
 */
void EXTI1_voidInit(EXTI1_CFG* EXTI1_cfg);

/**
 * This function is used to Initialize EXTI2. 
 * 
 * @param EXTI2_cfg represents the EXTI2 Configurations.
 */
void EXTI2_voidInit(EXTI2_CFG* EXTI2_cfg);

/**
 * This function is used to set the callback function for EXTI0. 
 * 
 * @param Copy_pvInt0Func pointer to the callback function.
 * 
 * @return an enum which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus EXTI_enuErrorStateInt0SetCallBack(void (*Copy_pvInt0Func)(void));

/**
 * This function is used to set the callback function for EXTI2. 
 * 
 * @param Copy_pvInt2Func pointer to the callback function.
 * 
 * @return an enum which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus EXTI_enuErrorStateInt1SetCallBack(void (*Copy_pvInt1Func)(void));

/**
 * This function is used to set the callback function for EXTI2. 
 * 
 * @param Copy_pvInt2Func pointer to the callback function.
 * 
 * @return an enum which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus EXTI_enuErrorStateInt2SetCallBack(void (*Copy_pvInt2Func)(void));

#endif