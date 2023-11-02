/*
 * SSD_CFG.h
 *
 * Created: 10/21/2023 6:20:35 PM
 *  Author: Mahmoud Tariq
 */ 


#ifndef SSD_CFG_H_
#define SSD_CFG_H_

//OPerating Mode
/*Options
1 to Turn on
0 to Turn off
*/
#define Four_bitMode  1  //Default
#define Eight_bitMode 0


/*Pins for 4 bit Mode*/

#define  SSD_D1	PORTA_PIN4
#define  SSD_D2 PORTA_PIN5
#define  SSD_D3 PORTA_PIN6
#define  SSD_D4 PORTA_PIN7

/*Nibble Options if used*/
#define LOW_NIBBLE  0
#define HIGH_NIBBLE 1



/*Decimal Point */
#define  SSD_DIP	PORTB_PIN3

#endif /* SSD_CFG_H_ */