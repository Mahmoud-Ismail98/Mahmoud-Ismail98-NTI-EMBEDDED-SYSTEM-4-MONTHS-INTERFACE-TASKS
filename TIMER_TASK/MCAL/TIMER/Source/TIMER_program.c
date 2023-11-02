/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 24 Oct 2023                                                           */
/************************************************************************************/

#include "../../../LIB/Include/STD_TYPES.h"
#include "../../../LIB/Include/BIT_MATH.h"

#include "../Include/TIMER_interface.h"
#include "../Include/TIMER_private.h"
#include "../Include/TIMER_config.h"

/* Global Preload Value */
u8 TIMER0_u8PreloadValue = TIMER0_u8_PRELOAD_VALUE;
u16 TIMER1_u16PreloadValue = TIMER1_u16_PRELOAD_VALUE;
/* Global Time of OVF */
u32 TIMER0_u32OVFTime;
/* Global Pointer to Function => Timer0 */
static void (*TIMER_ApfTimer0[2])(void);

/* Global Pointer to Function => Timer0 */
static void (*TIMER_ApfTimer1[2])(void);

TIMEREnum TIMER_TIMEREnumTimer0Init(u8 copy_u8TimerMode)
{
    TIMEREnum local_TIMEREnumErrorState = TIMER_OK;
    /* check about input parameters */
    if(copy_u8TimerMode <= TIMER_PHASE_CORR_MODE)
    {
        /* to configure which mode you need */
        switch(copy_u8TimerMode)
        {
            case TIMER_NORMAL_MODE    :  // In the normal Mode
            /* set the generation mode */
            CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM00_BIT);
            CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM01_BIT);
            /* configuration of the compare output mode  => OC HW Pin */
            #if   TIMER_NORM_CTC_MODE == TIMER_NORMAL_PORT  // Normal Port => OC disconnected
                CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00_BIT);
                CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01_BIT);
            #elif TIMER_NORM_CTC_MODE == TIMER_TOG_ON_CMATCH  // Togle OC on compare match
                SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00_BIT);
                CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01_BIT);
            #elif TIMER_NORM_CTC_MODE == TIMER_CLR_ON_CMATCH  // Clear OC on compare match
                CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00_BIT);
                SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01_BIT);
            #elif TIMER_NORM_CTC_MODE == TIMER_SET_ON_CMATCH  // Set OC on compare match
                SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00_BIT);
                SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01_BIT);
            #endif
            /* Update the preload Value */
            TIMER0_u8_TCNT0_REG = TIMER0_u8_PRELOAD_VALUE;
            /* Enable OVF Interrupt */
            SET_BIT(TIMER0_u8_TIMSK_REG,TIMER0_u8_TOIE0_BIT);
            break;
            case TIMER_CTC_MODE       :  // In the CTC Mode
            /* set the generation mode */
            CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM00_BIT);
            SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM01_BIT);
            /* configuration of the compare output mode  => OC HW Pin */
            #if   TIMER_NORM_CTC_MODE == TIMER_NORMAL_PORT  // Normal Port => OC disconnected
                CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00_BIT);
                CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01_BIT);
            #elif TIMER_NORM_CTC_MODE == TIMER_TOG_ON_CMATCH  // Togle OC on compare match
                SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00_BIT);
                CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01_BIT);
            #elif TIMER_NORM_CTC_MODE == TIMER_CLR_ON_CMATCH  // Clear OC on compare match
                CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00_BIT);
                SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01_BIT);
            #elif TIMER_NORM_CTC_MODE == TIMER_SET_ON_CMATCH  // Set OC on compare match
                SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00_BIT);
                SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01_BIT);
            #endif
            /* Update the compare match Value */
            TIMER0_u8_OCR0_REG = TIMER0_u8_COMPMATCH_VALUE;
            /* Enable Compare Match Interrupt */
            SET_BIT(TIMER0_u8_TIMSK_REG,TIMER0_u8_OCIE0_BIT);
            break;
            case TIMER_FAST_PWM_MODE  :  // IN the Fast PWM Mode
            /* set the generation mode */
            SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM00_BIT);
            SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM01_BIT);
            /* configuration of the compare output mode  => OC HW Pin */
            #if   TIMER_FAST_PHASE_MODE == TIMER_NORM_PORT  // Normal Port => OC disconnected
                CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00_BIT);
                CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01_BIT);
            #elif TIMER_FAST_PHASE_MODE == TIMER_NON_INVERTING  // non_inverting mode
                CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00_BIT);
                SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01_BIT);
            #elif TIMER_FAST_PHASE_MODE == TIMER_INVRTING  // inverting mode
                SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00_BIT);
                SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01_BIT);
            #endif
            break;
            case TIMER_PHASE_CORR_MODE:  // In the Phase Correct Mode
            /* set the generation mode */
            SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM00_BIT);
            CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_WGM01_BIT);
            /* configuration of the compare output mode  => OC HW Pin */
            #if   TIMER_FAST_PHASE_MODE == TIMER_NORM_PORT  // Normal Port => OC disconnected
                CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00_BIT);
                CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01_BIT);
            #elif TIMER_FAST_PHASE_MODE == TIMER_NON_INVERTING  // non_inverting mode
                CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00_BIT);
                SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01_BIT);
            #elif TIMER_FAST_PHASE_MODE == TIMER_INVRTING  // inverting mode
                SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM00_BIT);
                SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_COM01_BIT);
            #endif
            break;
        }
        /* configuration of the prescaler */
        #if   TIMER_CLK_PRESCALER == TIMER_NO_PRESCALING  // No prescaling
            SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00_BIT);
            CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01_BIT);
            CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02_BIT);
        #elif TIMER_CLK_PRESCALER == TIMER_CLK_8_PRESCALING  // prescaling 8 => F_CPU/8
            CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00_BIT);
            SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01_BIT);
            CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02_BIT);
        #elif TIMER_CLK_PRESCALER == TIMER_CLK_64_PRESCALING  // prescaling 64 => F_CPU/64
            SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS00_BIT);
            SET_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS01_BIT);
            CLR_BIT(TIMER0_u8_TCCR0_REG,TIMER0_u8_CS02_BIT);
        #endif
    }
    else
    {
        local_TIMEREnumErrorState = TIMER0_INIT_NOK; 
    }
    return local_TIMEREnumErrorState;
}

