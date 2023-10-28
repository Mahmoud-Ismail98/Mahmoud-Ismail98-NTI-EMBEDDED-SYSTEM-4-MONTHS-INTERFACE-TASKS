/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : ADC                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef ADC_H
#define ADC_H

/*ADC channels macros */
#define ADC_SINGLE_CHANNEL_0                             0b00000000
#define ADC_SINGLE_CHANNEL_1                             0b00000001
#define ADC_SINGLE_CHANNEL_2                             0b00000010
#define ADC_SINGLE_CHANNEL_3                             0b00000011
#define ADC_SINGLE_CHANNEL_4                             0b00000100
#define ADC_SINGLE_CHANNEL_5                             0b00000101
#define ADC_SINGLE_CHANNEL_6                             0b00000110
#define ADC_SINGLE_CHANNEL_7                             0b00000111
#define ADC_DIFF_CHANNELS_0_AND_0_GAIN_10x               0b00001000
#define ADC_DIFF_CHANNELS_1_AND_0_GAIN_10x               0b00001001
#define ADC_DIFF_CHANNELS_0_AND_0_GAIN_200x              0b00001010
#define ADC_DIFF_CHANNELS_1_AND_0_GAIN_200x              0b00001011
#define ADC_DIFF_CHANNELS_2_AND_2_GAIN_10x               0b00001100
#define ADC_DIFF_CHANNELS_3_AND_2_GAIN_10x               0b00001101
#define ADC_DIFF_CHANNELS_2_AND_2_GAIN_200x              0b00001110
#define ADC_DIFF_CHANNELS_3_AND_2_GAIN_200x              0b00001111
#define ADC_DIFF_CHANNELS_0_AND_1_GAIN_1x                0b00010000
#define ADC_DIFF_CHANNELS_1_AND_1_GAIN_1x                0b00010001
#define ADC_DIFF_CHANNELS_2_AND_1_GAIN_1x                0b00010010
#define ADC_DIFF_CHANNELS_3_AND_1_GAIN_1x                0b00010011
#define ADC_DIFF_CHANNELS_4_AND_1_GAIN_1x                0b00010100
#define ADC_DIFF_CHANNELS_5_AND_1_GAIN_1x                0b00010101
#define ADC_DIFF_CHANNELS_6_AND_1_GAIN_1x                0b00010110
#define ADC_DIFF_CHANNELS_7_AND_1_GAIN_1x                0b00010111
#define ADC_DIFF_CHANNELS_0_AND_2_GAIN_1x                0b00011000
#define ADC_DIFF_CHANNELS_1_AND_2_GAIN_1x                0b00011001
#define ADC_DIFF_CHANNELS_2_AND_2_GAIN_1x                0b00011010
#define ADC_DIFF_CHANNELS_3_AND_2_GAIN_1x                0b00011011
#define ADC_DIFF_CHANNELS_4_AND_2_GAIN_1x                0b00011100
#define ADC_DIFF_CHANNELS_5_AND_2_GAIN_1x                0b00011101

/*ADC resolution macros*/
#define ADC_RESOLUTION_8BIT                             1
#define ADC_RESOLUTION_16BIT                            2

/*ADC prescaler macros*/
#define ADC_PRESCALER_DIV_FACTOR_2                      1
#define ADC_PRESCALER_DIV_FACTOR_4                      2
#define ADC_PRESCALER_DIV_FACTOR_8                      3
#define ADC_PRESCALER_DIV_FACTOR_16                     4
#define ADC_PRESCALER_DIV_FACTOR_32                     5
#define ADC_PRESCALER_DIV_FACTOR_64                     6
#define ADC_PRESCALER_DIV_FACTOR_128                    7

/**
 * This function is used to Initialize the adc. 
 */
void ADC_voidInit();

/**
 * This function is used to read the ADC value for a certain channel. 
 * 
 * @param Copy_u8Channel represents the channel number.
 * 
 * @param Copy_u8PreScaler represents the prescaler that will be applied to adc clock.
 * 
 * @param Copy_u8Resolution represents the desired adc resolution.
 * 
 * @param Copy_pu16DigitalValue pointer to a u16 to save the ADC reading in it.
 */
void ADC_voidReadChannel(u8 Copy_u8Channel,u8 Copy_u8PreScaler, u8 Copy_u8Resolution, pu16 Copy_pu16DigitalValue);

/**
 * This function is used to read the ADC value for a certain channel without waiting. 
 * 
 * @param Copy_u8Channel represents the channel number.
 * 
 * @param Copy_u8PreScaler represents the prescaler that will be applied to adc clock.
 * 
 * @param Copy_u8Resolution represents the desired adc resolution.
 * 
 * @param Copy_pu16DigitalValue pointer to a u16 to save the ADC reading in it.
 */
void ADC_voidReadChannelAsynch(u8 Copy_u8Channel,u8 Copy_u8PreScaler, u8 Copy_u8Resolution, pu16 Copy_pu16DigitalValue);

/**
 * This function is used to set the callback function for ADC. 
 * 
 * @param ADC_callBackFunc pointer to the callback function.
 * 
 * @return an enum which indicates whether the operation was successful or if there was an error.
 */
tenuErrorStatus ADC_enuSetCallBackFunc(void (*ADC_callBackFunc)());

#endif
