/*
 * GPIO.c
 *
 *  Created on: Nov 6, 2023
 *      Author: computer store
 */

#ifndef GPIO_GPIO_SRC_GPIO_C_
#define GPIO_GPIO_SRC_GPIO_C_
#include <MCAL/GPIO/GPIO_Includes/Gpio.h>
#include <MCAL/GPIO/GPIO_Includes/GPIO_CFG.h>


static GPIOx_t* (Loc_Arr_Gpiox[6]) = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOH};


void GPIO_Init_Static2(uint32 GPIO_PORTx)
{
	if(GPIO_PORTx == GPIO_PORT_A)
	{
		for(uint8 PINx=0; PINx < 16; PINx++)
		{
			GpioPinCfg_t PIN_CFG = GPIOA_PINx_CFG[PINx];
			Gpio_init(&PIN_CFG);
		}
	}
	else if(GPIO_PORTx == GPIO_PORT_B)
	{
		for(uint8 PINx=0; PINx < 16; PINx++)
		{
			GpioPinCfg_t PIN_CFG = GPIOB_PINx_CFG[PINx];
			Gpio_init(&PIN_CFG);
		}
	}


	else if(GPIO_PORTx == GPIO_PORT_C)
	{
		for(uint8 PINx=0; PINx < 16; PINx++)
		{
			GpioPinCfg_t PIN_CFG = GPIOC_PINx_CFG[PINx];
			Gpio_init(&PIN_CFG);
		}
	}

	else if(GPIO_PORTx == GPIO_PORT_D)
	{
		for(uint8 PINx=0; PINx < 16; PINx++)
		{
			GpioPinCfg_t PIN_CFG = GPIOD_PINx_CFG[PINx];
			Gpio_init(&PIN_CFG);
		}
	}

	else if(GPIO_PORTx == GPIO_PORT_E)
	{
		for(uint8 PINx=0; PINx < 16; PINx++)
		{
			GpioPinCfg_t PIN_CFG = GPIOE_PINx_CFG[PINx];
			Gpio_init(&PIN_CFG);
		}
	}

	else if(GPIO_PORTx == GPIO_PORT_H)
	{
		for(uint8 PINx=0; PINx < 16; PINx++)
		{
			GpioPinCfg_t PIN_CFG = GPIOH_PINx_CFG[PINx];
			Gpio_init(&PIN_CFG);
		}
	}
}


Gpio_tenuErrorStatus Gpio_init(GpioPinCfg_t  *Add_CnfgStruct)
{
	//clear
	Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->MODER &= ~(3 << (Add_CnfgStruct->gpio_pin_x * 2));
	Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->PUPDR &= ~(3 << (Add_CnfgStruct->gpio_pin_x * 2));
	Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->OTYPER &= ~(1 << (Add_CnfgStruct->gpio_pin_x));
	Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->OSPEEDR &= ~(3 << (Add_CnfgStruct->gpio_pin_x * 2));

	switch (Add_CnfgStruct->gpio_mode_x)
	{

	case GPIO_MODE_INPUT:
		//set configurations
		Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->MODER |= GPIO_Input << (Add_CnfgStruct->gpio_pin_x * 2);
		Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->PUPDR |= (Add_CnfgStruct->gpio_Pull_x) << (Add_CnfgStruct->gpio_pin_x * 2);
		break;

	case GPIO_MODE_OUTPUT_PP:

		Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->MODER |= GPIO_Output << (Add_CnfgStruct->gpio_pin_x * 2);
		Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->OTYPER |= GPIO_Output_PP << (Add_CnfgStruct->gpio_pin_x);
		Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->PUPDR |= Add_CnfgStruct->gpio_Pull_x << (Add_CnfgStruct->gpio_pin_x * 2);
		Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->OSPEEDR |= Add_CnfgStruct->gpio_speed_x << (Add_CnfgStruct->gpio_pin_x * 2);

		break;

	case GPIO_MODE_OUTPUT_OD:
		Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->MODER |= GPIO_Output << (Add_CnfgStruct->gpio_pin_x * 2);
		Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->OTYPER |= GPIO_Output_OD << (Add_CnfgStruct->gpio_pin_x);
		Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->PUPDR |= Add_CnfgStruct->gpio_Pull_x << (Add_CnfgStruct->gpio_pin_x * 2);
		Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->OSPEEDR |= Add_CnfgStruct->gpio_speed_x << (Add_CnfgStruct->gpio_pin_x * 2);
		break;

	case GPIO_MODE_AF:
		Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->MODER |= GPIO_AF << (Add_CnfgStruct->gpio_pin_x * 2);
		Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->PUPDR |= Add_CnfgStruct->gpio_Pull_x << (Add_CnfgStruct->gpio_pin_x * 2);
		break;

	case GPIO_MODE_ANALOG:
		Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->MODER |= GPIO_Analog << (Add_CnfgStruct->gpio_pin_x * 2);
		break;
	}

	return Gpio_enuOk;
}

