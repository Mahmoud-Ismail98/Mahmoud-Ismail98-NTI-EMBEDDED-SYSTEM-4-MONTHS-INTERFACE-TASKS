/*
 * Timers.h
 *
 * Created: 10/24/2023 11:15:51 AM
 *  Author: Wael
 */
 #include "Std_types.h"
#include "Bit_utils.h"
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

/*Operates on Normal Mode Only*/
void Timer0_voidCallFuncatTime(u16 Copy_u16Time, void (*Func)(void));
/*Operates on FastPWM mode Only*/
void Timer0_voidGeneratePWM(u32 Copy_u32Freq, u8 Copy_u8Duty);
