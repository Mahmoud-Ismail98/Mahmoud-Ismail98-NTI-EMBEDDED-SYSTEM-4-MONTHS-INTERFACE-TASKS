/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : SWICU                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/
#ifndef SWICU_H
#define SWICU_H



void SWICU_voidEnable(void);
void SWICU_voidDisable(void);

tenuErrorStatus SWICU_ErrStateGetOnPeriod(pu16 Copy_pu16OnPeriod);

tenuErrorStatus SWICU_ErrStateGetTotalPeriod(pu32 Copy_pu32TotalPeriod);

tenuErrorStatus SWICU_ErrStateGetDutyCycle(pu8 Copy_pu8DutyCycle);

#endif
