/**************************************************************************/
/* Filename						: RCC.c                            */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 5, 2023  	           	 	      	 */
/* Version 	 					: V01                                     */
/* MicroController  			: STM32F429 								  	  */
/* Trainee At					: NTI (4 Months)						  */
/* Instructor					: Mahmoud Embabi						  */
/**************************************************************************/



/********************************** Includes *********************************************/

#include "../../SERVICES/BIT_UTILS.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/MAGIC_NUMBERS.h"
#include "../../SERVICES/HELPERS.h"

#include "RCC_private.h"
#include "RCC.h"

/********************************** Private declaration **********************************/


/********************************** Data Type Declarations ****************************/


/********************************** Macros Declarations *******************************/

/********************************** Macros Function Declarations *********************/

/******************************* Software Interfaces Implementation *******************/

Rcc_StatusErrorType Rcc_enuSetHsiTrimValue(u8 Copy_u8Value){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;

	RCC_setHSITrim(Copy_u8Value);

	return Loc_enuRccStatusError;
}


Rcc_StatusErrorType Rcc_enuEnableClockSecutiy(void){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;

	RCC_enableClockSecuritySystem();

	return Loc_enuRccStatusError;
}

Rcc_StatusErrorType Rcc_enuDisableClockSecutiy(void){

	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;

	RCC_disableClockSecuritySystem();

	return Loc_enuRccStatusError;
}


Rcc_StatusErrorType Rcc_enuEnableClock(Rcc_ClkSoruceIndexType Copy_enuClockSourceIndex){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;
	u8 Loc_u8CounterTimeOut = 240;
	switch (Copy_enuClockSourceIndex){

	case RCC_CLK_SOURCE_HSI_INDEX:
		RCC_enableHSI();
		while(RCC_IsHSIReady() == ZERO_VALUE && Loc_u8CounterTimeOut != ZERO_VALUE){
			Loc_u8CounterTimeOut--;
		}

		break;
	case RCC_CLK_SOURCE_HSE_INDEX:

		RCC_enableHSE();
		while(RCC_IsHSEReady() == ZERO_VALUE && Loc_u8CounterTimeOut != ZERO_VALUE){
			Loc_u8CounterTimeOut--;
		}
		break;

	case RCC_CLK_SOURCE_PLL_INDEX:
		RCC_enablePLL();
		while(RCC_IsPLLReady() == ZERO_VALUE && Loc_u8CounterTimeOut != ZERO_VALUE){
			Loc_u8CounterTimeOut--;
		}
		break;


	case RCC_CLK_SOURCE_PLLI2S_INDEX:
		RCC_enablePLLI2S();
		while(RCC_IsPLLReadyI2S() == ZERO_VALUE && Loc_u8CounterTimeOut != ZERO_VALUE){
			Loc_u8CounterTimeOut--;
		}
		break;

	case RCC_CLK_SOURCE_PLLSAI_INDEX:
		RCC_enablePLLSAI();
		while(RCC_IsPLLReadySAI() == ZERO_VALUE && Loc_u8CounterTimeOut != ZERO_VALUE){
			Loc_u8CounterTimeOut--;
		}
		break;

	default :
		Loc_enuRccStatusError = RCC_STATUS_WRONG_INDEX;
	}

	if(Loc_u8CounterTimeOut == ZERO_VALUE)
		Loc_enuRccStatusError = RCC_STATUS_TIME_OUT_FLAG;

	return Loc_enuRccStatusError;
}

Rcc_StatusErrorType Rcc_enuDisableClock(Rcc_ClkSoruceIndexType Copy_enuClockSourceIndex){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;


	switch (Copy_enuClockSourceIndex){

	case RCC_CLK_SOURCE_HSI_INDEX:
		RCC_disableHSI();
		break;

	case RCC_CLK_SOURCE_HSE_INDEX:

		RCC_disableHSE();
		break;

	case RCC_CLK_SOURCE_PLL_INDEX:
		RCC_disablePLL();
		break;

	case RCC_CLK_SOURCE_PLLI2S_INDEX:
		RCC_disablePLLI2S();
		break;

	case RCC_CLK_SOURCE_PLLSAI_INDEX:
		RCC_disablePLLSAI();

		break;

	default :
		Loc_enuRccStatusError = RCC_STATUS_WRONG_INDEX;
	}


	return Loc_enuRccStatusError;
}


