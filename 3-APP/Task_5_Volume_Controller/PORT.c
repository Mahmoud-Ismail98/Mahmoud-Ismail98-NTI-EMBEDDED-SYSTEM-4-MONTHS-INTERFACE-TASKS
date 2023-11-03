/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : PORT                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/
#include "Std_types.h"
#include "Bit_utils.h"

#include "PORT.h"
#include "PORT_prv.h"
#include "PORT_cfg.h"

#define CONC(B7,B6,B5,B4,B3,B2,B1,B0)   CONC_HELPER(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELPER(B7,B6,B5,B4,B3,B2,B1,B0) 0b##B7##B6##B5##B4##B3##B2##B1##B0

/**
* this function is used to initialize the port module. 
* It sets the initial configuration for all the pins in the port. 

* @return: a value which indicates whether the initialization was successful or if there was an error.
*/
tenuErrorStatus PORT_enuInit(){
    /* defining a variable to hold the error state value */
	tenuErrorStatus local_error_state = no_error;

    /* preparing the macros for concatenation */
    #undef PORT_MODE_OUTPUT_LOW            
    #define PORT_MODE_OUTPUT_LOW            1

    #undef PORT_MODE_OUTPUT_HIGH           
    #define PORT_MODE_OUTPUT_HIGH           1

    #undef PORT_MODE_INPUT_FLOATING        
    #define PORT_MODE_INPUT_FLOATING        0

    #undef PORT_MODE_INPUT_PULLUP          
    #define PORT_MODE_INPUT_PULLUP          0

    DDRA = CONC(PORT_A_PIN_7_CFG,PORT_A_PIN_6_CFG,PORT_A_PIN_5_CFG,PORT_A_PIN_4_CFG,PORT_A_PIN_3_CFG,PORT_A_PIN_2_CFG,PORT_A_PIN_1_CFG,PORT_A_PIN_0_CFG);
    DDRB = CONC(PORT_B_PIN_7_CFG,PORT_B_PIN_6_CFG,PORT_B_PIN_5_CFG,PORT_B_PIN_4_CFG,PORT_B_PIN_3_CFG,PORT_B_PIN_2_CFG,PORT_B_PIN_1_CFG,PORT_B_PIN_0_CFG);
    DDRC = CONC(PORT_C_PIN_7_CFG,PORT_C_PIN_6_CFG,PORT_C_PIN_5_CFG,PORT_C_PIN_4_CFG,PORT_C_PIN_3_CFG,PORT_C_PIN_2_CFG,PORT_C_PIN_1_CFG,PORT_C_PIN_0_CFG);
    DDRD = CONC(PORT_D_PIN_7_CFG,PORT_D_PIN_6_CFG,PORT_D_PIN_5_CFG,PORT_D_PIN_4_CFG,PORT_D_PIN_3_CFG,PORT_D_PIN_2_CFG,PORT_D_PIN_1_CFG,PORT_D_PIN_0_CFG);

    /* preparing the macros for concatenation */
    #undef PORT_MODE_OUTPUT_LOW            
    #define PORT_MODE_OUTPUT_LOW            0

    #undef PORT_MODE_OUTPUT_HIGH           
    #define PORT_MODE_OUTPUT_HIGH           1

    #undef PORT_MODE_INPUT_FLOATING        
    #define PORT_MODE_INPUT_FLOATING        0

    #undef PORT_MODE_INPUT_PULLUP          
    #define PORT_MODE_INPUT_PULLUP          1


    PORTA = CONC(PORT_A_PIN_7_CFG,PORT_A_PIN_6_CFG,PORT_A_PIN_5_CFG,PORT_A_PIN_4_CFG,PORT_A_PIN_3_CFG,PORT_A_PIN_2_CFG,PORT_A_PIN_1_CFG,PORT_A_PIN_0_CFG);
    PORTB = CONC(PORT_B_PIN_7_CFG,PORT_B_PIN_6_CFG,PORT_B_PIN_5_CFG,PORT_B_PIN_4_CFG,PORT_B_PIN_3_CFG,PORT_B_PIN_2_CFG,PORT_B_PIN_1_CFG,PORT_B_PIN_0_CFG);
    PORTC = CONC(PORT_C_PIN_7_CFG,PORT_C_PIN_6_CFG,PORT_C_PIN_5_CFG,PORT_C_PIN_4_CFG,PORT_C_PIN_3_CFG,PORT_C_PIN_2_CFG,PORT_C_PIN_1_CFG,PORT_C_PIN_0_CFG);
    PORTD = CONC(PORT_D_PIN_7_CFG,PORT_D_PIN_6_CFG,PORT_D_PIN_5_CFG,PORT_D_PIN_4_CFG,PORT_D_PIN_3_CFG,PORT_D_PIN_2_CFG,PORT_D_PIN_1_CFG,PORT_D_PIN_0_CFG);

    /* returning macros to there default values */
    #define PORT_MODE_OUTPUT_LOW            0
    #define PORT_MODE_OUTPUT_HIGH           1
    #define PORT_MODE_INPUT_FLOATING        2
    #define PORT_MODE_INPUT_PULLUP          3

    /* returning the error state */
    return local_error_state;
}

