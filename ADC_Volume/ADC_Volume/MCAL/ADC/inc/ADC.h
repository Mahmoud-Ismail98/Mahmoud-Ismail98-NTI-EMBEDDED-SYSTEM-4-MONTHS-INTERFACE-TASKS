/*
 * KeyPad.h
 *
 * Created: 10/23/2023 11:15:51 AM
 *  Author: Ahmed Wael
 */

#ifndef ADC_H_
#define ADC_H_
#include "ADC_prv.h"
/*
ADC_voidInit() Description:

Copy_u8VREF Options:
					ADC_VREF_AREF
                    ADC_VREF_AVCC
                    ADC_VREF_INT256   //2.56V

Copy_u8Prescaler Options:
					ADC_Prescaler_2
                    ADC_Prescaler_4
                    ADC_Prescaler_8
                    ADC_Prescaler_16
                    ADC_Prescaler_32
                    ADC_Prescaler_64
					ADC_Prescaler_128

This Function Only Initiate Configurations of the ADC, You need to call ADC_Enable() after this for ADC Enable
*/
void ADC_voidInit(u8 Copy_u8VREF, u8 Copy_u8Prescaler);


/*
ADC_Enable() Description:
Enables The ADC
*/
void ADC_Enable();


/*
ADC_Disable() Description:
Disables The ADC
*/
void ADC_Disable();


/*
ADC_ADC_voidRead() Description:
Copy_u8Channel Options:
					ADC_CH0
					ADC_CH1
					ADC_CH2
					ADC_CH3
					ADC_CH4
					ADC_CH5
					ADC_CH6
					ADC_CH7
This Function Uses Polling On the ADC, It will wait until it finishes conversion, you can use Interrupts to avoid polling
The Interrupt should be Disapled while using this function
*/
void ADC_voidReadPolling(u8 Copy_u8Channel, u16* ADC_Read_Value);

/*
ADC_InterruptEnable() Description:
Enables the Interrupt
*/
void ADC_InterruptEnable();

/*
DC_ADC_voidRead() Description:
Copy_u8Channel Options:
						ADC_CH0
						ADC_CH1
						ADC_CH2
						ADC_CH3
						ADC_CH4
						ADC_CH5
						ADC_CH6
						ADC_CH7
This Function Uses Starts Conversion in ADC, It will fire an interrupt when it finishes conversion.
The Interrupt should be Enabled while using this function*/
void ADC_voidStartConversionInterrupt(u8 Copy_u8Channel);



/*
ADC_InterruptSetCallBack() Description:
Set ISR Function that will be executed when it finishes conversion
*/
void ADC_InterruptSetCallBack(void (*Fptr) (void));


/*
ADC_InterruptDisable() Description:
Disables the Interrupt
*/
void ADC_InterruptDisable();




#endif
