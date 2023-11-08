#ifndef SYSTICK_H_
#define SYSTICK_H_


/*TYPEDEF ENUM FOR THE TYPES OF ERROR STATUS*/
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

#define SYSTICK_ENABLE					    0x1	    //MACRO SYSTICK_ENABLE MASK

////////////////////////////PROTOTYPES/////////////////////////////////////////
/*PROTOYPE FOR Systick_Init FUNCTION */
Systick_tenuErrorStatus Systick_Init(u32 Copy_TimeMs);
/*PROTOYPE FOR Systick_RegisterCbf FUNCTION */
Systick_tenuErrorStatus Systick_RegisterCbf(Systick_Cbf Add_pfCbf);
/*PROTOTYPE FOR Systick_Start FUNCTION*/
void Systick_Start(void);
/*PROTOTYPE FOR Systick_Stop FUNCTION*/
void Systick_Stop(void);
/*PROTOTYPE FOR Systick_UpdateFreq FUNCTION*/
void Systick_UpdateFreq(u32 Copy_CPU_FREQ);
///////////////////////////////////////////////////////////////////////////////


#endif


