/*
 * PORT.c
 *
 * Created: 10/20/2023 11:58:15 AM
 *  Author: FADY
 */ 
#include "../../SERVICES/Bit_utils.h"
#include "../../SERVICES/Std_types.h"

#include "PORT.h"
#include "PORT_prv.h"
#include "PORT_cfg.h"


/* TO INIALIZE DIRECTION AND VALUE IT SHOULD BE SET ON CFG FILE  */
void PORT_VoidInit(void)
{
    /* INSTEAD OF USING 32 MACRO IN CFG FILE WE JUST USED THE HALF */
    /* IN DETERMINIG DIR WE WILL MAKE ALL OUT WITH 1 AND ALL IN WITH ONE  */
    #undef PORT_OUTPUT_LOW
	#define PORT_OUTPUT_LOW 1
	
	#undef PORT_INPUT_FLOATING
	#define PORT_INPUT_FLOATING 0

	#undef PORT_INPUT_PULLUP
	#define PORT_INPUT_PULLUP 0
   
	DDRA_Reg = CONC(PORT_PA7_INTIAL_STATE,PORT_PA6_INTIAL_STATE,PORT_PA5_INTIAL_STATE,PORT_PA4_INTIAL_STATE,PORT_PA3_INTIAL_STATE,PORT_PA2_INTIAL_STATE,PORT_PA1_INTIAL_STATE,PORT_PA0_INTIAL_STATE);
    
	DDRB_Reg = CONC(PORT_PB7_INTIAL_STATE,PORT_PB6_INTIAL_STATE,PORT_PB5_INTIAL_STATE,PORT_PB4_INTIAL_STATE,PORT_PB3_INTIAL_STATE,PORT_PB2_INTIAL_STATE,PORT_PB1_INTIAL_STATE,PORT_PB0_INTIAL_STATE);
   
	DDRC_Reg = CONC(PORT_PC7_INTIAL_STATE,PORT_PC6_INTIAL_STATE,PORT_PC5_INTIAL_STATE,PORT_PC4_INTIAL_STATE,PORT_PC3_INTIAL_STATE,PORT_PC2_INTIAL_STATE,PORT_PC1_INTIAL_STATE,PORT_PC0_INTIAL_STATE);
                  
	DDRD_Reg = CONC(PORT_PD7_INTIAL_STATE,PORT_PD6_INTIAL_STATE,PORT_PD5_INTIAL_STATE,PORT_PD4_INTIAL_STATE,PORT_PD3_INTIAL_STATE,PORT_PD2_INTIAL_STATE,PORT_PD1_INTIAL_STATE,PORT_PD0_INTIAL_STATE);	

    /* IN DETERMINIG VALUE WE KNOW OUTBUT LOW REPRESENTED AND INPUT FLOATING  BY 0 , OUTBUT HIGH AND INPUT PULLUP WITH 1  */					   
	#undef PORT_OUTPUT_LOW
	#define PORT_OUTPUT_LOW 0
	
	#undef PORT_INPUT_FLOATING
	#define PORT_INPUT_FLOATING 0

	#undef PORT_INPUT_PULLUP
	#define PORT_INPUT_PULLUP 1											 


	PORTA_Reg = CONC(PORT_PA7_INTIAL_STATE,PORT_PA6_INTIAL_STATE,PORT_PA5_INTIAL_STATE,PORT_PA4_INTIAL_STATE,PORT_PA3_INTIAL_STATE,PORT_PA2_INTIAL_STATE,PORT_PA1_INTIAL_STATE,PORT_PA0_INTIAL_STATE);
	
    PORTB_Reg = CONC(PORT_PB7_INTIAL_STATE,PORT_PB6_INTIAL_STATE,PORT_PB5_INTIAL_STATE,PORT_PB4_INTIAL_STATE,PORT_PB3_INTIAL_STATE,PORT_PB2_INTIAL_STATE,PORT_PB1_INTIAL_STATE,PORT_PB0_INTIAL_STATE);

	PORTC_Reg = CONC(PORT_PC7_INTIAL_STATE,PORT_PC6_INTIAL_STATE,PORT_PC5_INTIAL_STATE,PORT_PC4_INTIAL_STATE,PORT_PC3_INTIAL_STATE,PORT_PC2_INTIAL_STATE,PORT_PC1_INTIAL_STATE,PORT_PC0_INTIAL_STATE);  

 	PORTD_Reg = CONC(PORT_PD7_INTIAL_STATE,PORT_PD6_INTIAL_STATE,PORT_PD5_INTIAL_STATE,PORT_PD4_INTIAL_STATE,PORT_PD3_INTIAL_STATE,PORT_PD2_INTIAL_STATE,PORT_PD1_INTIAL_STATE,PORT_PD0_INTIAL_STATE);  

    /*RETURNING THEM TO THEIR ORIGIN STATE AS IT ON CFG FILE */
	#undef PORT_OUTPUT_LOW
	#define PORT_OUTPUT_LOW 0

	#undef PORT_INPUT_FLOATING
	#define PORT_INPUT_FLOATING 2

	#undef PORT_INPUT_PULLUP
	#define PORT_INPUT_PULLUP 3                                                                           
}



