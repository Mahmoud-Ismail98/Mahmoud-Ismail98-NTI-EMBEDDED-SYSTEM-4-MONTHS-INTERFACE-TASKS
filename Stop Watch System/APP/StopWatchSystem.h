/*
=======================================================================================================================
Author       : Mamoun
Project      : Stop Watch System
File Name    : StopWatchSystem.h
Date Created : Oct 26, 2023
=======================================================================================================================
*/


#ifndef APP_STOPWATCHSYSTEM_H_
#define APP_STOPWATCHSYSTEM_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

#define START_BUTTON_PORT_ID                   (DIO_PORTD_ID)
#define START_BUTTON_PIN_ID                    (DIO_PIN4_ID)

#define PAUSE_BUTTON_PORT_ID                   (DIO_PORTD_ID)
#define PAUSE_BUTTON_PIN_ID                    (DIO_PIN5_ID)

#define RESET_BUTTON_PORT_ID                   (DIO_PORTD_ID)
#define RESET_BUTTON_PIN_ID                    (DIO_PIN6_ID)


#define SSD_NUM_OF_MPX_SSD                     (4U)

#define SSD_DECODER_PORT_ID                    (DIO_PORTC_ID)

#define SSD_DECODER_PIN0_ID                    (DIO_PIN0_ID)
#define SSD_DECODER_PIN1_ID                    (DIO_PIN1_ID)
#define SSD_DECODER_PIN2_ID                    (DIO_PIN2_ID)
#define SSD_DECODER_PIN3_ID                    (DIO_PIN3_ID)

#define SSD_ENABLE_PORT_ID                     (DIO_PORTD_ID)

#define SSD_ENABLE_PIN0_ID                     (DIO_PIN0_ID)
#define SSD_ENABLE_PIN1_ID                     (DIO_PIN1_ID)
#define SSD_ENABLE_PIN2_ID                     (DIO_PIN2_ID)
#define SSD_ENABLE_PIN3_ID                     (DIO_PIN3_ID)

#define SSD_DISPLAY_DELAY                      (10U)

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef struct
{
    uint8 units;
    uint8 tens;
    uint8 hundreds;
    uint8 thousands;
}SSD_numberFormat;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

void SSD_displayNumber(uint8 a_number);
void SSD_enableSevenSegment(uint8 a_sevenSegementID);
void IncrementCounter(void);
void ResetCounter(void);

#endif /* APP_STOPWATCHSYSTEM_H_ */
