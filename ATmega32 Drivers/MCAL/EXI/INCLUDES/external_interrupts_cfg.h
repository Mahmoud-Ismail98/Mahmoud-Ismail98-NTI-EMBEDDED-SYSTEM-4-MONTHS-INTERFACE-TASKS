/*
=======================================================================================================================
Author       : Mamoun
Module       : External Interrupt
File Name    : external_interrupts_cfg.h
Date Created : Oct 22, 2023
Description  : Configuration file for the ATmega32 External Interrupt driver.
=======================================================================================================================
*/


#ifndef MCAL_EXI_INCLUDES_EXTERNAL_INTERRUPTS_CFG_H_
#define MCAL_EXI_INCLUDES_EXTERNAL_INTERRUPTS_CFG_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* Choose the status of every external interrupt from: [EXI_INT_ENABLE - EXI_INT_DISABLE]. */
#define EXI_INT0_STATUS                              (EXI_INT_DISABLE)
#define EXI_INT1_STATUS                              (EXI_INT_DISABLE)
#define EXI_INT2_STATUS                              (EXI_INT_ENABLE)

/* Choose the mode of every external interrupt from: [EXI_LOW_LEVEL - EXI_ANY_LOGICAL_CHANGE - EXI_FALLING_EDGE - EXI_RISING_EDGE]. */
#define EXI_INT0_TRIGGER_MODE                        (EXI_RISING_EDGE)
#define EXI_INT1_TRIGGER_MODE                        (EXI_RISING_EDGE)
#define EXI_INT2_TRIGGER_MODE                        (EXI_RISING_EDGE)

#endif /* MCAL_EXI_INCLUDES_EXTERNAL_INTERRUPTS_CFG_H_ */
