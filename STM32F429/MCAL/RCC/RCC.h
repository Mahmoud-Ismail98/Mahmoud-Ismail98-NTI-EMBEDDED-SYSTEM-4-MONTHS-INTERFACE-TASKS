/**************************************************************************/
/* Filename						: RCC.h                            */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 5, 2023  	           	 	      	 */
/* Version 	 					: V01                                     */
/* MicroController  			: STM32F429 								  	  */
/* Trainee At					: NTI (4 Months)						  */
/* Instructor					: Mahmoud Embabi						  */
/**************************************************************************/



#ifndef RCC_H_
#define RCC_H_



/********************************** Includes *********************************************/



/********************************** Macros Declarations *******************************/



/********************************** Macros Function Declarations *********************/


/********************************** Data Type Declarations ****************************/


typedef enum{
	RCC_STATUS_FAIL,
	RCC_STATUS_OK,
	RCC_STATUS_WRONG_INDEX,
	RCC_STATUS_NULL_POINTER_ADDRESS,
	RCC_STATUS_TIME_OUT_FLAG,
	RCC_STATUS_WRONG_CFG
}Rcc_StatusErrorType;


typedef enum{
	RCC_CLK_SOURCE_HSI_INDEX,
	RCC_CLK_SOURCE_HSE_INDEX,
	RCC_CLK_SOURCE_PLL_INDEX,
	RCC_CLK_SOURCE_PLLI2S_INDEX,
	RCC_CLK_SOURCE_PLLSAI_INDEX
}Rcc_ClkSoruceIndexType;


typedef enum{
	RCC_SYSTEM_CLK_HSI_INDEX,
	RCC_SYSTEM_CLK_HSE_INDEX,
	RCC_SYSTEM_CLK_PLL_INDEX
}Rcc_SystemClkSoruceIndexType;

typedef enum{
	RCC_BUS_INDEX_AHB1,
	RCC_BUS_INDEX_AHB2,
	RCC_BUS_INDEX_AHB3,
	RCC_BUS_INDEX_APB1,
	RCC_BUS_INDEX_APB2,
}Rcc_BusIndexType;

typedef enum{
	RCC_OFF,
	RCC_ON
}Rcc_OnOffType;

/************************************* MCOx Pins *****************************/
typedef enum{
	RCC_MCO2_PIN_SELECT_SYSTEM_CLK,
	RCC_MCO2_PIN_SELECT_PLLI2S_CLK,
	RCC_MCO2_PIN_SELECT_HSE_CLK,
	RCC_MCO2_PIN_SELECT_PLL_CLK

}Rcc_MCO2PinSelectClkSoruceType;

typedef enum{
	RCC_MCO2_PIN_SELECT_PRESCALER_NO_DIV = 0b000,
	RCC_MCO2_PIN_SELECT_PRESCALER_DIV_2 = 0b100,
	RCC_MCO2_PIN_SELECT_PRESCALER_DIV_3 = 0b101,
	RCC_MCO2_PIN_SELECT_PRESCALER_DIV_4 = 0b110,
	RCC_MCO2_PIN_SELECT_PRESCALER_DIV_5 = 0b111

}Rcc_MCO2PinSelectPrescalerType;

typedef enum{
	RCC_MCO1_PIN_SELECT_HSI_CLK,
	RCC_MCO1_PIN_SELECT_LSE_CLK,
	RCC_MCO1_PIN_SELECT_HSE_CLK,
	RCC_MCO1_PIN_SELECT_PLL_CLK

}Rcc_MCO1PinSelectClkSoruceType;

typedef enum{
	RCC_MCO1_PIN_SELECT_PRESCALER_NO_DIV = 0b000,
	RCC_MCO1_PIN_SELECT_PRESCALER_DIV_2 = 0b100,
	RCC_MCO1_PIN_SELECT_PRESCALER_DIV_3 = 0b101,
	RCC_MCO1_PIN_SELECT_PRESCALER_DIV_4 = 0b110,
	RCC_MCO1_PIN_SELECT_PRESCALER_DIV_5 = 0b111

}Rcc_MCO1PinSelectPrescalerType;


/****************************Busses **************************************************/

typedef enum{
	RCC_APB2_SELECT_PRESCALER_AHB_NO_DIV = 0b000,
	RCC_APB2_SELECT_PRESCALER_AHB_DIV_2 = 0b100,
	RCC_APB2_SELECT_PRESCALER_AHB_DIV_4 = 0b101,
	RCC_APB2_SELECT_PRESCALER_AHB_DIV_8 = 0b110,
	RCC_APB2_SELECT_PRESCALER_AHB_DIV_16 = 0b111

}Rcc_APB2SelectPrescalerType;

