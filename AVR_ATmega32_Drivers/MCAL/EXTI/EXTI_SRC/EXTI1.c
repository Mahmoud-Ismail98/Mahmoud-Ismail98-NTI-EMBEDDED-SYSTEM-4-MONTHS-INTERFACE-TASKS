/*
 * EXTI.h
 *
 * Created: 10/22/2023 3:43:21 PM
 *  Author: Mohamed Alaa
 */ 


#include <MCAL/EXTI/EXTI_Includes/EXTI.h>
#include <MCAL/EXTI/EXTI_Includes/EXTI_CFG.h>
#include <MCAL/EXTI/EXTI_Includes/EXTI_Private.h>
#include <Services/Bit_utils.h>
#include <MCAL/GIE/GIE_Includes/GIE.h>

void (*(EXTI_INTx_GPCallBack[3]))(void) = {EXTI_INT0_PCallBack, EXTI_INT1_PCallBack, EXTI_INT2_PCallBack};

EXTI_Error_State EXTI_Init(void)
{
	EXTI_Error_State EXTI_State = EXTI_No_Error;
	
	if( ((uint8)EXTI_INT0_Detect > EXTI_Disabled) | ((uint8)EXTI_INT1_Detect > EXTI_Disabled) | ((uint8)EXTI_INT2_Detect > EXTI_Disabled) | ((uint8)EXTI_INT2_Detect < EXTI_Falling_Edge))
		EXTI_State = EXTI_Invalid_Configurations;
	else
	{
		
		//set EXTI_INT0 Trigger condition
		if(EXTI_INT0_Detect != EXTI_Disabled)
		{
			MCUCR_REG &= ~(0x03 << ISC00);	//clear bits
			MCUCR_REG |= (EXTI_INT0_Detect << ISC00);
			SET_BIT(GICR_REG, INT0);			//enable EXTI_INT0 inside the EXTI module
		}
		//set EXTI_INT1 Trigger condition
		if(EXTI_INT1_Detect != EXTI_Disabled)
		{
			MCUCR_REG &= ~(0x03 << ISC10);	//clear bits
			MCUCR_REG |= (EXTI_INT1_Detect << ISC10);
			SET_BIT(GICR_REG, INT1);			//enable EXTI_INT1 inside the EXTI module
		}
		//set EXTI_INT2 Trigger condition
		if(EXTI_INT2_Detect == EXTI_Rising_Edge)
		{
			SET_BIT(MCUCSR_REG, ISC2);
			SET_BIT(GICR_REG, INT2);			//enable EXTI_INT2 inside the EXTI module
		}
		else if(EXTI_INT2_Detect == EXTI_Falling_Edge)
		{
			CLR_BIT(MCUCSR_REG, ISC2);
			SET_BIT(GICR_REG, INT2);
		}
		GIE_Enable();	
	}
	
	return EXTI_State;
}

EXTI_Error_State EXTI_Enable(uint8 EXTI_INTx, uint8 EXTI_INTx_Detection, void (*EXTI_INTx_PCallBack)(void))
{
	EXTI_Error_State EXTI_State = EXTI_No_Error;
	if(((uint8)EXTI_INTx_Detection > EXTI_Rising_Edge) | ((EXTI_INTx == EXTI_INT2) && (EXTI_INTx_Detection != EXTI_Falling_Edge)) | ((EXTI_INTx == EXTI_INT2) && (EXTI_INTx_Detection != EXTI_Falling_Edge)))
	{
		EXTI_State = EXTI_Invalid_Detection_Argument;
	}
	else if (EXTI_INTx_PCallBack == PTR_NULL)
	{
		EXTI_State = EXTI_PCallBack_is_Null;
	}
	else
	{
		EXTI_INTx_GPCallBack[EXTI_INTx] = EXTI_INTx_PCallBack;
		switch(EXTI_INTx)
		{
			case EXTI_INT0:
 			MCUCR_REG &= ~(0x03 << ISC00);	//clear bits
 			MCUCR_REG |= (EXTI_INTx_Detection << ISC00);
			 SET_BIT(GICR_REG, INT0);			//enable EXTI_INT0 inside the EXTI module

			break;
			
			case EXTI_INT1:
			MCUCR_REG &= ~(0x03 << ISC10);	//clear bits
			MCUCR_REG |= (EXTI_INTx_Detection << ISC10);
			SET_BIT(GICR_REG, INT1);			//enable EXTI_INT1 inside the EXTI module
			break;
			
			case EXTI_INT2:
			if(EXTI_INTx_Detection == EXTI_Rising_Edge)
			{
				SET_BIT(MCUCSR_REG, ISC2);
				SET_BIT(GICR_REG, INT2);			//enable EXTI_INT2 inside the EXTI module
			}
			else if(EXTI_INTx_Detection == EXTI_Falling_Edge)
			{
				CLR_BIT(MCUCSR_REG, ISC2);
				SET_BIT(GICR_REG, INT2);
			}
			break;
			
			default:
			EXTI_State = EXTI_Invalid_Interrupt_Number;
		}
	}
	
	return EXTI_State;
}

EXTI_Error_State EXTI_Disable(uint8 EXTI_INTx)
{
	EXTI_Error_State EXTI_State = EXTI_No_Error;
	switch(EXTI_INTx)
	{
		case EXTI_INT0:
		CLR_BIT(GICR_REG, INT0);			//Disable EXTI_INT0 inside the EXTI module	
		break;
		
		case EXTI_INT1:
		CLR_BIT(GICR_REG, INT1);			//Disable EXTI_INT0 inside the EXTI module
		break;
		
		case EXTI_INT2:
		CLR_BIT(GICR_REG, INT2);			//Disable EXTI_INT0 inside the EXTI module
		
		default:
		EXTI_State = EXTI_Invalid_Interrupt_Number;
	}

return EXTI_State;
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void) 
{
	EXTI_INTx_GPCallBack[EXTI_INT0]();
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	EXTI_INTx_GPCallBack[EXTI_INT1]();
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	EXTI_INTx_GPCallBack[EXTI_INT2]();
}