PORT_tenuErrorStatus Port_enuSetPinDirection(u8 Copy_u8PinNum, u8 Copy_u8PinDirection) {
    PORT_tenuErrorStatus Local_u8Status = PORT_OK;
    
    if ((Copy_u8PinNum > 31) || (Copy_u8PinNum < 0)) {
        Local_u8Status = PORT_WRONGPIN;
    } else {
        if ((Copy_u8PinDirection > 1) || (Copy_u8PinDirection < 0)) {
            Local_u8Status = PORT_WRONGDIRECTION;
        } else {
            /* Calculate the port number and pin number */
            u8 Local_u8Port = Copy_u8PinNum / 8;
            u8 Local_u8Pin = Copy_u8PinNum % 8;

            /* Use a switch statement to set the pin direction */
            switch (Local_u8Port) {
                case PORT_PORTA:
                    if (Copy_u8PinDirection == PORT_INPUT) {
                        CLR_BIT(DDRA_Reg, Local_u8Pin);
                    } else {
                        SET_BIT(DDRA_Reg, Local_u8Pin);
                    }
                    break;

                case PORT_PORTB:
                    if (Copy_u8PinDirection == PORT_INPUT) {
                        CLR_BIT(DDRB_Reg, Local_u8Pin);
                    } else {
                        SET_BIT(DDRB_Reg, Local_u8Pin);
                    }
                    break;

                case PORT_PORTC:
                    if (Copy_u8PinDirection == PORT_INPUT) {
                        CLR_BIT(DDRC_Reg, Local_u8Pin);
                    } else {
                        SET_BIT(DDRC_Reg, Local_u8Pin);
                    }
                    break;

                case PORT_PORTD:
                    if (Copy_u8PinDirection == PORT_INPUT) {
                        CLR_BIT(DDRD_Reg, Local_u8Pin);
                    } else {
                        SET_BIT(DDRD_Reg, Local_u8Pin);
                    }
                    break;

                default:
                    /* DO NOTHING*/
                    break;
            }
        }
    }
    return Local_u8Status;
}

