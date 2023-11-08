#include "Std_types.h"
#include "Bit_utils.h"

#include "RCC.h"
#include "GPIO.h"

#include "SYSTIC.h"

//#include "RCC_prv.h"

//	#define RCC_AHB1ENR *((volatile unsigned long int *)0x40023800+0x30)

int main (void)
{
	//unsigned long int *ptr = 0x40023800+0x30;
//	RCC_t * RCCC = 0x40023800;
//	Rcc_enuControlCLk(RCC_CNTROL_HSION  ,RCC_CNTROL_HSEON ,RCC_CNTROL_PLLON);
	//RCC_enumSetSystemBus(RCC_CLK_HSE);
//	*ptr = 1;
	//RCC_AHB1ENR =0x01 ;
	//RCCC->AHB1ENR = 1;
	Rcc_enuEnablePeriphral(RCC_REGISTER_AHB1 , 0);
	PORT_voidInit();
	STK_voidInit();
	SET_DELAY(100);
	while(1)
	{
			//RCC_AHB1ENR = 1;
			Write_GPIOPIN(2,13 ,1);
			SET_DELAY(1000000);
			Write_GPIOPIN(2,13 ,0);
			SET_DELAY(1000000);
	}
	return 0;
}
