/*
 * RCC.c
 *
 *  Created on: Nov 5, 2023
 *      Author: Ismail
 */



#include "Std_types.h"
#include "Bit_utils.h"
#include "RCC.h"
#define RCC_REGISTER_BIT_0   0
#define RCC_REGISTER_BIT_1	1
#define RCC_REGISTER_BIT_2	2
#define RCC_REGISTER_BIT_3	3
#define RCC_REGISTER_BIT_4	4
#define RCC_REGISTER_BIT_5	5
#define RCC_REGISTER_BIT_6	6
#define RCC_REGISTER_BIT_7	7
#define RCC_REGISTER_BIT_8	8
#define RCC_REGISTER_BIT_9	9
#define RCC_REGISTER_BIT_10	10
#define RCC_REGISTER_BIT_11	11
#define RCC_REGISTER_BIT_12	12
#define RCC_REGISTER_BIT_13	13
#define RCC_REGISTER_BIT_14	14
#define RCC_REGISTER_BIT_15	15
#define RCC_REGISTER_BIT_16	16
#define RCC_REGISTER_BIT_17	17
#define RCC_REGISTER_BIT_18	18
#define RCC_REGISTER_BIT_19	19
#define RCC_REGISTER_BIT_20	20
#define RCC_REGISTER_BIT_21	21
#define RCC_REGISTER_BIT_22	22
#define RCC_REGISTER_BIT_23	23
#define RCC_REGISTER_BIT_24	24
#define RCC_REGISTER_BIT_25	25
#define RCC_REGISTER_BIT_26	26
#define RCC_REGISTER_BIT_27	27
#define RCC_REGISTER_BIT_28	28
#define RCC_REGISTER_BIT_29	29
#define RCC_REGISTER_BIT_30	30
#define RCC_REGISTER_BIT_31	31
#define RCC_REGISTER_BIT_32	32

/*BIT MASKING*/

#define RCC_MASK_SWS 		 0x00001100   //SYSTEM CLK SWITCH STATUS
#define RCC_MASK_SW   	     0x00000003

#define RCC_HSI_MASK	     0x00000000  // USED AT TURNING THE OLD CLK OFF BY SWITCHING
#define RCC_HSE_MASK	     0x00000004
#define RCC_PLL_MASK	     0x00000008

/*RCC_REGISTER MAPPING*/
typedef struct
{

	volatile u32 RCC_CR;
	volatile u32 RCC_PLLCFGR;
	volatile u32 RCC_CFGR;
	volatile u32 RCC_CIR;
	volatile u32 RCC_AHB1RSTR;
	volatile u32 RCC_AHB2RSTR;
	volatile u32 RCC_Reserved0[2];
	volatile u32 RCC_APB1RSTR;
	volatile u32 RCC_APB2RSTR;
	volatile u32 RCC_Reserved1[2];
	volatile u32 RCC_AHB1ENR;
	volatile u32 RCC_AHB2ENR;
	volatile u32 RCC_Reserved2[2];
	volatile u32 RCC_APB1ENR;
	volatile u32 RCC_APB2ENR;
	volatile u32 RCC_Reserved3[2];
	volatile u32 RCC_AHB1LPENR;
	volatile u32 RCC_AHB2LPENR;
	volatile u32 RCC_Reserved4[2];
	volatile u32 RCC_APB1LPENR;
	volatile u32 RCC_APB2LPENR;
	volatile u32 RCC_Reserved5[2];
	volatile u32 RCC_BDCR;
	volatile u32 RCC_CSR;
	volatile u32 RCC_Reserved6[2];
	volatile u32 RCC_SSCGR;
	volatile u32 RCC_PLLI2SCFGR;
	volatile u32 RCC_DCKCFGR;

} RCC_t;

#define PERIPHERAL_BITBAND(REGISTER,BIT)	(*((volatile u32*)(PERIPHERAL_ALIAS_BASE+(((((u32)&(REGISTER)))-PERIPHERALS_BASE)*(32))+(BIT*(4)))))
//#define PERIPHERAL_ALIAS_BASE
//#define PERIPHERALS_BASE

#define RCC   ((RCC_t*)(0x40023800))


/*MACROS*/

