/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : PORT                **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/* Port configurations options:
    1 - PORT_MODE_OUTPUT_LOW            
    2 - PORT_MODE_OUTPUT_HIGH           
    3 - PORT_MODE_INPUT_FLOATING        
    4 - PORT_MODE_INPUT_PULLUP          
*/

/* Port A Pins Configurations */
#define PORT_A_PIN_0_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_A_PIN_1_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_A_PIN_2_CFG                    PORT_MODE_OUTPUT_LOW
#define PORT_A_PIN_3_CFG                    PORT_MODE_OUTPUT_LOW
#define PORT_A_PIN_4_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_A_PIN_5_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_A_PIN_6_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_A_PIN_7_CFG                    PORT_MODE_INPUT_FLOATING

/* Port B Pins Configurations */
#define PORT_B_PIN_0_CFG                    PORT_MODE_OUTPUT_LOW
#define PORT_B_PIN_1_CFG                    PORT_MODE_OUTPUT_LOW
#define PORT_B_PIN_2_CFG                    PORT_MODE_OUTPUT_LOW
#define PORT_B_PIN_3_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_B_PIN_4_CFG                    PORT_MODE_OUTPUT_LOW
#define PORT_B_PIN_5_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_B_PIN_6_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_B_PIN_7_CFG                    PORT_MODE_INPUT_FLOATING

/* Port C Pins Configurations */
#define PORT_C_PIN_0_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_C_PIN_1_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_C_PIN_2_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_C_PIN_3_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_C_PIN_4_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_C_PIN_5_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_C_PIN_6_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_C_PIN_7_CFG                    PORT_MODE_INPUT_FLOATING

/* Port D Pins Configurations */
#define PORT_D_PIN_0_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_D_PIN_1_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_D_PIN_2_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_D_PIN_3_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_D_PIN_4_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_D_PIN_5_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_D_PIN_6_CFG                    PORT_MODE_INPUT_FLOATING
#define PORT_D_PIN_7_CFG                    PORT_MODE_INPUT_FLOATING

#endif
