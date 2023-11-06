/*
 * GIE.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Online
 */

#ifndef COTS_1_MCAL_4_GIE_INCLUDE_GIE_H_
#define COTS_1_MCAL_4_GIE_INCLUDE_GIE_H_



#define SREG            *((volatile u8*)0x5F)
#define SREG_I               7
void GIE_VidInit(void);

#endif /* COTS_1_MCAL_4_GIE_INCLUDE_GIE_H_ */
