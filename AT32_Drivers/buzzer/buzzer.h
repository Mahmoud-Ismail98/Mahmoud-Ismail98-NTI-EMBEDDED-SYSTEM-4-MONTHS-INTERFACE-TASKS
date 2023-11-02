/*
 * BUZZER.h
 *
 *  Created on: Aug 5, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include"../Mcal/timer.h"
#include"../Mcal/dio.h"
#include"../Mcal/port.h"
#include"../Services/std_types.h"
#include"../Services/common_macros.h"

#define BUZZER_PIN         PORT_PIN16_ID


/*
 * Setup the direction for the buzzer pin as output pin through the GPIO driver
 * Turn off the buzzer through the GPIO
*/
void Buzzer_init(void);

/*Function to enable the Buzzer through the GPIO*/
void Buzzer_on(void);

/*Function to disable the Buzzer through the GPIO*/
void Buzzer_off(void);

#endif /* BUZZER_H_ */
