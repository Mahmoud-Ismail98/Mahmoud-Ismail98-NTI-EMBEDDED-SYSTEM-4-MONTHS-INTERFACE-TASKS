/*
 * ICUSW.h
 *
 * Created: 10/27/2023 12:53:00 PM
 *  Author: HP
 */ 


#ifndef ICUSW_H_
#define ICUSW_H_








typedef enum ICUSW_ErrorState{
    ICUSW_NULLPTR,ICUSW_OK
}ICUSW_ErrorState;


void ICUSW_voidEnableSWICU(void);
void ICUSW_voidDisableSWICU(void);
ICUSW_ErrorState   ICUSW_u8GetOnPeriod(pu16  Copy_pu16OnPeriod);
ICUSW_ErrorState   ICUSW_u8GetOffPeriod(pu32  Copy_pu32TotalPeriod);
ICUSW_ErrorState   ICUSW_u8GetDutyCycle(pu8  Copy_pu8DutyCycle);



#endif /* ICUSW_H_ */