/*
 * EXTI.c
 *
 * Created: 10/22/2023 3:40:25 PM
 *  Author: Mahmoud Tariq
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_CFG.h"
#include "EXTI_PRIVATE.h"
#include "EXTI.h"
static void (*Global_PtoFs[3]) (void) = {NULL,NULL,NULL};
void EXTI_vidInit(){
	
	/*Activating INT0*/
	#if (EXTI_Enable_INT0 == 1)
		SET_BIT(GICR,GICR_INT0);
		#if (EXTI_INT0_FALLING_EDGE == 1)
			CLR_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
		#endif
		
		#if (EXTI_INT0_LOW_LEVEL == 1)
			CLR_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
		#endif
		
		#if (EXTI_INT0_ON_CHANGE == 1)
			SET_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
		#endif
		
		#if (EXTI_INT0_RISING_EDGE == 1)
			SET_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
		#endif
		
	#endif
	
	/*Activating INT1*/
	#if  (EXTI_Enable_INT1 == 1)
		SET_BIT(GICR,GICR_INT1);
			#if (EXTI_INT1_FALLING_EDGE == 1)
			CLR_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
			#endif
			
			#if (EXTI_INT1_LOW_LEVEL == 1)
			CLR_BIT(MCUCR,MCUCR_ISC10);
			CLR_BIT(MCUCR,MCUCR_ISC11);
			#endif
			
			#if (EXTI_INT1_ON_CHANGE == 1)
			SET_BIT(MCUCR,MCUCR_ISC10);
			CLR_BIT(MCUCR,MCUCR_ISC11);
			#endif
			
			#if (EXTI_INT1_RISING_EDGE == 1)
			SET_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
			#endif
	#endif
	
	/*Activating INT2*/
	#if (EXTI_Enable_INT2 ==1)
		SET_BIT(GICR,GICR_INT2);
		/*Initializing Wanted Mode*/
		#if (EXTI_INT2_RISING_EDGE == 1)
		SET_BIT(MCUCSR,MCUCSR_ISC2);
		#endif
		
		#if (EXTI_INT2_FALLING_EDGE == 1)
		CLR_BIT(MCUCSR,MCUCSR_ISC2);
		#endif
	#endif
}


void EXTI_vidDeInit(){
	CLR_BIT(GICR,GICR_INT2);
	CLR_BIT(GICR,GICR_INT1);
	CLR_BIT(GICR,GICR_INT0);
	
}
void EXTI_vidSetFallingEdge  (u8 copy_u8EXTI_Index){
	
	switch(copy_u8EXTI_Index){
		
		case EXTI_INT0:
			SET_BIT(GICR,GICR_INT0);
			CLR_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;
		case EXTI_INT1:
			SET_BIT(GICR,GICR_INT1);
			CLR_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
			break;
		case EXTI_INT2:
			SET_BIT(GICR,GICR_INT2);
			CLR_BIT(MCUCSR,MCUCSR_ISC2);
			break;
		default:break;		
	}
}
void EXTI_vidSetRisingEdge (u8 copy_u8EXTI_Index){
	
	switch(copy_u8EXTI_Index){
		
		case EXTI_INT0:
		SET_BIT(GICR,GICR_INT0);
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
		case EXTI_INT1:
		SET_BIT(GICR,GICR_INT1);
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
		break;
		case EXTI_INT2:
		SET_BIT(GICR,GICR_INT2);
		SET_BIT(MCUCSR,MCUCSR_ISC2);
		break;
		default:break;
		
	}
}
void EXTI_vidClear(u8 copy_u8EXTI_Index){
	switch(copy_u8EXTI_Index){
		
		case EXTI_INT0:
		CLR_BIT(GICR,GICR_INT0);
		break;
		case EXTI_INT1:
		CLR_BIT(GICR,GICR_INT1);	
		break;
		case EXTI_INT2:
		CLR_BIT(GICR,GICR_INT2);
		break;
		default:break;
		
	}
	
	
	
}
void EXTI_vidSetCallBack(u8 copy_u8IntID,void (*PF) (void))
{
	if (PF != NULL)
	{
		switch (copy_u8IntID)
		{
			case EXTI_INT0:Global_PtoFs[0] = PF;
			break;
			case EXTI_INT1:Global_PtoFs[1] = PF;
			break;
			case EXTI_INT2:Global_PtoFs[2] = PF;
			break;
			default:
			break;
		}
	}
}
//ISR for INT0
void __vector_1	(void)	__attribute__((signal,used));
void __vector_1	(void)
{
	if(Global_PtoFs[0] != NULL)
	{
		Global_PtoFs[0]();
	}
}
//ISR for INT1
void __vector_2	(void)	__attribute__((signal,used));
void __vector_2	(void)
{
	if(Global_PtoFs[1] != NULL)
	{
		Global_PtoFs[1]();
	}
}
//ISR for INT2
void __vector_3	(void)	__attribute__((signal,used));
void __vector_3	(void)
{
	if(Global_PtoFs[2] != NULL)
	{
		Global_PtoFs[2]();
	}
}



