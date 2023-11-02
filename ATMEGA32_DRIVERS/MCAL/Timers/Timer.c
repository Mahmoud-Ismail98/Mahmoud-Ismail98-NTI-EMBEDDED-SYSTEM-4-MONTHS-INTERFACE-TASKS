#include "std_types.h"
#include "Bit_utils.h"
#include "Timer.h"
#include "Timer_priv.h"
#include "Timer_config.h"

/* Global Variables */
static volatile void (* Timer0_INT_ptr) (void);
u8 over_flow_counter =0;

/* Function: TIMER_init
 * Description: Initializes Timer 0 with selected operating mode and clock prescaler.
 * Inputs: None
 * Outputs: None
 */

void TIMER_init(void){
#if (OPERATING_MODE == NORMAL_MODE)
CLEAR_BIT(TCCR0,WGM01);
CLEAR_BIT(TCCR0,WGM00);
CLEAR_BIT(TCCR0,COM01);
CLEAR_BIT(TCCR0,COM00);
#elif(OPERATING_MODE == PWM_PHASE_CORRECT_MODE)
CLEAR_BIT(TCCR0,WGM01);
SET_BIT(TCCR0,WGM00);
#if (COMPARE_OUTPUT_PHASE_CORRECT_PWM_MODE == NORMAL_OUTPUT)
CLEAR_BIT(TCCR0,COM01);
CLEAR_BIT(TCCR0,COM00);
#elif(COMPARE_OUTPUT_PHASE_CORRECT_PWM_MODE == SET_OC0_DOWNCOUNT_CLEAR_UPCOUNT)
CLEAR_BIT(TCCR0,COM01);
CLEAR_BIT(TCCR0,COM00);
#elif(COMPARE_OUTPUT_PHASE_CORRECT_PWM_MODE == CLEAR_OC0_DOWNCOUNT_SET_UPCOUNT)
CLEAR_BIT(TCCR0,COM01);
CLEAR_BIT(TCCR0,COM00);
#endif


#elif(OPERATING_MODE == CTC_MODE)
#if(COMPARE_OUTPUT_NO_PWM_MODE == NORMAL_COMPARE_OUTPUT )
CLEAR_BIT(TCCR0,COM01);
CLEAR_BIT(TCCR0,COM00);
#elif(COMPARE_OUTPUT_NO_PWM_MODE == SET_OC0_ON_COMPARE_MATCH )
SET_BIT(TCCR0,COM01);
SET_BIT(TCCR0,COM00);
#elif(COMPARE_OUTPUT_NO_PWM_MODE == CLEAR_OC0_ON_COMPARE_MATCH )
SET_BIT(TCCR0,COM01);
CLEAR_BIT(TCCR0,COM00);
#endif


#elif(OPERATING_MODE == FAST_PWM_MODE)


#if(COMPARE_OUTPUT_FAST_PWM_MODE == NORMAL_OUTPUY)
SET_BIT(TCCR0,COM00);
SET_BIT(TCCR0,COM00);
#elif(COMPARE_OUTPUT_FAST_PWM_MODE == SET_OC0_ON_COMPARE_MATCH )
SET_BIT(TCCR0,COM01);
SET_BIT(TCCR0,COM00);
#elif(COMPARE_OUTPUT_FAST_PWM_MODE == CLEAR_OC0_ON_COMPARE_MATCH )
SET_BIT(TCCR0,COM01);
CLEAR_BIT(TCCR0,COM00);
#endif

#endif

/*NO_CLK
 *CLK_1
 *CLK_8
 *CLK_64
 *CLK_256
 *CLK_1024
 *EXTERNAL_ON_T0_COUNT_ON_FALLING_EDGE
 *EXTERNAL_ON_T0_COUNT_ON_RISING_EDGE
 */
#if(CLOCK_PRESCALER_SELECT == NO_CLK)
CLEAR_BIT(TCCR0,CS00);
CLEAR_BIT(TCCR0,CS01);
CLEAR_BIT(TCCR0,CS02);
#elif(CLOCK_PRESCALER_SELECT == CLK_1)
SET_BIT(TCCR0,CS00);
CLEAR_BIT(TCCR0,CS01);
CLEAR_BIT(TCCR0,CS02);
#elif(CLOCK_PRESCALER_SELECT == CLK_8)
CLEAR_BIT(TCCR0,CS00);
SET_BIT(TCCR0,CS01);
CLEAR_BIT(TCCR0,CS02);
#elif(CLOCK_PRESCALER_SELECT == CLK_64)
SET_BIT(TCCR0,CS00);
SET_BIT(TCCR0,CS01);
CLEAR_BIT(TCCR0,CS02);
#elif(CLOCK_PRESCALER_SELECT == CLK_256)
CLEAR_BIT(TCCR0,CS00);
CLEAR_BIT(TCCR0,CS01);
SET_BIT(TCCR0,CS02);
#elif(CLOCK_PRESCALER_SELECT == CLK_1024)
SET_BIT(TCCR0,CS00);
CLEAR_BIT(TCCR0,CS01);
SET_BIT(TCCR0,CS02);
#elif(CLOCK_PRESCALER_SELECT == EXTERNAL_ON_T0_COUNT_ON_FALLING_EDGE)
CLEAR_BIT(TCCR0,CS00);
SET_BIT(TCCR0,CS01);
SET_BIT(TCCR0,CS02);
#elif(CLOCK_PRESCALER_SELECT == EXTERNAL_ON_T0_COUNT_ON_RISING_EDGE)
SET_BIT(TCCR0,CS00);
SET_BIT(TCCR0,CS01);
SET_BIT(TCCR0,CS02);

#endif

}

