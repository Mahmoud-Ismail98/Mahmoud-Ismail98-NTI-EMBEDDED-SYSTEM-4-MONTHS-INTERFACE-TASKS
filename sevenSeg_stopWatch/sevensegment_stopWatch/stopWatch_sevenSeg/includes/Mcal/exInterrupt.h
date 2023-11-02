/*
 * exInterrupt.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef MCAL_EXINTERRUPT_H_
#define MCAL_EXINTERRUPT_H_

#include"port.h"
#include"dio.h"
#include"exInterrupt_prv.h"
#include"exInterrupt_cfg.h"
#include"../Services/std_types.h"
#include"../Services/common_macros.h"

#define INDEX_ZERO                  0
#define INDEX_ONE                   1
#define INDEX_TWO                   2

#define NUM_OF_CONFIGS              2

#define LOW_LEVEL_INT_REQ           0
#define LOGICAL_CHANGE_INT_REQ      1
#define FALLING_EDGE_INT_REQ        2
#define RISING_EDGE_INT_REQ         3


#define BIT_0   0
#define BIT_1   1
#define BIT_2   2
#define BIT_3   3
#define BIT_4   4
#define BIT_5   5
#define BIT_6   6
#define BIT_7   7

typedef enum
{
	EXint_OK,
	EXint_configError
}EXint_statusError;

void callBack(void(*loc_clbk_ptr)(void), u8 index);
void exInt0_enable(u8 trigger);
void exInt0_disable(void);

void exInt1_enable(u8 trigger);
void exInt1_disable(void);

void exInt2_enable(u8 trigger);
void exInt2_disable(void);

#endif /* MCAL_EXINTERRUPT_H_ */
