/**************************************************************************/
/* Filename						: RCC_private.h                            */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 8, 2023  	           	 	         	 */ 
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/* Trainee At					: NTI (4 Months)						  */
/* Instructor					: Mahmoud Embabi						  */
/**************************************************************************/


#ifndef RCC_RCC_PRIVATE_H_
#define RCC_RCC_PRIVATE_H_



/********************************** Includes *********************************************/



/********************************** Macros Declarations *******************************/


/********************************** Data Type Declarations ****************************/
typedef volatile struct{
	u32 RCC_CR;
	u32 RCC_PLLCFGR;
	u32 RCC_CFGR;
	u32 RCC_CIR;
	u32 RCC_AHB1RSTR;
	u32 RCC_AHB2RSTR;
	u32 RCC_AHB3RSTR;
	u32 Reserved1;
	u32 RCC_APB1RSTR;
	u32 RCC_APB2RSTR;
	u32 Reserved2[2];
	u32 RCC_AHB1ENR;
	u32 RCC_AHB2ENR;
	u32 RCC_AHB3ENR;
	u32 Reserved3;
	u32 RCC_APB1ENR;
	u32 RCC_APB2ENR;
	u32 Reserved4[2];
	u32 RCC_AHB1LPENR;
	u32 RCC_AHB2LPENR;
	u32 RCC_AHB3LPENR;
	u32 Reserved5;
	u32 RCC_APB1LPENR;
	u32 RCC_APB2LPENR;
	u32 Reserved6[2];
	u32 RCC_BDCR;
	u32 RCC_CSR;
	u32 Reserved7[2];
	u32 RCC_SSCGR;
	u32 RCC_PLLI2SCFGR;
	u32 RCC_PLLSAICFGR;
	u32 RCC_DCKCFGR;


}RCC_Type;

#define RCC 	((volatile RCC_Type*)(0x40023800))

static volatile u32* Global_PeripheralClkRegEnArr[]={&(RCC->RCC_AHB1ENR),&(RCC->RCC_AHB2ENR),&(RCC->RCC_AHB3ENR),&(RCC->RCC_APB1ENR),&(RCC->RCC_APB2ENR)};
static volatile u32* Global_PeripheralResetRegArr[]={&(RCC->RCC_AHB1RSTR),&(RCC->RCC_AHB2RSTR),&(RCC->RCC_AHB3RSTR),&(RCC->RCC_APB1RSTR),&(RCC->RCC_APB2RSTR)};
static volatile u32* Global_PeripheralLowPowerClkRegEnArr[]={&(RCC->RCC_AHB1LPENR),&(RCC->RCC_AHB2LPENR),&(RCC->RCC_AHB3LPENR),&(RCC->RCC_APB1LPENR),&(RCC->RCC_APB2LPENR)};


/********************************** Macros Function Declarations *********************/


#define RCC_enableHSI()				    	(SET_BIT((RCC->RCC_CR),ZERO_VALUE))
#define RCC_disableHSI()				    (CLEAR_BIT((RCC->RCC_CR),ZERO_VALUE))
#define RCC_IsHSIReady()				    ((READ_BIT((RCC->RCC_CR),ONE_VALUE) == ONE_VALUE))


#define RCC_enableHSE()				            	(SET_BIT((RCC->RCC_CR),SIXTEEN_VALUE))
#define RCC_disableHSE()		    	        	(CLEAR_BIT((RCC->RCC_CR),SIXTEEN_VALUE))
#define RCC_IsHSEReady()			            	((READ_BIT((RCC->RCC_CR),SEVENTEEN_VALUE) == ONE_VALUE))

#define RCC_enableBypassClock_UsedRCexternal()                 (SET_BIT((RCC->RCC_CR),EIGHTEEN_VALUE))
#define RCC_disableBypassClock_UsedCrystalexternal()           (CLEAR_BIT((RCC->RCC_CR),EIGHTEEN_VALUE))


#define RCC_enableClockSecuritySystem()					    	(SET_BIT((RCC->RCC_CR),NINETEEN_VALUE))
#define RCC_disableClockSecuritySystem()						(CLEAR_BIT((RCC->RCC_CR),NINETEEN_VALUE))

#define RCC_setHSITrim(_VALUE_)									((RCC->RCC_CR) = (((RCC->RCC_CR) &0xFFFFFF07) | (_VALUE_)<<THREE_VALUE ))


