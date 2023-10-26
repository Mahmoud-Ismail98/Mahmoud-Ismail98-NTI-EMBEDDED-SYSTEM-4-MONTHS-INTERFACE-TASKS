/*
 * KeyPad_prv.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Ismail
 */

#ifndef HAL_KEYPAD_KEYPAD_PRV_H_
#define HAL_KEYPAD_KEYPAD_PRV_H_
#include"../../Services/Std_types.h"
u8 KeyPadSwitchValues[4][4] = {
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

struct bits {
  u8 b0:1;
  u8 b1:1;
  u8 b2:1;
  u8 b3:1;
  u8 b4:1;
  u8 b5:1;
  u8 b6:1;
  u8 b7:1;
} __attribute__((__packed__));

#define SBIT(port,pin) ((*(volatile struct bits*)&port).b##pin)

#define C4 30
#define C3 29
#define C2 28
#define C1 27

/******** Rows Definition *********/
/* RANGE : DIO_enuPin0 -----> DIO_enuPin31 */
#define R4 21
#define R3 20
#define R2 19
#define R1 18

u8 u8ColArr[4] = {C1, C2, C3, C4};
u8 u8RowArr[4] = {R1, R2, R3, R4};
#define KEYPADSIZE 4



#endif /* HAL_KEYPAD_KEYPAD_PRV_H_ */
