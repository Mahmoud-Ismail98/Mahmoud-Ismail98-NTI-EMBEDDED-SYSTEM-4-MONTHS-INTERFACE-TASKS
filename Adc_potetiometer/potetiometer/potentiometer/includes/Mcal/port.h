/*
 * port.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef PORT_H_
#define PORT_H_

/*INCLUDED FILES*/
#include"../Services/common_macros.h"
#include"../Services/std_types.h"
#include"port_prv.h"
#include"port_config.h"

/*ERROR TYPES*/
typedef enum
{
	port_OK,
	pinError,
	pinDirectionError
}port_errorStatus;

/*LIST OF OPTIONS TO THE USER TO SET DIRECTION*/
#define PIN_INPUT               0
#define PIN_OUTPUT              1
#define PORT_INPUT              0X00
#define PORT_OUTPUT             0xFF



/*LIST OF OPTIONS TO THE USER TO SET MODE*/
#define PIN_OUTPUT_LOW              0
#define PIN_OUTPUT_HIGH             1
#define PIN_INPUT_PULL_UP           2
#define PIN_INPUT_FLOATING          3


/*PORTA PINS*/
#define PORT_PIN0_ID                0
#define PORT_PIN1_ID                1
#define PORT_PIN2_ID                2
#define PORT_PIN3_ID                3
#define PORT_PIN4_ID                4
#define PORT_PIN5_ID                5
#define PORT_PIN6_ID                6
#define PORT_PIN7_ID                7

/*PORTB PINS*/
#define PORT_PIN8_ID                8
#define PORT_PIN9_ID                9
#define PORT_PIN10_ID               10
#define PORT_PIN11_ID               11
#define PORT_PIN12_ID               12
#define PORT_PIN13_ID               13
#define PORT_PIN14_ID               14
#define PORT_PIN15_ID               15

/*PORTC PINS*/
#define PORT_PIN16_ID               16
#define PORT_PIN17_ID               17
#define PORT_PIN18_ID               18
#define PORT_PIN19_ID               19
#define PORT_PIN20_ID               20
#define PORT_PIN21_ID               21
#define PORT_PIN22_ID               22
#define PORT_PIN23_ID               23

/*PORTD PINS*/
#define PORT_PIN24_ID               24
#define PORT_PIN25_ID               25
#define PORT_PIN26_ID               26
#define PORT_PIN27_ID               27
#define PORT_PIN28_ID               28
#define PORT_PIN29_ID               39
#define PORT_PIN30_ID               30
#define PORT_PIN31_ID               31


/*functions prototypes*/

void port_init(void);
port_errorStatus setPinDirection(u8 pin_id, u8 direction);
port_errorStatus setMode(u8 pin_id, u8 mode);

#endif /* PORT_H_ */