Rcc_StatusErrorType Rcc_enuConfigPLL(const Rcc_PllConfigType* Address_Pll){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;

	if(Address_Pll == NULL){
		Loc_enuRccStatusError = RCC_STATUS_NULL_POINTER_ADDRESS;
	}
	else{
		RCC_setPLL_M_Factor(Address_Pll->rcc_PLL_M_From2To63);
		RCC_setPLL_N_Factor(Address_Pll->rcc_PLL_N_From50To432);
		RCC_setPLL_P_Factor(Address_Pll->rcc_select_pllp);
		RCC_setPLL_Q_Factor(Address_Pll->rcc_select_pllq);
		RCC_setPLLClk(Address_Pll->rcc_select_pll_source);
	}

	return Loc_enuRccStatusError;
}

Rcc_StatusErrorType Rcc_enuInitMCO2(Rcc_MCO2PinSelectClkSoruceType Copy_enuMCO2ClkSource,Rcc_MCO2PinSelectPrescalerType Copy_enuMCO2Prescaler){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;

	RCC_selectMoc2Prescaler(Copy_enuMCO2Prescaler);
	RCC_selectMoc2ClkSource(Copy_enuMCO2ClkSource);

	return Loc_enuRccStatusError;
}
Rcc_StatusErrorType Rcc_enuInitMCO1(Rcc_MCO1PinSelectClkSoruceType Copy_enuMCO1ClkSource,Rcc_MCO1PinSelectPrescalerType Copy_enuMCO1Prescaler){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;

	RCC_selectMoc1Prescaler(Copy_enuMCO1Prescaler);
	RCC_selectMoc1ClkSource(Copy_enuMCO1ClkSource);

	return Loc_enuRccStatusError;
}

Rcc_StatusErrorType Rcc_enuSelectAPB2Prescaler(Rcc_APB2SelectPrescalerType Copy_enuAPB2Prescaler){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;
	RCC_selectAPB2Prescaler(Copy_enuAPB2Prescaler);

	return Loc_enuRccStatusError;
}
Rcc_StatusErrorType Rcc_enuSelectAPB1Prescaler(Rcc_APB1SelectPrescalerType Copy_enuAPB1Prescaler){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;
	RCC_selectAPB1Prescaler(Copy_enuAPB1Prescaler);

	return Loc_enuRccStatusError;
}
Rcc_StatusErrorType Rcc_enuSelectAHBPrescaler(Rcc_AHBSelectPrescalerType Copy_enuAHBPrescaler){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;
	RCC_selectAHBPrescaler(Copy_enuAHBPrescaler);

	return Loc_enuRccStatusError;
}

Rcc_StatusErrorType Rcc_enuSelectSystemClkSource(Rcc_SystemClkSoruceIndexType Copy_enuSystemClkSource){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;

	RCC_selectSystemClk(Copy_enuSystemClkSource);
	return Loc_enuRccStatusError;
}

Rcc_StatusErrorType Rcc_enuGetSystemClkSource(Rcc_SystemClkSoruceIndexType* Address_ClkSource){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;
	if(Address_ClkSource == NULL){
		Loc_enuRccStatusError = RCC_STATUS_NULL_POINTER_ADDRESS;
	}
	else{
		*Address_ClkSource = RCC_getSystemClk();
	}

	return Loc_enuRccStatusError;
}

Rcc_StatusErrorType Rcc_enuEnablePeripheralClk(Rcc_BusIndexType Copy_enuBusIndex, u8 Copy_u8PeripheralIndex){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;
	if(Copy_u8PeripheralIndex>THIRTYONE_VALUE  || Copy_enuBusIndex > FOUR_VALUE){
		Loc_enuRccStatusError = RCC_STATUS_WRONG_INDEX;
	}
	else{
		WRITE_BIT((*Global_PeripheralClkRegEnArr[Copy_enuBusIndex]),Copy_u8PeripheralIndex,ONE_VALUE);
	}

	return Loc_enuRccStatusError;
}

