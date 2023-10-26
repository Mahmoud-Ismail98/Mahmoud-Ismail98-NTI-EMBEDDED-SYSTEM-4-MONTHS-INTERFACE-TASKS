/*
 * 7_seg_.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef HAL_SEVENSEG_H_
#define HAL_SEVENSEG_H_

#include"../Mcal/dio.h"
#include"../Mcal/port.h"
#include"sevenSeg_prv.h"
#include"sevenSeg_cfg.h"
#include"../Services/common_macros.h"
#include"../Services/std_types.h"

/*display number macros*/
#define SEVENSEG_ZERO        (0x7E)
#define SEVENSEG_ONE         (0x0C)
#define SEVENSEG_TWO         (0xB6)
#define SEVENSEG_THREE       (0x9E)
#define SEVENSEG_FOUR        (0xCC)
#define SEVENSEG_FIVE        (0xDA)
#define SEVENSEG_SIX         (0xFA)
#define SEVENSEG_SEVEN       (0x0E)
#define SEVENSEG_EIGHT       (0xFE)
#define SEVENSEG_NINE        (0xCE)

/*display by decoder macro*/
#define DISPLAY_DECODER(REG,VALUE)         (REG = ( (REG & 0XF0) | (VALUE & 0X0F) ) )

/*macros for min and max number could be displayed*/
#define MAX_DISPLAY_NUM          9
#define MIN_DISPLAY_NUM          0

/*functions prototypes*/
void SevenSegment_Display(u8 value);
#endif /* HAL_SEVENSEG_H_ */
