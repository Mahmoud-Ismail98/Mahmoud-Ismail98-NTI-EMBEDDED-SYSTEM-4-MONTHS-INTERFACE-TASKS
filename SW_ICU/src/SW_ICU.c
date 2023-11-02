
#include "../inc/LIB/Std_types.h"
#include "../inc/LIB/Bit_utils.h"

#include "../inc/MCAL/PORT/PORT.h"
#include "../inc/MCAL/DIO/DIO_int.h"
#include "../inc/MCAL/EXTI/EXTI_int.h"
#include "../inc/MCAL/TIMER0/TIMER0_int.h"
#include "../inc/SERVICE/SW_ICU/SW_ICU.h"

u8 Global_u8TON=0;
u8 Global_u8TOFF=0;
void SW_ICU_voidGetGlobalVals(void)
{
	static u8 Local_u8Flag = 0;
	if(Local_u8Flag == 0)
	{
		EXTI_voidSetSignal(EXTI0,FALLING_EDGE);
		TIMER0_voidSetTimerTicks(0);
		Local_u8Flag = 1;

	}
	else if(Local_u8Flag == 1)
	{
		EXTI_voidSetSignal(EXTI0,RISING_EDGE);
		Global_u8TON = TIMER0_voidGetTimerTicks();
		TIMER0_voidSetTimerTicks(0);
		Local_u8Flag = 2;
	}
	else if(Local_u8Flag == 2)
	{
		Global_u8TOFF = TIMER0_voidGetTimerTicks();
		TIMER0_voidSetTimerTicks(0);
		Local_u8Flag = 0;
	}
}
void SW_ICU_voidInit(void)
{
	PORT_enumSET_PINDirection(PORT_u8PORTDPIN2, PORT_u8PINDIR_INPUT);
	PORT_enumSET_PINMODE(PORT_u8PORTDPIN2, PORT_u8PINMODE_INPUT_FLOATING);
	EXTI_voidSetCallBack(EXTI0, SW_ICU_voidGetGlobalVals);
	EXTI_voidInit();
	TIMER0_voidInit();
	
}
void SW_ICU_voidGetTON_TOFFVals(u8 *Ptr_u8TON, u8 *Ptr_u8TOFF)
{
	*Ptr_u8TON = Global_u8TON;
	*Ptr_u8TOFF = Global_u8TOFF;
}
