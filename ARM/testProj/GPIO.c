
#include "bit_math.h"
#include "std_types.h"
#include "helpers.h"
#include "GPIO_prv.h"
#include "GPIO_cfg.h"
#include "GPIO.h"


/*
  Gpio_enuOk,
	Gpio_WrongPinNumError,
	Gpio_WrongPortNumError,
	Gpio_WrongModeError,
	Gpio_WrongPuPdError,
	Gpio_WrongSpeedError,
	Gpio_WrongValueError,
	Gpio_WrongReadError,
	Gpio_WrongAFError
*/

Gpio_tenuErrorStatus Gpio_init(GpioPinCfg_t  *Add_CnfgStruct)
{
	Gpio_tenuErrorStatus loc_enu_returnStatus = Gpio_enuOk;
	GPIOx_t *loc_ptr_GPIOx[6] = {GPIO_A,GPIO_B,GPIO_C,GPIO_D,GPIO_E,GPIO_H};
	u8 loc_u8_portNumber = Add_CnfgStruct->gpio_port_x;
	u8 loc_u8_pinNumber  = Add_CnfgStruct->gpio_pin_x;
	
	if ( loc_u8_portNumber > MAX_PORT_NUMBER)
	{
		loc_enu_returnStatus = Gpio_WrongPortNumError;
	}
	else if ( loc_u8_pinNumber > MAX_PIN_NUMBER)
	{
		loc_enu_returnStatus = Gpio_WrongPinNumError;
	}
	else
	{
		switch(Add_CnfgStruct->gpio_mode_x)
		{
			case GPIO_MODE_u64_OUTPUT_PP:
			  BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_MODER,loc_u8_pinNumber*2)   = TRUE;
			  BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_MODER,loc_u8_pinNumber*2+1) = FALSE;
			  BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_OTYPER,loc_u8_pinNumber)    = FALSE;
			  break;					
      case GPIO_MODE_u64_OUTPUT_OD:
				BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_MODER,loc_u8_pinNumber*2)   = TRUE;
			  BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_MODER,loc_u8_pinNumber*2+1) = FALSE;
			  BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_OTYPER,loc_u8_pinNumber)    = TRUE;
			  break;									   
      case GPIO_MODE_u64_INPUT:
				BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_MODER,loc_u8_pinNumber*2)   = FALSE;
			  BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_MODER,loc_u8_pinNumber*2+1) = FALSE;
			  break;				
      case GPIO_MODE_u64_AF_PP:
				BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_MODER,loc_u8_pinNumber*2)   = FALSE;
			  BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_MODER,loc_u8_pinNumber*2+1) = TRUE;
			  BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_OTYPER,loc_u8_pinNumber)    = FALSE;
			  break;									  
      case GPIO_MODE_u64_AF_OD:
				BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_MODER,loc_u8_pinNumber*2)   = FALSE;
			  BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_MODER,loc_u8_pinNumber*2+1) = TRUE;
			  BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_OTYPER,loc_u8_pinNumber)    = TRUE;
				break;					   
      case GPIO_MODE_u64_ANALOG:
				BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_MODER,loc_u8_pinNumber*2)   = TRUE;
			  BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_MODER,loc_u8_pinNumber*2+1) = TRUE;
				break;
			default : loc_enu_returnStatus = Gpio_WrongModeError;
		}
		
		// case error
		if ( loc_enu_returnStatus != Gpio_enuOk)
		{
			// do nothing
		}
		else
		{
			switch (Add_CnfgStruct->gpio_Pull_x)
			{
				case GPIO_PUPD_u32_PULL_DOWN :
					BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_PUDR,loc_u8_pinNumber*2)   = FALSE;
			    BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_PUDR,loc_u8_pinNumber*2+1) = TRUE;
					break;
				case GPIO_PUPD_u32_FLOATING  :
					BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_PUDR,loc_u8_pinNumber*2)   = FALSE;
			    BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_PUDR,loc_u8_pinNumber*2+1) = FALSE;
					break;
				case GPIO_PUPD_u32_PULL_UP   :
					BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_PUDR,loc_u8_pinNumber*2)   = TRUE;
			    BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_PUDR,loc_u8_pinNumber*2+1) = FALSE;
					break;
				default : loc_enu_returnStatus = Gpio_WrongPuPdError;
			}
			// case error
			if ( loc_enu_returnStatus != Gpio_enuOk)
			{
				// do nothing
			}
			else
			{
				switch (Add_CnfgStruct->gpio_speed_x)
				{
		
					case GPIO_SPEED_LOW :
						BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_OSPEEDER,loc_u8_pinNumber*2)   = FALSE;
						BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_OSPEEDER,loc_u8_pinNumber*2+1) = FALSE;
						break;
					case GPIO_SPEED_MEDIUM  :
						BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_OSPEEDER,loc_u8_pinNumber*2)   = TRUE;
						BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_OSPEEDER,loc_u8_pinNumber*2+1) = FALSE;
						break;
					case GPIO_SPEED_HIGH   :
						BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_OSPEEDER,loc_u8_pinNumber*2)   = FALSE;
						BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_OSPEEDER,loc_u8_pinNumber*2+1) = TRUE;
						break;
					case GPIO_SPEED_VHIGH   :
						BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_OSPEEDER,loc_u8_pinNumber*2)   = TRUE;
						BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_OSPEEDER,loc_u8_pinNumber*2+1) = TRUE;
						break;
					default : loc_enu_returnStatus = Gpio_WrongSpeedError;
				}
			}
		}
	}
	return loc_enu_returnStatus;
}
Gpio_tenuErrorStatus Gpio_setPinValue(GpioPinCfg_t  *Add_pu8CnfgStatus , u8 Copyu8PinValue)
{
	Gpio_tenuErrorStatus loc_enu_returnStatus = Gpio_enuOk;
	GPIOx_t *loc_ptr_GPIOx[6] = {GPIO_A,GPIO_B,GPIO_C,GPIO_D,GPIO_E,GPIO_H};
	u8 loc_u8_portNumber = Add_pu8CnfgStatus->gpio_port_x;
	u8 loc_u8_pinNumber  = Add_pu8CnfgStatus->gpio_pin_x;
	
	if ( loc_u8_portNumber > MAX_PORT_NUMBER)
	{
		loc_enu_returnStatus = Gpio_WrongPortNumError;
	}
	else if ( loc_u8_pinNumber > MAX_PIN_NUMBER)
	{
		loc_enu_returnStatus = Gpio_WrongPinNumError;
	}
	else
	{
		if (Copyu8PinValue == GPIO_ODR_HIGH)
		{
			SET_BIT(loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_ODR,loc_u8_pinNumber);
			BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_BSRR,loc_u8_pinNumber) = TRUE;
			
			SET_BIT(loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_AFRL,loc_u8_pinNumber);
		}
		else if (Copyu8PinValue == GPIO_ODR_LOW)
		{
			SET_BIT(loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_ODR,(loc_u8_pinNumber+16));
			CLR_BIT(loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_ODR,loc_u8_pinNumber);
			CLR_BIT(loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_AFRL,loc_u8_pinNumber);
			//BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_BSRR,loc_u8_pinNumber)    = FALSE;
			//BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_BSRR,loc_u8_pinNumber+16) = TRUE;
		}
		else
		{
			loc_enu_returnStatus = Gpio_WrongValueError;
		}
		
	}
	return loc_enu_returnStatus;
}
Gpio_tenuErrorStatus Gpio_setPinnValue(u8 Copyu8Port ,u8 Copyu8Pin ,u8 Copyu8Value)
{
	Gpio_tenuErrorStatus loc_enu_returnStatus = Gpio_enuOk;
	GPIOx_t *loc_ptr_GPIOx[6] = {GPIO_A,GPIO_B,GPIO_C,GPIO_D,GPIO_E,GPIO_H};
	if ( Copyu8Port > MAX_PORT_NUMBER)
	{
		loc_enu_returnStatus = Gpio_WrongPortNumError;
	}
	else if ( Copyu8Pin > MAX_PIN_NUMBER)
	{
		loc_enu_returnStatus = Gpio_WrongPinNumError;
	}
	else
	{
		if (Copyu8Value == GPIO_ODR_HIGH)
		{
			BIT_BAND(&loc_ptr_GPIOx[Copyu8Port]->GPIOx_BSRR,Copyu8Pin) = TRUE;
		}
		else if (Copyu8Value == GPIO_ODR_LOW)
		{
			BIT_BAND(&loc_ptr_GPIOx[Copyu8Port]->GPIOx_BSRR,Copyu8Pin+16) = TRUE;
			BIT_BAND(&loc_ptr_GPIOx[Copyu8Port]->GPIOx_BSRR,Copyu8Pin)    = FALSE;
		}
		else
		{
			loc_enu_returnStatus = Gpio_WrongValueError;
		}
		
	}
	return loc_enu_returnStatus;
}


