
#include "Std_types.h"
#include "Bit_utils.h"
#include "rcc.h"
#include "GPIO.h"
#include "systic.h"

void ISR_SYSTICK(void);
static GpioPinCfg_t led_configuraion={GPIO_MODE_u64_OUTPUT_PP,GPIO_PUPD_u32_FLOATING,GPIO_SPEED_LOW,GPIO_PIN_01,GPIO_PORT_B};
int main(void)
{	

Rcc_enuSelectSysCLk(RCC_CLK_HSI,RCC_HSE_disable);
Rcc_enuEnablePeriphral(RCC_REGISTER_AHB1 , AHB1_GPIOB_EN);	
		
Systick_RegisterCbf(ISR_SYSTICK);	
Systick_Init(1000);
Systick_Start();
	
	return 0;
}	

void ISR_SYSTICK(void)
{	
	Gpio_setPinValue(&led_configuraion,GPIO_ODR_HIGH);
}	


