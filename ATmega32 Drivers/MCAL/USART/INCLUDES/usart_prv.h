/*
=======================================================================================================================
Author       : Mamoun
Module       : USART
File Name    : usart_prv.h
Date Created : Oct 28, 2023
Description  : Private file for the ATmega32 USART driver.
=======================================================================================================================
*/


#ifndef MCAL_USART_INCLUDES_USART_PRV_H_
#define MCAL_USART_INCLUDES_USART_PRV_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* USART API interface modes: [Interrupt or Polling]. */
#define USART_USING_POLLING                                (0U)
#define USART_USING_INTERRUPT                              (1U)

/*=====================================================================================================================
                                         < Function-like Macros >
=====================================================================================================================*/

#define USART_SET_RECEIVER_STATUS(STATUS)          (UCSRB = ((UCSRB & 0XEF) | ((STATUS & 0X01) << RXEN)))
#define USART_SET_TRANSMITTER_STATUS(STATUS)       (UCSRB = ((UCSRB & 0XF7) | ((STATUS & 0X01) << TXEN)))
#define USART_ENABLE_DOUBLE_BAUD_RATE(STATUS)      (UCSRA = ((UCSRA & 0XFD) | ((STATUS & 0X01) << U2X)))
#define USART_SET_COMMUNICATION_MODE(MODE)         (UCSRC = ((UCSRC & 0XBF) | ((MODE & 0X01) << UMSEL) | (0X80)))
#define USART_SET_PARITY_MODE(MODE)                (UCSRC = ((UCSRC & 0XCF) | ((MODE & 0X03) << UPM0) | (0X80)))
#define USART_SET_DATA_BITS_SIZE()                 (UCSRC = ((UCSRC & 0XF9) | (0X03 << UCSZ0) | (0X80)))
#define USART_SET_STOP_BIT_SIZE()                  (UCSRC = (UCSRC & 0XF7) | (0X80))
#define USART_SET_UBRRL_REGISTER(VALUE)            (UBRRL = (VALUE & 0X00FF))
#define USART_SET_UBRRH_REGISTER(VALUE)            (UBRRH = ((VALUE & 0X0F00) >> 8))

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/



#endif /* MCAL_USART_INCLUDES_USART_PRV_H_ */
