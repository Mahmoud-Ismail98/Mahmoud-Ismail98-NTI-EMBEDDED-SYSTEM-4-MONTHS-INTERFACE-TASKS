

#include "../../../services/Std_types.h"
#include "../../../services/Bit_utils.h"
#include "../../../MCAL/PORT/include/port.h"
#include "../../../MCAL/DIO/include/DIO.h"
#include "../../../MCAL/ADC/ADC.h"

#define ADC_enable_pin 7
#define ADC_INT_PIN	4
#define ADC_START_CONVERSATIONPin 6
#define INTERRUPT_MODE	INTERUPT_DISABLE
void ADC_voidInit(void)
{  
	
	SET_BIT(ADCSRA,ADC_enable_pin);  //ADC_enable_pin
	ADCSRA|=(PRESCALER);
	ADMUX|=(Ref_VOLT_MODE<<6);  //6
	//ADMUX|=(ADC_CHA);
	//ADMUX |= (1<<5);	//ADLAR to left adjust the result	


#ifdef ADC_CHA
ADMUX|=(ADC_CHA);
#endif	

#ifdef Trigger_Source_Selections
  SET_BIT(ADCSRA,5); //ADATE: ADC Auto Trigger Enable pin 
  SFIOR|=(Trigger_Source_Selections<<5);
#endif

#if INTERRUPT_MODE==INTERRUPT_ENABLE
SET_BIT(ADCSRA ,3);  //Bit 3 – ADIE: ADC Interrupt Enable 
#endif	
}


ADC_ERROR_STATE ADC_read(u8 ADC_CHANEL,u16 *loc_AdcVal)
{
	ADC_ERROR_STATE ADC_ERROR =ADC_ERROR_FREE;
	ADMUX|=(ADC_CHA);
	ADCSRA |= (1<<ADC_START_CONVERSATIONPin);		/*6 IS  Start_conversion_pin  */

		
while((ADCSRA&(1<<ADC_INT_PIN))==0);	/*check for interrupt if */

	*loc_AdcVal = (u16)ADCL ;
	*loc_AdcVal = *loc_AdcVal+(u16)ADCH*256 ;
/*	*loc_AdcVal|=ADCL;
	*loc_AdcVal|=(ADCH<<8);	*/			
//	CLR_BIT(ADCSRA,4); 		
	return ADC_ERROR;

}

void ADC_Disable(void)
{
		  CLR_BIT(ADCSRA,ADC_START_CONVERSATIONPin); //sart conversation pin 	

}


