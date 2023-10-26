
#include <avr/io.h>

#include "Bit_utils.h"    
#include "Std_types.h"	 
#include "Port.h"		
#include "Port_cfg.h"	
#include "Port_prv.h"	

/***************************************************************************************/
/* Description: Initialize the ports for input and output configurations                */
/* Input      : None                                                                */
/* Output     : None                                                                */
/***************************************************************************************/
void Port_vidInit(void)
{
    /* Configure Data Direction Registers (DDRx) for Ports A, B, C, and D */
    DDRA = CONC(PORT_u8MODEPIN07, PORT_u8MODEPIN06, PORT_u8MODEPIN05, PORT_u8MODEPIN04, PORT_u8MODEPIN03, PORT_u8MODEPIN02, PORT_u8MODEPIN01, PORT_u8MODEPIN00);
    DDRB = CONC(PORT_u8MODEPIN15, PORT_u8MODEPIN14, PORT_u8MODEPIN13, PORT_u8MODEPIN12, PORT_u8MODEPIN11, PORT_u8MODEPIN10, PORT_u8MODEPIN09, PORT_u8MODEPIN08);
    DDRC = CONC(PORT_u8MODEPIN23, PORT_u8MODEPIN22, PORT_u8MODEPIN21, PORT_u8MODEPIN20, PORT_u8MODEPIN19, PORT_u8MODEPIN18, PORT_u8MODEPIN17, PORT_u8MODEPIN16);
    DDRD = CONC(PORT_u8MODEPIN31, PORT_u8MODEPIN30, PORT_u8MODEPIN29, PORT_u8MODEPIN28, PORT_u8MODEPIN27, PORT_u8MODEPIN26, PORT_u8MODEPIN25, PORT_u8MODEPIN24);

    /* Configure Port Data Registers (PORTx) for Ports A, B, C, and D */
    PORTA = CONC(PORT_u8MODEPIN07, PORT_u8MODEPIN06, PORT_u8MODEPIN05, PORT_u8MODEPIN04, PORT_u8MODEPIN03, PORT_u8MODEPIN02, PORT_u8MODEPIN01, PORT_u8MODEPIN00);
    PORTB = CONC(PORT_u8MODEPIN15, PORT_u8MODEPIN14, PORT_u8MODEPIN13, PORT_u8MODEPIN12, PORT_u8MODEPIN11, PORT_u8MODEPIN10, PORT_u8MODEPIN09, PORT_u8MODEPIN08);
    PORTC = CONC(PORT_u8MODEPIN23, PORT_u8MODEPIN22, PORT_u8MODEPIN21, PORT_u8MODEPIN20, PORT_u8MODEPIN19, PORT_u8MODEPIN18, PORT_u8MODEPIN17, PORT_u8MODEPIN16);
    PORTD = CONC(PORT_u8MODEPIN31, PORT_u8MODEPIN30, PORT_u8MODEPIN29, PORT_u8MODEPIN28, PORT_u8MODEPIN27, PORT_u8MODEPIN26, PORT_u8MODEPIN25, PORT_u8MODEPIN24);

    /* Reset the configurations of pull-up resistors, output levels, and input floating */
    #undef 	PORT_u8INPUT_PULLUP
    #undef 	PORT_u8OUTPUT_LOW
    #undef 	PORT_u8INPUT_FLOATING

    /* Define constants for pull-up resistors, output low, and input floating */
    #define PORT_u8OUTPUT_LOW 		0
    #define PORT_u8INPUT_FLOATING 	2
    #define PORT_u8INPUT_PULLUP 	3
}

/***************************************************************************************/
/* Description: Set the direction (input/output) of a specific pin on a selected port. */
/* Input      : Copy_u8PinNum - Pin number (0 to 31)                                */
/*              Copy_u8PinDirection - Desired pin direction (PORT_u8OUTPUT or PORT_u8INPUT) */
/* Output     : Port_tenuErrorStatus - Status indicating success or an error condition */
/***************************************************************************************/
Port_tenuErrorStatus Port_enuSetPinDirection(u8 Copy_u8PinNum, u8 Copy_u8PinDirection) {
    Port_tenuErrorStatus LOC_enuReturnStatus = Port_enuOk;
    u8 LOC_u8Port;
    u8 LOC_u8Pin;

    if (Copy_u8PinNum > PORT_u8NUMBER_OF_PINS) {
        LOC_enuReturnStatus = Port_enuPinError;
    } else if (Copy_u8PinDirection > PORT_u8NUMBER_OF_DIRECTION) {
        LOC_enuReturnStatus = Port_enuDirectionError;
    } else {
        LOC_u8Port = Copy_u8PinNum / PORT_u8REGISTER_SIZE;
        LOC_u8Pin = Copy_u8PinNum % PORT_u8REGISTER_SIZE;

        /* Determine the port and set the pin direction accordingly */
        switch (LOC_u8Port) {
            case PORT_u8PORTA:
                if (Copy_u8PinDirection == PORT_u8OUTPUT) {
                    SET_BIT(DDRA, LOC_u8Pin);
                } else {
                    CLR_BIT(DDRA, LOC_u8Pin);
                }
                break;

            case PORT_u8PORTB:
                if (Copy_u8PinDirection == PORT_u8OUTPUT) {
                    SET_BIT(DDRB, LOC_u8Pin);
                } else {
                    CLR_BIT(DDRB, LOC_u8Pin);
                }
                break;

            case PORT_u8PORTC:
                if (Copy_u8PinDirection == PORT_u8OUTPUT) {
                    SET_BIT(DDRC, LOC_u8Pin);
                } else {
                    CLR_BIT(DDRC, LOC_u8Pin);
                }
                break;

            case PORT_u8PORTD:
                if (Copy_u8PinDirection == PORT_u8OUTPUT) {
                    SET_BIT(DDRD, LOC_u8Pin);
                } else {
                    CLR_BIT(DDRD, LOC_u8Pin);
                }
                break;
        }
    }

    return LOC_enuReturnStatus;
}



