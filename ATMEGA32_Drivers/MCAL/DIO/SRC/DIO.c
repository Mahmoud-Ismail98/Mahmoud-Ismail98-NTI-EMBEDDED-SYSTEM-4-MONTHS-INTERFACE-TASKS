/*
 * DIO.c
 *
 * Created: 10/20/2023 12:00:44 PM
 *  Author: Mahmoud Tariq
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_PRIVATE.h"
#include "DIO_CFG.h"
#include "DIO.h"


DIO_enuErrorStatus DIO_enuWriteChannel(u8 copy_u8ChannelId ,u8 copy_u8Level){
	
	DIO_enuErrorStatus Return_val = DIO_Status_Fail;
	
	if(copy_u8ChannelId >= DIO_CHANNELS_NUMBER) Return_val = DIO_Pin_NO_ERR;
	else if(copy_u8Level > 1) Return_val = DIO_Logic_Level_ERR;
	else{
		
		u8 loc_u8PortNo = copy_u8ChannelId / DIO_REGISTERS_SIZE ;
		u8 loc_u8PinNo  = copy_u8ChannelId % DIO_REGISTERS_SIZE ;
		
		switch(loc_u8PortNo)
		{
			case DIO_PORTA :
							//if(DIO_HIGH == copy_u8Level && GET_BIT(DDRD,loc_u8PinNo)) SET_BIT(PORTA,loc_u8PinNo);
							if     (DIO_HIGH== copy_u8Level) SET_BIT(PORTA,loc_u8PinNo);
							else if(DIO_LOW == copy_u8Level) CLR_BIT(PORTB,loc_u8PinNo);
							Return_val = DIO_Status_Ok;
							break;
			case DIO_PORTB :
							if     (DIO_HIGH== copy_u8Level) SET_BIT(PORTB,loc_u8PinNo);
							else if(DIO_LOW == copy_u8Level) CLR_BIT(PORTB,loc_u8PinNo);
							Return_val = DIO_Status_Ok;
							break;
			case DIO_PORTC :
							if     (DIO_HIGH== copy_u8Level) SET_BIT(PORTC,loc_u8PinNo);
							else if(DIO_LOW == copy_u8Level) CLR_BIT(PORTB,loc_u8PinNo);
							Return_val = DIO_Status_Ok;
							break;
			case DIO_PORTD :
							//if(DIO_HIGH == copy_u8Level && GET_BIT(DDRD,loc_u8PinNo)) SET_BIT(PORTD,loc_u8PinNo);
							if     (DIO_HIGH== copy_u8Level) SET_BIT(PORTD,loc_u8PinNo);
							else if(DIO_LOW == copy_u8Level) CLR_BIT(PORTB,loc_u8PinNo);
							Return_val = DIO_Status_Ok;
							break;
			default		   :
							Return_val = DIO_PORT_NO_ERR;
							break;
		}
	}
	return Return_val;	
}
/*
DIO_enuErrorStatus DIO_enuWriteChannel (u8 Copy_u8ChannelId    ,u8 Copy_u8Level){
	DIO_enuErrorStatus Return_val = DIO_Status_Fail;
	
	
	if(Copy_u8ChannelId >31) Return_val = DIO_Pin_NO_ERR;
	else if( 0 != Copy_u8Level && 1 != Copy_u8ChannelId) Return_val = DIO_Logic_Level_ERR;
	else
	{
u8 LOC_u8Port = Copy_u8ChannelId / DIO_REGISTERS_SIZE;
u8 LOC_u8Pin = Copy_u8ChannelId % DIO_REGISTERS_SIZE;

switch (LOC_u8Port) {

	case DIO_PORTA:
	if (DIO_OUTPUT == GET_BIT(DDRA,LOC_u8Pin)) {
		switch (Copy_u8Level) {

			case DIO_HIGH:
			SET_BIT(PORTA, LOC_u8Pin);
			break;

			case DIO_LOW:
			CLR_BIT(PORTA, LOC_u8Pin);
			break;

		}
		} else {
		Return_val = DIO_Direction_ERR;
	}
	break;

	case DIO_PORTB:

	if (GET_BIT(DDRB,LOC_u8Pin) == DIO_OUTPUT) {
		switch (Copy_u8Level) {

			case DIO_HIGH:
			SET_BIT(PORTB, LOC_u8Pin);
			break;

			case DIO_LOW:
			CLR_BIT(PORTB, LOC_u8Pin);
			break;

		}
		} else {
		Return_val = DIO_Direction_ERR;
	}

	break;

	case DIO_PORTC:

	if (GET_BIT(DDRC,LOC_u8Pin) == DIO_OUTPUT) {
		switch (Copy_u8Level) {

			case DIO_HIGH:
			SET_BIT(PORTC, LOC_u8Pin);
			break;

			case DIO_LOW:
			CLR_BIT(PORTC, LOC_u8Pin);
			break;

		}
		} else {
		Return_val = DIO_Direction_ERR;
	}
	break;

	case DIO_PORTD:

	if (GET_BIT(DDRD,LOC_u8Pin) == DIO_OUTPUT) {
		switch (Copy_u8Level) {

			case DIO_HIGH:
			SET_BIT(PORTD, LOC_u8Pin);
			break;

			case DIO_LOW:
			CLR_BIT(PORTD, LOC_u8Pin);
			break;

		}
		} else {
		Return_val = DIO_Direction_ERR;
	}
	break;

}

}
	return Return_val;
}
*/
DIO_enuErrorStatus DIO_enuReadChannel  (u8 copy_u8ChannelId    ,u8 Add_pu8ChannelLevel){
	DIO_enuErrorStatus Return_val = DIO_Status_Fail;
	
	if ( copy_u8ChannelId > 31) Return_val= DIO_Pin_NO_ERR;
	else if ( Add_pu8ChannelLevel == NULL) Return_val=DIO_Null_ptr_ERR;
	else{
		u8 u8_Loc_PortNo = copy_u8ChannelId /DIO_REGISTERS_SIZE;
		u8 u8_Loc_PinNo = copy_u8ChannelId  %DIO_REGISTERS_SIZE;
		
		switch(u8_Loc_PortNo)
		{
			case DIO_PORTA :
					if(0 == GET_BIT(DDRA,u8_Loc_PinNo) )
					{
					Add_pu8ChannelLevel == GET_BIT(PINA,u8_Loc_PinNo);
					Return_val = DIO_Status_Ok;
					}
					else{Return_val = DIO_Logic_Level_ERR;}
			break;
			case DIO_PORTB :
					if(0 == GET_BIT(DDRB,u8_Loc_PinNo) )
					{
						Add_pu8ChannelLevel == GET_BIT(PINB,u8_Loc_PinNo);
						Return_val = DIO_Status_Ok;
					}
					else{Return_val = DIO_Logic_Level_ERR;}
						
			break;
			case DIO_PORTC :
					if(0 == GET_BIT(DDRC,u8_Loc_PinNo) )
					{
						Add_pu8ChannelLevel == GET_BIT(PINC,u8_Loc_PinNo);
						Return_val = DIO_Status_Ok;
					}
					else{Return_val = DIO_Logic_Level_ERR;}
			
			break;
			case DIO_PORTD :
					if(0 == GET_BIT(DDRD,u8_Loc_PinNo) )
					{
						Add_pu8ChannelLevel == GET_BIT(PIND,u8_Loc_PinNo);
						Return_val = DIO_Status_Ok;
					}
					else{Return_val = DIO_Logic_Level_ERR;}
			
			break;
			default:
			break;	
		}	
	}
return Return_val;	
}



