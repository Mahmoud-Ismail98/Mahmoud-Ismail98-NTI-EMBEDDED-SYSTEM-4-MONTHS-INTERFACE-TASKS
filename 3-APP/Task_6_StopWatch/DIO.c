/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : DIO                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/
#include "Std_types.h"
#include "Bit_utils.h"

#include "DIO.h"
#include "DIO_prv.h"
#include "DIO_cfg.h"

/**
 * This function is used to set the level of a specific pin in the port. 
 * 
 * @param Copy_u8ChannelId which represents the pin number.
 * 
 * @param Copy_u8Level which represents the desired level for the pin. 
 * 
 * @return a value which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus DIO_enuWriteChannel(u8 Copy_u8ChannelId, u8 Copy_u8Level){
    /* defining a variable to hold the error state value */
	tenuErrorStatus local_eunErrorState = no_error;
    /* calculation pin number */
    u8 local_u8PinId = Copy_u8ChannelId %8;
    /* calculation port number */
    u8 local_u8PortId = Copy_u8ChannelId / 8 ;

    /* checking for error in ChannelId parameter */
    if (Copy_u8ChannelId > PORT_D_CHANNEL_7){
        local_eunErrorState = ERROR_wrongChannelID;
    } /* checking for error in Channel level */
    else if (Copy_u8Level > DIO_CHANNEL_LEVEL_HIGH){
        local_eunErrorState = ERROR_wrongPinModeParameter;
    } else {
        /* taking action based on desired level */
        if (Copy_u8Level){
            /* taking action based on desired Port */
            switch (local_u8PortId)
            {
            case 0: SET_BIT(PORTA, local_u8PinId); break;
            case 1: SET_BIT(PORTB, local_u8PinId); break;
            case 2: SET_BIT(PORTC, local_u8PinId); break;
            case 3: SET_BIT(PORTD, local_u8PinId); break;
            }
        }
        /* taking action based on desired level */
        else{
            /* taking action based on desired Port */
            switch (local_u8PortId)
            {
            case 0: CLR_BIT(PORTA, local_u8PinId); break;
            case 1: CLR_BIT(PORTB, local_u8PinId); break;
            case 2: CLR_BIT(PORTC, local_u8PinId); break;
            case 3: CLR_BIT(PORTD, local_u8PinId); break;
            }
        }
    }
    /* returning the error state */
    return local_eunErrorState;
}

/**
 * This function is used to read the level of a specific pin in the port. 
 * 
 * @param Copy_u8ChannelId which represents the pin number.
 * 
 * @param Add_pu8ChannelLevel which is a pointer to a u8 to save the current pin level. 
 * 
 * @return a value which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus DIO_enuReadChannel(u8 Copy_u8ChannelId, pu8 Add_pu8ChannelLevel){
    /* defining a variable to hold the error state value */
	tenuErrorStatus local_eunErrorState = no_error;
    /* calculation pin number */
    u8 local_u8PinId = Copy_u8ChannelId %8;
    /* calculation port number */
    u8 local_u8PortId = Copy_u8ChannelId / 8 ;
    /* checking for Null pointer error */
    if (Add_pu8ChannelLevel == NULL){
        local_eunErrorState = ERROR_nullPointer;
    }
    /* checking for error in ChannelId parameter */
    else if (Copy_u8ChannelId > PORT_D_CHANNEL_7){
        local_eunErrorState = ERROR_wrongChannelID;
    }else {
            /* taking action based on desired Port */
            switch (local_u8PortId)
            {
            case 0: *Add_pu8ChannelLevel = GET_BIT(PINA, local_u8PinId); break;
            case 1: *Add_pu8ChannelLevel = GET_BIT(PINB, local_u8PinId); break;
            case 2: *Add_pu8ChannelLevel = GET_BIT(PINC, local_u8PinId); break;
            case 3: *Add_pu8ChannelLevel = GET_BIT(PIND, local_u8PinId); break;
            }
    }
    /* returning the error state */
    return local_eunErrorState;
}

/**
 * This function is used to set the level for a full port . 
 * 
 * @param Copy_u8PortId indicates which port we want change it's value.
 * 
 * @param Copy_u8Value the value to be copped to the specific port. 
 * 
 * @return a value which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus DIO_enuWritePort(u8 Copy_u8PortId,u8 Copy_u8Value){
    /* defining a variable to hold the error state value */
	tenuErrorStatus local_eunErrorState = no_error;
    /* checking for error in ChannelId parameter */
    if (Copy_u8PortId > PORTD_ID){
        local_eunErrorState = ERROR_wrongPortID;
    }else {
        /* taking action based on desired Port */
        switch (Copy_u8PortId)
        {
        case PORTA_ID: PORTA = Copy_u8Value; break;
        case PORTB_ID: PORTB = Copy_u8Value; break;
        case PORTC_ID: PORTC = Copy_u8Value; break;
        case PORTD_ID: PORTD = Copy_u8Value; break;
        }
    }
    /* returning the error state */
    return local_eunErrorState;
}

/**
 * This function is used to read the level of a specific port. 
 * 
 * @param Copy_u8PortId which represents the port we want read it's value.
 * 
 * @param Add_pu8PortValue which is a pointer to a u8 to save the current port value. 
 * 
 * @return a value which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus DIO_enuReadPort(u8 Copy_u8PortId, pu8 Add_pu8PortValue){
    /* defining a variable to hold the error state value */
	tenuErrorStatus local_eunErrorState = no_error;
    /* checking for Null pointer error */
    if (Add_pu8PortValue == NULL){
        local_eunErrorState = ERROR_nullPointer;
    }/* checking for error in PortID parameter */
    else if (Copy_u8PortId > PORTD_ID){
        local_eunErrorState = ERROR_wrongPortID;
    }else {
        /* taking action based on desired Port */
        switch (Copy_u8PortId)
        {
        case PORTA_ID: *Add_pu8PortValue =  PORTA ; break;
        case PORTB_ID: *Add_pu8PortValue =  PORTB ; break;
        case PORTC_ID: *Add_pu8PortValue =  PORTC ; break;
        case PORTD_ID: *Add_pu8PortValue =  PORTD ; break;
        }
    }
    /* returning the error state */
    return local_eunErrorState;
}

/**
 * This function is used to flip the level of a specific pin. 
 * 
 * @param Copy_u8ChannelId which represents the pin we want flip it's level.
 * 
 * @return a value which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus DIO_enuFlipChannel(u8 Copy_u8ChannelId){
    /* defining a variable to hold the error state value */
	tenuErrorStatus local_eunErrorState = no_error;
    /* calculation pin number */
    u8 local_u8PinId = Copy_u8ChannelId %8;
    /* calculation port number */
    u8 local_u8PortId = Copy_u8ChannelId / 8 ;

    /* checking for error in ChannelId parameter */
    if (Copy_u8ChannelId > PORT_D_CHANNEL_7){
        local_eunErrorState = ERROR_wrongChannelID;
    } else {
        /* taking action based on desired Port */
        switch (local_u8PortId)
        {
        case 0: TGL_BIT(PORTA, local_u8PinId); break;
        case 1: TGL_BIT(PORTB, local_u8PinId); break;
        case 2: TGL_BIT(PORTC, local_u8PinId); break;
        case 3: TGL_BIT(PORTD, local_u8PinId); break;
        }
    }
    /* returning the error state */
    return local_eunErrorState;
}