TIMEREnum TIMER_TIMEREnumTimer0Callback(u8 copy_u8TimerMode,void (*copy_pfTimer0)(void))
{
    TIMEREnum local_TIMEREnumErrorState = TIMER_OK;
    /* check about input parameters */
    if((copy_u8TimerMode <= TIMER_CTC_MODE) && (copy_pfTimer0 != NULL))
    {
        /* Update the Global Pointer to Function */
        TIMER_ApfTimer0[copy_u8TimerMode] = copy_pfTimer0;
    }
    else
    {
        local_TIMEREnumErrorState = TIMER0_CALL_NOK; 
    }
    return local_TIMEREnumErrorState;
}

TIMEREnum TIMER_TIMEREnumTimer0SetCompMatchValue (u8 copy_u8Value)
{
    TIMEREnum local_TIMEREnumErrorState = TIMER_OK;
    /* check about input parameters */
    if(copy_u8Value <= 255)
    {
        /* update the value of compare match in OCR0 register */
        TIMER0_u8_OCR0_REG = copy_u8Value;
    }
    else
    {
        local_TIMEREnumErrorState = TIMER0_CMATCH_NOK; 
    }
    return local_TIMEREnumErrorState;
}
/*========================================================================================*/
TIMEREnum TIMER_TIMEREnumTimer1Init(u8 copy_u8TimerMode)
{
    TIMEREnum local_TIMEREnumErrorState = TIMER_OK;
    /* check about input parameters */
    if(copy_u8TimerMode <= TIMER_PHASE_CORR_MODE)
    {
        /* to configure which mode you need */
        switch(copy_u8TimerMode)
        {
            case TIMER_NORMAL_MODE    :  // In the normal Mode
            /* set the generation mode */
            CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_WGM10_BIT);
            CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_WGM11_BIT);
            CLR_BIT(TIMER1_u8_TCCR1B_REG,TIMER1_u8_WGM12_BIT);
            CLR_BIT(TIMER1_u8_TCCR1B_REG,TIMER1_u8_WGM13_BIT);
            /* configuration of the compare output mode  => OC HW Pin */
            #if   TIMER_NORM_CTC_MODE == TIMER_NORMAL_PORT  // Normal Port => OC disconnected
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B0_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A0_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B1_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A1_BIT);
            #elif TIMER_NORM_CTC_MODE == TIMER_TOG_ON_CMATCH  // Togle OC on compare match
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B0_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A0_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B1_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A1_BIT);
            #elif TIMER_NORM_CTC_MODE == TIMER_CLR_ON_CMATCH  // Clear OC on compare match
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B0_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A0_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B1_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A1_BIT);
            #elif TIMER_NORM_CTC_MODE == TIMER_SET_ON_CMATCH  // Set OC on compare match
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B0_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A0_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B1_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A1_BIT);
            #endif
            /* Update the preload Value */
            TIMER1_u16_TCNT1_REG = TIMER1_u16_PRELOAD_VALUE;
            /* Enable OVF Interrupt */
            SET_BIT(TIMER0_u8_TIMSK_REG,TIMER1_u8_TOIE1_BIT);
            break;
            case TIMER_CTC_MODE       :  // In the CTC Mode
            /* set the generation mode */
            CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_WGM10_BIT);
            CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_WGM11_BIT);
            SET_BIT(TIMER1_u8_TCCR1B_REG,TIMER1_u8_WGM12_BIT);
            CLR_BIT(TIMER1_u8_TCCR1B_REG,TIMER1_u8_WGM13_BIT);
            /* configuration of the compare output mode  => OC HW Pin */
            #if   TIMER_NORM_CTC_MODE == TIMER_NORMAL_PORT  // Normal Port => OC disconnected
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B0_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A0_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B1_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A1_BIT);
            #elif TIMER_NORM_CTC_MODE == TIMER_TOG_ON_CMATCH  // Togle OC on compare match
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B0_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A0_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B1_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A1_BIT);
            #elif TIMER_NORM_CTC_MODE == TIMER_CLR_ON_CMATCH  // Clear OC on compare match
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B0_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A0_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B1_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A1_BIT);
            #elif TIMER_NORM_CTC_MODE == TIMER_SET_ON_CMATCH  // Set OC on compare match
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B0_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A0_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B1_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A1_BIT);
            #endif
            /* Update the compare match Value */
            TIMER1_u16_OCR1A_REG = TIMER1_u16_COMPMATCH_VALUE_A;
            TIMER1_u16_OCR1B_REG = TIMER1_u16_COMPMATCH_VALUE_B;
            /* Enable Compare Match Interrupt at A and B */
            SET_BIT(TIMER0_u8_TIMSK_REG,TIMER1_u8_OCIE1A_BIT);
            SET_BIT(TIMER0_u8_TIMSK_REG,TIMER1_u8_OCIE1B_BIT);
            break;
            case TIMER_FAST_PWM_MODE  :  // IN the Fast PWM Mode
            /* set the generation mode */
            CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_WGM10_BIT);
            SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_WGM11_BIT);
            SET_BIT(TIMER1_u8_TCCR1B_REG,TIMER1_u8_WGM12_BIT);
            SET_BIT(TIMER1_u8_TCCR1B_REG,TIMER1_u8_WGM13_BIT);
            /* configuration of the compare output mode  => OC HW Pin */
            #if   TIMER_FAST_PHASE_MODE == TIMER_NORM_PORT  // Normal Port => OC disconnected
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B0_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A0_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B1_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A1_BIT);
            #elif TIMER_FAST_PHASE_MODE == TIMER_NON_INVERTING  // non_inverting mode
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B0_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A0_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B1_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A1_BIT);
            #elif TIMER_FAST_PHASE_MODE == TIMER_INVRTING  // inverting mode
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B0_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A0_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B1_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A1_BIT);
            #endif
            break;
            case TIMER_PHASE_CORR_MODE:  // In the Phase Correct Mode
            /* set the generation mode */
            CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_WGM10_BIT);
            SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_WGM11_BIT);
            CLR_BIT(TIMER1_u8_TCCR1B_REG,TIMER1_u8_WGM12_BIT);
            SET_BIT(TIMER1_u8_TCCR1B_REG,TIMER1_u8_WGM13_BIT);
            /* configuration of the compare output mode  => OC HW Pin */
            #if   TIMER_FAST_PHASE_MODE == TIMER_NORM_PORT  // Normal Port => OC disconnected
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B0_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A0_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B1_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A1_BIT);
            #elif TIMER_FAST_PHASE_MODE == TIMER_NON_INVERTING  // non_inverting mode
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B0_BIT);
                CLR_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A0_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B1_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A1_BIT);
            #elif TIMER_FAST_PHASE_MODE == TIMER_INVRTING  // inverting mode
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B0_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A0_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1B1_BIT);
                SET_BIT(TIMER1_u8_TCCR1A_REG,TIMER1_u8_COM1A1_BIT);
            #endif
            break;
        }
        /* configuration of the prescaler */
        #if   TIMER_CLK_PRESCALER == TIMER_NO_PRESCALING  // No prescaling
            SET_BIT(TIMER1_u8_TCCR1B_REG,TIMER1_u8_CS10_BIT);
            CLR_BIT(TIMER1_u8_TCCR1B_REG,TIMER1_u8_CS11_BIT);
            CLR_BIT(TIMER1_u8_TCCR1B_REG,TIMER1_u8_CS12_BIT);
        #elif TIMER_CLK_PRESCALER == TIMER_CLK_8_PRESCALING  // prescaling 8 => F_CPU/8
            CLR_BIT(TIMER1_u8_TCCR1B_REG,TIMER1_u8_CS10_BIT);
            SET_BIT(TIMER1_u8_TCCR1B_REG,TIMER1_u8_CS11_BIT);
            CLR_BIT(TIMER1_u8_TCCR1B_REG,TIMER1_u8_CS12_BIT);
        #elif TIMER_CLK_PRESCALER == TIMER_CLK_64_PRESCALING  // prescaling 64 => F_CPU/64
            SET_BIT(TIMER1_u8_TCCR1B_REG,TIMER1_u8_CS10_BIT);
            SET_BIT(TIMER1_u8_TCCR1B_REG,TIMER1_u8_CS11_BIT);
            CLR_BIT(TIMER1_u8_TCCR1B_REG,TIMER1_u8_CS12_BIT);
        #endif
    }
    else
    {
        local_TIMEREnumErrorState = TIMER1_INIT_NOK; 
    }
    return local_TIMEREnumErrorState;
}

