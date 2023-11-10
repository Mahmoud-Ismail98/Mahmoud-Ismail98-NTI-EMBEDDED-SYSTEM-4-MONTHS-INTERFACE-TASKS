#ifndef  SYSTCK_H_
#define  SYSTCK_H_
//////////////////////////////////////////////////////////////////////////////
#define source_F 16000000UL
#include "Std_types.h"
typedef struct{
	volatile u32 STK_CTRL ;
	volatile u32 STK_LOAD ;
	volatile u32 STK_VAL ;
	volatile u32 STK_CALIB; } sys_t;

	#define systck  ((sys_t*)0xE000E010)

/*
source_F - SYSTICK_PRESCALER_DIV8 STK_LOAD
*/
#define CLK_SRC     SYSTICK_PRESCALER_DIV8  

	
#define ENABLE_INT                0x02
#define DISABLE_INT               0x00
	

#define INTERRUPT_STATUS      ENABLE_INT



	
/*TYPEDEF ENUM FOR THE TYPES OF 0xE000 E010.ERROR STATUS*/
typedef enum{
	/*ERROR STATUS IS OK*/
	Systick_enuOk,
	/*ERROR STATUS IS IN TIMEMs  ERROR*/
	Systick_enuErrorTimeMs,
	/*ERROR STATUS IS IN NULL POINTER ERROR*/
	Systick_enuErrorNullPointer,

}Systick_tenuErrorStatus;//NAME OF THE TYPEDEF ENUM

typedef void (* Systick_Cbf) (void); // TYPEDEF  FOR A POINTER TO A FUNCTION
//////////////////////////////MACROS///////////////////////////////////////////
#define VALIDATE_RELOADVALUE   			0xFF000000 //MACRO VALIDATE_RELOADVALUE MASK

#define SYSTICK_PRESCALER_DIV8 			0x02	//MACRO SYSTICK_PRESCALER_DIV8 MASK

#define SYSTICK_PRESCALER_DIV1 			0x06 	//MACRO SYSTICK_PRESCALER_DIV1 MASK

#define SYSTICK_ENABLE					0x1	    //MACRO SYSTICK_ENABLE MASK

////////////////////////////PROTOTYPES/////////////////////////////////////////
/*PROTOYPE FOR Systick_Init FUNCTION */
 void Systick_Init(u32 Copy_TimeMs);
/*PROTOYPE FOR Systick_RegisterCbf FUNCTION */
Systick_tenuErrorStatus Systick_RegisterCbf(Systick_Cbf Add_pfCbf);
/*PROTOTYPE FOR Systick_Start FUNCTION*/
 void Systick_Start(void);
/*PROTOTYPE FOR Systick_Stop FUNCTION*/
void Systick_Stop(void);
///////////////////////////////////////////////////////////////////////////////
#endif