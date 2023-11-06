/*
 * EXIT_Pro.c
 *
 *  Created on: Oct 24, 2023
 *      Author: Online
 */
#include "../../../4-SERVICS/Std_types.h"
#include "../../../4-SERVICS/Bit_utils.h"
#include "../../3-ADC/include/ADC_Prv.h"
#include "../../3-ADC/include/ADC_Cfg.h"
#include "../../3-ADC/include/ADC.h"

u8* Global_pu8ADCReading =NULL;
void (*ADC_puCallBackFun)(void)=NULL;
u8 ADC_u8State = IDEL;

void ADC_voidInit(void){
/*Voltage Referance Selection */
#if Voltage_Referance == AVCC_WithExternalCapacitorAREFPin
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS0);
#elif Voltage_Referance == AREF_InternalVrefTurnedOff
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS0);
#elif Voltage_Referance == Internal2.56V_WithExternalCapacitorAtAREFPin
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS0);
#else
#error
#endif

	/*  ADC Left Adjust Result */
#if Left_Adjust == Left_AdjustEnable
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif Left_Adjust == Left_AdjustDisable
	ClR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error
#endif

	/*Auto Triggerred Enable */
#if AuTRIGGER == DISABLE
	CLR_BIT(ADCSRA,ADCSRA_ADATE);
#elif AuTRIGGER_ENABLE == ENABLE
	 SET_BIT(ADCSRA,ADCSRA_ADATE);
#else
#error
#endif
 /* ADC PRESCALER */

ADCSRA &= 0xF8;
ADCSRA |= ADC_Prescaler;

/* ADC ENABLE */
#if ADC_ENABLE == ENABLE
	SET_BIT(ADCSRA,ADCSRA_ADEN);
#elif ADC_ENABLE == DISABLE
	ClR_BIT(ADCSRA,ADCSRA_ADEN);
#else
#error
#endif

}

ADC_tenuErrorStatus ADC_u8StartConversionSynch(u8 Copy_u8Channal, pu8 Copy_pu8Reading){
	u8 local_u8Counter=0;
	u8 Error_u8State= ADC_EnmOk;
	if (ADC_u8State == IDEL)
		{
		ADC_u8State = BUSY;
/* Clear the MUX Bits In ADMUX Register */
ADMUX &= 0xE0;
/* Set The Requires Channals in ADMUX */
ADMUX |= Copy_u8Channal;
/* ADC Start Conversion */
SET_BIT(ADCSRA,ADCSRA_ADSC);
/* Polling until the conversion complete or Counter Reaching Time Out*/
while (((GET_BIT(ADCSRA,ADCSRA_ADIF))== 0) &&(local_u8Counter != ADC_u32TimeOut))
{
	local_u8Counter ++;
	if (local_u8Counter == ADC_u32TimeOut)
	{
		Error_u8State =ADC_EnmError;
	}
	else
	{
		/* Clear the Flag */
		SET_BIT(ADCSRA,ADCSRA_ADIF);
		/* Return the reading */
		*Copy_pu8Reading = ADCH;
		ADC_u8State =IDEL;
	}
}
		}
	else {
		Error_u8State = ADC_EnmError;
	}
return Error_u8State;
}
ADC_tenuErrorStatus ADC_u8StartConversionAsynch(u8 Copy_u8Channal, pu8 Copy_pu8Reading, void (*Copy_VNatifacationFunc)(void))
{
	u8 Local_StateError = ADC_EnmOk;
	if (ADC_u8State == IDEL)
	{
	Global_pu8ADCReading = Copy_pu8Reading;
	ADC_puCallBackFun = Copy_VNatifacationFunc;

	if ((Copy_pu8Reading != NULL ) || (Copy_VNatifacationFunc != NULL))
		{
		ADC_u8State =BUSY;
		/* Clear the MUX Bits In ADMUX Register */
		ADMUX &= 0xE0;

		/* Set The Requires Channals in ADMUX */
		ADMUX |= Copy_u8Channal;

		/* ADC Start Conversion */
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/* Enable ADC interrupt */
		SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
	else {
		Local_StateError = NULL_POINTER ;
	}
	}
	else {
		Local_StateError= ADC_EnmError;
	}
return Local_StateError;
}



void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	/* reading ADC result */
	*Global_pu8ADCReading = ADCH;
	/*   make ADC State Idel */
	ADC_u8State = IDEL;
	ADC_puCallBackFun();
	/* Disable ADC interrupt */
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
}





