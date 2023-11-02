/*
 * Timer1.c
 *
 * Created: 10/30/2023 11:18:25 PM
 *  Author: 20101
 */ 
#include "Std_types.h"
#include "Bit_utils.h"

#include "Timer1.h"
#include "Timer1_cfg.h"
#include "TImer1_priv.h"



void Timer1_Init(void)
{
	/* Non Iverting */
	SET_BIT(TCCR1A , COM1A1 ) ;
	CLR_BIT(TCCR1A , COM1A0) ;
	
	
	
	/* Wave Form : Fast PWM*/ 
	 CLR_BIT(TCCR1A , WGM10) ; 
	 SET_BIT(TCCR1A , WGM11) ;
	 
	 SET_BIT(TCCR1B , WGM12) ;
	 SET_BIT(TCCR1B , WGM13) ;
	 
	 /* Prescaler  / 8  */
	
	 TCCR1B &=0b11111000 ; 
	 TCCR1B |= 2 ; 
	 
	 
	 
	 
	
}
void Timer1_voidSetICR(u16 copy_u16TOP)
{
	ICR1 = copy_u16TOP ; 
	
}
void TImer1_voidSetCompAMatch(u16 copy_u16CompareAMatch)
{
	OCR1A = copy_u16CompareAMatch ; 
}

void Servo_Init(void) 
{
	TCCR1A |= 0x82;
	
	TCCR1B |= 0x1c;
	//652
	ICR1 = 1250;

	TCCR1B |=0x04;

}

void Servo_SetDegree(float degree)
{
		degree = degree * 0.3527777778 + 61.5;
		OCR1A = degree;
	/* simulation
	degree = degree * 0.1866666667 + 31.6;
	OCR1A = degree;
	*/
}


/*************** PWM MODE TIMER ZERO SPAGHETTII CODE ***********/
/*
void PWM_init(void)
{

	//Setting PWM Mode
	SET_BIT(TCCR0 , TCCR0_WGM00) ;

	//Setting Non-Inverted Mode
	SET_BIT(TCCR0 , COM01) ;
}

void PWM_start(void)
{
	//Prescallar = 64
	SET_BIT(TCCR0 , CS00) ;
	SET_BIT(TCCR0 , CS01) ;
}

void PWM_Generate(u16 Duty_Cycle)
{
	//Setting OCR0 Value
	OCR0 = ((Duty_Cycle * 256) / 100) - 1 ;
}

*/