#define BREAK_TIME    	    		999
#define MAX_M						63
#define MINIMUM_M					2
#define MAX_P						84
#define MINIMUM_N					192
#define MAX_N						432
#define MAX_Q                      	15
#define MINIMUM_Q                   2
//MACROS FOR THE PLL CONFIG FUNCTION
#define RCC_CONFIG_PLL_M			    ((COPY_u8M))
#define RCC_CONFIG_PLL_N				((Copy_u16N) << RCC_REGISTER_BIT_6)
#define RCC_CONFIG_PLL_P				((Copy_u8P) << RCC_REGISTER_BIT_16)
#define RCC_CONFIG_SRCPLL			((Copy_u8SrcPll) << RCC_REGISTER_BIT_22)
#define RCC_CONFIG_PLL_Q				((Copy_u8Q) << RCC_REGISTER_BIT_24)
//TO CONFIG THE PLL AT ONE LINE
#define RCC_CONFIG_PLL      RCC_CONFIG_PLL_M | RCC_CONFIG_PLL_N | RCC_CONFIG_PLL_P | RCC_CONFIG_SRCPLL | RCC_CONFIG_PLL_Q

Rcc_tenuErrorStatus Rcc_enuSelectSysCLk(u8 Copy_u8NewSysClk, u8 Copy_u8OldSysClk)
{

	//LOCAL VARIBLES

	Rcc_tenuErrorStatus Error_Status = Rcc_enuOk;
	u8 LOC_CurrentSysClk = ((RCC->RCC_CFGR) & (RCC_MASK_SWS));
	u16 LOC_Counter = 0;

	// SELCTING SYS CLK

	switch (Copy_u8NewSysClk)
	{
	case RCC_CLK_HSI:
		//RCC_STATE_TURNON_HSI
		SET_BIT(RCC->RCC_CR, RCC_REGISTER_BIT_0);
		//WAIT_HSI_READY
		while (GET_BIT(RCC->RCC_CR,RCC_REGISTER_BIT_1) == RCC_STATE_NOTREADY)
		{
			LOC_Counter++;
						if (LOC_Counter == BREAK_TIME)
						{
							Error_Status = Rcc_enuTimeOutError;
							break;
						}

		}

		//SWITCH SYSTEM CLK TO HSI
		RCC->RCC_CFGR = ((RCC->RCC_CFGR & ~(RCC_MASK_SW)) | RCC_CLK_HSI);

					//CHECK RCC_SWS_STATUS FLAG
		while ( (((RCC->RCC_CFGR) & (RCC_MASK_SWS)) >> 2) != RCC_CLK_HSI) //WAIT UNTIL SWS BE IN HSI
		{
			LOC_Counter++;
			if (LOC_Counter == BREAK_TIME)
			{
				Error_Status = Rcc_enuTimeOutError;
				break;
			}
		}

		break;
	case RCC_CLK_HSE:

		//RCC_STATE_TURNON_HSE;

		SET_BIT(RCC->RCC_CR, RCC_REGISTER_BIT_16);

		//WAIT TILL HSE IS READY

		while (GET_BIT(RCC->RCC_CR,RCC_REGISTER_BIT_17) == RCC_STATE_NOTREADY)
		{
			LOC_Counter++;
						if (LOC_Counter == BREAK_TIME)
						{
							Error_Status = Rcc_enuTimeOutError;
							break;
						}
		}
			//SWITCH THE SYSTEM CLK TO HSE
		RCC->RCC_CFGR = ((RCC->RCC_CFGR & ~(RCC_MASK_SW)) | RCC_CLK_HSE);


		while ( (((RCC->RCC_CFGR) & (RCC_MASK_SWS)) >> 2) != RCC_CLK_HSE) //WAIT UNTIL SWS BE IN HSE STATUS
		{
			LOC_Counter++;
			if (LOC_Counter == BREAK_TIME)
			{
				Error_Status = Rcc_enuTimeOutError;
				break;
			}
		}

		break;
	case RCC_CLK_PLL:

		//RCC_STATE_TURNON_PLL
		SET_BIT(RCC->RCC_CR, RCC_REGISTER_BIT_24);

		//WAIT TILL PLL IS READY
		while (GET_BIT(RCC->RCC_CR,RCC_REGISTER_BIT_25) == RCC_STATE_NOTREADY)
		{
			LOC_Counter++;
						if (LOC_Counter == BREAK_TIME)
						{
							Error_Status = Rcc_enuTimeOutError;
							break;
						}
		}

		//SWITCH SYSCLK TO PLL;
		RCC->RCC_CFGR = ((RCC->RCC_CFGR & ~(RCC_MASK_SW)) | RCC_CLK_PLL);

		while ( (((RCC->RCC_CFGR) & (RCC_MASK_SWS)) >> 2) != RCC_CLK_PLL) //WAIT UNTIL SWS BE IN PLL STATUS
		{
			LOC_Counter++;
			if (LOC_Counter >= BREAK_TIME)
			{
				Error_Status = Rcc_enuTimeOutError;
				break;
			}
		}

		break;
	default:

		break;
	}

/*TURNING THE OLD CLK OFF*/

	if (Copy_u8OldSysClk == RCC_STATE_NOTPRESERVE)
	{
		switch (LOC_CurrentSysClk)
		{
		case RCC_HSI_MASK: //0xXXXX0000

			//RCC STATE TURN OFF HSI
			CLR_BIT(RCC->RCC_CR, RCC_REGISTER_BIT_0);
			break;
		case RCC_HSE_MASK: //0xXXXX0100

			//RCC_STATE TURN OFF HSE
			CLR_BIT(RCC->RCC_CR, RCC_REGISTER_BIT_16);
			break;

		case RCC_PLL_MASK: //0xXXXX1000

			//RCC_STATE TURN OFF PLL
			CLR_BIT(RCC->RCC_CR, RCC_REGISTER_BIT_24);
			break;
			default:
			break;
		}

	}

	return Error_Status;
}
Rcc_tenuErrorStatus Rcc_enuControlCLk(u8 Copy_u8ControlHSI  ,u8 Copy_u8ControlHSE ,u8 Copy_u8ControlPLL){

		//local error variable
	Rcc_tenuErrorStatus Error_Status = Rcc_enuOk;

	switch (Copy_u8ControlHSI)
		{

		case RCC_CNTROL_HSION:
				//CHECK IF HSI IS ON
			if (GET_BIT(RCC->RCC_CR, RCC_REGISTER_BIT_0)==1)
			{

				Error_Status = RCC_enuUnLogicActionError;
			}

			else
			{
				// RCC STATE TURN ON HSI;
				SET_BIT(RCC->RCC_CR, RCC_REGISTER_BIT_0);
			}
			break;
		case RCC_CNTROL_HSIOFF:
			//CHECK IF HSI IS OFF
			if ((((RCC->RCC_CFGR) & (RCC_MASK_SWS)) >> 2) == RCC_CLK_HSI)
			{

				Error_Status = RCC_enuUnLogicActionError;

			}


			//CHECK IF PLL SOURCE IS HSI

			else if (GET_BIT(RCC->RCC_PLLCFGR, RCC_REGISTER_BIT_22)==0)
			{

				Error_Status = RCC_enuUnLogicActionError;

			}
			else
			{

				// RCC STATE TURN OFF HSI;
				CLR_BIT(RCC->RCC_CR, RCC_REGISTER_BIT_0);
			}

			break;

		}


	switch (Copy_u8ControlHSE)
			{

			case RCC_CNTROL_HSEON:

					//CHECK IF HSE IS ON
				if (GET_BIT(RCC->RCC_CR, RCC_REGISTER_BIT_16)==1)
				{

					Error_Status = RCC_enuUnLogicActionError;
				}

				else
				{
					// RCC STATE TURN ON HSE;
					SET_BIT(RCC->RCC_CR, RCC_REGISTER_BIT_16);
				}
				break;
			case RCC_CNTROL_HSEOFF:

				//CHECK IF HSE IS OFF FROM SWS STATUS BITS

				if ((((RCC->RCC_CFGR) & (RCC_MASK_SWS)) >> 2) == RCC_CLK_HSE)
				{

					Error_Status = RCC_enuUnLogicActionError;

				}


				//CHECK IF PLL SOURCE IS HSE

				else if (GET_BIT(RCC->RCC_PLLCFGR, RCC_REGISTER_BIT_22)==1)
				{

					Error_Status = RCC_enuUnLogicActionError;

				}
				else
				{

					// RCC STATE TURN OFF HSE;
					CLR_BIT(RCC->RCC_CR, RCC_REGISTER_BIT_16);
				}

				break;

			}


	switch (Copy_u8ControlPLL)
			{

			case RCC_CNTROL_PLLON:
					//CHECK IF PLL IS ON
				if (GET_BIT(RCC->RCC_CR, RCC_REGISTER_BIT_24)==1)
				{

					Error_Status = RCC_enuUnLogicActionError;
				}

				else
				{
					// RCC STATE TURN ON PLL;
					SET_BIT(RCC->RCC_CR, RCC_REGISTER_BIT_24);
				}
				break;
			case RCC_CNTROL_PLLOFF:
				//CHECK IF PLL IS OFF
				if ((((RCC->RCC_CFGR) & (RCC_MASK_SWS)) >> 2) == RCC_CLK_PLL)
				{
					Error_Status = RCC_enuUnLogicActionError;

				}
				else
				{
					//TURN OFF PLL
					CLR_BIT(RCC->RCC_CR, RCC_REGISTER_BIT_24);

				}

				break;

			}



	return Error_Status;
}

