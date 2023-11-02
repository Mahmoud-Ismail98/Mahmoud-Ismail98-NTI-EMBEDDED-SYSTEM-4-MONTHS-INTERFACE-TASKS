/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 22 Oct 2023                                                           */
/************************************************************************************/
#include "../../../LIB/Include/STD_TYPES.h"
#include "../../../LIB/Include/BIT_MATH.h"

#include "../Include/GIE_interface.h"
#include "../Include/GIE_private.h"

void GIE_voidInit(u8 copy_u8State)
{
    switch(copy_u8State)
    {
        case GIE_u8_ENABLE :  SET_BIT(GIE_u8_SREG,7);       break;
        case GIE_u8_DISABLE:  CLR_BIT(GIE_u8_SREG,7);       break;
    }
}

