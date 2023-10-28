/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : Timer               **********************/
/**********************    Version: 1.0                 **********************/
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

#define TIMER_0_INTERRUPT_MODE_DISABLE              0
#define TIMER_0_INTERRUPT_MODE_ENABLE_OVERFLOW      1
#define TIMER_0_INTERRUPT_MODE_ENABLE_CTC           2
#define TIMER_0_INTERRUPT_MODE_ENABLE_OVERFLOW_CTC  3


#define CLOCK_MODE_NO_CLOCK                         0
#define CLOCK_MODE_NO_PRESCALER                     1
#define CLOCK_MODE_8_PRESCALER                      2
#define CLOCK_MODE_64_PRESCALER                     3
#define CLOCK_MODE_256_PRESCALER                    4
#define CLOCK_MODE_1024_PRESCALER                   5
#define CLOCK_MODE_EXT_ON_T0_Falling                6
#define CLOCK_MODE_EXT_ON_T0_Rising                 7
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
        CLOCK_MODE_NO_CLOCK           
        CLOCK_MODE_NO_PRESCALER       
        CLOCK_MODE_8_PRESCALER        
        CLOCK_MODE_64_PRESCALER       
        CLOCK_MODE_256_PRESCALER      
        CLOCK_MODE_1024_PRESCALER     
        CLOCK_MODE_EXT_ON_T0_Falling  
        CLOCK_MODE_EXT_ON_T0_Rising   
    */
    u8 CLOCK_MODE;

} Timer0_cfg;

void TIMER_0_voidInit(Timer0_cfg * prt_TIMER0_CFG);
void TIMER_0_void_setValue(u8 copy_u8Value);
void TIMER_0_void_setCTCValue(u8 copy_u8CompareValue);
tenuErrorStatus Timer0_enuErrorStateOverFlowSetCallBack(void (*Copy_pvT0overflowFunc)(void));
tenuErrorStatus Timer0_enuErrorStateCTCSetCallBack(void (*Copy_pvT0CTCFunc)(void));

u8 TIMER_0_void_getValue();

u8 TIMER_0_void_getCTCValue();
