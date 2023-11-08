#ifndef RCC_PRV_H_
#define RCC_PRV_H_
#include "Std_types.h"

typedef struct
{
	volatile u32 CR;
	volatile u32 PLLCFGR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 AHB1RSTR;
	volatile u32 AHB2RSTR;
	volatile u32 Reserved_0[2];
	volatile u32 APB1RSTR;
	volatile u32 APB2RSTR;
	volatile u32 Reserved_1[2];
	volatile u32 AHB1ENR;
	volatile u32 AHB2ENR;
	volatile u32 Reserved_2[2];
	volatile u32 APB1ENR;
	volatile u32 APB2ENR;
	volatile u32 Reserved_3[2];
	volatile u32 AHB1LPENR;
	volatile u32 AHB2LPENR;
	volatile u32 Reserved_4[2];
	volatile u32 APB1LPENR;
	volatile u32 APB2LPENR;
	volatile u32 Reserved_5[2];
	volatile u32 BDCR;
	volatile u32 CSR;	
	volatile u32 Reserved_6[2];
	volatile u32 SSCGR;	
	volatile u32 PLLI2SCFGR;
	volatile u32 Reserved_7;
	volatile u32 DCKCFGR;
}RCC_t;

//#define RCC ((RCC_t*)0x40023800)

#define HSION		0
#define HSIRDY		1
#define HSEON		16
#define HSERDY		17
#define PLLON		24
#define PLLRDY		25

#define PLLSRC		22
#endif
