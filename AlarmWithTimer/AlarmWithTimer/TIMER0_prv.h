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

#define TOIE0					0
#define	OCIE0					1

#define	Normal_MODE				0
#define	Phase_CorrectPWM_MODE	1
#define	CTC_MODE				2
#define	FastPWM_MODE			3


#define CTC_PWMOUTMODE_1		0
#define CTC_PWMOUTMODE_2		1
#define CTC_PWMOUTMODE_3		2
#define CTC_PWMOUTMODE_4		3



#define	ENABLE							1
#define DISABLE							0




#define AVR_CLOCK		8
void __vector_10 (void) __attribute__((signal));
void __vector_11 (void) __attribute__((signal));

#endif
