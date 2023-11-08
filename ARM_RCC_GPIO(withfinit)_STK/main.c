#include "STD_TYPES.h"
#include "BIT_UTILS.h"
#include "RCC.h"
#include "GPIO.h"
#include "SYSTICK.h"
int main()
{

	 Rcc_enuSelectSysCLk(RCC_CLK_HSI,RCC_CLK_HSI);

	 Rcc_enuEnablePeriphral(RCC_REGISTER_AHB1,AHB1_GPIOA_EN);
	Rcc_enuEnablePeriphral(RCC_REGISTER_AHB1,AHB1_GPIOB_EN);
	Rcc_enuEnablePeriphral(RCC_REGISTER_AHB1,AHB1_GPIOC_EN);
	Rcc_enuEnablePeriphral(RCC_REGISTER_AHB1,AHB1_GPIOD_EN);
	Rcc_enuEnablePeriphral(RCC_REGISTER_AHB1,AHB1_GPIOE_EN);
	Rcc_enuEnablePeriphral(RCC_REGISTER_AHB1,AHB1_GPIOH_EN);
	// Rcc_enuEnablePeriphral(RCC_REGISTER_AHB1,AHB1_GPIOB_EN);
	// Rcc_enuEnablePeriphral(RCC_REGISTER_AHB1,AHB1_GPIOC_EN);
	// Rcc_enuEnablePeriphral(RCC_REGISTER_AHB1,AHB1_GPIOD_EN);
	// Rcc_enuEnablePeriphral(RCC_REGISTER_AHB1,AHB1_GPIOA_EN);
	// Rcc_enuEnablePeriphral(RCC_REGISTER_AHB1,AHB1_GPIOE_EN);
	// Rcc_enuEnablePeriphral(RCC_REGISTER_AHB1,AHB1_GPIOH_EN);

	// Rcc_enuCfgBusPrescalers(RCC_APB2_NOTDIV);
	
	// GpioPinCfg_t PIN_Test_1={
    // GPIO_MODE_u64_INPUT,
    // GPIO_PUPD_u32_PULL_UP,
    // GPIO_SPEED_MEDIUM,
    // GPIO_PIN_00,
    // GPIO_PORT_A,
	// };
	// u8 value =0;
	//Gpio_init(&PIN_Test_1);
	//Gpio_setPinValue(&PIN_Test_1,GPIO_ODR_HIGH);
	//Gpio_readPinValue(&PIN_Test_1,&value);
	//Gpio_FInit();
	//Systick_Init(8000);
	while(1)
	{
	}
	return 0;
}
