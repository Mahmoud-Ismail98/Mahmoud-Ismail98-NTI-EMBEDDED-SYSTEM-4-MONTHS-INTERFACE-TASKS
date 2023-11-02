/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 21 Oct 2023                                                           */
/************************************************************************************/
#ifndef KPD_INTERFACE_H
#define KPD_INTERFACE_H

typedef enum{
    KPD_Read_OK,
    KPD_Read_NOK,
    KPD_GetKey_OK,
    KPD_GetKey_NOK,
}KPDEnum;

static void KPD_voidWrite(u8 copy_u8RowPattern);
static KPDEnum KPD_KPDEnumRead(pu8 copy_pu8ColPattern);
KPDEnum KPD_KPDEnumGetKeyState(pu8 local_pu8Return);

#endif