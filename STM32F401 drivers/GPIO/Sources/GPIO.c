#include "Std_types.h"
#include "Bit_utils.h"
#include "GPIO.h"


Gpio_tenuErrorStatus Gpio_init(GpioPinCfg_t  *Add_CnfgStruct){

	Gpio_tenuErrorStatus ERROR_STATE= Gpio_enuOk;
	
	u64 Loc_pin =	Add_CnfgStruct->gpio_pin_x;
	u64 Loc_port= Add_CnfgStruct->gpio_port_x;
	
	if (Loc_pin > 15){
		
			  ERROR_STATE = Gpio_WrongPinNumError;}
	
	else if (Loc_port > 5) {
		
				ERROR_STATE = Gpio_WrongPortNumError;}

	GPIO_t* ARR_GPIO[6]= {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};
	
	switch(Add_CnfgStruct->gpio_mode_x){
		
			case GPIO_MODE_u64_OUTPUT_PP:
			
					ARR_GPIO[Loc_port]->GPIOx_MODER |= (GPIO_MODE_u64_OUTPUT_PP << Loc_pin*2);
					CLR_BIT( ARR_GPIO[Loc_port]->GPIOx_OTYPER , Loc_pin);
					break;
		
			case GPIO_MODE_u64_OUTPUT_OD :
			
					ARR_GPIO[Loc_port]->GPIOx_MODER |= (GPIO_MODE_u64_OUTPUT_PP <<  Loc_pin*2);
					SET_BIT( ARR_GPIO[Loc_port]->GPIOx_OTYPER , Loc_pin);
					break;
		
			case GPIO_MODE_u64_INPUT:
				
					ARR_GPIO[Loc_port]->GPIOx_MODER |= (GPIO_MODE_u64_INPUT <<  Loc_pin*2);
					break;
	 	
	  	case GPIO_MODE_u64_AF_PP:
			
					ARR_GPIO[Loc_port]->GPIOx_MODER |= (GPIO_MODE_u64_AF_PP <<  Loc_pin*2);
					CLR_BIT( ARR_GPIO[Loc_port]->GPIOx_OTYPER , Loc_pin);
					break;
		
	  	case GPIO_MODE_u64_AF_OD :
			
				ARR_GPIO[Loc_port]->GPIOx_MODER |= (GPIO_MODE_u64_AF_OD <<  Loc_pin*2);
				SET_BIT( ARR_GPIO[Loc_port]->GPIOx_OTYPER , Loc_pin);
				break;
	}


	
	switch (Add_CnfgStruct->gpio_Pull_x){
		
		case GPIO_PUPD_u32_FLOATING :
			ARR_GPIO[Loc_port]->GPIOx_MODER |= (GPIO_MODE_u64_INPUT << Loc_pin*2);
			ARR_GPIO[Loc_port]->GPIOx_PUPDR |= (GPIO_PUPD_u32_FLOATING <<  Loc_pin*2);
		  break;
		
		case GPIO_PUPD_u32_PULL_UP :
			ARR_GPIO[Loc_port]->GPIOx_MODER |= (GPIO_MODE_u64_INPUT <<  Loc_pin*2);
			ARR_GPIO[Loc_port]->GPIOx_PUPDR |= (GPIO_PUPD_u32_PULL_UP <<  Loc_pin*2);
		  break;
		
			case GPIO_PUPD_u32_PULL_DOWN :
			ARR_GPIO[Loc_port]->GPIOx_MODER |= (GPIO_MODE_u64_INPUT <<  Loc_pin*2);
			ARR_GPIO[Loc_port]->GPIOx_PUPDR |= (GPIO_PUPD_u32_PULL_DOWN <<  Loc_pin*2);
		  break;
		
		}
	
		switch (Add_CnfgStruct->gpio_speed_x)
		{ 
			case GPIO_SPEED_LOW :
				ARR_GPIO[Loc_port]->GPIOx_OSPEEDER |= (GPIO_SPEED_LOW << Loc_pin*2);
			  break;
			
			case GPIO_SPEED_MEDIUM :
				ARR_GPIO[Loc_port]->GPIOx_OSPEEDER |= (0x01<< Loc_pin*2);
			  break;
			
			case GPIO_SPEED_HIGH :
				ARR_GPIO[Loc_port]->GPIOx_OSPEEDER |= (GPIO_SPEED_HIGH<<  Loc_pin*2);
			  break;
			
			case GPIO_SPEED_VHIGH :
				ARR_GPIO[Loc_port]->GPIOx_OSPEEDER |= (GPIO_SPEED_VHIGH<<  Loc_pin*2);
			  break;
		}
	
			return  ERROR_STATE;
	}
	
		Gpio_tenuErrorStatus Gpio_setPinValue(GpioPinCfg_t *Add_pu8CnfgStatus , u8 Copyu8PinValue){
		
		Gpio_tenuErrorStatus ERROR_STATE = Gpio_WrongValueError;
		u64 Loc_pin = Add_pu8CnfgStatus->gpio_pin_x ;
		u64 Loc_port = Add_pu8CnfgStatus->gpio_port_x ;
		GPIO_t* ARR_GPIO[6]= {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};
		
		if (Loc_pin > 15){
		
			 ERROR_STATE = Gpio_WrongPinNumError;}
	
	  else if (Loc_port > 5) {
		
		   ERROR_STATE = Gpio_WrongPortNumError;}
		
		
			switch ( Copyu8PinValue ){
					
				case GPIO_ODR_HIGH :
					
					ERROR_STATE = Gpio_enuOk;
					ARR_GPIO[Loc_port]->GPIOx_MODER |= (GPIO_MODE_u64_OUTPUT_PP << Loc_pin*2);
					SET_BIT(ARR_GPIO[Loc_port]->GPIOx_ODR , Loc_pin);
					break;
				
				case GPIO_ODR_LOW :
					
				  ERROR_STATE = Gpio_enuOk;
					ARR_GPIO[Loc_port]->GPIOx_MODER |= (GPIO_MODE_u64_OUTPUT_PP << Loc_pin*2);
					CLR_BIT(ARR_GPIO[Loc_port]->GPIOx_ODR , Loc_pin);
				  break;
				
				default : break;
			}
			return ERROR_STATE;
		}
					
		
		Gpio_tenuErrorStatus Gpio_readPinValue(GpioPinCfg_t  *Add_CnfgStruct , pu32 Add_pu8PinValue){
		
			Gpio_tenuErrorStatus ERROR_STATE = Gpio_enuOk;
			u64 Loc_pin  = Add_CnfgStruct->gpio_pin_x ;
			u64 Loc_port = Add_CnfgStruct->gpio_port_x ;
			GPIO_t* ARR_GPIO[6]= {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};
		
		if (Loc_pin > 15){
		
			 ERROR_STATE = Gpio_WrongPinNumError;
		}
	
	  else if (Loc_port > 5) {
		
		   ERROR_STATE = Gpio_WrongPortNumError;
		}
		
		  *Add_pu8PinValue = 	GET_BIT(ARR_GPIO[Loc_port]->GPIOx_IDR , Loc_pin);
			
			return ERROR_STATE;
	}
		
	
	void Gpio_SetAlternateFunction(GpioPinCfg_t  *Add_CnfgStruct , u8 CopyAF){
		
			u64 Loc_pin  = Add_CnfgStruct->gpio_pin_x ;
			u64 Loc_port = Add_CnfgStruct->gpio_port_x ;
			GPIO_t* ARR_GPIO[6]= {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};
		
		if ( Loc_pin > 7)
				
				ARR_GPIO[Loc_port]->GPIOx_AFRH |= ( CopyAF << Loc_pin*4);
			
			else
				ARR_GPIO[Loc_port]->GPIOx_AFRL |= ( CopyAF << Loc_pin*4);
			
		}
	
	void GPIO_INIT (GpioPinCfg_t  *Add_CnfgStruct){
		
		u64 Loc_port = Add_CnfgStruct->gpio_port_x ;
		GPIO_t* ARR_GPIO[6]= {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};
		
			ARR_GPIO[Loc_port]->GPIOx_MODER = CONCA(pin15,pin14,pin13,pin12,pin11,pin10,pin9,pin8,pin7,pin6,pin5,pin4,pin3,pin2,pin1,pin0);
		
		#undef OUTPUT
		#undef INPUT
		#undef AF
		#undef ANALOG
		
		#define OUTPUT    OUTPUT_MODE   
		#define INPUT     OUTPUT_MODE   
		#define AF        OUTPUT_MODE
		#define ANALOG    OUTPUT_MODE
		
		ARR_GPIO[Loc_port]->GPIOx_OTYPER = CONCA(pin15,pin14,pin13,pin12,pin11,pin10,pin9,pin8,pin7,pin6,pin5,pin4,pin3,pin2,pin1,pin0);
		
		#undef OUTPUT
		#undef INPUT
		#undef AF
		#undef ANALOG
		
		#define OUTPUT    INPUT_MODE   
		#define INPUT     INPUT_MODE  
		#define AF        INPUT_MODE
		#define ANALOG    INPUT_MODE
		
		ARR_GPIO[Loc_port]->GPIOx_PUPDR  = CONCA(pin15,pin14,pin13,pin12,pin11,pin10,pin9,pin8,pin7,pin6,pin5,pin4,pin3,pin2,pin1,pin0);
		
		#undef  OUTPUT
		#define OUTPUT    SPEED_LEVEL  /* HIGH_SPEED - LOW_SPEED - MEDIUM_SPEED - VH_SPEED */ 

		
		ARR_GPIO[Loc_port]->GPIOx_OSPEEDER = CONCA(pin15,pin14,pin13,pin12,pin11,pin10,pin9,pin8,pin7,pin6,pin5,pin4,pin3,pin2,pin1,pin0);
		
	}
		