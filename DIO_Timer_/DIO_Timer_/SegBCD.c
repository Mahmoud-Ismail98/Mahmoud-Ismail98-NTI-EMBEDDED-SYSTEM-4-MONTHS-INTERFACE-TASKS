/*
 * SegBCD.c
 *
 * Created: 10/21/2023 9:29:31 AM
 *  Author: Ahmed Wael
 */

#include "SegBCD.h"


 /*Customized to eta32 board*/
 void SegBCD_vInit(void)
 {
	 Dio_enuWriteChannel(SEG1_COM,DIO_u8LEVEL_HIGH);
	 Dio_enuWriteChannel(SEG2_COM,DIO_u8LEVEL_HIGH);
	 Dio_enuWriteChannel(SEG3_COM,DIO_u8LEVEL_HIGH);
	 Dio_enuWriteChannel(SEG4_COM,DIO_u8LEVEL_HIGH);
 }

void SegBSD_vWriteVal(u8 Copy_u8Num)
{
	if(Copy_u8Num <= 7)
	{
		Dio_enuWriteChannel(BCD_BIT0,GET_BIT(Copy_u8Num,0));
		Dio_enuWriteChannel(BCD_BIT1,GET_BIT(Copy_u8Num,1));
		Dio_enuWriteChannel(BCD_BIT2,GET_BIT(Copy_u8Num,2));
		Dio_enuWriteChannel(BCD_BIT3,DIO_u8LEVEL_LOW);

	}
	else if(Copy_u8Num > 7 && Copy_u8Num <=9)
	{
		Dio_enuWriteChannel(BCD_BIT3,DIO_u8LEVEL_HIGH);

		Dio_enuWriteChannel(BCD_BIT0,GET_BIT(Copy_u8Num,0));
		Dio_enuWriteChannel(BCD_BIT1,GET_BIT(Copy_u8Num,1));
		Dio_enuWriteChannel(BCD_BIT2,GET_BIT(Copy_u8Num,2));

	}
}

static u8 Choose_Seg(u8 num)
{
	u8 R_val=0;
	switch(num)
	{
		case 0:
		R_val = SEG1_COM;
		break;
		case 1:
		R_val = SEG2_COM;
		break;
		case 2:
		R_val = SEG3_COM;
		break;
		case 3:
		R_val = SEG4_COM;
		break;
	}
	return R_val;
}


void SegBSD_vWriteValMUX(u32 Copy_u32Num)
{

	u8 x = 0;
	while(Copy_u32Num != 0  || x<4)
	{
		Dio_enuWriteChannel(Choose_Seg(x),DIO_u8LEVEL_LOW);
		SegBSD_vWriteVal(Copy_u32Num%10);
		_delay_ms(1);
		Dio_enuWriteChannel(Choose_Seg(x),DIO_u8LEVEL_HIGH);
		x++;
		Copy_u32Num/=10;

	}
}

