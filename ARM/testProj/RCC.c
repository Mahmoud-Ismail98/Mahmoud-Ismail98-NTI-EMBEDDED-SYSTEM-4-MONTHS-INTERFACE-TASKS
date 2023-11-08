
#include "std_types.h"
#include "helpers.h"
#include "RCC_pv.h"
#include "rcc.h"


Rcc_tenuErrorStatus Rcc_enuSelectSysCLk(u8 Copy_u8SysClk , u8 Copy_u8OldSysClk) 
{
	// loc return status
	Rcc_tenuErrorStatus loc_enu_returnValue   = Rcc_enuOk;
	
	// case HSI
	if ( Copy_u8SysClk == RCC_CLK_HSI )
	{
		if ( BIT_BAND(&RCC_CR,HSIRDY) == TRUE)
		{
		  BIT_BAND(&RCC_CFGR,SW0) = FALSE;
		  BIT_BAND(&RCC_CFGR,SW1) = FALSE;
		}
		else
		{
			loc_enu_returnValue = RCC_enuUnLogicActionError;
		}
	}
	
	// case HSE
	else if ( Copy_u8SysClk == RCC_CLK_HSE )
	{
		if ( BIT_BAND(&RCC_CR,HSERDY) == TRUE)
		{
			BIT_BAND(&RCC_CFGR,SW0) = TRUE;
		  BIT_BAND(&RCC_CFGR,SW1) = FALSE;
		}
		else
		{
			loc_enu_returnValue = RCC_enuUnLogicActionError;
		}
		
	}
	//case PLL
	else if ( Copy_u8SysClk == RCC_CLK_PLL )
	{
		if ( BIT_BAND(&RCC_CR,PLLRDY) == TRUE)
		{
			BIT_BAND(&RCC_CFGR,SW0) = FALSE;
		  BIT_BAND(&RCC_CFGR,SW1) = TRUE;
		}
		else
		{
			loc_enu_returnValue = RCC_enuUnLogicActionError;
		}
		
	}
	else
	{
		loc_enu_returnValue = Rcc_enuClockSelectError;
	}
	
	// case error in clock select
	if ( loc_enu_returnValue != Rcc_enuOk )
	{
		// do nothing
	}
	// clock selected
	else
	{
		// disable old clk
		 // case HSI
		 if ( Copy_u8OldSysClk == RCC_CLK_HSI )
		 {
			 BIT_BAND(&RCC_CR,HSION) = FALSE;
		 }
		 
		 // case HSE
		 else if ( Copy_u8OldSysClk == RCC_CLK_HSE )
		 {
			 BIT_BAND(&RCC_CR,HSEON) = FALSE;
		 }
		 //case PLL
		 else if ( Copy_u8OldSysClk == RCC_CLK_PLL )
		 {
			 BIT_BAND(&RCC_CR,PLLON) = FALSE;
		 }
		 else
		 {
			 loc_enu_returnValue = Rcc_enuClockSelectError;
		 }
	}
	
	
	
	return loc_enu_returnValue;
	
	
}