typedef enum{
	RCC_APB1_SELECT_PRESCALER_AHB_NO_DIV = 0b000,
	RCC_APB1_SELECT_PRESCALER_AHB_DIV_2 = 0b100,
	RCC_APB1_SELECT_PRESCALER_AHB_DIV_4 = 0b101,
	RCC_APB1_SELECT_PRESCALER_AHB_DIV_8 = 0b110,
	RCC_APB1_SELECT_PRESCALER_AHB_DIV_16 = 0b111

}Rcc_APB1SelectPrescalerType;


typedef enum{
	RCC_AHB_SELECT_PRESCALER_SYSTEM_CLK_NO_DIV = 0b0000,
	RCC_AHB_SELECT_PRESCALER_SYSTEM_CLK_DIV_2 = 0b1000,
	RCC_AHB_SELECT_PRESCALER_SYSTEM_CLK_DIV_4 = 0b1000,
	RCC_AHB_SELECT_PRESCALER_SYSTEM_CLK_DIV_8 = 0b1000,
	RCC_AHB_SELECT_PRESCALER_SYSTEM_CLK_DIV_16 = 0b1000,
	RCC_AHB_SELECT_PRESCALER_SYSTEM_CLK_DIV_64 = 0b1000,
	RCC_AHB_SELECT_PRESCALER_SYSTEM_CLK_DIV_128 = 0b1000,
	RCC_AHB_SELECT_PRESCALER_SYSTEM_CLK_DIV_256 = 0b1000,
	RCC_AHB_SELECT_PRESCALER_SYSTEM_CLK_DIV_512 = 0b1000

}Rcc_AHBSelectPrescalerType;

/************************ PLL ******************************/
typedef enum{
	RCC_PLLP_2 = 0,
	RCC_PLLP_4,
	RCC_PLLP_6,
	RCC_PLLP_8
}Rcc_SelectPllPType;


typedef enum{
	RCC_PLL_Q_2 = 2,
	RCC_PLL_Q_3 = 3,
	RCC_PLL_Q_4 = 4,
	RCC_PLL_Q_5 = 5,
	RCC_PLL_Q_6 = 6,
	RCC_PLL_Q_7 = 7,
	RCC_PLL_Q_8 = 8,
	RCC_PLL_Q_9 = 9,
	RCC_PLL_Q_10 = 10,
	RCC_PLL_Q_11 = 11,
	RCC_PLL_Q_12 = 12,
	RCC_PLL_Q_13 = 13,
	RCC_PLL_Q_14 = 14,
	RCC_PLL_Q_15 = 15

}Rcc_SelectPLLQType;



typedef enum{
	RCC_SELECT_PLL_SOURCE_HSI,
	RCC_SELECT_PLL_SOURCE_HSE
}Rcc_SelectPllSourceType;

typedef struct{

	Rcc_SelectPllSourceType rcc_select_pll_source;
	Rcc_SelectPllPType rcc_select_pllp ;
	Rcc_SelectPLLQType rcc_select_pllq;
	u16 rcc_PLL_N_From50To432;
	u8 rcc_PLL_M_From2To63;

}Rcc_PllConfigType;

/************************ PLLI2S ******************************/
/*
 * R (2-->7 )
 * Q (2-->15)
 * N (50 --> 432 )
 */
typedef enum{
	RCC_PLL_I2S_R_2 = 2,
	RCC_PLL_I2S_R_3 = 3,
	RCC_PLL_I2S_R_4 = 4,
	RCC_PLL_I2S_R_5 = 5,
	RCC_PLL_I2S_R_6 = 6,
	RCC_PLL_I2S_R_7 = 7
}Rcc_SelectPll_I2S_R_Type;


typedef enum{
	RCC_PLL_I2S_Q_2 = 2,
	RCC_PLL_I2S_Q_3 = 3,
	RCC_PLL_I2S_Q_4 = 4,
	RCC_PLL_I2S_Q_5 = 5,
	RCC_PLL_I2S_Q_6 = 6,
	RCC_PLL_I2S_Q_7 = 7,
	RCC_PLL_I2S_Q_8 = 8,
	RCC_PLL_I2S_Q_9 = 9,
	RCC_PLL_I2S_Q_10 = 10,
	RCC_PLL_I2S_Q_11 = 11,
	RCC_PLL_I2S_Q_12 = 12,
	RCC_PLL_I2S_Q_13 = 13,
	RCC_PLL_I2S_Q_14 = 14,
	RCC_PLL_I2S_Q_15 = 15

}Rcc_SelectPLL_I2S_Q_Type;