#define RCC_enablePLL()				            	    (SET_BIT((RCC->RCC_CR),TWENTYFOUR_VALUE))
#define RCC_disablePLL()		    	        	    (CLEAR_BIT((RCC->RCC_CR),TWENTYFOUR_VALUE))
#define RCC_IsPLLReady()			            	    ((READ_BIT((RCC->RCC_CR),TWENTYFIVE_VALUE) == ONE_VALUE))

#define RCC_enablePLLI2S()				            	(SET_BIT((RCC->RCC_CR),TWENTYSIX_VALUE))
#define RCC_disablePLLI2S()		    	        	(CLEAR_BIT((RCC->RCC_CR),TWENTYSIX_VALUE))
#define RCC_IsPLLReadyI2S()			            	(READ_BIT((RCC->RCC_CR),TWENTYSEVEN_VALUE) == ONE_VALUE)


#define RCC_enablePLLSAI()				            	(SET_BIT((RCC->RCC_CR),TWENTYEIGHT_VALUE))
#define RCC_disablePLLSAI()		    	        	(CLEAR_BIT((RCC->RCC_CR),TWENTYEIGHT_VALUE))
#define RCC_IsPLLReadySAI()			            	(READ_BIT((RCC->RCC_CR),TWENTYNINE_VALUE) == ONE_VALUE)



/* PLL Part */

#define RCC_setPLL_M_Factor(_VALUE_)				(( RCC->RCC_PLLCFGR ) = ((( RCC->RCC_PLLCFGR ) &0xFFFFFFE0) | (( _VALUE_) & 0x1F )))
#define RCC_setPLL_N_Factor(_VALUE_)				(( RCC->RCC_PLLCFGR ) = ((( RCC->RCC_PLLCFGR ) &0xFFFFC01F) | (( ( _VALUE_) <<SIX_VALUE) & 0x00003FE0 )) )
#define RCC_setPLL_P_Factor(_VALUE_)				(( RCC->RCC_PLLCFGR ) = (( (RCC->RCC_PLLCFGR ) &0x30000) | (( (_VALUE_)<<SIXTEEN_VALUE) & 0xFFFCFFFF )))
#define RCC_setPLLClk(_ARGU_)				         (WRITE_BIT((RCC->RCC_PLLCFGR),TWENTYTWO_VALUE,(_ARGU_)))
#define RCC_setPLL_Q_Factor(_VALUE_)				((RCC->RCC_PLLCFGR) = (((RCC->RCC_PLLCFGR) &0xF0FFFFFF) | (((_VALUE_)<<TWENTYFOUR_VALUE) & 0xF000000 )))

/* MCO2 Part */
#define RCC_selectMoc2ClkSource(_VALUE_)			((RCC->RCC_CFGR) = (((RCC->RCC_CFGR) &0x3FFFFFFF) | (((_VALUE_)<<THIRTY_VALUE) & 0xC0000000 )))
#define RCC_selectMoc2Prescaler(_VALUE_)			((RCC->RCC_CFGR) = (((RCC->RCC_CFGR) &0xC7FFFFFF) | (((_VALUE_)<<TWENTYSEVEN_VALUE) & 0x38000000 )))

/* MCO1 Part */
#define RCC_selectMoc1ClkSource(_VALUE_)			((RCC->RCC_CFGR) = (((RCC->RCC_CFGR) &0xFF9FFFFF) | (((_VALUE_)<<TWENTYONE_VALUE) & 0x600000 )))
#define RCC_selectMoc1Prescaler(_VALUE_)			((RCC->RCC_CFGR) = (((RCC->RCC_CFGR) &0xFF8FFFFF) | (((_VALUE_)<<TWENTYFOUR_VALUE) & 0x700000 )))


/* Buses Prescaler Part */
#define RCC_selectAPB2Prescaler(_VALUE_)			((RCC->RCC_CFGR) = (((RCC->RCC_CFGR) &0xFFFF1FFF) | (((_VALUE_)<<THIRTEEN_VALUE) & 0xE000 )))
#define RCC_selectAPB1Prescaler(_VALUE_)			((RCC->RCC_CFGR) = (((RCC->RCC_CFGR) &0xFFFFE3FF) | (((_VALUE_)<<TEN_VALUE) & 0x1C00 )))
#define RCC_selectAHBPrescaler(_VALUE_)			     ((RCC->RCC_CFGR) = (((RCC->RCC_CFGR) &0xFFFFFF0F) | (((_VALUE_)<<THIRTEEN_VALUE) & 0xF0 )))

