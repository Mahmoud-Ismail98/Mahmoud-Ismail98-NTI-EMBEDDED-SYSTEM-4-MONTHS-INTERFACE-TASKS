#include "../../../4-SERVICS/Std_types.h"
#include "../../../4-SERVICS/Bit_utils.h"
#include "../../1-PORT/include/Port.h"
#include "../../1-PORT/include/Port_Prv.h"
#include "../../1-PORT/include/Port_Cfg.h"


void Port_VoidInit(void){
#undef  PORT_u8Output_High
#define PORT_u8Output_High       1

#undef  PORT_u8Output_Low
#define PORT_u8Output_Low        1

#undef  PORT_u8Intput_Pullup
#define PORT_u8Intput_Pullup     0


#undef  PORT_u8Intput_Floating
#define PORT_u8Intput_Floating   0

	/* Set pins in DDR registers for data direction */
	DDRA= CONC(PORT_u8ModePin7,PORT_u8ModePin6,PORT_u8ModePin5,PORT_u8ModePin4,PORT_u8ModePin3,PORT_u8ModePin2,PORT_u8ModePin1,PORT_u8ModePin0);
	DDRB= CONC(PORT_u8ModePin7,PORT_u8ModePin6,PORT_u8ModePin5,PORT_u8ModePin4,PORT_u8ModePin3,PORT_u8ModePin2,PORT_u8ModePin1,PORT_u8ModePin0);
	DDRC= CONC(PORT_u8ModePin7,PORT_u8ModePin6,PORT_u8ModePin5,PORT_u8ModePin4,PORT_u8ModePin3,PORT_u8ModePin2,PORT_u8ModePin1,PORT_u8ModePin0);
	DDRD= CONC(PORT_u8ModePin7,PORT_u8ModePin6,PORT_u8ModePin5,PORT_u8ModePin4,PORT_u8ModePin3,PORT_u8ModePin2,PORT_u8ModePin1,PORT_u8ModePin0);

#undef  PORT_u8Output_High
#define PORT_u8Output_High       1

#undef  PORT_u8Output_Low
#define PORT_u8Output_Low        0

#undef  PORT_u8Intput_Pullup
#define PORT_u8Intput_Pullup     1


#undef  PORT_u8Intput_Floating
#define PORT_u8Intput_Floating    0

	/* Set pins in PORT registers for Moods */
	PORTA= CONC(PORT_u8ModePin7,PORT_u8ModePin6,PORT_u8ModePin5,PORT_u8ModePin4,PORT_u8ModePin3,PORT_u8ModePin2,PORT_u8ModePin1,PORT_u8ModePin0);
	PORTB= CONC(PORT_u8ModePin7,PORT_u8ModePin6,PORT_u8ModePin5,PORT_u8ModePin4,PORT_u8ModePin3,PORT_u8ModePin2,PORT_u8ModePin1,PORT_u8ModePin0);
	PORTC= CONC(PORT_u8ModePin7,PORT_u8ModePin6,PORT_u8ModePin5,PORT_u8ModePin4,PORT_u8ModePin3,PORT_u8ModePin2,PORT_u8ModePin1,PORT_u8ModePin0);
	PORTD= CONC(PORT_u8ModePin7,PORT_u8ModePin6,PORT_u8ModePin5,PORT_u8ModePin4,PORT_u8ModePin3,PORT_u8ModePin2,PORT_u8ModePin1,PORT_u8ModePin0);


#define PORT_u8Output_Low        0
#define PORT_u8Output_High       1

#undef  PORT_u8Intput_Pullup
#define PORT_u8Intput_Pullup     2

#undef  PORT_u8Intput_Floating
#define PORT_u8Intput_Floating   3
}