typedef enum{
	RCC_SELECT_PLL_I2S_SOURCE,
	RCC_SELECT_PLL_I2S_SOURCE_EXTERNAL_PIN_CKIN
}Rcc_SelectPll_I2S_SourceType;

typedef struct{

	Rcc_SelectPll_I2S_R_Type rcc_select_pll_I2S_R ;
	Rcc_SelectPLL_I2S_Q_Type rcc_select_pll_I2S_Q;
	u16 rcc_PLLI2S_N_From50To432;
	Rcc_SelectPll_I2S_SourceType rcc_select_pll_i2s_source_clk;

}Rcc_PllI2SConfigType;

/************************ PLL_SAI ******************************/
/*
 * R (2-->7 )
 * Q (2-->15)
 * N (50 --> 432 )
 * Qx_Last =  PLLI2SDIVQ
 * Qy_last =  PLLSAIDIVQ
 * Rlcd_last = PLLSAIDIVR
 */

typedef enum{
	RCC_PLL_SAI_R_2 = 2,
	RCC_PLL_SAI_R_3 = 3,
	RCC_PLL_SAI_R_4 = 4,
	RCC_PLL_SAI_R_5 = 5,
	RCC_PLL_SAI_R_6 = 6,
	RCC_PLL_SAI_R_7 = 7
}Rcc_SelectPll_SAI_R_Type;


typedef enum{
	RCC_PLL_SAI_Q_2 = 2,
	RCC_PLL_SAI_Q_3 = 3,
	RCC_PLL_SAI_Q_4 = 4,
	RCC_PLL_SAI_Q_5 = 5,
	RCC_PLL_SAI_Q_6 = 6,
	RCC_PLL_SAI_Q_7 = 7,
	RCC_PLL_SAI_Q_8 = 8,
	RCC_PLL_SAI_Q_9 = 9,
	RCC_PLL_SAI_Q_10 = 10,
	RCC_PLL_SAI_Q_11 = 11,
	RCC_PLL_SAI_Q_12 = 12,
	RCC_PLL_SAI_Q_13 = 13,
	RCC_PLL_SAI_Q_14 = 14,
	RCC_PLL_SAI_Q_15 = 15

}Rcc_SelectPLL_SAI_Q_Type;

//----

typedef enum{
	RCC_SELECT_PLL_SAI_PLLSAIDIVR_LCD_RLast_IS_2,
	RCC_SELECT_PLL_SAI_PLLSAIDIVR_LCD_RLast_IS_4,
	RCC_SELECT_PLL_SAI_PLLSAIDIVR_LCD_RLast_IS_8,
	RCC_SELECT_PLL_SAI_PLLSAIDIVR_LCD_RLast_IS_16

}Rcc_SelectPll_SAI_PLLSAIDIVR_LCD_RLast_Type;




typedef enum{
	RCC_SELECT_PLL_SAI1A_SOURCE_IS_SA11_Y,
	RCC_SELECT_PLL_SAI1A_SOURCE_IS_SA11_X,
	RCC_SELECT_PLL_SAI1A_SOURCE_IS_EXTERNAL_PIN_I2S_CKIN
}Rcc_Select_SAI1A_SourceType;

typedef enum{
	RCC_SELECT_PLL_SAI1B_SOURCE_IS_SA11_Y,
	RCC_SELECT_PLL_SAI1B_SOURCE_IS_SA11_X,
	RCC_SELECT_PLL_SAI1B_SOURCE_IS_EXTERNAL_PIN_I2S_CKIN
}Rcc_Select_SAI1B_SourceType;


typedef struct{

	Rcc_SelectPll_SAI_R_Type rcc_select_pll_SAI_R ;
	Rcc_SelectPLL_SAI_Q_Type rcc_select_pll_SAI_Q;
	u16 rcc_PLLSAI_N_From50To432;

	u16 rcc_PLLSAI_PLLSAIDIVQ_Qy_Last_FROM1to50;
	u16 rcc_PLLSAI_PLLI2SDIVQ_Qx_Last_FROM1to50;
	Rcc_SelectPll_SAI_PLLSAIDIVR_LCD_RLast_Type rcc_select_pll_sai_pllsaidivr_lcd_rlast;
	Rcc_Select_SAI1A_SourceType rcc_select_SAI1A_source;
	Rcc_Select_SAI1B_SourceType rcc_select_SAI1B_source;

}Rcc_PllSAIConfigType;