Rcc_StatusErrorType Rcc_enuDisablePeripheralClk(Rcc_BusIndexType Copy_enuBusIndex, u8 Copy_u8PeripheralIndex){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;
	if(Copy_u8PeripheralIndex>THIRTYONE_VALUE  || Copy_enuBusIndex > FOUR_VALUE){
		Loc_enuRccStatusError = RCC_STATUS_WRONG_INDEX;
	}
	else{
		WRITE_BIT((*Global_PeripheralClkRegEnArr[Copy_enuBusIndex]),Copy_u8PeripheralIndex,ZERO_VALUE);
	}

	return Loc_enuRccStatusError;
}

Rcc_StatusErrorType Rcc_enuResetPeripheral(Rcc_BusIndexType Copy_enuBusIndex, u8 Copy_u8PeripheralIndex){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;
	volatile u16 Loc_u16DelayCounter = 1000;
	if(Copy_u8PeripheralIndex>THIRTYONE_VALUE  || Copy_enuBusIndex > FOUR_VALUE){
		Loc_enuRccStatusError = RCC_STATUS_WRONG_INDEX;
	}
	else{
		WRITE_BIT((*Global_PeripheralResetRegArr[Copy_enuBusIndex]),Copy_u8PeripheralIndex,ONE_VALUE);
		while(Loc_u16DelayCounter--){
			asm("NOP");
		}
		WRITE_BIT((*Global_PeripheralResetRegArr[Copy_enuBusIndex]),Copy_u8PeripheralIndex,ZERO_VALUE);
	}

	return Loc_enuRccStatusError;
}


Rcc_StatusErrorType Rcc_enuEnablePeripheralClkInLowPowerMode(Rcc_BusIndexType Copy_enuBusIndex, u8 Copy_u8PeripheralIndex){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;
	if(Copy_u8PeripheralIndex>THIRTYONE_VALUE  || Copy_enuBusIndex > FOUR_VALUE){
		Loc_enuRccStatusError = RCC_STATUS_WRONG_INDEX;
	}
	else{
		WRITE_BIT((*Global_PeripheralLowPowerClkRegEnArr[Copy_enuBusIndex]),Copy_u8PeripheralIndex,ONE_VALUE);
	}

	return Loc_enuRccStatusError;
}
Rcc_StatusErrorType Rcc_enuDisablePeripheralClkInLowPowerMode(Rcc_BusIndexType Copy_enuBusIndex, u8 Copy_u8PeripheralIndex){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;
	if(Copy_u8PeripheralIndex>THIRTYONE_VALUE  || Copy_enuBusIndex > FOUR_VALUE){
		Loc_enuRccStatusError = RCC_STATUS_WRONG_INDEX;
	}
	else{
		WRITE_BIT((*Global_PeripheralLowPowerClkRegEnArr[Copy_enuBusIndex]),Copy_u8PeripheralIndex,ONE_VALUE);
	}

	return Loc_enuRccStatusError;
}


Rcc_StatusErrorType Rcc_enuConfigPLLI2S(const Rcc_PllI2SConfigType* Address_PllI2S){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;

	if(Address_PllI2S == NULL){
		Loc_enuRccStatusError = RCC_STATUS_NULL_POINTER_ADDRESS;
	}
	else{

		RCC_setPLL_I2S_N_Factor(Address_PllI2S->rcc_PLLI2S_N_From50To432);
		RCC_setPLL_I2S_R_Factor(Address_PllI2S->rcc_select_pll_I2S_R);
		RCC_setPLL_I2S_Q_Factor(Address_PllI2S->rcc_select_pll_I2S_Q);
		RCC_setPLL_I2S_Clk(Address_PllI2S->rcc_select_pll_i2s_source_clk);
	}

	return Loc_enuRccStatusError;
}