DIO_enuErrorStatus DIO_enuWritePort    (u8 copy_u8PortId       ,u8 copy_Value)
{
	DIO_enuErrorStatus Return_val = DIO_Status_Fail;
	
	if(copy_u8PortId >= DIO_PORTS_NUMBER) Return_val = DIO_PORT_NO_ERR;
	else if(copy_Value <0 || copy_Value>256){ Return_val = DIO_Logic_Level_ERR;}
	else
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
				SET_REG(DDRA);
				ASSIGN_REG(PORTA,copy_Value);
				Return_val = DIO_Status_Ok;
			break;
			case DIO_PORTB:
				SET_REG(DDRB);
				ASSIGN_REG(PORTB,copy_Value);
				Return_val = DIO_Status_Ok;
			break;
			case DIO_PORTC:
					SET_REG(DDRC);
					ASSIGN_REG(PORTC,copy_Value);
					Return_val = DIO_Status_Ok;
			break;
			case DIO_PORTD:
					SET_REG(DDRD);
					ASSIGN_REG(PORTD,copy_Value);
					Return_val = DIO_Status_Ok;
			break;
			default:break;
				
				
		}
	}
	return Return_val;	
}

DIO_enuErrorStatus DIO_enuFlipChannel  (u8 copy_u8ChannelId){
	DIO_enuErrorStatus Return_val = DIO_Status_Fail;
	
	if(copy_u8ChannelId>31) Return_val = DIO_Pin_NO_ERR;
	else{
		u8 PortNum = copy_u8ChannelId /DIO_REGISTERS_SIZE;   // Get Port Number
		u8 PinNum = copy_u8ChannelId  % DIO_REGISTERS_SIZE;  // Get Pin Number
		
		switch(PortNum){
			case DIO_PORTA :
			if(1 == GET_BIT(DDRA,PinNum) )
			{
				TGL_BIT(PORTA,PinNum);
				Return_val = DIO_Status_Ok;
			}
			else{
				Return_val = DIO_Direction_ERR;
			}
			break;
			case DIO_PORTB:
			if(1 == GET_BIT(DDRB,PinNum) )
			{
				TGL_BIT(PORTB,PinNum);
				Return_val = DIO_Status_Ok;
			}
			else{
				Return_val = DIO_Direction_ERR;
			}
				TGL_BIT(PORTB,PinNum);
				Return_val = DIO_Status_Ok;
			break;
			case DIO_PORTC:
				if(1 == GET_BIT(DDRC,PinNum) )
				{
					TGL_BIT(PORTC,PinNum);
					Return_val = DIO_Status_Ok;
				}
				else{
					Return_val = DIO_Direction_ERR;
				}
			break;
			case DIO_PORTD:
				if(1 == GET_BIT(DDRD,PinNum) )
				{
					TGL_BIT(PORTD,PinNum);
					Return_val = DIO_Status_Ok;
				}
				else{
					Return_val = DIO_Direction_ERR;
				}
			break;
			default:
			break;
			
		}
	}
	
	return Return_val;
}

