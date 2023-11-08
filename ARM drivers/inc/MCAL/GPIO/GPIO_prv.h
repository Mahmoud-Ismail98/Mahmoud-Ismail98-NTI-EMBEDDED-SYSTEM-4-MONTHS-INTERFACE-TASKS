#ifndef GPIO_PRV_H_
#define GPIO_PRV_H_
#include "Std_types.h"
#include "Bit_utils.h"

typedef struct 
{
	volatile u32 MODER;
	volatile u32 OTYPER;
	volatile u32 OSPEEDR;
	volatile u32 PUPDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 LCKR;
	volatile u32 AFRL;
	volatile u32 AFRH;
}GPIOx_t;

#define GPIOA ((GPIOx_t *)(0x40020000))

volatile GPIOx_t* GPIO[6] =
{
	(( GPIOx_t*)(0x40020000)),
	(( GPIOx_t*)0x40020400),
	(( GPIOx_t*)0x40020800),
	(( GPIOx_t*)0x40020C00),
	(( GPIOx_t*)0x40021000),
	(( GPIOx_t*)0x40021C00),
};

#define MODER_INPUT				0
#define MODER_OUTPUT			1
#define MODER_AF_OUTPUT			2
#define MODER_ANALOG			3

#define OTYPER_OUTPUT_PP			0
#define OTYPER_OUTPUT_OD			1

#define OSPEEDR_LOW					0
#define OSPEEDR_Medium				1
#define OSPEEDR_High				2
#define OSPEEDR_VHIGH				3

#define PUPDR_NO_PULLUPDOWN					0
#define PUPDR_PULLUP						1
#define PUPDR_PULLDOWN						2

#define ODR_LOW							0
#define ODR_HIGH						1

#define GPIO_MODE_OUTPUT_PP								2

#define GPIO_MODE_OUTPUT_OD								1

#define GPIO_MODE_INPUT       							0

#define GPIO_MODE_AF_PP									3

#define GPIO_MODE_AF_OD									4

#define GPIO_MODE_ANALOG								5

#endif
