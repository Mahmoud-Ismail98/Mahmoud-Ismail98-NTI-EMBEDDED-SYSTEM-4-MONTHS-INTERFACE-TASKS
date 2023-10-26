#include "std_types.h"
#include "Bit_utils.h" 


#include "ADC.h"
#include "ADC_priv.h"
#include "ADC_cfg.h"


/* Function: ADC_voidInit
 * Description: Initializes the ADC based on configurations in ADC_Config.h.
 */
void ADC_voidInit(void) {
    // Select voltage reference
    #if (VOLTAGE_REFERENCE_SELECTION == AREF)
    CLEAR_BIT(ADMUX, REFS0);
    CLEAR_BIT(ADMUX, REFS1);
    #elif (VOLTAGE_REFERENCE_SELECTION == AVCC_CAPACITOR_AT_AREF)
    SET_BIT(ADMUX, REFS0);
    CLEAR_BIT(ADMUX, REFS1);
    #elif ((VOLTAGE_REFERENCE_SELECTION == INTERNAL_2_56_VOLTAGE_REFERENCE))
    SET_BIT(ADMUX, REFS0);
    SET_BIT(ADMUX, REFS1);
    #else
    #error "Wrong reference selection mode chosen"
    #endif

    // Select ADC conversion form (left or right adjusted)
    #if (ADC_CONVERSION_FORM == LEFT_ADJUSTED)
    SET_BIT(ADMUX, ADLAR);
    #elif (ADC_CONVERSION_FORM == RIGHT_ADJUSTED)
    CLEAR_BIT(ADMUX, ADLAR);
    #else
    #error "Wrong left or right adjust mode chosen"
    #endif

    // Select analog channel and gain reference
    #if (ANALOG_CHANNEL_AND_GAIN_SELECTION_REFERENCE == SEI_ADC0)
    CLEAR_BIT(ADMUX, MUX4);
    CLEAR_BIT(ADMUX, MUX3);
    CLEAR_BIT(ADMUX, MUX2);
    CLEAR_BIT(ADMUX, MUX1);
    CLEAR_BIT(ADMUX, MUX0);
    // Add other cases for different channels and gain references
    #else
    #error "Wrong gain channel mode selected"
    #endif

    // Enable or disable auto-trigger conversions
    #if (ADC_AUTO_TRIGGER_ENABLE == ENABLED)
    SET_BIT(ADCSRA, ADATE);
    #elif (ADC_AUTO_TRIGGER_ENABLE == DISABLED)
    CLEAR_BIT(ADCSRA, ADATE);
    #else
    #error "Wrong auto-trigger mode selected, please select enabled or disabled"
    #endif

    // Enable or disable interrupts that occur after conversion
    #if (ADC_INTERRUPT_ENABLE == ENABLED)
    SET_BIT(ADCSRA, ADIE);
    #elif (ADC_INTERRUPT_ENABLE == DISABLED)
    CLEAR_BIT(ADCSRA, ADIE);
    #else
    #error "Wrong interrupt mode selected, please select enabled or disabled"
    #endif

    // Select the prescaler for the ADC
    #if (ADC_PRESCALER_SET_BITS == DIVISION_FACTOR_2)
    CLEAR_BIT(ADCSRA, ADPS2);
    CLEAR_BIT(ADCSRA, ADPS1);
    CLEAR_BIT(ADCSRA, ADPS0);
    // Add other cases for different prescaler values
    #else
    #error "Wrong prescaler value selected"
    #endif

    // Set the auto-trigger source
    #if (AUTO_TRIGGER_SOURCE == FREE_RUNNING_MODE)
    CLEAR_BIT(SFIOR, ADTS2);
    CLEAR_BIT(SFIOR, ADTS1);
    CLEAR_BIT(SFIOR, ADTS0);
    // Add other cases for different auto-trigger sources
    #else
    #error "Auto trigger wrong source selected, please choose from options in configuration"
    #endif

    // Enable the ADC to start converting
    #if (ADC_ENABLE == ENABLED)
    SET_BIT(ADCSRA, ADEN);
    #elif (ADC_ENABLE == DISABLED)
    CLEAR_BIT(ADCSRA, ADEN);
    #else
    #error "Wrong mode for activating ADC selected, please either enable or disable"
    #endif
}


  
     
	
 
