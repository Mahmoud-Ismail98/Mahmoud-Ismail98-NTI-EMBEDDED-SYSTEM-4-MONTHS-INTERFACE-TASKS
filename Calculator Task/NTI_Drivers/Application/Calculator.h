/*
 * Calculator.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Ismail
 */

#ifndef APPLICATION_CALCULATOR_H_
#define APPLICATION_CALCULATOR_H_
#include "../Services/Std_types.h"
#include"../HAL/LCD/LCD.h"
#include <util/delay.h>

#define Error   13

u16 GetNumber(u8 num);
u8 GetOperation(u8 Op);
void DispError(u16 error );
void DispNumber(s16 num);

#endif /* APPLICATION_CALCULATOR_H_ */
