/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 24 Oct 2023                                                           */
/************************************************************************************/
#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

/* Registers Definition */
#define TIMER0_u8_TCCR0_REG                *((volatile u8 *)0x53)
#define TIMER0_u8_TCNT0_REG                *((volatile u8 *)0x52)
#define TIMER0_u8_OCR0_REG                 *((volatile u8 *)0x5C)
#define TIMER0_u8_TIMSK_REG                *((volatile u8 *)0x59)
#define TIMER0_u8_TIFR_REG                 *((volatile u8 *)0x58)
#define TIMER0_u8_SFIOR_REG                *((volatile u8 *)0x50)

/* Registers Definition */
#define TIMER1_u8_TCCR1A_REG               *((volatile u8 *)0x4F)
#define TIMER1_u8_TCCR1B_REG               *((volatile u8 *)0x4E)
#define TIMER1_u8_TCNT1H_REG               *((volatile u8 *)0x4D)
#define TIMER1_u8_TCNT1L_REG               *((volatile u8 *)0x4C)
#define TIMER1_u16_TCNT1_REG               *((volatile u16 *)0x4C)
#define TIMER1_u8_OCR1AH_REG               *((volatile u8 *)0x4B)
#define TIMER1_u8_OCR1Al_REG               *((volatile u8 *)0x4A)
#define TIMER1_u16_OCR1A_REG               *((volatile u16 *)0x4A)
#define TIMER1_u8_OCR1BH_REG               *((volatile u8 *)0x49)
#define TIMER1_u8_OCR1Bl_REG               *((volatile u8 *)0x48)
#define TIMER1_u16_OCR1B_REG               *((volatile u16 *)0x48)
#define TIMER1_u8_ICR1H_REG                *((volatile u8 *)0x47)
#define TIMER1_u8_ICR1L_REG                *((volatile u8 *)0x46)
#define TIMER1_u16_ICR1_REG                *((volatile u16 *)0x46)
/* Macros for Register's Bits */
// TCCR0
#define TIMER0_u8_CS00_BIT               0
#define TIMER0_u8_CS01_BIT               1
#define TIMER0_u8_CS02_BIT               2
#define TIMER0_u8_WGM01_BIT              3
#define TIMER0_u8_COM00_BIT              4
#define TIMER0_u8_COM01_BIT              5
#define TIMER0_u8_WGM00_BIT              6
#define TIMER0_u8_FOC0_BIT               7
// TCCR1A
#define TIMER1_u8_WGM10_BIT              0
#define TIMER1_u8_WGM11_BIT              1
#define TIMER1_u8_FOC1B_BIT              2
#define TIMER1_u8_FOC1A_BIT              3
#define TIMER1_u8_COM1B0_BIT             4
#define TIMER1_u8_COM1B1_BIT             5
#define TIMER1_u8_COM1A0_BIT             6
#define TIMER1_u8_COM1A1_BIT             7
// TCCR1B
#define TIMER1_u8_CS10_BIT               0
#define TIMER1_u8_CS11_BIT               1
#define TIMER1_u8_CS12_BIT               2
#define TIMER1_u8_WGM12_BIT              3
#define TIMER1_u8_WGM13_BIT              4
#define TIMER1_u8_ICES1_BIT              6
#define TIMER1_u8_ICNC1_BIT              7
// TIMSK
#define TIMER0_u8_TOIE0_BIT              0
#define TIMER0_u8_OCIE0_BIT              1
#define TIMER1_u8_TOIE1_BIT              2
#define TIMER1_u8_OCIE1B_BIT             3
#define TIMER1_u8_OCIE1A_BIT             4
#define TIMER1_u8_TICIE1_BIT             5
#define TIMER0_u8_TOIE2_BIT              6
#define TIMER0_u8_OCIE2_BIT              7
// TIFR
#define TIMER0_u8_TOV0_BIT               0
#define TIMER0_u8_OCF0_BIT               1
#define TIMER1_u8_TOV1_BIT               2
#define TIMER1_u8_OCF1B_BIT              3
#define TIMER1_u8_OCF1A_BIT              4
#define TIMER1_u8_ICF1_BIT               5

// SFIOR
#define TIMER0_u8_PSR10_BIT              0


/* Macros for configuration of the compare output mode */
// normal and ctc mode
#define TIMER_NORMAL_PORT              0
#define TIMER_TOG_ON_CMATCH            1
#define TIMER_CLR_ON_CMATCH            2
#define TIMER_SET_ON_CMATCH            3
// fast and phase  mode
#define TIMER_NORM_PORT                0
#define TIMER_NON_INVERTING            1
#define TIMER_INVRTING                 2

/* Macros for prescaler */
#define TIMER_NO_PRESCALING            0
#define TIMER_CLK_8_PRESCALING         1
#define TIMER_CLK_64_PRESCALING        2

#endif
