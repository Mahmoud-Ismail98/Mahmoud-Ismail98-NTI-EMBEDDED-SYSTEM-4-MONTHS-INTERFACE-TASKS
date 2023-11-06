/*
=======================================================================================================================
Author       : Mamoun
Module       : GPIO
File Name    : gpio_prv.h
Date Created : Nov 6, 2023
Description  : Private file for the STM32F401 GPIO peripheral driver.
=======================================================================================================================
*/


#ifndef MCAL_GPIO_INCLUDES_GPIO_PRV_H_
#define MCAL_GPIO_INCLUDES_GPIO_PRV_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

#define GPIO_NUM_OF_PORTS                              (6)
#define GPIO_NUM_OF_PINS_PER_PORT                      (16)

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef struct
{
    volatile uint32 GPIO_MODER;
    volatile uint32 GPIO_OTYPER;
    volatile uint32 GPIO_OSPEEDR;
    volatile uint32 GPIO_PUPDR;
    volatile uint32 GPIO_IDR;
    volatile uint32 GPIO_ODR;
    volatile uint32 GPIO_BSRR;
    volatile uint32 GPIO_LCKR;
    volatile uint32 GPIO_AFRL;
    volatile uint32 GPIO_AFRH;
}GPIO_registers;

/*=====================================================================================================================
                                < Peripheral Registers and Pins Definitions >
=====================================================================================================================*/

#define GPIOA                              ((volatile GPIO_registers*)0X40020000)
#define GPIOB                              ((volatile GPIO_registers*)0X40020400)
#define GPIOC                              ((volatile GPIO_registers*)0X40020800)
#define GPIOD                              ((volatile GPIO_registers*)0X40020C00)
#define GPIOE                              ((volatile GPIO_registers*)0X40021000)
#define GPIOH                              ((volatile GPIO_registers*)0X40021C00)

/*=====================================================================================================================
                                         < Function-like Macros >
=====================================================================================================================*/



/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/



#endif /* MCAL_GPIO_INCLUDES_GPIO_PRV_H_ */
