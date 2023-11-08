
#ifndef MCAL_SYSTICK_SYSTICK_H_
#define MCAL_SYSTICK_SYSTICK_H_

#include <Services/Memory_Map.h>
#include <Services/Bit_utils.h>
#include <Services/Std_types.h>

//////////////////////////////////////////////////////////////////////////////
/*TYPEDEF ENUM FOR THE TYPES OF ERROR STATUS*/
typedef enum{
	/*ERROR STATUS IS OK*/
	Systick_enuOk,
	/*ERROR STATUS IS IN TIMEMs  ERROR*/
	Systick_enuErrorTimeMs,
	/*ERROR STATUS IS IN NULL POINTER ERROR*/
	Systick_enuErrorNullPointer,

}Systick_tenuErrorStatus;//NAME OF THE TYPEDEF ENUM

//////////////////////////////MACROS///////////////////////////////////////////
#define VALIDATE_RELOADVALUE   			0xFF000000 			//MACRO VALIDATE_RELOADVALUE MASK

#define SYSTICK_PRESCALER_DIV8 			((uint32)0)			//MACRO SYSTICK_PRESCALER_DIV8 MASK
#define SYSTICK_PRESCALER_DIV1 			((uint32)(1<<2)) 	//MACRO SYSTICK_PRESCALER_DIV1 MASK

#define SYSTICK_EN						((uint32)(1<<0))	//MACRO SYSTICK_ENABLE MASK

#define TICKINT_State_Disable			((uint32)0)
#define TICKINT_State_EN				((uint32)(1<<1))

typedef struct
{
	uint32 CLKSOURCE;
	uint32 TICKINT_State;
	void (* Systick_Cbf) (void);
}
SysTic_CFG_t;



////////////////////////////PROTOTYPES/////////////////////////////////////////
/*PROTOYPE FOR Systick_Init FUNCTION */
Systick_tenuErrorStatus Systick_Init(SysTic_CFG_t *SysTic_CFG);
/*PROTOTYPE FOR Systick_Start FUNCTION*/
void Systick_Start(uint64 Time_us);
/*PROTOTYPE FOR Systick_Stop FUNCTION*/
void Systick_Stop(void);
///////////////////////////////////////////////////////////////////////////////
#endif /* MCAL_SYSTICK_SYSTICK_H_ */
