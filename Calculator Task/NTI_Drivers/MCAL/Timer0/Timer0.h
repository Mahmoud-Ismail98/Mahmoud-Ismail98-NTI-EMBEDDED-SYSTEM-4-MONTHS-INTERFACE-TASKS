/*
 * Timer0.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Ismail
 */

#ifndef MCAL_TIMER0_TIMER0_H_
#define MCAL_TIMER0_TIMER0_H_


/*Function Prototypes*/
void TIMER0_Init();

void TIMER0_SetPreload(u8 Copy_u8Preload);

void TIMER0_SetCTC(u8 Copy_u8OCR);

void TIMER0_OVERFLOW_CALLBACK(void(*Ptr_OverflowApp)(void));


void TIMER0_CTC_CALLBACK(void(*Ptr_CTCApp)(void));
void Timer0_Start(void);
void Timer0_Stop(void);
void Pwm0_Init(void);

void Pwm0_SetDutyCycle(u8 Local_u8_DesiredDutyCycle);

void Pwm0_Start(void);

void Pwm0_Stop(void);

#endif /* MCAL_TIMER0_TIMER0_H_ */
