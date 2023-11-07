/*
 * LCD_CFG.h
 *
 * Created: 10/22/2023 10:05:42 AM
 *  Author: Mahmoud Tariq
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/*4-BIT MODE DATA PINS "NTI BOARD DEFAULT"*/

#define LCD_D1  PORTB_PIN0
#define LCD_D2  PORTB_PIN1
#define LCD_D3  PORTB_PIN2
#define LCD_D4  PORTB_PIN4

#define LCD_RS  PORTA_PIN3
#define LCD_RW	100
#define LCD_EN  PORTA_PIN2

/*4-BIT MODE DATA PINS "AMIT BOARD DEFAULT"*/
/*
#define LCD_D1  PORTA_PIN4
#define LCD_D2  PORTA_PIN5
#define LCD_D3  PORTA_PIN6
#define LCD_D4  PORTA_PIN7

#define LCD_RS  PORTB_PIN1
#define LCD_RW	100
#define LCD_EN  PORTB_PIN3
*/
#define LCD16_2   0

#define LCD20_4   1







#endif /* LCD_CFG_H_ */