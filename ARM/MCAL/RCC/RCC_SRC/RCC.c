/*
 * RCC.c
 *
 *  Created on: Nov 5, 2023
 *      Author: computer store
 */

#include "MCAL/RCC/RCC_Includes/RCC.h"


Rcc_tenuErrorStatus Rcc_enuSelectSysCLk(uint8 Copy_u8SysClk , uint8 Copy_u8OldSysClk)
{
	uint8 Ready_Flag_Value = 0;
	uint8 Ready_Flag_Location = 0;

	//get flag location to read according to the desired clock to select
	switch(Copy_u8SysClk)
	{
	case RCC_CLK_HSI:
		Ready_Flag_Location = 1;
		break;

	case RCC_CLK_HSE:
		Ready_Flag_Location = 17;
		break;

	case RCC_CLK_PLL: //check if locked or not but doesn't check that it's generating a clock
		Ready_Flag_Location = 25;
		break;
	}

	//read the flag according to it's location Ready_Flag_Location
	for(uint8 cnt=0; cnt < 100 && Ready_Flag_Value == 0; cnt++)
	{
		Ready_Flag_Value = Bit_Band_Peripheral(RCC->RCC_CFGR, Ready_Flag_Location);
	}

	//for keil only
	Ready_Flag_Value = 1;

	//if flag is true
	if(Ready_Flag_Value)
	{
		// read the current clock but commented for keil
		uint8 Old_Clock = Bit_Band_Peripheral(RCC->RCC_CFGR, 2) | (Bit_Band_Peripheral(RCC->RCC_CFGR, 3) << 1);

		//select the new clock
		Bit_Band_Peripheral(RCC->RCC_CFGR, 0) = GET_BIT(Copy_u8SysClk, 0);
		Bit_Band_Peripheral(RCC->RCC_CFGR, 1) = GET_BIT(Copy_u8SysClk, 1);

		//check if the old clock is not the new clock and the user wants to close the clock
		//wait commented for keil
		if(Copy_u8OldSysClk && Old_Clock != Copy_u8SysClk)
		{
			switch(Old_Clock)// disable old clock
			{
			case RCC_CLK_HSI:
				Bit_Band_Peripheral(RCC->RCC_CR, 0) = 0; //disable o
				break;

			case RCC_CLK_HSE:
				Bit_Band_Peripheral(RCC->RCC_CR, 16) = 0;
				break;

			case RCC_CLK_PLL:
				Bit_Band_Peripheral(RCC->RCC_CR, 24) = 0;
				break;
			}
		}
	}
	return Rcc_enuOk;
}

Rcc_tenuErrorStatus Rcc_enuControlCLk(uint8 Copy_u8ControlHSI  ,uint8 Copy_u8ControlHSE ,uint8 Copy_u8ControlPLL_Main, uint8 Copy_u8ControlPLL_I2S)
{
	// read the current clock but commented for keil
	uint8 System_Clock = Bit_Band_Peripheral(RCC->RCC_CFGR, 2) | (Bit_Band_Peripheral(RCC->RCC_CFGR, 3) << 1);

	if(System_Clock != RCC_CLK_PLL) //commented for keil
		//main PLL
		Bit_Band_Peripheral(RCC->RCC_CR, 24) = Copy_u8ControlPLL_Main;

	//I2S PLL
	Bit_Band_Peripheral(RCC->RCC_CR, 26) = Copy_u8ControlPLL_I2S;

	//HSE
	Bit_Band_Peripheral(RCC->RCC_CR, 16) = Copy_u8ControlHSE;

	//HSI
	Bit_Band_Peripheral(RCC->RCC_CR, 0) = Copy_u8ControlHSI;

	return Rcc_enuOk;
}

Rcc_tenuErrorStatus Rcc_enuCheckCLk(uint8 Copy_u8CLk, Puint8 Add_pu8RdyStatus)
{
	uint8 Ready_Flag_Value = 0;
	uint8 Ready_Flag_Location = 0;

	//get flag location to read according to the desired clock to select
	switch(Copy_u8CLk)
	{
	case RCC_CLK_HSI:
		Ready_Flag_Location = 1;
		break;

	case RCC_CLK_HSE:
		Ready_Flag_Location = 17;
		break;

	case RCC_CLK_PLL: //check if locked or not but doesn't check that it's generating a clock
		Ready_Flag_Location = 25;
		break;
	}

	//read the flag according to it's location Ready_Flag_Location
	for(uint8 cnt=0; cnt < 100 && Ready_Flag_Value == 0; cnt++)
	{
		Ready_Flag_Value = Bit_Band_Peripheral(RCC->RCC_CFGR, Ready_Flag_Location);
	}

	*Add_pu8RdyStatus = Ready_Flag_Value;
	return Rcc_enuOk;
}

Rcc_tenuErrorStatus Rcc_enuCnfgrPll(uint8 COPY_u8M , uint16 Copy_u16N , uint8 Copy_u8P , uint8 Copy_u8SrcPll , uint8 Copy_u8Q)
{
	RCC->RCC_PLLCFGR = ( COPY_u8M << 0) | (Copy_u16N << 6) | (Copy_u8P) | (Copy_u8SrcPll) | (Copy_u8Q);
	return Rcc_enuOk;
}

Rcc_tenuErrorStatus Rcc_enuEnablePeriphral(uint8 Copy_u8PeriphralBus , uint32 Copy_u32Periphral)
{
	uint32 Temp_Reg = RCC->RCC_AHB1ENR;
	Temp_Reg &= ~(Copy_u32Periphral);
	switch(Copy_u8PeriphralBus)
	{
	case RCC_REGISTER_AHB1:
	case RCC_REGISTER_AHB2:
	case RCC_REGISTER_APB1:
	case RCC_REGISTER_APB2:
		Temp_Reg |= Copy_u32Periphral;
		RCC->RCC_AHB1ENR = Temp_Reg;
	break;
	}
	return Rcc_enuOk;
}

Rcc_tenuErrorStatus Rcc_enuDisablePeriphral(uint8 Copy_u8PeriphralBus , uint32 Copy_u32Periphral)
{
	uint32 Temp_Reg = RCC->RCC_AHB1ENR;
	switch(Copy_u8PeriphralBus)
	{
	case RCC_REGISTER_AHB1:
	case RCC_REGISTER_AHB2:
	case RCC_REGISTER_APB1:
	case RCC_REGISTER_APB2:
		Temp_Reg &= ~(Copy_u32Periphral);
		RCC->RCC_APB2ENR = Temp_Reg;
	break;
	}
	return Rcc_enuOk;
}

Rcc_tenuErrorStatus Rcc_enuCfgBusPrescalers(uint8 Copy_u8PeriphralBus, uint32 Copy_u32Prescaler)
{
	uint32 Temp_Reg = RCC->RCC_AHB1ENR;
	Temp_Reg &= ~(Copy_u32Prescaler);
	switch(Copy_u8PeriphralBus)
	{
	case RCC_REGISTER_AHB1:
	case RCC_REGISTER_AHB2:
	case RCC_REGISTER_APB1:
	case RCC_REGISTER_APB2:
		Temp_Reg |= Copy_u32Prescaler;
		RCC->RCC_AHB1ENR = Temp_Reg;
	break;
	}
	return Rcc_enuOk;
}
