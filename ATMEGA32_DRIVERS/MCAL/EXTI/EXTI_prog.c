#include "std_types.h"
#include "Bit_utils.h"

#include "EXTI.h"
#include "EXTI_cfg.h"
#include "EXTI_priv.h"

 /*This is the pointer to function*/
static volatile void (* Ext_INT0_ptr) (void); 

/***************************************************************************************/
/* Description: Initialize the External Interrupts controller with the specified      */
/*              interrupt number and triggering mode.                                */
/* Input      : None                                                                */
/* Output     : None                                                                */
/***************************************************************************************/
void ExtI_voidInitialize(void) {
    // Enable the selected external interrupt (INT0, INT1, or INT2) based on configuration.
    // Use the preprocessor macros EXTI_NUM and EXTI_MODE for configuration.
    #if EXTI_NUM == INT0
        SET_BIT(GICR, INT0);
    #elif EXTI_NUM == INT1
        SET_BIT(GICR, INT1);
    #elif EXTI_NUM == INT2
        SET_BIT(GICR, INT2);
    #endif

    // Configure the triggering mode of the selected external interrupt based on EXTI_MODE.
    // Configure INT0 and INT1 using MCUCR, and INT2 using MCUCSR.
    #if EXTI_MODE == LOW_LEVEL && EXTI_NUM == INT0
        CLR_BIT(MCUCR, 0);
        CLR_BIT(MCUCR, 1);
    #elif EXTI_MODE == ANY_CHANGE && EXTI_NUM == INT0
        SET_BIT(MCUCR, 0);
        CLR_BIT(MCUCR, 1);
    #elif EXTI_MODE == FALLING_EDGE && EXTI_NUM == INT0
        CLR_BIT(MCUCR, 0);
        SET_BIT(MCUCR, 1);
    #elif EXTI_MODE == RISING_EDGE && EXTI_NUM == INT0
        SET_BIT(MCUCR, 0);
        SET_BIT(MCUCR, 1);
    #endif

    #if EXTI_MODE == LOW_LEVEL && EXTI_NUM == INT1
        CLR_BIT(MCUCR, 2);
        CLR_BIT(MCUCR, 3);
    #elif EXTI_MODE == ANY_CHANGE && EXTI_NUM == INT1
        SET_BIT(MCUCR, 2);
        CLR_BIT(MCUCR, 3);
    #elif EXTI_MODE == FALLING_EDGE && EXTI_NUM == INT1
        CLR_BIT(MCUCR, 2);
        SET_BIT(MCUCR, 3);
    #elif EXTI_MODE == RISING_EDGE && EXTI_NUM == INT1
        SET_BIT(MCUCR, 2);
        SET_BIT(MCUCR, 3);
    #endif

    #if EXTI_MODE == FALLING_EDGE && EXTI_NUM == INT2
        CLR_BIT(MCUCSR, 6);
    #elif EXTI_MODE == RISING_EDGE && EXTI_NUM == INT2
        SET_BIT(MCUCSR, 6);
    #endif
}




/***************************************************************************************/
/* Description: Enable the external interrupt with the specified interrupt number.     */
/* Input      : None                                                                */
/* Output     : None                                                                */
/***************************************************************************************/
void ExtI_voidEnableExtI(void) {
    // Enable the selected external interrupt (INT0, INT1, or INT2) based on configuration.
    // Use the preprocessor macros EXTI_NUM for configuration.
    #if EXTI_NUM == INT0
        SET_BIT(GICR, INT0);
    #elif EXTI_NUM == INT1
        SET_BIT(GICR, INT1);
    #elif EXTI_NUM == INT2
        SET_BIT(GICR, INT2);
    #endif
}


/***************************************************************************************/
/* Description: Disable the external interrupt with the specified interrupt number.    */
/* Input      : None                                                                */
/* Output     : None                                                                */
/***************************************************************************************/
void ExtI_voidDisableExtI(void) {
    // Disable the selected external interrupt (INT0, INT1, or INT2) based on configuration.
    // Use the preprocessor macros EXTI_NUM for configuration.
    #if EXTI_NUM == INT0
        CLR_BIT(GICR, INT0);
    #elif EXTI_NUM == INT1
        CLR_BIT(GICR, INT1);
    #elif EXTI_NUM == INT2
        CLR_BIT(GICR, INT2);
    #endif
}


/***************************************************************************************/
/* Description: Get the status of the external interrupt 0 (INT0) flag.               */
/* Input      : None                                                                */
/* Output     : u8 - Status of the INT0 interrupt flag (ENABLED or DISABLED).        */
/***************************************************************************************/
u8 ExtI_u8ExtInterrupt0FlagStatus(void) {
    // Check the status of the INT0 interrupt flag in the GIFR register.
    if (CHECK_BIT(GIFR, INTF0) == ENABLED) {
        return ENABLED;
    } else {
        return DISABLED;
    }
}





/****************** POST_BUILD_CONFIGURATIONS To use More Than one interrupt and to change in Run Time *********************************/
void EnableExtI0(void) {
    SET_BIT(GICR, INT0);
}

void EnableExtI1(void) {
    SET_BIT(GICR, INT1);
}

void EnableExtI2(void) {
    SET_BIT(GICR, INT2);
}

void DisableExtI0(void) {
    CLR_BIT(GICR, INT0);
}

void DisableExtI1(void) {
    CLR_BIT(GICR, INT1);
}

void DisableExtI2(void) {
    CLR_BIT(GICR, INT2);
}

	




/***************************************************************************************/
/* Description: Set the callback function to be executed when an external interrupt   */
/*              (INT0) occurs.                                                      */
/* Input      : I_ptr - Pointer to the callback function.                            */
/* Output     : None                                                                */
/***************************************************************************************/
void ExtI_voidSetCallBack(void (*I_ptr)(void)) {
    // Set the callback function for the external interrupt (INT0).
    Ext_INT0_ptr = I_ptr;
}





/***************************************************************************************/
/* Description: Interrupt Service Routine (ISR) for external interrupt 0 (INT0).      */
/*              This ISR calls the user-defined callback function.                   */
/* Input      : None                                                                */
/* Output     : None                                                                */
/***************************************************************************************/
void __vector_1(void) __attribute((signal, used));
void __vector_1(void) {
    // Call the user-defined callback function when INT0 interrupt occurs.
    Ext_INT0_ptr();
}



