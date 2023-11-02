/*
 * timer_prv.h
 *
 * Created: 10/24/2023 12:19:33 AM
 *  Author: sharb
 */ 


#ifndef TIMER_PRV_H_
#define TIMER_PRV_H_

#define TCCR0                      (*(vu8*)(0x53))
#define TCNT0			           (*(vu8*)(0x52))
#define OCR0			           (*(vu8*)(0x5C))
#define TIMSK			           (*(vu8*)(0x59))
#define TIFR			           (*(vu8*)(0x58))
#define SFIOR			           (*(vu8*)(0x50))
 						           
#define TCCR1A			           (*(vu8*)(0x4F))
#define TCCR1B			           (*(vu8*)(0x4E))
#define TCNT1H			           (*(vu8*)(0x4D))
#define TCNT1L			           (*(vu8*)(0x4C))
#define TCNT1LH			           (*(vu16*)(0x4C))
#define OCR1AH			           (*(vu8*)(0x4B))
#define OCR1AL			           (*(vu8*)(0x4A))
#define OCR1ALH			           (*(vu16*)(0x4A))
#define OCR1BH			           (*(vu8*)(0x49))
#define OCR1BL			           (*(vu8*)(0x48))
#define OCR1BLH			           (*(vu16*)(0x48))
#define ICR1H			           (*(vu8*)(0x47))
#define ICR1L			           (*(vu8*)(0x46))
#define ICR1LH			           (*(vu16*)(0x46))
 						           
#define TCCR2			           (*(vu8*)(0x45))
#define TCNT2			           (*(vu8*)(0x44))
#define OCR2			           (*(vu8*)(0x43))
#define ASSR			           (*(vu8*)(0x42))
						           
#define WDTCR			           (*(vu8*)(0x41))


#define FOC0                 7
#define WGM00                6
#define COM01                5
#define COM00                4
#define WGM01                3
#define CS02                 2
#define CS01                 1
#define CS00                 0
								   
								   
								   
								   
#define OCIE2                7
#define TOIE2                6
#define TICIE1               5
#define OCIE1A               4
#define OCIE1B               3
#define TOIE1                2
#define OCIE0                1
#define TOIE0                0
								   
								   
#define OCF2                  7
#define TOV2                  6
#define ICF1                  5
#define OCF1A                 4
#define OCF1B                 3
#define TOV1                  2
#define OCF0                  1
#define TOV0                  0
								   
#define PSR10                0
#define PSR2                 1 
								   
								   
#define COM1A1              7
#define COM1A0              6
#define COM1B1              5
#define COM1B0              4
#define FOC1A               3
#define FOC1B               2
#define WGM11               1
#define WGM10               0
								   
								   
#define ICNC1               7
#define ICES1               6
#define WGM13               4
#define WGM12               3
#define CS12                2
#define CS11                1
#define CS10                0
								   
								   
#define FOC2                 7
#define WGM20                6
#define COM21                5
#define COM20                4
#define WGM21                3
#define CS22                 2
#define CS21                 1
#define CS20                 0
								   
								   
								   
#define AS2                   3
#define TCN2UB                2
#define OCR2UB                1
#define TCR2UB                0


#define TIMER0_FREQUENCY_1M        1.0f
#define TIMER0_FREQUENCY_8M        8.0f
#define TIMER0_FREQUENCY_16M       16.0f

#define TIMER0_NORMAL_MODE         0
#define TIMER0_PWM_PHASE_MODE      1
#define TIMER0_CTC_MODE            2
#define TIMER0_FAST_PWM_MODE       3
								   
#define TIMER0_NO_PRESCALER        1
#define TIMER0_8_PRESCALER         8
#define TIMER0_64_PRESCALER        64
#define TIMER0_256_PRESCALER       256UL
#define TIMER0_1024_PRESCALER      1024UL
#define TIMER0_EXT_CLOCK_FALLING   1        
#define TIMER0_EXT_CLOCK_RISING    1


#define TIMER0_INTERRUPT_ENABLE    0
#define TIMER0_INTERRUPT_DISABLE   1

#define PWM_INVERTED               0
#define PWM_NON_INVERTED           1


#define MILLI_CONV                 ((u16)1000   )
#define SEC_CONV                   ((u32)1000000)
#define TIMER0_REG_SIZE            256
#define MAX_DUTY                   100
#define ONE_TICK                   1


#define NUM_OF_TIMERS             3

#define TIMER0_INDEX              0
#define TIMER1_INDEX              1
#define TIMER2_INDEX              2



static void TIMER0_BLOCK(void);

#endif /* TIMER_PRV_H_ */