Rcc_tenuErrorStatus Rcc_enuCheckCLk(u8 Copy_u8CLk, pu8 Add_pu8RdyStatus){
	//LOCAL ERROR VARIABLE
	Rcc_tenuErrorStatus Error_Status = Rcc_enuOk;


	if (Add_pu8RdyStatus == NULL)
		{
			Error_Status = RCC_enuNullPointerError;
		}
		else
		{

			switch (Copy_u8CLk)
			{

			case RCC_CLK_HSI:
				if (GET_BIT(RCC->RCC_CR,RCC_REGISTER_BIT_1))
				{
					*Add_pu8RdyStatus = RCC_STATE_READY;
				}
				else
				{
					*Add_pu8RdyStatus = RCC_STATE_NOTREADY;
				}

				break;
			case RCC_CLK_HSE:
				if (GET_BIT(RCC->RCC_CR,RCC_REGISTER_BIT_17))
				{
					*Add_pu8RdyStatus = RCC_STATE_READY;
				}
				else
				{
					*Add_pu8RdyStatus = RCC_STATE_NOTREADY;
				}
				break;


			case RCC_CLK_PLL:

				if (GET_BIT(RCC->RCC_CR,RCC_REGISTER_BIT_25))
				{

					*Add_pu8RdyStatus = RCC_STATE_READY;

				}
				else
				{

					*Add_pu8RdyStatus = RCC_STATE_NOTREADY;

				}

				break;

			}

		}


	return Error_Status;
}