TIMEREnum TIMER_TIMEREnumTimer1Callback(u8 copy_u8TimerMode,void (*copy_pfTimer1)(void))
{
    TIMEREnum local_TIMEREnumErrorState = TIMER_OK;
    /* check about input parameters */
    if((copy_u8TimerMode <= TIMER_CTC_MODE) && (copy_pfTimer1 != NULL))
    {
        /* Update the Global Pointer to Function */
        TIMER_ApfTimer1[copy_u8TimerMode] = copy_pfTimer1;
    }
    else
    {
        local_TIMEREnumErrorState = TIMER1_CALL_NOK; 
    }
    return local_TIMEREnumErrorState;
}

TIMEREnum TIMER_TIMEREnumTimer1SetCompMatchValue (u16 copy_u16CompValueA,u16 copy_u16CompValueB,u16 copy_u16ICR1Value)
{
    TIMEREnum local_TIMEREnumErrorState = TIMER_OK;
    /* check about input parameters */
    if((copy_u16CompValueA <= 655535) && (copy_u16ICR1Value <= 65535) && (copy_u16CompValueB <= 655535))
    {
        /* update the value of compare match and ICR */
        TIMER1_u16_OCR1A_REG = copy_u16CompValueA;
        TIMER1_u16_OCR1B_REG = copy_u16CompValueB;
        TIMER1_u16_ICR1_REG = copy_u16ICR1Value;
    }
    else
    {
        local_TIMEREnumErrorState = TIMER1_CMATCH_NOK; 
    }
    return local_TIMEREnumErrorState;
}

