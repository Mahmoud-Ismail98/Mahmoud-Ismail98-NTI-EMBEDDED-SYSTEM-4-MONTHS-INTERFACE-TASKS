#include "../../../4-SERVICS/Bit_utils.h"
#include "../../../4-SERVICS/Std_types.h"
#include "../../2-DIO/include/DIO.h"
#include "../../2-DIO/include/DIO_Cfg.h"
#include "../../2-DIO/include/DIO_Prv.h"

Dio_tenuErrorStatus Dio_enuWritechannal(u8 Copy_u8ChannalId , u8 Copy_u8Level)
{
      // set the number of port
	u8 Copy_u8PortId = Copy_u8ChannalId / RIGESTER_SIZE;
	 // set the number of Channals
	u8 ChannalId = Copy_u8ChannalId % RIGESTER_SIZE;

	Dio_tenuErrorStatus Error_state = Dio_EnmDioOk;
	if (Copy_u8ChannalId > NUMBER_CHANNALS )
	{
		Error_state = Dio_EnmChannalIdError;
	}
	switch(Copy_u8PortId)
		{
		case PORTA_REG :
		{
	if (Copy_u8Level ==  DIO_HIGH ) {
	        // Set the specified pin to HIGH.
	        SET_BIT(PORTA, ChannalId);
	    }
	else if (Copy_u8Level == DIO_LOW) {
	        // Set the specified pin to LOW.
	        CLR_BIT(PORTA, ChannalId);
	    }
	else {
	        // Handle an invalid level (it's neither HIGH nor LOW).
	    	Error_state = Dio_EnmChannalLevelError;

	    }
		}break;
		case PORTB_REG :
				{
			if (Copy_u8Level ==  DIO_HIGH ) {
			        // Set the specified pin to HIGH.
			        SET_BIT(PORTB,ChannalId);
			    }
			else if (Copy_u8Level == DIO_LOW) {
			        // Set the specified pin to LOW.
			        CLR_BIT(PORTB, ChannalId);
			    }
			else {
			        // Handle an invalid level (it's neither HIGH nor LOW).
			    	Error_state = Dio_EnmChannalLevelError;

			    }
				}break;
		case PORTC_REG :
						{
					if (Copy_u8Level ==  DIO_HIGH ) {
					        // Set the specified pin to HIGH.
					        SET_BIT(PORTC, ChannalId);
					    }
					else if (Copy_u8Level == DIO_LOW) {
					        // Set the specified pin to LOW.
					        CLR_BIT(PORTC, ChannalId);
					    }
					else {
					        // Handle an invalid level (it's neither HIGH nor LOW).
					    	Error_state = Dio_EnmChannalLevelError;
					    }
						}break;
		case PORTD_REG :
						{
					if (Copy_u8Level ==  DIO_HIGH ) {
					        // Set the specified pin to HIGH.
					        SET_BIT(PORTD, ChannalId);
					    }
					else if (Copy_u8Level == DIO_LOW) {
					        // Set the specified pin to LOW.
					        CLR_BIT(PORTD, ChannalId);
					    }
					else {
					        // Handle an invalid level (it's neither HIGH nor LOW).
					    	Error_state = Dio_EnmChannalLevelError;

					    }
						}break;
		default : Error_state = Dio_EnmInvalidPortID;break;
		}
	return Error_state;

}
Dio_tenuErrorStatus Dio_enuReadchannal(u8 Copy_u8ChannalId , pu8 Add_pu8ChannelLevel)
{
	// set the number of port
		u8 Copy_u8PortId = Copy_u8ChannalId / RIGESTER_SIZE;
		 // set the number of Channals
		u8 ChannalId = Copy_u8ChannalId % RIGESTER_SIZE;

		Dio_tenuErrorStatus Error_state = Dio_EnmDioOk;
			if (Copy_u8ChannalId > NUMBER_CHANNALS )
			{
				Error_state = Dio_EnmChannalIdError;
			}

			switch(Copy_u8PortId)
					{
					case PORTA_REG :
					{
					  *Add_pu8ChannelLevel= GET_BIT(PINA,ChannalId);
					}break;
					case PORTB_REG :
					{
					  *Add_pu8ChannelLevel= GET_BIT(PINB,ChannalId);
					}break;
					case PORTC_REG :
					{
					  *Add_pu8ChannelLevel= GET_BIT(PINC,ChannalId);
					}break;
					case PORTD_REG :
					{
					  *Add_pu8ChannelLevel= GET_BIT(PIND,ChannalId);
					}break;
					default : Error_state = Dio_EnmInvalidPortID;break;

				}
			return Error_state;

}
Dio_tenuErrorStatus Dio_enuWritePort(u8 Copy_u8PortId , u8 Copy_u8Value)
{
	Dio_tenuErrorStatus Error_state = Dio_EnmDioOk;
		if (Copy_u8PortId > NUMBER_PORTS )
		{
			Error_state = Dio_EnmInvalidPortID;
		}
		switch(Copy_u8PortId)
			{
			case PORTA_REG :ASSIGN_REG( PORTA , Copy_u8Value);break;
			case PORTB_REG :ASSIGN_REG( PORTB , Copy_u8Value);break;
			case PORTC_REG :ASSIGN_REG(PORTC , Copy_u8Value);break;
			case PORTD_REG :ASSIGN_REG( PORTD , Copy_u8Value);break;
			default : Error_state = Dio_EnmInvalidPortID;break;
			}
		return Error_state;

}
Dio_tenuErrorStatus Dio_enuReadPort(u8 Copy_u8PortId ,  pu8 Add_puPortValue)
{
	Dio_tenuErrorStatus Error_state = Dio_EnmDioOk;
			if (Copy_u8PortId > NUMBER_PORTS )
			{
				Error_state = Dio_EnmInvalidPortID;
			}
			switch(Copy_u8PortId)
								{
								case PORTA_REG :
								{
								  *Add_puPortValue= PINA;
								}break;
								case PORTB_REG :
								{
								  *Add_puPortValue= PINB;
								}break;
								case PORTC_REG :
								{
								  *Add_puPortValue= PINC;
								}break;
								case PORTD_REG :
								{
								  *Add_puPortValue= PIND;
								}break;
								default : Error_state = Dio_EnmInvalidPortID;break;

							}
						return Error_state;
}
Dio_tenuErrorStatus Dio_enuFlipChannel(u8 Copy_u8ChannalId)
{
	        // set the number of port
			u8 Copy_u8PortId = Copy_u8ChannalId / RIGESTER_SIZE;
			 // set the number of Channals
			u8 ChannalId = Copy_u8ChannalId % RIGESTER_SIZE;

			Dio_tenuErrorStatus Error_state = Dio_EnmDioOk;

			if (Copy_u8ChannalId > NUMBER_CHANNALS )
				{
					Error_state = Dio_EnmChannalIdError;
				}
				switch(Copy_u8PortId)
				{
				case PORTA_REG : TGL_BIT(PORTA,ChannalId);break;
								case PORTB_REG : TGL_BIT(PORTA,ChannalId);break;
								case PORTC_REG : TGL_BIT(PORTA,ChannalId);break;
								case PORTD_REG : TGL_BIT(PORTA,ChannalId);break;
								default :  Error_state = Dio_EnmInvalidPortID;
								}

            return Error_state;
}
