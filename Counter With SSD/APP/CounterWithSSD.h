/*
=======================================================================================================================
Author       : Mamoun
Project      : Counetr With SSD
File Name    : CounterWithSSD.h
Date Created : Oct 21, 2023
=======================================================================================================================
*/


#ifndef APP_COUNTERWITHSSD_H_
#define APP_COUNTERWITHSSD_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

#define INCREMENT_BUTTON_PORT_ID               (DIO_PORTD_ID)
#define INCREMENT_BUTTON_PIN_ID                (DIO_PIN7_ID)

#define DECREMENT_BUTTON_PORT_ID               (DIO_PORTD_ID)
#define DECREMENT_BUTTON_PIN_ID                (DIO_PIN6_ID)

#define RESET_BUTTON_PORT_ID                   (DIO_PORTD_ID)
#define RESET_BUTTON_PIN_ID                    (DIO_PIN5_ID)


#define SSD_NUM_OF_MPX_SSD                     (4U)

#define SSD_DECODER_PORT_ID                    (DIO_PORTB_ID)

#define SSD_DECODER_PIN0_ID                    (DIO_PIN0_ID)
#define SSD_DECODER_PIN1_ID                    (DIO_PIN1_ID)
#define SSD_DECODER_PIN2_ID                    (DIO_PIN2_ID)
#define SSD_DECODER_PIN3_ID                    (DIO_PIN3_ID)

#define SSD_ENABLE1_PORT_ID                     (DIO_PORTB_ID)
#define SSD_ENABLE1_PIN0_ID                     (DIO_PIN6_ID)
#define SSD_ENABLE2_PORT_ID                     (DIO_PORTB_ID)
#define SSD_ENABLE2_PIN0_ID                     (DIO_PIN5_ID)
#define SSD_ENABLE3_PORT_ID                     (DIO_PORTA_ID)
#define SSD_ENABLE3_PIN0_ID                     (DIO_PIN2_ID)
#define SSD_ENABLE4_PORT_ID                     (DIO_PORTA_ID)
#define SSD_ENABLE4_PIN0_ID                     (DIO_PIN3_ID)

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

void SSD_display(void);
void SSD_displayNumber(uint8 a_number);
void SSD_enableSevenSegment(uint8 a_sevenSegementID);
void IncrementCounter(void);
void DecrementCounter(void);
void ResetCounter(void);

#endif /* APP_COUNTERWITHSSD_H_ */
