/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 22 Oct 2023                                                           */
/************************************************************************************/
#ifndef KPD_INTERFACE_H
#define KPD_INTERFACE_H

#define  KPD_u8_KEY_NOT_PRESSED      0xff

typedef enum{
    KPD_OK,
    KPD_NOK,
}KPDEnum;

KPDEnum KPD_KPDEnumGetKeyState  (u8 * Copy_Pu8ReturnedKey);

#endif