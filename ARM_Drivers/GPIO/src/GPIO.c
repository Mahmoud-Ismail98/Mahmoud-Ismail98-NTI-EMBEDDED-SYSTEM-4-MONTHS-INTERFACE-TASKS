
#include "std_type.h"
#include "util.h"
#include "GPIO.h"

Gpio_tenuErrorStatus Gpio_init(GpioPinCfg_t  *Add_CnfgStruct)
{
	Gpio_tenuErrorStatus ERROR_STATE = Gpio_enuOk;
	GPIO_t *GPIO_ARR[]={ GPIO_A, GPIO_B, GPIO_C, GPIO_D, GPIO_E, GPIO_H};
	u8 Local_u8Port = Add_CnfgStruct -> gpio_port_x;
	u8 Local_u8Pin = Add_CnfgStruct -> gpio_pin_x;

	if (Local_u8Pin > 15){
		ERROR_STATE = Gpio_WrongPinNumError;

	}
	if (Local_u8Port > 5){
		ERROR_STATE = Gpio_WrongPortNumError;
	}
	switch (Add_CnfgStruct -> gpio_mode_x)
	{
	case GPIO_MODE_u64_OUTPUT_PP:
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_MODER ,Local_u8Pin*2)=0;
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_MODER ,Local_u8Pin*2)=1;
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_OTYPER ,Local_u8Pin)=0;
		break;
	case GPIO_MODE_u64_OUTPUT_OD:
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_MODER ,Local_u8Pin*2)=0;
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_MODER ,Local_u8Pin*2)=1;
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_OTYPER ,Local_u8Pin)=1;
		break;
	case GPIO_MODE_u64_INPUT:
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_MODER ,Local_u8Pin*2)=0;
		break;
	case GPIO_MODE_u64_AF_PP:
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_MODER ,Local_u8Pin*2)=1;
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_MODER ,Local_u8Pin*2)=0;
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_OTYPER ,Local_u8Pin)=0;
		break;
	case GPIO_MODE_u64_AF_OD:
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_MODER ,Local_u8Pin*2)=0;
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_MODER ,Local_u8Pin*2)=1;
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_OTYPER ,Local_u8Pin)=1;
		break;
	case GPIO_MODE_u64_ANALOG:
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_MODER ,Local_u8Pin*2)=0;
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_MODER ,Local_u8Pin*2)=1;
		break;
    default : ERROR_STATE = Gpio_WrongModeError; break;
	}
	switch (Add_CnfgStruct -> gpio_Pull_x)
	{
	case GPIO_PUPD_u32_FLOATING:
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_PUPDR ,Local_u8Pin*2)=0;
		break;
	case GPIO_PUPD_u32_PULL_UP:
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_PUPDR ,Local_u8Pin*2)=0;
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_PUPDR ,Local_u8Pin*2)=1;
		break;
	case GPIO_PUPD_u32_PULL_DOWN:
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_PUPDR ,Local_u8Pin*2)=0;
		Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_PUPDR ,Local_u8Pin*2)=2;
		break;
	default: ERROR_STATE = Gpio_WrongPuPdError ;break;

	}
	switch (Add_CnfgStruct -> gpio_speed_x)
		{
		case GPIO_SPEED_LOW:
			Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_OSPEEDER ,Local_u8Pin*2)=0;
			break;
		case GPIO_SPEED_MEDIUM:
			Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_OSPEEDER ,Local_u8Pin*2)=0;
			Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_OSPEEDER ,Local_u8Pin*2)=1;
			break;
		case GPIO_SPEED_HIGH:
			Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_OSPEEDER ,Local_u8Pin*2)=0;
			Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_OSPEEDER ,Local_u8Pin*2)=2;
			break;
		case GPIO_SPEED_VHIGH:
			Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_OSPEEDER ,Local_u8Pin*2)=0;
			Peripheral_BitBand(GPIO_ARR[Local_u8Port] -> GPIOx_OSPEEDER ,Local_u8Pin*2)=3;
			break;

		default: ERROR_STATE = Gpio_WrongSpeedError; break;

		}

	return ERROR_STATE;

}
Gpio_tenuErrorStatus Gpio_setPinValue(GpioPinCfg_t  *Add_pu8CnfgStatus , u8 Copyu8PinValue)
{
	Gpio_tenuErrorStatus ERROR_STATE = Gpio_enuOk;
	GPIO_t *GPIO_ARR[]={ GPIO_A, GPIO_B, GPIO_C, GPIO_D, GPIO_E, GPIO_H};
		u8 Local_u8Port = Add_pu8CnfgStatus -> gpio_port_x;
		u8 Local_u8Pin = Add_pu8CnfgStatus -> gpio_pin_x;

	if (Local_u8Pin > 15){
			ERROR_STATE = Gpio_WrongPinNumError;

		}
	else if (Local_u8Port > 5){
			ERROR_STATE = Gpio_WrongPortNumError;
		}
	else
	{
		switch (Copyu8PinValue){
		case GPIO_ODR_HIGH:
			/* Set Pin Value */
				Peripheral_BitBand(GPIO_ARR[Local_u8Port]-> GPIOx_ODR ,Local_u8Pin)= 1;
				break;
				/* RESET Pin Value */
		case GPIO_ODR_LOW:{
			Peripheral_BitBand(GPIO_ARR[Local_u8Port]->  GPIOx_ODR ,Local_u8Pin)   = 0;

			}break;
		}
	}
	return ERROR_STATE = Gpio_enuOk ;
}