/*************** struct for rcc init *************************************/
typedef struct{

	Rcc_OnOffType rcc_hse_on_or_off;
	Rcc_OnOffType rcc_hsi_on_or_off;
	Rcc_OnOffType rcc_pll_on_or_off;
	Rcc_OnOffType rcc_pllI2S_on_or_off;
	Rcc_OnOffType rcc_pllSAI_on_or_off;

	Rcc_PllConfigType* address_pll_cfg;
	Rcc_PllI2SConfigType* adress_pll_i2s_cfg;
	Rcc_PllSAIConfigType* address_pll_sai_cfg;

	Rcc_APB2SelectPrescalerType rcc_apb2_select_prescaler;
	Rcc_APB1SelectPrescalerType rcc_apb1_select_prescaler;
	Rcc_AHBSelectPrescalerType rcc_ahb_select_prescaler;

	Rcc_SystemClkSoruceIndexType rcc_sysmte_clk_soruce;

}Rcc_ConfigType;
/*************************************************************************************/




/********************************** Software Interfaces Declarations *******************/

/* Register RCC_CR*/

Rcc_StatusErrorType Rcc_enuSetHsiTrimValue(u8 Copy_u8Value);
Rcc_StatusErrorType Rcc_enuEnableClockSecutiy(void);
Rcc_StatusErrorType Rcc_enuDisableClockSecutiy(void);


Rcc_StatusErrorType Rcc_enuEnableClock(Rcc_ClkSoruceIndexType Copy_enuClockSourceIndex); //1-
Rcc_StatusErrorType Rcc_enuDisableClock(Rcc_ClkSoruceIndexType Copy_enuClockSourceIndex);

Rcc_StatusErrorType Rcc_enuConfigPLL(const Rcc_PllConfigType* Address_Pll);
Rcc_StatusErrorType Rcc_enuInitMCO2(Rcc_MCO2PinSelectClkSoruceType Copy_enuMCO2ClkSource,Rcc_MCO2PinSelectPrescalerType Copy_enuMCO2Prescaler);
Rcc_StatusErrorType Rcc_enuInitMCO1(Rcc_MCO1PinSelectClkSoruceType Copy_enuMCO1ClkSource,Rcc_MCO1PinSelectPrescalerType Copy_enuMCO1Prescaler);

Rcc_StatusErrorType Rcc_enuSelectAPB2Prescaler(Rcc_APB2SelectPrescalerType Copy_enuAPB2Prescaler);
Rcc_StatusErrorType Rcc_enuSelectAPB1Prescaler(Rcc_APB1SelectPrescalerType Copy_enuAPB1Prescaler);
Rcc_StatusErrorType Rcc_enuSelectAHBPrescaler(Rcc_AHBSelectPrescalerType Copy_enuAHBPrescaler);

Rcc_StatusErrorType Rcc_enuSelectSystemClkSource(Rcc_SystemClkSoruceIndexType Copy_enuSystemClkSource);
Rcc_StatusErrorType Rcc_enuGetSystemClkSource(Rcc_SystemClkSoruceIndexType* Address_ClkSource);

Rcc_StatusErrorType Rcc_enuEnablePeripheralClk(Rcc_BusIndexType Copy_enuBusIndex, u8 Copy_u8PeripheralIndex);
Rcc_StatusErrorType Rcc_enuDisablePeripheralClk(Rcc_BusIndexType Copy_enuBusIndex, u8 Copy_u8PeripheralIndex);

Rcc_StatusErrorType Rcc_enuResetPeripheral(Rcc_BusIndexType Copy_enuBusIndex, u8 Copy_u8PeripheralIndex);

Rcc_StatusErrorType Rcc_enuEnablePeripheralClkInLowPowerMode(Rcc_BusIndexType Copy_enuBusIndex, u8 Copy_u8PeripheralIndex);
Rcc_StatusErrorType Rcc_enuDisablePeripheralClkInLowPowerMode(Rcc_BusIndexType Copy_enuBusIndex, u8 Copy_u8PeripheralIndex);


Rcc_StatusErrorType Rcc_enuConfigPLLI2S(const Rcc_PllI2SConfigType* Address_PllI2S);
Rcc_StatusErrorType Rcc_enuConfigPLLSAI(const Rcc_PllSAIConfigType* Address_PllSAI);

Rcc_StatusErrorType Rcc_enuInit(const Rcc_ConfigType* Address_Rcc);

/* interrupt */


#endif /* RCC_H_ */
