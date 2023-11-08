#include "std_types.h"
#include "utile.h"
#include "RCC.h"

#define SW_Mask       0x0000000C
#define TimeOut        5000
#define RCCSWS_STATE 				(((RCC->RCC_CFGR) & (SW_Mask)) >> 2)
typedef struct
{
	volatile u32 RCC_CR;
	volatile u32 RCC_PLLCFGR;
	volatile u32 RCC_CFGR;
	volatile u32 RCC_CIR;
	volatile u32 RCC_AHB1RSTR;
	volatile u32 RCC_AHB2RSTR;
	volatile u32 RCC_Reserved[2];
	volatile u32 RCC_APB1RSTR;
	volatile u32 RCC_APB2RSTR;
	volatile u32 RCC1_Reserved[2];
	volatile u32 RCC_AHB1ENR;
	volatile u32 RCC_AHB2ENR;
	volatile u32 RCC2_Reserved[2];
	volatile u32 RCC_APB1ENR;
	volatile u32 RCC_APB2ENR;
	volatile u32 RCC3_Reserved[2];
	volatile u32 RCC_AHB1LPENR;
	volatile u32 RCC_AHB2LPENR;
	volatile u32 RCC4_Reserved[2];
	volatile u32 RCC_APB1LPENR;
	volatile u32 RCC_APB2LPENR;
	volatile u32 RCC5_Reserved[2];
	volatile u32 RCC_BDCR;
	volatile u32 RCC_CSR;
	volatile u32 RCC6_Reserved[2];
	volatile u32 RCC_SSCGR;
	volatile u32 RCC_PLLI2SCFGR;
	volatile u32 RCC_DCKCFGR;
}RCC_REG;
#define RCC    ((RCC_REG*)(0x40023800))



