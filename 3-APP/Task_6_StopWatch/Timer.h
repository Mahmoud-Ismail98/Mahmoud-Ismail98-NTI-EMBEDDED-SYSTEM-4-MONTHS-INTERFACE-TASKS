/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : Timer               **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
/*****************************************************************************/
/*******************************    TIMER 0    *******************************/
/*****************************************************************************/
/*****************************************************************************/
/*timer 0 modes*/
#define TIMER_0_MODE_NORMAL                         1
#define TIMER_0_MODE_PWM_PHASE_CORRECT              2
#define TIMER_0_MODE_CTC                            3
#define TIMER_0_MODE_FAST_PWM                       4

/*oc0 modes*/
#define OC0_MODE_NORMAL_PORT                        1
#define OC0_MODE_TOGGLE_ON_CTC                      2
#define OC0_MODE_CLEAR_ON_CTC_NON_INV               3
#define OC0_MODE_SET_ON_CTC_INV                     4

/*Timer0 Interrupt macros*/
#define TIMER_0_INTERRUPT_MODE_DISABLE              0
#define TIMER_0_INTERRUPT_MODE_ENABLE_OVERFLOW      1
#define TIMER_0_INTERRUPT_MODE_ENABLE_CTC           2
#define TIMER_0_INTERRUPT_MODE_ENABLE_OVERFLOW_CTC  3

/*Timer0 Clock Prescaler macros*/
#define TIMER_0_CLOCK_MODE_NO_CLOCK                 0
#define TIMER_0_CLOCK_MODE_NO_PRESCALER             1
#define TIMER_0_CLOCK_MODE_8_PRESCALER              2
#define TIMER_0_CLOCK_MODE_64_PRESCALER             3
#define TIMER_0_CLOCK_MODE_256_PRESCALER            4
#define TIMER_0_CLOCK_MODE_1024_PRESCALER           5
#define TIMER_0_CLOCK_MODE_EXT_ON_T0_Falling        6
#define TIMER_0_CLOCK_MODE_EXT_ON_T0_Rising         7
typedef struct {

    /*Options : 
        TIMER_0_MODE_NORMAL           
        TIMER_0_MODE_PWM_PHASE_CORRECT
        TIMER_0_MODE_CTC              
        TIMER_0_MODE_FAST_PWM         
    */
    u8 TIMER_0_MODE;

    /*Options : 
        OC0_MODE_NORMAL_PORT                     
        OC0_MODE_TOGGLE_ON_CTC                   
        OC0_MODE_CLEAR_ON_CTC_NON_INV                    
        OC0_MODE_SET_ON_CTC_INV                      
    */
    u8 OC0_MODE;
    /*Options : 
        TIMER_0_INTERRUPT_MODE_DISABLE             
        TIMER_0_INTERRUPT_MODE_ENABLE_OVERFLOW     
        TIMER_0_INTERRUPT_MODE_ENABLE_CTC
        TIMER_0_INTERRUPT_MODE_ENABLE_OVERFLOW_CTC 
    */
    u8 TIMER_0_INTERRUPT_MODE;

    /*Options : 
        TIMER_0_CLOCK_MODE_NO_CLOCK           
        TIMER_0_CLOCK_MODE_NO_PRESCALER       
        TIMER_0_CLOCK_MODE_8_PRESCALER        
        TIMER_0_CLOCK_MODE_64_PRESCALER       
        TIMER_0_CLOCK_MODE_256_PRESCALER      
        TIMER_0_CLOCK_MODE_1024_PRESCALER     
        TIMER_0_CLOCK_MODE_EXT_ON_T0_Falling  
        TIMER_0_CLOCK_MODE_EXT_ON_T0_Rising   
    */
    u8 CLOCK_MODE;

} Timer0_cfg;

/**
 * This function is used to Initialize Timer0. 
 * 
 * @param prt_TIMER0_CFG a pointer to struct that represents the timer configuration.
 */
void TIMER_0_voidInit(Timer0_cfg * prt_TIMER0_CFG);

/**
 * This function is used to set the timer pre load value. 
 * 
 * @param copy_u8Value the value to be setted in timer register .
 */
void TIMER_0_void_setValue(u8 copy_u8Value);

/**
 * This function is used to set the compare match value. 
 * 
 * @param copy_u8CompareValue the value to be setted in ctc register .
 */
void TIMER_0_void_setCTCValue(u8 copy_u8CompareValue);

/**
 * This function is used to set the callback function for Timer0 when an overflows happens. 
 * 
 * @param Copy_pvT0overflowFunc pointer to the callback function.
 * 
 * @return an enum which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus Timer0_enuErrorStateOverFlowSetCallBack(void (*Copy_pvT0overflowFunc)(void));

/**
 * This function is used to set the callback function for Timer0 when a compare match happens. 
 * 
 * @param Copy_pvT0CTCFunc pointer to the callback function.
 * 
 * @return an enum which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus Timer0_enuErrorStateCTCSetCallBack(void (*Copy_pvT0CTCFunc)(void));

/**
 * This function is used to get the value in timer 0 register. 
 *
 * @return the current timer/counter 0 value.
 */
u8 TIMER_0_void_getValue();

