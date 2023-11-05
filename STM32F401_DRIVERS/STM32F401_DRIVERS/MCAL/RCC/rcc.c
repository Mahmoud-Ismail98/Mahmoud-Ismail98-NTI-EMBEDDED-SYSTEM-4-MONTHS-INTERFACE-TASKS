#include "../../services/Std_types.h"
#include "../../servicesBit_utils.h"
#include "rcc.h"

typedef struct
{
	volatile u32 RCC_CR;
	volatile u32 RCC_PLLCFGR;
	volatile u32 RCC_CFGR;
	volatile u32 RCC_CIR;
	volatile u32 RCC_AHB1RSTR;
	volatile u32 RCC_AHB2RSTR;
	volatile u32 RCC_Reserved1;
	volatile u32 RCC_Reserved2;	
	volatile u32 RCC_APB1RSTR;
	volatile u32 RCC_APB2RSTR;
	volatile u32 RCC_Reserved3;
	volatile u32 RCC_Reserved4;	
	volatile u32 RCC_AHB1ENR;
	volatile u32 RCC_AHB2ENR;
	volatile u32 RCC_Reserved5;
	volatile u32 RCC_Reserved6;	
	volatile u32 RCC_APB1ENR;
	volatile u32 RCC_APB2ENR;
	volatile u32 RCC_Reserved7;
	volatile u32 RCC_Reserved8;	
	volatile u32 RCC_AHB1LPENR;
	volatile u32 RCC_AHB2LPENR;
	volatile u32 RCC_Reserved9;
	volatile u32 RCC_Reserved10;	
	volatile u32 RCC_APB1LPENR;
	volatile u32 RCC_APB2LPENR;
	volatile u32 RCC_Reserved11;
	volatile u32 RCC_Reserved12;	
	volatile u32 RCC_BDCR;
	volatile u32 RCC_CSR;
	volatile u32 RCC_Reserved13;
	volatile u32 RCC_Reserved14;
	volatile u32 RCC_SSCGR;
	volatile u32 RCC_PLLI2SCFGR;
	volatile u32 RCC_DCKCFGR;
} RCC_t;


#define RCC    ((volatile  RCC_t *)0x40023800)



Rcc_tenuErrorStatus Rcc_enuSelectSysCLk(u8 Copy_u8NewSysClk,u8 Copy_u8OldSysClk)
{
	Rcc_tenuErrorStatus Error_Status = Rcc_enuOk;   
	switch (Copy_u8NewSysClk)
	{
	case RCC_CLK_HSI:
		SET_BIT(RCC->RCC_CR, 0);
	
		//while (GET_BIT(RCC->RCC_CR,1)==0);
		RCC->RCC_CFGR =((RCC->RCC_CFGR & ~(0x00000003)) | 0x0000000);
		break;
	case RCC_CLK_HSE:
		SET_BIT(RCC->RCC_CR, 16);
		//while (!GET_BIT(RCC->RCC_CR,17));
	//  RCC->RCC_CFGR =((RCC->RCC_CFGR & ~(0x00000003)) | 0x00000001);
		RCC->RCC_CFGR =((RCC->RCC_CFGR & 0xFFFFFFFC)| 0x00000001);
		break;
	case RCC_CLK_PLL:
		SET_BIT(RCC->RCC_CR, 24);
  //while(GET_BIT(RCC->RCC_CR,25) == 0);
   RCC->RCC_CFGR = ((RCC->RCC_CFGR & ~(0x00000003)) | 0x00000002);
		break;
	default:
		break;
	}

	switch (Copy_u8OldSysClk)
	{
	case RCC_HSI_disable:
		CLR_BIT(RCC->RCC_CR,0);
		break;
	case RCC_HSE_disable:
		CLR_BIT(RCC->RCC_CR,16);
		break;
	case RCC_PLL_disable:
		CLR_BIT(RCC->RCC_CR,24);
		break;
	default:
		break;
	}
	return Error_Status;
}

Rcc_tenuErrorStatus Rcc_enuControlCLk(u8 Copy_u8ControlHSI,u8 Copy_u8ControlHSE, u8 Copy_u8ControlPLL)
{
	Rcc_tenuErrorStatus Error_Status = Rcc_enuOk;
	switch (Copy_u8ControlHSI)
	{
	case RCC_CNTROL_HSION:
			SET_BIT(RCC->RCC_CR, 0);
		break;
	case RCC_CNTROL_HSIOFF:
			CLR_BIT(RCC->RCC_CR,0);
		break;
	}
	switch (Copy_u8ControlHSE)
	{
	case RCC_CNTROL_HSEON:
			SET_BIT(RCC->RCC_CR, 16);
		break;
	case RCC_CNTROL_HSEOFF:
			CLR_BIT(RCC->RCC_CR, 16);
		break;
	}
	switch (Copy_u8ControlPLL)
	{
	case RCC_CNTROL_PLLON:
			SET_BIT(RCC->RCC_CR, 24);
		break;
	case RCC_CNTROL_PLLOFF:
			CLR_BIT(RCC->RCC_CR, 24);
		break;
	}
	return Error_Status;
}


