#ifndef GPIO_PRV_H
#define GPIO_PRV_H

#define GPIOA_BASE_ADDRESS	   0x40020000
#define GPIOB_BASE_ADDRESS	   0x40020400
#define GPIOC_BASE_ADDRESS	   0x40020800
#define GPIOD_BASE_ADDRESS	   0x40020C00
#define GPIOE_BASE_ADDRESS	   0x40021000
#define GPIOH_BASE_ADDRESS	   0x40021C00

typedef struct{
	 volatile u32 MODER  ;
	 volatile u32 OTYPER ;
	 volatile u32 OSPEEDR;
	 volatile u32 PUPDR  ;
	 volatile u32 IDR    ;
	 volatile u32 ODR    ;
	 volatile u32 BSRR   ;
	 volatile u32 LCKR   ;
	 volatile u32 AFRL   ;
	 volatile u32 AFRH   ;
}GPIOx_t;

#define MGPIO_PORTA_REG     ((GPIOx_t *)GPIOA_BASE_ADDRESS)
#define MGPIO_PORTB_REG     ((GPIOx_t *)GPIOB_BASE_ADDRESS)
#define MGPIO_PORTC_REG     ((GPIOx_t *)GPIOC_BASE_ADDRESS)
#define MGPIO_PORTD_REG     ((GPIOx_t *)GPIOD_BASE_ADDRESS)
#define MGPIO_PORTE_REG     ((GPIOx_t *)GPIOE_BASE_ADDRESS)
#define MGPIO_PORTH_REG     ((GPIOx_t *)GPIOH_BASE_ADDRESS)



#endif