Gpio_tenuErrorStatus Gpio_setPinnValue(u8 Copyu8Port ,u8 Copyu8Pin ,u8 Copyu8Value)
{
	Gpio_tenuErrorStatus ERROR_STATE = Gpio_enuOk;
	GPIO_t *GPIO_ARR[]={ GPIO_A, GPIO_B, GPIO_C, GPIO_D, GPIO_E, GPIO_H};

	if ((Copyu8Pin > 16) || (Copyu8Port > 5)){
			ERROR_STATE = Gpio_WrongPinNumError;

		}

		else if (Copyu8Value == GPIO_ODR_HIGH ){
			
			Peripheral_BitBand(GPIO_ARR[Copyu8Port] -> GPIOx_BSRR,Copyu8Pin) = 1;
		
		}
	else 
	{
			Peripheral_BitBand(GPIO_ARR[Copyu8Port] -> GPIOx_BSRR,Copyu8Pin+16) = 1;
		}
	
	return ERROR_STATE;
}
Gpio_tenuErrorStatus Gpio_readPinValue(GpioPinCfg_t  *Add_CnfgStruct , pu32 Add_pu8PinValue)
{
	Gpio_tenuErrorStatus ERROR_STATE = Gpio_enuOk;
	GPIO_t *GPIO_ARR[]={ GPIO_A, GPIO_B, GPIO_C, GPIO_D, GPIO_E, GPIO_H};
			u8 Local_u8Port = Add_CnfgStruct -> gpio_port_x;
			u8 Local_u8Pin = Add_CnfgStruct -> gpio_pin_x;
			if (Local_u8Pin > 15){
						ERROR_STATE = Gpio_WrongPinNumError;

					}
		 if (Local_u8Port > 5){
						ERROR_STATE = Gpio_WrongPortNumError;
					}
	
if (Add_CnfgStruct -> gpio_mode_x == GPIO_MODE_u64_INPUT){

	*Add_pu8PinValue= GET_BIT(GPIO_ARR[Local_u8Port]->GPIOx_IDR,Local_u8Pin);
}
else {
	ERROR_STATE =Gpio_WrongReadError;
}

	return ERROR_STATE;
}
Gpio_tenuErrorStatus Gpio_SetAlternateFunction(GpioPinCfg_t  *Add_CnfgStruct , u8 CopyAF)
{

	Gpio_tenuErrorStatus ERROR_STATE = Gpio_enuOk;

	GPIO_t *GPIO_ARR[]={ GPIO_A, GPIO_B, GPIO_C, GPIO_D, GPIO_E, GPIO_H};
				u64 Local_u8Port = Add_CnfgStruct -> gpio_port_x;
				u64 Local_u8Pin = Add_CnfgStruct -> gpio_pin_x;
				if (Local_u8Pin > 15){
							ERROR_STATE = Gpio_WrongPinNumError;

						}
				 if (Local_u8Port > 5){
							ERROR_STATE = Gpio_WrongPortNumError;
						}
						
							switch (CopyAF){
							case GPIO_AF_0:
								GPIO_ARR[Local_u8Port]->GPIOx_AFRL &= ~(0x0000000F<< GPIO_PIN_00*4);
								GPIO_ARR[Local_u8Port]->GPIOx_AFRL |= (GPIO_AF_0 << Local_u8Pin*4);
								break;
							case GPIO_AF_1:GPIO_ARR[Local_u8Port]->GPIOx_AFRL &= ~(0x0000000F<< GPIO_PIN_00*4);
							GPIO_ARR[Local_u8Port]->GPIOx_AFRL |= (GPIO_AF_1 << Local_u8Pin*4);
								break;
							case GPIO_AF_2:GPIO_ARR[Local_u8Port]->GPIOx_AFRL &= ~(0x0000000F<< GPIO_PIN_00*4);
							GPIO_ARR[Local_u8Port]->GPIOx_AFRL |= (GPIO_AF_2 << Local_u8Pin*4);
								break;
							case GPIO_AF_3:GPIO_ARR[Local_u8Port]->GPIOx_AFRL &= ~(0x0000000F<< GPIO_PIN_00*4);
							GPIO_ARR[Local_u8Port]->GPIOx_AFRL |= (GPIO_AF_3 << Local_u8Pin*4);
								break;
							case GPIO_AF_4:GPIO_ARR[Local_u8Port]->GPIOx_AFRL &= ~(0x0000000F<< GPIO_PIN_00*4);
							GPIO_ARR[Local_u8Port]->GPIOx_AFRL |= (GPIO_AF_4 << Local_u8Pin*4);
								break;
							case GPIO_AF_5:GPIO_ARR[Local_u8Port]->GPIOx_AFRL &= ~(0x0000000F<< GPIO_PIN_00*4);
							GPIO_ARR[Local_u8Port]->GPIOx_AFRL |= (GPIO_AF_5 << Local_u8Pin*4);
								break;
							case GPIO_AF_6:GPIO_ARR[Local_u8Port]->GPIOx_AFRL &= ~(0x0000000F<< GPIO_PIN_00*4);
							GPIO_ARR[Local_u8Port]->GPIOx_AFRL |= (GPIO_AF_6 << Local_u8Pin*4);
								break;
							case GPIO_AF_7:GPIO_ARR[Local_u8Port]->GPIOx_AFRL &= ~(0x0000000F<< GPIO_PIN_00*4);
							GPIO_ARR[Local_u8Port]->GPIOx_AFRL |= (GPIO_AF_7 << Local_u8Pin*4);
								break;
							case GPIO_AF_8:GPIO_ARR[Local_u8Port]->GPIOx_AFRL &= ~(0x0000000F<< GPIO_PIN_00*4);
							GPIO_ARR[Local_u8Port]->GPIOx_AFRL |= (GPIO_AF_8 << Local_u8Pin*4);
								break;
							case GPIO_AF_9:GPIO_ARR[Local_u8Port]->GPIOx_AFRL &= ~(0x0000000F<< GPIO_PIN_00*4);
							GPIO_ARR[Local_u8Port]->GPIOx_AFRL |= (GPIO_AF_9 << Local_u8Pin*4);
								break;
							case GPIO_AF_10:GPIO_ARR[Local_u8Port]->GPIOx_AFRL &= ~(0x0000000F<< GPIO_PIN_00*4);
							GPIO_ARR[Local_u8Port]->GPIOx_AFRL |= (GPIO_AF_10 << Local_u8Pin*4);
								break;
							case GPIO_AF_11:GPIO_ARR[Local_u8Port]->GPIOx_AFRL &= ~(0x0000000F<< GPIO_PIN_00*4);
							GPIO_ARR[Local_u8Port]->GPIOx_AFRL |= (GPIO_AF_11 << Local_u8Pin*4);
								break;
							case GPIO_AF_12:GPIO_ARR[Local_u8Port]->GPIOx_AFRL &= ~(0x0000000F<< GPIO_PIN_00*4);
							GPIO_ARR[Local_u8Port]->GPIOx_AFRL |= (GPIO_AF_12 << Local_u8Pin*4);
								break;
							case GPIO_AF_13:GPIO_ARR[Local_u8Port]->GPIOx_AFRL &= ~(0x0000000F<< GPIO_PIN_00*4);
							GPIO_ARR[Local_u8Port]->GPIOx_AFRL |= (GPIO_AF_13 << Local_u8Pin*4);
								break;
							case GPIO_AF_14:GPIO_ARR[Local_u8Port]->GPIOx_AFRL &= ~(0x0000000F<< GPIO_PIN_00*4);
							GPIO_ARR[Local_u8Port]->GPIOx_AFRL |= (GPIO_AF_14 << Local_u8Pin*4);
								break;
							case GPIO_AF_15:GPIO_ARR[Local_u8Port]->GPIOx_AFRL &= ~(0x0000000F<< GPIO_PIN_00*4);
							GPIO_ARR[Local_u8Port]->GPIOx_AFRL |= (GPIO_AF_15 << Local_u8Pin*4);
								break;
							}
						




	return ERROR_STATE;
}