Rcc_tenuErrorStatus Rcc_enuControlCLk(u8 Copy_u8ControlHSI  ,u8 Copy_u8ControlHSE ,u8 Copy_u8ControlPLL)
{
	u32 loc_HSI_TimeOut = FALSE;
	u32 loc_HSE_TimeOut = FALSE;
	u32 loc_PLL_TimeOut = FALSE;
	// loc return status
	Rcc_tenuErrorStatus loc_enu_returnValue   = Rcc_enuOk;
	// check on HSI
	switch ( Copy_u8ControlHSI )
	{
		case RCC_CNTROL_HSION  : BIT_BAND(&RCC_CR,HSION) = TRUE ;
		while( BIT_BAND(&RCC_CR,HSIRDY) == FALSE)
		{
		  loc_HSI_TimeOut++;
      if ( loc_HSI_TimeOut == 1000000)
			{
				break;
			}				
		}
		if (loc_HSI_TimeOut == 1000000)
		{
			loc_enu_returnValue = Rcc_enuTimeOutError;
		}
		break;
		case RCC_CNTROL_HSIOFF : 
		if (BIT_BAND(&RCC_CFGR,SWS2) == FALSE && BIT_BAND(&RCC_CFGR,SWS3) == FALSE)
		{
			loc_enu_returnValue = RCC_enuUnLogicActionError;
		}
		else if (BIT_BAND(&RCC_PLLCFGR,PLLSRC)== FALSE)
		{
			loc_enu_returnValue = RCC_enuUnLogicActionError;
		}
		else 
		{
			BIT_BAND(&RCC_CR,HSION) = FALSE;
		}
		break;
		default : loc_enu_returnValue = Rcc_enuClockSelectError;
	}
	// check if HSI CONTROL ERROR
	if ( loc_enu_returnValue != Rcc_enuOk )
	{
		// do nothing
	}
	else
	{ 
		// check on HSE
		switch ( Copy_u8ControlHSE )
		{
			case RCC_CNTROL_HSEON  :
				BIT_BAND(&RCC_CR,HSEON) = TRUE ;
			  while( BIT_BAND(&RCC_CR,HSERDY) == FALSE)
		    {
		       loc_HSE_TimeOut++;
           if ( loc_HSE_TimeOut == 1000000)
			     {
			     	break;
			     }				
		    }
		    if (loc_HSE_TimeOut == 1000000)
		    {
		    	loc_enu_returnValue = Rcc_enuTimeOutError;
		    }
			  break;
			case RCC_CNTROL_HSEOFF :
				if (BIT_BAND(&RCC_CFGR,SWS2) == TRUE && BIT_BAND(&RCC_CFGR,SWS3) == FALSE)
				{
					loc_enu_returnValue = RCC_enuUnLogicActionError;
				}
				else if (BIT_BAND(&RCC_PLLCFGR,PLLSRC)== TRUE)
				{
					loc_enu_returnValue = RCC_enuUnLogicActionError;
				}
				else
				{
					BIT_BAND(&RCC_CR,HSEON) = FALSE;
				}
				break;
			default : loc_enu_returnValue = Rcc_enuClockSelectError;
		}
	}
	// check if HSE CONTROL ERROR
	if ( loc_enu_returnValue != Rcc_enuOk )
	{
		// do nothing
	}
	else
	{
		// check on PLL
		switch ( Copy_u8ControlPLL )
		{
			case RCC_CNTROL_PLLON  : BIT_BAND(&RCC_CR,PLLON) = TRUE ;
			while( BIT_BAND(&RCC_CR,PLLRDY) == FALSE)
		  {
		     loc_PLL_TimeOut++;
         if ( loc_PLL_TimeOut == 1000000)
			   {
			   	break;
			   }				
		  }
		  if (loc_PLL_TimeOut == 1000000)
		  {
		  	loc_enu_returnValue = Rcc_enuTimeOutError;
		  }
			break;
			case RCC_CNTROL_PLLOFF : 
				if (BIT_BAND(&RCC_CFGR,SWS2) == FALSE && BIT_BAND(&RCC_CFGR,SWS3) == TRUE)
				{
					loc_enu_returnValue = RCC_enuUnLogicActionError;
				}
				else
				{
					BIT_BAND(&RCC_CR,PLLON) = FALSE;
				}
				break;
			default : loc_enu_returnValue = Rcc_enuClockSelectError;
		}
	}
  
	return loc_enu_returnValue;
}

Rcc_tenuErrorStatus Rcc_enuCheckCLk(u8 Copy_u8CLk, pu8 Add_pu8RdyStatus)
{
	// loc return status
	Rcc_tenuErrorStatus loc_enu_returnValue   = Rcc_enuOk;
	if ( Add_pu8RdyStatus != PTR_NULL)
	{
			// case HSI
			if ( Copy_u8CLk == RCC_CLK_HSI )
			{
				*Add_pu8RdyStatus = BIT_BAND(&RCC_CR,HSIRDY);
			}
			
			// case HSE
			else if ( Copy_u8CLk == RCC_CLK_HSE )
			{
				*Add_pu8RdyStatus = BIT_BAND(&RCC_CR,HSERDY);
			}
			//case PLL
			else if ( Copy_u8CLk == RCC_CLK_PLL )
			{
				*Add_pu8RdyStatus = BIT_BAND(&RCC_CR,PLLRDY);
			}
			else
			{
				loc_enu_returnValue = Rcc_enuClockSelectError;
			}
	}
	else
	{
		loc_enu_returnValue = RCC_enuNullPointerError;
	}
	return loc_enu_returnValue;
}