/***************************************************************************************/
/* Description: Set the mode (input/output and pull-up) of a specific pin on a selected port. */
/* Input      : Copy_u8PinNum - Pin number (0 to 31)                                */
/*              Copy_u8PinMode - Desired pin mode (PORT_u8OUTPUT_LOW, PORT_u8OUTPUT_HIGH, PORT_u8INPUT_FLOATING, PORT_u8INPUT_PULLUP) */
/* Output     : Port_tenuErrorStatus - Status indicating success or an error condition */
/***************************************************************************************/
Port_tenuErrorStatus Port_enuSetPinMode(u8 Copy_u8PinNum, u8 Copy_u8PinMode) {
    Port_tenuErrorStatus LOC_enuReturnStatus = Port_enuOk;
    u8 LOC_u8Port;
    u8 LOC_u8Pin;

    if (Copy_u8PinNum > PORT_u8NUMBER_OF_PINS) {
        LOC_enuReturnStatus = Port_enuPinError;
    } else if (Copy_u8PinMode > PORT_u8INPUT_PULLUP) {
        LOC_enuReturnStatus = Port_enuDirectionError;
    } else {
        LOC_u8Port = Copy_u8PinNum / PORT_u8REGISTER_SIZE;
        LOC_u8Pin = Copy_u8PinNum % PORT_u8REGISTER_SIZE;

        /* Determine the port and set the pin mode accordingly */
        switch (LOC_u8Port) {
            case PORT_u8PORTA:
                switch (Copy_u8PinMode) {
                    case PORT_u8OUTPUT_LOW:
                        SET_BIT(DDRA, LOC_u8Pin);
                        CLR_BIT(PORTA, LOC_u8Pin);
                        break;
                    case PORT_u8OUTPUT_HIGH:
                        SET_BIT(DDRA, LOC_u8Pin);
                        SET_BIT(PORTA, LOC_u8Pin);
                        break;
                    case PORT_u8INPUT_FLOATING:
                        CLR_BIT(DDRA, LOC_u8Pin);
                        CLR_BIT(PORTA, LOC_u8Pin);
                        break;
                    case PORT_u8INPUT_PULLUP:
                        CLR_BIT(DDRA, LOC_u8Pin);
                        SET_BIT(PORTA, LOC_u8Pin);
                        break;
                }
                break;

            case PORT_u8PORTB:
                switch (Copy_u8PinMode) {
                    case PORT_u8OUTPUT_LOW:
                        SET_BIT(DDRB, LOC_u8Pin);
                        CLR_BIT(PORTB, LOC_u8Pin);
                        break;
                    case PORT_u8OUTPUT_HIGH:
                        SET_BIT(DDRB, LOC_u8Pin);
                        SET_BIT(PORTB, LOC_u8Pin);
                        break;
                    case PORT_u8INPUT_FLOATING:
                        CLR_BIT(DDRB, LOC_u8Pin);
                        CLR_BIT(PORTB, LOC_u8Pin);
                        break;
                    case PORT_u8INPUT_PULLUP:
                        CLR_BIT(DDRB, LOC_u8Pin);
                        SET_BIT(PORTB, LOC_u8Pin);
                        break;
                }
                break;

            case PORT_u8PORTC:
                switch (Copy_u8PinMode) {
                    case PORT_u8OUTPUT_LOW:
                        SET_BIT(DDRC, LOC_u8Pin);
                        CLR_BIT(PORTC, LOC_u8Pin);
                        break;
                    case PORT_u8OUTPUT_HIGH:
                        SET_BIT(DDRC, LOC_u8Pin);
                        SET_BIT(PORTC, LOC_u8Pin);
                        break;
                    case PORT_u8INPUT_FLOATING:
                        CLR_BIT(DDRC, LOC_u8Pin);
                        CLR_BIT(PORTC, LOC_u8Pin);
                        break;
                    case PORT_u8INPUT_PULLUP:
                        CLR_BIT(DDRC, LOC_u8Pin);
                        SET_BIT(PORTC, LOC_u8Pin);
                        break;
                }
                break;

            case PORT_u8PORTD:
                switch (Copy_u8PinMode) {
                    case PORT_u8OUTPUT_LOW:
                        SET_BIT(DDRD, LOC_u8Pin);
                        CLR_BIT(PORTD, LOC_u8Pin);
                        break;
                    case PORT_u8OUTPUT_HIGH:
                        SET_BIT(DDRD, LOC_u8Pin);
                        SET_BIT(PORTD, LOC_u8Pin);
                        break;
                    case PORT_u8INPUT_FLOATING:
                        CLR_BIT(DDRD, LOC_u8Pin);
                        CLR_BIT(PORTD, LOC_u8Pin);
                        break;
                    case PORT_u8INPUT_PULLUP:
                        CLR_BIT(DDRD, LOC_u8Pin);
                        SET_BIT(PORTD, LOC_u8Pin);
                        break;
                }
                break;
        }
    }

    /* Return the error status */
    return LOC_enuReturnStatus;
}
