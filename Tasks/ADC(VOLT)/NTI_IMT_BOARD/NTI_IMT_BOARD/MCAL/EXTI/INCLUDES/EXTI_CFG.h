/*
 * EXTI_CFG.h
 *
 * Created: 10/22/2023 3:29:19 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_

#define EXTI_INT0    0
#define EXTI_INT1    1
#define EXTI_INT2    2

/*Set the following with 1 to enable or 0 to disable*/
#define  EXTI_Enable_INT0     1
#define  EXTI_Enable_INT1     1
#define  EXTI_Enable_INT2     1

/*1 to set the wanted mode */
#define EXTI_INT0_RISING_EDGE  0
#define EXTI_INT0_FALLING_EDGE 1
#define EXTI_INT0_ON_CHANGE    0
#define EXTI_INT0_LOW_LEVEL    1

/*1 to set the wanted mode */
#define EXTI_INT1_RISING_EDGE  0
#define EXTI_INT1_FALLING_EDGE 1
#define EXTI_INT1_ON_CHANGE    0
#define EXTI_INT1_LOW_LEVEL    0

/*1 to set the wanted mode */
#define EXTI_INT2_RISING_EDGE  0
#define EXTI_INT2_FALLING_EDGE 1






#endif /* EXTI_CFG_H_ */