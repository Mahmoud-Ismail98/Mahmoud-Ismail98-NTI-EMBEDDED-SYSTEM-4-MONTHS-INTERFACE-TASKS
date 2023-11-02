/*
 * Timer.h
 *
 * Created: 10/29/2023 10:04:38 AM
 *  Author: 20101
 */ 


#ifndef TIMER_H_
#define TIMER_H_



void TIMER0_Init(void);
u8 TIMER0_u8SetCallBack (void (*copy_pvCallBack)(void));



#endif /* TIMER_H_ */