/*
 * GPTM_PRIVATE.h
 *
 * Created: 10/23/2023 9:18:45 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef GPTM_PRIVATE_H_
#define GPTM_PRIVATE_H_

/*TIMER 0 REGISTERS*/

#define  TCCR0 (*((volatile pu8)0x53))
	/*TCCR0 BITS*/
	#define TCCR0_FOC0    7   //Force Ouput Compare bit
	#define TCCR0_WGM00   6   //Waveform Generation Mode BIT 0
	#define TCCR0_COM01   5   //Compare Match Output Mode BIT 0
	#define TCCR0_COM00   4   //Compare Match Output Mode BIT 1
	#define TCCR0_WGM01   3   //Waveform Generation Mode BIT 1
	#define TCCR0_CS02    2   //Clock Select BIT 2
	#define TCCR0_CS01    1   //Clock Select BIT 1
	#define TCCR0_CS00    0   //Clocl Select BIT 0

#define  TCNT0 (*((volatile pu8)0x52))

#define  OCR0 (*((volatile pu8)0x5C))


/*TIMER 1 REGISTERS*/

#define  TCCR1A ((*(volatile pu8)0x4F))



#define  TCCR1B ((*(volatile pu8)0x4E))
	/*TCCR1B BITS*/
	#define TCCR1B_ICNC1   7   // Input Capture Noise Canceler BIT
	#define TCCR1B_ICES1   6   // Input Capture Edge Select BIT
	#define TCCR1B_WGM13   4   //  Waveform Generation Mode BIT  4
	#define TCCR1B_WGM12   3   //  Waveform Generation Mode BIT  4
	#define TCCR1B_CS12    2   //  Clock Select BIT  3
	#define TCCR1B_CS11    2   //  Clock Select BIT  2
	#define TCCR1B_CS10    2   //  Clock Select BIT  1
	
	
	
	
#define  TCNT1H ((*(volatile pu8)0x4D))
#define  TCNT1L ((*(volatile pu8)0x4C))

#define  OCR1AH ((*(volatile pu8)0x4B))
#define  OCR1AL ((*(volatile pu8)0x4A))
#define  OCR1BH ((*(volatile pu8)0x49))
#define  OCR1BL ((*(volatile pu8)0x48))

#define  ICR1H  ((*(volatile pu8)0x47))  //Input Capture Register high byte
#define  ICR1L  ((*(volatile pu8)0x46))  //Input Capture Register LOW   Byte


/*TIMER 2 REGISTERS*/

#define  TCCR2 ((*(volatile pu8)0x45))
	/*TCCR2 BITS*/
	#define TCCR2_FOC2    7   //Force Ouput Compare bit
	#define TCCR2_WGM20   6   //Waveform Generation Mode BIT 0
	#define TCCR2_COM21   5   //Compare Match Output Mode BIT 0
	#define TCCR2_COM20   4   //Compare Match Output Mode BIT 1
	#define TCCR2_WGM21   3   //Waveform Generation Mode BIT 1
	#define TCCR2_CS22    2   //Clock Select BIT 2
	#define TCCR2_CS21    1   //Clock Select BIT 1
	#define TCCR2_CS20    0   //Clock Select BIT 0
	
#define  TCNT2 (*((volatile pu8)0x44))
#define  OCR2  (*((volatile pu8)0x43))

/*TIMERS INTERRUPT ENABLE "PIE" REGIRSTER*/
#define  TIMSK (*((volatile pu8)0x59))
	/*TIMSK BITS*/
	#define OCIE2    7   //Output Compare match Interrupt Enable for Timer2
	#define TOIE2    6   //Timer Counter Overflow Interrupt Enable for timer2
	#define TICIE1   5   //Timer/Counter1, Input Capture Interrupt Enable
	#define OCIE1A   4   //Output Compare match Interrupt Enable for Timer1A
	#define OCIE1B   3   //Output Compare match Interrupt Enable for Timer1B
	#define TOIE1    2   //Timer Counter Overflow Interrupt Enable for timer1
	#define OCIE0    1   //Output Compare match Interrupt Enable for Timer0
	#define TOIE0    0   //Timer Counter Overflow Interrupt Enable for timer0