Rcc_tenuErrorStatus Rcc_enuCnfgrPll(u8 COPY_u8M , u16 Copy_u16N , u8 Copy_u8P , u8 Copy_u8SrcPll , u8 Copy_u8Q)
{
	Rcc_tenuErrorStatus loc_enu_returnValue   = Rcc_enuOk;
	
	// case correct M divisor
	if ( ( COPY_u8M <= PLL_M_HIGHEST_BOUND ) && ( COPY_u8M >= PLL_M_LOWEST_BOUND ))
	{
		RCC_PLLCFGR &= PLL_M_MASK;
		RCC_PLLCFGR |= COPY_u8M;
		
		// case correct N Multiplication
		if ( ( Copy_u16N <= PLL_N_HIGHEST_BOUND ) && ( Copy_u16N >= PLL_N_LOWEST_BOUND ))
		{
			RCC_PLLCFGR &= PLL_N_MASK;
			RCC_PLLCFGR |= (Copy_u16N<<6);
			
			// check on PLL P
			if ( Copy_u8P == RCC_PLLP_DIVBY_2)
			{
				BIT_BAND(&RCC_PLLCFGR,PLLP0) = FALSE;
				BIT_BAND(&RCC_PLLCFGR,PLLP1) = FALSE;
			}
			else if ( Copy_u8P == RCC_PLLP_DIVBY_4)
			{
				BIT_BAND(&RCC_PLLCFGR,PLLP0) = TRUE;
				BIT_BAND(&RCC_PLLCFGR,PLLP1) = FALSE;
			}
			else if ( Copy_u8P == RCC_PLLP_DIVBY_6)
			{
				BIT_BAND(&RCC_PLLCFGR,PLLP0) = FALSE;
				BIT_BAND(&RCC_PLLCFGR,PLLP1) = TRUE;
			}
			else if ( Copy_u8P == RCC_PLLP_DIVBY_8)
			{
				BIT_BAND(&RCC_PLLCFGR,PLLP0) = TRUE;
				BIT_BAND(&RCC_PLLCFGR,PLLP1) = TRUE;
			}
			else
			{
					// case invalid P Divisor
			    loc_enu_returnValue = RCC_enuInvalid_P_Error;
			}
			
			// check if invalid P Divisor
			if ( loc_enu_returnValue != Rcc_enuOk)
			{
				// do nothing
			}
			else
			{
				// check on CLKSRC FOR PLL
				if (Copy_u8SrcPll == RCC_PLLSRC_HSI)
				{
					BIT_BAND(&RCC_PLLCFGR,PLLSRC) = FALSE;
				}
				else if (Copy_u8SrcPll == RCC_PLLSRC_HSE)
				{
					BIT_BAND(&RCC_PLLCFGR,PLLSRC) = TRUE;
				}
				else
				{
					// clksrc error
					loc_enu_returnValue = RCC_enuInvalid_ScrPll_Error;
				}
				
			}
			
		}
		else
		{
			// case invalid N Multiplication
			loc_enu_returnValue = RCC_enuInvalid_N_Error;
		}
	}
	else
	{
		// case invalid M divisor
		loc_enu_returnValue = RCC_enuInvalid_M_Error;
	}
	
	// check on previous config
	if ( loc_enu_returnValue == Rcc_enuOk)
	{
		if ( Copy_u8Q <= RCC_Q_DIVBY_15 && Copy_u8Q >= RCC_Q_DIVBY_2)
		{
			RCC_PLLCFGR &= PLL_Q_MASK;
			RCC_PLLCFGR |= (((u32)Copy_u8Q)<<24);
		}
		else
		{
			loc_enu_returnValue = RCC_enuInvalid_Q_Error;
		}
	}
	else
	{
		// do nothing
	}
	return loc_enu_returnValue;
}

Rcc_tenuErrorStatus Rcc_enuEnablePeriphral(u8 Copy_u8PeriphralBus , u32 Copy_u32Periphral)
{
	Rcc_tenuErrorStatus loc_enu_returnValue   = Rcc_enuOk;
	switch(Copy_u8PeriphralBus)
	{
		case RCC_REGISTER_AHB1:
		{
			RCC_AHB1ENR |= Copy_u32Periphral;
			break;
		}
		case RCC_REGISTER_AHB2:
		{
			RCC_AHB2ENR |= Copy_u32Periphral;
			break;
		}
		case RCC_REGISTER_APB1:
		{
			RCC_APB1ENR |= Copy_u32Periphral;
			break;
		}
		case RCC_REGISTER_APB2:
		{
			RCC_APB2ENR |= Copy_u32Periphral;
			break;
		}
		default : loc_enu_returnValue = Rcc_enuWrongPeriphralBusError;
			
	}
	return loc_enu_returnValue;
}

Rcc_tenuErrorStatus Rcc_enuDisablePeriphral(u8 Copy_u8PeriphralBus , u32 Copy_u32Periphral)
{
		Rcc_tenuErrorStatus loc_enu_returnValue   = Rcc_enuOk;
	switch(Copy_u8PeriphralBus)
	{
		case RCC_REGISTER_AHB1:
		{
			RCC_AHB1RSTR |= Copy_u32Periphral;
			break;
		}
		case RCC_REGISTER_AHB2:
		{
			RCC_AHB2RSTR |= Copy_u32Periphral;
			break;
		}
		case RCC_REGISTER_APB1:
		{
			RCC_APB1RSTR |= Copy_u32Periphral;
			break;
		}
		case RCC_REGISTER_APB2:
		{
			RCC_APB2RSTR |= Copy_u32Periphral;
			break;
		}
		default : loc_enu_returnValue = Rcc_enuWrongPeriphralBusError;
			
	}
	return loc_enu_returnValue;
}

Rcc_tenuErrorStatus Rcc_enuCfgBusPrescalers(u32 Copy_u32Prescaler)
{
	RCC_CFGR |= Copy_u32Prescaler;
}