/* Function: TIMER_reset
 * Description: Resets Timer 0 counter value to 0.
 * Inputs: None
 * Outputs: None
 */1
void TIMER_init(void)
{
	TCNT0 = 0x00;
}

/* Function: TIMER_forceOutputCompareMode
 * Description: Forces Output Compare mode for Timer 0.
 * Inputs: None
 * Outputs: None
 */
void TIMER_voidForceOutPutCompareMode(void){
	SET_BIT(TCCR0,FOC0);
}

/* Function: TIMER_enableOutputCompareInterrupt
 * Description: Enables the Output Compare Interrupt for Timer 0.
 * Inputs: None
 * Outputs: None
 */

void TIMER_voidEnableOutputCompareInterrupt(void){
SET_BIT(TIMSK,OCIE0);
}


/* Function: TIMER_enableOverflowInterrupt
 * Description: Enables the Overflow Interrupt for Timer 0.
 * Inputs: None
 * Outputs: None
 */
void TIMER_voidEnableOverFlowInterrupt(void){
	SET_BIT(TIMSK,TOIE0);
}


/* Function: TIMER_setCounterValue
 * Description: Writes a value to Timer 0's counter register (TCNT0).
 * Inputs:
 *   - time: The value to write to TCNT0.
 * Outputs: None
 */
void TIMER_WriteInTCNT0(u8 time){
	TCNT0 = time;
}

/* Function: TIMER_setOutputCompareValue
 * Description: Writes a value to the Output Compare Register (OCR0) for Timer 0.
 * Inputs:
 *   - value: The value to write to OCR0.
 * Outputs: None
 */
void TIMER_WriteInOCR0(u8 value){
	OCR0 = value;
}

#if(OPERATING_MODE == NORMAL_MODE)

/* Function: TIMER_setOutputCompareCallback
 * Description: Sets a callback function for Timer 0's Output Compare Interrupt.
 * Inputs:
 *   - TimerInterrupt_ptr: Pointer to the callback function.
 * Outputs: None
 */

void TIMER_SetCallBack(void (* TimerInterrupt_ptr)(void)){
	Timer0_INT_ptr = TimerInterrupt_ptr;
}

void __vector_11(void)__attribute((signal,used));
void __vector_11(void) {
	Timer0_INT_ptr();
}
#endif
#if(OPERATING_MODE == CTC_MODE)

/* Function: TIMER_setCaptureCompareCallback
 * Description: Sets a callback function for Timer 0's Capture Compare Interrupt.
 * Inputs:
 *   - CaptureCompareInterrupt_ptr: Pointer to the callback function.
 * Outputs: None
 */
void Timer0_SetCallBack(void (* CaptureCompareInterrupt_ptr)(void)){
	Timer0_INT_ptr = CaptureCompareInterrupt_ptr;
}
/* Timer 0 Capture Compare Interrupt Vector */

void __vector_10(void)__attribute((signal,used));
void __vector_10(void) {
	Timer0_INT_ptr();
}
#endif



                                                       /*ICU : Soft AND Hardware Using Timer1*/


/***** Intialize ICU Mode In Timer One*****/

/* Function: ICU_init
 * Description: Initializes ICU (Input Capture Unit) mode in Timer 1.
 * Inputs: None
 * Outputs: None
 */
