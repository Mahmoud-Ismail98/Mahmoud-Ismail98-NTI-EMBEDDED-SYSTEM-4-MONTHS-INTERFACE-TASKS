#include "../../../Services/Lib/std_types.h"
#include "../../../Services/Lib/common_macros.h"
#include "../Includes/ADC.h"
#include "../Includes/ADC_Cfg.h"
#include "../Includes/ADC_Prv.h"

  void(*G_Ptr)(uint16)=Null_ptr;


  ADC_enuErrorStatus ADC_Init(const ADC_ConfigType* Config_Ptr)
{
	uint8 ErrorStatus=ADC_enuOK;
	if(Config_Ptr==Null_ptr)
	{
		ErrorStatus=ADC_enuNullPtr;
	}
	ADMUX=(ADMUX & 0x3F) | (Config_Ptr->Voltage<<6);
	ADCSRA=(ADCSRA & 0xF8) |( Config_Ptr->Prescaler);

#if(ADC_ADJUST==ADC_ADJUST_ENBLE)
	SET_BIT(ADMUX,5);
#else
	CLEAR_BIT(ADMUX,5);
#endif

#if(ADC_INTERRUPT==ADC_INTERRUPT_ENABL)
	SET_BIT(ADCSRA,3);
#else
	CLEAR_BIT(ADCSRA,3);
#endif
	SET_BIT(ADCSRA,7);

return ErrorStatus;
}

void ADC_StartConcersion()
{
	SET_BIT(ADCSRA,6);
}

void ADC_Disable(void)
{
	CLEAR_BIT(ADCSRA,7);

}

ADC_enuErrorStatus ADC_enuReadChannel(ADC_Channel Copy_u8Channel )
{
	uint8 ErrorStatus=ADC_enuOK;
	if(Copy_u8Channel>ADC7)
	{
		ErrorStatus=ADC_enuWrongChannel;
	}

	ADMUX=(ADMUX & 0xE0) | (Copy_u8Channel &0x07);
	ADC_StartConcersion();

	return ErrorStatus;
}

void ADC_CallBack(void(*ADC_CallPtr)(uint16))
{
	G_Ptr=ADC_CallPtr;
}