/**
 * This function is used to get the value in timer 0 ctc register. 
 *
 * @return the current timer/counter 0 ctc value.
 */
u8 TIMER_0_void_getCTCValue();

/*****************************************************************************/
/*****************************************************************************/
/*******************************    TIMER 2    *******************************/
/*****************************************************************************/
/*****************************************************************************/
/*timer 2 modes*/
#define TIMER_2_MODE_NORMAL                         1
#define TIMER_2_MODE_PWM_PHASE_CORRECT              2
#define TIMER_2_MODE_CTC                            3
#define TIMER_2_MODE_FAST_PWM                       4

/*oc2 modes*/
#define OC2_MODE_NORMAL_PORT                        1
#define OC2_MODE_TOGGLE_ON_CTC                      2
#define OC2_MODE_CLEAR_ON_CTC_NON_INV               3
#define OC2_MODE_SET_ON_CTC_INV                     4

/*Timer2 Interrupt macros*/
#define TIMER_2_INTERRUPT_MODE_DISABLE              0
#define TIMER_2_INTERRUPT_MODE_ENABLE_OVERFLOW      1
#define TIMER_2_INTERRUPT_MODE_ENABLE_CTC           2
#define TIMER_2_INTERRUPT_MODE_ENABLE_OVERFLOW_CTC  3

/*Timer2 Clock Prescaler macros*/
#define TIMER_2_CLOCK_MODE_NO_CLOCK                         0
#define TIMER_2_CLOCK_MODE_NO_PRESCALER                     1
#define TIMER_2_CLOCK_MODE_8_PRESCALER                      2
#define TIMER_2_CLOCK_MODE_32_PRESCALER                     3
#define TIMER_2_CLOCK_MODE_64_PRESCALER                     4
#define TIMER_2_CLOCK_MODE_128_PRESCALER                    5
#define TIMER_2_CLOCK_MODE_256_PRESCALER                    6
#define TIMER_2_CLOCK_MODE_1024_PRESCALER                   7
typedef struct {

    /*Options : 
        TIMER_2_MODE_NORMAL           
        TIMER_2_MODE_PWM_PHASE_CORRECT
        TIMER_2_MODE_CTC              
        TIMER_2_MODE_FAST_PWM         
    */
    u8 TIMER_2_MODE;

    /*Options : 
        OC2_MODE_NORMAL_PORT                     
        OC2_MODE_TOGGLE_ON_CTC                   
        OC2_MODE_CLEAR_ON_CTC_NON_INV                    
        OC2_MODE_SET_ON_CTC_INV                      
    */
    u8 OC2_MODE;
    /*Options : 
        TIMER_2_INTERRUPT_MODE_DISABLE             
        TIMER_2_INTERRUPT_MODE_ENABLE_OVERFLOW     
        TIMER_2_INTERRUPT_MODE_ENABLE_CTC
        TIMER_2_INTERRUPT_MODE_ENABLE_OVERFLOW_CTC 
    */
    u8 TIMER_2_INTERRUPT_MODE;

    /*Options : 
        TIMER_2_CLOCK_MODE_NO_CLOCK           
        TIMER_2_CLOCK_MODE_NO_PRESCALER       
        TIMER_2_CLOCK_MODE_8_PRESCALER        
        TIMER_2_CLOCK_MODE_64_PRESCALER       
        TIMER_2_CLOCK_MODE_256_PRESCALER      
        TIMER_2_CLOCK_MODE_1024_PRESCALER     
        TIMER_2_CLOCK_MODE_EXT_ON_T0_Falling  
        TIMER_2_CLOCK_MODE_EXT_ON_T0_Rising   
    */
    u8 CLOCK_MODE;

} Timer2_cfg;

/**
 * This function is used to Initialize Timer2. 
 * 
 * @param prt_TIMER2_CFG a pointer to struct that represents the timer configuration.
 */
void TIMER_2_voidInit(Timer2_cfg * prt_TIMER2_CFG);

/**
 * This function is used to set the timer pre load value. 
 * 
 * @param copy_u8Value the value to be setted in timer register .
 */
void TIMER_2_void_setValue(u8 copy_u8Value);

/**
 * This function is used to set the compare match value. 
 * 
 * @param copy_u8CompareValue the value to be setted in ctc register .
 */
void TIMER_2_void_setCTCValue(u8 copy_u8CompareValue);

/**
 * This function is used to set the callback function for Timer2 when an overflows happens. 
 * 
 * @param Copy_pvT2overflowFunc pointer to the callback function.
 * 
 * @return an enum which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus Timer2_enuErrorStateOverFlowSetCallBack(void (*Copy_pvT2overflowFunc)(void));

/**
 * This function is used to set the callback function for Timer2 when a compare match happens. 
 * 
 * @param Copy_pvT2CTCFunc pointer to the callback function.
 * 
 * @return an enum which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus Timer2_enuErrorStateCTCSetCallBack(void (*Copy_pvT2CTCFunc)(void));

/**
 * This function is used to get the value in timer 2 register. 
 *
 * @return the current timer/counter 2 value.
 */
u8 TIMER_2_void_getValue();

/**
 * This function is used to get the value in timer 2 ctc register. 
 *
 * @return the current timer/counter 2 ctc value.
 */
u8 TIMER_2_void_getCTCValue();
