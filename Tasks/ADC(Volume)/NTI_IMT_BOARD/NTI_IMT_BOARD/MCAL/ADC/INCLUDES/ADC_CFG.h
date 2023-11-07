/*
 * ADC_CFG.h
 *
 * Created: 10/26/2023 6:43:41 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef ADC_CFG_H_
#define ADC_CFG_H_

/*ADC INTERRUPT [1]ENABLE/[0]DISABLE*/

#define  ADC_INTERRUPT_ENABLE 0


/*ADC VOLTAGE REFERENCE OPTIONS    [1]ENABLE/[0]DISABLE */
#define ADC_AREF_INTERNAL_VrefOFF             0
#define ADC_AVCC_WITH_CAP_AT_AREF             1
#define ADC_INTERNAL_2_56V_WITH_CAP_AT_AREF   0

/*ADC DATA REGISTER ADJUSTMENT OPTIONS [1]Enable/[0]Disable*/
#define  ADC_LEFT_ADJUST          0
#define  ADC_RIGHT_ADJUST         1

/*ADC PRESCALER OPTIONS [1]Enable/[0]Disable*/

#define ADC_PRESCALE_2        0  // 1/2 PRESCALE IS MAX SPEED
#define ADC_PRESCALE_4        0   // 1/4 PRESCALE
#define ADC_PRESCALE_8        0   // 1/8 PRESCALE
#define ADC_PRESCALE_16       0	  // 1/16 PRESCALE
#define ADC_PRESCALE_32       0	  // 1/32 PRESCALE
#define ADC_PRESCALE_64		  1  // 1/64 PRESCALE
#define ADC_PRESCALE_128      0  // RECOMMENDED FOR 10BIT RESOLUTION MODE WITH 16MHZ CLOCK FREQ

/*ADC AUTO TRIGGER SOURCE [1]Enable/[0]Disable */

#define ADC_Free_Running_Mode					1
#define ADC_Analog_Comparator					0
#define ADC_External_Interrupt_Request0         0
#define ADC_TIMER0_COMPARE_MATCH				0
#define ADC_TIMER0_OVERFLOW						0
#define ADC_TIMER_COMPARE_MATCH_B				0
#define ADC_TIMER1_OverFlow						0
#define ADC_TIMER1_CAPTURE_EVENT				0

#endif /* ADC_CFG_H_ */