Rcc_StatusErrorType Rcc_enuConfigPLLSAI(const Rcc_PllSAIConfigType* Address_PllSAI){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;

	if(Address_PllSAI == NULL){
		Loc_enuRccStatusError = RCC_STATUS_NULL_POINTER_ADDRESS;
	}
	else{

		RCC_setPLL_SAI_N_Factor(Address_PllSAI->rcc_PLLSAI_N_From50To432);
		RCC_setPLL_SAI_Q_Factor(Address_PllSAI->rcc_select_pll_SAI_Q);
		RCC_setPLL_SAI_R_Factor(Address_PllSAI->rcc_select_pll_SAI_R);

		RCC_setPLL_SAI_QX_PLLI2SDIVQ_Factor(Address_PllSAI->rcc_PLLSAI_PLLI2SDIVQ_Qx_Last_FROM1to50);
		RCC_setPLL_SAI_QY_PLLSAIDIVQ_Factor(Address_PllSAI->rcc_PLLSAI_PLLSAIDIVQ_Qy_Last_FROM1to50);
		RCC_setPLL_SAI_RLcd_PLLSAIDIVR_Factor(Address_PllSAI->rcc_select_pll_SAI_R);

		RCC_setPLL_SAI1A_Clk(Address_PllSAI->rcc_select_SAI1A_source);
		RCC_setPLL_SAI1B_Clk(Address_PllSAI->rcc_select_SAI1B_source);



	}

	return Loc_enuRccStatusError;


}


Rcc_StatusErrorType Rcc_enuInit(const Rcc_ConfigType* Address_Rcc){
	Rcc_StatusErrorType Loc_enuRccStatusError = RCC_STATUS_OK;

	if(Address_Rcc == NULL){
		Loc_enuRccStatusError = RCC_STATUS_NULL_POINTER_ADDRESS;
	}
	else{

		/*  Enable Clocks */
		if(Address_Rcc->rcc_hse_on_or_off == RCC_ON){
			Loc_enuRccStatusError = Rcc_enuEnableClock(Address_Rcc->rcc_hse_on_or_off);
		}

		else{
			Loc_enuRccStatusError = Rcc_enuDisableClock(Address_Rcc->rcc_hse_on_or_off);
		}

		if(Address_Rcc->rcc_hsi_on_or_off == RCC_ON){
			Loc_enuRccStatusError = Rcc_enuEnableClock(Address_Rcc->rcc_hsi_on_or_off);
		}
		else{
			Loc_enuRccStatusError = Rcc_enuDisableClock(Address_Rcc->rcc_hsi_on_or_off);
		}


		if(Address_Rcc->rcc_pll_on_or_off == RCC_ON && Address_Rcc->address_pll_cfg  != NULL){
			Loc_enuRccStatusError = Rcc_enuConfigPLL(Address_Rcc->address_pll_cfg);
			Loc_enuRccStatusError = Rcc_enuEnableClock(Address_Rcc->rcc_pll_on_or_off);
		}
		else{
			Loc_enuRccStatusError = Rcc_enuDisableClock(Address_Rcc->rcc_pll_on_or_off);
		}

		if(Address_Rcc->rcc_pllI2S_on_or_off == RCC_ON && Address_Rcc->adress_pll_i2s_cfg  != NULL){
			Loc_enuRccStatusError = 	Rcc_enuConfigPLLI2S(Address_Rcc->adress_pll_i2s_cfg);
			Loc_enuRccStatusError = Rcc_enuEnableClock(Address_Rcc->rcc_pllI2S_on_or_off);
		}
		else{
			Loc_enuRccStatusError = 	Rcc_enuDisableClock(Address_Rcc->rcc_pllI2S_on_or_off);
		}

		if(Address_Rcc->rcc_pllSAI_on_or_off == RCC_ON && Address_Rcc->address_pll_sai_cfg  != NULL){
			Loc_enuRccStatusError = Rcc_enuConfigPLLSAI(Address_Rcc->address_pll_sai_cfg);
			Loc_enuRccStatusError = Rcc_enuEnableClock(Address_Rcc->rcc_pllSAI_on_or_off);
		}
		else{
			Loc_enuRccStatusError = Rcc_enuDisableClock(Address_Rcc->rcc_pllSAI_on_or_off);
		}

		Loc_enuRccStatusError = Rcc_enuSelectAPB2Prescaler(Address_Rcc->rcc_apb2_select_prescaler );
		Loc_enuRccStatusError = Rcc_enuSelectAPB1Prescaler( Address_Rcc->rcc_apb1_select_prescaler);
		Loc_enuRccStatusError = Rcc_enuSelectAHBPrescaler( Address_Rcc->rcc_ahb_select_prescaler);
		Loc_enuRccStatusError = Rcc_enuSelectSystemClkSource(Address_Rcc->rcc_sysmte_clk_soruce);


	}

	return Loc_enuRccStatusError;
}
/**************************** Private Software Interface Implementation **************/