PORT_tenuErrorStatus Port_enuSetPinMode(u8 Copy_u8PinNum,u8 Copy_u8PinMode){

    PORT_tenuErrorStatus Local_u8Status = PORT_OK;
   
    if((Copy_u8PinNum>31)||(Copy_u8PinNum<0)){
        Local_u8Status = PORT_WRONGPIN;
    }
    else if((Copy_u8PinMode>3)||(Copy_u8PinMode<0))
    {
        Local_u8Status = PORT_WRONGMODE;
    }
    else
    {
            u8 Local_u8Port = Copy_u8PinNum/8;
            u8 Local_u8Pin = Copy_u8PinNum%8;
            switch(Local_u8Port)
            {
                case PORT_PORTA:
                    switch (Copy_u8PinMode) {
                        case PORT_OUTPUT_LOW:
                            SET_BIT(DDRA_Reg, Local_u8Pin);
                            CLR_BIT(PORTA_Reg, Local_u8Pin);
                        break;
                        case PORT_OUTPUT_HIGH:
                            SET_BIT(DDRA_Reg, Local_u8Pin);
                            SET_BIT(PORTA_Reg, Local_u8Pin);
                        break;
                        case PORT_INPUT_PULLUP:
                            CLR_BIT(DDRA_Reg, Local_u8Pin);
                            SET_BIT(PORTA_Reg, Local_u8Pin);
                        break;
                        case PORT_INPUT_FLOATING:
                            CLR_BIT(DDRA_Reg, Local_u8Pin);
                            CLR_BIT(PORTA_Reg, Local_u8Pin);
                        break;
                        default:
                            /*DO NOTHING*/
                        break;
                    }
                break;
                case PORT_PORTB:
                    switch (Copy_u8PinMode) {
                        case PORT_OUTPUT_LOW:
                            SET_BIT(DDRB_Reg, Local_u8Pin);
                            CLR_BIT(PORTB_Reg, Local_u8Pin);
                        break;
                        case PORT_OUTPUT_HIGH:
                            SET_BIT(DDRB_Reg, Local_u8Pin);
                            SET_BIT(PORTB_Reg, Local_u8Pin);
                            break;
                            case PORT_INPUT_PULLUP:
                                CLR_BIT(DDRB_Reg, Local_u8Pin);
                                SET_BIT(PORTB_Reg, Local_u8Pin);
                            break;
                            case PORT_INPUT_FLOATING:
                                CLR_BIT(DDRB_Reg, Local_u8Pin);
                                CLR_BIT(PORTB_Reg, Local_u8Pin);
                            break;
                            default:
                                /*DO NOTHING*/
                            break;
                        }         
                    break;
                    case PORT_PORTC:
                        switch (Copy_u8PinMode) {
                            case PORT_OUTPUT_LOW:
                                SET_BIT(DDRC_Reg, Local_u8Pin);
                                CLR_BIT(PORTC_Reg, Local_u8Pin);
                            break;
                            case PORT_OUTPUT_HIGH:
                                SET_BIT(DDRC_Reg, Local_u8Pin);
                                SET_BIT(PORTC_Reg, Local_u8Pin);
                            break;
                            case PORT_INPUT_PULLUP:
                                CLR_BIT(DDRC_Reg, Local_u8Pin);
                                SET_BIT(PORTC_Reg, Local_u8Pin);
                            break;
                            case PORT_INPUT_FLOATING:
                                CLR_BIT(DDRC_Reg, Local_u8Pin);
                                CLR_BIT(PORTC_Reg, Local_u8Pin);
                            break;
                            default:
                                /*DO NOTHING*/
                            break;
                        }  
                        break;

                        case PORT_PORTD:
                            switch (Copy_u8PinMode) {
                                case PORT_OUTPUT_LOW:
                                    SET_BIT(DDRD_Reg, Local_u8Pin);
                                    CLR_BIT(PORTD_Reg, Local_u8Pin);
                                break;
                                case PORT_OUTPUT_HIGH:
                                    SET_BIT(DDRD_Reg, Local_u8Pin);
                                    SET_BIT(PORTD_Reg, Local_u8Pin);
                                break;
                                case PORT_INPUT_PULLUP:
                                    CLR_BIT(DDRD_Reg, Local_u8Pin);
                                    SET_BIT(PORTD_Reg, Local_u8Pin);
                                break;
                                case PORT_INPUT_FLOATING:
                                    CLR_BIT(DDRD_Reg, Local_u8Pin);
                                    CLR_BIT(PORTD_Reg, Local_u8Pin);
                                break;
                                default:
                                    /*DO NOTHING*/
                                break;
                            }   
                        break;

                        default :
                            /*DO NOTHING*/
                        break;
                    }       
        
    }
    return Local_u8Status;

}





