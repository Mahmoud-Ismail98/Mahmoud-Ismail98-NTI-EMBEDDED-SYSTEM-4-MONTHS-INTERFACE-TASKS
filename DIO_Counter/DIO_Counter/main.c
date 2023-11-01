/*
 * DIO_Counter.c
 *
 * Created: 11/1/2023 2:44:16 PM
 * Author : Ahmed Wael
 */

#include "LIB/Bit_utils.h"
#include "LIB/Std_types.h"
#include "MCAL/Port/inc/Port.h"
#include "MCAL/Dio/inc/Dio.h"
#include "HAL/SegBCD/inc/SegBCD.h"

int main(void)
{
	Port_vidInit();
	SegBCD_vInit();
	u16 Local_u16Counter = 0;
	u8 Local_u8Button;
	
    while (1)
    {
		SegBSD_vWriteValMUX(Local_u16Counter);
		Dio_enuReadChannel(DIO_u8CHANNEL24,&Local_u8Button);
		if(Local_u8Button == 0)
		{
			Local_u16Counter++;
		}
		while(Local_u8Button == 0)
		{
			Dio_enuReadChannel(DIO_u8CHANNEL24,&Local_u8Button);
		}
    }
}

