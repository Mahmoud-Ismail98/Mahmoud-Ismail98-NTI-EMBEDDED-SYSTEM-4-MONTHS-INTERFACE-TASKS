#include "Std_types.h"
#include "Bit_utils.h"

#include "RCC.h"
#include "RCC_prv.h"
#include "RCC_cfg.h"
RCC_t *RCC = 0x40023800;

RCC_enumErrStatus_t RCC_enumSetSystemBus(u8 Copy_u8RCCSource)
{
	u32 Local_u32TimeOut = 0;
	RCC_enumErrStatus_t Local_enumErrStatus = Rcc_enumOk;
	switch(Copy_u8RCCSource)
	{
		case RCC_CLK_HSI:
			Rcc_enuControlCLk(RCC_CNTROL_HSION  ,RCC_CNTROL_HSEON ,RCC_CNTROL_PLLOFF);
			CLR_BITBAND(RCC->CFGR,0);
			CLR_BITBAND(RCC->CFGR,1);
			while(GET_BIT(RCC->CFGR,2) !=0 && GET_BIT(RCC->CFGR,3)!=0)
			{
				Local_u32TimeOut++;
				if(Local_u32TimeOut>10000000)
				{
					Local_enumErrStatus = Rcc_enumTimeOutError;
					break;
				}
			}
			Rcc_enuControlCLk(RCC_CNTROL_HSION  ,RCC_CNTROL_HSEOFF ,RCC_CNTROL_PLLOFF);
			break;
		case RCC_CLK_HSE:
			Rcc_enuControlCLk(RCC_CNTROL_HSION  ,RCC_CNTROL_HSEON ,RCC_CNTROL_PLLOFF);
			SET_BITBAND(RCC->CFGR,0);
			CLR_BITBAND(RCC->CFGR,1);
			while(GET_BIT(RCC->CFGR,2) !=1 && GET_BIT(RCC->CFGR,3)!=0)
			{
				Local_u32TimeOut++;
				if(Local_u32TimeOut>10000000)
				{
					Local_enumErrStatus = Rcc_enumTimeOutError;
					break;
				}
			}
			Rcc_enuControlCLk(RCC_CNTROL_HSIOFF  ,RCC_CNTROL_HSEON ,RCC_CNTROL_PLLOFF);
			break;
		case RCC_CLK_HSI_PLL:
			Rcc_enuCnfgrPll(PLL_Mcfg , PLL_Ncfg, PLL_Pcfg , RCC_PLLSRC_HSI , PLL_Qcfg);
			Rcc_enuControlCLk(RCC_CNTROL_HSION  ,RCC_CNTROL_HSEON ,RCC_CNTROL_PLLON);
			CLR_BITBAND(RCC->CFGR,0);
			SET_BITBAND(RCC->CFGR,1);
			while(GET_BIT(RCC->CFGR,2) !=0 && GET_BIT(RCC->CFGR,3)!=1)
			{
				Local_u32TimeOut++;
				if(Local_u32TimeOut>10000000)
				{
					Local_enumErrStatus = Rcc_enumTimeOutError;
					break;
				}
			}
			Rcc_enuControlCLk(RCC_CNTROL_HSION  ,RCC_CNTROL_HSEOFF ,RCC_CNTROL_PLLON);
			break;
		case RCC_CLK_HSE_PLL:
			Rcc_enuCnfgrPll(PLL_Mcfg , PLL_Ncfg, PLL_Pcfg , RCC_PLLSRC_HSE , PLL_Qcfg);
			Rcc_enuControlCLk(RCC_CNTROL_HSION  ,RCC_CNTROL_HSEON ,RCC_CNTROL_PLLON);
			CLR_BITBAND(RCC->CFGR,0);
			SET_BITBAND(RCC->CFGR,1);
			while(GET_BIT(RCC->CFGR,2) !=0 && GET_BIT(RCC->CFGR,3)!=1)
			{
				Local_u32TimeOut++;
				if(Local_u32TimeOut>10000000)
				{
					Local_enumErrStatus = Rcc_enumTimeOutError;
					break;
				}
			}
			Rcc_enuControlCLk(RCC_CNTROL_HSIOFF  ,RCC_CNTROL_HSEON ,RCC_CNTROL_PLLON);
			break;
		default:
			Local_enumErrStatus = RCC_enumUnLogicActionError;
			break;
	}
//	SET_BITBAND(RCC->AHB1ENR,Copy_u32Periphral);
	//SET_BIT(RCC_AHB1ENR,0);
	//RCC_AHB1ENR = 1;
	return Local_enumErrStatus;
}
RCC_enumErrStatus_t Rcc_enuControlCLk(u8 Copy_u8ControlHSI  ,u8 Copy_u8ControlHSE ,u8 Copy_u8ControlPLL)
{
	u32 Local_counter_ErrStat = 0;
	RCC_enumErrStatus_t Local_enumErrStatus = Rcc_enumOk;
	if(Copy_u8ControlHSI == RCC_CNTROL_HSION)
	{
		SET_BITBAND(RCC->CR,HSION);
		while(GET_BIT(RCC->CR,HSIRDY)== 0)
		{
			Local_counter_ErrStat++;
			if(Local_counter_ErrStat == 10000000)
			{
				Local_enumErrStatus = Rcc_enumTimeOutError;
				break;
			}
		}
	}
	else if (Copy_u8ControlHSI == RCC_CNTROL_HSIOFF)
	{
		CLR_BITBAND(RCC->CR,HSION);
	}
	else
	{
		Local_enumErrStatus = RCC_enumUnLogicActionError;
	}
	if(Copy_u8ControlHSE == RCC_CNTROL_HSEON)
	{
		SET_BITBAND(RCC->CR,HSEON);
		while(GET_BIT(RCC->CR,HSERDY)== 0)
		{
			Local_counter_ErrStat++;
			if(Local_counter_ErrStat == 10000000)
			{
				Local_enumErrStatus = Rcc_enumTimeOutError;
				break;
			}
		}
		
	}
	else if (Copy_u8ControlHSE == RCC_CNTROL_HSEOFF)
	{
		CLR_BITBAND(RCC->CR,HSEON);
	}
	else
	{
		Local_enumErrStatus = RCC_enumUnLogicActionError;
	}
	if(Copy_u8ControlPLL == RCC_CNTROL_PLLON)
	{
		SET_BITBAND(RCC->CR,PLLON);
		while(GET_BIT(RCC->CR,PLLRDY)== 0)
		{
			Local_counter_ErrStat++;
			if(Local_counter_ErrStat == 10000000)
			{
				Local_enumErrStatus = Rcc_enumTimeOutError;
				break;
			}
		}
		
	}
	else if (Copy_u8ControlPLL == RCC_CNTROL_PLLOFF)
	{
		CLR_BITBAND(RCC->CR,PLLON);
	}
	else
	{
		Local_enumErrStatus = RCC_enumUnLogicActionError;
	}
	return Local_enumErrStatus;
}
RCC_enumErrStatus_t Rcc_enuCheckCLk(u8 Copy_u8CLk, pu8 Add_pu8RdyStatus) 
{
	u32 RCC_CFGRstatus = (((RCC->CFGR)>>2)|0x00000003);
	RCC_enumErrStatus_t Local_enumErrStatus = Rcc_enumOk;
	switch(Copy_u8CLk)
	{
		case RCC_CLK_HSI:
			if(RCC_CFGRstatus == 0)
			{
				*Add_pu8RdyStatus = RCC_STATE_READY;
			}
			else
			{
				*Add_pu8RdyStatus = RCC_STATE_NOTREADY;
			}
			break;
		case RCC_CLK_HSE:
			if(RCC_CFGRstatus == 1)
			{
				*Add_pu8RdyStatus = RCC_STATE_READY;
			}
			else
			{
				*Add_pu8RdyStatus = RCC_STATE_NOTREADY;
			}
			break;
		case RCC_CLK_PLL:
			if(RCC_CFGRstatus == 2)
			{
				*Add_pu8RdyStatus = RCC_STATE_READY;
			}
			else
			{
				*Add_pu8RdyStatus = RCC_STATE_NOTREADY;
			}
			break;
		default:
		Local_enumErrStatus = RCC_enumUnLogicActionError;
		break;
	}
	return Local_enumErrStatus;
}
RCC_enumErrStatus_t Rcc_enuCnfgrPll(u8 COPY_u8M , u16 Copy_u16N , u8 Copy_u8P , u8 Copy_u8SrcPll , u8 Copy_u8Q)
{
	RCC_enumErrStatus_t Local_enumErrStatus = Rcc_enumOk;
	if(COPY_u8M < 64 && COPY_u8M > 1)
	{
		RCC->PLLCFGR = ((RCC->PLLCFGR & 0xFFFFFFC0)|COPY_u8M);
	}
	else
	{
		Local_enumErrStatus = RCC_enumInvalid_M_Error;
	}
	if(Copy_u16N < 433 && Copy_u16N >192)
	{
		RCC->PLLCFGR = ((RCC->PLLCFGR & 0xFFFF803F)|Copy_u16N);
	}
	else
	{
		Local_enumErrStatus = RCC_enumInvalid_N_Error;
	}
	if(Copy_u8P < 4)
	{
		RCC->PLLCFGR = ((RCC->PLLCFGR & 0xFFFCFFFF)|Copy_u8P);
	}
	else
	{
		Local_enumErrStatus = RCC_enumInvalid_P_Error;
	}
	if(Copy_u8Q < 16 && Copy_u8Q >1)
	{
		RCC->PLLCFGR = ((RCC->PLLCFGR & 0xF0FFFFFF)|Copy_u8Q);		
	}
	else
	{
		Local_enumErrStatus = RCC_enumInvalid_Q_Error;
	}
	if(Copy_u8SrcPll<2)
	{
		BITBAND_REG(RCC->PLLCFGR,PLLSRC) = Copy_u8SrcPll;
	}
	else
	{
		Local_enumErrStatus = RCC_enumInvalid_ScrPll_Error;
	}
	return Local_enumErrStatus;
}
RCC_enumErrStatus_t Rcc_enuEnablePeriphral(u8 Copy_u8PeriphralBus , u32 Copy_u32Periphral)
{
	RCC_enumErrStatus_t Local_enumErrStatus = Rcc_enumOk;
	switch(Copy_u8PeriphralBus)
	{
		case RCC_REGISTER_AHB1:
			//RCC->AHB1ENR = (RCC->AHB1ENR|Copy_u32Periphral);	
			SET_BITBAND(RCC->AHB1ENR,Copy_u32Periphral);
			break;
		case RCC_REGISTER_AHB2:
			//RCC->AHB2ENR = (RCC->AHB2ENR|Copy_u32Periphral);
			SET_BITBAND(RCC->AHB2ENR,Copy_u32Periphral);
			break;
		case RCC_REGISTER_APB1:
			//RCC->APB1ENR = (RCC->APB1ENR|Copy_u32Periphral);
			SET_BITBAND(RCC->APB1ENR,Copy_u32Periphral);
			
			break;
		case RCC_REGISTER_APB2:
			//RCC->APB2ENR = (RCC->APB2ENR|Copy_u32Periphral);
			SET_BITBAND(RCC->APB2ENR,Copy_u32Periphral);
			break;
		default:
			Local_enumErrStatus = Rcc_enumWrongPeriphralBusError;
			break;
	}
	return Local_enumErrStatus;
}
RCC_enumErrStatus_t Rcc_enuDisablePeriphral(u8 Copy_u8PeriphralBus , u32 Copy_u32Periphral)
{
	RCC_enumErrStatus_t Local_enumErrStatus = Rcc_enumOk;
	switch(Copy_u8PeriphralBus)
	{
		case RCC_REGISTER_AHB1:
			//RCC->AHB1ENR = (RCC->AHB1ENR|Copy_u32Periphral);	
			CLR_BITBAND(RCC->AHB1ENR,Copy_u32Periphral);
			break;
		case RCC_REGISTER_AHB2:
			//RCC->AHB2ENR = (RCC->AHB2ENR|Copy_u32Periphral);
			CLR_BITBAND(RCC->AHB2ENR,Copy_u32Periphral);
			break;
		case RCC_REGISTER_APB1:
			//RCC->APB1ENR = (RCC->APB1ENR|Copy_u32Periphral);
			CLR_BITBAND(RCC->APB1ENR,Copy_u32Periphral);
			
			break;
		case RCC_REGISTER_APB2:
			//RCC->APB2ENR = (RCC->APB2ENR|Copy_u32Periphral);
			CLR_BITBAND(RCC->APB2ENR,Copy_u32Periphral);
			break;
		default:
			Local_enumErrStatus = Rcc_enumWrongPeriphralBusError;
			break;
	}
	return Local_enumErrStatus;	
}
RCC_enumErrStatus_t Rcc_enuCfgBusPrescalers(u8 Copy_u8PeriphralBus, u32 Copy_u32Prescaler)
{
	RCC_enumErrStatus_t Local_enumErrStatus = Rcc_enumOk;
	switch(Copy_u8PeriphralBus)
	{
		case RCC_REGISTER_AHB1:
			RCC->CFGR = ((RCC->CFGR&0xFFFFFF0F)|(Copy_u32Prescaler<<4));	
			break;
		case RCC_REGISTER_AHB2:
			RCC->CFGR = ((RCC->CFGR&0xFFFFFF0F)|(Copy_u32Prescaler<<4));	
			break;

		case RCC_REGISTER_APB1:
			RCC->CFGR = ((RCC->CFGR&0xFFFFE3FF)|(Copy_u32Prescaler<<10));	
			break;

		case RCC_REGISTER_APB2:
			RCC->CFGR = ((RCC->CFGR&0xFFFF1FFF)|(Copy_u32Prescaler<<13));	
			break;
		default:
			Local_enumErrStatus = Rcc_enumWrongBusPrescalerError;
			break;
	}
	return Local_enumErrStatus;		
}
