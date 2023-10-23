/*
 * SegBCD.h
 *
 * Created: 10/21/2023 9:29:51 AM
 *  Author: Wael
 */ 


#ifndef SEGBCD_H_
#define SEGBCD_H_

#include "Port.h"
#include "Dio.h"
#include "Std_types.h"
#include "Bit_utils.h"

#define F_CPU 16000000
#include "util/delay.h"
 /*Customized to eta32 board*/

#define BCD_BIT0 DIO_u8CHANNEL08
#define BCD_BIT1 DIO_u8CHANNEL09
#define BCD_BIT2 DIO_u8CHANNEL10
#define BCD_BIT3 DIO_u8CHANNEL12

#define SEG1_COM DIO_u8CHANNEL03
#define SEG2_COM DIO_u8CHANNEL02
#define SEG3_COM DIO_u8CHANNEL13
#define SEG4_COM DIO_u8CHANNEL14



void SegBCD_vInit(void);

void SegBSD_vWriteVal(u8 Copy_u8Num);

void SegBSD_vWriteValMUX(u32 Copy_u32Num);

u8 Choose_Seg(u8 num);

		 void SegBSD_vTime(void);


#endif /* SEGBCD_H_ */