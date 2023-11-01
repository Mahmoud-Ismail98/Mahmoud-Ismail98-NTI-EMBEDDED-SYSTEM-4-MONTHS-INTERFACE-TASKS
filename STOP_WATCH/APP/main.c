#include "../LIB/Include/STD_TYPES.h"
#include "../LIB/Include/BIT_MATH.h"
#include "../MCAL/PORT/Include/PORT_interface.h"
#include "../MCAL/DIO/Include/DIO_interface.h"
#include "../HAL/SSD/Include/SSD_interface.h"
#define F_CPU    8000000UL
#include <util/delay.h>

#define START            0
#define STOP             1
#define CLEAR            2
u32 NUM;
int main(void)
{
	u8 local_u8Flag = CLEAR;
	u32 local_u32Count;
	u8 local_u8ReadPB1,local_u8ReadPB2,local_u8ReadPB3;
	PORT_voidInit();
	while(1)
	{
		DIO_DioEnumReadChannel(DIO_u8_PORTA,DIO_u8_PIN0,&local_u8ReadPB1);
		DIO_DioEnumReadChannel(DIO_u8_PORTA,DIO_u8_PIN1,&local_u8ReadPB2);
		DIO_DioEnumReadChannel(DIO_u8_PORTA,DIO_u8_PIN2,&local_u8ReadPB3);
		if(local_u8ReadPB1 == DIO_u8_LOW)
		{
			local_u8Flag = START;
		}
		if(local_u8ReadPB2 == DIO_u8_LOW)
		{
			local_u8Flag = STOP;
		}
		if(local_u8ReadPB3 == DIO_u8_LOW)
		{
			local_u8Flag = CLEAR;
		}
		switch(local_u8Flag)
		{
			case START:
			for(local_u32Count=0;local_u32Count<=9999;local_u32Count++)
			{
				SSD_voidWriteTo4SS(local_u32Count);
				NUM = local_u32Count;
				DIO_DioEnumReadChannel(DIO_u8_PORTA,DIO_u8_PIN1,&local_u8ReadPB2);
				if(local_u8ReadPB2 == DIO_u8_LOW)
				{
					local_u8Flag = STOP;
					//SSD_voidWriteTo4SS(NUM);
					break;
				}
				DIO_DioEnumReadChannel(DIO_u8_PORTA,DIO_u8_PIN2,&local_u8ReadPB3);
				if(local_u8ReadPB3 == DIO_u8_LOW)
				{
					local_u8Flag = CLEAR;
					//SSD_voidWriteTo4SS(0);
					break;
				}
			}
			break;
			case STOP : SSD_voidWriteTo4SS(NUM);            break;
			case CLEAR: SSD_voidWriteTo4SS(0);              break;
		}

	}
	return 0;
}




