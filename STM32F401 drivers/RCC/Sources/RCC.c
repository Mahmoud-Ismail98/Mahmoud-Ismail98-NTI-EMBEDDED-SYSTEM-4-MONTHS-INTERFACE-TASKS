#include "Std_types.h"
#include "Bit_utils.h"
#include "RCC.h"

typedef struct{
volatile u32 RCC_CR;
volatile u32 RCC_PLLCFGR;
volatile u32 RCC_CFGR;
volatile u32 RCC_CIR;
volatile u32 RCC_AHB1RSTR;
volatile u32 RCC_AHB2RSTR;
volatile u32 Reversed[2];
volatile u32 RCC_APB1RSTR;
volatile u32 RCC_APB2RSTR ;
volatile u32 Reversed1[2];
volatile u32 RCC_AHB1ENR;
volatile u32 RCC_AHB2ENR;
volatile u32 Reversed2[2];
volatile u32 RCC_APB1ENR;
volatile u32 RCC_APB2ENR;
volatile u32 RCC_AHB1LPENR;
volatile u32 RCC_APB2LPENR;
volatile u32 Reversed3[2];
volatile u32 RCC_BDCR;
volatile u32 RCC_CSR;
volatile u32 Reversed4[2];
volatile u32 RCC_SSCGR;
volatile u32 RCC_PLLI2SCFGR;
volatile u32 RCC_DCKCFGR ;
} RCC_t;

#define RCC ((RCC_t*)0x40023800)

Rcc_tenuErrorStatus Rcc_enuSelectSysCLk(u8 Copy_u8SysClk ){
	
		u16 CounterTimeout =0;
		Rcc_tenuErrorStatus ERORR_STATE = Rcc_enuOk;
		switch( Copy_u8SysClk ) {
			
			case  RCC_CLK_HSI :
				
				SET_BIT (RCC->RCC_CR,0);
				while ( CounterTimeout < 3000){
					if (GET_BIT(RCC->RCC_CR,1) !=0){
						RCC->RCC_CFGR |= RCC_CLK_HSE;	
						break;}
					else{ 
					CounterTimeout ++;}
				}
				if ( GET_BIT(RCC->RCC_CR,1) ==0) ERORR_STATE = Rcc_enuTimeOutError;
				else                             ERORR_STATE = Rcc_enuOk;
				break;
			
			case  RCC_CLK_HSE :
				
				SET_BIT (RCC->RCC_CR,16);
				while ( CounterTimeout < 3000){
					if (GET_BIT(RCC->RCC_CR,17) !=0){
						RCC->RCC_CFGR |= RCC_CLK_HSE;	
						break;}
					else{ 
					CounterTimeout ++;}
				}
				if ( GET_BIT(RCC->RCC_CR,17) ==0) ERORR_STATE = Rcc_enuTimeOutError;
				else                              ERORR_STATE = Rcc_enuOk;
				break;
			
			case RCC_CLK_PLL :
				
				SET_BIT (RCC->RCC_CR,24);
				while ( CounterTimeout < 3000){
					if (GET_BIT(RCC->RCC_CR,25) !=0){
						RCC->RCC_CFGR |= RCC_CLK_HSE;	
						break;}
					else{ 
					CounterTimeout ++;}
				}
				if ( GET_BIT(RCC->RCC_CR,25) ==0) ERORR_STATE = Rcc_enuTimeOutError;
				else                              ERORR_STATE = Rcc_enuOk;
				break; 
			default : break; }
		return ERORR_STATE;
		}



