/*
 * SevenSegment.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Ismail
 */

#ifndef HAL_SEVENSEGMENT_SEVENSEGMENT_H_
#define HAL_SEVENSEGMENT_SEVENSEGMENT_H_
#include"../../Services/Bit_utils.h"
#include"../../Services/Std_types.h"
#define SEVEN_SEG_ON 1
#define SEVEN_SEG_OFF 0



typedef struct
{
	u8 PinEnPort;
	u8 PinEn;
	u8 PinAport;
	u8 PinA;
	u8 PinBport;
	u8 PinB;
	u8 PinCport;
	u8 PinC;
	u8 PinDport;
	u8 PinD;

}SevenSeg_t;

#endif /* HAL_SEVENSEGMENT_SEVENSEGMENT_H_ */
