/*
 * SevenSegment_prv.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Ismail
 */

#ifndef HAL_SEVENSEGMENT_SEVENSEGMENT_PRV_H_
#define HAL_SEVENSEGMENT_SEVENSEGMENT_PRV_H_



void SEVENSEGMENT_Init(SevenSeg_t* Ptr_SevenSegObj);
void SEVENSEGMENT_SetMode(SevenSeg_t* Ptr_SevenSegObj,u8 Copy_u8SevenSegMode);
void SEVENSEGMENT_Display(SevenSeg_t* Ptr_SevenSegObj,u8 Copy_u8SevenSegValue);


#endif /* HAL_SEVENSEGMENT_SEVENSEGMENT_PRV_H_ */
