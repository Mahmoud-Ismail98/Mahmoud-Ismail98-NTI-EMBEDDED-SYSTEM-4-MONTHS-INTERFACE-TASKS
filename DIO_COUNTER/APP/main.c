#include "../LIB/Include/STD_TYPES.h"
#include "../LIB/Include/BIT_MATH.h"
#include "../MCAL/PORT/Include/PORT_interface.h"
#include "../MCAL/DIO/Include/DIO_interface.h"
#include "../HAL/SSD/Include/SSD_interface.h"
#define F_CPU    8000000UL
#include <util/delay.h>

int main(void)
{
	u32 local_u32Count = 0;
	u8 local_u8ReadPB;
	PORT_voidInit();
	while(1)
	{
		SSD_voidWriteTo4SS(local_u32Count);
		DIO_DioEnumReadChannel(DIO_u8_PORTA,DIO_u8_PIN0,&local_u8ReadPB);
		if(local_u8ReadPB == DIO_u8_LOW)
		{
			/* De_bouncing */
			_delay_ms(10);
			/* Then Check Again */
			DIO_DioEnumReadChannel(DIO_u8_PORTA,DIO_u8_PIN0,&local_u8ReadPB);
			while (local_u8ReadPB == DIO_u8_LOW)
			{
				DIO_DioEnumReadChannel(DIO_u8_PORTA,DIO_u8_PIN0,&local_u8ReadPB);
			}
			SSD_voidWriteTo4SS(local_u32Count);
			local_u32Count++;
		}
	}
	return 0;
}




