/*
 * KeyPad.h
 *
 * Created: 10/23/2023 11:15:51 AM
 *  Author: Ahmed Wael
 */
#include"Bit_utils.h"
#include"Std_types.h"

#include "../inc/ADC.h"
#include "../inc/ADC_prv.h"
#include "../inc/ADC_cfg.h"


void (*FptrG) (void) = NULL;

void ADC_voidInit(u8 Copy_u8VREF, u8 Copy_u8Prescaler)
{

	ADMUX &= 0x3F; //0011 1111
 	ADMUX |= Copy_u8VREF<<6; //Select VREF
	// ADLAR = 0;
	ADCSRA &= 0xF8; //1111 1000
	ADCSRA |= Copy_u8Prescaler; //Select Prescaler
}

void ADC_Enable()
{
	SET_BIT(ADCSRA,ADEN); //Enable
}
void ADC_Disable()
{
	CLR_BIT(ADCSRA,ADEN); //Disable
}


void ADC_voidReadPolling(u8 Copy_u8Channel, u16* ADC_Read_Value)
{
	ADMUX &= 0xE0;  //1110 0000
	ADMUX |= Copy_u8Channel;  //Select Channel

	SET_BIT(ADCSRA,ADSC);
	while(GET_BIT(ADCSRA,ADSC));

	*ADC_Read_Value = ADC_R;
}

void ADC_voidStartConversionInterrupt(u8 Copy_u8Channel)
{
	ADMUX &= 0xE0;  //1110 0000
	ADMUX |= Copy_u8Channel;  //Select Channel

	SET_BIT(ADCSRA,ADSC);
}


void ADC_InterruptEnable()
{
	SET_BIT(ADCSRA,ADIE);
}

void ADC_InterruptSetCallBack(void (*Fptr) (void))
{
	FptrG = Fptr;
}


void ADC_InterruptDisable()
{
	CLR_BIT(ADCSRA,ADIE);
}



ISR(ADC_vect)
{
	FptrG();
}
