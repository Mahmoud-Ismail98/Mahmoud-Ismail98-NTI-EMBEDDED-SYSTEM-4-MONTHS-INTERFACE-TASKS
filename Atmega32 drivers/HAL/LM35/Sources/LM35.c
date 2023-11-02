/*
 * L35.c
 *
 * Created: 23/10/2023 11:27:35 
 *  Author: EGYPT
 */ 
#include "Std_types.h"
#include "Bit_utils.h"

#include "DIO.h"
#include "ADC.h"

#include "LM35.h"
#include "LM35_priv.h"


 void LM35_u8GetValue (LM35_CONFIG * lm35 , u16 * Copy_u8Value)
{

	u16 Local_u16ADCResult ;
	u16 Local_u16AnalogValue=0 ;
	
	u16 Local_u8ADCReference = ( lm35->Copy_u8ADCVoltageReference ) * 1000 ;  // To Convert from ( V --> mV )
	
	
	/* ADC Digital Reading  */
	ADC_u8GetResultSync( lm35->Copy_u8LM35Channel , &Local_u16ADCResult ) ;

	/* Check for ADC Resolution  */
	if ( lm35->Copy_u8ADCResolution == ADC_RESOLUTION_10_BIT )
	{
		Local_u16AnalogValue = (u16) ( ((u32)Local_u16ADCResult * (u32)Local_u8ADCReference ) / 1024UL) ;

	}
	else if ( lm35->Copy_u8ADCResolution == ADC_RESOLUTION_8_BIT )
	{
		Local_u16AnalogValue = (u16) ( ((u32)Local_u16ADCResult * (u32)Local_u8ADCReference ) / 256UL) ;
	}


	
	* Copy_u8Value = Local_u16AnalogValue  ;

	
}