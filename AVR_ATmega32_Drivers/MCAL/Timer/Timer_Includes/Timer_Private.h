/*
 * Timer0_Privqate.h
 *
 * Created: 10/24/2023 11:19:56 AM
 *  Author: Mohamed Alaa
 */ 


#ifndef TIMER0_PRIVQATE_H_
#define TIMER0_PRIVQATE_H_

//=================================================
//Timer0 registers
//=================================================
#define TCCR0	(*(volatile Puint8)0x53)
#define TCNT0	(*(volatile Puint8)0x52)
#define OCR0	(*(volatile Puint8)0x5c)
#define TIMSK	(*(volatile Puint8)0x59)
#define TIFR	(*(volatile Puint8)0x58)

//=================================================
//TCCR0 bits 
//=================================================
#define FOC0	7
#define WGM00	6
#define COM0n	4
#define WGM01	3
#define CS0n	0

//=================================================
//TIMSK bits
//=================================================
#define OCIE0	1
#define TOIE0	0
#define TICIE1	5

//=================================================
//TIFR bits
//=================================================
#define OCF0	1
#define TOV0	0
#define Timer0_Run_Free_Enable	1
#define Timer0_Run_Free_Disable	0

//=================================================
//Timer1 registers
//=================================================
#define TCCR1B	(*(volatile Puint8)0x4E)
#define ICR1	(*(volatile Puint16)0x46)
#define TCNT1	(*(volatile Puint16)0x4C)

//=================================================
//TCCR1B bits
//=================================================
#define CS10	0
#define ICES1	6


//=================================================
//variables
//=================================================
static Timer0_Config_t Timer0_GCFG;
void(*Timer0_GPCallBack[2])(void) = {0, 0};
void(*Timer1_GPCallBack)(void) = 0;
static uint8 Timer0_Run_Free_State = Timer0_Run_Free_Disable;
float64 Tic_Time = 0;
uint32 Timer0_Total_Tics = 0;
uint32 Timer0_Flag_Counts = 0;
uint32 Timer0_Last_Time_Tics = 0;
float64 PWM_Periodic_Time = 0;
float64 PWM_On_Time = 0;







#endif /* TIMER0_PRIVQATE_H_ */