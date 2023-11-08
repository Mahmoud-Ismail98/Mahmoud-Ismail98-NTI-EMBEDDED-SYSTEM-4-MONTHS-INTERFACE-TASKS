
#include "std_types.h"
#include "rcc.h"
#include "GPIO.h"
#include "SysTick.h"


void cb_sys(void);
//GpioPinCfg_t pinC13 =
//{
//	GPIO_MODE_u64_OUTPUT_PP,GPIO_PUPD_u32_PULL_UP,GPIO_SPEED_MEDIUM,GPIO_PIN_13,GPIO_PORT_C
//};
int main()
{
	u32 loc_delay = FALSE;
	u8  val       = TRUE;
  Rcc_enuControlCLk(RCC_CNTROL_HSION,RCC_CNTROL_HSEOFF,RCC_CNTROL_PLLOFF);
  Rcc_enuEnablePeriphral(RCC_REGISTER_AHB1,AHB1_GPIOC_EN);
  GPIO_voidInitCFG();
	Systick_Init(1000);
	Systick_RegisterCbf(cb_sys);
  Systick_Start();
	while(1)
	{
		
	}
}


void cb_sys(void)
{
		Gpio_TGLPin(GPIO_PORT_C,GPIO_PIN_13);
}