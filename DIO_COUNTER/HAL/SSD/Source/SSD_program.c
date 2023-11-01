/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 21 Oct 2023                                                           */
/************************************************************************************/

#include "../../../LIB/Include/STD_TYPES.h"
#include "../../../LIB/Include/BIT_MATH.h"

#include "../../../MCAL/PORT/Include/PORT_interface.h"
#include "../../../MCAL/DIO/Include/DIO_interface.h"

#include "../Include/SSD_interface.h"
#define F_CPU    8000000UL
#include <util/delay.h>

void (*Enable_Apf[4])(void) = {SSD_voidEnable4,SSD_voidEnable3,SSD_voidEnable2,SSD_voidEnable1};
void (*Disable_Apf[4])(void) = {SSD_voidDisable4,SSD_voidDisable3,SSD_voidDisable2,SSD_voidDisable1};

void SSD_voidEnable1(void)
{
    DIO_DioEnumWriteChannel(SSD_ENABLE_PORT,SSD_ENABLE_PIN_0,DIO_u8_HIGH);
}
void SSD_voidEnable2(void)
{
    DIO_DioEnumWriteChannel(SSD_ENABLE_PORT,SSD_ENABLE_PIN_1,DIO_u8_HIGH);
}
void SSD_voidEnable3(void)
{
    DIO_DioEnumWriteChannel(SSD_ENABLE_PORT,SSD_ENABLE_PIN_2,DIO_u8_HIGH);
}
void SSD_voidEnable4(void)
{
    DIO_DioEnumWriteChannel(SSD_ENABLE_PORT,SSD_ENABLE_PIN_3,DIO_u8_HIGH);
}

void SSD_voidDisable1(void)
{
    DIO_DioEnumWriteChannel(SSD_ENABLE_PORT,SSD_ENABLE_PIN_0,DIO_u8_LOW);
}
void SSD_voidDisable2(void)
{
    DIO_DioEnumWriteChannel(SSD_ENABLE_PORT,SSD_ENABLE_PIN_1,DIO_u8_LOW);
}
void SSD_voidDisable3(void)
{
    DIO_DioEnumWriteChannel(SSD_ENABLE_PORT,SSD_ENABLE_PIN_2,DIO_u8_LOW);
}
void SSD_voidDisable4(void)
{
    DIO_DioEnumWriteChannel(SSD_ENABLE_PORT,SSD_ENABLE_PIN_3,DIO_u8_LOW);
}

void SSD_voidWriteNumber(u8 copy_u8Number)
{
    if(copy_u8Number < 10)
    {
        DIO_DioEnumWriteChannel(SSD_DATA_PORT,SSD_DATA_PIN_0,GET_BIT(copy_u8Number,0));
        DIO_DioEnumWriteChannel(SSD_DATA_PORT,SSD_DATA_PIN_1,GET_BIT(copy_u8Number,1));
        DIO_DioEnumWriteChannel(SSD_DATA_PORT,SSD_DATA_PIN_2,GET_BIT(copy_u8Number,2));
        DIO_DioEnumWriteChannel(SSD_DATA_PORT,SSD_DATA_PIN_3,GET_BIT(copy_u8Number,3));
    }
}

void SSD_voidWriteTo2SS(u8 copy_u8Num,f32 copy_f32TimeSec)
{
    u32 local_u32TimeMs = (copy_f32TimeSec * 1000) / 20;
    if(copy_u8Num < 100)
    {
        u8 local_u8RightNum = copy_u8Num % 10;
        u8 local_u8LeftNum  = copy_u8Num / 10;
        for(u32 count = 0;count < local_u32TimeMs;count++)
        {
            SSD_voidDisable3();
            SSD_voidDisable4();
            SSD_voidWriteNumber(local_u8RightNum);
            SSD_voidEnable4();
            _delay_ms(10);
            SSD_voidDisable4();
            SSD_voidWriteNumber(local_u8LeftNum);
            SSD_voidEnable3();
            _delay_ms(10);
        }
    }
}

void SSD_voidWriteTo4SS(u32 copy_u32Num)
{
	u8 x = 0;
	while((copy_u32Num != 0) || (x < 4))
	{
		Enable_Apf[x]();
		SSD_voidWriteNumber(copy_u32Num%10);
		_delay_ms(2);
		Disable_Apf[x]();
		x++;
		copy_u32Num /= 10;
	}
}




//u32 local_u32TimeMs = (copy_f32TimeSec * 1000) / 40;
//if(copy_u32Num <= 9999)
//{
//
//    for(u32 count = 0;count < local_u32TimeMs;count++)
//    {
//        SSD_voidDisable1();
//        SSD_voidDisable2();
//        SSD_voidDisable3();
//        SSD_voidDisable4();
//        SSD_voidWriteNumber(copy_u32Num%10);
//        SSD_voidEnable4();
//        _delay_ms(10);
//        copy_u32Num /= 10;
//        SSD_voidDisable4();
//        SSD_voidWriteNumber(copy_u32Num%10);
//        SSD_voidEnable3();
//        _delay_ms(10);
//        copy_u32Num /= 10;
//        SSD_voidDisable3();
//        SSD_voidWriteNumber(copy_u32Num%10);
//        SSD_voidEnable2();
//        _delay_ms(10);
//        copy_u32Num /= 10;
//        SSD_voidDisable2();
//        SSD_voidWriteNumber(copy_u32Num%10);
//        SSD_voidEnable1();
//        _delay_ms(10);
//        copy_u32Num /= 10;
//    }
//}
