/*#include "../../../MCAL/PORT/include/port_cfg.h"
#include "../../../MCAL/PORT/include/port_private.h"
#include"../../../services/Bit_utils"
#include "../../../services/Std_types.h"
#include "Std_types.h"
#include "../../../MCAL/PORT/include/port.h"*/
#include "../../MCAL/PORT/include/port_cfg.h"
#include "../../MCAL/PORT/include/port_private.h"
#include "../../MCAL/PORT/include/port.h"
#include "../../services/Bit_utils.h"
#include "../../services/Std_types.h"



void Port_Init(void)
{

    #undef  PIN_IN_FLOAT
    #define PIN_IN_FLOAT 0

    #undef  PIN_IN_PULLUP
    #define PIN_IN_PULLUP 0

    #undef  PIN_OUT_LOW
    #define PIN_OUT_LOW 1

    DDRA=CONC(PIN_ID7_MODE,PIN_ID6_MODE,PIN_ID5_MODE,PIN_ID4_MODE,PIN_ID3_MODE,PIN_ID2_MODE,PIN_ID1_MODE,PIN_ID0_MODE);
    DDRB=CONC(PIN_ID15_MODE,PIN_ID14_MODE,PIN_ID13_MODE,PIN_ID12_MODE,PIN_ID11_MODE,PIN_ID10_MODE,PIN_ID9_MODE,PIN_ID8_MODE);
    DDRC=CONC(PIN_ID23_MODE,PIN_ID22_MODE,PIN_ID21_MODE,PIN_ID20_MODE,PIN_ID19_MODE,PIN_ID18_MODE,PIN_ID17_MODE,PIN_ID16_MODE);
    DDRD=CONC(PIN_ID31_MODE,PIN_ID30_MODE,PIN_ID29_MODE,PIN_ID28_MODE,PIN_ID27_MODE,PIN_ID26_MODE,PIN_ID25_MODE,PIN_ID24_MODE);	

	#undef PIN_OUT_LOW
	#define PIN_OUT_LOW  0
	
    #undef PIN_IN_FLOAT
    #define PIN_IN_FLOAT 0

    #undef PIN_IN_PULLUP
    #define PIN_IN_PULLUP 1
	
    PORTA=CONC(PIN_ID7_MODE,PIN_ID6_MODE,PIN_ID5_MODE,PIN_ID4_MODE,PIN_ID3_MODE,PIN_ID2_MODE,PIN_ID1_MODE,PIN_ID0_MODE);
    PORTB=CONC(PIN_ID15_MODE,PIN_ID14_MODE,PIN_ID13_MODE,PIN_ID12_MODE,PIN_ID11_MODE,PIN_ID10_MODE,PIN_ID9_MODE,PIN_ID8_MODE);
    PORTC=CONC(PIN_ID23_MODE,PIN_ID22_MODE,PIN_ID21_MODE,PIN_ID20_MODE,PIN_ID19_MODE,PIN_ID18_MODE,PIN_ID17_MODE,PIN_ID16_MODE);
    PORTD=CONC(PIN_ID31_MODE,PIN_ID30_MODE,PIN_ID29_MODE,PIN_ID28_MODE,PIN_ID27_MODE,PIN_ID26_MODE,PIN_ID25_MODE,PIN_ID24_MODE);
	
	#undef PIN_IN_FLOAT
	#define PIN_IN_FLOAT 2

	#undef PIN_IN_PULLUP
	#define PIN_IN_PULLUP 3	


}
ERROR_TYPES Port_setPinDirection(u8 pin_id,u8 pin_direction)
{
	ERROR_TYPES ERROR_LOC_RET =OK;	
    u8 loc_pin_id =pin_id % 8;

    u8 loc_port_num=pin_id/8;
    switch(loc_port_num)
    {
        case u8PORTA:

        if(pin_direction==PIN_OUTPUT)
        {
            SET_BIT(DDRA,loc_pin_id);
        }
        else if(pin_direction==PIN_INPUT)
        {
            CLR_BIT(DDRA,loc_pin_id);
        } 
		break;     
        case u8PORTB:
        if(pin_direction==PIN_OUTPUT)
        {
           SET_BIT(DDRB,loc_pin_id);
        }
        else if(pin_direction==PIN_INPUT)
        {
            CLR_BIT(DDRB,loc_pin_id);
        }
        break;
        case u8PORTC:

        if(pin_direction==PIN_OUTPUT)
        {
            SET_BIT(DDRC,loc_pin_id);
        }
        else if(pin_direction==PIN_INPUT)
        {
            CLR_BIT(DDRC,loc_pin_id);
        }
        break;
        case u8PORTD:
        if(pin_direction==PIN_OUTPUT)
        {
            SET_BIT(DDRD,loc_pin_id);
        }
        else if(pin_direction==PIN_INPUT)
        {
            CLR_BIT(DDRD,loc_pin_id);
        }
        break;
    default:
	 ERROR_LOC_RET =PIN_DIR_ERROR;
		
    }
 return ERROR_LOC_RET;   
}
ERROR_TYPES Port_SetPinMode(u8 pin_id,u8 pin_mode)
{
  ERROR_TYPES ERROR_LOC_RET =OK;
    u8 loc_Pin_id= pin_id % 8;
    u8 loc_port_num=pin_id/8;
    switch(loc_port_num)
    {
        case u8PORTA:
          switch(pin_mode){
            case PIN_OUT_HIGH:
				SET_BIT(DDRA,loc_Pin_id);
				SET_BIT(PORTA,loc_Pin_id);
				break;
			case  PIN_OUT_LOW:
			    SET_BIT(DDRA,loc_Pin_id);
			    CLR_BIT(PORTA,loc_Pin_id);
			    break;	
            case   PIN_IN_FLOAT:
				CLR_BIT(DDRA,loc_Pin_id);
				CLR_BIT(PORTA,loc_Pin_id);                     
				break;
            case   PIN_IN_PULLUP:
			    CLR_BIT(DDRA,loc_Pin_id);
			    SET_BIT(PORTA,loc_Pin_id);                     
			    break;   				         
            default:
			ERROR_LOC_RET= PIN_MODE_ERROR;
		  }
		  break;			
        case u8PORTB:
          switch(pin_mode){
		  
            case PIN_OUT_HIGH:
            SET_BIT(DDRB,loc_Pin_id);
            SET_BIT(PORTB,loc_Pin_id);
            break;
           case PIN_OUT_LOW:
            SET_BIT(DDRB,loc_Pin_id);
            CLR_BIT(PORTB,loc_Pin_id);
            break;
            case   PIN_IN_FLOAT:
            CLR_BIT(DDRB,loc_Pin_id);
            CLR_BIT(PORTB,loc_Pin_id);                     
            break;

            case   PIN_IN_PULLUP:
            CLR_BIT(DDRB,loc_Pin_id);
            SET_BIT(PORTB,loc_Pin_id);                     
            break;            
            default:
			ERROR_LOC_RET=PIN_MODE_ERROR;			  
		  }
		  break;			
        case u8PORTC:
          switch(pin_mode){
            case PIN_OUT_HIGH:
            SET_BIT(DDRC,loc_Pin_id);
            SET_BIT(PORTC,loc_Pin_id);
            break;
		    case PIN_OUT_LOW:
            SET_BIT(DDRC,loc_Pin_id);
            CLR_BIT(PORTC,loc_Pin_id);
            break;
            case   PIN_IN_FLOAT:
            CLR_BIT(DDRC,loc_Pin_id);
            CLR_BIT(PORTC,loc_Pin_id);                     
            break;

            case   PIN_IN_PULLUP:
            CLR_BIT(DDRC,loc_Pin_id);
            SET_BIT(PORTC,loc_Pin_id);                     
            break;            
            default:
			ERROR_LOC_RET=PIN_MODE_ERROR;	
		  }
		  break;					 


        case u8PORTD:
          switch(pin_mode){
            case PIN_OUT_HIGH:
            SET_BIT(DDRD,loc_Pin_id);
            SET_BIT(PORTD,loc_Pin_id);
            break;
            case PIN_OUT_LOW:
            SET_BIT(DDRD,loc_Pin_id);
            CLR_BIT(PORTD,loc_Pin_id);
            break;			
            case PIN_IN_FLOAT:
            CLR_BIT(DDRD,loc_Pin_id);
            CLR_BIT(PORTD,loc_Pin_id);                     
            break;
            case PIN_IN_PULLUP:
            CLR_BIT(DDRD,loc_Pin_id);
            SET_BIT(PORTD,loc_Pin_id);                     
            break;            
            default: 
			ERROR_LOC_RET=PIN_MODE_ERROR;	
			}
			break;		

        }   

  //  }  

	return ERROR_LOC_RET;

}