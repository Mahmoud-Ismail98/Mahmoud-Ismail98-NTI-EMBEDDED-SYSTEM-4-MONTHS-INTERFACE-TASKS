/*
=======================================================================================================================
Author       : Mamoun
Project       : Stop Watch System
File Name    : StopWatchSystem.h
Date Created : Oct 20, 2023
=======================================================================================================================
*/


#ifndef APP_STOPWATCHSYSTEM_H_
#define APP_STOPWATCHSYSTEM_H_

/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "Std_types.h"
#include "Bit_utils.h"

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/
											   
#define SSD_DECODER_PORT_ID                    DIO_u8PORTC
											   
#define SSD_DECODER_PIN0_ID                    DIO_u8CHANNEL16
#define SSD_DECODER_PIN1_ID                    DIO_u8CHANNEL17
#define SSD_DECODER_PIN2_ID                    DIO_u8CHANNEL18
#define SSD_DECODER_PIN3_ID                    DIO_u8CHANNEL19
											   
#define SSD_ENABLE_PORT_ID                     DIO_u8PORTD

#define SSD_ENABLE_PIN0_ID                     DIO_u8CHANNEL24
#define SSD_ENABLE_PIN1_ID                     DIO_u8CHANNEL25
#define SSD_ENABLE_PIN2_ID                     DIO_u8CHANNEL26
#define SSD_ENABLE_PIN3_ID                     DIO_u8CHANNEL27

#define DISPLAY_DELAY                          2

typedef struct
{
    u8 units;
    u8 tens;
    u8 hundreds;
    u8 thousands;
}StopWatchSystem_numberFormat;

typedef enum
{
	BUTTON_PRESSED,
	BUTTON_NOT_PRESSED

}buttonStatus;

void SSD_displayNumber(u8 a_number);

void SSD_enableSevenSegment(u8 a_sevenSegementID);

buttonStatus CheckButtonPressed(u8 a_portID, u8 a_pinID);

void IncrementCounter(void);

void DecrementCounter(void);

void ResetCounter(void);


#endif 