Gpio_tenuErrorStatus Gpio_TGLPin(u8 Copyu8Port ,u8 Copyu8Pin)
{
	Gpio_tenuErrorStatus loc_enu_returnStatus = Gpio_enuOk;
	GPIOx_t *loc_ptr_GPIOx[6] = {GPIO_A,GPIO_B,GPIO_C,GPIO_D,GPIO_E,GPIO_H};
	if ( Copyu8Port > MAX_PORT_NUMBER)
	{
		loc_enu_returnStatus = Gpio_WrongPortNumError;
	}
	else if ( Copyu8Pin > MAX_PIN_NUMBER)
	{
		loc_enu_returnStatus = Gpio_WrongPinNumError;
	}
	else
	{
		TGL_BIT(loc_ptr_GPIOx[Copyu8Port]->GPIOx_ODR,Copyu8Pin);
		
	}
	return loc_enu_returnStatus;
}
Gpio_tenuErrorStatus Gpio_readPinValue(GpioPinCfg_t  *Add_CnfgStruct , pu32 Add_pu8PinValue)
{
	Gpio_tenuErrorStatus loc_enu_returnStatus = Gpio_enuOk;
	GPIOx_t *loc_ptr_GPIOx[6] = {GPIO_A,GPIO_B,GPIO_C,GPIO_D,GPIO_E,GPIO_H};
	u8 loc_u8_portNumber = Add_CnfgStruct->gpio_port_x;
	u8 loc_u8_pinNumber  = Add_CnfgStruct->gpio_pin_x;
	
	if ( loc_u8_portNumber > MAX_PORT_NUMBER)
	{
		loc_enu_returnStatus = Gpio_WrongPortNumError;
	}
	else if ( loc_u8_pinNumber > MAX_PIN_NUMBER)
	{
		loc_enu_returnStatus = Gpio_WrongPinNumError;
	}
	else if ( Add_pu8PinValue == PTR_NULL)
	{
		loc_enu_returnStatus = Gpio_WrongReadError;
	}
	else
	{
		*Add_pu8PinValue = BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_IDR,loc_u8_pinNumber);
	}
	return loc_enu_returnStatus;
}
Gpio_tenuErrorStatus Gpio_SetAlternateFunction(GpioPinCfg_t  *Add_CnfgStruct , u8 CopyAF)
{
	Gpio_tenuErrorStatus loc_enu_returnStatus = Gpio_enuOk;
	GPIOx_t *loc_ptr_GPIOx[6] = {GPIO_A,GPIO_B,GPIO_C,GPIO_D,GPIO_E,GPIO_H};
	u8 loc_u8_portNumber = Add_CnfgStruct->gpio_port_x;
	u8 loc_u8_pinNumber  = Add_CnfgStruct->gpio_pin_x;
	
	if ( loc_u8_portNumber > MAX_PORT_NUMBER)
	{
		loc_enu_returnStatus = Gpio_WrongPortNumError;
	}
	else if ( loc_u8_pinNumber > MAX_PIN_NUMBER)
	{
		loc_enu_returnStatus = Gpio_WrongPinNumError;
	}
	else
	{
		// make sure pin is AF 
		if ( (BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_MODER,loc_u8_pinNumber*2) == FALSE) && (BIT_BAND(&loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_MODER,loc_u8_pinNumber*2+1) == TRUE))
		{
			  if (loc_u8_pinNumber < 8)
				{
					loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_AFRL &= (~(0xF<<loc_u8_pinNumber*4));
					loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_AFRL |= (CopyAF<<loc_u8_pinNumber*4);
				}
				else if (loc_u8_pinNumber > 7)
				{
					loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_AFRH &= (~(0xF<< (loc_u8_pinNumber-8)*4));
					loc_ptr_GPIOx[loc_u8_portNumber]->GPIOx_AFRH |= (CopyAF<<(loc_u8_pinNumber-8)*4);
				}
				else
				{
					
				}
		}
		else
		{
			// pin is not AF
			loc_enu_returnStatus = Gpio_WrongAFError;
		}
	}
	return loc_enu_returnStatus;
}



