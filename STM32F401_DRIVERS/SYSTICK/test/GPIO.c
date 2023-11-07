#include "Std_types.h"
#include "Bit_utils.h"
#include "GPIO.h"


typedef  struct{
	volatile u32 GPIOx_MODER;
	volatile u32 GPIOx_OTYPER;
	volatile u32 GPIOx_OSPEEDER;
	volatile u32 GPIOx_PUPDR;
	volatile u32 GPIOx_IDR;
	volatile u32 GPIOx_ODR;
	volatile u32 GPIOx_BSRR;
	volatile u32 GPIOx_LCKR;
	volatile u32 GPIOx_AFRL;
	volatile u32 GPIOx_AFRH;
} GPIO_t ;

#define GPIO_A_BASE        0x40020000
#define GPIO_B_BASE        0x40020400
#define GPIO_C_BASE        0x40020800

#define GPIOA    ((volatile GPIO_t*)(GPIO_A_BASE))
#define GPIOB    ((volatile GPIO_t*)(GPIO_B_BASE))
#define GPIOC    ((volatile GPIO_t*)(GPIO_C_BASE))



//GpioPinCfg_t led_configuraion={GPIO_MODE_u64_OUTPUT_PP,GPIO_PUPD_u32_FLOATING,GPIO_SPEED_MEDIUM,GPIO_PIN_00,GPIO_PORT_A};

Gpio_tenuErrorStatus Gpio_init(GpioPinCfg_t  *Add_CnfgStruct){

	Gpio_tenuErrorStatus ErrorStatus = Gpio_enuOk;
	GPIO_t* ARRY_GPIO[3]={GPIOA,GPIOB,GPIOC};
	u32 PORT= Add_CnfgStruct->gpio_port_x;
	u32 PIN= Add_CnfgStruct->gpio_pin_x;

	switch(Add_CnfgStruct->gpio_mode_x)
    {
	case GPIO_MODE_u64_OUTPUT_PP:
		ARRY_GPIO[PORT]->GPIOx_MODER  &= ~(0x00000003<<(PIN*2));
		ARRY_GPIO[PORT]->GPIOx_MODER  |=   (GPIO_MODE_u64_OUTPUT_PP<<(PIN*2));
	//	ARRY_GPIO[PORT]->GPIOx_OTYPER &= ~ (0<<PIN);
		CLR_BIT(ARRY_GPIO[PORT]->GPIOx_OTYPER,PIN);
		break;
	case  GPIO_MODE_u64_OUTPUT_OD:
		ARRY_GPIO[PORT]->GPIOx_MODER  &= ~ (0x00000003<<(PIN*2));
		SET_BIT(ARRY_GPIO[PORT]->GPIOx_OTYPER,PIN);
		break;
	case GPIO_MODE_u64_INPUT :
		ARRY_GPIO[PORT]->GPIOx_MODER &= ~ (0x00000003<<(PIN*2));
		break;
	default :
		ErrorStatus = Gpio_WrongModeError;
		break;
	}
switch(Add_CnfgStruct->gpio_Pull_x){
	case GPIO_PUPD_u32_FLOATING:
		ARRY_GPIO[PORT]->GPIOx_PUPDR &= ~ (GPIO_PUPD_u32_FLOATING<<PIN*2);
	break;

	case GPIO_PUPD_u32_PULL_UP:
		ARRY_GPIO[PORT]->GPIOx_PUPDR &= ~ (GPIO_PUPD_u32_FLOATING<<(PIN*2));
		ARRY_GPIO[PORT]->GPIOx_PUPDR |=   (GPIO_PUPD_u32_PULL_UP<<(PIN*2));
	break;
	case GPIO_PUPD_u32_PULL_DOWN:
		ARRY_GPIO[PORT]->GPIOx_PUPDR &= ~ (GPIO_PUPD_u32_FLOATING<<PIN*2);
		ARRY_GPIO[PORT]->GPIOx_PUPDR |=   (GPIO_PUPD_u32_PULL_DOWN<<PIN*2);
	break;
	default:
		ErrorStatus = Gpio_WrongPuPdError;
		break;
}
switch(Add_CnfgStruct->gpio_speed_x){
	case GPIO_SPEED_LOW:
		ARRY_GPIO[PORT]->GPIOx_OSPEEDER &= ~ (0x00000003 << (PIN*2 ));
	break;
	case GPIO_SPEED_MEDIUM :
		ARRY_GPIO[PORT]->GPIOx_OSPEEDER &= ~ (0x00000003 << (PIN*2));
		ARRY_GPIO[PORT]->GPIOx_OSPEEDER |=   (GPIO_SPEED_MEDIUM << (PIN*2));
	break;
	case GPIO_SPEED_HIGH:
		ARRY_GPIO[PORT]->GPIOx_OSPEEDER &= ~ (0x00000003 << (PIN*2));
		ARRY_GPIO[PORT]->GPIOx_OSPEEDER |=   (GPIO_SPEED_HIGH << (PIN*2));
		break;
	case GPIO_SPEED_VHIGH:
		ARRY_GPIO[PORT]->GPIOx_OSPEEDER &= ~ (0x00000003 << (PIN*2));
		ARRY_GPIO[PORT]->GPIOx_OSPEEDER |=   (GPIO_SPEED_VHIGH << (PIN*2));
		break;
	default:

		break;

}
return ErrorStatus ;
}

