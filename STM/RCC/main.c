
#include "Bit_utils.h"
#include "Std_types.h"
#include "RCC.h"
#include "GPIO.h"
/*
typedef struct{

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

#define PERIPHERAL_BITBAND(REGISTER,BIT)	(*((volatile u32*)(PERIPHERAL_ALIAS_BASE+(((((u32)&(REGISTER)))-PERIPHERALS_BASE)*(32))+(BIT*(4)))))

#define GPIO_C_BASEADDRESS        0x40020800
#define PERIPHERAL_ALIAS_BASE			(0x42000000UL)
#define PERIPHERALS_BASE          (0x40000000UL)
#define GPIO_C    								((GPIO_t*)(GPIO_C_BASEADDRESS))
#define GPIO_C_ODRC       (0x40020814)

int main(){
	while (1){
		
	PERIPHERAL_BITBAND(GPIO_C->GPIOx_MODER,13)=1;

	
	}
	return 1;
}
*/
int main() {

	
while (1){
	
	//  Rcc_enuSelectSysCLk(RCC_CLK_HSI,RCC_STATE_NOTPRESERVE);
	// Rcc_enuCnfgrPll(60 , 400 , RCC_PLLP_DIVBY_2 , RCC_PLLSRC_HSE , RCC_Q_DIVBY_2);

			GpioPinCfg_t test ={GPIO_MODE_u64_OUTPUT_PP,
		GPIO_PUPD_u32_PULL_UP,GPIO_SPEED_LOW,GPIO_PIN_13,GPIO_PORT_C,
	};
	
	Gpio_init(&test);
}
return 0;
}