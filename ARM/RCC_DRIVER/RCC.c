
#include "STD_TYPES.h"
#include "BIT_UTILS.h"
#include "RCC.h"
#include "RCC_prv.h"
#include "RCC_cfg.h"



Rcc_tenuErrorStatus Rcc_enuSelectSysCLk(u8 Copy_u8SysClk , u8 Copy_u8OldSysClk) {
  
    u8 Counter =0;
    switch(Copy_u8SysClk)
    {
        case RCC_CLK_HSE:
            SET_BIT(MRCC->CR,16U);
             while ((GET_BIT(MRCC->CR, 17U) == 0)||Counter!=20)
             {
                Counter++;
             }
             if(Counter==20)
             {
           
             }
             else
             {

             }
			/*Disable BYP*/
			CLR_BIT(MRCC->CR,18U);
			/* Input system Clk*/
			SET_BIT(MRCC->CFGR,0U);
			CLR_BIT(MRCC->CFGR,1U);
        break;
        case RCC_CLK_HSI:
            /*Enable HSI */
		    SET_BIT(MRCC->CR,0U);
            while ((GET_BIT(MRCC->CR, 1U) == 0)||Counter!=20)
             {
                Counter++;
             }
             if(Counter==20)
             {
              
             }
             else
             {

             }
		    /* Input system Clk*/
		    CLR_BIT(MRCC->CFGR,0U);
		    CLR_BIT(MRCC->CFGR,1U);

        break;
        case RCC_CLK_PLL:
            /*1-Enable HSE */

#if SOURCE_CLK_FOR_PLL == RCC_PLLSRC_HSE            
			SET_BIT(MRCC->CR,16U);
             while ((GET_BIT(MRCC->CR, 17U) == 0)||Counter!=20)
             {
                Counter3++;
             }
             if(Counter==20)
             {
               
             }
             else
             {

             }		
#elif SOURCE_CLK_FOR_PLL == RCC_PLLSRC_HSI
            SET_BIT(MRCC->CR,0U);
            while ((GET_BIT(MRCC->CR, 1U) == 0)||Counter!=20)
             {
                Counter++;
             }
             if(Counter==20)
             {
              
             }
             else
             {

             }
#endif 
			/*2- EN PLL*/
			SET_BIT(MRCC->CR,24U);
			/**/
             while ((GET_BIT(MRCC->CR, 25U) == 0)||Counter!=20)
             {
                Counter++;
             }
             if(Counter==20)
             {
               
             }
             else
             {

             }
			SET_BIT(MRCC->PLLCFGR, 22U);
			
			CLR_BIT(MRCC->CFGR,0U);
			SET_BIT(MRCC->CFGR,1U);
        break;
        default:
        break;

    }
}
Rcc_tenuErrorStatus Rcc_enuControlCLk(u8 Copy_u8ControlHSI, u8 Copy_u8ControlHSE, u8 Copy_u8ControlPLL) 
{
  

    if (Copy_u8ControlHSI == RCC_CNTROL_HSION)
    {
        SET_BIT(MRCC->CR, 0U); // Enable HSI
        u8 Counter =0;
         while ((GET_BIT(MRCC->CR, 1U) == 0)&&Counter<20)
         {
            Counter++;
         }
    }
    else if(Copy_u8ControlHSI == RCC_CNTROL_HSIOFF)
    {
        CLR_BIT(MRCC->CR, 0U); // Disable HSI
    }

    if (Copy_u8ControlHSE == RCC_CNTROL_HSEON)
    {
        SET_BIT(MRCC->CR, 16U); // Enable HSE
        u8 Counter =0;
         while ((GET_BIT(MRCC->CR, 17U) == 0)&&Counter<20)
         {
            Counter++;
         }
    }
    else if(Copy_u8ControlHSE == RCC_CNTROL_HSEOFF)
    {
        CLR_BIT(MRCC->CR, 16U); // Disable HSE
    }

    if (Copy_u8ControlPLL == RCC_CNTROL_PLLON)
    {
        SET_BIT(MRCC->CR, 24U); // Enable PLL
        u8 Counter =0;
         while ((GET_BIT(MRCC->CR, 25U) == 0)&&Counter<20)
         {
            Counter++;
         }
    }
    else if (Copy_u8ControlPLL == RCC_CNTROL_PLLOFF)
    {
        CLR_BIT(MRCC->CR, 24U); // Disable PLL
    }


}