Rcc_tenuErrorStatus Rcc_enuSelectSysCLk(u8 Copy_u8SysClk ){
	Rcc_tenuErrorStatus Error_State = Rcc_enuOk;
	u32 Local_u8Counter = 0 ;
	/* Switch on System Clock */
	switch (Copy_u8SysClk)
	{
	/* Case of The Clock Is HSI */
	case RCC_CLK_HSI:
		/* Set Bit 0 OF CLK_HSI */
		SET_BIT(RCC -> RCC_CR,0);
		/* wating HSI  To Be Ready */
		while (GET_BIT(RCC -> RCC_CR,1)== 0){
			/* Increament The Counter */
			Local_u8Counter ++;
			/* Check Counter To Equal TimeOut */
			if (Local_u8Counter == TimeOut)
			{
				/* NO ERRORS */
				Error_State = 	Rcc_enuTimeOutError;
				break;
			}
		}
		/* Switch System Clock ti HSI */
		Peripheral_BitBand(RCC -> RCC_CFGR,0)=0;
		Peripheral_BitBand(RCC -> RCC_CFGR,1)=1;

		/* Wait The SWS In Mode HSI ClK */
		while(RCCSWS_STATE != RCC_CLK_HSI)
		{
			Local_u8Counter++;
			if (Local_u8Counter == TimeOut)
			{
				Error_State = Rcc_enuTimeOutError;
				break;
			}
		}break;
		/*************************************************************************/
		/* Case of The Clock Is HSE */
	case RCC_CLK_HSE:
		/* Set Bit 0 OF CLK_HSE */
		SET_BIT(RCC -> RCC_CR,16);
		/* wating HSI  To Be Ready */
		while (GET_BIT(RCC -> RCC_CR,17)== 0){
			/* Increament The Counter */
			Local_u8Counter ++;
			/* Check Counter To Equal TimeOut */
			if (Local_u8Counter == TimeOut)
			{
				Error_State = 	Rcc_enuTimeOutError;
				break;
			}
		}
		/* Switch System Clock ti HSE */
		Peripheral_BitBand(RCC -> RCC_CFGR,0)=1;
		Peripheral_BitBand(RCC -> RCC_CFGR,1)=0;
		/* Wait The SWS In Mode HSI ClK */
		while(RCCSWS_STATE != RCC_CLK_HSE)
		{
			Local_u8Counter++;
			if (Local_u8Counter == TimeOut)
			{
				Error_State = Rcc_enuTimeOutError;
				break;
			}
		}break;
		/********************************************************************/
	case RCC_CLK_PLL:
		SET_BIT(RCC -> RCC_CR,26);
		while (GET_BIT(RCC -> RCC_CR,27)== 1){
			/* Increament The Counter */
			Local_u8Counter ++;
			/* Check Counter To Equal TimeOut */
			if (Local_u8Counter == TimeOut)
			{
				Error_State = 	Rcc_enuTimeOutError;
				break;
			}
		}
		/* Switch System Clock ti PLL */
		Peripheral_BitBand(RCC -> RCC_CFGR,0)=0;
		Peripheral_BitBand(RCC -> RCC_CFGR,1)=1;
		/* Wait The SWS In Mode HSI ClK */
		while(RCCSWS_STATE != RCC_CLK_PLL)
		{
			Local_u8Counter++;
			if (Local_u8Counter == TimeOut)
			{
				Error_State = Rcc_enuTimeOutError;
				break;
			}
		}break;
		/****************************************************************************/
	}
	return Error_State;
}
Rcc_tenuErrorStatus Rcc_enuControlCLk(u8 Copy_u8ControlHSI  ,u8 Copy_u8ControlHSE ,u8 Copy_u8ControlPLL)
{
	Rcc_tenuErrorStatus Error_State = Rcc_enuOk;

	switch (Copy_u8ControlHSI){

	case RCC_CNTROL_HSION:
		/* Check On HSI Is On */
		if (GET_BIT(RCC -> RCC_CR,0)==1)
		{
			Error_State = RCC_enuUNLogicActionError;
		}
		else {
			/* Set HSION bit*/
			SET_BIT(RCC -> RCC_CR,0);
		}

		break;
	case RCC_CNTROL_HSIOFF:

		if (RCCSWS_STATE == RCC_CLK_HSI)
		{

			Error_State = RCC_enuUNLogicActionError;

		}
		/* check IS HSI Is Selected As PLL */
		else if (GET_BIT(RCC -> RCC_PLLCFGR,22)==0)
		{

			Error_State = RCC_enuUNLogicActionError;

		}
		else
		{

			CLR_BIT(RCC -> RCC_CR,0);
		}break;

	}
	/***********************************************************************************************/
	switch (Copy_u8ControlHSE)
	{

	case RCC_CNTROL_HSEON:
		/* Check On HSE Is On */
		if (GET_BIT(RCC -> RCC_CR,16)==1)
		{
			Error_State = RCC_enuUNLogicActionError;
		}
		else {
			/* Set HSEON bit*/
			SET_BIT(RCC -> RCC_CR,16);
		}

		break;
	case RCC_CNTROL_HSEOFF:
		/* Check Of State Is Equal HSE */
		if (RCCSWS_STATE == RCC_CLK_HSE)
		{

			Error_State = RCC_enuUNLogicActionError;

		}
		/* check IS HSE Is Selected As PLL */
		else if (GET_BIT(RCC -> RCC_PLLCFGR,22)==1)
		{

			Error_State = RCC_enuUNLogicActionError;

		}
		else
		{

			CLR_BIT(RCC -> RCC_CR,0);
		}break;

	}
	/***********************************************************************************************/
	switch (Copy_u8ControlPLL)
	{

	case RCC_CNTROL_PLLON:

		if (GET_BIT(RCC -> RCC_CR,24)==1)
		{

			Error_State = RCC_enuUNLogicActionError;
		}

		else
		{
			SET_BIT(RCC -> RCC_CR,24);
		}
		break;
		/***********************************************************************************************/
	case RCC_CNTROL_PLLOFF:

		if (RCCSWS_STATE == RCC_CLK_PLL)
		{

			Error_State = RCC_enuUNLogicActionError;

		}
		else
		{

			CLR_BIT(RCC -> RCC_CR,24);
		}

		break;

	}

	return Error_State;
}



