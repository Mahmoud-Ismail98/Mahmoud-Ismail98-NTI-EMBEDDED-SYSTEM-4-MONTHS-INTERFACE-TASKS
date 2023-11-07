/*
 * rcc.h
 *
 *  Created on: Mar 9, 2022
 *      Author: MahmoudElImbabi
 */
#ifndef MCAL_RCC_RCC_H_
#define MCAL_RCC_RCC_H_
//////////////////////GUARD FILE///////////////////////////////////////////
/* ERROR STATUS ENUM */

#include <Services/Std_types.h>
#include "Services/Memory_Map.h"
#include <Services/Bit_utils.h>

typedef enum
{
	Rcc_enuOk,
	Rcc_enuTimeOutError,
	RCC_enuUnLogicActionError,
	RCC_enuNullPointerError,
	RCC_enuInvalid_M_Error,
	RCC_enuInvalid_N_Error,
	RCC_enuInvalid_P_Error,
	RCC_enuInvalid_ScrPll_Error,
	RCC_enuInvalid_Q_Error,
	RCC_enuPll_IS_On_Error,
	Rcc_enuWrongPeriphralBusError,
	Rcc_enuWrongBusPrescalerError

} Rcc_tenuErrorStatus;

/////////////////////////////////////////////////////////////////
/* SYSCLK OPTIONS AND INPUT PARAMETERS FOR Rcc_enuSelectSysCLk */

#define RCC_CLK_HSI 	0		//ALSO USED IN Rcc_enuCheckCLk
#define RCC_CLK_HSE 	1		//ALSO USED IN Rcc_enuCheckCLk
#define RCC_CLK_PLL 	2		//ALSO USED IN Rcc_enuCheckCLk

#define RCC_STATE_PRESERVE 		0
#define RCC_STATE_NOTPRESERVE 	1

/*CONTROL EACH CLK BY SELECTING THREE FROM THOSE INPUT PARAMETERS FOR Rcc_enuControlCLk*/
#define RCC_CNTROL_HSION 			1
#define RCC_CNTROL_HSIOFF			0
#define RCC_CNTROL_HSEON			1
#define RCC_CNTROL_HSEOFF			0
#define RCC_CNTROL_PLLMainON		1
#define RCC_CNTROL_PLLMainOFF		0
#define RCC_CNTROL_PLLI2SON			1
#define RCC_CNTROL_PLLI2SOFF		0
//////////////////_/////////////////////////////////////////////////////////////////////

//////VALUES OF THE CREATED VALUE FOR CHECKING READY OR NOT IN  Rcc_enuCheckCLk/////////
#define RCC_STATE_NOTREADY  	0
#define RCC_STATE_READY  		1

//////////////////////////////INPUTS FOR Rcc_enuCnfgrPll////////////////////////////////
/*PLLP INPUTS*/
#define RCC_PLLP_DIVBY_2        (0 << 16)
#define RCC_PLLP_DIVBY_4        (1 << 16)
#define RCC_PLLP_DIVBY_6        (2 << 16)
#define RCC_PLLP_DIVBY_8        (3 << 16)

/*SRCPLL INPUTS*/
#define RCC_PLLSRC_HSI			(0 << 22)
#define RCC_PLLSRC_HSE			(1 << 22)

/*PLLQ INPUTS*/
#define RCC_Q_DIVBY_2 			(2 << 24)
#define RCC_Q_DIVBY_3 			(3 << 24)
#define RCC_Q_DIVBY_4 			(4 << 24)
#define RCC_Q_DIVBY_5 			(5 << 24)
#define RCC_Q_DIVBY_6 			(6 << 24)
#define RCC_Q_DIVBY_7 			(7 << 24)
#define RCC_Q_DIVBY_8 			(8 << 24)
#define RCC_Q_DIVBY_9 			(9 << 24)
#define RCC_Q_DIVBY_10 			(10 << 24)
#define RCC_Q_DIVBY_11			(11 << 24)
#define RCC_Q_DIVBY_12			(12 << 24)
#define RCC_Q_DIVBY_13			(13 << 24)
#define RCC_Q_DIVBY_14			(14 << 24)
#define RCC_Q_DIVBY_15			(15 << 24)


//////////////////INPUTS FOR Rcc_enuEnablePeriphral FUNCTION/////////////////////////////////
/*Copy_u8PeriphralBus  OPTIONS*/
#define RCC_REGISTER_AHB1       (0)
#define RCC_REGISTER_AHB2       (1)
#define RCC_REGISTER_APB1       (2)
#define RCC_REGISTER_APB2       (3)

