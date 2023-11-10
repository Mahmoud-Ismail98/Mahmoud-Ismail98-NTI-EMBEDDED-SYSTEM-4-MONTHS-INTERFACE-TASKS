#include "Std_types.h"
#include "Bit_utils.h"
#include "systick.h"



void Systick_Init(u32 Copy_TimeMs){
	
	
	#if CLK_SRC == source_F
	 //select the processor clock as the source clock
		SET_BIT( systck->STK_CTRL , 2);
	
	#elif CLK_SRC == SYSTICK_PRESCALER_DIV8 
	
	 // processor clock divided by 8
		CLR_BIT(systck->STK_CTRL , SYSTICK_PRESCALER_DIV8);
	
	#endif
	
	
	#if INTERRUPT_STATUS == ENABLE_INT
	
	// Enable interrupt request when counting is finished
		systck->STK_CTRL = ENABLE_INT;
	
	#elif  INTERRUPT_STATUS == DISABLE_INT
		
		systck->STK_CTRL = DISABLE_INT;
	
	#endif
	
// calculating the reload value
	u32 RELOAD_VALUE = (source_F /1000)*Copy_TimeMs - 1;
	systck->STK_LOAD = RELOAD_VALUE;

//clear the current value
	systck->STK_VAL =0;
}

void Systick_Start(void) {
	
	systck->STK_CTRL=SYSTICK_ENABLE;
}

void Systick_Stop(void){
	
	CLR_BIT(systck->STK_CTRL,0);
}

	
	

	
	
	