Rcc_tenuErrorStatus Rcc_enuCheckCLk(u8 Copy_u8CLk, pu8 Add_pu8RdyStatus) {
	Rcc_tenuErrorStatus ERROR_State = Rcc_enuOk;
	if (Add_pu8RdyStatus == NULL){
		ERROR_State = RCC_enuNullPointerError;
	}
	else
	{
		switch(Copy_u8CLk){
		case RCC_CLK_HSI:
			if (GET_BIT(RCC->RCC_CR,1))
			{
				*Add_pu8RdyStatus = RCC_STATE_READY;
			}
			else
			{
				*Add_pu8RdyStatus = RCC_STATE_NOTREADY;
			}break;
		case RCC_CLK_HSE:
			if (GET_BIT(RCC->RCC_CR,17))
			{
				*Add_pu8RdyStatus = RCC_STATE_READY;
			}
			else
			{
				*Add_pu8RdyStatus = RCC_STATE_NOTREADY;
			}break;
		case RCC_CLK_PLL:
			if (GET_BIT(RCC->RCC_CR,25))
			{
				*Add_pu8RdyStatus = RCC_STATE_READY;
			}
			else
			{
				*Add_pu8RdyStatus = RCC_STATE_NOTREADY;
			}break;
		}
	}
	return ERROR_State;
}

Rcc_tenuErrorStatus Rcc_enuCnfgrPll(u8 COPY_u8M , u16 Copy_u16N , u8 Copy_u8P , u8 Copy_u8SrcPll , u8 Copy_u8Q)
{
	Rcc_tenuErrorStatus ERROR_State = Rcc_enuOk;
	if (GET_BIT(RCC -> RCC_CR,24)==1){
		ERROR_State = RCC_enuPll_IS_On_Error;
	}
	else if (COPY_u8M > 63)
	{

		ERROR_State = RCC_enuInvalid_M_Error;

	}
	/***********************************************************************************************/
	else if (Copy_u16N > 432)
	{

		ERROR_State = RCC_enuInvalid_N_Error;

	}
	/***********************************************************************************************/
	else if (Copy_u8P > RCC_PLLP_DIVBY_8)
	{

		ERROR_State = RCC_enuInvalid_P_Error;

	}
	/***********************************************************************************************/
	else if (Copy_u8SrcPll > RCC_PLLSRC_HSE)
	{

		ERROR_State = RCC_enuInvalid_ScrPll_Error;
	}

	else if (Copy_u8Q > RCC_Q_DIVBY_15)
	{

		ERROR_State = RCC_enuInvalid_Q_Error;

	}
	\
	else
	{

		RCC->RCC_PLLCFGR = ((COPY_u8M)) | ((Copy_u16N) << 6) | ((Copy_u8P) << 16) |((Copy_u8SrcPll) << 22)|((Copy_u8Q) << 24);

	}

	return ERROR_State;
}


Rcc_tenuErrorStatus Rcc_enuEnablePeriphral(u8 Copy_u8PeriphralBus , u32 Copy_u32Periphral)
{
	Rcc_tenuErrorStatus ERROR_State = Rcc_enuOk;

	switch(Copy_u8PeriphralBus)
	{
	case RCC_REGISTER_AHB1 : SET_BIT(RCC ->RCC_AHB1ENR, Copy_u32Periphral);	break;
	case RCC_REGISTER_AHB2 : SET_BIT(RCC ->RCC_AHB1ENR, Copy_u32Periphral);	break;
	case RCC_REGISTER_APB1 : SET_BIT(RCC ->RCC_AHB1ENR, Copy_u32Periphral);	break;
	case RCC_REGISTER_APB2 : SET_BIT(RCC ->RCC_AHB1ENR, Copy_u32Periphral);	break;
	default		   : /*Do Nothing*/							break;
	}
	return ERROR_State;
}



