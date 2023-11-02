/*
 * PORT_CFG.h
 *
 * Created: 10/19/2023 9:58:54 PM
 *  Author: Sharpel
 */ 


#ifndef PORT_CFG_H_
#define PORT_CFG_H_


// In case of using pre-build configuration this macro must equal true

#define   PRE_BUILD_STATUS          TRUE


/*
  for all 32 pins any pin can take only one value from the following
  
  1- PORT_PIN_MODE_INPUT_FLOATING
  2- PORT_PIN_MODE_INPUT_PULLUP
  3- PORT_PIN_MODE_OUTPUT_LOW
  4- PORT_PIN_MODE_OUTPUT_HIGH
  
*/


//PORT A
#define PORTA_PIN0_MODE        PORT_PIN_MODE_INPUT_FLOATING    
#define PORTA_PIN1_MODE        PORT_PIN_MODE_INPUT_FLOATING 
#define PORTA_PIN2_MODE        PORT_PIN_MODE_OUTPUT_LOW 
#define PORTA_PIN3_MODE        PORT_PIN_MODE_OUTPUT_LOW 
#define PORTA_PIN4_MODE        PORT_PIN_MODE_INPUT_FLOATING 
#define PORTA_PIN5_MODE        PORT_PIN_MODE_INPUT_FLOATING 
#define PORTA_PIN6_MODE        PORT_PIN_MODE_INPUT_FLOATING
#define PORTA_PIN7_MODE        PORT_PIN_MODE_INPUT_FLOATING  

//PORT B
#define PORTB_PIN0_MODE        PORT_PIN_MODE_OUTPUT_LOW
#define PORTB_PIN1_MODE        PORT_PIN_MODE_OUTPUT_LOW
#define PORTB_PIN2_MODE        PORT_PIN_MODE_OUTPUT_LOW
#define PORTB_PIN3_MODE        PORT_PIN_MODE_OUTPUT_LOW
#define PORTB_PIN4_MODE        PORT_PIN_MODE_OUTPUT_LOW
#define PORTB_PIN5_MODE        PORT_PIN_MODE_INPUT_FLOATING
#define PORTB_PIN6_MODE        PORT_PIN_MODE_INPUT_FLOATING
#define PORTB_PIN7_MODE        PORT_PIN_MODE_INPUT_FLOATING     

//PORT C
#define PORTC_PIN0_MODE        PORT_PIN_MODE_OUTPUT_HIGH
#define PORTC_PIN1_MODE        PORT_PIN_MODE_OUTPUT_HIGH
#define PORTC_PIN2_MODE        PORT_PIN_MODE_OUTPUT_HIGH
#define PORTC_PIN3_MODE        PORT_PIN_MODE_OUTPUT_HIGH
#define PORTC_PIN4_MODE        PORT_PIN_MODE_OUTPUT_HIGH
#define PORTC_PIN5_MODE        PORT_PIN_MODE_OUTPUT_HIGH
#define PORTC_PIN6_MODE        PORT_PIN_MODE_OUTPUT_LOW
#define PORTC_PIN7_MODE        PORT_PIN_MODE_OUTPUT_HIGH


//PORT D
#define PORTD_PIN0_MODE        PORT_PIN_MODE_OUTPUT_LOW
#define PORTD_PIN1_MODE        PORT_PIN_MODE_INPUT_FLOATING
#define PORTD_PIN2_MODE        PORT_PIN_MODE_INPUT_PULLUP
#define PORTD_PIN3_MODE        PORT_PIN_MODE_INPUT_PULLUP
#define PORTD_PIN4_MODE        PORT_PIN_MODE_INPUT_PULLUP
#define PORTD_PIN5_MODE        PORT_PIN_MODE_INPUT_PULLUP
#define PORTD_PIN6_MODE        PORT_PIN_MODE_INPUT_PULLUP
#define PORTD_PIN7_MODE        PORT_PIN_MODE_INPUT_PULLUP

#endif /* PORT_CFG_H_ */

