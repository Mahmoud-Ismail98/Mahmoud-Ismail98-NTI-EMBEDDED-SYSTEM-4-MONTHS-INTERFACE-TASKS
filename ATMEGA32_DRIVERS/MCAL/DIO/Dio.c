
#include "Bit_utils.h"     
#include "Std_types.h"	 
#include "Dio_cfg.h"
#include "Dio_prv.h"
#include "Dio.h"
			
#include <avr/io.h>			

/***************************************************************************************/
/* Description: Write a digital level to a specific channel on a selected port.      */
/* Input      : Copy_u8ChannelId - Channel ID (0 to 31)                               */
/*              Copy_u8Level - Desired digital level (DIO_u8LEVEL_HIGH or DIO_u8LEVEL_LOW) */
/* Output     : Dio_tenuErrorStatus - Status indicating success or an error condition */
/***************************************************************************************/
Dio_tenuErrorStatus Dio_enuWriteChannel(u8 Copy_u8ChannelId, u8 Copy_u8Level) {
    Dio_tenuErrorStatus LOC_enuReturnStatus = Dio_enuOk;
    u8 LOC_u8Port;
    u8 LOC_u8Pin;

    if (Copy_u8ChannelId > DIO_u8NUMBER_OF_CHANNELS) {
        LOC_enuReturnStatus = Dio_enuChannelError;
    } else if (Copy_u8Level > DIO_u8NUMBER_OF_LEVELS) {
        LOC_enuReturnStatus = Dio_enuLevelError;
    } else {
        LOC_u8Port = Copy_u8ChannelId / DIO_u8REGISTER_SIZE;
        LOC_u8Pin = Copy_u8ChannelId % DIO_u8REGISTER_SIZE;

        /* Determine the port and write the level accordingly */
        switch (LOC_u8Port) {
            case DIO_u8PORTA:
                if (GET_BIT(DDRA, LOC_u8Pin) == DIO_u8OUTPUT) {
                    switch (Copy_u8Level) {
                        case DIO_u8LEVEL_HIGH:
                            SET_BIT(PORTA, LOC_u8Pin);
                            break;
                        case DIO_u8LEVEL_LOW:
                            CLR_BIT(PORTA, LOC_u8Pin);
                            break;
                    }
                } else {
                    LOC_enuReturnStatus = Dio_enuDirectionError;
                }
                break;

            case DIO_u8PORTB:
                if (GET_BIT(DDRB, LOC_u8Pin) == DIO_u8OUTPUT) {
                    switch (Copy_u8Level) {
                        case DIO_u8LEVEL_HIGH:
                            SET_BIT(PORTB, LOC_u8Pin);
                            break;
                        case DIO_u8LEVEL_LOW:
                            CLR_BIT(PORTB, LOC_u8Pin);
                            break;
                    }
                } else {
                    LOC_enuReturnStatus = Dio_enuDirectionError;
                }
                break;

            case DIO_u8PORTC:
                if (GET_BIT(DDRC, LOC_u8Pin) == DIO_u8OUTPUT) {
                    switch (Copy_u8Level) {
                        case DIO_u8LEVEL_HIGH:
                            SET_BIT(PORTC, LOC_u8Pin);
                            break;
                        case DIO_u8LEVEL_LOW:
                            CLR_BIT(PORTC, LOC_u8Pin);
                            break;
                    }
                } else {
                    LOC_enuReturnStatus = Dio_enuDirectionError;
                }
                break;

            case DIO_u8PORTD:
                if (GET_BIT(DDRD, LOC_u8Pin) == DIO_u8OUTPUT) {
                    switch (Copy_u8Level) {
                        case DIO_u8LEVEL_HIGH:
                            SET_BIT(PORTD, LOC_u8Pin);
                            break;
                        case DIO_u8LEVEL_LOW:
                            CLR_BIT(PORTD, LOC_u8Pin);
                            break;
                    }
                } else {
                    LOC_enuReturnStatus = Dio_enuDirectionError;
                }
                break;
        }
    }

    /* Return the error status */
    return LOC_enuReturnStatus;
}

