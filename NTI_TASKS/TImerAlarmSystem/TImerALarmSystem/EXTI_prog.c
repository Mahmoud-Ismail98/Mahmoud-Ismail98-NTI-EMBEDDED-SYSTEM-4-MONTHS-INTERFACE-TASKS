
#include "Std_types.h"
#include "Bit_utils.h"


#include "EXTI.h"
#include "EXTI_cfg.h"
#include "EXT_priv.h"

#include <avr/io.h>
/*This is the pointer to function*/
static volatile void (* Ext_INT0_ptr) (void); 

void ExtI_voidInitialize(void)
{
#if EXTI_NUM==INT0
	SET_BIT(GICR,INT0);

#elif EXTI_NUM==INT1
	SET_BIT(GICR,INT1);

#elif EXTI_NUM==INT2
	SET_BIT(GICR,INT2);
#endif


#if (EXTI_MODE == LOW_LEVEL) && (EXTI_NUM == INT0)
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);

#elif EXTI_MODE==ANY_CHANGE &&  EXTI_NUM==INT0

		SET_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);

	#elif EXTI_MODE==FALLING_EDGE &&  EXTI_NUM==INT0

			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);

	#elif EXTI_MODE==RISING_EDGE &&  EXTI_NUM==INT0

				SET_BIT(MCUCR,0);
				SET_BIT(MCUCR,1);


	#endif

#if EXTI_MODE== LOW_LEVEL && EXTI_NUM==INT1
	CLR_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);

#elif EXTI_MODE==ANY_CHANGE &&  EXTI_NUM==INT1

		SET_BIT(MCUCR,2);
		CLR_BIT(MCUCR,3);

	#elif EXTI_MODE==FALLING_EDGE &&  EXTI_NUM==INT1

			CLR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);

	#elif EXTI_MODE==RISING_EDGE &&  EXTI_NUM==INT1

				SET_BIT(MCUCR,2);
				SET_BIT(MCUCR,3);


	#endif

	#if EXTI_MODE==FALLING_EDGE &&  EXTI_NUM==INT2

			CLR_BIT(MCUCSR,6);

	#elif EXTI_MODE==RISING_EDGE &&  EXTI_NUM==INT2

			SET_BIT(MCUCSR,6);

	#endif



}



void ExtI_voidEnableExtI(void)  
{
	#if EXTI_NUM==INT0
	SET_BIT(GICR,INT0);

#elif EXTI_NUM==INT1
	SET_BIT(GICR,INT1);

#elif EXTI_NUM==INT2
	SET_BIT(GICR,INT2);
#endif

}

void ExtI_voidDisableExtI(void)  
{
	#if EXTI_NUM==INT0
	CLR_BIT(GICR,INT0);

#elif EXTI_NUM==INT1
	CLR_BIT(GICR,INT1);

#elif EXTI_NUM==INT2
	CLR_BIT(GICR,INT2);
#endif

}

u8 ExtI_u8ExtInterrupt0FlagStatus(void)
{
	//Here we know the status of the Interrupt flag if we want to
	if (GET_BIT(GIFR,INTF0) == ENABLED){
          return ENABLED;
	}
	else
		return DISABLED;
}

u8 EXTI_u8Int0SetSenseControl(u8 copy_u8Sense)
{
	switch (copy_u8Sense)
	{
		case LOW_LEVEL :   CLR_BIT(MCUCR,0); CLR_BIT(MCUCR,1);
		case ANY_CHANGE:  SET_BIT(MCUCR,0); CLR_BIT(MCUCR,1);
		case FALLING_EDGE: CLR_BIT(MCUCR,0); SET_BIT(MCUCR,1);
        case RISING_EDGE : SET_BIT(MCUCR,0); SET_BIT(MCUCR,1);
		
	}
}

void ExtI_voidSetCallBack(void (* I_ptr)(void)){
     Ext_INT0_ptr = I_ptr;
}




void __vector_1(void)__attribute((signal,used));
void __vector_1(void) {
	Ext_INT0_ptr();
}

