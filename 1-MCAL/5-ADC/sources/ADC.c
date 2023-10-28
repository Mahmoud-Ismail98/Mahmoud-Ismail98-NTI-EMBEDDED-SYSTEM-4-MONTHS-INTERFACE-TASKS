/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : ADC                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "Std_types.h"
#include "Bit_utils.h"

#include "ADC.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"

pu16 Glob_u16DigitalVal = 0;

u16 Glob_u8Res = 0;

void (*ADC_ISR_FUNC)() = NULL;

/**
 * This function is used to Initialize the adc. 
 */
void ADC_voidInit(){
    #if ADC_REFERENCE == ADC_REFERENCE_AREF_Internal_Vref_turned_off
        CLR_BIT(ADMUX,7);
        CLR_BIT(ADMUX,6);
    #elif ADC_REFERENCE == ADC_REFERENCE_AVCC_with_external_capacitor_at_AREF_pin
        CLR_BIT(ADMUX,7);
        SET_BIT(ADMUX,6);
    #elif ADC_REFERENCE == ADC_REFERENCE_Internal_Voltage
        SET_BIT(ADMUX,7);
        SET_BIT(ADMUX,6);
    #endif

    #if ADC_ADJUST == ADC_RIGHT_ADJUST
        CLR_BIT(ADMUX,5);
    #elif ADC_ADJUST == ADC_LEFT_ADJUST
        SET_BIT(ADMUX,5);
    #endif


}

/**
 * This function is used to read the ADC value for a certain channel. 
 * 
 * @param Copy_u8Channel represents the channel number.
 * 
 * @param Copy_u8PreScaler represents the prescaler that will be applied to adc clock.
 * 
 * @param Copy_u8Resolution represents the desired adc resolution.
 * 
 * @param Copy_pu16DigitalValue pointer to a u16 to save the ADC reading in it.
 */
void ADC_voidReadChannel(u8 Copy_u8Channel,u8 Copy_u8PreScaler, u8 Copy_u8Resolution, pu16 Copy_pu16DigitalValue){
    /* setting the channel */
    ADMUX &= ADC_MULTIPLEXER_SELECTION_MASK;
    ADMUX |= Copy_u8Channel;

    /*setting prescaler*/
    ADCSRA &= ADC_PRESCALER_MASK;
    ADCSRA |= Copy_u8PreScaler;
    /* enabling adc */
    ADC_prvENABLE();
    /* start conversion */
    SET_BIT(ADCSRA, 6);

    /* wait until conversion ends */
    while(GET_BIT(ADCSRA, 4) == 0);

    if (Copy_u8Resolution == ADC_RESOLUTION_8BIT){
        #if ADC_ADJUST == ADC_RIGHT_ADJUST
            *Copy_pu16DigitalValue = ADCL;
            *Copy_pu16DigitalValue = Copy_pu16DigitalValue >> 2;
            *Copy_pu16DigitalValue |= ADCH << 6;

        #elif ADC_ADJUST == ADC_LEFT_ADJUST
            *Copy_pu16DigitalValue = ADCH ;
        #endif
    }else if (Copy_u8Resolution == ADC_RESOLUTION_16BIT){
        #if ADC_ADJUST == ADC_RIGHT_ADJUST
            *Copy_pu16DigitalValue = ADCL;
            *Copy_pu16DigitalValue |= ADCH << 8;
        #elif ADC_ADJUST == ADC_LEFT_ADJUST
            *Copy_pu16DigitalValue = ADCDATA >> 6;
        #endif
    }
    SET_BIT(ADCSRA, 4);
    ADC_prvDISABLE();
}

static void ADC_prvENABLE(){
    SET_BIT(ADCSRA, 7);
}


static void ADC_prvDISABLE(){
    CLR_BIT(ADCSRA, 7);
}

/**
 * This function is used to read the ADC value for a certain channel without waiting. 
 * 
 * @param Copy_u8Channel represents the channel number.
 * 
 * @param Copy_u8PreScaler represents the prescaler that will be applied to adc clock.
 * 
 * @param Copy_u8Resolution represents the desired adc resolution.
 * 
 * @param Copy_pu16DigitalValue pointer to a u16 to save the ADC reading in it.
 */
void ADC_voidReadChannelAsynch(u8 Copy_u8Channel,u8 Copy_u8PreScaler, u8 Copy_u8Resolution, pu16 Copy_pu16DigitalValue){
    /* setting the channel */
    ADMUX &= ADC_MULTIPLEXER_SELECTION_MASK;
    ADMUX |= Copy_u8Channel;
    Glob_u8Res = Copy_u8Resolution;
    Glob_u16DigitalVal = Copy_pu16DigitalValue;
    /*setting prescaler*/
    ADCSRA &= ADC_PRESCALER_MASK;
    ADCSRA |= Copy_u8PreScaler;
    /* enabling adc */
	ADC_prvENABLE();
	/*enable interrupt */
	SET_BIT(ADCSRA, 3);
    /* start conversion */
    SET_BIT(ADCSRA, 6);

}
/**
 * This function is used to set the callback function for ADC. 
 * 
 * @param ADC_callBackFunc pointer to the callback function.
 * 
 * @return an enum which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus ADC_enuSetCallBackFunc(void (*ADC_callBackFunc)()){
    tenuErrorStatus Local_u8ErrorState = no_error;
    if(ADC_callBackFunc != NULL){
    	ADC_ISR_FUNC = ADC_callBackFunc;
    }
    else {
        Local_u8ErrorState = ERROR_nullPointer;
    }
    return Local_u8ErrorState;
}
void __vector_16 (void) __attribute__((signal));
void __vector_16 (void){
    /* Save ADC reading */
    if (Glob_u8Res == ADC_RESOLUTION_8BIT){
        #if ADC_ADJUST == ADC_RIGHT_ADJUST
            *Copy_pu16DigitalValue = ADCL;
            *Copy_pu16DigitalValue = Copy_pu16DigitalValue >> 2;
            *Copy_pu16DigitalValue |= ADCH << 6;

        #elif ADC_ADJUST == ADC_LEFT_ADJUST
            *Glob_u16DigitalVal = ADCH ;
        #endif
    }else if (Glob_u8Res == ADC_RESOLUTION_16BIT){
        #if ADC_ADJUST == ADC_RIGHT_ADJUST
            *Copy_pu16DigitalValue = ADCL;
            *Copy_pu16DigitalValue |= ADCH << 8;
        #elif ADC_ADJUST == ADC_LEFT_ADJUST
            *Glob_u16DigitalVal = ADCDATA >> 6;
        #endif
    }
    if (ADC_ISR_FUNC != NULL){
    	ADC_ISR_FUNC();
    }

}
