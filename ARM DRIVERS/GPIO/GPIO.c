#include "std_types.h"
#include "bit_utils.h"

#include "GPIO.h"
#include "GPIO_cfg.h"


typedef struct GPIO_x
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
}GPIO_x;


#define GPIOA ((volatile GPIO_x*) 0x40020000)
#define GPIOB ((volatile GPIO_x*) 0x40020400)
#define GPIOC ((volatile GPIO_x*) 0x40020800)
#define GPIOD ((volatile GPIO_x*) 0x40020C00)
#define GPIOE ((volatile GPIO_x*) 0x40021000)
#define GPIOH ((volatile GPIO_x*) 0x40021C00)

GPIO_x* volatile ARR[6] = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOH};

Gpio_tenuErrorStatus Gpio_init(GpioPinCfg_t  *Add_CnfgStruct){
    Gpio_tenuErrorStatus local_errorState = Gpio_enuOk; 
    u8 port = Add_CnfgStruct->gpio_port_x;
    u8 pin = Add_CnfgStruct->gpio_pin_x;

    switch(Add_CnfgStruct->gpio_mode_x){
        case GPIO_MODE_u64_INPUT :
            Peripheral_BitBand(ARR[port]->MODER, pin*2)    = 0;
            Peripheral_BitBand(ARR[port]->MODER, pin*2 +1) = 0;
            break;
        case GPIO_MODE_u64_OUTPUT_PP :
            Peripheral_BitBand(ARR[port]->MODER, pin*2)    = 1;
            Peripheral_BitBand(ARR[port]->MODER, pin*2 +1) = 0;
            Peripheral_BitBand(ARR[port]->OTYPER, pin)     = 0;
            break;
        case GPIO_MODE_u64_OUTPUT_OD :
            Peripheral_BitBand(ARR[port]->MODER, pin*2)    = 1;
            Peripheral_BitBand(ARR[port]->MODER, pin*2 +1) = 0;
            Peripheral_BitBand(ARR[port]->OTYPER, pin)     = 1;
            break;
        case GPIO_MODE_u64_AF_PP :
            Peripheral_BitBand(ARR[port]->MODER, pin*2)    = 0;
            Peripheral_BitBand(ARR[port]->MODER, pin*2 +1) = 1;
            break;
        case GPIO_MODE_u64_AF_OD :
            Peripheral_BitBand(ARR[port]->MODER, pin*2)    = 0;
            Peripheral_BitBand(ARR[port]->MODER, pin*2 +1) = 1;
            break;
        case GPIO_MODE_u64_ANALOG :
            Peripheral_BitBand(ARR[port]->MODER, pin*2)    = 1;
            Peripheral_BitBand(ARR[port]->MODER, pin*2 +1) = 1;
            break;
    }

    switch(Add_CnfgStruct->gpio_Pull_x){
        case GPIO_PUPD_u32_FLOATING :
            Peripheral_BitBand(ARR[port]->PUPDR, pin*2)    = 0;
            Peripheral_BitBand(ARR[port]->PUPDR, pin*2 +1) = 0;
            break;
        case GPIO_PUPD_u32_PULL_UP :
            Peripheral_BitBand(ARR[port]->PUPDR, pin*2)    = 1;
            Peripheral_BitBand(ARR[port]->PUPDR, pin*2 +1) = 0;
            break;
        case GPIO_PUPD_u32_PULL_DOWN :
            Peripheral_BitBand(ARR[port]->PUPDR, pin*2)    = 0;
            Peripheral_BitBand(ARR[port]->PUPDR, pin*2 +1) = 1;
            break;
    }


    switch(Add_CnfgStruct->gpio_speed_x){
        case GPIO_SPEED_LOW :
            Peripheral_BitBand(ARR[port]->OSPEEDR, pin*2)    = 0;
            Peripheral_BitBand(ARR[port]->OSPEEDR, pin*2 +1) = 0;
            break;
        case GPIO_SPEED_MEDIUM :
            Peripheral_BitBand(ARR[port]->OSPEEDR, pin*2)    = 1;
            Peripheral_BitBand(ARR[port]->OSPEEDR, pin*2 +1) = 0;
            break;
        case GPIO_SPEED_HIGH :
            Peripheral_BitBand(ARR[port]->OSPEEDR, pin*2)    = 0;
            Peripheral_BitBand(ARR[port]->OSPEEDR, pin*2 +1) = 1;
            break;
        case GPIO_SPEED_VHIGH :
            Peripheral_BitBand(ARR[port]->OSPEEDR, pin*2)    = 1;
            Peripheral_BitBand(ARR[port]->OSPEEDR, pin*2 +1) = 1;
            break;
    }


    return local_errorState;

}

Gpio_tenuErrorStatus Gpio_setPinValue(GpioPinCfg_t  *Add_pu8CnfgStatus , u8 Copyu8PinValue){
    Gpio_tenuErrorStatus local_errorState = Gpio_enuOk; 
    
    u8 port = Add_pu8CnfgStatus->gpio_port_x;
    u8 pin = Add_pu8CnfgStatus->gpio_pin_x;
    Peripheral_BitBand(ARR[port]->ODR, pin) = Copyu8PinValue;
    return local_errorState;
}

Gpio_tenuErrorStatus Gpio_setPinnValue(u8 Copyu8Port ,u8 Copyu8Pin ,u8 Copyu8Value){
    Gpio_tenuErrorStatus local_errorState = Gpio_enuOk; 
    Peripheral_BitBand(ARR[Copyu8Port]->ODR, Copyu8Pin) = Copyu8Value;
    return local_errorState;
}

Gpio_tenuErrorStatus Gpio_readPinValue(GpioPinCfg_t  *Add_CnfgStruct , pu32 Add_pu8PinValue){
    Gpio_tenuErrorStatus local_errorState = Gpio_enuOk; 
    
    u8 port = Add_CnfgStruct->gpio_port_x;
    u8 pin = Add_CnfgStruct->gpio_pin_x;
    *Add_pu8PinValue = Peripheral_BitBand(ARR[port]->IDR, pin) ;
    return local_errorState;

}

Gpio_tenuErrorStatus Gpio_SetAlternateFunction(GpioPinCfg_t  *Add_CnfgStruct , u8 CopyAF){
    Gpio_tenuErrorStatus local_errorState = Gpio_enuOk; 
    
    u8 port = Add_CnfgStruct->gpio_port_x;
    u8 pin = Add_CnfgStruct->gpio_pin_x;

    
    if (pin < 8){
        u32 local_u32_mask  = 0xF << pin*4;
        u32 local_u32_value = CopyAF << pin*4 ;
        ARR[port]->AFRL  &= !local_u32_mask;
        ARR[port]->AFRL  |= local_u32_value;
    }else if(pin < 16){
        pin -= 8;
        u32 local_u32_mask  = 0xF << pin*4;
        u32 local_u32_value = CopyAF << pin*4 ;
        ARR[port]->AFRH  &= !local_u32_mask;
        ARR[port]->AFRH  |= local_u32_value;

    }

    return local_errorState;

}