/**
 * This function is used to set the mode of a specific pin in the port. 
 * 
 * @param Copy_u8PinNum which represents the pin number.
 * 
 * @param Copy_u8PinMode which represents the desired mode for the pin. 
 * 
 * @return a value which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus PORT_enuSetPinMode(u8 Copy_u8PinNum, u8 Copy_u8PinMode){
    /* defining a variable to hold the error state value */
	tenuErrorStatus local_error_state = no_error;
    /* calculation port number */
    u8 local_u8portId = Copy_u8PinNum / 8;
    /* calculation pin number */
    u8 local_u8PinId = Copy_u8PinNum % 8;
    /* checking for error in Pin Num parameter */
    if (Copy_u8PinNum > PORT_D_PIN_7 ){
        local_error_state = ERROR_wrongPinNumber;
    }/* checking for error in Mode parameter */
    else if (Copy_u8PinMode > PORT_ModePullUp){
        local_error_state = ERROR_wrongPinModeParameter;
    }
    else {
        /* taking action based on desired mode */
        if (Copy_u8PinMode == PORT_ModeHigh || Copy_u8PinMode == PORT_ModePullUp){
            /* taking action based on desired Port */
            switch (local_u8portId)
            {
            case 0: SET_BIT(PORTA, local_u8PinId); break;
            case 1: SET_BIT(PORTB, local_u8PinId); break;
            case 2: SET_BIT(PORTC, local_u8PinId); break;
            case 3: SET_BIT(PORTD, local_u8PinId); break;
            }
        }/* taking action based on desired mode */
        else if (Copy_u8PinMode == PORT_ModeLow || Copy_u8PinMode == PORT_ModeFloating){
            /* taking action based on desired Port */
            switch (local_u8portId)
            {
            case 0: CLR_BIT(PORTA, local_u8PinId); break;
            case 1: CLR_BIT(PORTB, local_u8PinId); break;
            case 2: CLR_BIT(PORTC, local_u8PinId); break;
            case 3: CLR_BIT(PORTD, local_u8PinId); break;
            }
        }
            
    }
    /* returning the error state */
    return local_error_state;
}

/**
 * This function is used to set the direction of a specific pin in the port. 
 * 
 * @param Copy_u8PinNum which represents the pin number.
 * 
 * @param Copy_u8PinMode which represents the desired mode for the pin. 
 * 
 * @return a value which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus PORT_enuSetPinDirection(u8 Copy_u8PinNum, u8 Copy_u8PinDirection){
    /* defining a variable to hold the error state value */
	tenuErrorStatus local_error_state = no_error;
    /* calculation port number */
    u8 local_u8portId = Copy_u8PinNum / 8;
    /* calculation pin number */
    u8 local_u8PinId = Copy_u8PinNum % 8;
    /* checking for error in Pin Num parameter */
    if (Copy_u8PinNum > PORT_D_PIN_7 ){
        local_error_state = ERROR_wrongPinNumber;
    }/* checking for error in Direction parameter */
    else if (Copy_u8PinDirection > PORT_ModePullUp){
        local_error_state = ERROR_wrongPinModeParameter;
    }
    else {/* taking action based on desired direction */
        if (Copy_u8PinDirection == PORT_directionOutput){
            /* taking action based on desired Port */
            switch (local_u8portId)
            {
            case 0: SET_BIT(DDRA, local_u8PinId); break;
            case 1: SET_BIT(DDRB, local_u8PinId); break;
            case 2: SET_BIT(DDRC, local_u8PinId); break;
            case 3: SET_BIT(DDRD, local_u8PinId); break;
            }
        }/* taking action based on desired direction */
        else if (Copy_u8PinDirection == PORT_directionInput){
            /* taking action based on desired Port */
            switch (local_u8portId)
            {
            case 0: CLR_BIT(DDRA, local_u8PinId); break;
            case 1: CLR_BIT(DDRB, local_u8PinId); break;
            case 2: CLR_BIT(DDRC, local_u8PinId); break;
            case 3: CLR_BIT(DDRD, local_u8PinId); break;
            }
        }
            
    }
    /* returning the error state */
    return local_error_state;
}
