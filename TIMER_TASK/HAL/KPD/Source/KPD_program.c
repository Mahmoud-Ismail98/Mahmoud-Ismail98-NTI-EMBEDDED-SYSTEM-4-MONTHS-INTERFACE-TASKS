/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 21 Oct 2023                                                           */
/************************************************************************************/

#include "../../../LIB/Include/STD_TYPES.h"
#include "../../../LIB/Include/BIT_MATH.h"

#include "../../../MCAL/PORT/Include/PORT_interface.h"
#include "../../../MCAL/DIO/Include/DIO_interface.h"

#include "../Include/KPD_interface.h"
#include "../Include/KPD_private.h"
#include "../Include/KPD_config.h"
/* array of configuration keypad state */
u8 KPD_u8ArrKey[] = {KPD_u8_ROW_0_COL_0,KPD_u8_ROW_0_COL_1,KPD_u8_ROW_0_COL_2,KPD_u8_ROW_0_COL_3,
                     KPD_u8_ROW_1_COL_0,KPD_u8_ROW_1_COL_1,KPD_u8_ROW_1_COL_2,KPD_u8_ROW_1_COL_3,
                     KPD_u8_ROW_2_COL_0,KPD_u8_ROW_2_COL_1,KPD_u8_ROW_2_COL_2,KPD_u8_ROW_2_COL_3,
                     KPD_u8_ROW_3_COL_0,KPD_u8_ROW_3_COL_1,KPD_u8_ROW_3_COL_2,KPD_u8_ROW_3_COL_3};
/* array of row and column pattern */
u8 KPD_u8ArrRowPatt[] = {KPD_u8_ROW_PATT_0,KPD_u8_ROW_PATT_1,KPD_u8_ROW_PATT_2,KPD_u8_ROW_PATT_3};
u8 KPD_u8ArrColPatt[] = {KPD_u8_COL_PATT_0,KPD_u8_COL_PATT_1,KPD_u8_COL_PATT_2,KPD_u8_COL_PATT_3};

static void KPD_voidWrite(u8 copy_u8RowPattern)
{
    /* write the pattern value into row pins */
    DIO_DioEnumWriteChannel(KPD_u8_ROW_PORT,KPD_u8_ROW_PIN_0,GET_BIT(copy_u8RowPattern,KPD_u8_ROW_PIN_0));
    DIO_DioEnumWriteChannel(KPD_u8_ROW_PORT,KPD_u8_ROW_PIN_1,GET_BIT(copy_u8RowPattern,KPD_u8_ROW_PIN_1));
    DIO_DioEnumWriteChannel(KPD_u8_ROW_PORT,KPD_u8_ROW_PIN_2,GET_BIT(copy_u8RowPattern,KPD_u8_ROW_PIN_2));
    DIO_DioEnumWriteChannel(KPD_u8_ROW_PORT,KPD_u8_ROW_PIN_3,GET_BIT(copy_u8RowPattern,KPD_u8_ROW_PIN_3));
}

static KPDEnum KPD_KPDEnumRead(pu8 copy_pu8ColPattern)
{
    KPDEnum local_KPDEnumErrorState = KPD_Read_OK;
    u8 local_u8TempRead = 0x00;
    /* check about pointer if equal null */
    if(copy_pu8ColPattern != NULL)
    {
        *copy_pu8ColPattern = 0x00;
        /* read the pattern value from column pins */
        DIO_DioEnumReadChannel(KPD_u8_COL_PORT,KPD_u8_COL_PIN_0,&local_u8TempRead);
        *copy_pu8ColPattern |= local_u8TempRead << KPD_u8_COL_PIN_0;
        DIO_DioEnumReadChannel(KPD_u8_COL_PORT,KPD_u8_COL_PIN_1,&local_u8TempRead);
        *copy_pu8ColPattern |= local_u8TempRead << KPD_u8_COL_PIN_1;
        DIO_DioEnumReadChannel(KPD_u8_COL_PORT,KPD_u8_COL_PIN_2,&local_u8TempRead);
        *copy_pu8ColPattern |= local_u8TempRead << KPD_u8_COL_PIN_2;
        DIO_DioEnumReadChannel(KPD_u8_COL_PORT,KPD_u8_COL_PIN_3,&local_u8TempRead);
        *copy_pu8ColPattern |= local_u8TempRead << KPD_u8_COL_PIN_3;
    }
    else 
    {
        local_KPDEnumErrorState = KPD_Read_NOK;
    }
    return local_KPDEnumErrorState;
}

KPDEnum KPD_KPDEnumGetKeyState(pu8 local_pu8Return)
{
    KPDEnum local_KPDEnumErrorState = KPD_GetKey_OK;
    u8 local_u8Count;
    u8 local_u8ReadPin;
    if(local_pu8Return != NULL)
    {
        for(local_u8Count = 0;local_u8Count < KPD_u8_ROW_ITERATOR;local_u8Count++)
        {
            /* loop for active each row pin by writing the pattern value into pins  */
            KPD_voidWrite(KPD_u8ArrRowPatt[local_u8Count]);
            /* read each column pin */
            KPD_KPDEnumRead(&local_u8ReadPin); // switch is pressed
            switch(local_u8ReadPin)
            {
                case KPD_u8_COL_PATT_0: 
                *local_pu8Return = KPD_u8ArrKey[(local_u8Count * KPD_u8_ROW_ITERATOR) + 0];    break;
                case KPD_u8_COL_PATT_1:
                *local_pu8Return = KPD_u8ArrKey[(local_u8Count * KPD_u8_ROW_ITERATOR) + 1];    break;
                case KPD_u8_COL_PATT_2:
                *local_pu8Return = KPD_u8ArrKey[(local_u8Count * KPD_u8_ROW_ITERATOR) + 2];    break;
                case KPD_u8_COL_PATT_3:
                *local_pu8Return = KPD_u8ArrKey[(local_u8Count * KPD_u8_ROW_ITERATOR) + 3];    break;
            }
        }
    }
    else
    {
        local_KPDEnumErrorState = KPD_GetKey_NOK;
    }
    return local_KPDEnumErrorState;
}
