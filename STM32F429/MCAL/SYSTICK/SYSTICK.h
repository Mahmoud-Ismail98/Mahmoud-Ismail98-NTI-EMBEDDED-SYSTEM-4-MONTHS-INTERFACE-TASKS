/**************************************************************************/
/* Filename						: SYSTICK.h                            */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 7, 2023  	           	 	         	 */ 
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/* Trainee At					: NTI (4 Months)						  */
/* Instructor					: Mahmoud Embabi						  */
/**************************************************************************/


#ifndef SYSTICK_SYSTICK_H_
#define SYSTICK_SYSTICK_H_



/********************************** Includes *********************************************/



/********************************** Macros Declarations *******************************/



/********************************** Macros Function Declarations *********************/


/********************************** Data Type Declarations ****************************/

typedef enum{
	SYSTICK_STATUS_FAIL,
	SYSTICK_STATUS_OK,
	SYSTICK_STATUS_NULL_POINTER_ADDRESS
}Systick_ErrorStatusType;


/********************************** Software Interfaces Declarations *******************/

Systick_ErrorStatusType Systick_enuInit(void); // to set clock source, disable interrupt
Systick_ErrorStatusType Systick_enuEnableInterrupt(void);
Systick_ErrorStatusType Systick_enuDisableInterrupt(void);


Systick_ErrorStatusType Systick_enuSetBusyWait(u32 Copy_u32TicksNumber);
Systick_ErrorStatusType Systick_enuSetIntervalOneTimeTicks (u32 Copy_u32TicksNumber,void (*callback)(void));
Systick_ErrorStatusType Systick_enuSetIntervalPeriodicTicks (u32 Copy_u32TicksNumber, void (*callback)(void));
Systick_ErrorStatusType Systick_enuStopTimer(void);
Systick_ErrorStatusType Systick_enuGetElapsedTimeTicks(pu32 Address_Result);
Systick_ErrorStatusType Systick_enuGetRemainingTimeTicks(pu32 Address_Result);


#endif /* SYSTICK_SYSTICK_H_ */
