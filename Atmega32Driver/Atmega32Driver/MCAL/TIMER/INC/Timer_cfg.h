/*
 * TIMER_cfg.h
 *
 * Created: 10/24/2023 11:35:38 AM
 *  Author: FADY
 */

#ifndef TIMER_CFG
#define TIMER_CFG


#define TIMER0_u8_PRELOAD_VALUE             156
#define TIMER_u8_OCR0_INIT_VALUE            155;






/* Timer 0 Mode Config */
/* Options = TIMER0_NORMAL_MODE
             TIMER0_PHASE_CORRECT_PWM
             TIMER0_CTC_MODE
             TIMER0_FAST_PWM          */

#define TIMER0_MODE              TIMER0_CTC_MODE

/* Timer 0 Interrupt Enable */
/* options = TIMER_INTERRUPT_ENABLE
             TIMER_INTERRUPT_DISABLE */
#define TIMER0_OVF_INTERRUPT_INIT    TIMER_INTERRUPT_DISABLE
#define TIMER0_CTC_INTERRUPT_INIT    TIMER_INTERRUPT_ENABLE

#define TIMER1_OVF_INTERRUPT_INIT    TIMER_INTERRUPT_DISABLE
#define TIMER1_CTC_INTERRUPT_INIT    TIMER_INTERRUPT_ENABLE

/* Timer  Prescaler values */
/* options = 
             TIMER_CLOCK_NO_PRESCHALER
             TIMER_CLOCK_8_PRESCHALER
             TIMER_CLOCK_64_PRESCHALER
             TIMER_CLOCK_256_PRESCHALER
             TIMER_CLOCK_1024_PRESCHALER
             TIMER_CLOCK_EXTERNAL_FALLING_EDGE
             TIMER_CLOCK_EXTERNAL_RISING_EDGE	 */
#define TIMER0_CLOCK_SOURCE          TIMER_CLOCK_1024_PRESCHALER
#define TIMER1_CLOCK_SOURCE          TIMER_CLOCK_8_PRESCHALER

/* OCX pin Config Macros */
/* Options :TIMER_u8_OCX_DISCONNECTED
            TIMER_u8_OCX_TOGGELE
            TIMER_u8_OCX_SET
            TIMER_u8_OCX_CLEAR        */
#define TIMER_u8_OC0_PIN_MODE        TIMER_u8_OCX_CLEAR







#endif