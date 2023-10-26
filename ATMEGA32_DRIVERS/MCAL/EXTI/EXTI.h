#ifndef _EXTI_H_ 
#define _EXTI_H_


#define LOW_LEVEL 0
#define ANY_CHANGE 1
#define FALLING_EDGE 2
#define RISING_EDGE 3

void ExtI_voidInitialize(void)  ;
void ExtI_voidEnableExtI(void)  ;
void ExtI_voidDisableExtI(void) ; 


void EnableExtI0(void) ;
void EnableExtI1(void) ;
void EnableExtI2(void) ;


void EnableExtI0(void) ;
void EnableExtI1(void) ;
void EnableExtI2(void) ;


void ExtI_voidSetCallBack(void (* I_ptr)(void));

#endif 