/*TIMERS INTERRUPTS FLAGS "PIF" REGIRSTER*/
#define  TIFR ((*(volatile pu8)0x58))
	/*TIFR BITS*/
	#define OCF2     7   //Output Compare match   Interrupt Flag for Timer2
	#define TOV2     6   //Timer Counter Overflow Interrupt Flag for timer2
	#define ICF1     5   // Timer/Counter1, Input Capture Flag
	#define OCF1A    4   //OCF1A: Timer/Counter1, Output Compare A Match Flag
	#define OCF1B    3   //OCF1B: Timer/Counter1, Output Compare B Match Flag
	#define TOV1     2   //TOV1: Timer/Counter1, Overflow Flag
	#define OCF0     1   //Output Compare match   Interrupt Flag for Timer0
	#define TOV0     0   //Timer Counter Overflow Interrupt Flag for timer0
	
	
/*Special Function IO Register containing Prescale reset pins*/
#define SFIOR ((*(volatile pu8)0x50))
	#define SFIOR_PSR10    0    //Prescale Reset for Timer 0 & Timer 1
	#define SFIOR_PSR2     1    //Prescale Reset for Timer 2
	
#define ASSR ((*(volatile pu8)0x42))
	#define ASSR_AS2    3 //AS2: Asynchronous Timer/Counter2 when set 1 timer 2 is clocked from external oscilator
	#define TCN2UB      2
	#define OCR2UB		1
	#define TCR2UB      0

#define Input_Capture_Pin   PORTD_PIN6	

#define TIMER_ZERO_OC_PIN PORTB_PIN3




//=========================TIMER0 CONFIGURATIONS======================

/*Timer 0 CLOCK SOURCE Settings --> 1 to turn on or 0 to turn off*/

#define  GPTM_Timer0_Freq_Default               1
#define  GPTM_Timer0_Freq_Prescaler1_8          2
#define  GPTM_Timer0_Freq_Prescaler1_64         3
#define  GPTM_Timer0_Freq_Prescaler1_256        4
#define  GPTM_Timer0_Freq_Prescaler1_1024       5

#define  GPTM_Timer0_Ext_Freq_ON_FALLING_EDGE   6
#define  GPTM_Timer0_Ext_Freq_ON_RISING_EDGE    7

/*Timer 0 Operating Mode Settings --> 1 to turn on or 0 to turn off*/
#define GPTM_TIMER0_NORMAL_MODE             0
#define GPTM_TIMER0_CTC_MODE				1
#define GPTM_TIMER0_FASTPWM_MODE			2
#define GPTM_TIMER0_PhaseCorrect_Mode		3

/*Timer 0 OC0 PIN OPERATION MODE ON COMPARE MATCH --> 1 to turn on or 0 to turn off*/
#define GPTM_TIMER0_OC0_NORMAL     0
#define GPTM_TIMER0_OC0_TGL        1
#define GPTM_TIMER0_OC0_CLEAR      2
#define GPTM_TIMER0_OC0_SET        3


/*TIMER0 INTERRUPT ENABLE(1)/DISABLE(0)  */
#define GPTM_TIMER0_DISABLE_INTERRUPT         0
#define GPTM_TIMER0_COMPARE_MATCH_IE          1
#define GPTM_TIMER0_OVERFLOW_IE               2

//=========================TIMER1 CONFIGURATIONS=====================
/*Timer 1 PreScaler Settings -->1 to turn on or 0 to turn off*/
#define  GPTM_Timer1_Freq_Default            0
#define  GPTM_Timer1_Freq_Prescaler1_8       1
#define  GPTM_Timer1_Freq_Prescaler1_64      0
#define  GPTM_Timer1_Freq_Prescaler1_256     0
#define  GPTM_Timer1_Freq_Prescaler1_1024    0

#define  GPTM_TIMER1_Ext_clck_src_on_T1_pin_Clck_on_falling_edge  0
#define  GPTM_TIMER1_Ext_clck_src_on_T1_pin_Clck_on_rising_edge   0

/*ICU EDGE DETECTION MODE [1]ENABLE/[2]DISABLE */

#define  GPTM_TIMER1_ICU_Capture_on_the_falling_edge    0
#define  GPTM_TIMER1_ICU_Capture_on_the_rising_edge     1

#define GPTM_TIMER0_INIT_CLOCK_MASK (0b11111000)


//========================TIMER2 CONFIGURATIONS======================
/*Timer 2 PreScaler Settings --> 1 to turn on or 0 to turn off*/
#define  GPTM_Timer2_Freq_Default              1
#define  GPTM_Timer2_Freq_Prescaler1_8         0
#define  GPTM_Timer2_Freq_Prescaler1_32        0
#define  GPTM_Timer2_Freq_Prescaler1_64        0
#define  GPTM_Timer2_Freq_Prescaler1_128       0
#define  GPTM_Timer2_Freq_Prescaler1_256       0
#define  GPTM_Timer2_Freq_Prescaler1_1024      0


#endif /* GPTM_PRIVATE_H_ */