/*
 * 7_seg.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Dwidar
 */
#include"sevenSeg.h"
#include"sevenSeg_cfg.h"

void SevenSegment_Display(u8 number)
{
#if(DECODER_USE == TRUE)
	DISPLAY_DECODER(SEVENSEG_PORT,number);
#else

		switch(number)
		{
		case 0:
			SEVENSEG_PORT = SEVENSEG_ZERO;
			break;
		case 1:
			SEVENSEG_PORT = SEVENSEG_ONE;
			break;
		case 2:
			SEVENSEG_PORT = SEVENSEG_TWO;
			break;
		case 3:
			SEVENSEG_PORT = SEVENSEG_THREE;
			break;
		case 4:
			SEVENSEG_PORT = SEVENSEG_FOUR;
			break;
		case 5:
			SEVENSEG_PORT = SEVENSEG_FIVE;
			break;
		case 6:
			SEVENSEG_PORT = SEVENSEG_SIX;
			break;
		case 7:
			SEVENSEG_PORT = SEVENSEG_SEVEN;
			break;
		case 8:
			SEVENSEG_PORT = SEVENSEG_EIGHT;
			break;
		case 9:
			SEVENSEG_PORT = SEVENSEG_NINE;
			break;
		}

#endif
}

