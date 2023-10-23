/*
 * KeyPad_cfg.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Ismail
 */

#ifndef HAL_KEYPAD_KEYPAD_CFG_H_
#define HAL_KEYPAD_KEYPAD_CFG_H_

#include"../../Services/Bit_utils.h"
#include"../../Services/Std_types.h"
#include"../../MCAL/PORT/PORT.h"
#include"../../MCAL/DIO/DIO.h"
#define HKPD_COLUMN_PORT  PORTD
#define HKPD_ROW_PORT PORTC
#define KEYPAD_NOT_PRESSED 255
#define HKPD_ROW_START	18
#define HKPD_COL_START	27	/** THE REAL PIN NUMBER**/
#define HKPD_ROW_END	21
#define HKPD_COL_END	30

#endif /* HAL_KEYPAD_KEYPAD_CFG_H_ */