/* ISR function for Timer0 => OVF */
void __vector_11(void)           __attribute__((signal));
void __vector_11(void) 
{
    /* define static counter */
    static u16 local_u16Counter = 0;
    local_u16Counter++;
    if(local_u16Counter == TIMER0_u32_NORMAL_NO_OVF)
    {
        /* clear the counter */
        local_u16Counter = 0;
        if(TIMER0_u8PreloadValue != 0)
        {
            /* Update the preload Value */
            TIMER0_u8_TCNT0_REG = TIMER0_u8PreloadValue;
        }
        /* chech about global pointer to function != NULL */
        if(TIMER_ApfTimer0[TIMER_NORMAL_MODE] != NULL)
        {
            /* call the global pointer to function */
            TIMER_ApfTimer0[TIMER_NORMAL_MODE]();
        }
    }
}

/* ISR function for Timer0 => Comp Match */
void __vector_10(void)           __attribute__((signal));
void __vector_10(void) 
{
    /* define static counter */
    static u16 local_u16Counter = 0;
    local_u16Counter++;
    if(local_u16Counter == TIMER0_u32_CTC_NO_OVF)
    {
        /* clear the counter */
        local_u16Counter = 0;
        if(TIMER0_u8PreloadValue != 0)
        {
            /* Update the preload Value */
            TIMER0_u8_TCNT0_REG = TIMER0_u8PreloadValue;
        }
        /* chech about global pointer to function != NULL */
        if(TIMER_ApfTimer0[TIMER_CTC_MODE] != NULL)
        {
            /* call the global pointer to function */
            TIMER_ApfTimer0[TIMER_CTC_MODE]();
        }
    }
}