Rcc_tenuErrorStatus Rcc_enuCheckCLk(u8 Copy_u8CLk, pu8 Add_pu8RdyStatus)
{
	Rcc_tenuErrorStatus Error_Status = Rcc_enuOk;
		switch (Copy_u8CLk)
		{

		case RCC_CLK_HSI:
			if (GET_BIT(RCC->RCC_CR,0))
			{
				*Add_pu8RdyStatus = RCC_STATE_READY;
			}
			else
			{
				*Add_pu8RdyStatus = RCC_STATE_NOTREADY;
			}
			break;
		case RCC_CLK_HSE:
			if (GET_BIT(RCC->RCC_CR,16))
			{
				*Add_pu8RdyStatus = RCC_STATE_READY;
			}
			else
			{
				*Add_pu8RdyStatus = RCC_STATE_NOTREADY;
			}
			break;
 		case RCC_CLK_PLL:
			if (GET_BIT(RCC->RCC_CR,24))
			{
				*Add_pu8RdyStatus = RCC_STATE_READY;
			}
			else
			{
				*Add_pu8RdyStatus = RCC_STATE_NOTREADY;
			}

			break;
		}
	return Error_Status;

}

Rcc_tenuErrorStatus Rcc_enuCnfgrPll(u8 COPY_u8M , u16 Copy_u16N , u8 Copy_u8P , u8 Copy_u8SrcPll , u8 Copy_u8Q)
{
	Rcc_tenuErrorStatus Error_Status = Rcc_enuOk;
	
		u32 RCC_CNFGR_PLLM=((COPY_u8M));
		u32 RCC_CNFGR_PLLN=((Copy_u16N)<<6);
		u32 RCC_CNFGR_PLLP=((Copy_u8P)<<16);
		u32 RCC_CNFGR_SRCPLL=((Copy_u8SrcPll)<<22);
		u32 RCC_CNFGR_Q=((Copy_u8Q)<<24);	
		RCC->RCC_PLLCFGR=(RCC_CNFGR_PLLM | RCC_CNFGR_PLLN | RCC_CNFGR_PLLP | RCC_CNFGR_SRCPLL | RCC_CNFGR_Q);	
		return Error_Status;
}
Rcc_tenuErrorStatus Rcc_enuEnablePeriphral(u8 Copy_u8PeriphralBus,
		u32 Copy_u32Periphral)
{
	Rcc_tenuErrorStatus Error_Status = Rcc_enuOk;
	switch (Copy_u8PeriphralBus)
	{
	case RCC_REGISTER_AHB1:
		RCC->RCC_AHB1ENR |= Copy_u32Periphral;
		break;
	case RCC_REGISTER_AHB2:
		RCC->RCC_AHB2ENR |= Copy_u32Periphral;
		break;
	case RCC_REGISTER_APB1:
		RCC->RCC_APB1ENR |= Copy_u32Periphral;
		break;
	case RCC_REGISTER_APB2:
		RCC->RCC_APB2ENR |= Copy_u32Periphral;
		break;
	default:
		Error_Status = Rcc_enuWrongPeriphralBusError;
		break;
	}

	return Error_Status;

}
Rcc_tenuErrorStatus Rcc_enuDisablePeriphral(u8 Copy_u8PeriphralBus,
		u32 Copy_u32Periphral)
{
	Rcc_tenuErrorStatus Error_Status = Rcc_enuOk;
	switch (Copy_u8PeriphralBus)
	{
	case RCC_REGISTER_AHB1:
		RCC->RCC_AHB1ENR &= ~Copy_u32Periphral;
		break;
	case RCC_REGISTER_AHB2:
		RCC->RCC_AHB2ENR &= ~Copy_u32Periphral;
		break;
	case RCC_REGISTER_APB1:
		RCC->RCC_APB1ENR &= ~Copy_u32Periphral;
		break;
	case RCC_REGISTER_APB2:
		RCC->RCC_APB2ENR &= ~Copy_u32Periphral;
		break;
	default:
		Error_Status = Rcc_enuWrongPeriphralBusError;
		break;
	}

	return Error_Status;

}