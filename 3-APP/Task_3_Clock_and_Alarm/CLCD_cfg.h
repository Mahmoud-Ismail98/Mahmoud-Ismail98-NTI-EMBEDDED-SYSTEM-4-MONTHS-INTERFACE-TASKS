/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : CLCD                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/
#ifndef CLCD_CFG_H
#define CLCD_CFG_H

/**
 * Mode Options : 
 * 1- CLCD_MODE_8BIT          
 * 2- CLCD_MODE_4BIT          
*/
#define CLCD_MODE                       CLCD_MODE_4BIT

#if CLCD_MODE == CLCD_MODE_8BIT
    #define CLCD_DATA_PIN_0             PORT_A_CHANNEL_0
    #define CLCD_DATA_PIN_1             PORT_A_CHANNEL_1
    #define CLCD_DATA_PIN_2             PORT_A_CHANNEL_2
    #define CLCD_DATA_PIN_3             PORT_A_CHANNEL_3
    #define CLCD_DATA_PIN_4             PORT_A_CHANNEL_4
    #define CLCD_DATA_PIN_5             PORT_A_CHANNEL_5
    #define CLCD_DATA_PIN_6             PORT_A_CHANNEL_6
    #define CLCD_DATA_PIN_7             PORT_A_CHANNEL_7
#elif CLCD_MODE == CLCD_MODE_4BIT
    #define CLCD_DATA_PIN_4             PORT_B_CHANNEL_0
    #define CLCD_DATA_PIN_5             PORT_B_CHANNEL_1
    #define CLCD_DATA_PIN_6             PORT_B_CHANNEL_2
    #define CLCD_DATA_PIN_7             PORT_B_CHANNEL_4
#endif

#define CLCD_CONTROL_PIN_RS             PORT_A_CHANNEL_3
// change RW to out of limit when working with nti KIT:
#define CLCD_CONTROL_PIN_RW             40
#define CLCD_CONTROL_PIN_EN             PORT_A_CHANNEL_2

#endif