/* System clk part */
#define RCC_selectSystemClk(_VALUE_)			     ((RCC->RCC_CFGR) = (((RCC->RCC_CFGR) &0xFFFFFFFC) | (((_VALUE_)) & 0x03 )))
#define RCC_getSystemClk()							 (((RCC->RCC_CFGR) >> TWO_VALUE) & 0x03)



/* PLL I2S Part */

#define RCC_setPLL_I2S_N_Factor(_VALUE_)				(( RCC->RCC_PLLI2SCFGR ) = ((( RCC->RCC_PLLI2SCFGR ) &0xFFFF803F) | (( ( _VALUE_) <<SIX_VALUE) & 0x7FC0 )) )
#define RCC_setPLL_I2S_Q_Factor(_VALUE_)			 	(( RCC->RCC_PLLI2SCFGR ) = (( (RCC->RCC_PLLI2SCFGR ) &0xF0FFFFFF) | (( (_VALUE_)<<TWENTYFOUR_VALUE) & 0xF000000 )))

#define RCC_setPLL_I2S_R_Factor(_VALUE_)				(( RCC->RCC_CFGR ) = ((( RCC->RCC_CFGR ) &0xFFFF803F) | (( ( _VALUE_) <<TWENTYEIGHT_VALUE) & 0x7FC0 )) )
#define RCC_setPLL_I2S_Clk(_ARGU_)				         (WRITE_BIT((RCC->RCC_CFGR),TWENTYTHREE_VALUE,(_ARGU_)))

/* PLL I2S Part */
#define RCC_setPLL_SAI_N_Factor(_VALUE_)				(( RCC->RCC_PLLSAICFGR ) = ((( RCC->RCC_PLLSAICFGR ) &0xFFFF803F) | (( ( _VALUE_) <<SIX_VALUE) & 0x7FC0 )) )
#define RCC_setPLL_SAI_Q_Factor(_VALUE_)				(( RCC->RCC_PLLSAICFGR ) = (( (RCC->RCC_PLLSAICFGR ) &0xF0FFFFFF) | (( (_VALUE_)<<TWENTYFOUR_VALUE) & 0xF000000 )))

#define RCC_setPLL_SAI_R_Factor(_VALUE_)				(( RCC->RCC_PLLSAICFGR ) = ((( RCC->RCC_PLLSAICFGR ) &0xFFFF803F) | (( ( _VALUE_) <<TWENTYEIGHT_VALUE) & 0x7FC0 )) )

#define RCC_setPLL_SAI_QX_PLLI2SDIVQ_Factor(_VALUE_)	(( RCC->RCC_DCKCFGR ) = ((( RCC->RCC_DCKCFGR ) &0xFFFFFFE0) | (( ( _VALUE_) <<ZERO_VALUE) & 0x1F )) )
#define RCC_setPLL_SAI_QY_PLLSAIDIVQ_Factor(_VALUE_)	(( RCC->RCC_DCKCFGR ) = ((( RCC->RCC_DCKCFGR ) &0xFFFFE0FF) | (( ( _VALUE_) <<SIX_VALUE) & 0x1F00 )) )
#define RCC_setPLL_SAI_RLcd_PLLSAIDIVR_Factor(_VALUE_)	(( RCC->RCC_DCKCFGR ) = ((( RCC->RCC_DCKCFGR ) &0xFFFCFFFF) | (( ( _VALUE_) <<SIX_VALUE) & 0x30000 )) )

#define	RCC_setPLL_SAI1A_Clk(_VALUE_)					(( RCC->RCC_DCKCFGR ) = ((( RCC->RCC_DCKCFGR ) &0xFFCFFFFF) | (( ( _VALUE_) <<SIX_VALUE) & 0x300000 )) )
#define RCC_setPLL_SAI1B_Clk(_VALUE_)					(( RCC->RCC_DCKCFGR ) = ((( RCC->RCC_DCKCFGR ) &0xFF3FFFFF) | (( ( _VALUE_) <<SIX_VALUE) & 0xC00000 )) )


/********************************** Software Interfaces Declarations *******************/



#endif /* RCC_RCC_PRIVATE_H_ */
