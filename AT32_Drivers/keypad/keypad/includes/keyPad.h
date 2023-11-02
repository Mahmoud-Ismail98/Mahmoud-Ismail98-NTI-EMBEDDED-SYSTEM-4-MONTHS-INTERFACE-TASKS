/*
 * keyPad.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef HAL_KEYPAD_H_
#define HAL_KEYPAD_H_

#include"keyPad_cfg.h"
#include"keyPad_prv.h"
#include"../Services/common_macros.h"
#include"../Services/std_types.h"
#include"../Mcal/port.h"
#include"../Mcal/dio.h"
#include<util/delay.h>

#define KEYPAD_BUTTON_PRESSED            LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED           LOGIC_HIGH

#define PIN_STATE_INPUT                  PIN_INPUT
#define PIN_STATE_OUTPUT                 PIN_OUTPUT

u8 KEYPAD_getPressedKey(void);

#endif /* HAL_KEYPAD_H_ */