Rcc_tenuErrorStatus Rcc_enuDisablePeriphral(u8 Copy_u8PeriphralBus , u32 Copy_u32Periphral)
{
	Rcc_tenuErrorStatus ERROR_State = Rcc_enuOk;

	switch(Copy_u8PeriphralBus)
	{
	case RCC_REGISTER_AHB1 : CLR_BIT(RCC ->RCC_AHB1ENR, Copy_u32Periphral);	break;
	case RCC_REGISTER_AHB2 : CLR_BIT(RCC ->RCC_AHB1ENR, Copy_u32Periphral);	break;
	case RCC_REGISTER_APB1 : CLR_BIT(RCC ->RCC_AHB1ENR, Copy_u32Periphral);	break;
	case RCC_REGISTER_APB2 : CLR_BIT(RCC ->RCC_AHB1ENR, Copy_u32Periphral);	break;
	default		   : /*Do Nothing*/							break;
	}
	return ERROR_State;
}

Rcc_tenuErrorStatus Rcc_enuCfgBusPrescalers(u32 Copy_u32Prescaler){
	Rcc_tenuErrorStatus ERROR_State = Rcc_enuOk;
	switch (Copy_u32Prescaler)
	{
	case RCC_APB2_NOTDIV:
		RCC->RCC_CFGR &= RCC_APB2_NOTDIV;
		break;

	case RCC_APB2_DIV2:
		RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_APB2_NOTDIV) | Copy_u32Prescaler;
		break;

	case RCC_APB2_DIV4:
		RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_APB2_NOTDIV) | Copy_u32Prescaler;
		break;

	case RCC_APB2_DIV8:
		RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_APB2_NOTDIV) | Copy_u32Prescaler;
		break;

	case RCC_APB2_DIV16:
		RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_APB2_NOTDIV) | Copy_u32Prescaler;
		break;


	case RCC_APB1_NOTDIV:
		RCC->RCC_CFGR &= RCC_APB1_NOTDIV;
		break;

	case RCC_APB1_DIV2:
		RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_APB1_NOTDIV) | Copy_u32Prescaler;
		break;

	case RCC_APB1_DIV4:
		RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_APB1_NOTDIV) | Copy_u32Prescaler;
		break;

	case RCC_APB1_DIV8:
		RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_APB1_NOTDIV) | Copy_u32Prescaler;
		break;

	case RCC_APB1_DIV16:
		RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_APB1_NOTDIV) | Copy_u32Prescaler;
		break;

	case RCC_AHB_NOTDIV:
		RCC->RCC_CFGR &= RCC_AHB_NOTDIV;
		break;

	case RCC_AHB_DIV2:
		RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_AHB_NOTDIV) | Copy_u32Prescaler;
		break;

	case RCC_AHB_DIV4:
		RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_AHB_NOTDIV) | Copy_u32Prescaler;
		break;

	case RCC_AHB_DIV8:
		RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_AHB_NOTDIV) | Copy_u32Prescaler;
		break;

	case RCC_AHB_DIV16:
		RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_AHB_NOTDIV) | Copy_u32Prescaler;
		break;

	case RCC_AHB_DIV64:
		RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_AHB_NOTDIV) | Copy_u32Prescaler;
		break;

	case RCC_AHB_DIV128:
		RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_AHB_NOTDIV) | Copy_u32Prescaler;
		break;

	case RCC_AHB_DIV256:
		RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_AHB_NOTDIV) | Copy_u32Prescaler;
		break;

	case RCC_AHB_DIV512:
		RCC->RCC_CFGR = (RCC->RCC_CFGR & RCC_AHB_NOTDIV) | Copy_u32Prescaler;
		break;

		/****************************************************************************************/

	default:
		ERROR_State = Rcc_enuWrongBusPrescalerError;
		break;

	}

	return ERROR_State;

}




