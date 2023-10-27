#include "Std_types.h"
#include "Bit_utils.h"
#include "DIO.h"
#include "PORT.h"
#include <util/delay.h>

#define POV_DELAY_TIME  5

/**
 * this function takes a number as input and sends it's binary representation on BCD bus.
 */
void displayNumber(u8 Copy_u8Number){
	DIO_enuWriteChannel(PORT_B_CHANNEL_0, GET_BIT(Copy_u8Number, 0));
	DIO_enuWriteChannel(PORT_B_CHANNEL_1,GET_BIT(Copy_u8Number, 1));
	DIO_enuWriteChannel(PORT_B_CHANNEL_2,GET_BIT(Copy_u8Number, 2));
	DIO_enuWriteChannel(PORT_B_CHANNEL_4,GET_BIT(Copy_u8Number, 3));
}

void main(void){
	/* Initialize the default pins direction and value */
	PORT_enuInit();
	/* Initialize initial counter value */
	u16 CounterValue = 1234;
	/* defining and initializing 3 variables to detect if a button is pressed */
	volatile u8 incButtonValue = 0;
	volatile u8 decButtonValue = 0;
	volatile u8 rstButtonValue = 0;

	/* main program loop */
	while(1){

		/* initializing a variable to hold the val for digits to be shown in SSD */
		u16 digitToBeDisplayed = CounterValue ;

		/* displaying first digit on first SSD */
		displayNumber(digitToBeDisplayed % 10);
		digitToBeDisplayed /= 10;
		DIO_enuWriteChannel(PORT_A_CHANNEL_3, DIO_CHANNEL_LEVEL_LOW);
		_delay_ms(POV_DELAY_TIME);
		DIO_enuWriteChannel(PORT_A_CHANNEL_3, DIO_CHANNEL_LEVEL_HIGH);

		/* displaying second digit on second SSD */
		displayNumber(digitToBeDisplayed%10);
		digitToBeDisplayed /= 10;
		DIO_enuWriteChannel(PORT_A_CHANNEL_2, DIO_CHANNEL_LEVEL_LOW);
		_delay_ms(POV_DELAY_TIME);
		DIO_enuWriteChannel(PORT_A_CHANNEL_2, DIO_CHANNEL_LEVEL_HIGH);
		displayNumber(digitToBeDisplayed%10);

		/* displaying third digit on third SSD */
		digitToBeDisplayed /= 10;
		DIO_enuWriteChannel(PORT_B_CHANNEL_5, DIO_CHANNEL_LEVEL_LOW);
		_delay_ms(POV_DELAY_TIME);
		DIO_enuWriteChannel(PORT_B_CHANNEL_5, DIO_CHANNEL_LEVEL_HIGH);

		/* displaying fourth digit on fourth SSD */
		displayNumber(digitToBeDisplayed%10);
		digitToBeDisplayed /= 10;
		DIO_enuWriteChannel(PORT_B_CHANNEL_6, DIO_CHANNEL_LEVEL_LOW);
		_delay_ms(POV_DELAY_TIME);
		DIO_enuWriteChannel(PORT_B_CHANNEL_6, DIO_CHANNEL_LEVEL_HIGH);

		/* detecting if a button is pressed */
		DIO_enuReadChannel(PORT_C_CHANNEL_4, &incButtonValue);
		DIO_enuReadChannel(PORT_C_CHANNEL_3, &rstButtonValue);
		DIO_enuReadChannel(PORT_C_CHANNEL_2, &decButtonValue);

		/* incrementing the counter within limits */
		if (incButtonValue == 0){
			_delay_ms(200);
			if (CounterValue < 9999){
				CounterValue ++;
			}else {
				CounterValue = 0;
			}


		}
		/* reseting the counter */
		if (rstButtonValue == 0){
			_delay_ms(200);
			CounterValue = 0;
		}
		/* decrementing the counter within limits */
		if (decButtonValue == 0){
			_delay_ms(200);
			if (CounterValue != 0){
			CounterValue --;
			}else {
				CounterValue = 9999;
			}
		}
	}
}
