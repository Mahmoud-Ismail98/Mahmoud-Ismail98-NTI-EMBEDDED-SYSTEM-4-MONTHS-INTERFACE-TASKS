/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 23 Oct 2023                                                           */
/************************************************************************************/
#include "../../../LIB/Include/STD_TYPES.h"
#include "../../../LIB/Include/BIT_MATH.h"

#include "../Include/ADC_interface.h"
#include "../Include/ADC_private.h"
#include "../Include/ADC_config.h"

/* global busy flag */
u8 ADC_u8Flag = 0;
/* global read variable */
u16 ADC_u16Result;
/* global pointer to function */
void (*ADC_pf)(void);

void ADC_voidInit(void)
{
    /* to set the prescaler => choosing prescaler 8MHz/64 */
    CLR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADPS0_BIT);
    SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADPS1_BIT);
    SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADPS2_BIT);
    /* to configure which voltage input to ADC */
    #if   ADC_u8_VOLTAGE == ADC_INT_VOLT // Internal Volt on MC 2.56
        SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_REFS0_BIT);
        SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_REFS1_BIT);
    #elif ADC_u8_VOLTAGE == ADC_REF_VOLT // Ref Volt in AREF Pin
        CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_REFS0_BIT);
        CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_REFS1_BIT);
    #elif ADC_u8_VOLTAGE == ADC_VCC_VOLT // Vcc volt 5v
        SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_REFS0_BIT);
        CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_REFS1_BIT);
    #endif
    /* to configure the adjust */
    #if   ADC_u8_ADJUSR == ADC_RIGHT_ADJUST // Right Adjust
        CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADLAR_BIT);
    #elif ADC_u8_ADJUSR == ADC_LEFT_ADJUST // Left Adjust
        SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADLAR_BIT);
    #endif
    /* to configure the mode of the ADC */
    #if   ADC_u8_MODE == ADC_SINGLE_MODE
        CLR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADATE_BIT);
    #elif ADC_u8_MODE == ADC_FREE_RUNNING_MODE
        SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADATE_BIT);
        CLR_BIT(ADC_u8_SFIOR_REG,ADC_u8_ADTS0_BIT);
        CLR_BIT(ADC_u8_SFIOR_REG,ADC_u8_ADTS1_BIT);
        CLR_BIT(ADC_u8_SFIOR_REG,ADC_u8_ADTS2_BIT);
    #endif
    /* Enable the ADC */
    SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADEN_BIT);
}

ADCEnum ADC_ADCEnumReadSync(u8 copy_u8Channel,pu16 copy_pu16DigitalValue)
{
    ADCEnum local_ADCEnumErrorState = ADC_Read_OK;
    u16 local_u16TimeOut = 0;
    /* check about input parameters */
    if((copy_u8Channel <= ADC_CHANNEL_7) && (copy_pu16DigitalValue != NULL))
    {
        /* to save the selection of the voltage and the adjust on ADMUX register */
        ADC_u8_ADMUX_REG &= 0b11100000;
        /* then update the channel number in the register */
        ADC_u8_ADMUX_REG |= copy_u8Channel;
        /* to start conversion */
        SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADSC_BIT);
        /* Polling Nonblocking Mechanism while the conversion is completed */
        while((GET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADIF_BIT)==0) && (local_u16TimeOut < ADC_TIMEOUT_MECHANISM ))
        {
            local_u16TimeOut++;
        }
        /* check about flag */
        if(GET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADIF_BIT)==1) // flag is set
        {
            /* clear the flag of conversion completed */
            SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADIF_BIT);
            /* read the digital value */
            *copy_pu16DigitalValue = ADC_u16_ADC_REG;
        }
        else
        {
            local_ADCEnumErrorState = ADC_Read_NOK;
        }
    }
    else
    {
        local_ADCEnumErrorState = ADC_Read_NOK;
    }
    return local_ADCEnumErrorState;
}

ADCEnum ADC_ADCEnumReadAsync(u8 copy_u8Channel,pu16 copy_pu16DigitalValue,void (*copy_pf)(void))
{
    ADCEnum local_ADCEnumErrorState = ADC_Read_OK;
    /* check about input parameters and the global busy flag */
    if((copy_u8Channel <= ADC_CHANNEL_7) && (copy_pu16DigitalValue != NULL) && (copy_pu16DigitalValue != NULL) && (ADC_u8Flag == 0))
    {
        /* set the busy flag */
        ADC_u8Flag = 1;
        /* update the global pointer to function */
        ADC_pf = copy_pf;
        /* to save the selection of the voltage and the adjust on ADMUX register */
        ADC_u8_ADMUX_REG &= 0b11100000;
        /* then update the channel number in the register */
        ADC_u8_ADMUX_REG |= copy_u8Channel;
        /* enable the ADC interrupt */
        SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADIE_BIT);
        /* to start conversion */
        SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADSC_BIT);
        *copy_pu16DigitalValue = ADC_u16Result;
    }
    else
    {
        local_ADCEnumErrorState = ADC_Read_NOK;
    }
    return local_ADCEnumErrorState;
}

/* ISR function for ADC */
void __vector_16(void)     __attribute__((signal));
void __vector_16(void)
{
    /* read the digital value  */
    ADC_u16Result = ADC_u16_ADC_REG;
    /* clear the busy flag */
    ADC_u8Flag = 0;
    /* clear the interrupt */
    CLR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADIE_BIT);
    /* call the global pointer to function */
    ADC_pf();
}

