#include "../inc/LIB/Bit_utils.h"
#include "../inc/LIB/Std_types.h"
#include "../inc/MCAL/ADC/ADC_cfg.h"
#include "../inc/MCAL/ADC/ADC_int.h"
#include "../inc/MCAL/ADC/ADC_prv.h"

volatile pu16 G_Ptr_AdcReading;
void(*G_ptr_AdcIsrNotification)(u16 Global_pu16Data);

void ADC_voidInit(void)
{
	#if Refernce_Selection == AREF_PIN
	CLR_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
	#elif Refernce_Selection == AVCC
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
	#elif Refernce_Selection == internal2Volt
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	#endif
	
	#if		LEFT_ADJUST == ENABLE
	SET_BIT(ADMUX,ADLAR);
	#elif	LEFT_ADJUST == DISABLE
	CLR_BIT(ADMUX,ADLAR);
	#endif
	
	ADCSRA=((ADCSRA&0b11111000)|ADC_Prescaller);
#if Interrupt_EN == ENABLE
	ADC_voidEnablePeripheralInterrupt();
#elif Interrupt_EN == DISABLE
	ADC_voidDisablePeripheralInterrupt();
#endif

	ADC_voidEnablePeripheral();
	
}

void ADC_voidEnablePeripheral(void)
{
		SET_BIT(ADCSRA,ADEN);
}

void ADC_voidDisablePeripheral(void)
{
		CLR_BIT(ADMUX,ADEN);
}
void ADC_voidEnablePeripheralInterrupt(void)
{
		SET_BIT(ADCSRA, ADIE);
}
void ADC_voidDisablePeripheralInterrupt(void)
{
		CLR_BIT(ADCSRA, ADIE);
}
void ADC_voidStartConversion(u8 Copy_u8ChannelID)
{
	ADMUX=((ADMUX&0b11100000)|Copy_u8ChannelID);
	SET_BIT(ADCSRA,ADSC);
}

void ADC_voidReadVal_Async(void(*LocaL_PtrToFunc)(u16 Ptr_pu16CopyData))
{
	G_ptr_AdcIsrNotification=LocaL_PtrToFunc;

}
void __vector_16 (void) 
{
	
	u16 data = ADC_DATA;
	(*G_ptr_AdcIsrNotification)(data);

}