Rcc_tenuErrorStatus Rcc_enuCheckCLk(u8 Copy_u8CLk, pu8 Add_pu8RdyStatus) 
{
    switch(Copy_u8CLk)
    {
        case RCC_CLK_HSI :
       
         *Add_pu8RdyStatus =GET_BIT(MRCC->CR, 0U) ;
        break;
        case RCC_CLK_HSE:
          *Add_pu8RdyStatus =GET_BIT(MRCC->CR, 16U) ;
        break;
        case RCC_CLK_PLL:
         *Add_pu8RdyStatus =GET_BIT(MRCC->CR, 24U) ;
        break;
        default:
        break;
    }
}

Rcc_tenuErrorStatus Rcc_enuCnfgrPll(u8 COPY_u8M , u16 Copy_u16N , u8 Copy_u8P , u8 Copy_u8SrcPll , u8 Copy_u8Q)
{
    switch(Copy_u8SrcPll)
    {
        case RCC_PLLSRC_HSI:
            CLR_BIT(MRCC-> PLLCFGR ,22);
            MRCC->PLLCFGR |= COPY_u8M<<0;
            MRCC->PLLCFGR |= Copy_u16N<<6;
            MRCC->PLLCFGR |= Copy_u8P<<16;
            MRCC->PLLCFGR |= Copy_u8Q<<24;

        break;

        case RCC_PLLSRC_HSE:
            SET_BIT(MRCC-> PLLCFGR ,22);
            MRCC->PLLCFGR |= COPY_u8M<<0;
            MRCC->PLLCFGR |= Copy_u16N<<6;
            MRCC->PLLCFGR |= Copy_u8P<<16;
            MRCC->PLLCFGR |= Copy_u8Q<<24;
        break;

        default:
        break;
    }
}

Rcc_tenuErrorStatus Rcc_enuEnablePeriphral(u8 Copy_u8PeriphralBus , u32 Copy_u32Periphral)
{
	

		switch (Copy_u8PeriphralBus)
		{
			case RCC_REGISTER_AHB1 :
            MRCC->AHB1ENR |= Copy_u32Periphral;
            break;
			case RCC_REGISTER_AHB2:
            MRCC->AHB2ENR |= Copy_u32Periphral;
            break;
			case RCC_REGISTER_APB1:
            MRCC->APB1ENR |= Copy_u32Periphral;
            break;
            case RCC_REGISTER_APB2 :
            MRCC->APB1ENR |= Copy_u32Periphral;
            break;
			default:
            break;
		}

	
}

Rcc_tenuErrorStatus Rcc_enuDisablePeriphral(u8 Copy_u8PeriphralBus , u32 Copy_u32Periphral){
		switch (Copy_u8PeriphralBus)
		{
			case RCC_REGISTER_AHB1 :
            MRCC->AHB1ENR &= ~Copy_u32Periphral;
            break;
			case RCC_REGISTER_AHB2:
            MRCC->AHB2ENR &= ~Copy_u32Periphral;
            break;
			case RCC_REGISTER_APB1:
            MRCC->APB1ENR &= ~Copy_u32Periphral;
            break;
            case RCC_REGISTER_APB2 :
            MRCC->APB2ENR &= ~Copy_u32Periphral;
            break;
			default:
            break;
		}
}

Rcc_tenuErrorStatus Rcc_enuCfgBusPrescalers(u32 Copy_u32Prescaler){
    MRCC->CFGR |= Copy_u32Prescaler;
}