Rcc_tenuErrorStatus Rcc_enuCnfgrPll(u8 COPY_u8M , u16 Copy_u16N , u8 Copy_u8P , u8 Copy_u8SrcPll , u8 Copy_u8Q){

		//LOCAL ERROR VARIABLE
		Rcc_tenuErrorStatus Error_Status = Rcc_enuOk;
		//IF PLL IS ON AN ERROR SHOULD ARISE, These bits should be written only if PLL is DISABLED
			if(GET_BIT(RCC->RCC_CR, RCC_REGISTER_BIT_24)==1){

				Error_Status = RCC_enuPll_IS_On_Error;
			}
			else if (COPY_u8M > MAX_M|COPY_u8M < MINIMUM_M){
				Error_Status = RCC_enuInvalid_M_Error;

			}

			else if (Copy_u16N > MAX_N |Copy_u16N <MINIMUM_N){
				Error_Status = RCC_enuInvalid_N_Error;
										}
			else if (Copy_u8P > RCC_PLLP_DIVBY_8){
				Error_Status = RCC_enuInvalid_P_Error;
			}

			else if (Copy_u8SrcPll > RCC_PLLSRC_HSE)
				{

					Error_Status = RCC_enuInvalid_ScrPll_Error;
				}
			else if (Copy_u8Q > RCC_Q_DIVBY_15){
							Error_Status = RCC_enuInvalid_Q_Error;
						}

			else {
				RCC->RCC_PLLCFGR = RCC_CONFIG_PLL;
			}

return 	Error_Status;
}

Rcc_tenuErrorStatus Rcc_enuEnablePeriphral(u8 Copy_u8PeriphralBus , u32 Copy_u32Periphral){
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
Rcc_tenuErrorStatus Rcc_enuDisablePeriphral(u8 Copy_u8PeriphralBus , u32 Copy_u32Periphral){
	Rcc_tenuErrorStatus Error_Status = Rcc_enuOk;
		switch (Copy_u8PeriphralBus)
		{
		case RCC_REGISTER_AHB1:
			RCC->RCC_AHB1ENR &= ~(Copy_u32Periphral);
			break;
		case RCC_REGISTER_AHB2:
			RCC->RCC_AHB2ENR &= ~(Copy_u32Periphral);
			break;
		case RCC_REGISTER_APB1:
			RCC->RCC_APB1ENR &= ~(Copy_u32Periphral);
			break;
		case RCC_REGISTER_APB2:
			RCC->RCC_APB2ENR &= ~(Copy_u32Periphral);
			break;
		default:
			Error_Status = Rcc_enuWrongPeriphralBusError;
			break;
		}

		return Error_Status;


}

Rcc_tenuErrorStatus Rcc_enuCfgBusPrescalers(u32 Copy_u32Prescaler){

	Rcc_tenuErrorStatus Error_Status = Rcc_enuOk;
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


		default:
			Error_Status = Rcc_enuWrongBusPrescalerError;
			break;

		}

		return Error_Status;




}