void ICU_VoidInit (void)
{
	/* Set Trigger Source To Rising Edge intially */
	SET_BIT(TCCR1B,TCCR1B_ICES1) ; 
	
	/* Enable Input Capture Interrupt */ 
	SET_BIT(TIMSK,TIMSK_TICIE1) ; 
	
	
}

/* Function: ICU_setTriggerEdge
 * Description: Sets the trigger edge (Rising/Falling) for Input Capture in ICU mode.
 * Inputs:
 *   - copy_u8Edge: The desired edge (ICU_RISING_EDGE or ICU_FALLING_EDGE).
 * Outputs:
 *   - Local_u8ErrorStatus: OK if successful, NOT_OK if invalid input.
 */
u8 ICU_voidSetTriggerICUEdge (u8 copy_u8Edge )
{
u8 Local_u8ErrorStatus = OK ; 
	if (copy_u8Edge == ICU_RISING_EDGE)
	{
	SET_BIT(TCCR1B,TCCR1B_ICES1) ;
	}
	else if (copy_u8Edge == ICU_FALLING_EDGE)
	{
	CLR_BIT(TCCR1B , TCCR1B_ICES1) ;

	}
	else 
	{
		Local_u8ErrorStatus = NOT_OK; 
	}
	return Local_u8ErrorStatus ; 
}

/* Function: ICU_enableInterrupt
 * Description: Enables the Input Capture Interrupt in ICU mode.
 * Inputs: None
 * Outputs: None
 */
void ICU_voidEnableInterrupt(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1) ; 
}
/* Function: ICU_disableInterrupt
 * Description: Disables the Input Capture Interrupt in ICU mode.
 * Inputs: None
 * Outputs: None
 */
void ICU_voidDisableInterrupt(void)
{
	CLR_BIT(TIMSK,TIMSK_TICIE1) ;
}


/* Function: ICU_getCapturedValue
 * Description: Reads the captured value in ICU mode.
 * Inputs: None
 * Outputs: Captured value in ICR1 register.
 */
u16 ICU_ReadInputCapture(void)
{
	return  ICR1 ;  
}

/* Function: ICU_setCallback
 * Description: Sets a callback function for the ICU mode Input Capture Interrupt.
 * Inputs:
 *   - copy_PvCallBack: Pointer to the callback function.
 * Outputs:
 *   - Local_u8ErrorStatus: OK if successful, NULL_POINTER if the callback is NULL.
 */

u8 ICU_u8SetCallBack (void (*copy_PvCallBack)(void)) 
{
	u8 Local_u8ErrorStatus = OK ; 
	if (copy_PvCallBack!= NULL)
	{
		ICUCallBackFunc = copy_PvCallBack ; 
		
	}
	else 
	{
		Local_u8ErrorStatus = NULL_POINTER ; 
	}
	
	return Local_u8ErrorStatus ; 
}

/* ICU mode Input Capture Interrupt Vector */

void __vector__6 (void) __attribute__((signal));
void __vector__6 (void)
{
	if (ICUCallBackFunc != NULL)
	{
		ICUCallBackFunc() ; 
	}
}



/*****************************************************************************Watch Dog Timer***********************************************************************/

/* Function: WDT_enable
 * Description: Enables the Watchdog Timer.
 * Inputs: None
 * Outputs: None
 */
void WDT_VoidEnable(void)
{
	SET_BIT (WDTCR,WDTCR_WDE);
}


/* Function: WDT_disable
 * Description: Disables the Watchdog Timer.
 * Inputs: None
 * Outputs: None
 */
void WDT_VoidDisable(void)
{
	WDTCR = (1<<WDTCR_WDTOE) | (1<<WDTCR_WDE) ; 
	/* One Cycle */
	WDTCR = 0 ;
	 
}


/* Function: WDT_setSleepTime
 * Description: Sets the Watchdog Timer sleep time.
 * Inputs:
 *   - copy_u8SleepTime: Sleep time value (0-7).
 * Outputs:
 *   - Local_u8ErrorState: OK if successful.
 */

u8 WDT_u8Sleep(u8 copy_u8SleepTime)
{
	u8 Local_u8ErrorState = OK ; 
	
	if (copy_u8SleepTime < 8 )
	{
		WDTCR  &= 0b11111000;
		WDTCR  |= 0b11111000;
		
	}
	
	return Local_u8ErrorState ; 
}


