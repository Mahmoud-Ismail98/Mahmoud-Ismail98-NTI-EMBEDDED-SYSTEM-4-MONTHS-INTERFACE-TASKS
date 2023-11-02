#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

//Here you can choose your operating mode you can choose between the following
/*NORMAL_MODE
 * PWM_PHASE_CORRECT_MODE
 * CTC_MODE //capture compare
 * FAST_PWM_MODE
 */
#define OPERATING_MODE NORMAL_MODE


//Here you can choose your operating mode in compare output, you can choose between the following
/*NORMAL_COMPARE_OUTPUT
 * TOGGLE_OC0_ON_COMPARE_MATCH
 * SET_OC0_ON_COMPARE_MATCH
 * CLEAR_OC0_ON_COMPARE_MATCH
 */
#define COMPARE_OUTPUT_NO_PWM_MODE NORMAL_COMPARE_OUTPUT


//Here you can choose your operating mode in fast pwm mode, you can choose between the following
/*NORMAL_OUTPUT
 * SET_OC0_ON_COMPARE_MATCH
 * CLEAR_OC0_ON_COMPARE_MATCH
 */
#define COMPARE_OUTPUT_FAST_PWM_MODE NORMAL_OUTPUT


//Here you can choose your operating mode in phase correct mode, you can choose between the following
/*NORMAL_OUTPUT
 * SET_OC0_DOWNCOUNT_CLEAR_UPCOUNT
 * CLEAR_OC0_DOWNCOUNT_SET_UPCOUNT
 */
#define COMPARE_OUTPUT_PHASE_CORRECT_PWM_MODE NORMAL_OUTPUT


//Here you can choose your prescaler value
/*NO_CLK
 *CLK_1
 *CLK_8
 *CLK_64
 *CLK_256
 *CLK_1024
 *EXTERNAL_ON_T0_COUNT_ON_FALLING_EDGE
 *EXTERNAL_ON_T0_COUNT_ON_RISING_EDGE
 */
#define CLOCK_PRESCALER_SELECT CLK_64
#endif /* TIMER0_CONFIG_H_ */