/* ISR function for Timer1 => OVF */
void __vector_9(void)           __attribute__((signal));
void __vector_9(void) 
{
    /* define static counter */
    static u16 local_u16Counter = 0;
    local_u16Counter++;
    if(local_u16Counter == TIMER1_u32_NORMAL_NO_OVF)
    {
        /* clear the counter */
        local_u16Counter = 0;
        if(TIMER1_u16PreloadValue != 0)
        {
            /* Update the preload Value */
            TIMER1_u16_TCNT1_REG = TIMER1_u16_PRELOAD_VALUE;
        }
        /* chech about global pointer to function != NULL */
        if(TIMER_ApfTimer1[TIMER_NORMAL_MODE] != NULL)
        {
            /* call the global pointer to function */
            TIMER_ApfTimer1[TIMER_NORMAL_MODE]();
        }
    }
}

/* ISR function for Timer1 => Comp Match */
void __vector_7(void)           __attribute__((signal));
void __vector_7(void) 
{
    /* define static counter */
    static u16 local_u16Counter = 0;
    local_u16Counter++;
    if(local_u16Counter == TIMER1_u32_CTC_NO_OVF)
    {
        /* clear the counter */
        local_u16Counter = 0;
        /* chech about global pointer to function != NULL */
        if(TIMER_ApfTimer1[TIMER_CTC_MODE] != NULL)
        {
            /* call the global pointer to function */
            TIMER_ApfTimer1[TIMER_CTC_MODE]();
        }
    }
}