Port_tenuErrorStatus Port_enuSetPinDirection(u8 Copy_u8PinNum ,u8 Copy_u8PinDirection )
{

	u8 Copy_u8PortNum = Copy_u8PinNum / RIGESTER_SIZE;    // Port Number
	Port_tenuErrorStatus Error_State = Port_EnmOk;
	if (Copy_u8PinNum > NUMBER_PINS ){
		Error_State = Port_EnmPinError;
	}

	switch(Copy_u8PortNum)
	{
	case PORTA_REG :
	{
		if (Copy_u8PinDirection == OUTPUT){
			SET_BIT(DDRA,Copy_u8PinNum);
		}
		else if (Copy_u8PinDirection == INTPUT){
			CLR_BIT(DDRA,Copy_u8PinNum);
		}
		else {
			Error_State = Port_EnmDirectionError;
		}
	}break;


	case PORTB_REG:
	{
		if (Copy_u8PinDirection == OUTPUT){
			SET_BIT(DDRB,Copy_u8PinNum);
		}
		else if (Copy_u8PinDirection == INTPUT){
			CLR_BIT(DDRB,Copy_u8PinNum);
		}
		else {
			Error_State = Port_EnmDirectionError;
		}
	}break;
	case PORTC_REG :
	{
		if (Copy_u8PinDirection == OUTPUT){
			SET_BIT(DDRC,Copy_u8PinNum);
		}
		else if (Copy_u8PinDirection == INTPUT){
			CLR_BIT(DDRC,Copy_u8PinNum);
		}
		else {
			Error_State = Port_EnmDirectionError;
		}
	}break;
	case PORTD_REG:
	{
		if (Copy_u8PinDirection == OUTPUT){
			SET_BIT(DDRD,Copy_u8PinNum);
		}
		else if (Copy_u8PinDirection == INTPUT){
			CLR_BIT(DDRD,Copy_u8PinNum);
		}
		else {
			Error_State = Port_EnmDirectionError;
		}
	} break;

	default : Error_State = Port_EnmPinError; break;
	}
	return Error_State;

}
Port_tenuErrorStatus Port_enuSetPinMode(u8 Copy_u8PinNum ,u8 Copy_u8PinMode )
{

	u8 Copy_u8PortNum = Copy_u8PinNum / RIGESTER_SIZE;
	u8 Pin_NUM = Copy_u8PinNum % RIGESTER_SIZE;
	Port_tenuErrorStatus Error_State = Port_EnmOk;

	// Check for valid pin number
	if (Copy_u8PinNum > NUMBER_PINS){
		Error_State = Port_EnmPinError;
	}
	else {
		switch(Copy_u8PortNum)
		{
		case PORTA_REG :
		{
			switch (Copy_u8PinMode)
			{
			case PORT_u8Output_High :
			{
				SET_BIT(DDRA,Pin_NUM);
				SET_BIT(PORTA,Pin_NUM);
			}break;
			case PORT_u8Output_Low :
			{
				SET_BIT(DDRA,Pin_NUM);
				CLR_BIT(PORTA,Pin_NUM);
			}break;
			case PORT_u8Intput_Pullup :
			{
				CLR_BIT(DDRA,Pin_NUM);
				SET_BIT(PORTA,Pin_NUM);
			}break;
			case PORT_u8Intput_Floating :
			{
				CLR_BIT(DDRA,Pin_NUM);
				CLR_BIT(PORTA,Pin_NUM);
			}break;

			default:   Error_State = Port_EnmInvalidPinMode; break;
			}
		}break;
		case PORTB_REG :
		{
			switch (Copy_u8PinMode)
			{
			case PORT_u8Output_High :
			{
				SET_BIT(DDRB,Pin_NUM);
				SET_BIT(PORTB,Pin_NUM);
			}break;
			case PORT_u8Output_Low :
			{
				SET_BIT(DDRB,Pin_NUM);
				CLR_BIT(PORTB,Pin_NUM);
			}break;
			case PORT_u8Intput_Pullup :
			{
				CLR_BIT(DDRB,Pin_NUM);
				SET_BIT(PORTB,Pin_NUM);
			}break;
			case PORT_u8Intput_Floating :
			{
				CLR_BIT(DDRB,Pin_NUM);
				CLR_BIT(PORTB,Pin_NUM);
			}break;
			default:   Error_State = Port_EnmInvalidPinMode; break;

			}
		}break;
		case PORTC_REG :
		{
			switch (Copy_u8PinMode)
			{
			case PORT_u8Output_High :
			{
				SET_BIT(DDRC,Pin_NUM);
				SET_BIT(PORTC,Pin_NUM);
			}break;
			case PORT_u8Output_Low :
			{
				SET_BIT(DDRC,Pin_NUM);
				CLR_BIT(PORTC,Pin_NUM);
			}break;
			case PORT_u8Intput_Pullup :
			{
				CLR_BIT(DDRC,Pin_NUM);
				SET_BIT(PORTC,Pin_NUM);
			}break;
			case PORT_u8Intput_Floating :
			{
				CLR_BIT(DDRC,Pin_NUM);
				CLR_BIT(PORTC,Pin_NUM);
			}break;
			default:   Error_State = Port_EnmInvalidPinMode; break;
			}
		}break;
		case PORTD_REG :
		{
			switch (Copy_u8PinMode)
			{
			case PORT_u8Output_High :
			{
				SET_BIT(DDRD,Pin_NUM);
				SET_BIT(PORTD,Pin_NUM);
			}break;
			case PORT_u8Output_Low :
			{
				SET_BIT(DDRD,Pin_NUM);
				CLR_BIT(PORTD,Pin_NUM);
			}break;
			case PORT_u8Intput_Pullup :
			{
				CLR_BIT(DDRD,Pin_NUM);
				SET_BIT(PORTD,Pin_NUM);
			}break;
			case PORT_u8Intput_Floating :
			{
				CLR_BIT(DDRD,Pin_NUM);
				CLR_BIT(PORTD,Pin_NUM);
			}break;
			default:   Error_State = Port_EnmInvalidPinMode; break;
			}
		}break;
		default : Error_State =  Port_EnmInvalidPort; break;


		}

	}
	return Error_State;

}


