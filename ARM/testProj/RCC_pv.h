



#ifndef RCC_PRV_H
#define RCC_PRV_H

// RCC 



#define RCC_BASE_ADDRESS             0x40023800
#define RCC_CR                       (*(vu32*)(RCC_BASE_ADDRESS+0x00))
#define RCC_PLLCFGR                  (*(vu32*)(RCC_BASE_ADDRESS+0x04))
#define RCC_CFGR                     (*(vu32*)(RCC_BASE_ADDRESS+0x08))
#define RCC_CIR                      (*(vu32*)(RCC_BASE_ADDRESS+0x0C))
#define RCC_AHB1RSTR                 (*(vu32*)(RCC_BASE_ADDRESS+0x10))
#define RCC_AHB2RSTR                 (*(vu32*)(RCC_BASE_ADDRESS+0x14))
#define RCC_APB1RSTR                 (*(vu32*)(RCC_BASE_ADDRESS+0x20))
#define RCC_APB2RSTR                 (*(vu32*)(RCC_BASE_ADDRESS+0x24))
#define RCC_AHB1ENR                  (*(vu32*)(RCC_BASE_ADDRESS+0x30))
#define RCC_AHB2ENR                  (*(vu32*)(RCC_BASE_ADDRESS+0x34))
#define RCC_APB1ENR                  (*(vu32*)(RCC_BASE_ADDRESS+0x40))
#define RCC_APB2ENR                  (*(vu32*)(RCC_BASE_ADDRESS+0x44))
#define RCC_AHB1LPENR                (*(vu32*)(RCC_BASE_ADDRESS+0x50))
#define RCC_AHB2LPENR                (*(vu32*)(RCC_BASE_ADDRESS+0x54))

#define RCC_APB1LPENR                (*(vu32*)(RCC_BASE_ADDRESS+0x60))
#define RCC_APB2LPENR                (*(vu32*)(RCC_BASE_ADDRESS+0x64))
#define RCC_BDCR                     (*(vu32*)(RCC_BASE_ADDRESS+0x70))
#define RCC_CSR                      (*(vu32*)(RCC_BASE_ADDRESS+0x74))
#define RCC_SSCGR                    (*(vu32*)(RCC_BASE_ADDRESS+0x80))
#define RCC_PLLI2SCFGR               (*(vu32*)(RCC_BASE_ADDRESS+0x84))
#define RCC_DCKCFGR                  (*(vu32*)(RCC_BASE_ADDRESS+0x8C))








#define PLLI2SRDY               27
#define PLLI2SON                26
#define PLLRDY                  25
#define PLLON                   24
#define CSSON                   19
#define HSEBYP                  18
#define HSERDY                  17
#define HSEON                   16
#define HSIRDY                  1
#define HSION                   0
//Bits 15:8 HSICAL[7:0]
//Bits 7:3 HSITRIM[4:0]:


///////////////////////////////////////////////
#define PLLSRC                  22


//f(VCO clock) = f(PLL clock input) × (PLLN / PLLM)
//f(PLL general clock output) = f(VCO clock) / PLLP
//f(USB OTG FS, SDIO, RNG clock output) = f(VCO clock) / PLLQ

//Bits 27:24 PLLQ  : Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks

//Bits 17:16 PLLP
#define PLLP0        16
#define PLLP1        17
//Bits 14:6 PLLN
//Bits 5:0 PLLM


/////////////////////////////////////////////////
/*
Bits 31:30 MCO2[1:0]: 
Microcontroller clock output 2
Set and cleared by software. Clock source selection may generate glitches on MCO2. It is 
highly recommended to configure these bits only after reset before enabling the external 
oscillators and the PLLs.
00: System clock (SYSCLK) selected
01: PLLI2S clock selected
10: HSE oscillator clock selected
11: PLL clock selected */
// Bits 29:27 MCO2PRE
// Bits 26:24 MCO1PRE
//Bit 23 I2SSRC: I2S clock selection

#define I2SSRC                 23

//Bits 22:21 MCO1: Microcontroller clock output 1
//Bits 20:16 RTCPRE
//Bits 15:13 PPRE2 
//Bits 12:10 PPRE1
//Bits 7:4 HPRE


/*
Bits 3:2 SWS: System clock switch status
Set and cleared by hardware to indicate which clock source is used as the system clock.
00: HSI oscillator used as the system clock
01: HSE oscillator used as the system clock
10: PLL used as the system clock
11: not applicable




Bits 1:0 SW: System clock switch
*/


#define SWS2              2
#define SWS3              3
#define SW0               0
#define SW1               1

///////////////////////////////////////////////////


