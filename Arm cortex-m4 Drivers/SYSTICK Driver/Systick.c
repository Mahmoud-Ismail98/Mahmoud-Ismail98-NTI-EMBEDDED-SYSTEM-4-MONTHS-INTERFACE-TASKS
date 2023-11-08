#include "Systick.h"
#include "Systick_Prv.h"
#include "std_types.h"
#include "Bit_utilies.h"
#include "Systick_Cfg.h"

//GLOBAL POINTER TO FUNCTION TO CALLBACK FUNCTION
void (*G_CBF) (void)=Null_ptr;

//SYSTICK INIT TO STORE THE VALUE OF THE TICKS AND DEFINE THE SYS CLOCK AND INTERRUPT MODE 
Systick_tenuErrorStatus Systick_Init(uint32 Copy_TimeMs)
 {
	 //ERROR STATUS VARIABLE
	 uint8 ErrorStatus=Systick_enuOk;
	 double64 tick_time=0;uint32 number_of_ticks=0,CLK_SRC=0;
	 //IF THE PARAMETER =0 FIRE ERROR STATUS 
	 if(Copy_TimeMs==0)
	 {
		 ErrorStatus=Systick_enuErrorTimeMs;
	 }
	 //NOT ZERO INITIALIZE THE SYSTICK
	 else 
		{
			#if(SYSTICK_CLK_MODE==SYSTICK_CLK_AHB)
			CLK_SRC=SYSTICK_CLK_SRC;
			tick_time=1/CLK_SRC;
			number_of_ticks=(uint32)Copy_TimeMs/tick_time;
			//SET THE CLKSO URCE BIT IN CRL REGISTER 
			SET_BIT(STK_CTRL,1);
			
			//ELSE 
			#elif(SYSTICK_CLK_MODE==SYSTICK_CLK_AHB_DIV8)
			CLK_SRC=SYSTICK_CLK_SRC;
			tick_time=8/CLK_SRC;
			number_of_ticks=(uint32)Copy_TimeMs/tick_time;
			//CLEAR THE CLKSO URCE BIT IN CRL REGISTER 
			CLEAR_BIT(STK_CTRL,1);
			#endif
			
			//LOAD THE VALUE TO VAL REGISTER 
			STK_LOAD=(STK_LOAD & VALIDATE_RELOADVALUE) |16000000;
			//RESET THE CURRENT REGISTER
			STK_VAL=0;
			
			//IN THE SYSTICK_CFG FILE IF THE INTERRUPT MODE DISALE 
			#if(SYSTICK_INTERRUPT_MODE==SYSTICK_INTERRUPT_D)
			
			//CLEAR THE TICK INT BIT IN CTL REGISTER
			CLEAR_BIT(STK_CTRL,1);
			
			//IF INTERRUPT MODE ENABLE 
			#elif(SYSTICK_INTERRUPT_MODE==SYSTICK_INTERRUPT_E)
			
			//SET THE INT BIT IN CTL REGISTER
			SET_BIT(STK_CTRL,1);
			
			#endif
			
			//IN THE SYSTICK_CFG FILE IF THE CLK MODE AHB 
			
	 }
		
	 //RETURN ERRORS LOGS
	 return ErrorStatus;
 }
 
 //FUNCTION TO TAKE THE ADDRESS OF THE CALLBACK FUNCTION AND STORE IT IN A GLOBAL POINTER  
 Systick_tenuErrorStatus Systick_RegisterCbf(Systick_Cbf Add_pfCbf)
 {
	 //ERROR STATUS 
	 uint8 ErrorStatus=Systick_enuOk;
	 
	 //IF THE POINTER IS NULL POINTER FIRE ERROR STATUS 
	 if(Add_pfCbf==Null_ptr)
	 {
		 ErrorStatus=Systick_enuErrorNullPointer;
	 }
	 //ELSE STORE THE ADDRESS OF THE FUNCTION 
	 else 
	 {
		 G_CBF=Add_pfCbf;
	 }
	 //RETURN ERROR STATUS 
	 return ErrorStatus;
 }
 
 //THE FUNCTION START THE TIMER COUNTER 
 void Systick_Start(void)
 {
	      //SET THE ENABLE BIT IN CLR REGISTER  
	 			SET_BIT(STK_CTRL,0);

 }
 
 //THE FUNCTION RESET THE TIMER COUNTER 
 void Systick_Stop(void)
 {
	 //CLEAR THE ENABLE BIT IN CLR REGISTER 
	 	 	CLEAR_BIT(STK_CTRL,0);
 }
 
 
 void SysTick_Handler(void)
 {
	 //CALL THE CALL BACK FUNCTION
	 G_CBF();
 }