/*Copy_u8Periphral  OPTIONS*/
/*AHB1_Periphral_bitmask*/
#define AHB1_GPIOA_EN   (0)
#define AHB1_GPIOB_EN   (1)
#define AHB1_GPIOC_EN   (2)
#define AHB1_GPIOD_EN   (3)
#define AHB1_GPIOE_EN   (4)
#define AHB1_GPIOH_EN   (7)
#define AHB1_CRC_EN     (12)
#define AHB1_DMA1_EN    (21)
#define AHB1_DMA2_EN    (22)

/*AHB2_Periphral_bitmask*/
#define AHB2_OTGFS_EN   (7)

/*APB1_Periphral_bitmask*/
#define APB1_TIM2_EN    (0)
#define APB1_TIM3_EN    (1)
#define APB1_TIM4_EN    (2)
#define APB1_TIM5_EN    (3)
#define APB1_WWDG_EN    (11)
#define APB1_SPI2_EN    (14)
#define APB1_SPI3_EN    (15)
#define APB1_USART2_EN  (17)
#define APB1_I2C1_EN    (21)
#define APB1_I2C2_EN    (22)
#define APB1_I2C3_EN    (23)
#define APB1_PWR_EN     (28)

/*APB2_Periphral_bitmask*/
#define APB2_TIM1_EN    (0)
#define	APB2_USART1_EN  (4)
#define APB2_USART6_EN  (5)
#define APB2_ADC1_EN    (8)
#define	APB2_SDIO_EN    (11)
#define APB2_SPI1_EN    (12)
#define APB2_SPI4_EN    (13)
#define APB2_SYSCFG_EN  (14)
#define APB2_TIM9_EN    (16)
#define APB2_TIM10_EN   (17)
#define APB2_TIM11_EN   (18)

///////////////////////INPUTS FOR Rcc_enuCfgBusPrescalers///////////////////////////////////


/*PPRE2 OPTIONS*/
#define RCC_APB2_NOTDIV  (0 << 13)
#define RCC_APB2_DIV2    (4 << 13)
#define RCC_APB2_DIV4    (5 << 13)
#define RCC_APB2_DIV8    (6 << 13)
#define RCC_APB2_DIV16   (7 << 13)

/*PPRE1 OPTIONS*/
#define RCC_APB1_NOTDIV  (0 << 10)
#define RCC_APB1_DIV2    (4 << 10)
#define RCC_APB1_DIV4    (5 << 10)
#define RCC_APB1_DIV8    (6 << 10)
#define RCC_APB1_DIV16   (7 << 10)

/*HPRE OPTIONS*/
#define RCC_AHB_NOTDIV  (0 << 4)
#define RCC_AHB_DIV2    (8 << 4)
#define RCC_AHB_DIV4    (9 << 4)
#define RCC_AHB_DIV8    (10 << 4)
#define RCC_AHB_DIV16   (11 << 4)
#define RCC_AHB_DIV64   (12 << 4)
#define RCC_AHB_DIV128  (13 << 4)
#define RCC_AHB_DIV256  (14 << 4)
#define RCC_AHB_DIV512  (15 << 4)

///////////////////////////////////////*FUNCTIONS*///////////////////////////////////////////

Rcc_tenuErrorStatus Rcc_enuSelectSysCLk(uint32 Copy_u32SysClk , uint32 Copy_u32OldSysClk) ;

Rcc_tenuErrorStatus Rcc_enuControlCLk(uint32 Copy_u32ControlHSI  ,uint32 Copy_u32ControlHSE ,uint32 Copy_u32ControlPLL_Main, uint32 Copy_u32ControlPLL_I2S);

Rcc_tenuErrorStatus Rcc_enuCheckCLk(uint32 Copy_u32CLk, Puint8 Add_pu32RdyStatus) ;

Rcc_tenuErrorStatus Rcc_enuCnfgrPll(uint32 COPY_u32M , uint32 Copy_u16N , uint32 Copy_u32P , uint32 Copy_u32SrcPll , uint32 Copy_u32Q);

Rcc_tenuErrorStatus Rcc_enuEnablePeriphral(uint32 Copy_u32PeriphralBus , uint32 Copy_u32Periphral);

Rcc_tenuErrorStatus Rcc_enuDisablePeriphral(uint32 Copy_u32PeriphralBus , uint32 Copy_u32Periphral);

Rcc_tenuErrorStatus Rcc_enuCfgBusPrescalers(uint32 Copy_u32PeriphralBus, uint32 Copy_u32Prescaler);
////////////////////////////////////////////////////////////////////////////////////////////
#endif /* MCAL_RCC_RCC_H_ */

