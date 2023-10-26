#include "std_types.h"
#include "Bit_utils.h" 


#include "ADC.h"
#include "ADC_priv.h"
#include "ADC_cfg.h"

/*** GLOBAL VARIABLES****/ 

static u8* ADC_pu8Reading = NULL ; 
static void (*ADC_pvCallBackNotificationFunc)(void) ;  
u8 ADC_u8BusyState = IDLE ;  
 
 /*this function initializes the ADC based on configurations in ADC_Config.h file */

void ADC_voidInit(void) 
{
	// ADC Enable
	SET_BIT(ADCSRA,7);


     
	// Prescaler Configuration as 128
	CLR_BIT(ADCSRA,2);
	CLR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);


	//Referance Voltage as AVCC with external capacitor
	CLR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);

	// ADC Data RIGHT Adjustment
	SET_BIT(ADMUX,5);
    
	/* Enable Interrupt */
	SET_BIT(ADCSRA,3);

}


  
     
	
 


u8 ADC_u8StartConversionSynchoronus(u8 copy_u8Channel , u8* Copy_u8Reading) 
{
	 u32 Local_u32Counter = 0 ;
     u8 Local_u8ErrorState = OK ;
	if (ADC_u8BusyState == IDLE)
	{
	/* ADC is Now Busy */
	ADC_u8BusyState = BUSY ; 
	
	/* Clear The MUX BITS IS ADMUX Register */ 
	 ADMUX &= 0b11100000 ; 
    /* Set The Required Channel Into The MUX Bits */
	 ADMUX |= copy_u8Channel ; 
	 
	 /*Start Conversion */ 
	 SET_BIT(ADCSRA , ADCSRA_ADSC ); 
	 
	 /* POlling (busy Waiting ) until the conversion complete Flag Is set Or Counter Reaching Time OUT */
	 while((GET_BIT(ADCSRA , ADCSRA_ADIF==0 ))&& (Local_u32Counter != ADC_u32TimeOUT));
	 {
		 Local_u32Counter++ ; 
		 
	 }
	 /* CLear The Conversion Complete Flag */ 
	 if(Local_u32Counter == ADC_u32TimeOUT)
	 {
		/* LOOP IS BROKEN BECAUSE THE TIME_OUT IS REACHING */
		 Local_u8ErrorState = NOT_OK ;
	 }
	 else 
	 {
		
		/* LOOP IS BROKEN Because FLag Is Raised */
		SET_BIT(ADCSRA ,ADCSRA_ADIF);
	    
		/* Return_The_Reading */
		 *Copy_u8Reading = ADC ;
		 
		 
		 /*ADC IS Finished , Return To IDLE */ 
		 ADC_u8BusyState = IDLE ; 
	 }
	}
	else 
	{
		Local_u8ErrorState = BUSY_FUNCTION ; 
	}

	 return Local_u8ErrorState ; 
	 
	 
} 
 



u8 ADC_u8StartConversionASynchoronus(u8 copy_u8Channel , u8* Copy_pu8Reading , void (*copy_pvNOtificationFunc)(void)) 
{
	    u8 Local_u8ErrorStatus = OK ;


	if (Copy_pu8Reading == NULL || copy_pvNOtificationFunc == NULL)
	{
	  Local_u8ErrorStatus = NOT_OK ; 	
	}
	else 
	{
		/* Make ADC Busy In Order not work until IDLE*/
		//ADC_u8BusyState = BUSY ; 
		
		/* Intialize the Reading Value Globally */ 
		ADC_pu8Reading = Copy_pu8Reading ;
		/* Intialize the CallBack Function Global */ 
		ADC_pvCallBackNotificationFunc = copy_pvNOtificationFunc ;
		/* Clear The MUX BITS IS ADMUX Register */
		ADMUX &= 0b11100000 ;
		/* Set THE required Channel into the MUX bits */
		ADMUX |= copy_u8Channel ;
		
		/* Start Conversion */
		SET_BIT(ADCSRA , ADCSRA_ADSC );
		
		/*ADC Interrupt Enable */
		//SET_BIT (ADCSRA , ADCSRA_ADIE) ; 
		
	  }

	return Local_u8ErrorStatus ; 
}

void __vector__16 (void) __attribute__((signal)) ; 
void __vector__16 (void)
{
	/* Read ADC Result */ 
	*ADC_pu8Reading = ADC ; 
	
	/* MAKE ADC STATE Be IDLE Because It IS Finished */
	//ADC_u8BusyState = IDLE ; 
	
	/*INVOKE CALL_BACK NOTIFICATION FUNC */ 
	ADC_pvCallBackNotificationFunc() ;
	
	/*Disable ADC Conversion Complete Interrupt */
	CLR_BIT (ADCSRA , ADCSRA_ADIE) ;  
}




