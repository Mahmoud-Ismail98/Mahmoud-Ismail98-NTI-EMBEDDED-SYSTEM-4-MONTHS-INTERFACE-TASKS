/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : KEYPAD              **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/
#ifndef KEYPAD_PRV_H
#define KEYPAD_PRV_H

/**
 * This function writes the bits of the given pattern to the corresponding row pins of a keypad.
 * 
 * @param Copy_u8Patter represents the pattern of bits to be written to the keypad row pins. 
 * Each bit in the pattern corresponds to a specific row pin on the keypad.
 */
void static KEYPAD_prvWritePins(u8 Copy_u8Pattern);

/**
 * This function reads the values of the keypad column pins and stores them in a pattern variable.
 * 
 * @param Copy_pu8Pattern is a pointer to an unsigned 8-bit integer. It is used to
 * store the pattern read from the keypad pins.
 */
void static KEYPAD_prvReadPins(pu8 Copy_pu8Pattern);

/* Each element in the array represents a key on the keypad.*/ 
u8 SYMBOLS[16] = {
    KEYPAD_KEY_1_SYMBOL,KEYPAD_KEY_2_SYMBOL,KEYPAD_KEY_3_SYMBOL,KEYPAD_KEY_4_SYMBOL,
    KEYPAD_KEY_5_SYMBOL,KEYPAD_KEY_6_SYMBOL,KEYPAD_KEY_7_SYMBOL,KEYPAD_KEY_8_SYMBOL,
    KEYPAD_KEY_9_SYMBOL,KEYPAD_KEY_10_SYMBOL,KEYPAD_KEY_11_SYMBOL,KEYPAD_KEY_12_SYMBOL,
    KEYPAD_KEY_13_SYMBOL,KEYPAD_KEY_14_SYMBOL,KEYPAD_KEY_15_SYMBOL,KEYPAD_KEY_16_SYMBOL
};

#endif
