/**************************************************************************/
/* Filename						: SYSTICK.c                            */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 7, 2023  	           	 	         	 */ 
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/* Trainee At					: NTI (4 Months)						  */
/* Instructor					: Mahmoud Embabi						  */
/**************************************************************************/





/********************************** Includes *********************************************/

#include "BIT_UTILS.h"
#include "MAGIC_NUMBERS.h"
#include "STD_TYPES.h"

#include "SYSTICK.h"
#include "SYSTIC_private.h"
#include "SYSTICK_config.h"
/********************************** Private declaration **********************************/

#define SYSTICK_INTERVAL_FLAG 			ZERO_VALUE
#define SYSTICK_PERIODIC_FLAG 			ONE_VALUE

static u8 Global_u8TimerTypeFlag = SYSTICK_INTERVAL_FLAG;

static void (*Systick_OverflowInterruptHandler)( void);
/********************************** Data Type Declarations ****************************/


/********************************** Macros Declarations *******************************/

/********************************** Macros Function Declarations *********************/

#define	Systick_startCounting()				(SET_BIT(STK_CTRL,ZERO_VALUE))
#define	Systick_stopTimer()				(CLEAR_BIT(STK_CTRL,ZERO_VALUE))


#define Systick_enableInterrupt()			(SET_BIT(STK_CTRL,ONE_VALUE))
#define Systick_disableInterrupt()			(CLEAR_BIT(STK_CTRL,ONE_VALUE))
#define Systick_getInterruptStatus()		(READ_BIT(STK_CTRL,ONE_VALUE))
#define Systick_setInterruptStatus(_VALUE_)		(WRITE_BIT(STK_CTRL,ONE_VALUE,_VALUE_))

#define Systick_setClkSoruce(_ARGU_)		(WRITE_BIT(STK_CTRL,TWO_VALUE,_ARGU_))


#define Systick_IsCountingDone()			(READ_BIT(STK_CTRL,SIXTEEN_VALUE) == ONE_VALUE)


#define Systick_SetValue(_VALUE_)			(ASSIGN_REG(STK_LOAD,_VALUE_))


/******************************* Software Interfaces Implementation **********************************/


Systick_ErrorStatusType Systick_enuInit(void){
	Systick_ErrorStatusType Loc_enuSystickErrorStatus = SYSTICK_STATUS_OK;

	/* Disable Interrupt */
	Systick_disableInterrupt();

	/* Select Clock Source */
	Systick_setClkSoruce(STK_CLK_SORUCE);


	return Loc_enuSystickErrorStatus;


}

Systick_ErrorStatusType Systick_enuEnableInterrupt(void){
	Systick_ErrorStatusType Loc_enuSystickErrorStatus = SYSTICK_STATUS_OK;

	/* Enable Interrupt */
	Systick_enableInterrupt();

	return Loc_enuSystickErrorStatus;


}
Systick_ErrorStatusType Systick_enuDisableInterrupt(void){
	Systick_ErrorStatusType Loc_enuSystickErrorStatus = SYSTICK_STATUS_OK;

	Systick_disableInterrupt();

	return Loc_enuSystickErrorStatus;


}


Systick_ErrorStatusType Systick_enuSetBusyWait(u32 Copy_u32TicksNumber){
	Systick_ErrorStatusType Loc_enuSystickErrorStatus = SYSTICK_STATUS_OK;

	u8 Loc_u8InterruptStatusEnable ;

	/* Set Value */
	Systick_SetValue(Copy_u32TicksNumber);

	/* get interrupt status */
	Loc_u8InterruptStatusEnable = Systick_getInterruptStatus();

	/* Disable interrupt */
	Systick_disableInterrupt();

	/* Start Timer */
	Systick_startCounting();
	while(Systick_IsCountingDone() == ZERO_VALUE);

	/* Disable/stop Timer */
	Systick_stopTimer();

	/* set interrupt as it was */
	Systick_setInterruptStatus(Loc_u8InterruptStatusEnable);

	return Loc_enuSystickErrorStatus;


}

Systick_ErrorStatusType Systick_enuSetIntervalOneTimeTicks (u32 Copy_u32TicksNumber,void (*callback)(void)){
	Systick_ErrorStatusType Loc_enuSystickErrorStatus = SYSTICK_STATUS_OK;
	if(callback == NULL){
		Loc_enuSystickErrorStatus =SYSTICK_STATUS_NULL_POINTER_ADDRESS;
	}
	else{


		/* Set Value */
		Systick_SetValue(Copy_u32TicksNumber);

		/* Set callback function */
		Systick_OverflowInterruptHandler = callback;

		/* Set flag mode to Interval */
		Global_u8TimerTypeFlag = SYSTICK_INTERVAL_FLAG;

		/* Enable interrupt */
		Systick_enableInterrupt();

		/* Start Timer */
		Systick_startCounting();



	}


	return Loc_enuSystickErrorStatus;


}
Systick_ErrorStatusType Systick_enuSetIntervalPeriodicTicks (u32 Copy_u32TicksNumber, void (*callback)(void) ){
	Systick_ErrorStatusType Loc_enuSystickErrorStatus = SYSTICK_STATUS_OK;
	if(callback == NULL){
		Loc_enuSystickErrorStatus =SYSTICK_STATUS_NULL_POINTER_ADDRESS;
	}
	else{


		/* Set Value */
		Systick_SetValue(Copy_u32TicksNumber);

		/* Set callback function */
		Systick_OverflowInterruptHandler = callback;

		/* Set flag mode to Interval */
		Global_u8TimerTypeFlag = SYSTICK_PERIODIC_FLAG;

		/* Enable interrupt */
		Systick_enableInterrupt();

		/* Start Timer */
		Systick_startCounting();



	}




	return Loc_enuSystickErrorStatus;


}
Systick_ErrorStatusType Systick_enuStopTimer(void){
	Systick_ErrorStatusType Loc_enuSystickErrorStatus = SYSTICK_STATUS_OK;

	Systick_stopTimer();

	return Loc_enuSystickErrorStatus;


}
Systick_ErrorStatusType Systick_enuGetElapsedTimeTicks(pu32 Address_Result){
	Systick_ErrorStatusType Loc_enuSystickErrorStatus = SYSTICK_STATUS_OK;

	if(Address_Result == NULL){
		Loc_enuSystickErrorStatus = SYSTICK_STATUS_FAIL;
	}
	else{
		*Address_Result = STK_LOAD - STK_VAL;
	}


	return Loc_enuSystickErrorStatus;


}
Systick_ErrorStatusType Systick_enuGetRemainingTimeTicks(pu32 Address_Result){
	Systick_ErrorStatusType Loc_enuSystickErrorStatus = SYSTICK_STATUS_OK;

	if(Address_Result == NULL){
		Loc_enuSystickErrorStatus = SYSTICK_STATUS_FAIL;
	}
	else{
		*Address_Result = STK_VAL;
	}


	return Loc_enuSystickErrorStatus;


}

/**************************** ISR Implementation ************************************/
void SysTick_Handler (void){

	if(Systick_OverflowInterruptHandler != NULL){
		Systick_OverflowInterruptHandler();
	}
	else{
		/* Error in setting callback */

	}

	if(Global_u8TimerTypeFlag == SYSTICK_INTERVAL_FLAG){
		Systick_disableInterrupt();
		Systick_stopTimer();
	}
}

/**************************** Private Software Interface Implementation **************/