void Rcc_enuControlCLk(u8 Copy_u8ControlHSI  ,u8 Copy_u8ControlHSE ,u8 Copy_u8ControlPLL){
	
		if ( Copy_u8ControlHSI == RCC_CNTROL_HSIOFF )  CLR_BIT(RCC->RCC_CR,0);
		else                                           SET_BIT (RCC->RCC_CR,0);
	
		if ( Copy_u8ControlHSE == RCC_CNTROL_HSEOFF )  CLR_BIT(RCC->RCC_CR,16);
		else                                           SET_BIT (RCC->RCC_CR,16);
	
		if ( Copy_u8ControlPLL == RCC_CNTROL_PLLOFF )  CLR_BIT(RCC->RCC_CR,24);
		else                                           SET_BIT (RCC->RCC_CR,24);
}
	
	
Rcc_tenuErrorStatus Rcc_enuCheckCLk(u8 Copy_u8CLk, pu8 Add_pu8RdyStatus) {
		
	Rcc_tenuErrorStatus Error_STATE =Rcc_enuOk;
		if (  Add_pu8RdyStatus == NULL_POINTER ){
			Error_STATE = RCC_enuNullPointerError;}
		
		switch (Copy_u8CLk){
			
			case RCC_CLK_HSI :
				if ( GET_BIT(RCC->RCC_CR,1) == 0 )
					 *Add_pu8RdyStatus = RCC_STATE_NOTREADY;
				else 
					 *Add_pu8RdyStatus = RCC_STATE_NOTREADY;
				break;
				
			case RCC_CLK_HSE :
				if ( GET_BIT(RCC->RCC_CR,17) == 0 )
					 *Add_pu8RdyStatus = RCC_STATE_NOTREADY;
				else 
					 *Add_pu8RdyStatus = RCC_STATE_READY;
				break;
				
			case RCC_CLK_PLL :
				if ( GET_BIT(RCC->RCC_CR,25) == 0 )
					 *Add_pu8RdyStatus = RCC_STATE_NOTREADY;
				else 
					 *Add_pu8RdyStatus = RCC_STATE_READY;
				break;
			default : break;
				
			}
		return Error_STATE;
		}

		void Rcc_enuCnfgrPll( u8 Copy_u8P , u8 Copy_u8SrcPll , u8 Copy_u8Q){
			
			// disable both PLL and PLLI2S to configure PLL
			CLR_BIT (RCC->RCC_CR,24);
			CLR_BIT (RCC->RCC_CR,26);
				switch (Copy_u8P){
					case RCC_PLLP_DIVBY_2 :
						RCC->RCC_PLLCFGR |= 0x02;
						break;
					case RCC_PLLP_DIVBY_4 :
						RCC->RCC_PLLCFGR |= 0x04;
						break;
					case RCC_PLLP_DIVBY_6 :
						RCC->RCC_PLLCFGR |= 0x06;
						break;
					case RCC_PLLP_DIVBY_8 :
						RCC->RCC_PLLCFGR |= 0x08;
						break;
				default : break;
				}
				
				switch (Copy_u8SrcPll){
					case RCC_PLLSRC_HSI:
						SET_BIT(RCC->RCC_PLLCFGR,22);
						break;
					case RCC_PLLSRC_HSE:
						CLR_BIT(RCC->RCC_PLLCFGR,22);
						break;
					default:break;
				}
			
				switch(Copy_u8Q) {
					
					case RCC_Q_DIVBY_2 :
						RCC->RCC_PLLCFGR |= (2UL<<24);
						break;
					case RCC_Q_DIVBY_3 :
						RCC->RCC_PLLCFGR |= (3UL<<24);
						break;
					case RCC_Q_DIVBY_4 :
						RCC->RCC_PLLCFGR |= (4UL<<24);
						break;
					case RCC_Q_DIVBY_5 :
						RCC->RCC_PLLCFGR |= (5UL<<24);
						break;
					case RCC_Q_DIVBY_6 :
						RCC->RCC_PLLCFGR |= (6UL<<24);
						break;
					case RCC_Q_DIVBY_7 :
						RCC->RCC_PLLCFGR |= (7UL<<24);
						break;\
					case RCC_Q_DIVBY_8 :
						RCC->RCC_PLLCFGR |= (8UL<<24);
						break;
      	  case RCC_Q_DIVBY_9 :
						RCC->RCC_PLLCFGR |= (9UL<<24);
						break;	
					case RCC_Q_DIVBY_10 :
						RCC->RCC_PLLCFGR |= (10UL<<24);
						break;
				  case RCC_Q_DIVBY_11 :
						RCC->RCC_PLLCFGR |= (11UL<<24);
						break;
				  case RCC_Q_DIVBY_12 :
						RCC->RCC_PLLCFGR |= (12UL<<24);
						break;
					case RCC_Q_DIVBY_13 :
						RCC->RCC_PLLCFGR |= (13UL<<24);
						break;
					case RCC_Q_DIVBY_14 :
						RCC->RCC_PLLCFGR |= (14UL<<24);
						break;
					case  RCC_Q_DIVBY_15 :
						RCC->RCC_PLLCFGR |= (15UL<<24);
						break;
					default :break;
				}
				
			}
		
		void Rcc_enuEnablePeriphral(u8 Copy_u8PeriphralBus , u32 Copy_u32Periphral){
			
			switch (Copy_u8PeriphralBus)
		{
			case RCC_REGISTER_AHB1 :
            RCC->RCC_AHB1ENR |= Copy_u32Periphral;
            break;
			case RCC_REGISTER_AHB2:
            RCC->RCC_AHB2ENR |= Copy_u32Periphral;
            break;
			case RCC_REGISTER_APB1:
            RCC->RCC_APB1ENR |= Copy_u32Periphral;
            break;
            case RCC_REGISTER_APB2 :
            RCC->RCC_APB2ENR |= Copy_u32Periphral;
            break;
			default:
            break;
		}
	}
		
void Rcc_enuDisablePeriphral(u8 Copy_u8PeriphralBus , u32 Copy_u32Periphral){
			
			switch (Copy_u8PeriphralBus)
		{
			case RCC_REGISTER_AHB1 :
            RCC->RCC_AHB1ENR &= ~(Copy_u32Periphral);
            break;
			case RCC_REGISTER_AHB2:
            RCC->RCC_AHB2ENR &= ~(Copy_u32Periphral);
            break;
			case RCC_REGISTER_APB1:
            RCC->RCC_APB1ENR &= ~(Copy_u32Periphral);
            break;
            case RCC_REGISTER_APB2 :
            RCC->RCC_APB2ENR &= ~(Copy_u32Periphral);
            break;
			default:
            break;
		}
	}

void Rcc_enuCfgBusPrescalers(u32 Copy_u32Prescaler) {
		RCC->RCC_CFGR |=  Copy_u32Prescaler;
}
		
	