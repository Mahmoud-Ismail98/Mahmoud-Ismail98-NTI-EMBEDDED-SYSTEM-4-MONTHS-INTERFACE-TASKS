/*
 * Timers.h
 *
 * Created: 10/24/2023 11:15:51 AM
 *  Author: Wael
 */

 typedef enum{
	Timer_0,
	Timer_1,
 }Timer_enuType;

 typedef enum{
	Timer0_NormalMode,
	Timer0_CTCMode,
	Timer0_FastPwmMode,
	Timer0_PhaseCorrectMode
 }Timer0_enuMode;

typedef enum{
	Timer0_STOP=0,
	Timer0_SCALER_1,
	Timer0_SCALER_8,
	Timer0_SCALER_64,
	Timer0_SCALER_256,
	Timer0_SCALER_1024,
	EXTERNALl_FALLING,
	EXTERNAL_RISING
}Timer0_enuScaler;

typedef enum
{
	OC0_DISCONNECTED=0,
	OC0_TOGGLE,
	OC0_NON_INVERTING,
	OC0_INVERTING

}Timer0_enuOC0Mode;


void Timer0_voidInit(Timer0_enuMode Copy_enuMode, Timer0_enuScaler Copy_enuScaler,Timer0_enuOC0Mode Copy_enuOC0Mode);

void Timer0_voidOVF_InterruptEnable();
void Timer0_voidOVF_InterruptDisable();


void Timer0_voidOC_InterruptEnable();
void Timer0_voidOC_InterruptDisable();

void Timer0_voidOVF_SetCallBack(void (*Fptr) (void));

void Timer0_voidSetTCNT(u8 Copy_u8Val);
u8 Timer0_u8GetTCNT();

/*Operates on Normal Mode Only*/
void Timer0_voidCallFuncatTime(u16 Copy_u16Time, void (*Func)(void));
/*Operates on FastPWM mode Only*/
void Timer0_voidGeneratePWM(u32 Copy_u32Freq, u8 Copy_u8Duty);
////////////////////////////////////////////////////////////////////////////////////////////////////////


typedef enum{
	TIMER1_STOP=0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	EXTERNAL0_FALLING,
	EXTERNAL0_RISING
}Timer1Scaler_type;

typedef enum
{
	TIMER1_NORMAL_MODE=0,
	TIMER1_CTC_ICR_TOP_MODE,
	TIMER1_CTC_OCRA_TOP_MODE,
	TIMER1_FASTPWM_8BIT_MODE,
	TIMER1_FASTPWM_ICR_TOP_MODE,
	TIMER1_FASTPWM_OCRA_TOP_MODE

}Timer1Mode_type;

typedef enum
{
	OCRA_DISCONNECTED=0,
	OCRA_TOGGLE,
	OCRA_NON_INVERTING,
	OCRA_INVERTING

}OC1A_Mode_type;

typedef enum
{
	OCRB_DISCONNECTED=0,
	OCRB_TOGGLE,
	OCRB_NON_INVERTING,
	OCRB_INVERTING

}OC1B_Mode_type;

void Timer1_voidInit(Timer1Mode_type Copy_enuMode, Timer1Scaler_type Copy_enuScaler);

void Timer1_voidSETOC1AMode(OC1A_Mode_type Copy_enuMode);
void Timer1_voidSETOC1BMode(OC1B_Mode_type Copy_enuMode);

void Timer1_voidSETOC1A(u16 Copy_u16Val );
void Timer1_voidSETOC1B(u16 Copy_u16Val );

