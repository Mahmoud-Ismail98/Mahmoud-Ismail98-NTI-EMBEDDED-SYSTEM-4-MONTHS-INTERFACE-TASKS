/*
 * ICU.h
 *
 * Created: 10/27/2023 3:09:51 AM
 *  Author: sharb
 */ 


#ifndef ICU_H_
#define ICU_H_

#include "../MCAL/EXTINT/ExtInt.h"
void get_new_read(void);
void ICUSW_voidEnableICUSW(enum_EXT_INT_index_t arg_enum_MonitorPin);
void ICUSW_voidDisableICUSW(void);
void ICUSW_voidGetOnPeriod(u32 *ptr_u32_onPeriod);
void ICUSW_voidGetTotalPeriod(u32 *ptr_u32_totalPeriod);
void ICUSW_voidGetDutyCycle(u8 *ptr_u8_dutyCycle);


#endif /* ICU_H_ */