Gpio_tenuErrorStatus Gpio_setPinValue(GpioPinCfg_t  *Add_pu8CnfgStatus , u8 Copyu8PinValue)
{
	Gpio_tenuErrorStatus ErrorStatus = Gpio_enuOk;
	GPIO_t* ARRY_GPIO[3]={GPIOA,GPIOB,GPIOC};
	u8 PORT= Add_pu8CnfgStatus->gpio_port_x;
	u8 PIN= Add_pu8CnfgStatus->gpio_pin_x;
	switch (Copyu8PinValue)
	{
	case GPIO_ODR_HIGH:
	//	SET_BIT(ARRY_GPIO[PORT]->GPIOx_ODR,PIN);
		SET_BIT(ARRY_GPIO[PORT]->GPIOx_ODR,PIN);
		break;
	case GPIO_ODR_LOW:
		SET_BIT(ARRY_GPIO[PORT]->GPIOx_BSRR,PIN+16);
		break;
	default:
		break;
	}
	return ErrorStatus;
}


Gpio_tenuErrorStatus Gpio_readPinValue(GpioPinCfg_t  *Add_CnfgStruct , pu32 Add_pu8PinValue)
{
	Gpio_tenuErrorStatus ErrorStatus = Gpio_enuOk;
	GPIO_t* ARRY_GPIO[3]={GPIOA,GPIOB,GPIOC};
	u32 PORT= Add_CnfgStruct->gpio_port_x;
	u32 PIN= Add_CnfgStruct->gpio_pin_x;

	if(Add_CnfgStruct->gpio_mode_x  == GPIO_MODE_u64_INPUT )
	{
		*Add_pu8PinValue = GET_BIT((ARRY_GPIO[PORT]->GPIOx_IDR),PIN);
	}
	else
	{
		ErrorStatus =  Gpio_WrongReadError ;
	}
	return ErrorStatus = Gpio_enuOk;
}

Gpio_tenuErrorStatus Gpio_setPinnValue(u8 Copyu8Port ,u8 Copyu8Pin ,u8 Copyu8Value){
	Gpio_tenuErrorStatus ErrorStatus = Gpio_enuOk;
	GPIO_t* ARRY_GPIO[3]={GPIOA,GPIOB,GPIOC};
	switch(Copyu8Value)
		{
		case GPIO_ODR_HIGH :
    	   SET_BIT(ARRY_GPIO[Copyu8Port]->GPIOx_BSRR,Copyu8Pin);
		break;
		case GPIO_ODR_LOW :
					SET_BIT(ARRY_GPIO[Copyu8Port]->GPIOx_BSRR,(Copyu8Pin+16));
			break;
	   }
	return ErrorStatus = Gpio_enuOk;

}