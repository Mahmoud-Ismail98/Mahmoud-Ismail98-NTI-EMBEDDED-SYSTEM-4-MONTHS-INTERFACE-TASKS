#ifndef RCC_H_
#define RCC_H_
#include "Std_types.h"

typedef enum
{
	Rcc_enumOk,
	Rcc_enumTimeOutError,
	RCC_enumUnLogicActionError,
	RCC_enumNullPointerError,
	RCC_enumInvalid_M_Error,
	RCC_enumInvalid_N_Error,
	RCC_enumInvalid_P_Error,
	RCC_enumInvalid_ScrPll_Error,
	RCC_enumInvalid_Q_Error,
	RCC_enumPll_IS_On_Error,
	Rcc_enumWrongPeriphralBusError,
	Rcc_enumWrongBusPrescalerError	
}RCC_enumErrStatus_t;

/* SYSCLK OPTIONS AND INPUT PARAMETERS FOR Rcc_enuSelectSysCLk */

#define RCC_CLK_HSI 		0x00000000		//ALSO USED IN Rcc_enuCheckCLk
#define RCC_CLK_HSE 		0x00000001		//ALSO USED IN Rcc_enuCheckCLk
#define RCC_CLK_HSI_PLL 	0x00000002		//ALSO USED IN Rcc_enuCheckCLk
#define RCC_CLK_HSE_PLL 	0x00000003		//ALSO USED IN Rcc_enuCheckCLk
#define RCC_CLK_PLL 	0x00000002		//ALSO USED IN Rcc_enuCheckCLk

/*CONTROL EACH CLK BY SELECTING THREE FROM THOSE INPUT PARAMETERS FOR Rcc_enuControlCLk*/
#define RCC_CNTROL_HSION 	1
#define RCC_CNTROL_HSIOFF	0
#define RCC_CNTROL_HSEON	1
#define RCC_CNTROL_HSEOFF	0
#define RCC_CNTROL_PLLON	1
#define RCC_CNTROL_PLLOFF	0
//////////////////_/////////////////////////////////////////////////////////////////////


//////VALUES OF THE CREATED VALUE FOR CHECKING READY OR NOT IN  Rcc_enuCheckCLk/////////
#define RCC_STATE_NOTREADY  	0
#define RCC_STATE_READY  		1
//////////////////////////////INPUTS FOR Rcc_enuCnfgrPll////////////////////////////////
/*PLLP INPUTS*/
#define RCC_PLLP_DIVBY_2        0
#define RCC_PLLP_DIVBY_4        1
#define RCC_PLLP_DIVBY_6        2
#define RCC_PLLP_DIVBY_8        3

/*SRCPLL INPUTS*/
#define RCC_PLLSRC_HSI			0
#define RCC_PLLSRC_HSE			1

/*PLLQ INPUTS*/
#define RCC_Q_DIVBY_2 			2
#define RCC_Q_DIVBY_3 			3
#define RCC_Q_DIVBY_4 			4
#define RCC_Q_DIVBY_5 			5
#define RCC_Q_DIVBY_6 			6
#define RCC_Q_DIVBY_7 			7
#define RCC_Q_DIVBY_8 			8
#define RCC_Q_DIVBY_9 			9
#define RCC_Q_DIVBY_10 			10
#define RCC_Q_DIVBY_11			11
#define RCC_Q_DIVBY_12			12
#define RCC_Q_DIVBY_13			13
#define RCC_Q_DIVBY_14			14
#define RCC_Q_DIVBY_15			15

//////////////////INPUTS FOR Rcc_enuEnablePeriphral FUNCTION/////////////////////////////////
/*Copy_u8PeriphralBus  OPTIONS*/
#define RCC_REGISTER_AHB1       6
#define RCC_REGISTER_AHB2       7
#define RCC_REGISTER_APB1       8
#define RCC_REGISTER_APB2       9


/*Copy_u8Periphral  OPTIONS*/
/*AHB1_Periphral_bitmask*/
#define AHB1_GPIOA_EN   0
#define AHB1_GPIOB_EN   1
#define AHB1_GPIOC_EN   2
#define AHB1_GPIOD_EN   3
#define AHB1_GPIOE_EN   4
#define AHB1_GPIOH_EN   7
#define AHB1_CRC_EN     12
#define AHB1_DMA1_EN    21
#define AHB1_DMA2_EN    22
/*AHB2_Periphral_bitmask*/
#define AHB2_OTGFS_EN   7
/*APB1_Periphral_bitmask*/
#define APB1_TIM2_EN    0
#define APB1_TIM3_EN    1
#define APB1_TIM4_EN    2
#define APB1_TIM5_EN    3
#define APB1_WWDG_EN    11
#define APB1_SPI2_EN    14
#define APB1_SPI3_EN    15
#define APB1_USART2_EN  17
#define APB1_I2C1_EN    21
#define APB1_I2C2_EN    22
#define APB1_I2C3_EN    23
#define APB1_PWR_EN     28
/*APB2_Periphral_bitmask*/
#define APB2_TIM1_EN    0
#define	APB2_USART1_EN  4
#define APB2_USART6_EN  5
#define APB2_ADC1_EN    8
#define	APB2_SDIO_EN    11
#define APB2_SPI1_EN    12
#define APB2_SPI4_EN    13
#define APB2_SYSCFG_EN  14
#define APB2_TIM9_EN    16
#define APB2_TIM10_EN   17
#define APB2_TIM11_EN   18


/*AHB Prescalled from SysClock used in prototype Rcc_enuCfgBusPrescalers*/
#define AHB_0		0
#define AHB_2		8
#define AHB_4		9
#define AHB_8		10
#define AHB_16		11
#define AHB_64		12
#define AHB_128		13
#define AHB_256		14
#define AHB_512		15

/*APB1 and APB2 Prescalled from AHB used in prototype Rcc_enuCfgBusPrescalers*/
#define AHB_0		0
#define AHB_2		4
#define AHB_4		5
#define AHB_8		6
#define AHB_16		7


RCC_enumErrStatus_t RCC_enumSetSystemBus(u8 Copy_u8RCCSource);

RCC_enumErrStatus_t Rcc_enuControlCLk(u8 Copy_u8ControlHSI  ,u8 Copy_u8ControlHSE ,u8 Copy_u8ControlPLL);

RCC_enumErrStatus_t Rcc_enuCheckCLk(u8 Copy_u8CLk, pu8 Add_pu8RdyStatus);

RCC_enumErrStatus_t Rcc_enuCnfgrPll(u8 COPY_u8M , u16 Copy_u16N , u8 Copy_u8P , u8 Copy_u8SrcPll , u8 Copy_u8Q);

RCC_enumErrStatus_t Rcc_enuEnablePeriphral(u8 Copy_u8PeriphralBus , u32 Copy_u32Periphral);

RCC_enumErrStatus_t Rcc_enuDisablePeriphral(u8 Copy_u8PeriphralBus , u32 Copy_u32Periphral);

RCC_enumErrStatus_t Rcc_enuCfgBusPrescalers(u8 Copy_u8PeriphralBus, u32 Copy_u32Prescaler);

#endif
