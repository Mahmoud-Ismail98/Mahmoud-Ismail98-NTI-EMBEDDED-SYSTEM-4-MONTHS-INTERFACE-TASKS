/*
 * KeyPad_prv.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Ismail
 */

#ifndef HAL_KEYPAD_KEYPAD_PRV_H_
#define HAL_KEYPAD_KEYPAD_PRV_H_
#include "KeyPad_cfg.h"
#define C4 HKPD_COL_END
#define C3 HKPD_COL_START+2
#define C2 HKPD_COL_START+1
#define C1 HKPD_COL_START

/******** Rows Definition *********/
/* RANGE : DIO_enuPin0 -----> DIO_enuPin31 */
#define R4 HKPD_ROW_END
#define R3 HKPD_ROW_START+2
#define R2 HKPD_ROW_START+1
#define R1 HKPD_ROW_START

#define KEYPADSIZE 4
u8 u8ColArr[4] = {C1, C2, C3, C4};
u8 u8RowArr[4] = {R1, R2, R3, R4};

#endif /* HAL_KEYPAD_KEYPAD_PRV_H_ */
