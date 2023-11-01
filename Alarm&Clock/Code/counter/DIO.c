/*
 * DIO.c
 *
 * Created: 10/20/2023 11:58:15 AM
 *  Author: FADY
 */ 
#include "Std_types.h"
#include "Bit_utils.h"
#include "DIO.h"
#include "DIO_prv.h"



DIO_tenuErrorStatus DIO_enuWriteChannel(u8 Copy_u8ChannelId , u8 Copy_u8Level){
    DIO_tenuErrorStatus Local_u8Status = DIO_OK;
    if((Copy_u8ChannelId>31)||(Copy_u8ChannelId<0)){
        Local_u8Status = DIO_WRONGCHANNEL;
    }
    else if((Copy_u8Level>1)||(Copy_u8Level<0))
    {
        Local_u8Status = DIO_WRONGDIR;
	}
    else{
        u8 Local_u8Port = Copy_u8ChannelId/8;
        u8 Local_u8Pin = Copy_u8ChannelId%8;
        switch(Local_u8Port)
        {
            case DIO_PORTA:
                if(Copy_u8Level==DIO_CHANNEL_LOW)
                {
                    CLR_BIT(DIO_PORTA_Reg,Local_u8Pin);
                }
                else
                {
                    SET_BIT(DIO_PORTA_Reg,Local_u8Pin);
                }   
            break;
            case DIO_PORTB:
                if(Copy_u8Level==DIO_CHANNEL_LOW)
                {
                    CLR_BIT(DIO_PORTB_Reg,Local_u8Pin);
                }
                else
                {
                    SET_BIT(DIO_PORTB_Reg,Local_u8Pin);
                }                          
            break;
            case DIO_PORTC:
                if(Copy_u8Level==DIO_CHANNEL_LOW)
                {
                    CLR_BIT(DIO_PORTC_Reg,Local_u8Pin);
                }
                else
                {
                    SET_BIT(DIO_PORTC_Reg,Local_u8Pin);
                }  
            break;
            case DIO_PORTD:
                if(Copy_u8Level==DIO_CHANNEL_LOW)
                {
                    CLR_BIT(DIO_PORTD_Reg,Local_u8Pin);
                }
                else
                {
                    SET_BIT(DIO_PORTD_Reg,Local_u8Pin);
                }  
            break;
            default :
                /*DO NOTHING*/
            break;
        }   
    }  
    return Local_u8Status;
}



DIO_tenuErrorStatus DIO_enuReadChannel(u8 Copy_u8ChannelId , pu8 Add_Pu8ChannelLevel){
    DIO_tenuErrorStatus Local_u8Status = DIO_OK;
    if((Copy_u8ChannelId>31)||(Copy_u8ChannelId<0))
    {
        Local_u8Status = DIO_WRONGCHANNEL;
    }
    else if(Add_Pu8ChannelLevel==NULL)
    {
        Local_u8Status = DIO_NULLPTR;
    }
    else{
        u8 Local_u8Port = Copy_u8ChannelId/8;
        u8 Local_u8Pin = Copy_u8ChannelId%8;
        switch(Local_u8Port){
            case DIO_PORTA : 
              *Add_Pu8ChannelLevel =  GET_BIT(DIO_PINA_Reg,Local_u8Pin);
            break;

            case DIO_PORTB :
                *Add_Pu8ChannelLevel =  GET_BIT(DIO_PINB_Reg,Local_u8Pin);
            break;

            case DIO_PORTC :
                *Add_Pu8ChannelLevel =  GET_BIT(DIO_PINC_Reg,Local_u8Pin);
            break;

            case DIO_PORTD :
              *Add_Pu8ChannelLevel =  GET_BIT(DIO_PIND_Reg,Local_u8Pin);
            break;

            default:
                /*DO NOTHING*/
            break;
        }
    }
    return Local_u8Status;
}


DIO_tenuErrorStatus Dio_enuWritePort(u8 Copy_u8PortId , u8 Copy_u8Level){
    DIO_tenuErrorStatus Local_u8Status = DIO_OK;

    if((Copy_u8PortId>3)||(Copy_u8PortId<0))
    {
        Local_u8Status = DIO_WRONGCHANNEL;
    }
    else{
        switch(Copy_u8PortId){
            case DIO_PORTA : 
                ASSIGN_REG(DIO_PORTA_Reg,Copy_u8Level);
            break;

            case DIO_PORTB :
                ASSIGN_REG(DIO_PORTB_Reg,Copy_u8Level);
            break;

            case DIO_PORTC :
                ASSIGN_REG(DIO_PORTC_Reg,Copy_u8Level);
            break;

            case DIO_PORTD :
                ASSIGN_REG(DIO_PORTD_Reg,Copy_u8Level);
            break;

            default:
                /*DO NOTHING*/
            break;
        }
    }
    return Local_u8Status;

}
DIO_tenuErrorStatus DIO_enuFlipChannel(u8 Copy_u8ChannelId ){
     DIO_tenuErrorStatus Local_u8Status = DIO_OK;

    if((Copy_u8ChannelId>31)||(Copy_u8ChannelId<0))
    {
        Local_u8Status = DIO_WRONGCHANNEL;
    }
    else{
        u8 Local_u8Port = Copy_u8ChannelId/8;
        u8 Local_u8Pin = Copy_u8ChannelId%8;
        switch(Local_u8Port){
            case DIO_PORTA : 
                TGL_BIT(DIO_PORTA_Reg,Local_u8Pin);
            break;

            case DIO_PORTB :
                TGL_BIT(DIO_PORTB_Reg,Local_u8Pin);
            break;

            case DIO_PORTC :
                TGL_BIT(DIO_PORTC_Reg,Local_u8Pin);
            break;

            case DIO_PORTD :
                TGL_BIT(DIO_PORTD_Reg,Local_u8Pin);
            break;

            default:
                /*DO NOTHING*/
            break;
        }
    }
    return Local_u8Status;

}