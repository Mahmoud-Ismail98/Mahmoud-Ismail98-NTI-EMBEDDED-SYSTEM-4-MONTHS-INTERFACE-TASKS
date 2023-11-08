
#ifndef _STK_H_
#define _STK_H_


typedef enum{
	/*ERROR STATUS IS OK*/
	Systick_enuOk,
	/*ERROR STATUS IS IN TIMEMs  ERROR*/
	Systick_enuErrorTimeMs,
	Systick_enuErrorStatus,
	/*ERROR STATUS IS IN NULL POINTER ERROR*/
	Systick_enuErrorNullPointer,

}Systick_tenuErrorStatus;//NAME OF THE TYPEDEF ENUM



typedef struct
{
	volatile u32 MSTK_CTRL   ;
	volatile u32 MSTK_LOAD   ;
	volatile u32 MSTK_VAL    ;
	volatile u32 MSTK_CALIB  ;

}MSTK_t;

#define MSTK_BASE_ADDRESS                        0xE000E010
#define MSTK                               ((MSTK_t *)(MSTK_BASE_ADDRESS))

/*********************************************************************************************/
typedef enum
{
	MSTK_DISABLE = 0 ,
	MSTK_ENABLE
}MSTK_State_t;

typedef enum
{
	MSTK_INT_DISABLE = 0 ,
	MSTK_INT_ENABLE
	
}MSTK_INT_State_t;

/********************************** PROTOTYPES ***************************************************/
void MSTK_voidInit(void);
Systick_tenuErrorStatus MSTK_voidTimerState(MSTK_State_t Copy_uddtState);
Systick_tenuErrorStatus MSTK_voidIntStatus(MSTK_INT_State_t Copy_uddtIntState);
void _delay_ms(u32 Copy_u32Time);
void _delay_us(u32 Copy_u32Time);
u8 MSTK_u8ReadFlag(void);
void MSTK_voidSetCallBack(void(*PFunc)(void));
void MSTK_voidStart(u32 Copy_u32Preload);




#endif