/*
 * SegBCD.c
 *
 * Created: 10/21/2023 9:29:31 AM
 *  Author: Wael
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

u8 Choose_Seg(u8 num)
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


void SegBSD_vTime(void)
{
	u32 Counter = 0;	
	static u32 Copy_u32Counter= 0;
	u32 TEMP_u32Counter=Copy_u32Counter;
	u8 Reset_B;
	u8 Pause_B;
	u8 Resume_B;
	static u8 Pause_flag = 0;
	Dio_enuReadChannel(DIO_u8CHANNEL31,&Reset_B);
	Dio_enuReadChannel(DIO_u8CHANNEL30,&Pause_B);
	Dio_enuReadChannel(DIO_u8CHANNEL29,&Resume_B);
	if(!Pause_B)
	{
		Pause_flag = 1;
	}
	if(!Resume_B)
	{
		Pause_flag = 0;
	}
	if(Pause_flag == 0)
	{
		while(Counter <= 249)
		{
			TEMP_u32Counter=Copy_u32Counter;
			Dio_enuReadChannel(DIO_u8CHANNEL31,&Reset_B);
			/*Display TEMP*/
			SegBSD_vWriteValMUX(TEMP_u32Counter);
			/**/
			Counter++;
			Dio_enuFlipChannel(DIO_u8CHANNEL06);
			if(!Reset_B)
			{
				Copy_u32Counter = 0;
			}
		}
		Copy_u32Counter++;
		if(Copy_u32Counter == 10000)
		{
			Copy_u32Counter = 0;
		}
		
	}
	else
	{
		SegBSD_vWriteValMUX(Copy_u32Counter);	
		if(!Reset_B)
		{
			Copy_u32Counter = 0;
		}
	}
	
}

