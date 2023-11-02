/*
 * Timer1.h
 *
 * Created: 10/30/2023 11:17:28 PM
 *  Author: 20101
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

void Timer1_Init(void); 
void Timer1_voidSetICR(u16 copy_u16TOP);
void TImer1_voidSetCompAMatch(u16 copy_u16CompareAMatch);
void Servo_SetDegree(float degree);
void Servo_Init(void) ; 


#endif /* TIMER1_H_ */