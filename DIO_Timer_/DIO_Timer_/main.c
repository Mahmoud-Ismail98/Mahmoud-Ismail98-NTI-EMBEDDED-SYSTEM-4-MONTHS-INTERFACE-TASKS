/*
 * Counter_DIO.c
 *
 * Created: 10/20/2023 3:23:00 PM
 * Author : Ahmed Wael

Counting Up Timer
 -> Description:
	This Project uses three push buttons Reset,Pause and resume Timer Displayed on four 7-segs

-> Peripherals & Drivers Used:
	DIO
	PORT
	SegBCD
 */
#include"Bit_utils.h"
#include"Std_types.h"

#include "Dio.h"
#include "Port.h"
#include "SegBCD.h"

#define F_CPU 16000000
#include "util/delay.h"

//Counting time function
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



int main(void)
{
	Port_vidInit();


    while (1)
    {

		 SegBSD_vTime();

    }
}