/***************************************************************************************/
/* Description: Read the digital level of a specific channel on a selected port.     */
/* Input      : Copy_u8ChannelId - Channel ID (0 to 31)                               */
/*              Add_pu8ChannelLevel - Pointer to store the channel level               */
/* Output     : Dio_tenuErrorStatus - Status indicating success or an error condition */
/***************************************************************************************/
Dio_tenuErrorStatus Dio_enuReadChannel(u8 Copy_u8ChannelId, pu8 Add_pu8ChannelLevel) {
    Dio_tenuErrorStatus LOC_enuReturnStatus = Dio_enuOk;
    u8 LOC_u8Port;
    u8 LOC_u8Pin;

    if (Copy_u8ChannelId > DIO_u8NUMBER_OF_CHANNELS) {
        LOC_enuReturnStatus = Dio_enuChannelError;
    } else if (Add_pu8ChannelLevel == NULL) {
        LOC_enuReturnStatus = Dio_enuNullPointerError;
    } else {
        LOC_u8Port = Copy_u8ChannelId / DIO_u8REGISTER_SIZE;
        LOC_u8Pin = Copy_u8ChannelId % DIO_u8REGISTER_SIZE;

        /* Determine the port and read the channel level accordingly */
        switch (LOC_u8Port) {
            case DIO_u8PORTA:
                if (GET_BIT(DDRA, LOC_u8Pin) == DIO_u8INPUT) {
                    *Add_pu8ChannelLevel = GET_BIT(PINA, LOC_u8Pin);
                } else {
                    LOC_enuReturnStatus = Dio_enuDirectionError;
                }
                break;

            case DIO_u8PORTB:
                if (GET_BIT(DDRB, LOC_u8Pin) == DIO_u8INPUT) {
                    *Add_pu8ChannelLevel = GET_BIT(PINB, LOC_u8Pin);
                } else {
                    LOC_enuReturnStatus = Dio_enuDirectionError;
                }
                break;

            case DIO_u8PORTC:
                if (GET_BIT(DDRC, LOC_u8Pin) == DIO_u8INPUT) {
                    *Add_pu8ChannelLevel = GET_BIT(PINC, LOC_u8Pin);
                } else {
                    LOC_enuReturnStatus = Dio_enuDirectionError;
                }
                break;

            case DIO_u8PORTD:
                if (GET_BIT(DDRD, LOC_u8Pin) == DIO_u8INPUT) {
                    *Add_pu8ChannelLevel = GET_BIT(PIND, LOC_u8Pin);
                } else {
                    LOC_enuReturnStatus = Dio_enuDirectionError;
                }
                break;
        }
    }
    return LOC_enuReturnStatus;
}
/***************************************************************************************/
/* Description: Write a digital value to all channels of a specific port.             */
/* Input      : Copy_u8PortId - Port ID (DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD) */
/*              Copy_u8Value - Desired digital value for all channels (0x00 to 0xFF)  */
/* Output     : Dio_tenuErrorStatus - Status indicating success or an error condition */
/***************************************************************************************/
Dio_tenuErrorStatus Dio_enuWritePort(u8 Copy_u8PortId, u8 Copy_u8Value) {
    Dio_tenuErrorStatus LOC_enuReturnStatus = Dio_enuOk;

    if (Copy_u8PortId > DIO_u8NUMBER_OF_PORTS) {
        LOC_enuReturnStatus = Dio_enuPortRangeError;
    } else {
        switch (Copy_u8PortId) {
            case DIO_u8PORTA:
                ASSIGN_REG(PORTA, Copy_u8Value);
                break;

            case DIO_u8PORTB:
                ASSIGN_REG(PORTB, Copy_u8Value);
                break;

            case DIO_u8PORTC:
                ASSIGN_REG(PORTC, Copy_u8Value);
                break;

            case DIO_u8PORTD:
                ASSIGN_REG(PORTD, Copy_u8Value);
                break;
        }
    }
    return LOC_enuReturnStatus;
}
/***************************************************************************************/
/* Description: Read the digital value of all channels on a specific port.             */
/* Input      : Copy_u8PortId - Port ID (DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD) */
/*              Add_pu8PortValue - Pointer to store the port's digital value           */
/* Output     : Dio_tenuErrorStatus - Status indicating success or an error condition */
/***************************************************************************************/
Dio_tenuErrorStatus Dio_enuReadPort(u8 Copy_u8PortId, pu8 Add_pu8PortValue) {
    Dio_tenuErrorStatus LOC_enuReturnStatus = Dio_enuOk;

    if (Add_pu8PortValue == NULL) {
        LOC_enuReturnStatus = Dio_enuNullPointerError;
    } else if (Copy_u8PortId > DIO_u8NUMBER_OF_PORTS) {
        LOC_enuReturnStatus = Dio_enuPortRangeError;
    } else {
        switch (Copy_u8PortId) {
            case DIO_u8PORTA:
                *Add_pu8PortValue = PINA;
                break;

            case DIO_u8PORTB:
                *Add_pu8PortValue = PINB;
                break;

            case DIO_u8PORTC:
                *Add_pu8PortValue = PINC;
                break;

            case DIO_u8PORTD:
                *Add_pu8PortValue = PIND;
                break;
        }
    }
    return LOC_enuReturnStatus;
}
/***************************************************************************************/
/* Description: Toggle the digital level of a specific channel on a selected port.    */
/* Input      : Copy_u8ChannelId - Channel ID (0 to 31)                               */
/* Output     : Dio_tenuErrorStatus - Status indicating success or an error condition */
/***************************************************************************************/
Dio_tenuErrorStatus Dio_enuFlipChannel(u8 Copy_u8ChannelId) {
    Dio_tenuErrorStatus LOC_enuReturnStatus = Dio_enuOk;
    u8 LOC_u8Port;
    u8 LOC_u8Pin;

    if (Copy_u8ChannelId > DIO_u8NUMBER_OF_CHANNELS) {
        LOC_enuReturnStatus = Dio_enuChannelError;
    } else {
        LOC_u8Port = Copy_u8ChannelId / DIO_u8REGISTER_SIZE;
        LOC_u8Pin = Copy_u8ChannelId % DIO_u8REGISTER_SIZE;

        /* Determine the port and toggle the channel level accordingly */
        switch (LOC_u8Port) {
            case DIO_u8PORTA:
                if (GET_BIT(DDRA, LOC_u8Pin) == DIO_u8OUTPUT) {
                    TGL_BIT(PORTA, LOC_u8Pin);
                }
                break;

            case DIO_u8PORTB:
                if (GET_BIT(DDRB, LOC_u8Pin) == DIO_u8OUTPUT) {
                    TGL_BIT(PORTB, LOC_u8Pin);
                }
                break;

            case DIO_u8PORTC:
                if (GET_BIT(DDRC, LOC_u8Pin) == DIO_u8OUTPUT) {
                    TGL_BIT(PORTC, LOC_u8Pin);
                }
                break;

            case DIO_u8PORTD:
                if (GET_BIT(DDRD, LOC_u8Pin) == DIO_u8OUTPUT) {
                    TGL_BIT(PORTD, LOC_u8Pin);
                }
                break;
        }
    }
    return LOC_enuReturnStatus;
}