/*
Bit 23 CSSC: Clock security system interrupt clear
This bit is set by software to clear the CSSF flag.
0: No effect
1: Clear CSSF flag
Bit 22 Reserved, must be kept at reset value.
Bit 21 PLLI2SRDYC: PLLI2S ready interrupt clear
This bit is set by software to clear the PLLI2SRDYF flag.
0: No effect
1: PLLI2SRDYF cleared
Bit 20 PLLRDYC: Main PLL(PLL) ready interrupt clear
This bit is set by software to clear the PLLRDYF flag.
0: No effect
1: PLLRDYF cleared
Bit 19 HSERDYC: HSE ready interrupt clear
This bit is set by software to clear the HSERDYF flag.
0: No effect
1: HSERDYF cleared
Bit 18 HSIRDYC: HSI ready interrupt clear
This bit is set software to clear the HSIRDYF flag.
0: No effect
1: HSIRDYF cleared
Bit 17 LSERDYC: LSE ready interrupt clear
This bit is set by software to clear the LSERDYF flag.
0: No effect
1: LSERDYF cleared
Bit 16 LSIRDYC: LSI ready interrupt clear
This bit is set by software to clear the LSIRDYF flag.
0: No effect
1: LSIRDYF cleared



Bits 15:14 Reserved, must be kept at reset value.
Bit 13 PLLI2SRDYIE: PLLI2S ready interrupt enable
Set and cleared by software to enable/disable interrupt caused by PLLI2S lock.
0: PLLI2S lock interrupt disabled
1: PLLI2S lock interrupt enabled
Bit 12 PLLRDYIE: Main PLL (PLL) ready interrupt enable
Set and cleared by software to enable/disable interrupt caused by PLL lock.
0: PLL lock interrupt disabled
1: PLL lock interrupt enabled
Bit 11 HSERDYIE: HSE ready interrupt enable
Set and cleared by software to enable/disable interrupt caused by the HSE oscillator 
stabilization.
0: HSE ready interrupt disabled
1: HSE ready interrupt enabled
Bit 10 HSIRDYIE: HSI ready interrupt enable
Set and cleared by software to enable/disable interrupt caused by the HSI oscillator 
stabilization.
0: HSI ready interrupt disabled
1: HSI ready interrupt enabled
Bit 9 LSERDYIE: LSE ready interrupt enable
Set and cleared by software to enable/disable interrupt caused by the LSE oscillator 
stabilization.
0: LSE ready interrupt disabled
1: LSE ready interrupt enabled
Bit 8 LSIRDYIE: LSI ready interrupt enable
Set and cleared by software to enable/disable interrupt caused by LSI oscillator 
stabilization.
0: LSI ready interrupt disabled
1: LSI ready interrupt enabled
Bit 7 CSSF: Clock security system interrupt flag
Set by hardware when a failure is detected in the HSE oscillator.
Cleared by software setting the CSSC bit.
0: No clock security interrupt caused by HSE clock failure
1: Clock security interrupt caused by HSE clock failure
Bit 6 Reserved, must be kept at reset value.
Bit 5 PLLI2SRDYF: PLLI2S ready interrupt flag
Set by hardware when the PLLI2S locks and PLLI2SRDYDIE is set.
Cleared by software setting the PLLRI2SDYC bit.
0: No clock ready interrupt caused by PLLI2S lock
1: Clock ready interrupt caused by PLLI2S lock
Bit 4 PLLRDYF: Main PLL (PLL) ready interrupt flag
Set by hardware when PLL locks and PLLRDYDIE is set.
Cleared by software setting the PLLRDYC bit.
0: No clock ready interrupt caused by PLL lock
1: Clock ready interrupt caused by PLL lock



Bit 3 HSERDYF: HSE ready interrupt flag
Set by hardware when External High Speed clock becomes stable and HSERDYDIE is set.
Cleared by software setting the HSERDYC bit.
0: No clock ready interrupt caused by the HSE oscillator
1: Clock ready interrupt caused by the HSE oscillator
Bit 2 HSIRDYF: HSI ready interrupt flag
Set by hardware when the Internal High Speed clock becomes stable and HSIRDYDIE is 
set.
Cleared by software setting the HSIRDYC bit.
0: No clock ready interrupt caused by the HSI oscillator
1: Clock ready interrupt caused by the HSI oscillator
Bit 1 LSERDYF: LSE ready interrupt flag
Set by hardware when the External Low Speed clock becomes stable and LSERDYDIE is 
set.
Cleared by software setting the LSERDYC bit.
0: No clock ready interrupt caused by the LSE oscillator
1: Clock ready interrupt caused by the LSE oscillator
Bit 0 LSIRDYF: LSI ready interrupt flag
Set by hardware when the internal low speed clock becomes stable and LSIRDYDIE is set.
Cleared by software setting the LSIRDYC bit.
0: No clock ready interrupt caused by the LSI oscillator
1: Clock ready interrupt caused by the LSI oscillator
*/


#define PLL_M_LOWEST_BOUND      2
#define PLL_M_HIGHEST_BOUND     63
#define PLL_N_LOWEST_BOUND      192
#define PLL_N_HIGHEST_BOUND     432

#define PLL_M_MASK              0xFFFFFFE0
#define PLL_N_MASK              0xFFFF803F
#define PLL_Q_MASK              0xF0FFFFFF
#endif