#ifndef TIMER0_PRV_H_
#define TIMER0_PRV_H_

#define TCCR0	*((volatile u8*)0x53)
#define TCNT0	*((volatile u8*)0x52)
#define OCR0	*((volatile u8*)0x5C)
#define TIMSK	*((volatile u8*)0x59)
#define TIFR	*((volatile u8*)0x58)

#define	WGM00					6
#define	WGM01					3
#define COM00					4
#define COM01					5

#define TOV0					0
#define	OCF0					1

#define	Normal_MODE				0
#define	Phase_CorrectPWM_MODE	1
#define	CTC_MODE				2
#define	FastPWM_MODE			3


#define CTC_PWMOUTMODE_1		0
#define CTC_PWMOUTMODE_2		1
#define CTC_PWMOUTMODE_3		2
#define CTC_PWMOUTMODE_4		3



#define	NO_ClockSource					0
#define No_prescaller					1
#define Prescaller_8					2
#define Prescaller_64					3
#define Prescaller_256					4
#define Prescaller_1024					5
#define EXTERNAL_OnFallingEdge			6
#define EXTERNAL_OnRISINGEdge			7

#define	ENABLE							1
#define DISABLE							0

#define	OVERFLOW_INT					0
#define COMPARE_MATCH_INT				1
#define OVERFLOW_AND_COMPARE_MATCH_INT	2				1
#define DISABLE_INT						3

void __vector_10 (void) __attribute__((signal));
void __vector_11 (void) __attribute__((signal));

#endif