Gpio_tenuErrorStatus Gpio_setPinValue1(GpioPinCfg_t  *Add_pu32CnfgStatus , uint32 Copyu32PinValue)
{
	Bit_Band_Peripheral(Loc_Arr_Gpiox[Add_pu32CnfgStatus->gpio_port_x]->ODR, Add_pu32CnfgStatus->gpio_pin_x) = Copyu32PinValue;
	return Gpio_enuOk;
}

Gpio_tenuErrorStatus Gpio_setPinValue2(uint32 Copyu32Port ,uint32 Copyu32Pin ,uint32 Copyu32Value)
{
	Bit_Band_Peripheral(Loc_Arr_Gpiox[Copyu32Port]->ODR, Copyu32Pin) = Copyu32Value;
	return Gpio_enuOk;
}

Gpio_tenuErrorStatus Gpio_readPinValue(GpioPinCfg_t  *Add_CnfgStruct , Puint32 Add_pu32PinValue)
{
	*Add_pu32PinValue = (uint8)Bit_Band_Peripheral(Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->IDR, Add_CnfgStruct->gpio_pin_x);
	return Gpio_enuOk;
}

Gpio_tenuErrorStatus Gpio_SetAlternateFunction(GpioPinCfg_t  *Add_CnfgStruct , uint32 CopyAF)
{
	if(0 <= Add_CnfgStruct->gpio_pin_x && Add_CnfgStruct->gpio_pin_x <= 7)
	{
		Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->AFRL &= ~(0x0F << (Add_CnfgStruct->gpio_pin_x * 4));
		Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->AFRL |= (CopyAF << (Add_CnfgStruct->gpio_pin_x * 4));
	}
	else if(8 <= Add_CnfgStruct->gpio_pin_x && Add_CnfgStruct->gpio_pin_x <= 15)
	{
		Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->AFRH &= ~(0x0F << ((Add_CnfgStruct->gpio_pin_x - 8) * 4));
		Loc_Arr_Gpiox[Add_CnfgStruct->gpio_port_x]->AFRH |= (CopyAF << ((Add_CnfgStruct->gpio_pin_x - 8) * 4));
	}
	return Gpio_enuOk;
}

Gpio_tenuErrorStatus Gpio_LockPin(uint32 Copyu32Port ,uint32 Copyu32Pin[16])
{
	for(uint8 PINx = 0; PINx < 16; PINx++)
	{
			Bit_Band_Peripheral(Loc_Arr_Gpiox[Copyu32Port]->LCKR, PINx) = Copyu32Pin[PINx] ;
	}
	uint32 temp_reg = Loc_Arr_Gpiox[Copyu32Port]->LCKR;
	temp_reg |= (1 << 16);
	Loc_Arr_Gpiox[Copyu32Port]->LCKR = temp_reg;
	temp_reg &= ~(1 << 16);
	Loc_Arr_Gpiox[Copyu32Port]->LCKR = temp_reg;
	temp_reg |= (1 << 16);
	Loc_Arr_Gpiox[Copyu32Port]->LCKR = temp_reg;
	return Gpio_enuOk;

}

#endif /* GPIO_GPIO_SRC_GPIO_C_ */
