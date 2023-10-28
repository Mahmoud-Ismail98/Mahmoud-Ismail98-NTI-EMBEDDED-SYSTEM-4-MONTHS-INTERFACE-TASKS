/*
=======================================================================================================================
Author       : Mamoun
Module       : USART
File Name    : usart_cfg.h
Date Created : Oct 28, 2023
Description  : Configuration file for the ATmega32 USART driver.
=======================================================================================================================
*/


#ifndef MCAL_USART_INCLUDES_USART_CFG_H_
#define MCAL_USART_INCLUDES_USART_CFG_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* The USART only has two API interface modes: [USART_USING_POLLING - USART_USING_INTERRUPT]. */
#define USART_API_INTERFACE_MODE                              (USART_USING_INTERRUPT)

/* The USART message terminator. when it received, the communnication will be terminated [In polling interface]. */
#define USART_MESSAGE_TERMINATOR                              ';'

#endif /* MCAL_USART_INCLUDES_USART_CFG_H_ */
