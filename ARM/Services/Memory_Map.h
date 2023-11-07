/*
 * Memory_Map.h
 *
 *  Created on: Nov 5, 2023
 *      Author: computer store
 */

#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_

#include <Services/Std_types.h>

//==================================================================
//stm32f401CC base addresses
//==================================================================
#define Peripheral_Base_Address	 			(0x40000000UL)
#define Peripheral_Alias_Base				(0x42000000UL)


//GPIO
#define GPIOA_Base_Address					(0x40020000UL)
#define GPIOB_Base_Address					(0x40020400UL)
#define GPIOC_Base_Address					(0x40020800UL)
#define GPIOD_Base_Address					(0x40020C00UL)		//has no pins in stm32f401_cc_ux (Package: UFQFPN48)
#define GPIOE_Base_Address					(0x40021000UL)		//has no pins in stm32f401_cc_ux (Package: UFQFPN48)
#define GPIOH_Base_Address					(0x40021C00UL)


//RCC
#define RCC_Base_Address					(0x40023800UL)


//==================================================================
//stm32f401CC bit band access for atomic instructions
//==================================================================
#define Bit_Band_Peripheral(Reg, Bit)	(*(volatile unsigned int *)( Peripheral_Alias_Base + (((uint32)&Reg - Peripheral_Base_Address) * 32) + Bit*4 ))


//==================================================================
//stm32f401CC user defined data types
//==================================================================

typedef struct
{
	volatile uint32 MODER;
	volatile uint32 OTYPER;
	volatile uint32 OSPEEDR;
	volatile uint32 PUPDR;
	volatile uint32 IDR;
	volatile uint32 ODR;
	volatile uint32 BSRR;
	volatile uint32 LCKR;
	volatile uint32 AFRL;
	volatile uint32 AFRH;
}GPIOx_t;

typedef struct
{
	volatile uint32 RCC_CR;
	volatile uint32 RCC_PLLCFGR;
	volatile uint32 RCC_CFGR;
	volatile uint32 RCC_CIR;
	volatile uint32 RCC_AHB1RSTR;
	volatile uint32 RCC_AHB2RSTR;
	volatile uint32 Reserved0[2];
	volatile uint32 RCC_APB1RSTR;
	volatile uint32 RCC_APB2RSTR;
	volatile uint32 Reserved1[2];
	volatile uint32 RCC_AHB1ENR;
	volatile uint32 RCC_AHB2ENR;
	volatile uint32 Reserved2[2];
	volatile uint32 RCC_APB1ENR;
	volatile uint32 RCC_APB2ENR;
	volatile uint32 Reserved3[2];
	volatile uint32 RCC_AHB1LPENR;
	volatile uint32 RCC_AHB2LPENR;
	volatile uint32 Reserved4[2];
	volatile uint32 RCC_APB1LPENR;
	volatile uint32 RCC_APB2LPENR;
	volatile uint32 Reserved5[2];
	volatile uint32 RCC_BDCR;
	volatile uint32 RCC_CSR;
	volatile uint32 Reserved6[2];
	volatile uint32 RCC_SSCGR;
	volatile uint32 RCC_PLLI2SCFGR;
	volatile uint32 RCC_DCKCFGR;
}RCC_t;

//GPIO
#define GPIOA	((GPIOx_t*)(GPIOA_Base_Address))
#define GPIOB	((GPIOx_t*)(GPIOB_Base_Address))
#define GPIOC	((GPIOx_t*)(GPIOC_Base_Address))
#define GPIOD	((GPIOx_t*)(GPIOD_Base_Address))
#define GPIOE	((GPIOx_t*)(GPIOE_Base_Address))
#define GPIOH	((GPIOx_t*)(GPIOH_Base_Address))




#define RCC		((RCC_t*)(RCC_Base_Address))


#endif /* MEMORY_MAP_H_ */
