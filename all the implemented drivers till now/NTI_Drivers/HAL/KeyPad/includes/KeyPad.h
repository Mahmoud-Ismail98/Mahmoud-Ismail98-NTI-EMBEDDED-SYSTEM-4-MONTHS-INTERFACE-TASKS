/*
 * KeyPad.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Ismail
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_
#include"../../../Services/Std_types.h"

/*Prototypes for The Functions*/

void KeyPadInit(void);
void KeyPad_GetPressedButton(u8 *u8PtrToPressedButton);
u8 keypressed(void);
#endif /* HAL_KEYPAD_KEYPAD_H_ */
