/*
 * EXTI.h
 *
 * Created: 10/22/2023 3:29:08 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef EXTI_H_
#define EXTI_H_

void EXTI_vidInit();

void EXTI_vidDeInit();


void EXTI_vidSetFallingEdge  (u8 copy_u8EXTI_Index);
void EXTI_vidSetRisingEdge   (u8 copy_u8EXTI_Index);

void EXTI_vidClear(u8 copy_u8EXTI_Index);


void EXTI_vidSetCallBack(u8 copy_u8IntID,   void (*PF) (void));   //try function with input parameter





#endif /* EXTI_H_ */