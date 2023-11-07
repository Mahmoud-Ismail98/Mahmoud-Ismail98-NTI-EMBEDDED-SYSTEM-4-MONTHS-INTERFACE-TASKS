/*
 * GPTM_CFG.h
 *
 * Created: 10/23/2023 9:18:25 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef GPTM_CFG_H_
#define GPTM_CFG_H_





/*Timer 0 CLOCK SOURCE Settings 
2-GPTM_Timer0_Freq_Default               
3-GPTM_Timer0_Freq_Prescaler1_8          
4-GPTM_Timer0_Freq_Prescaler1_64         
5-GPTM_Timer0_Freq_Prescaler1_256        
6-GPTM_Timer0_Freq_Prescaler1_1024       
7-GPTM_Timer0_Ext_Freq_ON_FALLING_EDGE   
9-GPTM_Timer0_Ext_Freq_ON_RISING_EDGE    
*/
#define GPTM_TIMER0_FREQ   GPTM_Timer0_Freq_Prescaler1_1024 



/*Timer 0 Operating Mode 
1-GPTM_TIMER0_NORMAL_MODE            
2-GPTM_TIMER0_CTC_MODE			
3-GPTM_TIMER0_FASTPWM_MODE			
4-GPTM_TIMER0_PhaseCorrect_Mode	
*/
#define GPTM_TIMER0_MODE      GPTM_TIMER0_FASTPWM_MODE	

/*Timer 0 OC0 PIN OPERATION MODE ON COMPARE MATCH 
1-GPTM_TIMER0_OC0_NORMAL     
2-GPTM_TIMER0_OC0_TGL        
3-GPTM_TIMER0_OC0_CLEAR      
4-GPTM_TIMER0_OC0_SET
*/
#define GPTM_TIMER0_OC0_MODE  GPTM_TIMER0_OC0_CLEAR  


/*TIMER0 INTERRUPT OPTIONS
GPTM_TIMER0_DISABLE_INTERRUPT
GPTM_TIMER0_COMPARE_MATCH_IE          
GPTM_TIMER0_OVERFLOW_IE
*/
#define GPTM_TIMER0_INTERRUPT_MODE   GPTM_TIMER0_DISABLE_INTERRUPT                 
   
#endif /* GPTM_CFG_H_ */