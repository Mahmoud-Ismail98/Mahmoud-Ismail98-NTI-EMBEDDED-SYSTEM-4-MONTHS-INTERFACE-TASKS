/*
 * dio.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef DIO_H_
#define DIO_H_

#include"../Services/std_types.h"
#include"../Services/common_macros.h"
#include"dio_prv.h"
#include"dio_cfg.h"
#include"port.h"

/*ERROR TYPES*/
typedef enum
{
	Dio_Ok,
	Dio_pinError,
	Dio_levelError,
	Dio_directionError,
	Dio_NullPointerError,
	Dio_portError
}DIO_errorStatus;

/*LIST OF OPTIONS TO THE USER TO SET value*/
#define DIO_HIGH				1
#define DIO_LOW					0

/*ports macros*/
#define DIO_PORTA                   0
#define DIO_PORTB                   1
#define DIO_PORTC                   2
#define DIO_PORTD                   3


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

DIO_errorStatus dio_writePin(u8 pin_id, u8 value);
u8 dio_readPin(u8 pin_id);
DIO_errorStatus dio_writePort(u8 port_id, u8 value);
DIO_errorStatus dio_readPort(u8 port_id, pu8 level);
DIO_errorStatus dio_tooglePin(u8 pin_id);


#endif /* DIO_H_ */
