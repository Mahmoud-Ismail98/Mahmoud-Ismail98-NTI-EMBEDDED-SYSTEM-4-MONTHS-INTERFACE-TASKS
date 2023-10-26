/*
 * port_config.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

/*
 * LIST OF OPTIONS TO THE USER
 *
 *PIN_OUTPUT_LOW
 *PIN_OUTPUT_HIGH
 *PIN_INPUT_PULL UP
 *PIN_INPUT_FLOATING
 * */

/*PORTA PINS*/
#define DIO_u8_PIN0       PIN_OUTPUT_LOW
#define DIO_u8_PIN1       PIN_OUTPUT_HIGH
#define DIO_u8_PIN2       PIN_OUTPUT_HIGH
#define DIO_u8_PIN3       PIN_OUTPUT_HIGH
#define DIO_u8_PIN4       PIN_OUTPUT_HIGH
#define DIO_u8_PIN5       PIN_OUTPUT_HIGH
#define DIO_u8_PIN6       PIN_OUTPUT_HIGH
#define DIO_u8_PIN7       PIN_OUTPUT_HIGH


/*PORTB PINS*/
#define DIO_u8_PIN8       PIN_OUTPUT_LOW
#define DIO_u8_PIN9       PIN_OUTPUT_LOW
#define DIO_u8_PIN10      PIN_OUTPUT_LOW
#define DIO_u8_PIN11      PIN_OUTPUT_LOW
#define DIO_u8_PIN12      PIN_OUTPUT_LOW
#define DIO_u8_PIN13      PIN_OUTPUT_LOW
#define DIO_u8_PIN14      PIN_OUTPUT_LOW
#define DIO_u8_PIN15      PIN_OUTPUT_LOW

/*PORTC PINS*/
#define DIO_u8_PIN16      PIN_OUTPUT_LOW
#define DIO_u8_PIN17      PIN_OUTPUT_LOW
#define DIO_u8_PIN18      PIN_OUTPUT_LOW
#define DIO_u8_PIN19      PIN_OUTPUT_LOW
#define DIO_u8_PIN20      PIN_OUTPUT_LOW
#define DIO_u8_PIN21      PIN_OUTPUT_LOW
#define DIO_u8_PIN22      PIN_OUTPUT_LOW
#define DIO_u8_PIN23      PIN_OUTPUT_LOW

/*PORTD PINS*/
#define DIO_u8_PIN24      PIN_OUTPUT_LOW
#define DIO_u8_PIN25      PIN_OUTPUT_LOW
#define DIO_u8_PIN26      PIN_INPUT_FLOATING
#define DIO_u8_PIN27      PIN_INPUT_FLOATING
#define DIO_u8_PIN28      PIN_INPUT_FLOATING
#define DIO_u8_PIN29      PIN_OUTPUT_LOW
#define DIO_u8_PIN30      PIN_OUTPUT_LOW
#define DIO_u8_PIN31      PIN_OUTPUT_LOW

#endif /* PORT_CONFIG_H_ */
