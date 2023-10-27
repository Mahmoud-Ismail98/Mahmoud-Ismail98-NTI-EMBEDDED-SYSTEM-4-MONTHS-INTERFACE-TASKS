/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : KEYPAD              **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/
#ifndef KEYPAD_H
#define KEYPAD_H

/**
 * This function reads the state of a keypad and returns the corresponding symbol
 * based on the pressed button.
 * 
 * @return the value of a variable, which represents the button that was pressed on the keypad.
 */
u8 KEYPAD_u8GetButton();

#endif