/*
 * SegBCD.h
 *
 * Created: 10/21/2023 9:29:51 AM
 *  Author: Ahmed Wael
 */

#ifndef SEGBCD_H_
#define SEGBCD_H_

#include "Std_types.h"
#include "Bit_utils.h"

#include "../MCAL/Port/inc/Port.h"
#include "../MCAL/Dio/inc/Dio.h"


#define F_CPU 16000000
#include "util/delay.h"
////////////////////////////

/*Configuration of BCD*/
#define BCD_BIT0 DIO_u8CHANNEL08
#define BCD_BIT1 DIO_u8CHANNEL09
#define BCD_BIT2 DIO_u8CHANNEL10
#define BCD_BIT3 DIO_u8CHANNEL12

#define SEG1_COM DIO_u8CHANNEL03
#define SEG2_COM DIO_u8CHANNEL02
#define SEG3_COM DIO_u8CHANNEL13
#define SEG4_COM DIO_u8CHANNEL14
/////////////////////////////////


/*
SegBCD_vInit(void);
Description:
		TurnOff all 7Segs before starting
*/
void SegBCD_vInit(void);


/*
SegBSD_vWriteVal(u8 Copy_u8Num);
Description:
			Write Value on the enabled 7-Seg
*/
void SegBSD_vWriteVal(u8 Copy_u8Num);



/*
SegBSD_vWriteValMUX(u32 Copy_u32Num);
Description:
			Write Value Number on four 7-Seg digits
*/
void SegBSD_vWriteValMUX(u32 Copy_u32Num);





#endif /* SEGBCD_H_ */