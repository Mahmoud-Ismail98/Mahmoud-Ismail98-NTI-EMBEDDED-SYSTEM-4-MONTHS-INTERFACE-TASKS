/*
 * KeyPad.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Ismail
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_
#include"KeyPad_prv.h"
#include "KeyPad_cfg.h"
u8 KeyPad_SwitchValues[4][4]={
		{'1',
		'4',
		'7',
		'*'
		},
		{		'2',
				'5',
				'8',
				'0'
				},

				{		'3',
						'6',
						'9',
						'#'
						},
				{'A',
				'B',
				'C',
				'D'
					}


};
/*Prototypes for The Functions*/
void KeyPad_Init();
void KeyPad_GetPressedButton();

#endif /* HAL_KEYPAD_KEYPAD_H_ */