void GPIO_voidInitCFG(void)
{
  // CFG PORTA
   PORTA_PIN0_CFG       
   PORTA_PIN1_CFG 
   PORTA_PIN2_CFG 
   PORTA_PIN3_CFG 
   PORTA_PIN4_CFG 
   PORTA_PIN5_CFG 
   PORTA_PIN6_CFG 
   PORTA_PIN7_CFG 
   PORTA_PIN8_CFG 
   PORTA_PIN9_CFG 
   PORTA_PIN10_CFG
   PORTA_PIN11_CFG
   PORTA_PIN12_CFG
   PORTA_PIN13_CFG
   PORTA_PIN14_CFG
   PORTA_PIN15_CFG   
	
	
	// CFG PORTB
   PORTB_PIN0_CFG       
   PORTB_PIN1_CFG 
   PORTB_PIN2_CFG 
   PORTB_PIN3_CFG 
   PORTB_PIN4_CFG 
   PORTB_PIN5_CFG 
   PORTB_PIN6_CFG 
   PORTB_PIN7_CFG 
   PORTB_PIN8_CFG 
   PORTB_PIN9_CFG 
   PORTB_PIN10_CFG
   PORTB_PIN11_CFG
   PORTB_PIN12_CFG
   PORTB_PIN13_CFG
   PORTB_PIN14_CFG
   PORTB_PIN15_CFG   
	 
	 // CFG PORTC
   PORTC_PIN0_CFG       
   PORTC_PIN1_CFG 
   PORTC_PIN2_CFG 
   PORTC_PIN3_CFG 
   PORTC_PIN4_CFG 
   PORTC_PIN5_CFG 
   PORTC_PIN6_CFG 
   PORTC_PIN7_CFG 
   PORTC_PIN8_CFG 
   PORTC_PIN9_CFG 
   PORTC_PIN10_CFG
   PORTC_PIN11_CFG
   PORTC_PIN12_CFG
   PORTC_PIN13_CFG
   PORTC_PIN14_CFG
   PORTC_PIN15_CFG   
	 
	 // CFG PORTD
   PORTD_PIN0_CFG       
   PORTD_PIN1_CFG 
   PORTD_PIN2_CFG 
   PORTD_PIN3_CFG 
   PORTD_PIN4_CFG 
   PORTD_PIN5_CFG 
   PORTD_PIN6_CFG 
   PORTD_PIN7_CFG 
   PORTD_PIN8_CFG 
   PORTD_PIN9_CFG 
   PORTD_PIN10_CFG
   PORTD_PIN11_CFG
   PORTD_PIN12_CFG
   PORTD_PIN13_CFG
   PORTD_PIN14_CFG
   PORTD_PIN15_CFG   
	 
	 
	 // CFG PORTE
   PORTE_PIN0_CFG       
   PORTE_PIN1_CFG 
   PORTE_PIN2_CFG 
   PORTE_PIN3_CFG 
   PORTE_PIN4_CFG 
   PORTE_PIN5_CFG 
   PORTE_PIN6_CFG 
   PORTE_PIN7_CFG 
   PORTE_PIN8_CFG 
   PORTE_PIN9_CFG 
   PORTE_PIN10_CFG
   PORTE_PIN11_CFG
   PORTE_PIN12_CFG
   PORTE_PIN13_CFG
   PORTE_PIN14_CFG
   PORTE_PIN15_CFG   
	 
	 
	 // CFG PORTH
   PORTH_PIN0_CFG       
   PORTH_PIN1_CFG 
   PORTH_PIN2_CFG 
   PORTH_PIN3_CFG 
   PORTH_PIN4_CFG 
   PORTH_PIN5_CFG 
   PORTH_PIN6_CFG 
   PORTH_PIN7_CFG 
   PORTH_PIN8_CFG 
   PORTH_PIN9_CFG 
   PORTH_PIN10_CFG
   PORTH_PIN11_CFG
   PORTH_PIN12_CFG
   PORTH_PIN13_CFG
   PORTH_PIN14_CFG
   PORTH_PIN15_CFG   
	
}