/*
 * GPTM.h
 *
 * Created: 10/23/2023 9:18:11 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef GPTM_H_
#define GPTM_H_

//==========================TIMERS Availabe===========================

#define GPTM_TIMER0         0
#define GPTM_TIMER1         1
#define GPTM_TIMER2         2


/*TIMER0 APIs*/
void GPTM_TIMER0_vidInit(void);
void GPTM_TIMER0_vidSetCompareMatchValue(u8 copy_u8Value);
//void GPTM_TIMER0_vidSetCallBack(void (pu8 PF) (void),u8 copy_u8TimerIntIndex);
void GPTM_timer0_setCallBack(void(*funClbk_ptr)(void), u8 index);
void GPTM_timer0_setPwm(u8 compareValue);
void GPTM_timer0_CLERPwm(void);
//void GPTM_TIMER0_vidSetPWM(u16 copy_u16CompareValue);
void GPTM_TIMER0_vidDeInit(void);

/*	TIMER1 APIs*/
/*  TIMER2 APIs*/



#endif /* GPTM_H_ */