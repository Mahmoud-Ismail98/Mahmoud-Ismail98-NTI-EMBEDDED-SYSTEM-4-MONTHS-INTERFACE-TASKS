#include "../../../inc/LIB/Bit_utils.h"
#include "../../../inc/LIB/Std_types.h"
#include "../../../inc/MCAL/DIO/DIO_int.h"
#include "../../../inc/MCAL/EXTI/EXTI_cfg.h"
#include "../../../inc/MCAL/EXTI/EXTI_int.h"
#include "../../../inc/MCAL/EXTI/EXTI_prv.h"
#include "../../../inc/MCAL/GIE/GIE_int.h"

void(*EXTI_GLOBALFUNC[3])(void);

void EXTI_voidInit(void)
{

	EXTI_voidSetSignal(EXTI_CHOICE,Signal_Choice);
	EXTI_voidEnableInt(EXTI_CHOICE);
}
void EXTI_voidEnableInt(u8 Copy_u8IntID)
{
	switch(Copy_u8IntID)
	{
		case EXTI0:
			SET_BIT(GICR,INT0);
		break;
		case EXTI1:
			SET_BIT(GICR,INT1);
		break;
		case EXTI2:
			SET_BIT(GICR,INT2);
		break;
	}
}
void EXTI_voidDisableInt(u8 Copy_u8IntID)
{
	switch(Copy_u8IntID)
	{
		case EXTI0:
			CLR_BIT(GICR,INT0);
		break;
		case EXTI1:
			CLR_BIT(GICR,INT1);
		break;
		case EXTI2:
			CLR_BIT(GICR,INT2);
		break;
	}	
}
void EXTI_voidSetSignal(u8 Copy_u8IntID,u8 Copy_u8SignalID)
{
	switch(Copy_u8IntID)
	{
		case EXTI0:
			MCUCR =((MCUCR &0b11111100)|Copy_u8SignalID);
		break;
		case EXTI1:
			MCUCR =((MCUCR &0b11110011)|(Copy_u8SignalID<<2));
		break;
		case EXTI2:
			if(Copy_u8SignalID == FALLING_EDGE)
			{
				CLR_BIT(MCUCR,ISC2);
			}
			else if(Copy_u8SignalID == RISING_EDGE)
			{
				SET_BIT(MCUCR,ISC2);
			}
			else
			{}
		break;
	}	
}
void EXTI_voidSetCallBack(u8 Copy_u8IntID, void(*PTR)(void))
{
	EXTI_GLOBALFUNC[Copy_u8IntID] = PTR;
}
void __vector_1 (void) {
	EXTI_GLOBALFUNC[0]();
}

void __vector_2 (void) {
	EXTI_GLOBALFUNC[1]();
}

void __vector_3 (void) {
	EXTI_GLOBALFUNC[2]();
}