/***************************************************************************************/
/* Function: ADC_u8StartConversionSynchoronus                                       */
/* Description: Initiates a synchronous ADC conversion and waits for its completion. */
/* Input:                                                                      */
/*   copy_u8Channel - The ADC channel to convert.                                 */
/*   Copy_u8Reading - A pointer to store the converted value.                      */
/* Output:                                                                         */
/*   Returns the status of the operation (OK or NOT_OK).                           */
/***************************************************************************************/
u8 ADC_u8StartConversionSynchoronus(u8 copy_u8Channel, u8* Copy_u8Reading) 
{
    u32 Local_u32Counter = 0;
    u8 Local_u8ErrorState = OK;

    if (ADC_u8BusyState == IDLE)
    {
        /* ADC is Now Busy */
        ADC_u8BusyState = BUSY;

        /* Clear The MUX BITS in ADMUX Register */
        ADMUX &= 0b11100000;
        
        /* Set The Required Channel Into The MUX Bits */
        ADMUX |= copy_u8Channel;

        /* Start Conversion */
        SET_BIT(ADCSRA, ADCSRA_ADSC);

        /* Polling (busy waiting) until the conversion complete Flag Is set or Counter Reaches Time Out */
        while ((GET_BIT(ADCSRA, ADCSRA_ADIF == 0)) && (Local_u32Counter != ADC_u32TimeOUT))
        {
            Local_u32Counter++;
        }

        /* Clear The Conversion Complete Flag */
        if (Local_u32Counter == ADC_u32TimeOUT)
        {
            /* Loop is broken because the timeout is reached */
            Local_u8ErrorState = NOT_OK;
        }
        else
        {
            /* Loop is broken because the flag is raised */
            SET_BIT(ADCSRA, ADCSRA_ADIF);
            
            /* Return the reading */
            *Copy_u8Reading = ADC;
            
            /* ADC is finished, return to IDLE */
            ADC_u8BusyState = IDLE;
        }
    }
    else
    {
        Local_u8ErrorState = BUSY_FUNCTION;
    }

    return Local_u8ErrorState;
}


/***************************************************************************************/
/* Function: ADC_u8StartConversionASynchronous                                       */
/* Description: Initiates an asynchronous ADC conversion and sets a callback function */
/* to be executed when the conversion is complete.                                   */
/* Input:                                                                        */
/*   copy_u8Channel - The ADC channel to convert.                                  */
/*   Copy_pu8Reading - A pointer to store the converted value.                     */
/*   copy_pvNotificationFunc - A callback function to be executed upon completion.  */
/* Output:                                                                         */
/*   Returns the status of the operation (OK or NOT_OK).                           */
/***************************************************************************************/
u8 ADC_u8StartConversionASynchronous(u8 copy_u8Channel, u8* Copy_pu8Reading, void (*copy_pvNotificationFunc)(void)) 
{
    u8 Local_u8ErrorStatus = OK;

    if (Copy_pu8Reading == NULL || copy_pvNotificationFunc == NULL)
    {
        Local_u8ErrorStatus = NOT_OK;
    }
    else
    {
        /* Initialize the Reading Value Globally */
        ADC_pu8Reading = Copy_pu8Reading;

        /* Initialize the Callback Function Global */
        ADC_pvCallBackNotificationFunc = copy_pvNotificationFunc;

        /* Clear The MUX BITS in ADMUX Register */
        ADMUX &= 0b11100000;

        /* Set the required Channel into the MUX bits */
        ADMUX |= copy_u8Channel;

        /* Start Conversion */
        SET_BIT(ADCSRA, ADCSRA_ADSC);
        
        /* Enable ADC Conversion Complete Interrupt */
        SET_BIT(ADCSRA, ADCSRA_ADIE);
    }

    return Local_u8ErrorStatus;
}





/***************************************************************************************/
/* Description: Interrupt Service Routine (ISR) for ADC conversion complete.        */
/* This ISR reads the ADC result, invokes the callback function, and disables the   */
/* ADC conversion complete interrupt.                                               */
/* Input: None                                                                   */
/* Output: None                                                                  */
/***************************************************************************************/
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
    /* Read ADC Result */
    *ADC_pu8Reading = ADC;
    
    /* Invoke callback notification function */
    ADC_pvCallBackNotificationFunc();
    
    /* Disable ADC Conversion Complete Interrupt */
    CLR_BIT(ADCSRA, ADCSRA_ADIE);
}









