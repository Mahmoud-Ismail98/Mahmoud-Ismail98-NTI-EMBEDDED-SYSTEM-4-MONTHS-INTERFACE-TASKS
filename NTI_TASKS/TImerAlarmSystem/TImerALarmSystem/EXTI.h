#ifndef _EXTI_H_ 
#define _EXTI_H_


#define LOW_LEVEL 0
#define ANY_CHANGE 1
#define FALLING_EDGE 2
#define RISING_EDGE 3

void ExtI_voidInitialize(void)  ;
void ExtI_voidEnableExtI(void)  ;
void ExtI_voidDisableExtI(void) ; 
void ExtI_voidSetCallBack(void (* I_ptr)(void));
u8 EXTI_u8Int0SetSenseControl(u8 copy_u8Sense);

#endif 