DIO_enuErrorStatus DIO_enuReadPort     (u8  copy_u8ChannelId          ,pu8 Add_pu8PortValue){
	DIO_enuErrorStatus Return_val = DIO_Status_Fail;

	
	if(copy_u8ChannelId>31) Return_val = DIO_Pin_NO_ERR;
	else if (NULL == Add_pu8PortValue) Return_val = DIO_Null_ptr_ERR;
	else{
		
		u8 PortNum = copy_u8ChannelId /DIO_REGISTERS_SIZE;   // Get Port Number
		u8 PinNum = copy_u8ChannelId  % DIO_REGISTERS_SIZE;  // Get Pin Number
		
		switch(PortNum)
		{
					case DIO_PORTA :
					if(0 == DDRA )
					{
						*Add_pu8PortValue = PINA;
						Return_val = DIO_Status_Ok;
					}
					else{
						Return_val = DIO_Direction_ERR;
					}
					break;
					case DIO_PORTB:
						if(0 == DDRB )
						{
							*Add_pu8PortValue = PINB;
							Return_val = DIO_Status_Ok;
						}
						else{
							Return_val = DIO_Direction_ERR;
							};
					break;
					case DIO_PORTC:
					if(0 == DDRC )
					{
						*Add_pu8PortValue = PINC;
						Return_val = DIO_Status_Ok;
					}
					else{
						Return_val = DIO_Direction_ERR;
					}
					break;
					case DIO_PORTD:
					if(0 == DDRD )
					{
						*Add_pu8PortValue = PIND;
						Return_val = DIO_Status_Ok;
					}
					else{
						Return_val = DIO_Direction_ERR;
					}
					break;
					default:
					break;
		}
	
	
	
}
return Return_val;
}