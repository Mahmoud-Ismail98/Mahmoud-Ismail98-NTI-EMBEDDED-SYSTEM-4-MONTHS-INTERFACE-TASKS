/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : CLCD                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/
#ifndef CLCD_PRV_H
#define CLCD_PRV_H

/* macros for clcd mode*/
#define CLCD_MODE_8BIT          1
#define CLCD_MODE_4BIT          2



/**
 *  this is a static function that is used to send an 8-bit command to the module.
 *  @param Copy_u8Command: is the command to be sent. The function is responsible for sending.
 */
static void CLCD_prvSend8bData(u8 Copy_u8Command);

/**
 *  this is a static function that is used to send a 4-bit command to the module.
 *  @param Copy_u8Command: is the command to be sent. The function is responsible for sending.
 */
static void CLCD_prvSend4bData(u8 Copy_u8Command);


/**
 *  this is a static function that is used to send an enable pulse to the CLCD module.
 *  it is responsible for toggling the enable pin of the CLCD module to start data transfer.
 */
static void CLCD_prvSendEnablePulse();

#endif
